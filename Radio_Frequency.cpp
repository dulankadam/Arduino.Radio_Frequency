#include <VirtualWire.h> // Include the RF receiver library

const int receiverPin = 2; // Define the pin where your receiver module is connected

void setup() {
  Serial.begin(9600); // Initialize serial communication
  vw_set_ptt_inverted(true); // Required for some modules
  vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN]; // Create a buffer to hold the received data
  uint8_t buflen = VW_MAX_MESSAGE_LEN; // Set the buffer length to maximum
  
  if (vw_get_message(buf, &buflen)) { // Non-blocking, will return true if message received
    for (int i = 0; i < buflen; i++) {
      Serial.print(buf[i], HEX); // Print the received data in hexadecimal format
      Serial.print(' ');
    }
    Serial.println(); // Print a new line
  }
}
