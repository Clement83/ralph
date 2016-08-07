//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
//imports the Gamebuino library
#include <Gamebuino.h>
//creates a Gamebuino object named gb
Gamebuino gb;

const byte gameover[] PROGMEM = {88,48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xF,0xC3,0xF3,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xAF,0xFF,0xFE,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0x6F,0xBF,0xEB,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xD8,0x7F,0xC7,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xF7,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xE0,0x7F,0xFC,0x78,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFD,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF7,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFB,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFB,0xFF,0xFF,0xFC,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0x8B,0xFF,0xFF,0xFC,0x97,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0x1F,0xEF,0xFF,0x7F,0xF7,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0x0,0x7F,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0x0,0x7F,0xBF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xE0,0x0,0x7F,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFB,0xC6,0x3,0x1E,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFB,0xC6,0x3,0x1E,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xC0,0x0,0x1D,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xEF,0xC1,0x8C,0x1C,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0x41,0x8C,0x1B,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xC0,0x40,0x0,0x18,0x17,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xC0,0xC0,0x0,0x10,0x17,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xE0,0xC1,0x8C,0x10,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xE0,0xC1,0x8C,0x10,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xE0,0xC1,0x8C,0x18,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xE0,0xC0,0x0,0x18,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xE0,0x40,0x0,0x10,0x3F,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFE,0x0,0x0,0x3,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFE,0x0,0x0,0x3,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFE,0x0,0x0,0x3,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0x0,0x0,0x0,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0x0,0x0,0x0,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0x30,0x0,0x60,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0x30,0x0,0x60,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0xFF,0xFF,0xF8,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0xFF,0xFF,0xF8,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0xFF,0xFF,0xF8,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0xC7,0xFF,0x18,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0xC7,0xFF,0x18,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0xF0,0x0,0x78,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0xF0,0x0,0x78,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xF8,0x70,0x0,0x70,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0x0,0x0,0x3,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0x0,0x0,0x3,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xC0,0x0,0x1F,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xC0,0x0,0x1F,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF,0xFF,0xC0,0x0,0x1F,0xFF,0xFF,0xFF,0xF0,};

const byte floors[] PROGMEM = {40,37,0xF7,0xFF,0xFF,0xFF,0xDE,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0xF7,0xFF,0xFF,0xFF,0xDE,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0xF7,0xFF,0xFF,0xFF,0xDE,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0xF7,0xFF,0xFF,0xFF,0xDE,};
const byte GroundFloor[] PROGMEM = {40,11,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x0,0x0,0x58,0x1C,0x0,0x0,0x0,0x70,0x34,0x0,0x30,0x0,0x58,0x1C,0x0,0x48,0x0,0x70,0x34,0x0,0x84,0x0,0x58,0x1C,0x0,0x84,0x0,0x70,0x34,0x0,0x84,0x0,0x58,0x1C,0x0,0x84,0x0,0x70,};
const byte RoofTop10[] PROGMEM = {40,11,0x7C,0x0,0x0,0x3,0xFC,0x92,0x40,0x0,0x4A,0x4A,0xFF,0xF8,0x1,0x37,0xFE,0x82,0x9,0x0,0x60,0x82,0x44,0xA,0x0,0xB8,0x44,0x34,0x54,0x0,0x24,0x58,0x1C,0xA6,0x0,0x42,0x70,0x34,0x9B,0x0,0x5A,0x58,0x1C,0xA2,0x80,0xE6,0x70,0x34,0xC0,0x81,0x80,0x58,0x1C,0x0,0xFE,0x0,0x70,};
const byte RoofTop50[] PROGMEM = {40,11,0x7F,0xFC,0x0,0x3F,0xFC,0x92,0x49,0x0,0x52,0x4A,0xFF,0xFF,0x83,0xBF,0xFE,0x82,0x0,0x44,0x0,0x82,0x44,0x8,0x28,0x38,0x44,0x34,0x54,0x78,0x44,0x58,0x1C,0xA2,0x88,0x82,0x70,0x34,0x92,0x94,0x9A,0x58,0x1C,0x82,0x82,0xA6,0x70,0x34,0xFE,0xFE,0xC0,0x58,0x1C,0x0,0x0,0x0,0x70,};
const byte RoofTop99[] PROGMEM = {40,11,0x7F,0xFF,0xFF,0xFF,0xFC,0x92,0x49,0x24,0x92,0x4A,0xFF,0xFF,0xFF,0xFF,0xFE,0x82,0x0,0x0,0x0,0x82,0x44,0x38,0x38,0x38,0x44,0x34,0x44,0x44,0x44,0x58,0x1C,0x82,0x82,0x82,0x70,0x34,0x82,0x82,0x82,0x58,0x1C,0x82,0x82,0x82,0x70,0x34,0xFE,0xFE,0xFE,0x58,0x1C,0x0,0x0,0x0,0x70,};
const byte RoofTop100[] PROGMEM = {40,11,0x7F,0xFF,0xFF,0xFF,0xFC,0x92,0x49,0x24,0x92,0x4A,0xFF,0xFF,0xFF,0xFF,0xFE,0x82,0x0,0x0,0x0,0x82,0x44,0x38,0x38,0x38,0x44,0x34,0x44,0x44,0x44,0x58,0x1C,0x82,0x82,0x82,0x70,0x34,0x82,0x82,0x82,0x58,0x1C,0x82,0x82,0x82,0x70,0x34,0xFE,0xFE,0xFE,0x58,0x1C,0x0,0x0,0x0,0x70,};

