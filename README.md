**🔌Digital Frequency Meter using Arduino Uno**

**📌 Project Overview**

This project presents the design and implementation of a Digital Frequency Meter using Arduino Uno to measure the frequency of AC signals (such as 230V mains frequency) safely and accurately.

The system is fully powered from the same 230V AC source being measured.
**⚡ No separate battery or external DC supply was used.**

The AC mains supply is stepped down, rectified, regulated, and used to power the entire circuit including the Arduino.

**🎯 Objectives**

Measure AC frequency (typically 50Hz–60Hz mains)

Safely step down 230V AC for measurement

Power the entire system directly from mains

Use Schmitt trigger for noise filtering

Display real-time frequency on LCD

**🧠 System Architecture**
            230V AC Input
            
                  │
        ┌─────────┴─────────┐
        │                   │
 Power Supply Path     Signal Conditioning Path
 
        │                   │
Step-down Transformer   High Impedance Divider

        │                   │
Bridge Rectifier       Schmitt Trigger (74HC14)

        │                   │
7805 Voltage Regulator      │

        │                   │
    
    Arduino Uno  <──────────┘
        │
      16x2 LCD

**⚡ Power Supply Design**

✔ 230V AC → Step-down Transformer (230V to 9V/12V AC)

✔ Bridge Rectifier (1N4007 Diodes)

✔ Filter Capacitor

✔ 7805 Voltage Regulator

✔ Provides regulated 5V supply

**🔹 Important Feature:**
There is no separate battery or adapter.
The Arduino and LCD are powered directly from the regulated output derived from the same AC source under measurement.

This ensures:

Compact design

Single-source operation

No dependency on external power

**🛠 Hardware Components**

🔹 Arduino Uno (ATmega328P)

🔹 230V to 9V/12V Transformer

🔹 Bridge Rectifier (1N4007 x4)

🔹 7805 Voltage Regulator

🔹 Filter Capacitors

🔹 High-value Resistors (Voltage Divider)

🔹 Schmitt Trigger IC (74HC14)

🔹 16x2 LCD Display

**⚙️ Working Principle**

The 230V AC input is stepped down using a transformer.

The stepped-down AC is:

Rectified and regulated to power the Arduino.

Also conditioned for frequency measurement.

A high impedance voltage divider reduces signal amplitude.

The Schmitt trigger converts the sine wave into a clean square wave.

The square wave is fed to an Arduino interrupt pin.

Arduino measures time between two rising edges using micros().

Frequency is calculated:

Frequency (Hz) = 1 / Time Period

The measured frequency is displayed on the LCD.

**📊 Measurement Range**

Input Frequency:	45Hz – 65Hz

Nominal Frequency	50Hz (India)

Accuracy	±0.1Hz (Timer dependent)

**🔐 Safety Measures**

Transformer isolation from mains

High-value resistor divider for safe signal reduction

Schmitt trigger for noise immunity

Common grounding after isolation stage

⚠️ Warning: Never connect 230V AC directly to Arduino without proper isolation.

**🚀 Applications**

Power system laboratory experiments

Frequency stability monitoring

Educational instrumentation

Electrical measurement projects
