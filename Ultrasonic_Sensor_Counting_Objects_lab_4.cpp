// for a  HC-SR04 Ultrasonic distance sensor on a rover that is that is trying to detect whether a object is present or not and counts how many times has an object passed the sensor
int trigPin = 11;
int echoPin = 12;

long duration;
int distance;
// the amount of times an object has passed the sensor
int objects = 0;
// a function that finds the distance; used for to make while loops update
int readDistance(){
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
 return duration * 0.034 / 2;
}
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 

  Serial.begin(9600);
}

void loop() {
  //defines distance as the function that found it in cm
  distance = readDistance();
  // if the distance is more than 10cm declares that its Waiting To Detect An Object
  while(distance > 10){
    Serial.println("Waiting To Detect An Object");
    // rereads distance in order to update when redoing the loop
    distance = readDistance();
  }
  // if the distance of the thing in front of it is 10cm or less it declares that Object Detected & Present
  while(distance <= 10){
    Serial.println("Object Detected & Present");
     // rereads distance in order to update when redoing the loop
    distance = readDistance();
  }
  Serial.println("Detected Object Is Gone");
 // adds one to the amount of times that an object has passed by the sensor
  objects++;
  Serial.println(String(objects) +" Objects Detected");
}
