#include <SoftwareSerial.h>

int btTX = 2;
int btRX = 3;
int pinFR = 12;
int pinRS = 11;
int pinVR = 10;
int rtSpeed = 0;

String myString = "";

SoftwareSerial mySerial(btTX, btRX);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  mySerial.begin(9600);

   if (Serial.available()) {
    Serial.write("Start...");
  }

  pinMode(pinRS, OUTPUT);
  digitalWrite(pinRS, HIGH);
  
  pinMode(pinVR, OUTPUT);
  rtSpeed = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  while (mySerial.available()) {
    char myChar = (char) mySerial.read();
    myString += myChar;
    delay(5);
  }

  if (!myString.equals("")) {
    Serial.println("input: "+myString);

    if (myString.equals("r")) {
        digitalWrite(pinRS, LOW);
        Serial.println("do: r ");
    }  else if (myString.equals("s")) {
        digitalWrite(pinRS, HIGH);
        Serial.println("do: s ");
    } else if (myString.equals("u")) {
        if (rtSpeed < 256) rtSpeed = rtSpeed + 30;
        analogWrite(pinVR, rtSpeed);
        Serial.println("do: u");
    } else if (myString.equals("d")) {
        if (rtSpeed > 0) rtSpeed = rtSpeed - 30;
        else rtSpeed = 0;
        analogWrite(pinVR, rtSpeed);
        Serial.println("do: d");
    }

    myString = "";
  }
  
  /*
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }

  if (Serial.available()) {
    mySerial.write(Serial.read());
  }*/
}
