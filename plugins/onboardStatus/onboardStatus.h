#pragma once

#include "plugin_base.h"
#include <stdint.h>

using namespace std;

namespace dronecore {

class System;
class OnboardStatusImpl;

class OnboardStatus : public PluginBase {
public:
    explicit OnboardStatus(System &system);
    ~OnboardStatus();

    void say_hello() const;
    void send_status(uint16_t temp[6], uint16_t hum[6], uint8_t nb_sample, uint8_t comp_id) const;

    // Non-copyable
    OnboardStatus(const OnboardStatus &) = delete;
    const OnboardStatus &operator=(const OnboardStatus &) = delete;

private:
    // Underlying implementation, set at instantiation
    OnboardStatusImpl *_impl;
};

} // namespace dronecore
