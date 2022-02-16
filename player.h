/**
 * @brief Funcionalidad para el manejo de los jugadores
 *
 * @file player.h
 * @author Iñigo
 * @version 2.0
 * @date 16-02-2022
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/**
  * @brief It creates a new player
  * @author Iñigo
  *
  * player_create allocates memory for a new player
  *  and initializes its members
  * @param id the identification number for the new player
  * @return a new player, initialized
  */
Player* player_create(Id id);

#endif