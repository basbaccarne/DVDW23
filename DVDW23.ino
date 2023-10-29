// This is the script for the DVDW23 project
// 6 GL5516LDR photoresistors are connected to the analog pins of a Seeed Studio XIAO ESP32S3
// The ESP32S3 reads and sends a value to the serial monitor every 10 milliseconds, in aa format that can be read by Protopie Connect
// Experiment: Hall sensor to detect movement of the bike pedal
// by Bas Baccarne

// pins
const int photo1 = A0;
const int photo2 = A1;
const int photo3 = A2;
const int photo4 = A3;
const int photo5 = A4;
const int photo6 = A5;

const int hall = A6;

// live readings
int photo1_value = 0;
int photo2_value = 0;
int photo3_value = 0;
int photo4_value = 0;
int photo5_value = 0;
int photo6_value = 0;

int hall_value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  // read data 
    photo1_value = analogRead(photo1);
    photo2_value = analogRead(photo2);
    photo3_value = analogRead(photo3);
    photo4_value = analogRead(photo4);
    photo5_value = analogRead(photo5);
    photo5_value = analogRead(photo6);

    // send data to serial monitor
    Serial.print("sensor1||");
      Serial.println(photo1_value);
    Serial.print("sensor2||");
      Serial.println(photo2_value);
    Serial.print("sensor3||");
      Serial.println(photo3_value);
    Serial.print("sensor4||");
      Serial.println(photo4_value);
    Serial.print("sensor5||");
      Serial.println(photo5_value);
    Serial.print("sensor6||");
      Serial.println(photo6_value);  

    Serial.print("hall||");
      Serial.println(hall_value);
 
  // wait 10 milliseconds before the next loop (ADC needs time to convert)
  delay(10);
} 