#include "stdlib.h"
#include "string.h"

struct struct_path {
  char *dirname;
  char *basename;
  char *extname;
};

typedef struct struct_path path;

path parser_path (char *str) {
  int len = strlen(str);
  path new_path;
	// last slash
	int index_last_sl;

  // basename init ...
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

  // array of characters for copy de basename of path string
  char *basename;

  // array of integers in ascii code for convert a character
  int arr_chr[len - index_basename];
  int c_arr_chr = 0;

  for (int i = index_basename; i < len; i++) {
    arr_chr[c_arr_chr] = str[i];
    c_arr_chr++;
  }

  // allocate memory for basename
  basename = (char*) malloc(len - index_basename);

	// transform the integers at characters
  for (int i = 0; i < c_arr_chr; i++)
    strcpy(&basename[i], (char*) &arr_chr[i]);

	// init extname ...
	char *extname;
	int index_ext;

	for (int i = 0; basename[i] != '\0'; i++) {
		if (basename[i] == '.')
			index_ext = i;
	}

	int arr_ext[strlen(basename) - index_ext];
	int c_arr_ext = 0;

	for (int i = index_ext; basename[i] != '\0'; i++) {
		arr_ext[c_arr_ext] = basename[i];
		c_arr_ext++;
	}

	// allocate memory for extname
	extname = (char*) malloc(strlen(basename) - index_ext);

	for (int i = 0; i < c_arr_ext; i++)
		strcpy(&extname[i], (char*) &arr_ext[i]);

	// append extname
	new_path.extname = extname;
  // append basename
  new_path.basename = basename;

  return new_path;
}
