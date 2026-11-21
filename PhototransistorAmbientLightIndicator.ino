const int greenLEDPin = 9;
const int yellowLEDPin = 10;
const int redLEDPin = 11;
const int SensorPin = A0;
int value = 0;
int greenValue = 0;
int blueValue = 0;
int SensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);                                       
  pinMode(yellowLEDPin, OUTPUT);
}

void loop() {
  SensorValue = analogRead(SensorPin); // 10-bit ADC: 0–1023
  delay(5);
  Serial.print("Raw Sensor Value: ");
  Serial.println(SensorValue);
  value = SensorValue/4; // Scale to 8-bit: 0–255
  Serial.print("Mapped Sensor Value: ");
  Serial.println(value);  
  if (SensorValue < 100){
    analogWrite(redLEDPin, 255);
    analogWrite(greenLEDPin, 0);
    analogWrite(yellowLEDPin, value); // PWM duty cycle
  }
  else {
    analogWrite(redLEDPin, 0);
    analogWrite(greenLEDPin, 255);
    analogWrite(yellowLEDPin, value); // PWM duty cycle
  }
  delay(1000);
}
