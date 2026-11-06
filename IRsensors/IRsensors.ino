const int SENSOR_PIN = 7; // Connect OUT pin to digital pin 2

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  int sensorState = digitalRead(SENSOR_PIN);

  if (sensorState == LOW) {
    // Depending on calibration, LOW often means White (high reflection)
    Serial.println("Surface: WHITE (or obstacle detected)");
  } else {
    // HIGH often means Black (low/no reflection)
    Serial.println("Surface: BLACK (or line detected)");
  }

  delay(150);
}