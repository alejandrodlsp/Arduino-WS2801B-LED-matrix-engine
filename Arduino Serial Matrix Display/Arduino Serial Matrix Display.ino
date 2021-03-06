#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
  #define PSTR // Make Arduino Due happy
#endif
#include "Definitions.h"
#include "Shape.h"

// Control PIN
#define LED_PIN 10
#define BUZZER_PIN 12

// Set the brightness (max 50)
int brigh = 50;
// Delay between animation
int wait = 300;

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(11, 11, LED_PIN,  // INNIT MATRIX
  NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);

// TEXT PRINTING VARIABLES
int x = matrix.width();
int pass = 0;
int currentAnimation = 0;
uint16_t textColor = matrix.Color(0, 0, 0);
int textSpeed = 100;
String text = "";

// SERIAL CONNECTION
String serialInput = "";
String command = "";
String data = "";

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT); // BUZZER INNIT

  matrix.begin(); // MATRIX INNIT
  matrix.setTextWrap(false);
  matrix.setBrightness(brigh);

  Serial.begin(9600); // SERIAL INNIT
  Serial.setTimeout(10);
}

//-------------------------------------------------------------------------------------
#pragma region SerialCommunication

// SERIAL COMMUNICATION DATA STRICTURE:
//    COMMAND(A-Z)/DATA(STRING)/ VALUE (STRING)
//
//    COMMANDS:   A: TEXT      / COLOR (R+G+B)    / SPEED
//                B: ANIMATION    (B/{ANIMATION NUMBER})
//                E: STOP      (Stops all animations on the matrix)
//

void loop()
{

  if (text != "") // WRITE TEXT WHEN AVAILABLE
  {
    writeColor(text, textColor, textSpeed);
  }
  else
  {
    if (currentAnimation != 0)
      animate();
    else
    {
      Serial.println("L");
      clearScreen();
    }
  }

  serialInput = Serial.readString();  // READ SERIAL DATA
  if (serialInput == "") // IF NO DATA IS AVAILABLE RETURN
    return;

  command = serialInput;
  command.remove(serialInput.indexOf("/", 0)); // REMOVE EVERYTHING TO THE LEFT OF THE FIRST /

  data = serialInput;
  data.remove(0, 2);  // REMOVE FIRST TWO CHARACTERS

  if (command == "A")
  {      // PRINT TEXT COMMAND ~~   TEXT/ RED GREEN BLUE / SPEED
    String _speed = data;
    String _color = data;
    _speed.remove(0, data.indexOf("/", 1) + 11);  // REMOVE EVERYTHING TO THE LEFT OF THE / (Isolates speed param)
    _color.remove(0, data.indexOf("/", 1) + 1); // REMOVE EVERYTHING To THE LEFT OF THE FIRST / (Isolates color and speed)
    _color.remove(9, 13); // REMOVE EVERYTHING To THE RIGHT OF THE OTHER / (Isolates color)
    data.remove(data.indexOf("/", 0)); // REMOVE EVERYTHING TO THE RIGHT OF THE FIRST / (Isolates text)

    Serial.println(_color);
    textColor = getColorFromString(_color);
    textSpeed = _speed.toInt();
    text = data;
  }
  else if (command == "B")
  {
    currentAnimation = 0;
  }
  else if (command == "C")
  {
    currentAnimation = 1;
  }
  else if (command == "D")
  {
    currentAnimation = 2;
  }
  else if (command == "F")
  {
    currentAnimation = 3;
  }
  else if (command == "G")
  {
    currentAnimation = 4;
  }
  else if (command == "E")
  {
    clearScreen();
  }

}

#pragma endregion
//-----------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------
#pragma region util
void clearScreen()
{
  matrix.fillScreen(0);
  x = 0;
  text = "";
  writeColor("", WHITESMOKE, 0);
}

uint16_t getColorFromString(String _color)
{
  String red = _color, green = _color, blue = _color;
  red.remove(3, 8);
  green.remove(0, 3);
  green.remove(3, 6);
  blue.remove(0, 6);
  int _red = red.toInt(), _green = green.toInt(), _blue = blue.toInt();
  return (matrix.Color(_red, _green, _blue));
}
#pragma endregion
//------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------
#pragma region Display

// Set the color of animation (see Definitions.h)

void sprite(const uint8_t* x, unsigned long y, int w)
{   // PRINT SPRITE
  byte red = (y & 0xFF0000) >> 16;
  byte green = (y & 0x00FF00) >> 8;
  byte blue = (y & 0x0000FF);
  matrix.drawBitmap(1, 1, x, 8, 8, matrix.Color(red, green, blue));
  matrix.show();
  delay(w);
  matrix.fillScreen(0);
}

void writeColor(String y, uint16_t _color, int _speed)
{   // PRINT TEXT
  int len = y.length();
  matrix.fillScreen(0);
  matrix.setCursor(x, 2);
  matrix.print(y);
  matrix.setTextColor(_color);
  if (--x < -len * 6)
  {
    x = matrix.width();
    matrix.setTextColor(_color);
    pass = 0;
  }
  matrix.show();
  delay(_speed);
}

void animate()
{
  switch (currentAnimation)
  {
  case 1:
    face();
    break;
  case 2:
    dog();
    break;
  case 3:
    dance();
    break;
  case 4:
    sprite(youtube1, RED, 3000);
    sprite(youtube2, RED, 3000);
  }
  currentAnimation = 0;
}
#pragma endregion
//-----------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------//
