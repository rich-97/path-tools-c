# tools for paths

simple use:

```c
#include "stdio.h"
#include "path-tools-c/path.h"

int main () {
  char str[] = "/var/www/index.php";

  // struct path
  path your_path;

  your_path = parser_path(str);

  printf("basename: %s\n", your_path.basename);
  printf("extname %s\n", your_path.extname);
  return 0;
}
```
