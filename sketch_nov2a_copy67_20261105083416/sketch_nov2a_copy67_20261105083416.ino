#define IR1 9
#define IR2 10
#define IR3 11

#define M1F 2
#define M1B 3
#define M2F 4
#define M2B 7

#define M1A 5
#define M2A 6

const int trigPin = 8;
const int echoPin = 9;
long duration;
float distance;

void setup() {
  Serial.begin(9600);

   pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);

  pinMode(M1F, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2F, OUTPUT);
  pinMode(M2B, OUTPUT);

  pinMode(M1A, OUTPUT);
  pinMode(M2A, OUTPUT);
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
  
  analogWrite(M1A, 255);
  analogWrite(M2A, 255);

  Serial.print(digitalRead(IR1));
  Serial.print(digitalRead(IR2));
  Serial.println(digitalRead(IR3));

  if (distance < 15) {
    digitalWrite(M1F, LOW);
    digitalWrite(M1B, LOW);
    digitalWrite(M2F, LOW);
    digitalWrite(M2B, LOW); 
    
  } else {
    digitalWrite(M1F, HIGH);
    digitalWrite(M1B, LOW);
    digitalWrite(M2F, HIGH);
    digitalWrite(M2B, LOW);
  }

  delay(1000);

  analogWrite(M1A, 160);
  analogWrite(M2A, 255);

  delay(1000);

  analogWrite(M1A, 255);
  analogWrite(M2A, 159);

  delay(1000);

}