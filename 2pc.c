#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  int fd1[2], fd2[2], n, m;
  char buffer[100];
  pid_t p;
  pipe(fd1);  // 1st pipe is created;
  pipe(fd2);  // 2nd pipe is created;
  p = fork(); // Child is created
  if (p > 0)
  {
    close(fd1[0]); // close read end of pipe 1
    close(fd2[1]); // close write end of pipe 2
    printf("Passing content to child-->pipe-1\n");
    write(fd1[1], "Hello my Child\n", 100);
    m = read(fd2[0], buffer, 100);
    write(1, buffer, m);
    wait(NULL);
  }
  else
  {
    close(fd1[1]); // close write end of pipe 1
    close(fd2[0]); // close read end of pipe 2
    n = read(fd1[0], buffer, 100);
    write(1, buffer, n);
    printf("Passing content to parent-->pipe-2\n");
    write(fd2[1], "Hello my parent\n", 150);
    wait(NULL);
  }
  return 0;
}