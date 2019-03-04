
int redLed = 8;
int blueLed = 7;
int buzzer = 10;
int smokeA0 = A5;
//  Threshold value
int sensorThres = 250;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    tone(buzzer, 1000, 200);
    
    
  }

  
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}
