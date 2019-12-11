#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv)

{
  DIR *d;
  struct dirent de, *dep;
  int i;
  char *mydir;

  if (argc == 1)
  {
    mydir = ".";
  }
  else
  {
    mydir = argv[1];
  }

  d = opendir(mydir);

  if (d == NULL)
  {
    perror(mydir);
    return 1;
  }

  i = 0;

  while (readdir_r(d, &de, &dep) == 0 && dep != NULL)
  {
    if (de.d_name[0] != 46)
      printf("%-4d %-20s\n", i++, de.d_name);
  }

  if (closedir(d) == -1)
  {
    perror("closedir");
  }

  return 0;
}
