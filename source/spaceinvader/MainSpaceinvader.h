#include "obj/Alien.h"

class MainSpaceinvader {
private:
  Alien arr[5][3];
  enum DIRECTION { LEFT, RIGHT };
  DIRECTION direction = RIGHT;

  void createAliens(void);
  void handleAliens(void);

public:
  MainSpaceinvader(void);
  void executeSpaceinvader(void);
};
