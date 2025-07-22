# 📡 ESP32DIVwroom32u

**Modernized and Modular Fork of ESP32-DIV Wireless Toolkit**

This firmware reimagines the original [ESP32-DIV](https://github.com/martin-ger/esp32-div) RF toolkit with a modular C++ architecture and cleaner logic flow — fully compatible with **ESP32-WROOM32U**, while preserving its iconic touchscreen UX, splash animation, and feature set.

---

## 🔧 Features

- 🖥️ Rotary + touchscreen menu interface (TFT ILI9341 + XPT2046)
- 📶 Wi-Fi scanner, deauth attack, packet sniffing
- 📡 Sub-GHz replay, jamming, signal capture (CC1101)
- 💾 SD logging and profile management
- 🔋 Bluetooth serial messaging
- ⚙️ Modern modular codebase (Arduino IDE 2.x compatible)

---

## 🧩 Architecture Overview

| Module                | Description                             |
|-----------------------|-----------------------------------------|
| `main.cpp`            | Entry point (replaces `ESP32-DIV.ino`)  |
| `Encoder.cpp/h`       | Rotary encoder input                    |
| `Touchscreen.cpp/h`   | Touch input via XPT2046                 |
| `Display.cpp/h`       | UI rendering and layout                 |
| `Splash.cpp/h`        | Original splash animation               |
| `Calibration.cpp/h`   | Touch zone mapping                      |
| `Menu.cpp/h`          | Navigation logic                        |
| `AppState.cpp/h`      | Mode execution based on menu state      |
| `Storage.cpp/h`       | SD file management                      |
| `WiFiTools.cpp/h`     | Wi-Fi scanner, deauth, sniffer          |
| `BluetoothTools.cpp/h`| Bluetooth comm interface                |
| `SubGHzTools.cpp/h`   | Sub-GHz signal tools (CC1101)           |
| `Diagnostics.cpp/h`   | Signal strength & module tests          |

---

## 📂 Legacy Source

To preserve original functionality and aid future migration, unmodified source files like `wifi.cpp`, `subghz.cpp`, and `bluetooth.cpp` have been archived under:

/legacy/ ├── wifi.cpp ├── subghz.cpp ├── bluetooth.cpp ├── utils.cpp/h ├── shared.h

---

## ⚙️ Setup Instructions

1. Flash to **ESP32-WROOM32U**
2. Wire TFT (ILI9341), Touch (XPT2046), Rotary Encoder, SD Card
3. Open the sketch in **Arduino IDE 2.3.6** or later
4. Install required libraries:
   - `TFT_eSPI`
   - `XPT2046_Touchscreen`
   - `AiEsp32RotaryEncoder`
   - `SD`
   - `WiFi`
   - `BluetoothSerial`
5. Compile & upload!

---

## 🔜 Future Plans

- `Config.cpp/h` for user settings & preferences
- OTA support via Wi-Fi or Bluetooth
- Advanced diagnostics & analytics
- Replay profile manager for RF toolkit

---

## 📘 Credits

- Based on [ESP32-DIV](https://github.com/martin-ger/esp32-div) by Martin Ger
- Modernized & maintained by [look4green](https://github.com/look4green)

---

## 💬 Community

Feel free to fork, contribute, or raise issues. This RF toolkit honors open-source legacy while paving the way for modern embedded dev.

> 📁 Framework, not just firmware. Modular. Respectful. Powerful.


You can drop this straight into README.md on your GitHub homepage. Want me to help tag a versioned release or write a changelog next? We’re cruising now 🧠📡💥


---

## ⚙️ Setup Instructions

1. Flash to **ESP32-WROOM32U**
2. Wire TFT (ILI9341), Touch (XPT2046), Rotary Encoder, SD Card
3. Open the sketch in **Arduino IDE 2.3.6** or later
4. Install required libraries:
   - `TFT_eSPI`
   - `XPT2046_Touchscreen`
   - `AiEsp32RotaryEncoder`
   - `SD`
   - `WiFi`
   - `BluetoothSerial`
5. Compile & upload!

---

## 🔜 Future Plans

- `Config.cpp/h` for user settings & preferences
- OTA support via Wi-Fi or Bluetooth
- Advanced diagnostics & analytics
- Replay profile manager for RF toolkit

---

## 📘 Credits

- Based on [ESP32-DIV](https://github.com/martin-ger/esp32-div) by Martin Ger
- Modernized & maintained by [look4green](https://github.com/look4green)

---

## 💬 Community

Feel free to fork, contribute, or raise issues. This RF toolkit honors open-source legacy while paving the way for modern embedded dev.

> 📁 Framework, not just firmware. Modular. Respectful. Powerful.
