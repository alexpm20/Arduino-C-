void setup() {
Serial.begin(9600);
 
 for (int x = 0; x < 21; x++){
    if(x < 10){
      Serial.println( String(x) + " is less than 10");
    }
    if (x == 10){
      Serial.println( String(x) + " is equal to 10");
    }
    if (x > 10){
      Serial.println( String(x) + " is greater than 10");
    }
 }
}

void loop() {
}

