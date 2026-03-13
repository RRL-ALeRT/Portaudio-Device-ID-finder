#include <portaudio.h>
#include <rclcpp/rclcpp.hpp>

class ApDeviceIdFinder : public rclcpp::Node {
public:
  ApDeviceIdFinder();
private:
  std::string search_term_;
  std::string device_name;
  int device;
};
