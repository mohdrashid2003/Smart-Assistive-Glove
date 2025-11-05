# Smart Assistive Glove

The Smart Assistive Glove is a low-cost wearable assistive device designed to help individuals with limited speech or mobility communicate essential needs easily. The glove uses **push buttons** to send predefined messages wirelessly to a caretaker via **433 MHz RF communication**, providing **visual, audio, and text-based feedback**.

---

##  Concept

Many differently-abled or paralyzed patients face difficulty in communicating their needs.  
This glove simplifies communication by **mapping each button to a specific message**:

| Button | Message Sent |
|--------|--------------|
| 1      | Assistance   |
| 2      | Emergency    |
| 3      | Food         |
| 4      | Tea          |

When a button is pressed, the message is **transmitted wirelessly** to the receiver unit, which displays the corresponding message on an **LCD** and can trigger audio/visual alerts.

---

##  Hardware Components Used

| Component | Quantity | Description |
|----------|----------|-------------|
| Arduino Uno (Transmitter) | 1 | Reads button inputs and encodes data |
| Arduino Uno (Receiver)    | 1 | Receives RF data and decodes messages |
| Push Buttons | 4 | User input interface |
| 433 MHz RF Transmitter | 1 | Sends data wirelessly |
| 433 MHz RF Receiver | 1 | Receives transmitted data |
| LCD Display (16x2 with I2C) | 1 | Shows received messages |
| Buzzer / Speaker (optional) | 1 | Audio feedback |
| LEDs (optional) | 4 | Visual indication |
| Power supply / USB cable | - | To power boards |

---

##  System Flow

**Transmitter (Glove Side):**
Button → Arduino → RF Transmitter → Wireless Signal

**Receiver (Caretaker Side):**
RF Receiver → Arduino → LCD Display / Buzzer → Caretaker Alert

---

## Communication Protocol
- **433 MHz RF Wireless Module**
- Data transmitted using **Serial / VirtualWire** communication (depending on implementation)

---

##  Code Structure
Smart-Assistive-Glove/
│
├── Transmitter/
│ └── transmitter_code.ino
│
└── Receiver/
└── receiver_code.ino


Upload the transmitter `.ino` to the glove Arduino and the receiver `.ino` to the caretaker unit Arduino.

---

##  Outcome
✔ Enables effective communication for differently-abled individuals  
✔ Lightweight, portable, and low-cost  
✔ Works within home range (typical use-case distances)

---

##  Possible Improvements (Future Work)
- Bluetooth / Wi-Fi (Mobile App alerts)
- Voice playback module (ISD1820 / DFPlayer Mini)
- GSM-based emergency SMS alerts
- Gesture-based activation using flex sensors

---

##  Author
**Mohammed Rashid K**  
B.Tech Electronics & Communication Engineering  

GitHub: https://github.com/mohdrashid2003  
LinkedIn: https://www.linkedin.com/in/mohdrashid-ece



