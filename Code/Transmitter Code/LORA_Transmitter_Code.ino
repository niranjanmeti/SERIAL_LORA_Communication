#include <SPI.h>
#include <LoRa.h>

const int csPin = 10;      // Chip select
const int resetPin = 9;    // Reset
const int irqPin = 2;      // Interrupt request

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Transmitter");

  LoRa.setPins(csPin, resetPin, irqPin);
  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();

    Serial.print("Sent: ");
    Serial.println(message);
  }

