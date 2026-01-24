#include <RTK/RtkConverter.h>
#include <RTK/RtkReciever.h>
#include <messaging/MavlinkConnection.h>

RtkConverter::RtkConverter(RtkReciever &rtkReciever, MavlinkConnection &mavlinkConnection)
    : mavlinkConnection_(mavlinkConnection)
{
    connect(&rtkReciever, &RtkReciever::rawMessageReceived,
            this, &RtkConverter::processRawMessage);
}

RtkConverter::~RtkConverter() = default;

void RtkConverter::processRawMessage(const QByteArray &rtcmData)
{
    int len = rtcmData.size();

    // Debug 1: Log incoming data size
    qDebug() << "RTCM Data Received | Size:" << len << "bytes";

    int offset = 0;
    uint8_t sequence = 0;
    bool isFragmented = (len > 180);

    // Check if we even have a passthrough available before looping
    auto passthrough = mavlinkConnection_.mavlinkPassthrough();
    if (!passthrough)
    {
        qWarning() << "RTK Converter: Cannot send. MavlinkPassthrough is NULL (Drone not connected?)";
        return;
    }

    while (len > 0)
    {
        int chunk = qMin(len, 180);

        uint8_t flags = (sequence << 3);
        if (isFragmented)
        {
            flags |= 0x01;
        }

        mavlink_message_t msg;
        mavlink_msg_gps_rtcm_data_pack(
            1, 255, &msg,
            flags,
            static_cast<uint8_t>(chunk),
            reinterpret_cast<const uint8_t *>(rtcmData.data() + offset));

        qDebug() << "  -> Sending MAVLink RTCM Fragment | Chunk:" << chunk
                 << "Seq:" << sequence
                 << "Flags:" << QString::number(flags, 16);

        passthrough->send_message(msg);

        len -= chunk;
        offset += chunk;
        sequence = (sequence + 1) % 32;
    }
}