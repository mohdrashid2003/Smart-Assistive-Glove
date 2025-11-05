#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <VirtualWire.h>

#define RF_RX_PIN 7  // RF Receiver Data Pin
#define LED1 12       // LED for "Assistance"
#define LED2 13       // LED for "Emergency"
#define LED3 9        // LED for "Food"
#define LED4 8        // LED for "Tea"
#define BUZZER 2      // Buzzer Pin

// Initialize LCD with I2C address (try 0x27 or 0x3F depending on your module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    vw_set_rx_pin(RF_RX_PIN);
    vw_setup(2000); // Match transmission speed with transmitter
    vw_rx_start(); // Start the receiver

    // Initialize LEDs as outputs
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(BUZZER, OUTPUT); // Initialize buzzer pin as output

    // Initialize LCD
    lcd.begin(16,2);
    lcd.backlight(); // Turn on backlight
    lcd.setCursor(0, 0);
    lcd.print("Receiver Ready");
    delay(1000);
    lcd.clear();

    Serial.println("Receiver initialized");
}

// Function to beep the buzzer 3 times
void beepBuzzer() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(BUZZER, HIGH);
        delay(200);
        digitalWrite(BUZZER, LOW);
        delay(200);
    }
}

void loop() {
    uint8_t buf[12]; // Buffer to store received message
    uint8_t buflen = sizeof(buf);

    if (vw_get_message(buf, &buflen)) { // If a message is received
        buf[buflen] = '\0'; // Null-terminate the string
        Serial.print("Message received: ");
        Serial.println((char*)buf);

        // Turn off all LEDs and clear LCD first
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        lcd.clear();

        // Beep the buzzer when a message is received
        beepBuzzer();

        if (strcmp((char*)buf, "Assistance") == 0) {
            Serial.println("ACTION: Assistance requested");
            digitalWrite(LED1, HIGH);
            lcd.setCursor(0, 0);
            lcd.print("Assistance");
            delay(5000); 
            digitalWrite(LED1, LOW);
            lcd.clear();
        } 
        else if (strcmp((char*)buf, "Emergency") == 0) {
            Serial.println("ACTION: Emergency situation!");
            digitalWrite(LED2, HIGH);
            lcd.setCursor(0, 0);
            lcd.print("Emergency");
            delay(5000);
            digitalWrite(LED2, LOW);
            lcd.clear();
        } 
        else if (strcmp((char*)buf, "Food") == 0) {
            Serial.println("ACTION: Food requested");
            digitalWrite(LED3, HIGH);
            lcd.setCursor(0, 0);
            lcd.print("Food");
            delay(5000);
            digitalWrite(LED3, LOW);
            lcd.clear();
        } 
        else if (strcmp((char*)buf, "Tea") == 0) {
            Serial.println("ACTION: Tea requested");
            digitalWrite(LED4, HIGH);
            lcd.setCursor(0, 0);
            lcd.print("Tea");
            delay(5000);
            digitalWrite(LED4, LOW);
            lcd.clear();
        }
    }
}
