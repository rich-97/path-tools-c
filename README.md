# tools for paths

simple use:

```c
#include <stdio.h>
#include <stdlib.h>
#include "path-tools-c/path.h"

int main (void) {
  char str[] = "/var/www/index.php";

  // Struct path
  path your_path;
  
  parser_path(&your_path, str);
  
  printf("%s\n", your_path.dirname); // /var/www
  printf("%s\n", your_path.basename); // index.php
  printf("%s\n", your_path.extname); // .php
  return EXIT_SUCCESS; 
}
```

Compile and execute:

```shell
gcc main.c path-tools-c/path.c -o main; ./main
```
