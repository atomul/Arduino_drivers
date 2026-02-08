# KY-003 Pin Explanation (Arduino / General Electronics)

The **KY-003** is a digital Hall effect sensor module commonly used in Arduino and other microcontroller projects **to detect magnetic fields**. It utilizes the A3144 Hall-effect switch to output a binary signal (high or low) when a magnetic field is detected, often used for position, speed, or proximity sensing. 

## Power
- 5V - some websites mention it supposely works with 4.5V - 24V DC. Tested with 12V and it works, but I would still use 5V

## Behavior

- Red LED: always ON (power indicator)
- No magnet → digitalRead() = 1 (HIGH)
- Magnet detected → digitalRead() = 0 (LOW)
---

## Pin Table

| Pin | Type | Meaning | Connect To (Typical) | Notes |
|---|---|---|---|---|
| **GND** | Ground | Common ground reference | Arduino GND + Battery GND | **All grounds must be connected together.** |
| **VDD (middle pin)** | Power | Power supply voltage | Arduino 5V / External power supply | 5V (some sheets reference 4.5V - 24V DC) |
| **S (Signal)** | Output | Signal | Arduino digital pin | Needs pull-up (INPUT_PULLUP or external). |

---

## Quick Wiring Example (Arduino)

- **VCC → 5V (Arduino or battery)**
- **GND → Arduino GND + battery -**
- **S**
  - Internal pullup
    - S → Arduino digital pin with **INPUT_PULLUP** OR
  - External pullup
    -  S → Arduino digital pin with **INPUT** and 
    -  S → 10KΩ → Arduino VCC (possibly works with 5V external as well)