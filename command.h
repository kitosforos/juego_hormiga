/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2
#define N_CMD 5

typedef enum enum_CmdType {
  CMDS,
  CMDL} T_CmdType;

typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  NEXT,
  BACK} T_Command;

/**
20   * @brief obtiene la instruccion del usuario
19   * @author Marcos Alonso
		 *
		 * @return el comando introducido
12   */


T_Command command_get_user_input();

#endif
