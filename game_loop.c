/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 30-11-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"
#include "game.h"
#include "command.h"

/**
   * @brief inicia el juego y comprueba que no haya errores
   * @author Marcos Alonso
   *
   * 
   * @param *game variable juego usada para crear el juego
   * @param **gengine motor del juego
	 * @param *file_name archivo desde el que se crea el juego
	 * @return es 1 si hay error, es 0 si no hay errores
   */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
   * @brief ejecuta el juego
   * @author Marcos Alonso 
   * 
   * @param game variable que contiene el juego
   * @param *gengine motor usado para los graficos del juego
   */
void game_loop_run(Game game, Graphic_engine *gengine);

/**
   * @brief destruye el juego y los graficos creados
   * @author Marcos Alonso
   *
   * 
   * @param *gengine el motor de los graficos que se borran
   * @param game el juego que se borra
   */
void game_loop_cleanup(Game game, Graphic_engine *gengine);

int main(int argc, char *argv[])
{
  Game game;
  Graphic_engine *gengine;

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
 
  if (!game_loop_init(&game, &gengine, argv[1]))
  {
    game_loop_run(game, gengine);
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

// inicia el juego y comprueba que no hay errores

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
{
	// error en el juego
  if (game_create_from_file(game, file_name) == ERROR)
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }
	// error en el motor grafico
  if ((*gengine = graphic_engine_create()) == NULL)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

// ejecuta el juego

void game_loop_run(Game game, Graphic_engine *gengine)
{
  T_Command command = NO_CMD;

  while ((command != EXIT) && !game_is_over(&game))
  {
    graphic_engine_paint_game(gengine, &game);
    command = command_get_user_input();
    game_update(&game, command);
  }
}

// destruye el juego creado

void game_loop_cleanup(Game game, Graphic_engine *gengine)
{
  game_destroy(&game);
  graphic_engine_destroy(gengine);
}
