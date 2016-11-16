// this will a lib for paths
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

  // basename init ...
  int index_basename;
  int c_cmp = 0;
  int c_chr = 0;

  for (int i = 0; i < len; i++) {
    if (str[i] == '/')
      c_chr++;
  }

  for (int i = 0; i < len; i++) {

    if (str[i] == '/')
      c_cmp++;

    if (c_cmp == c_chr) {
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

  // allocate memory
  basename = (char*) malloc(len - index_basename);

  for (int i = 0; i < c_arr_chr; i++)
    strcpy(&basename[i], (char*) &arr_chr[i]);

  // append basename
  new_path.basename = basename;
  return new_path;
}
