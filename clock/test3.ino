#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

int hr;
int mn;
int sec;
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int con1 = 9;
int con2 = 10;
int con3 = 11;
int con4 = 12;
int blnk = 8;
int dl = 3;
int tempPin = A1;
int x, y, x1, y1, hr1, count, time = 0, pre = 0, post, flag = 0;


void setup() {
  Serial.begin(9600);
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));


  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(con1, OUTPUT);
  pinMode(con2, OUTPUT);
  pinMode(con3, OUTPUT);
  pinMode(con4, OUTPUT);
  pinMode(blnk, OUTPUT);
}

void num1() {
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num2() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num3() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(g, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num4() {
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num5() {
  digitalWrite(a, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num6() {
  digitalWrite(a, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num7() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num8() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num9() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void num0() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void numo() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void numC() {
  digitalWrite(a, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  delay(dl);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void glow(int x)
{
  if (x == 0) num0();
  else if (x == 1) num1();
  else if (x == 2) num2();
  else if (x == 3) num3();
  else if (x == 4) num4();
  else if (x == 5) num5();
  else if (x == 6) num6();
  else if (x == 7) num7();
  else if (x == 8) num8();
  else if (x == 9) num9();
}


void loop() {

  float val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 4800;
  float cel = mv / 10;
  int temp = cel;

  DateTime now = rtc.now();
  hr = now.hour();
  mn = now.minute();
  sec = now.second();
  post = sec;
  hr1 = hr % 12;
  if (hr1 == 0) hr1 = 12;

  count = hr1;
  y = count % 10;
  count = count / 10;
  x = count;
  Serial.println(hr);


  count = mn;
  y1 = count % 10;
  count = count / 10;
  x1 = count;
  if (x != 0) {
    digitalWrite(con1, LOW);
    glow(x);
  }
  digitalWrite(con1, HIGH);
  digitalWrite(con2, LOW);
  glow(y);
  digitalWrite(con2, HIGH);
  digitalWrite(con3, LOW);
  glow(x1);
  digitalWrite(con3, HIGH);
  digitalWrite(con4, LOW);
  glow(y1);
  digitalWrite(con4, HIGH);
  if(sec%2 == 0) digitalWrite(blnk, HIGH);
  else digitalWrite(blnk, LOW);
  time++;
  /*if (pre != post && flag == 0)
  {
    flag = 1;
    time = 0;
  }
  if (time <= 30) digitalWrite(blnk, HIGH);
  else {
    flag = 0;
    pre = post;
    digitalWrite(blnk, LOW);
  }*/
  //analogWrite(blnk, 150);
  if (sec == 10)
  {
    digitalWrite(blnk, LOW);
    delay(300);
    int mnth = now.month();
    int dy = now.day();
    count = dy;
    y = count % 10;
    count = count / 10;
    x = count;


    count = mnth;
    y1 = count % 10;
    count = count / 10;
    x1 = count;
    for (int i = 0; i < 200; i++)
    {
      digitalWrite(con1, LOW);
      glow(x);
      digitalWrite(con1, HIGH);
      digitalWrite(con2, LOW);
      glow(y);
      digitalWrite(con2, HIGH);
      digitalWrite(con3, LOW);
      glow(x1);
      digitalWrite(con3, HIGH);
      digitalWrite(con4, LOW);
      glow(y1);
      digitalWrite(con4, HIGH);
    }
    
    delay(300);
    count = temp;
    y = count % 10;
    count = count / 10;
    x = count;


    count = mnth;
    y1 = count % 10;
    count = count / 10;
    x1 = count;
    for (int i = 0; i < 200; i++)
    {
      digitalWrite(con1, LOW);
      glow(x);
      digitalWrite(con1, HIGH);
      digitalWrite(con2, LOW);
      glow(y);
      digitalWrite(con2, HIGH);
      digitalWrite(con3, LOW);
      numo();
      digitalWrite(con3, HIGH);
      digitalWrite(con4, LOW);
      numC();
      digitalWrite(con4, HIGH);
    }
    delay(300);
  }
}

