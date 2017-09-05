#include <stdio.h>
#include  <sys/types.h>

#define COUNT 100
void printChild(){
  int i;
  for(i = 0; i < COUNT;i++)
    printf("Hello, I'm a Child. I'm on the line:%d!\n",i+COUNT);
}

void printParent(){
  int i;
  for(i = 0; i < COUNT;i++)
    printf("Hello, I'm the Parent. I'm on the line:%d!\n",i);
}

int main(void){
  pid_t pid;
  pid = fork();
  if(pid == 0){
    printChild();
  }
  else{
    printParent();
  }
  return 0;
}
