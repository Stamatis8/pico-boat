#ifndef UTIL_HPP
#define UTIL_HPP

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

bool set_voltage(int pin_number, double voltage){
    /*
        Description: Sets voltage of int 'pin_number' to double 'voltage' using
            Pulse Width Modulation (PWM). The maximum voltage at 100% duty cycle
            is assumed to be 3.3V.
    */

    gpio_set_function(pin_number, GPIO_FUNC_PWM);
    int slice_num = pwm_gpio_to_slice_num(pin_number);
    int duty_cycle = voltage * 65535 / 3.3;
    pwm_set_chan_level(
        pwm_gpio_to_slice_num(pin_number),
        pwm_gpio_to_channel(pin_number),
        duty_cycle);
    pwm_set_clkdiv(slice_num, 10);
    pwm_set_enabled(slice_num, true);

    return true;
}

#endif //UTIL_HPP