/** 
 * @brief It defines the game interface
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"

typedef struct _Game
{
  Id player_location;
  Id object_location;
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;
} Game;

/**
   * @brief inicializa un juego
   * @author Marcos Alonso
   *
   * 
   * @param game el juego que se inicializa
   * @return indica que esta todo OK
   */
STATUS game_create(Game *game);


/**
   * @brief inicializa un juego, carga los espacios y situa al personaje y al objeto en 
   * el primer espacio
   * @author Marcos Alonso
   *
   * 
   * @param game se guardan los datos del juego
   * @param filename archivo de donde se cargan los espacios
   * @return indica que esta todo OK
   */
STATUS game_create_from_file(Game *game, char *filename);

/**
   * @brief actualiza el juego segun el comando pasado
   * @author Marcos Alonso
   *
   * 
   * @param game contiene los datos del juego
   * @param cmd el comando que se quiere aplicar para actualizar
   * @return indica que esta todo OK
   */
STATUS game_update(Game *game, T_Command cmd);

/**
   * @brief destruye el espacio del juego
   * @author Marcos Alonso
   *
   * 
   * @param game contiene los espacios del juego a ser borrados
   * @return indica que esta todo OK
   */
STATUS game_destroy(Game *game);

/**
   * @brief establece que el juego termina
   * @author Marcos Alonso
   *
   * 
   * @param game el juego que se termina
   * @return FALSE
   */
BOOL game_is_over(Game *game);

/**
   * @brief imprime en la pantalla los datos del juego
   * @author Marcos Alonso
   *
   * 
   * @param game contiente los datos del juego
   */
void game_print_data(Game *game);

/**
   * @brief obtiene el espacio del juego que corresponde con la id
   * @author Marcos Alonso
   *
   * 
   * @param game el juego que contiene los datos
   * @param id la id del espacio que se busca
   * @return el espacio buscado
   */
Space *game_get_space(Game *game, Id id);

/**
   * @brief obtiene la id de la localizacion del jugador
   * @author Marcos Alonso
   *
   * 
   * @param game el juego que contiene los datos
   * @return la id de la localización del jugador
   */
Id game_get_player_location(Game *game);

/**
   * @brief obtiene la id de la localización del objeto
   * @author Marcos Alonso
   *
   * 
   * @param game el juego que contiene los datos
   * @return la id de la localización del objeto
   */
Id game_get_object_location(Game *game);

/**
   * @brief obtiene el ultimo comando
   * @author Marcos Alonso
   *
   * 
   * @param game el juego que contiene los datos
   * @return el último comando
   */
T_Command game_get_last_command(Game *game);
#endif
