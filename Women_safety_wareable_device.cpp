// #include <SPI.h>
// #include <Wire.h>
#include <Adafruit GFX.h> #include <Adafruit SSD1306.h> #include ASK.h>
RH ASK driver;
#include "MAX30100 PulseOximeter.h"
#define REPORTING PERIOD MS 1000
// PulseOximeter is the higher level interface to the sensor
// it offers:
// * beat detection reporting
// * heart rate calculation
// * Sp02 (oxidation level) calculation
PulseOximeter pox;
uint32 t tsLastReport = 0;
String Rvalue;
#define SCREEN WIDTH 128 // OLED display width, in pixels #define SCREEN HEIGHT 32 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to 12C (SDA, SCL pins)
// The pins for 12C are defined by the Wire-library.
// On an arduino UNO: 	A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO: 2(SDA), 3(SCL), ...
#define OLED RESET 4        // Reset pin # (or -l if sharing Arduino reset pin)
#define SCREEN ADDRESS Ox3C ///< See datasheet for Address; Ox3D for 128x64, Ox3C for 128x32
Adafruit SSD1306 display(SCREEN WIDTH, SCREEN HEIGHT, &Wire,
                         OLED RESET);
unsigned long oldtime3;
void setup()
{
    Serial.begin(9600);
    // SSD1306 SWITCHCAPVCC = generate display voltage from 3.3V internally
 SWITCHCAPVCC, SCREEN ADDRESS))
 {
     allocation failed ")); for(;;); // Don't proceed, loop forever
         if (!driver.init())
             Serial.println("init failed");
     if (!pox.begin())
     {

         // for(;;);
     }
     else
     {

         display.clearDisplay();
         display.display();
         void loop()
         {
             pox.update();
             // if (millis() - oldtime3 > 4000) { readRF433();
             // oldtime3=millis();
             if (millis() - tsLastReport > REPORTING PERIOD MS)
             {
                 // Clear the buffer.
                 // display.clearDisplay(); display.clearDisplay(); display.display(); // Display Text display.setTextSize( l); display.setTextC010r(WHITE)•, display.setCursor(0,0); display.print("BPM— "); display.println(pox.getHeartRate()); display.setCursor(0,8); display.print("Sp02= "); display.println(pox.getSp02()); display.setCursor(75,0); display.print("lntake"); display.setCursor(80,8); display.println(Rvalue); //display.print(" ml");

                 display.setTextSize(l);
                 display.print("Recom—");
                 display.println(" 1.5 lit ");
                 display.display(); // delay(200);
                 // display.clearDisplay(); display.display();
                 Serial.print("Heart rate: ");
                 Serial.print(pox.getHeartRate()); Serial.print("bpm / Sp02:  Serial.print(pox.getSp02());
Serial.println("%");
tsLastReport = millis();
String convertToString(char* a, int size)
int i;
String s  for (i = 0; i < size; i++) {
                        s = s + a[i];
                        return s;
                        void readRF433()
                        { uint8 t bun 12];
                            uint8 t buflen = sizeof(buf);
                            String val;
                            if (driver.recv(buf, &buflen))
                                Rvalue = convertToString(buf, 4);
                            Serial.print("rval incoming: ");
                            Serial.println(Rvalue);
                            Serial.print("Message: ");
                            Serial.print((char *)buf);
Serial.print("  Serial.println(buflen); val = String((char*)buf);
// Rvalue=val;
Rvalue = val.tolnt(); Serial.print("rval: ");
Serial.println(Rvalue);
String msg = getValue(Rvalue, ',', 0); String msg2 = getValue(Rvalue, ',', 1);
String zval = getValue(Rvalue, ',', 2);
Serial.print("rval: ");
Serial.println(msg);  	Serial.print("rva12: ");
 	Serial.println(msg2);   Rvalue    display.clearDisplay();   display.display();   display. setTextSize(1);
// display.setTextC010r(WHITE)•,   Serial.println("coming2");   display.setCursor(0,0);   display.print("Rec= 't);   display.print(Rvalue);   display.print(" ml ");   display.display();   oldtimel=millis();
String getValue(String data, char separator, int index)
int found = 0; int strlndex[]  int maxlndex = data.length() - l;
for (int i = 0; i <= maxlndex && found <= index; i++) {
                                if (data.charAt(i) — separator I l i == maxlndex)
                                {
                                    found++;
                                    strIndex[0] ¯ strlndex[l] + 1;
                                    strlndex[l] = (i == maxlndex) ? i + l return found > index ? data.substring(strIndex[0], strlndex[l]):
