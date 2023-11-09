// This is the script for the DVDW23 project
// 6 GL5516LDR photoresistors are connected to the analog pins of a Seeed Studio XIAO ESP32S3
// The ESP32S3 reads and sends a value to the serial monitor every 10 milliseconds, in a format that can be read by Protopie Connect (detecting of cups are shot)
// The ESP32S3 also reads the magnegtic field using a HALL sensor and sends both the presence of a magnet and the frequency to protopie connect (detecting pedal speed)
// by Bas Baccarne

// pins
const int photo1 = A0;
const int photo2 = A1;
const int photo3 = A2;
const int photo4 = A3;
const int photo5 = A4;
const int photo6 = A5;

const int hallPin = D8;

// variables for photoresistor readings
int photo1_value = 0;
int photo2_value = 0;
int photo3_value = 0;
int photo4_value = 0;
int photo5_value = 0;
int photo6_value = 0;

// variables for the hall sensors and frequency calculation
int hall_value = 0;
int magnetState = HIGH;
unsigned long previousMillis = 0;
unsigned long interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(hallPin, INPUT_PULLUP);
  pinMode(photo1, INPUT);
  pinMode(photo2, INPUT);
  pinMode(photo3, INPUT);
  pinMode(photo4, INPUT);
  pinMode(photo5, INPUT);
  pinMode(photo6, INPUT);
}

void loop() {

  // read data from all sensors
    photo1_value = analogRead(photo1);
    photo2_value = analogRead(photo2);
    photo3_value = analogRead(photo3);
    photo4_value = analogRead(photo4);
    photo5_value = analogRead(photo5);
    photo6_value = analogRead(photo6);

    hall_value = digitalRead(hallPin);

    // send raw data to serial monitor
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

    // process hall sensor data to calculate frequency
      if (hall_value == LOW && magnetState == HIGH) { // if a magnet is detected
        unsigned long currentMillis = millis(); // Get current time
        unsigned long timeElapsed = currentMillis - previousMillis; // Calculate time elapsed since last detection
        previousMillis = currentMillis; // Store current time for next comparison
        float frequency = 1000.0 / timeElapsed; // Calculate frequency (Hz)
        
        // send data to serial monitor (Hz)
        Serial.print("frequency||");
        Serial.println(frequency, 2); 
      
        magnetState = LOW; 

      } else if (hall_value == HIGH && magnetState == LOW) {
        // Magnet is not detected
        magnetState = HIGH;
      }
 
  // wait 10 milliseconds before the next loop (ADC needs time to convert)
  delay(10);
} 
