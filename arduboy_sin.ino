#include <Arduboy2.h>
#include <Tinyfont.h>

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

int hoffset = 0;
int yoffset = 0;
int frequency = 1;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(2);
  arduboy.initRandomSeed();
}

void loop() {
  arduboy.clear();
  arduboy.drawLine(64 + hoffset, 0, 64 + hoffset, 128);
  arduboy.drawLine(0, 32 + yoffset, 128, 32 + yoffset);
  if (arduboy.pressed(RIGHT_BUTTON)) {
    hoffset += 1;
  }
  if (arduboy.pressed(LEFT_BUTTON)) {
    hoffset -= 1;
  }
  
  if (arduboy.pressed(UP_BUTTON)) {
    yoffset -= 1;
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    yoffset += 1;
  }
  if (arduboy.pressed(A_BUTTON)) {
    frequency += 2; 
  }
  if (arduboy.pressed(B_BUTTON)) {
    frequency -= 2;
  }
  
  tinyfont.setCursor(0, 0);
  tinyfont.print("X OFFSET: ");
  tinyfont.print(hoffset);
  tinyfont.print("\n");
  tinyfont.print("Y OFFSET: ");
  tinyfont.print(yoffset);
  
  for (int x = 0; x <= 128; x++) {
    double angle = ((x - hoffset) / 128.0) * 360.0 * frequency;
    int y = sin(angle * PI / 180) * 32;
    arduboy.drawPixel(x, y + 32 + yoffset, WHITE);
  }
  arduboy.display();
}
