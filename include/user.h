#ifndef CLADV_USER_H
#define CLADV_USER_H

typedef struct user_s user_t;

extern user_t root;

extern user_t* users;
extern int n_users;

int user_init();

#endif