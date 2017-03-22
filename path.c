/*
 * (c) Ricardo Moreno <morenoricardo237@gmail.com>
 *
 * For more details about the license of this source code,
 * please view the file LICENSE.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "path.h"

/* Return 1 if the path is absolute otherwise 0 is relative. */
int is_absolute (char *str) {
  if (str[0] == '/')
    return 1;
  else
    return 0;
}

/* Convert integers to string. */
void int_to_str (char *str, int *arr_int, int count) {
  for (int i = 0; i < count; i++)
    strcpy(&str[i], (char*) &arr_int[i]);
}

/* Return the index of the last character */
int index_last_chr (char *str, char chr) {
  int length = strlen(str);
  int index;
  
  for (int i = length - 1; i >= 0; i--) {
    if (str[i] == chr) {
      index = i;
      break;
    }
  }

  return index;
}

/* Get the dirname */
char *get_dirname (char *str) {
  int length = strlen(str);
  int index_last_sl = index_last_chr(str, '/');
  int length_dir = index_last_sl;
  int arr[length_dir];
  char *dirn;

  for (int i = 0; i < length_dir; i++)
    arr[i] = str[i];

  dirn = (char*) malloc(length_dir);
  int_to_str(dirn, arr, length_dir);

  return dirn;
}

/* Get the basename */
char *get_basename (char *str) {
  int length = strlen(str);
  int index = index_last_chr(str, '/') + 1;
  int length_basen = length - index;
  int arr[length_basen];
  char *basen;

  for (int i = index, j = 0; i < length; i++, j++)
    arr[j] = str[i];
  
  basen = (char*) malloc(length_basen);
  int_to_str(basen, arr, length_basen);

  return basen;
}

/* Get the extname */
char *get_extname (char *str) {
  int length = strlen(str);
  int index_basen = index_last_chr(str, '/') + 1;
  int length_basen = length - index_basen;
  int index_extn = index_last_chr(str, '.');
  int length_extn = length - index_extn;
  int arr[length_extn];
  char *extn;

  for (int i = index_extn, j = 0; i < length; i++, j++)
    arr[j] = str[i];

  extn = (char*) malloc(length_extn);
  int_to_str(extn, arr, length_extn);

  return extn;
}

/* Parser path from a string */
void parser_path (path *sp, char *str) {
  path *p = sp;

  // Append to estruct.
  p->dirname  = get_dirname(str);
  p->basename = get_basename(str);
  p->extname  = get_extname(str);
}

