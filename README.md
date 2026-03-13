git clone 
cd ap_device_id_finder
colcon build --packages-select ap_audio_device_id_finder
ros2 run ap_device_id_finder ap_device_id_finder_node
Take note of "Portaudio Device ID"
ros2 run audio_common audio_capturer_node --ros-args -p rate:=44100 -p device:=<replace-with-portaudio-device-id>
