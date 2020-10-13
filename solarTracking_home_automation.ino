#define BLYNK_PRINT DebugSerial
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(13,12);

#include <BlynkSimpleStream.h>
int ldr1=2;
int ldr2=3;
int ldr3=4;
int solarClock=5;
int solarAntiClock=6;

int re[]={7,8,9,10};

char auth[]="";
void setup() {
  // put your setup code here, to run once:
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(ldr3,INPUT);
  pinMode(solarClock,OUTPUT);
  pinMode(solarAntiClock,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(Serial,auth);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  firstLDR();
  middleLDR();
  secondLDR();
}

void firstLDR(){
  if(!digitalRead(ldr1)){
    digitalWrite(solarClock,HIGH);
    DebugSerial.print("Clock wise");
  }else{
    digitalWrite(solarClock,LOW);
    DebugSerial.print(".......");
  }
}


void middleLDR(){
  if(!digitalRead(ldr2)){
    digitalWrite(solarClock,HIGH);
    DebugSerial.print("Clock wise");
    delay(600);
    digitalWrite(solarClock,LOW);
    digitalWrite(solarAntiClock,HIGH);
    delay(300);
    digitalWrite(solarAntiClock,LOW);
  }else{
    digitalWrite(solarClock,LOW);
    DebugSerial.print(".....");
  }
}



void secondLDR(){
  if(!digitalRead(ldr3)){
    digitalWrite(solarAntiClock,HIGH);
    DebugSerial.print("AntiClock wise");
    delay(600);
    digitalWrite(solarAntiClock,LOW);
  }else{
    digitalWrite(solarAntiClock,LOW);
    DebugSerial.print("AntiClock wise");
  }
}

BLYNK_WRITE(V8){
  if(param.asInt()){
    digitalWrite(re[0],HIGH);
    Blynk.virtualWrite(V10,"ON");
  }else{
    digitalWrite(re[0],LOW);
    Blynk.virtualWrite(V10,"OFF");
  }
}


BLYNK_WRITE(V7){
  if(param.asInt()){
    digitalWrite(re[1],HIGH);
    Blynk.virtualWrite(V11,"ON");
  }else{
    digitalWrite(re[1],LOW);
    Blynk.virtualWrite(V11,"OFF");
  }
}


BLYNK_WRITE(V6){
  if(param.asInt()){
    digitalWrite(re[2],HIGH);
    Blynk.virtualWrite(V12,"ON");
  }else{
    digitalWrite(re[2],LOW);
    Blynk.virtualWrite(V12,"OFF");
  }
}


BLYNK_WRITE(V5){
  if(param.asInt()){
    digitalWrite(re[3],HIGH);
    Blynk.virtualWrite(V13,"ON");
  }else{
    digitalWrite(re[3],LOW);
    Blynk.virtualWrite(V13,"OFF");
  }
}
