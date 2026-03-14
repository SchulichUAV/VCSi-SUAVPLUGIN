#include <RTK/RtkModule.h>
#include <RTK/RtkReciever.h>
#include <RTK/RtkConverter.h>

RtkModule::RtkModule(MavlinkConnection& mavlinkConnection)
: rtkReciever_(std::make_unique<RtkReciever>())
, rtkConverter_(std::make_unique<RtkConverter>(*rtkReciever_, mavlinkConnection))
{   
}

RtkModule::~RtkModule() = default;

void RtkModule::startRtkReciever()
{
    rtkReciever_->start();
}
RtkReciever& RtkModule::getRtkReciever() {
    return *rtkReciever_;
}
