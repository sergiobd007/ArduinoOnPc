#include "TFT_LinuxWrapper.h"
//#include "../libraries/Wire/Wire.h"
#define TFT_PC
#include "../libraries/GuiPittix/Gui.h"

//#include "Touch_LinuxWrapper.h" // TOUCH


TouchScreen ts;


GUI_Button button1 ( 150,100,"  up");
GUI_Button button2 (        "down");

GUI_Number number  ( 50, 50,"counter");

void setup()
{
  gui.begin();

  button1.show();
  button2.show();
  number.show();
}

int Counter = 0;

void loop(void)
{
  // read touch pad and tell the gui
  TSPoint p = ts.getPoint();
  gui.setTouch(p.x, p.y, p.z);

  if (button1.wasPressed())  Counter++;
  if (button2.wasPressed())  Counter--;

  number.print(Counter);

  delay(50);
}
