// Blink GPIO 4, 5 and 6 on the NORVI Neural project

const uint8_t LED_PINS[] = {4, 5, 6};
const uint8_t LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
const unsigned long BLINK_INTERVAL_MS = 500;

bool ledState = false;
unsigned long lastToggle = 0;

void setup() {
  Serial.begin(115200);
  for (uint8_t i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
  Serial.println("GPIO 4, 5, 6 blink started");
}

void loop() {
  unsigned long now = millis();
  if (now - lastToggle >= BLINK_INTERVAL_MS) {
    lastToggle = now;
    ledState = !ledState;
    for (uint8_t i = 0; i < LED_COUNT; i++) {
      digitalWrite(LED_PINS[i], ledState ? HIGH : LOW);
    }
    Serial.println(ledState ? "GPIO 4,5,6: ON" : "GPIO 4,5,6: OFF");
  }
}
