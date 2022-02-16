/**
 * @brief Funcionalidad para el manejo de los jugadores
 *
 * @file player.h
 * @author Iñigo
 * @version 2.0
 * @date 16-02-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */

struct _Player {
  Id id;                    /*!< Id number of the player, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the player */
  Id location;                /*!< Location of the player*/
  BOOL object;              /*!< Whether the player has an object or not */
};

