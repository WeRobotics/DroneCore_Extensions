#pragma once

#include "onboardStatus.h"
#include "mavlink_include.h"
#include "plugin_impl_base.h"
#include "system.h"
#include <stdint.h>

using namespace std;

namespace dronecore {

class OnboardStatusImpl : public PluginImplBase {
public:
    OnboardStatusImpl(System &system);
    ~OnboardStatusImpl();

    void say_hello() const;
    void send_status(uint16_t temp[6], uint16_t hum[6], uint8_t nb_sample, uint8_t comp_id) const;

    void init() override;
    void deinit() override;

    void enable() override;
    void disable() override;

private:
    void process_heartbeat(const mavlink_message_t &message);
};

} // namespace dronecore
