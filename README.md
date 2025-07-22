📡 ESP32DIVwroom32u
🔧 Modular Modernization of the Original ESP32-DIV Wireless Toolkit
This project reimagines the iconic ESP32-DIV firmware using a fully modular structure, while preserving original features, layout, and touchscreen behavior. Designed for ESP32-WROOM32U, this version uses rotary + touchscreen navigation and SD-backed data logging.

📁 Features
- 🖥️ TFT display menu interface with rotary + touch support
- 📶 Wi-Fi scanner, deauth attack, and packet sniffing
- 📡 Sub-GHz tools (CC1101) for jamming, capture, and replay
- 💾 SD card logging and profile management
- 🔋 Bluetooth serial support for remote triggering
- ⚙️ Modular C++ architecture (Arduino IDE compatible)

🧩 Modular Architecture
| Module               | Role                          | 
| Encoder.cpp/h        | Rotary encoder input          | 
| Touchscreen.cpp/h    | XPT2046 touch input           | 
| Display.cpp/h        | TFT UI rendering              | 
| Splash.cpp/h         | Original splash screen        | 
| Menu.cpp/h           | Navigation logic              | 
| AppState.cpp/h       | State management              | 
| Storage.cpp/h        | SD card file handling         | 
| Calibration.cpp/h    | Touch zone mapping            | 
| WiFiTools.cpp/h      | Wi-Fi scanner + deauth        | 
| BluetoothTools.cpp/h | Remote Bluetooth interface    | 
| SubGHzTools.cpp/h    | CC1101 signal toolkit         | 
| Diagnostics.cpp/h    | Module testing and RSSI check | 



🔧 Setup
- Flash to ESP32-WROOM32U
- Wire up TFT (ILI9341), XPT2046, rotary encoder, SD module
- Open main.cpp in Arduino IDE 2.x
- Install necessary libraries:
- TFT_eSPI, XPT2046_Touchscreen, AiEsp32RotaryEncoder, SD, WiFi, BluetoothSerial
- Compile and upload 🚀

🗂️ Legacy Files
To preserve original firmware behavior, untouched source files (e.g. wifi.cpp, subghz.cpp) have been moved to the /legacy folder for reference.


