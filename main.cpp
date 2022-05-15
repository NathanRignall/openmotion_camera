#include <iostream>
#include <unistd.h>	

#include <openmotion_led_hat_control.h>
#include <openmotion_network.h>

using namespace open_motion;

int main(){
    std::printf("hello");

    led_hat led_hat(0x17);

    led_hat.set_ring_led_brightness(0xFF);
    led_hat.set_ir_led_brightness(0x90);

    system("libcamera-vid -t 0 -b 10000000 --width 1280 --height 720 --intra 60 --rotation 180 --inline --listen -o tcp://0.0.0.0:9000");

    while (true) {
        sleep(100);
    };
}