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

## Repository Structure

```text
esp32-brute-force-attack-to-bypass-lock/
├── 4_Digit_Brute_Force_Attack/
│   └── sketch_aug24a/
│       └── sketch_aug24a.ino     # 4-digit PIN automation script[cite: 1]
├── 6_digit_brute_force_attack/
│   └── sketch_aug21b.ino           # 6-digit PIN automation script[cite: 2]
├── LICENSE
└── README.md
```



## Usage Instructions

1. Open either the 4_digit_attack or 6_digit_attack folder using the Arduino IDE.

2. Select your ESP32 board model from Tools > Board.

3. Compile and upload the sketch to your ESP32 board.

4. Open the Serial Monitor (set to 115200 baud) to monitor connection status and attempt progress.

5. Pair your phone/target device with the Bluetooth device named "ESP32 Keyboard".
