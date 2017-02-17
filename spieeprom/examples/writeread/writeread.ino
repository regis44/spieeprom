#include <spieeprom.h>

SPIEEPROM eeprom(0);// parameter is type
                    // type=0: 16-bits address
                    // type=1: 24-bits address
                    // type>1: defaults to type 0

double testWrite[10] = {-12.59, -10.30, 2.45, 1287454, 9873.10, 34298, 5.63, 247, -128, -47943};
double testRead[10];

void setup() {
  Serial.begin(115200);
  while (!Serial);
  eeprom.begin();
}

void loop() {
  eeprom.write(0, testWrite);
  eeprom.read(0, testRead);
  for (int i = 0; i < 10; i++) 
  {
    Serial.print(testRead[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(10);
}
