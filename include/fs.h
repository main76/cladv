#ifndef CLADV_FS_H
#define CLADV_FS_H

typedef struct file_s file_t;
typedef struct fpolicy_s fpolicy_t;

extern file_t mount_root;

extern file_t* kernel_files;
extern int n_kernel_files;

extern file_t* user_files;
extern int n_user_files;

int fs_init(file_t* kfiles, int n_kfiles, file_t* ufiles, int n_ufiles);
file_t* fs_get(int i);
int fs_create(char* name, int pid);

static int __build_tree();

struct file_s {
  char name[32];
  int id;
  int pid;
  int owner;
  int type;
  int entry;
  fpolicy_t puser;
  fpolicy_t psudo;
};

struct fpolicy_s {
  int hidden: 1;
  int exec: 1;
  int read: 1;
  int write: 1;
};

#endif