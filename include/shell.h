#ifndef CLADV_SHELL_H
#define CLADV_SHELL_H

#include "user.h"

typedef struct shout_s shout_t;
typedef struct sharg_s sharg_t;
typedef shout_t* (*shcmd_t)(sharg_t* args);

extern user_t curr;
extern int is_sudo;

sharg_t* sharg(char* line);
void _sharg(sharg_t* p);

shout_t* shout(char* string);
void _shout(shout_t* p);

#endif