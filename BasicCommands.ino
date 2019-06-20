#include <SoftwareSerial.h>
#include <MagicRC.h>

MagicRC myRC(8, 9, 3, 4, 5, 6); // Bluetooth TX, RX

void setup() {
  myRC.begin(9600); // Bluetooth baudrate
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case 'a':
        myRC.forward();
        break;
      case 'b':
        myRC.backward();
        break;
      case 'c':
        myRC.turnLeft();
        break;
      case 'd':
        myRC.turnRight();
        break;
      case 'e':
        myRC.stop();
        break;
      case 'f':
        int speed = Serial.parseInt();
        myRC.setSpeed(speed);
        break;
    }
  }
}
