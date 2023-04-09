# RoboWars
The repository presented here includes the Robot Operating System (ROS) architecture based velocity command control and arduino motor control code used to operate a robot designed for participation in the Robowars tournament.


## Dependencies
```bash
sudo apt install ros-noetic-rosserial
sudo apt install ros-noetic-rosserial-arduino
cd sketchbook/libraries/
rosrun rosserial_arduino make_libraries.py .
```
## Setup Code
### Create ROS Workspace (optional)
```bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
```
### Clone this repo
```bash
cd ~/catkin_ws/src
git clone
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
```

## Run Instructions
- edit the arduino code 
    - edit hotspot/LAN SSID and Password
    - edit IP address of roscore running host
- Upload the arduino code to ESP8266
- Power On ESP32
- ESP32 will now automatically connect to the hotspot/LAN
- Run the code
```bash
roscore
rosrun rosserial_python serial_node.py tcp
python3 robowars.py
```

## Credits
Aravind, Manas, Samrat, Saikat, Vashist, Yash
