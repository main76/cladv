#include <stdlib.h>
#include <string.h>
#include "kernel.h"

struct store_s {
  void** value;
  int count;
  int capacity;
};

static store_t strings = { .value = NULL, .count = 0, .capacity = 16 };
static store_t shells = { .value = NULL, .count = 0, .capacity = 16 };

static image_t* image;
static upack_t* package;

static int store_push(store_t* p, void* v) {
  if (p->count == p->capacity) {
    p->capacity <<= 1;
    p->value = realloc(p->value, p->capacity);

    if (p->value == NULL)
      return 1;
  }

  p->value[p->count++] = v;
  return 0;
}

int kernel_inst(image_t* img) {
  if (img == NULL)
    return 1;

  image = img;
  
  for (int i = 0; i < img->n_strings; i++)
    if (store_push(&strings, img->strings[i]))
      return 1;

  for (int i = 0; i < img->n_shells; i++)
    if (store_push(&shells, img->shells[i]))
      return 1;
}

int kernel_load(upack_t* pkg) {
  if (pkg == NULL)
    return 1;
  
  if (pkg->magic != image->magic)
    return 1;
  
  package = pkg;
  for (int i = 0; i < pkg->n_strings; i++)
    if (store_push(&strings, pkg->strings[i]))
      return 1;

  return fs_init(image->files, image->n_files, pkg->files, pkg->n_files);
}
