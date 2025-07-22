
🧰 ESP32DIVwroom32u
A modular RF toolkit for wireless exploration, signal capture, and jamming — powered by ESP32-WROOM-32U with rotary encoder and touchscreen input.
This is a reimagined fork of ESP32-DIV, optimized for a 2.8" ILI9341 display, SD logging, and expanded RF capabilities.

🚀 Features
- 📡 Wi-Fi scanner, packet sniffer, and deauth toolkit
- 📀 SD card logging for captured signals and configurations
- 🎛️ Rotary encoder interface (no buttons!)
- 🖱️ Optional touchscreen input via XPT2046 controller
- 🖥️ ILI9341 TFT display (2.8") with live signal visualization
- 📶 NRF24 and CC1101 RF modules for 2.4GHz and sub-GHz operations
- 🧱 Modular codebase for easy customization and expansion

📦 Hardware Overview
| Component | Description | 
| ESP32-WROOM-32U (16MB) | Core MCU with Wi-Fi, BLE, and external antenna support | 
| ILI9341 TFT Display (2.8") | 240×320 SPI screen for UI and signal feedback | 
| Rotary Encoder | Menu navigation and selection (push-to-select) | 
| XPT2046 Touchscreen | Resistive touch controller for optional tap input | 
| SD Card Slot | Stores logs, signals, and config files | 
| 3 × NRF24L01+ Modules | 2.4GHz RF transceivers for jamming and scanning | 
| CC1101 Module | Sub-GHz transceiver for replay/jamming (315/433/868/915 MHz) | 



🔧 Wiring Guide
| Signal | ESP32 GPIO | 
| TFT_CS | 15 | 
| TFT_RST | -1 | 
| TFT_DC | 2 | 
| TFT_MOSI | 13 | 
| TFT_SCLK | 14 | 
| TFT_BL | 27 | 
| Encoder CLK | 25 | 
| Encoder DT | 26 | 
| Encoder SW | 27 | 
| SD_CS | 5 | 
| Touch_CS | 33 | 
| Touch_IRQ | 36 | 
| Touch_CLK | 25 | 
| Touch_DIN | 32 | 
| Touch_DO | 39 | 



🛠️ Installation
- Clone the repo
git clone https://github.com/look4green/ESP32DIVwroom32u.git
- Open in Arduino IDE or PlatformIO
- Install required libraries:
- TFT_eSPI
- AiEsp32RotaryEncoder
- XPT2046_Touchscreen (optional)
- Configure User_Setup.h for ILI9341 and your pinout
- Flash to your ESP32 board

🎮 Controls
- Rotate encoder to scroll through menu
- Press encoder to select
- Tap screen (optional) to select or navigate
- Long press (optional): back or reset

🖱️ Touchscreen Support
Touch input is handled via the XPT2046 controller. You can use it to:
- Tap-to-select menu items
- Trigger actions without encoder
- Calibrate touch zones for precision
Touch is optional and can be disabled in code if using rotary-only mode.

📸 Screenshots / Demo
Add screenshots or GIFs of the UI once available.

🧪 Roadmap
- [ ] Modularize display and encoder logic
- [ ] Add rotary acceleration and wraparound
- [ ] Integrate OTA updates
- [ ] Add RF signal visualization overlays
- [ ] Touchscreen calibration and gesture support

🤝 Credits
- Forked from ESP32-DIV by CiferTech
- Rotary encoder via AiEsp32RotaryEncoder
- Touchscreen via XPT2046_Touchscreen

📄 License
MIT — feel free to fork, remix, and share!


