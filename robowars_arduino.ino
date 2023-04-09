#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ros.h>
#include <std_msgs/Int32.h>

#define DEBUG 1

const int motor1PinA = 4;
const int motor1PinB = 5;
const int motor2PinA = 6;
const int motor2PinB = 7;

const char *ssid = "Manas";                 //hotspot name
const char *password = "hellowemeetagain";  //hotspot password

IPAddress server(192,168,43,206);           //your laptop IP where roscore is gonna run, commas separated

const uint16_t serverPort = 11411;

ros::NodeHandle nh;

void cmd_velCallback( const std_msgs::Int32& msg){
  int incomingByte = msg.data;
  //  write code here
  if (incomingByte == 1) {
      Serial.println("Moving Robot forward");
      digitalWrite(motor1PinA, HIGH);
      digitalWrite(motor1PinB, LOW);
      digitalWrite(motor2PinA, HIGH);
      digitalWrite(motor2PinB, LOW);
      
    } else if (incomingByte == 2) {
      Serial.println("Moving Robot backward");
      digitalWrite(motor1PinA, LOW);
      digitalWrite(motor1PinB, HIGH);
      digitalWrite(motor2PinA, LOW);
      digitalWrite(motor2PinB, HIGH);
    } else if (incomingByte == 3) {
      Serial.println("Moving Robot Left");
      digitalWrite(motor1PinA, HIGH);
      digitalWrite(motor1PinB, LOW);
      digitalWrite(motor2PinA, LOW);
      digitalWrite(motor2PinB, HIGH);
    } else if (incomingByte == 4) {
      Serial.println("Moving Robot Right");
      digitalWrite(motor2PinA, LOW);
      digitalWrite(motor2PinB, HIGH);
      digitalWrite(motor1PinA, HIGH);
      digitalWrite(motor1PinB, LOW);
    } else if (incomingByte == 5) {
      Serial.println("Stopping Robot");
      digitalWrite(motor1PinA, LOW);
      digitalWrite(motor1PinB, LOW);
      digitalWrite(motor2PinA, LOW);
      digitalWrite(motor2PinB, LOW);
    }

}

ros::Subscriber<std_msgs::Int32> Sub("/cmd_vel", &cmd_velCallback );

void setupWiFi(){
  WiFi.begin(ssid, password);
}

void setup(){
  setupWiFi();
  delay(2000);
  if (DEBUG)
    Serial.begin(115200);
  nh.getHardware()->setConnection(server, serverPort);
  nh.initNode();
  nh.subscribe(Sub);

  pinMode(motor1PinA, OUTPUT);
  pinMode(motor1PinB, OUTPUT);
  pinMode(motor2PinA, OUTPUT);
  pinMode(motor2PinB, OUTPUT);
}

void loop(){
  nh.spinOnce ();
  delay(200);
}
