
#include <vector>

//including foo_bar pico library, corresponds to foo/bar.h header (or similar)
#include "pico/stdlib.h"

#include "src/util.hpp"

int main(){

    int pin_number = 25;
    gpio_init(pin_number);
    gpio_set_dir(pin_number, GPIO_OUT);
    set_voltage(pin_number, 1.1);
    while (true)
    {
        
    }
    

    return 0;
}