#include <allegro.h>
#include <iostream>
#include <stack>
#include <ctime>
#include <winalleg.h>

#define ELEPHANT 2
#define RHINOCEROS 1
#define MOUNTAIN 0


/// Graphic.hpp
#define RESOLUTION_X 800
#define RESOLUTION_Y 600


#define BOARD_X_BLIT 280
#define BOARD_Y_BLIT 80
#define GRID_DECAL 20
#define TILE_SIZE 80

#define COLOR_BLANC     makecol(255,255,255)
#define COLOR_NOIR      makecol(0,0,0)
#define COLOR_ROUGE       makecol(255,0,0)
#define COLOR_VERT     makecol(0,255,0)
#define COLOR_BEU      makecol(0,0,255)
#define COLOR_JAUNE   makecol(255,255,0)
#define COLOR_CYAN      makecol(0,255,255)
#define COLOR_ROSE      makecol(244,194,194)

// Game inputs
#define ARROW_UP          84 // KEY_UP equivalent
#define ARROW_BOTTOM      85
#define ARROW_LEFT        82
#define ARROW_RIGHT       83

#define BOARD_HEIGHT 5
#define BOARD_WIDTH  5
