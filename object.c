
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"


struct _Object {
    Id id;
    char name[WORD_SIZE + 1];
};

Object* object_create(Id id) {
    Object *newObject = NULL;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));
  if (newObject == NULL) {
    return NULL;
  }

  /* Initialization of an empty space*/
  newObject->id = id;
  newObject->name[0] = '\0';

  return newObject;
}

STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

/** It sets the name of a space
  */
STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }
  return OK;
}
/** It gets the name of a space
  */
const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}

STATUS object_print(Object* object) {
  /* Error Control */
  if (!object) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name); 
  return OK;
}