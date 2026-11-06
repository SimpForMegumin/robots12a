const int trigPin = 8;
const int echoPin = 9;
const int leftSensorPin = 2;
const int rightSensorPin = 3;
long duration;
float distance;

void setup() { 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
   pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH); 
distance = (duration * 0.034) / 2; // Speed of sound is ~0.034 cm/us

Serial.print("Distance: "); 
Serial.print(distance); 
Serial.println(" cm"); delay(50);
}

 