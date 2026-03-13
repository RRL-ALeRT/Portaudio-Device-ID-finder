git clone 
cd ap_device_id_finder
colcon build --packages-select ap_audio_device_id_finder
ros2 run ap_device_id_finder ap_device_id_finder_node
Take note of "Portaudio Device ID"
