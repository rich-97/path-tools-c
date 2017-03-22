/* Simple test */

#include <stdio.h>

#include "../path.h"

int main (void) {
  char path_str[] = "/var/www/index.php";

  path path_st;

  parser_path(&path_st, path_str);

  printf("Dirname: %s\n", path_st.dirname);
  printf("Basename: %s\n", path_st.basename);
  printf("Extname: %s\n", path_st.extname);

  // Or if don't have use a struct,
  // you can use the functions directly.
  
  char other_path[] = "/var/www/foo.php";
  printf("Basename of: %s is: %s\n", other_path, get_basename(other_path));
  return 0;
}
