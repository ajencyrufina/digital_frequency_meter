#include <Wire.h>                // Library for I2C communication
#include <LiquidCrystal_I2C.h>   // Library for I2C LCD

// Create LCD object
// Parameters: (I2C Address, Columns, Rows)
// Common addresses: 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Digital pin connected to Schmitt Trigger output
const int freqInputPin = 8;

void setup() {

    // Initialize LCD
    lcd.init();           
    lcd.backlight();      

    // Display startup message
    lcd.setCursor(0, 0);
    lcd.print("Freq Meter Ready");
    delay(2000);          // Wait 2 seconds
    lcd.clear();

    // Set frequency input pin as input
    pinMode(freqInputPin, INPUT);
}

void loop() {

    unsigned long pulseCount = 0;        // Stores number of pulses
    unsigned long startTime = millis();  // Record start time

    /*
       Count pulses for exactly 1 second
       Each HIGH-to-LOW transition is counted as one pulse
    */
    while (millis() - startTime < 1000) {

        if (digitalRead(freqInputPin) == HIGH) {

            // Wait until signal goes LOW to avoid double counting
            while (digitalRead(freqInputPin) == HIGH);

            pulseCount++;  // Increment pulse count
        }
    }

    // Display result on LCD
    lcd.setCursor(0, 0);
    lcd.print("Frequency:");

    lcd.setCursor(0, 1);
    lcd.print(pulseCount);   // Frequency in Hz
    lcd.print(" Hz    ");    // Extra spaces clear old digits

    delay(500);  // Refresh display every 500 ms
}