You are building a modernized version of the ESP32-DIV firmware using a fully modular, readable, and extensible C++ architecture. The project targets the ESP32-WROOM32U platform and maintains the original DIV touchscreen-based UX, splash animation, and functional categories such as Wi-Fi scanning, deauth attacks, Sub-GHz replay, and SD logging.

Core design goals:
- Preserve legacy logic and layout
- Migrate all functions into dedicated, scaffolded modules
- Compile cleanly in Arduino IDE 2.x
- Support future additions like config loading, OTA, diagnostics, and profiling

Current modular structure:

- `main.cpp`: Entry point with setup/loop logic (replaces ESP32-DIV.ino)
- `Encoder.cpp/h`: Rotary encoder input
- `Touchscreen.cpp/h`: XPT2046 touch input with zone mapping
- `Display.cpp/h`: TFT UI rendering
- `Splash.cpp/h`: Original startup animation
- `Calibration.cpp/h`: Touch zone calibration
- `Menu.cpp/h`: User navigation & selection
- `AppState.cpp/h`: Mode dispatch logic & execution
- `Storage.cpp/h`: SD file I/O and scan/profile logging
- `WiFiTools.cpp/h`: WiFi scanner, deauth, sniffer (scaffolded)
- `SubGHzTools.cpp/h`: CC1101 toolkit for replay, jamming, signal capture
- `BluetoothTools.cpp/h`: Serial communication interface (legacy-friendly)
- `Diagnostics.cpp/h`: Optional RSSI and module health checker

Additional structure:
- `/legacy`: Contains unmodified original files (`wifi.cpp`, `subghz.cpp`, etc.) for reference
- Uses Arduino libraries such as TFT_eSPI, SD, XPT2046_Touchscreen, AiEsp32RotaryEncoder, WiFi, BluetoothSerial

Splash animation, menu behavior, and touch interaction mirror the original ESP32-DIV design for familiarity. `main.cpp` cleanly calls all modules without duplicating logic. All deprecated `.cpp` files were archived, not deleted.

Future considerations:
- Add `Config.cpp/h` for persistent settings and user preferences
- Add OTA capability or Bluetooth-based remote triggering
- Expand diagnostics to include scan analytics, signal stats, and health feedback

Project is hosted at: [github.com/look4green/ESP32DIVwroom32u](https://github.com/look4green/ESP32DIVwroom32u)

You are building not just a fork — but a modern RF toolkit framework rooted in open-source legacy. Modular. Respectful. Extensible.