const byte splash_screen[] PROGMEM = {88,42,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x19,0xB0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF,0xB0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0xFC,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3F,0xF0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x78,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF,0xF6,0xDF,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x39,0xF9,0x27,0xF8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF8,0xFB,0xA7,0xFE,0x0,0x0,0x0,0x80,0x0,0x40,0x3,0xF8,0xF7,0xCF,0xFF,0x80,0x0,0x0,0x40,0x80,0x80,0x7,0xFC,0x73,0x9F,0xFF,0x80,0x0,0x0,0x20,0x81,0x0,0x7,0xFC,0x60,0x1F,0xFF,0x80,0x0,0x0,0x10,0x82,0x0,0xF,0xFC,0x61,0xDF,0xFF,0xC0,0x0,0x0,0x8,0x84,0x0,0xF,0xFE,0x22,0x1F,0xFF,0xC0,0x0,0x0,0x4,0x8,0x0,0xF,0xFE,0x30,0x1F,0xFF,0xC0,0x0,0x6,0x0,0x0,0x70,0x1F,0xFE,0x18,0x3F,0xFF,0xE0,0x0,0x1,0xE0,0xF3,0xC0,0x1D,0xDE,0x1F,0xFF,0xFC,0xE0,0x0,0x0,0x4,0xF0,0x0,0x10,0xDE,0x1F,0xFF,0xEC,0x60,0x0,0x0,0x7,0xF0,0x0,0x10,0x6,0x1F,0xFF,0xE0,0x10,0x0,0xE,0x7,0xF0,0x0,0x10,0x6,0x3F,0xFF,0xE0,0x10,0x0,0x3F,0xC3,0xF0,0x0,0x10,0x4,0x1F,0xFF,0xE0,0x10,0x0,0x3F,0xF3,0x80,0x0,0x10,0x6,0xBF,0xFF,0xE0,0x10,0x0,0xFF,0xF3,0x80,0x0,0x10,0x6,0x3F,0xFF,0xC0,0x10,0x0,0xFF,0xE3,0x80,0x0,0x10,0x6,0x3F,0xFF,0xC0,0x10,0x0,0xFF,0xC3,0x80,0x0,0x10,0x7,0xFF,0xFF,0xC0,0x10,0x0,0xF7,0x43,0x80,0x0,0x10,0x7,0xFF,0xFF,0xC0,0x10,0x0,0x72,0x47,0x80,0x0,0x10,0x7,0xFF,0xFF,0xC0,0x10,0x0,0x7F,0xE7,0x80,0x0,0x10,0x7,0xFF,0xFF,0xC0,0x10,0x0,0x7F,0x67,0x0,0x0,0x10,0x7,0xFF,0xFF,0x80,0x10,0x0,0x77,0x7E,0x0,0x0,0x10,0x3F,0xFF,0xFF,0xF8,0x10,0x0,0x18,0xFC,0x0,0x0,0x10,0x1,0xFF,0xFF,0x80,0x10,0x0,0xF,0xF0,0x0,0x0,0x10,0x0,0xFF,0xFF,0x0,0x10,0x0,0x1F,0xF0,0x0,0x0,0x10,0x0,0xFF,0xFE,0x0,0x10,0x0,0x3F,0xC0,0x0,0x0,0x10,0x0,0x7F,0xFC,0x0,0x10,0x0,0xFF,0x80,0x0,0x0,0x10,0x0,0x7F,0xFC,0x0,0x10,0x0,0xEF,0x0,0x0,0x0,0x10,0x18,0x7F,0xFE,0x70,0x10,0x1,0xCF,0x0,0x0,0x0,0x10,0x6E,0xFF,0xFE,0xA0,0x30,0x1,0xEF,0x0,0x0,0x0,0x10,0xA1,0xFF,0xFF,0x10,0x20,0x0,0xFF,0x0,0x0,0x0,0x11,0x11,0xFF,0xFF,0x12,0x20,0x0,0x7F,0x0,0x0,0x0,0xF,0xFF,0xFF,0xFF,0xFF,0xC0,0x0,0x7F,0x0,0x0,0x0,};

