#include <RTK/RtkModule.h>
#include <RTK/RtkReciever.h>
#include <RTK/RtkConverter.h>

RtkModule::RtkModule(MavlinkConnection& mavlinkConnection)
: rtkReciever_(std::make_unique<RtkReciever>())
, rtkConverter_(std::make_unique<RtkConverter>())
{   
}

RtkModule::~RtkModule() = default;