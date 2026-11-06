#include <Servo.h>

Servo myservo;  // Create a servo object to control the SG90

int pos = 0;    // Variable to store the current servo position

void setup() {
  myservo.attach(9);  // Attaches the servo on pin 9 to the servo object
}

void loop() {
  // Rotate smoothly from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              // Tell servo to go to position in variable 'pos'
    delay(10);                       // Wait 15ms for the servo to reach the position
  }
  
  // Rotate smoothly back from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              // Tell servo to go to position in variable 'pos'
    delay(10);                       // Wait 15ms for the servo to reach the position
  }
}