const byte idle[] PROGMEM = {16,15,0x2,0x0,0x7,0x40,0xF,0xE0,0xF,0xE0,0x1D,0x70,0x14,0x50,0x32,0xB8,0x72,0x9C,0xF1,0x1E,0xF8,0x3E,0x8F,0xE2,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xE,0xE0,};
const byte punch[] PROGMEM = {16,15,0xF2,0x1E,0xD7,0x56,0xBF,0xFA,0x8F,0xE2,0xFB,0x7E,0xF8,0x3E,0xFA,0xBE,0xF2,0x9E,0x71,0x1C,0x18,0x30,0xF,0xE0,0xF,0xE0,0xF,0xE0,0xF,0xE0,0xE,0xE0,};
const byte walk1[] PROGMEM = {16,15,0x2,0x0,0x7,0x40,0xF,0xE0,0xF,0xE0,0x1D,0x70,0x14,0x50,0x3A,0xB8,0x72,0x9C,0xF1,0x1E,0xF8,0x3E,0x8F,0xE2,0xFF,0xFE,0xF1,0xFE,0xF1,0xFE,0xE,0xE0,};
const byte walk2[] PROGMEM = {16,15,0x2,0x0,0x7,0x40,0xF,0xE0,0xF,0xE0,0x1D,0x70,0x14,0x50,0x3A,0xB8,0x72,0x9C,0xF1,0x1E,0xF8,0x3E,0x8F,0xE2,0xFF,0xFE,0xFF,0x1E,0xFF,0x1E,0xE,0xE0,};

const byte windows10[] PROGMEM = {8,9,0x1C,0x16,0x28,0xC6,0xA2,0x12,0xAA,0xC6,0x7C,};
const byte windows50[] PROGMEM = {8,9,0xFE,0x86,0x88,0xD6,0xB2,0x12,0xAA,0xC6,0xFC,};
const byte windows99[] PROGMEM = {8,9,0xFE,0x96,0x98,0xD6,0xBE,0x92,0x92,0xD6,0xFC,};
const byte windows100[] PROGMEM = {8,9,0xFE,0x92,0x92,0x92,0xFE,0x92,0x92,0x92,0xFE,};

