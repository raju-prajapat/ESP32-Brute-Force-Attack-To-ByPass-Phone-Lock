# ESP32 BLE Keyboard PIN Brute-Forcer

A proof-of-concept security research project that utilizes an ESP32 microcontroller acting as a Bluetooth Low Energy (BLE) Keyboard to automate PIN entry sequences for 4-digit[cite: 1] and 6-digit[cite: 2] lock screens.

---

## ⚠️ Disclaimer
*This project is created strictly for educational purposes, personal device recovery, and hardware security testing. Unauthorized access to devices you do not own or do not have explicit permission to test is illegal and unethical.*

---

## Features
* **BLE HID Emulation:** Connects to target devices natively via Bluetooth as an external keyboard.
* **Configurable Delays:** Includes adjustable keystroke delays (`KEY_DELAY`) and attempt intervals (`ATTEMPT_DELAY`) to match device processing speeds.
* **Lockout Mitigation:** Built-in cooldown timers (e.g., pausing after a set number of attempts) to help manage device security timeout policies.
* **Targeted PIN Injection:** Supports prioritizing specific PIN attempts during execution sequences[cite: 1, 2].

---

## Prerequisites & Dependencies

### Hardware Required
* An ESP32 development board (e.g., ESP32 NodeMCU / ESP32-WROOM-32).
* A smartphone or target device with Bluetooth enabled.

### Software Required
* [Arduino IDE](https://www.arduino.cc/) or [PlatformIO](https://platformio.org/).
* **ESP32 Board Support package** installed in your IDE.
* **ESP32 BleKeyboard library** by T-vK. You can install it via the Arduino Library Manager by searching for `BleKeyboard`.

---

## Project Structure
```text
esp32-pin-bruteforce/
├── 4_digit_attack/          # Contains code for testing 4-digit combinations[cite: 1]
│   └── 4_digit_attack.ino
├── 6_digit_attack/          # Contains code for testing 6-digit combinations[cite: 2]
│   └── 6_digit_attack.ino
└── README.md
