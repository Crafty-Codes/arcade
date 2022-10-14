#include "obj/Alien.h"
#include "obj/Plasma.h"
#include <list>

enum STATUS { PLAYING, LOST, WON };

class MainSpaceinvader {
private:
  STATUS status = PLAYING;
  Alien aliens[5][3];
  Plasma shoots[4]{Plasma(150, 150, 5, 2)};
  uint8_t timer = 0;
  enum DIRECTION { LEFT, RIGHT };
  DIRECTION direction = RIGHT;

  bool down = false;

  void createAliens(void);
  void handleAliens(void);
  void autoShoot(void);

public:
  MainSpaceinvader(void);
  void executeSpaceinvader(void);
};
