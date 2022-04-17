#include <iostream>
#include <thread>

#include <openmotion_led_hat_control.h>

#include <unistd.h>		

using namespace open_motion;

int main(){
    std::printf("hello");

    led_hat led_hat(0x17);

    printf("test read %i \n", led_hat.get_ir_led_brightness());

    while (true) {
        printf("some \n");
        
        sleep(5);
        printf("test read %i \n", led_hat.get_ir_led_brightness());
    };
}