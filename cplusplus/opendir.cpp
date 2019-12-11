// #include <stdio.h>
 
// #include <sys/types.h>
// #include <dirent.h>
 
// int
// main(int argc, char **argv)
 
// {
//   DIR *d;
//   struct dirent de, *dep;
//   int i;
//   char *mydir;
 
//   if (argc == 1) {
//     mydir=".";  /* lazy way to set default */
//   } else {
//     mydir=argv[1];
//   }
 
//   d = opendir(mydir);
 
//   if (d == NULL) {
//     perror(mydir);
//     return 1;
//   }
 
//   i = 0;
 
//   while (readdir_r(d, &de, &dep) == 0 && dep != NULL) {
//     printf("%d | %d | %td\n", de.d_reclen, de.d_type, de.d_off);
//     printf("directory entry %d is %s\n", i++, de.d_name);
//   }
 
//   if (closedir(d) == -1) {
//     perror("closedir");
//   }
 
//   return 0;
// }
#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    std::string path = ".";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}