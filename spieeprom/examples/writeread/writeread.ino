#include <spieeprom.h>

SPIEEPROM eeprom(0); // parameter is type
                     // type = 0: 16-bits address
                     // type = 1: 24-bits address
                     // type > 1: defaults to type 0

float testWrite[8] = {1, 2, 3, 4, 5, 6, 7, 8};
float testRead[8];
long address = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  eeprom.begin();
}

void loop() {
  eeprom.write(address, testWrite);
  eeprom.read(address, testRead);
  for (int i = 0; i < 8; i++)
  {
    Serial.print(testRead[i]);
    Serial.print(" ");
  }
  Serial.println();
  address += 8;
  for (int i = 0; i < 8; i++)
  {
    testWrite[i] += 8;
  }
  delay(200);
}
