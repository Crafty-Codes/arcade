#include "obj/Alien.h"
#include "obj/Plasma.h"
#include <list>

class MainSpaceinvader {
private:
  Alien aliens[5][3];
  Plasma shoots[4]{Plasma(128, 128, 5, 2)};
  int timer = 0;
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
