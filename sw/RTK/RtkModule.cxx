#include <RTK/RtkModule.h>
#include <RTK/RtkReciever.h>
#include <RTK/RtkConverter.h>

#include <LmCdl/I_QmlApi.h>

// need to wire in the message sending
RtkModule::RtkModule(LmCdl::I_QmlApi &qmlApi)
    : qmlApi_(qmlApi)
    , rtkReciever_(std::make_unique<RtkReciever>())
    , rtkConverter_(std::make_unique<RtkConverter>())
{   
}

RtkModule::~RtkModule() = default;