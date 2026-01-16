// #pragma once

// #include <QObject>

// class RtkReciever;
// class RtkConverter;
// namespace LmCdl
// {
//     class I_QmlApi;
// }

// class RtkModule : public QObject
// {
//     Q_OBJECT
// public:
//     explicit RtkModule(
//         LmCdl::I_QmlApi &qmlApi);
//     virtual ~RtkModule();

// private:
//     LmCdl::I_QmlApi &qmlApi_;

//     std::unique_ptr<RtkReciever> rtkReciever_;
//     std::unique_ptr<RtkConverter> rtkConverter_;
// };