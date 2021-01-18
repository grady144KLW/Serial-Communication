#include <Wire.h> // Adding the library for the i2c
#define slave_address 9 // Declaring the address 

int pot = A7; // Declaring the pin of the potentiometer
int val_; // declaring the value variable

void setup() {
Wire.begin(); 
}

void loop() {
val_ = map(analogRead(pot),0, 1023, 0, 255); // mapping the potentiometer values to the LED values 

Wire.beginTransmission(slave_address); // talking to the slave code
Wire.write(val_); // sending the values to the slave code
Wire.endTransmission(); // ending the communication
}
