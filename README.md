git clone <br>
cd ap_device_id_finder <br>
colcon build --packages-select ap_audio_device_id_finder <br>
ros2 run ap_device_id_finder ap_device_id_finder_node <br>
Take note of "Portaudio Device ID" <br>
ros2 run audio_common audio_capturer_node --ros-args -p rate:=44100 -p device:=`<replace-with-portaudio-device-id>`
