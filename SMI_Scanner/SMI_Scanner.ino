#include "smi.h"

int i;
int j;
byte phyaddrHB;
byte phyaddrLB;
byte rData[2] = {0, 0};
byte wData[2] = {0, 0};
// unsigned long time;
// unsigned long timeb;
// unsigned long timee;

// Set Pin 5 as clock pin and pin 4 as data pin in SMI protocol
SMI smi(5, 4);

void setup() {
  // put your setup code here, to run once:
  // Set up UART protocol
  Serial.begin(9600);

  delay(5000);
  
  SMI_Scan();
}


void loop() {
  // put your main code here, to run repeatedly:
  //delay(1000);

  
  //phyaddrHB = 1;
  //phyaddrLB = 1;
  //smi.read(phyaddrHB, phyaddrLB, rData);
  //Serial.write(rData, 2);
}

void SMI_Scan() {
  // Initiate an SMI scan that will loop over all possible PHY and REG 5 bit combinations
  // We will see if we get data transmitted back to master from slave device and if we do send it via Serial.
  // Ideally we can use this information to reverse calculate RHY and REG addresses, in combination with an incomplete datasheet of the slave device
  // We found RealTek (or RTL) datasheets did not often tell us what PHY and REG for SMI protocol was 
  // So I was like "Fine, I'll do it myself"

  // We want to loop through all possible combinations of PHY and REG 

  
  for (phyaddrHB = 0; phyaddrHB < 32; phyaddrHB++) {
    for (phyaddrLB = 0; phyaddrLB < 32; phyaddrLB++) {
      delay(100);
      smi.read(phyaddrHB, phyaddrLB, rData);
      delay(10);
      Serial.write(phyaddrHB);
      delay(10);
      Serial.write(phyaddrLB);
      delay(10);
      Serial.write(rData, 2);
      delay(10);
    } 
  }
}
