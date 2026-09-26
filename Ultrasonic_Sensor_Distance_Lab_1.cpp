// for a  HC-SR04 Ultrasonic distance sensor, in order to find the distance of the object in front of the sensor in centimeters

int trigPin = 11;
int echoPin = 12;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 

  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // sends out a pulse that last 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // calculates distance in cm
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
