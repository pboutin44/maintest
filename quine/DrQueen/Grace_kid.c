//Comment
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define MAKE_LINE char*s="//Comment%c#include <stdio.h>%c#include <fcntl.h>%c#include <unistd.h>%c#define MAKE_LINE char*s=%c%s%c;%c#define GET_FILE int fd = open(%cGrace_kid.c%c, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);if (fd == -1){return (1);}%c%c#define FT int main(void){MAKE_LINE GET_FILE dprintf(fd,s,10,10,10,10,34,s,34,10,34,34,10,10,10,10,10);}%c%cFT%c";
#define GET_FILE int fd = open("Grace_kid.c", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);if (fd == -1){return (1);}

#define FT int main(void){MAKE_LINE GET_FILE dprintf(fd,s,10,10,10,10,34,s,34,10,34,34,10,10,10,10,10);}

FT
