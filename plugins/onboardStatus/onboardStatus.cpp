#include "onboardStatus.h"
#include "onboardStatus_impl.h"

namespace dronecore {

OnboardStatus::OnboardStatus(System &system) : PluginBase()
{
    _impl = new OnboardStatusImpl(system);
}

OnboardStatus::~OnboardStatus()
{
    _impl->disable();
}

void OnboardStatus::say_hello() const
{
    _impl->say_hello();
}

void OnboardStatus::send_status(uint16_t temp[6], uint16_t hum[6], uint8_t nb_sample, uint8_t comp_id) const
{
	_impl->send_status(temp, hum, nb_sample, comp_id);
}

} // namespace dronecore
