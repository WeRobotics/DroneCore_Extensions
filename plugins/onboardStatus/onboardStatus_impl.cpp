#include "onboardStatus_impl.h"
#include "global_include.h"
#include <functional>

namespace dronecore {

OnboardStatusImpl::OnboardStatusImpl(System &system) : PluginImplBase(system)
{
    _parent->register_plugin(this);
}

OnboardStatusImpl::~OnboardStatusImpl()
{
    _parent->register_plugin(this);
}

void OnboardStatusImpl::init()
{
    using namespace std::placeholders; // for `_1`
    
    _parent->register_mavlink_message_handler(
        MAVLINK_MSG_ID_COMMAND_LONG, std::bind(&OnboardStatusImpl::process_heartbeat, this, _1), this);
    
}

void OnboardStatusImpl::deinit()
{
    _parent->unregister_all_mavlink_message_handlers(this);
}

void OnboardStatusImpl::enable() {}

void OnboardStatusImpl::disable() {}

void OnboardStatusImpl::say_hello() const
{
    LogInfo() << "Hello world, I'm a new plugin.";
}

void OnboardStatusImpl::send_status(uint16_t temp[6], uint16_t hum[6], uint8_t nb_sample, uint8_t comp_id) const
{
    mavlink_message_t newMessage;
    mavlink_msg_wer_onboard_status_pack(
        GCSClient::system_id,
        GCSClient::component_id,
        &newMessage,
        comp_id,
        nb_sample,
        temp,
        hum);

    _parent->send_message(newMessage);
}

void OnboardStatusImpl::process_heartbeat(const mavlink_message_t &message)
{
    mavlink_command_long_t commandLong;

    mavlink_msg_command_long_decode(&message, &commandLong);
    if(commandLong.command != 200)
        LogDebug() << "I received a command " << unsigned(commandLong.command);
}

} // namespace dronecore
