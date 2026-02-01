# TB6612FNG Pin Explanation (Arduino / General Electronics)

The **TB6612FNG** is a dual H-bridge motor driver that can control **two DC motors** (Motor A and Motor B) or **one stepper motor**.

---

## Pin Table

| Pin | Type | Meaning | Connect To (Typical) | Notes |
|---|---|---|---|---|
| **VM** | Power (Motor) | Motor power supply voltage | Motor battery + (e.g. 6V–12V) | Powers the motor outputs (A/B). Not the logic. |
| **VCC** | Power (Logic) | Logic power supply voltage | Arduino 5V / ESP32 3.3V | Must match your MCU logic level. |
| **GND** | Ground | Common ground reference | Arduino GND + Battery GND | **All grounds must be connected together.** |
| **AOUT1** | Output | Motor A terminal 1 | Motor A wire | Connect to one motor lead. |
| **AOUT2** | Output | Motor A terminal 2 | Motor A wire | Connect to the other motor lead. |
| **BOUT1** | Output | Motor B terminal 1 | Motor B wire | Connect to one motor lead. |
| **BOUT2** | Output | Motor B terminal 2 | Motor B wire | Connect to the other motor lead. |
| **PWMA** | Input (PWM) | Speed control for Motor A | Arduino PWM pin (e.g. D5, D6, D9, D10) | PWM duty cycle controls speed. Can also be HIGH for full speed. |
| **INA1** | Input (Logic) | Motor A direction control 1 | Arduino digital pin | Used with INA2 to set direction/brake/coast. |
| **INA2** | Input (Logic) | Motor A direction control 2 | Arduino digital pin | Used with INA1 to set direction/brake/coast. |
| **PWMB** | Input (PWM) | Speed control for Motor B | Arduino PWM pin | PWM duty cycle controls speed. Can also be HIGH for full speed. |
| **INB1** | Input (Logic) | Motor B direction control 1 | Arduino digital pin | Used with INB2 to set direction/brake/coast. |
| **INB2** | Input (Logic) | Motor B direction control 2 | Arduino digital pin | Used with INB1 to set direction/brake/coast. |
| **STBY** / **STNDBY** | Input (Logic) | Standby control (enable/disable driver) | Arduino digital pin (or tie to VCC) | **HIGH = enabled**, **LOW = standby (off)**. Often tied to VCC through a pull-up. |

---

## Direction Control Logic (Motor A Example)

INA1 and INA2 decide what the motor does:

| INA1 | INA2 | Motor A Result |
|---:|---:|---|
| 0 | 0 | Coast (freewheel stop) |
| 1 | 0 | Forward |
| 0 | 1 | Reverse |
| 1 | 1 | Brake (active braking) |

Motor B works the same way using **INB1 / INB2**.

---

## Quick Wiring Example (Arduino Uno + 2 DC motors)

- **VCC → 5V**
- **VM → Motor battery +**
- **GND → Arduino GND + battery -**
- **STBY → 5V** (or Arduino pin set HIGH)
- **PWMA / PWMB → PWM pins**
- **INA1/INA2 + INB1/INB2 → digital pins**
- **AOUT/BOUT → motor wires**

---

If you'd like, I can also generate a matching Arduino code snippet for controlling both motors (forward/reverse + speed).
