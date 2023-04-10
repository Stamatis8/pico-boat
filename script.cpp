
//including foo_bar pico library, corresponds to foo/bar.h header (or similar)
#include "pico/stdlib.h"

int main(){

    int pin_number = 25;
    gpio_init(pin_number);
    gpio_set_dir(pin_number, GPIO_OUT);
    while (true)
    {
        gpio_put(pin_number, 1);
        sleep_ms(250);
        gpio_put(pin_number, 0);
        sleep_ms(250);
    }
    

    return 0;
}