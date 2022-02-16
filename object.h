#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

Object* object_create(Id id);

STATUS object_destroy(Object* space);

Id object_get_id(Object* object);

STATUS object_set_name(Object* object, char* name);

const char * object_get_name(Object* object) ;

#endif
