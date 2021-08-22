# LIM
Led Information Matrix

32x8 LED RGB Matrix for information display. Running on an NodeMCUv2.

Still in heavy development.

# Inspiration
- [AWTRIX](https://github.com/awtrix/AWTRIX2.0-Controller)
- [esp-rgb-led-matrix](https://github.com/BlueAndi/esp-rgb-led-matrix)

# Fixing Linking Errors with AsyncHTTPRequest_Generic
- See [Here](https://github.com/khoih-prog/AsyncHTTPRequest_Generic#howto-fix-multiple-definitions-linker-error)
- mv src src_h
- mv src_cpp src

# Constants.h
If a Constants.h file is present, constants will be loaded from there, otherwise defaults will be loaded that might not work with some applications (e.g. API Keys constants.) See main.cpp.

# Neopixels or FastLED
Right now FastLED has an issue where the first LED will now behave correctly, see [here](https://github.com/FastLED/FastLED/issues/1260).
For this reason, a configuratio for Neopixels exists.

# Aknowledgements and attributions
TomThub modified font thanks to [AWTRIX](https://github.com/awtrix/AWTRIX2.0-Controller)

Icons thanks to:
- Justin Cyr: https://twitter.com/JUSTIN_CYR/status/658031097805197313