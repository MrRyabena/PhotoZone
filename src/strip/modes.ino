static uint32_t tmr{};
int T = 200;

void redWheel() {
  static int16_t value{};

  if (millis() - tmr >= T) {
    static int8_t incr = 1;
    if (value >= 72) incr = -1;
    if (value <= 0) incr = 1;
    value += incr;

    uint8_t val = 192;
    val += value;
    strip.setWheel8(val);
    sendColor();
    tmr = millis();
  }
}

void colorWheel() {
  static uint8_t value{};
  if (millis() - tmr >= T) {
    strip.setWheel8(value++);
    sendColor();
    tmr = millis();
  }
}

void red() {
  strip.setRGB(255, 0, 0);
  sendColor();
}

void green() {
  strip.setRGB(0, 255, 0);
  sendColor();
}

void blue() {
  strip.setRGB(0, 0, 255);
  sendColor();
}

void purple() {
  strip.setRGB(139, 0, 255);
  sendColor();
}

