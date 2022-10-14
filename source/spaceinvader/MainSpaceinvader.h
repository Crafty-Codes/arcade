#include "obj/Alien.h"
#include "obj/Plasma.h"
#include <list>

class MainSpaceinvader {
private:
  uint16_t timer = 0;
  Alien arr[5][3];
  std::list<Plasma*> shoots;
  enum DIRECTION { LEFT, RIGHT };
  DIRECTION direction = RIGHT;

  void createAliens(void);
  void handleAliens(void);
  void autoShoot(void);

public:
  MainSpaceinvader(void);
  void executeSpaceinvader(void);
};
