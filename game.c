/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

/**
   Private functions
*/
STATUS game_add_space(Game *game, Space *space);
Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);
STATUS game_set_object_location(Game *game, Id id);

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);

/**
   Game interface implementation
*/

//inicializa un juego

STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  game->player_location = NO_ID;
  game->object_location = NO_ID;
  game->last_cmd = NO_CMD;

  return OK;
}

//inicializa un juego, carga los espacios y situa al objeto y al personaje en el primer espacio

STATUS game_create_from_file(Game *game, char *filename)
{

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR)
    return ERROR;

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

//destruye el espacio del juego

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  return OK;
}



STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

//obtiene el espacio del juego que corresponde con la id

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}



STATUS game_set_player_location(Game *game, Id id)
{

  if (id == NO_ID)
  {
    return ERROR;
  }

  game->player_location = id;
}

STATUS game_set_object_location(Game *game, Id id)
{

  int i = 0;

  if (id == NO_ID)
  {
    return ERROR;
  }

  game->object_location = id;

  return OK;
}

//obtiene la localización del jugador

Id game_get_player_location(Game *game)
{
  return game->player_location;
}

//obtiene la localización del objeto

Id game_get_object_location(Game *game)
{
  return game->object_location;
}

//actualiza el juego según el comando pasado

STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  
  switch (cmd)
  {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game_command_next(game);
      break;

    case BACK:
      game_command_back(game);
      break;

    default:
      break;
  }

  return OK;
}

//obtiene el último comando

T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

//imprime en la pantalla los datos del juego

void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game->object_location);
  printf("=> Player location: %d\n", (int)game->player_location);
}

//establece que el juego termina

BOOL game_is_over(Game *game)
{
  return FALSE;
}

/**
   Calls implementation for each action 
*/
void game_command_unknown(Game *game)
{
}

void game_command_exit(Game *game)
{
  
}

void game_command_next(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_command_back(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
