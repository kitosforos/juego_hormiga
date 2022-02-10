/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
  * @brief crea una estructura Graphic_engine
  * @author Marcos Alonso
  *
  * crea una estructura Graphic_engine y la 
  * inicializa con un nuevo area dentro de una pantalla
  * 
  * @return la estructura inicializada
  */

Graphic_engine *graphic_engine_create();

/**
  * @brief elimina el contenido de una estructura Graphic_engine
  * @author Marcos Alonso
  *
  * borra el contenido, limpia las areas de todas las variables
  * que componen la estructura pasada como argumento
  * 
  * @param ge una estructura Graphic_engine que quieres resetear
  */

void graphic_engine_destroy(Graphic_engine *ge);

/**
  * @brief pinta el espacio y los graficos del juego
  * @author Marcos Alonso
  *
  * crea todos los graficos del juego, incluyendo el mapa, la hormiga,
  * la comida... etc
  * 
  * @param ge estructura usada para crear los graficos
  * @param game estructura usada para los datos del juego
  */

void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
  * @brief funcion desconocida temporalmente
  * @author Marcos Alonso
  *
  */

void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
