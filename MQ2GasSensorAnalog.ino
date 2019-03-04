//VARIABLES
float Ro = 10000.0;    // this has to be tuned 10K Ohm
int sensorPin = A5;  // select the input pin for the sensor
int ledPin = 13;    // select the pin for the LED
int val = 0;        // variable to store the value coming from the sensor
float Vrl = 0.0;
float Rs = 0.0;
float ratio = 0.0;
int redLed = 8;
int blueLed = 7;
int buzzer = 10;
int smokeA0 = A5;
//  Threshold value
int sensorThres = 31;



// SETUP
void setup() {
pinMode(ledPin, OUTPUT); // declare the ledPin as an OUTPUT
Serial.begin(9600);      // initialize serial communication with computer
// analogReference(EXTERNAL);
}

// get  ppm
float get_ppm (float ratio){
  float ppm = 0.0;
  ppm = 37143 * pow (ratio, -3.178);
return ppm;
}

// LOOP
void loop() { 
  
val = analogRead(sensorPin);     // read the value from the analog sensor
//Serial.println(val);             // send it to the computer (as ASCII digits)
digitalWrite(ledPin, HIGH);      // turn the ledPin on
delay(100);                      // stop the program for some time
digitalWrite(ledPin, LOW);       // turn the ledPin off
delay(100);                      // stop the program for some time

Vrl = val * ( 5.00 / 1024.0  );      // V
Rs = 20000 * ( 5.00 - Vrl) / Vrl ;   // Ohm 
ratio =  Rs/Ro;                      

Serial.print ( "Vrl / Rs / ratio:");
Serial.print (Vrl);
Serial.print(" ");
Serial.print (Rs);
Serial.print(" ");
Serial.println(ratio);
Serial.print ( "ppm :");
Serial.println(get_ppm(ratio));

int analogSensor = analogRead(smokeA0);

  Serial.print("analog: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if ( get_ppm(ratio) > sensorThres)
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

delay(1000);
}
