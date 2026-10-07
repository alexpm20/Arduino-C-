// for a  HC-SR04 Ultrasonic distance sensor on a rover that is pointing down, in order to see if the rover is going to fall of an edge
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

// prints to the center consle to stop if the floor ahead of it is more than 4 cm
if ( distance > 4) { 
  Serial.println("STOP");
}
else{
  Serial.println("CLEAR");
}
}