const byte titleScreen[] PROGMEM = {64,36,0x0,0x0,0x0,0x3F,0xFE,0x0,0x0,0x0,0x0,0x0,0x0,0x1F,0xF8,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0xFE,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x1E,0x0,0x0,0x0,0x0,0x0,0x7,0xFB,0x6F,0xE0,0x0,0x0,0x0,0x0,0x1C,0xFC,0x93,0xFC,0x0,0x0,0x0,0x0,0x7C,0x7D,0xD3,0xFF,0x0,0x0,0x0,0x1,0xFC,0x7B,0xE7,0xFF,0xC0,0x0,0x0,0x3,0xFE,0x39,0xCF,0xFF,0xC0,0x0,0x0,0x3,0xFE,0x30,0xF,0xFF,0xC0,0x0,0x0,0x7,0xFE,0x30,0xEF,0xFF,0xE0,0x0,0x0,0x7,0xFF,0x11,0xF,0xFF,0xE0,0x0,0x0,0x7,0xFF,0x18,0xF,0xFF,0xE0,0x0,0x0,0xF,0xFF,0xC,0x1F,0xFF,0xF0,0x0,0x0,0xE,0xEF,0xF,0xFF,0xFE,0x70,0x0,0x0,0x8,0x6F,0xF,0xFF,0xF6,0x30,0x0,0x0,0x8,0x3,0xF,0xFF,0xF0,0x8,0x0,0x0,0x8,0x3,0x1F,0xFF,0xF0,0x8,0x0,0x0,0x8,0x2,0xF,0xFF,0xF0,0x8,0x0,0x0,0x8,0x3,0x5F,0xFF,0xF0,0x8,0x0,0x0,0x8,0x3,0x1F,0xFF,0xE0,0x8,0x0,0x0,0x8,0x3,0x1F,0xFF,0xE0,0x8,0x0,0x0,0x8,0x3,0xFF,0xFF,0xE0,0x8,0x0,0x0,0x8,0x3,0xFF,0xFF,0xE0,0x8,0x0,0x0,0x8,0x3,0xFF,0xFF,0xE0,0x8,0x0,0x0,0x8,0x3,0xFF,0xFF,0xE0,0x8,0x0,0x0,0x8,0x3,0xFF,0xFF,0xC0,0x8,0x0,0x0,0x8,0x1F,0xFF,0xFF,0xFC,0x8,0x0,0x0,0x8,0x0,0xFF,0xFF,0xC0,0x8,0x0,0x0,0x8,0x0,0x7F,0xFF,0x80,0x8,0x0,0x0,0x8,0x0,0x7F,0xFF,0x0,0x8,0x0,0x0,0x8,0x0,0x3F,0xFE,0x0,0x8,0x0,0x0,0x8,0x0,0x3F,0xFE,0x0,0x8,0x0,0x0,0x8,0xC,0x3F,0xFF,0x38,0x8,0x0,0x0,0x8,0x37,0x7F,0xFF,0x50,0x18,0x0,0x0,0x8,0x50,0xFF,0xFF,0x88,0x10,0x0,};



int roofLevel(int y);
int camX;
int camY;

#define S_GAME 0
#define S_GAME_OVER 1
#define S_INTRO 10
#define S_END_GAME 20
int state;

typedef struct {
  int life;
  int x,y;
}
Fenetre;

typedef struct {
  int status;
  int x,y;
}
Mobile;

#define NB_FENTRES 18
#define NB_LINES 6
#define LIFE_FENTRE 100

Fenetre fenetres[NB_FENTRES + 1];//+1 for rooftop
Mobile ralph;
#define HIT_RALPH 4

// the setup routine runs once when Gamebuino starts up
void setup(){
  // initialize the Gamebuino object
  gb.begin();
  //display the main menu:
  goToTitleScreen();
}

void goToTitleScreen()
{
  gb.titleScreen(F("I'm gonna wreck'it"), titleScreen);
  initGame();
}


void initGame()
{
  initWord();
  initWindow();
  initRalph();
  state = S_GAME;
  gb.battery.show = false;
}

// the loop routine runs over and over again forever
void loop(){
  //updates the gamebuino (the display, the sound, the auto backlight... everything)
  //returns true when it's time to render a new frame (20 times/second)
  if(gb.update()){
    if(gb.buttons.pressed(BTN_C)) {
      goToTitleScreen();
    }
    switch (state)
    {
      case S_GAME : 
        drawWord();
        drawWindow();
        drawRalph();
        
        updateWord();
        updateWindow();
        updateRalph();
        
        if(gb.buttons.pressed(BTN_UP)) {
          camY--;
        } else if(gb.buttons.pressed(BTN_DOWN)) {
          camY++;
        }
        
        if(gb.buttons.pressed(BTN_LEFT)) {
          camX--;
        } else if(gb.buttons.pressed(BTN_RIGHT)) {
          camX++;
        }
        break;
        case S_GAME_OVER :
          if(gb.buttons.pressed(BTN_A) || gb.buttons.pressed(BTN_B)) {
            state = S_GAME;
            initGame();
          }
          gb.display.drawBitmap(0,0, gameover);
        break;
        case S_INTRO :
          state = S_GAME;
        break;
        case S_END_GAME :
          drawWord();
          drawWindow();
          drawRalph();
          
          updateWord();
          updateWindow();
          updateEndGameRalph();
          //state = S_GAME;
        break;
    }
  }
}