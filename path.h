
#ifndef _PATH_H_
#define _PATH_H_

/* Struct layout */

struct _path {
  char *dirname;
  char *basename;
  char *extname;
};

typedef struct _path path;

/* Prototypes */

int is_absolute (char *str);
void int_to_str (char *str, int *arr_int, int count);
int index_last_chr (char *str, char chr);
char *get_dirname (char *str);
char *get_basename (char *str);
char *get_extname (char *str);
void parser_path (path *sp, char *str);

#endif
