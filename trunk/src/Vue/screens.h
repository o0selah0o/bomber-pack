#ifndef SCREENS_H
#define SCREENS_H
 
//Basic Screen Class
#include "Screen.h"
 
//Including each screen of application
#include "Screen_0.h"
#include "Screen_Jeux.h"
 
enum {
   SCREEN_EXIT = -1,
   SCREEN_0, // Il sera intéressant de nommer correctement les labels
   SCREEN_Jeux  // Du type SCREEN_MENU, SCREEN_GAME, SCREEN_OPTIONS, etc...
}
 
#endif // SCREENS_HP
