#include <VirtualWire.h>

#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4
#define BUTTON4 5
#define RF_TX_PIN 12  // RF Transmitter Data Pin

void setup() {
    Serial.begin(9600);
    vw_setup(2000);   // Set transmission speed
    vw_set_tx_pin(RF_TX_PIN); 

    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);
    pinMode(BUTTON3, INPUT_PULLUP);
    pinMode(BUTTON4, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(BUTTON1) == LOW) {
        sendSignal("Assistance");
        Serial.println("Assistance Sent");
        delay(500);
    }
    if (digitalRead(BUTTON2) == LOW) {
        sendSignal("Emergency");
        Serial.println("Emergency Sent");
        delay(500);
    }
    if (digitalRead(BUTTON3) == LOW) {
        sendSignal("Food");
        Serial.println("Food Sent");
        delay(500);
    }
    if (digitalRead(BUTTON4) == LOW) {
        sendSignal("Tea");
        Serial.println("Tea Sent");
        delay(500);
    }
}

void sendSignal(const char *message) {
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx();  // Wait until message is sent
}