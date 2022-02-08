#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  int fd[2], n;     // fd for no. of processes and n for number characters to read/write
  char buffer[100]; // for storing the content written by parent
  pid_t p;

  pipe(fd);
  p = fork();

  if (p > 0)
  {
    close(fd[0]); // Closing the end of reading section// avoiding access of data by child
    printf("Passing contents to the child");
    write(fd[1], "Hello Child\n", 15);
    wait(NULL);
  }

  else
  {
    close(fd[1]); // closing writing part of pipe
    n = read(fd[0], buffer, 100);
    write(1, buffer, n);
  }

  return 0;
}