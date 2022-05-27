#include "Arduino.h"
#include "SoftwareSerial.h"
#include "sms.h"

SoftwareSerial serialGSM(10, 11); // RX, TX

smsClass::smsClass()
{
}

void smsClass::setup(void)
{
    serialGSM.begin(9600);

    serialGSM.print("AT+CMGF=1\n;AT+CNMI=2,2,0,0,0\n;ATX4\n;AT+COLP=1\n"); 
}

void smsClass::sendSMS(void)
{
    serialGSM.println("AT+CMGF=1");
    serialGSM.print("AT+CMGS=\"+5535988677726\"\n");
    serialGSM.print("Foi identificado uma vazamento de gás em sua residência\n");
    serialGSM.print((char)26); 
}

smsClass sms = smsClass();