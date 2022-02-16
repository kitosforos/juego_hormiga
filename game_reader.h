#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"

typedef struct _Game Game;

STATUS game_load_spaces(Game *game, char *filename);
#endif