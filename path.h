
#ifndef PATH_H
#define PATH_H

#include "stdlib.h"
#include "string.h"

struct struct_path {
  char *dirname;
  char *basename;
  char *extname;
};

typedef struct struct_path path;

/* path absolute */
int is_absolute (char *str) {
  if (str[0] == '/')
    return 1;
  else
    return 0;
}

void str_copy_int (char *str, int *arr_int, int count) {
  for (int i = 0; i < count; i++)
    strcpy(&str[i], (char*) &arr_int[i]);
}

path parser_path (char *str) {
  char *basename;
  char *extname;
  char *dirname;
  int len = strlen(str);
  path new_path;
	// index last slash
	int index_last_sl;

  /* Parse basename init. */
  int index_basename;
  int c_cmp = 0;
	// slash counter '/'
  int c_chr = 0;

  for (int i = 0; i < len; i++) {
    if (str[i] == '/')
      c_chr++;
  }

  for (int i = 0; i < len; i++) {
    if (str[i] == '/')
      c_cmp++;

    if (c_cmp == c_chr) {
			index_last_sl = i;
      index_basename = i + 1;
      break;
    }
  }

  // array of integers in ascii code for convert a character
  int arr_chr[len - index_basename];
  int c_arr_chr = 0;

  for (int i = index_basename; i < len; i++) {
    arr_chr[c_arr_chr] = str[i];
    c_arr_chr++;
  }

  // allocate memory for basename
  basename = (char*) malloc(len - index_basename);

	// converts the integers at characters
  str_copy_int(basename, arr_chr, c_arr_chr);

	/* Parse extname init. */
	int index_ext;
  int len_basename = len - index_basename;
	for (int i = 0; i < len_basename; i++) {
		if (basename[i] == '.')
			index_ext = i;
	}

	int arr_ext[len_basename - index_ext];
	int c_arr_ext = 0;

	for (int i = index_ext; i < len_basename; i++) {
		arr_ext[c_arr_ext] = basename[i];
		c_arr_ext++;
	}

	// allocate memory for extname
  extname = (char*) malloc(len_basename - index_ext);

  // converts de integers at characters
  str_copy_int(extname, arr_ext, c_arr_ext);

  /* Parse dirname init. */
  int arr_dir[index_last_sl];
  int c_arr_dir = 0;

  for (int i = 0; i < index_last_sl; i++) {
    arr_dir[c_arr_dir] = str[i];
    c_arr_dir++;
  }

  dirname = (char*) malloc(index_last_sl);

  str_copy_int(dirname, arr_dir, c_arr_dir);

	// append to estruct.
	new_path.extname = extname;
  new_path.basename = basename;
  new_path.dirname = dirname;

  return new_path;
}

#endif
