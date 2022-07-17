#include <iostream>
#include <unistd.h>

#include <openmotion_led_hat_control.h>
#include <openmotion_network.h>
#include <openmotion_libcamera.hpp>

#include <opencv2/opencv.hpp>

using namespace open_motion;

int main()
{

    led_hat led_hat(0x17);
    cv::Mat image;
    PiCamera camera;

    camera.options->video_width = 1024;
    camera.options->video_height = 768;
    camera.options->framerate = 5;
    camera.options->verbose = true;

    led_hat.set_ring_led_brightness(0x40);
    led_hat.set_ir_led_brightness(0x00);

    cv::namedWindow("Video", cv::WINDOW_NORMAL);
    camera.startVideo();
    int ch = 0;
    while (ch != 27)
    {
        if (!camera.getVideoFrame(image, 1000))
        {
            std::cout << "Timeout error" << std::endl;
        }
        else
        {
            cv::imshow("Video", image);
            ch = cv::waitKey(10);
        }
    }
    camera.stopVideo();
    cv::destroyWindow("Video");
}