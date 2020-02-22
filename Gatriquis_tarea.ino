
#include <Adafruit_TFTLCD.h>
#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#include <stdint.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define TS_MINX 125
#define TS_MINY 109
#define TS_MAXX 952
#define TS_MAXY 903

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define YP A2
#define XM A3
#define YM 8
#define XP 9

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

boolean buttonEnabled = true;

int Boton = 0;
int Turno = 1;
int Ocupado = 0;
int C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0, C6 = 0, C7 = 0, C8 = 0, C9 = 0;
int sgte = 0;
int Casilla11 = 2;
int Casilla12 = 3;
int Casilla13 = 4;
int Casilla21 = 5;
int Casilla22 = 6;
int Casilla23 = 7;
int Casilla31 = 8;
int Casilla32 = 9;
int Casilla33 = 10;
void setup() {

  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(BLUE);


  tft.setCursor(66, 66);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("BIENVENIDO ");
  tft.setCursor(60, 95);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("A GATRIQUIS");

  tft.fillRect(75, 130, 150, 40, CYAN);
  tft.drawRect(75, 130, 150, 40, BLACK);
  tft.setCursor(80, 140);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.print("  MIAU");

}

void loop() {

  TSPoint p = ts.getPoint();

  if (p.z > ts.pressureThreshhold) {

    p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, 240);

    //int PP = 0
    buttonEnabled = false;
    Serial.println(Casilla11);
    Serial.println(Casilla12);
    Serial.println(Casilla13);
    Serial.println(Casilla21);
    Serial.println(Casilla22);
    Serial.println(Casilla23);
    Serial.println(Casilla31);
    Serial.println(Casilla32);
    Serial.println(Casilla33);

   //TRABAJAMOS POR CASOS PARA CADA CASILLA 
    // FILA 1 COLUMNA 1
    if (p.x > 40 && p.x < 113 && p.y > 5 && p.y < 73 && C1 != HIGH && sgte == 1) {

      if (Turno % 2 != 0 && sgte == 1) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(60, 28);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
       
        C1 = HIGH;
        Casilla11 = 0;

        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU ");
        }
      }

      else if (Turno % 2 == 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(60, 28);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C1 = HIGH;
        Casilla11 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU ");
        }
      }
    }
     // FILA 2 COLUMNA 1
   if(p.x > 40 && p.x < 115 && p.y > 73 && p.y < 146 & C2 != HIGH && sgte==1){
      if (Turno % 2 != 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(60, 93);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        C2 = HIGH;
        Casilla12 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU ");
        }
      }

      else if (Turno % 2 == 0) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(60, 93);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C2 = HIGH;
        Casilla12 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
          tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU");
        }
      }
    }
    //FILA 3 COLUMNA 1
if (p.x > 40 && p.x < 113 && p.y > 147 && p.y < 220 && C3 != HIGH && sgte==1) {

      if (Turno % 2 != 0) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(60, 161);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        C3 = HIGH;
        Casilla13 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
          tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU");
          
        }
      }

      else if (Turno % 2 == 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(60, 161);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C3 = HIGH;
        Casilla13 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU");
        }
      }
    }
    //FILA 1 COLUMNA 2
    if (p.x > 96 && p.x < 169 && p.y > 5 && p.y < 73 && C4 != HIGH && sgte==1) {
      if (Turno % 2 != 0) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(134, 35);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        C4 = HIGH;
        Casilla21 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU");
        }
      }

      else if (Turno % 2 == 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(134, 35);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C4 = HIGH;
        Casilla21 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU");
        }
      }
    }
   //FILA 2 COLUMNA 2
    if (p.x > 96 && p.x < 169 && p.y > 73 && p.y < 147 && C5 != HIGH && sgte==1) {

      if (Turno % 2 != 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(134, 97);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        C5 = HIGH;
        Casilla22 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU");
        }
      }

      else if (Turno % 2 == 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(134, 97);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C5 = HIGH;
        Casilla22 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU");
        }
      }
    }
   //FILA 3 COLUMNA 2
    if (p.x > 96 && p.x < 169 && p.y > 147 && p.y < 219 && C6 != HIGH && sgte==1){
      if (Turno % 2 != 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(134, 165);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        C6 = HIGH;
        Casilla23 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU");
        }
      }

      else if (Turno % 2 == 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(134, 165);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C6 = HIGH;
        Casilla23 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);
          tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU ");
        }
      }
    }

   //FILA 1 COLUMNA 3
 if (p.x > 153.7 && p.x < 227.3 && p.y > 5 && p.y < 73 && C7 != HIGH && sgte==1)
 {
      if (Turno % 2 != 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(211, 27);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        C7 = HIGH;
        Casilla31 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU");
        }
      }

      else if (Turno % 2 == 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(211, 27);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C7 = HIGH;
        Casilla31 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU");
        }
      }
    }
    //FILA 2 COLUMNA 3
    if (p.x > 153.7 && p.x < 227.3 && p.y > 73 && p.y < 147 && C8 != HIGH && sgte==1) {

      if (Turno % 2 != 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(211, 93);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        C8 = HIGH;
        Casilla32 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU");
        }
      }

      else if (Turno % 2 == 0) {
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(211, 93);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C8 = HIGH;
        Casilla32 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU");
        }
      }
    }
    ////FILA 3 COLUMNA 3
    if (p.x > 153.7 && p.x < 227.2 && p.y > 147 && p.y < 220 && C9 != HIGH && sgte==1){
      if (Turno % 2 != 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(211, 168);
        tft.setTextColor(GREEN);
        tft.setTextSize(5);
        tft.print("X");

        Turno = Turno + 1;
        C9 = HIGH;
        Casilla33 = 0;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES X, MIAU");
        }
      }

      else if (Turno % 2 == 0) {

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        tft.setCursor(211, 168);
        tft.setTextColor(BLUE);
        tft.setTextSize(5);
        tft.print("O");

        Turno = Turno + 1;
        C9 = HIGH;
        Casilla33 = 1;
        if ((Casilla11 == Casilla12 && Casilla12 == Casilla13) || (Casilla11 == Casilla21 && Casilla21 == Casilla31) || (Casilla11 == Casilla22 && Casilla22 == Casilla33) ||
            (Casilla13 == Casilla22 && Casilla22 == Casilla31) || (Casilla21 == Casilla22 && Casilla22 == Casilla23) || (Casilla31 == Casilla32 && Casilla32 == Casilla33) ||
            (Casilla12 == Casilla22 && Casilla22 == Casilla32) || (Casilla13 == Casilla23 && Casilla23== Casilla33)) {
          tft.fillScreen(WHITE);tft.fillScreen(WHITE);
          tft.setCursor(66, 66);
          tft.setTextColor(BLACK);
          tft.setTextSize(3);
          tft.print("FELICITACIONES O, MIAU");
          
          
            }        
      }
    }
    
     if (p.x > 40 && p.x < 250 && p.y > 114 && p.y < 157 && Boton != HIGH){

      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
//DEFINIMOS PARAMETROS DE LA TABLILLA DE JUEGO 
      tft.fillScreen(RED);
      tft.drawRect(40, 5, 220, 220, WHITE);

      tft.fillRect(113, 5, 2, 220, WHITE);
      tft.fillRect(187, 5, 2, 220, WHITE);

      tft.fillRect(40, 73, 220, 2, WHITE);
      tft.fillRect(40, 147, 220, 2, WHITE);

      Boton = HIGH;

      sgte = 1;

    }

  }
}
