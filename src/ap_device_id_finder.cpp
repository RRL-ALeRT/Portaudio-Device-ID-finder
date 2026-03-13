#include "ap_device_id_finder/ap_device_id_finder.h"

ApDeviceIdFinder::ApDeviceIdFinder() : Node("ap_device_id_finder") {
    this->declare_parameter<std::string>("search_term", "VideoMic");
    this->search_term_ = this->get_parameter("search_term").as_string();

     RCLCPP_INFO(this->get_logger(), "Search term: %s", this->search_term_.c_str());

     Pa_Initialize();

     this->device_name = "";
     this->device = 0;
     int device_count = Pa_GetDeviceCount();

     RCLCPP_INFO(this->get_logger(), "Searching %d devices...", device_count);

     while(this->device < device_count) {
        const PaDeviceInfo *info = Pa_GetDeviceInfo(this->device);
        if (info == nullptr) {
            this->device++;
            continue;
        }
        this->device_name = info->name;
        RCLCPP_INFO(this->get_logger(), "Device %d: %s", this->device, this->device_name.c_str());
        if (this->device_name.find(this->search_term_) != std::string::npos) {
            break;
        }
        this->device++;
      }

     if (this->device >= device_count) {
        RCLCPP_ERROR(this->get_logger(), "Device matching '%s' not found", this->search_term_.c_str());
     } else {
        RCLCPP_INFO(this->get_logger(), "Portaudio Device ID: %d", this->device);
     }
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ApDeviceIdFinder>());
    rclcpp::shutdown();
    return 0;
}