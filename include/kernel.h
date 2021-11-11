#ifndef CLADV_KERNEL_H
#define CLADV_KERNEL_H

#include "fs.h"
#include "shell.h"

typedef struct store_s store_t;
typedef struct image_s image_t;
typedef struct upack_s upack_t;

struct image_s {
  int magic;
  file_t* files;
  int n_files;
  shcmd_t* shells;
  int n_shells;
  char** strings;
  int n_strings;
};

struct upack_s {
  int magic;
  file_t* files;
  int n_files;
  char** strings;
  int n_strings;
};

extern store_t strings;
extern store_t shells;

int kernel_inst(image_t* img);
int kernel_load(upack_t* pkg);
int kernel_run();

void* store_get(store_t* p, int i);
void store_set(store_t* p, int i, void* v);

static void kernel_write(shout_t* out);

#endif