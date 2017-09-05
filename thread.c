#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *print_message(void *ptr);

int main(void){
  pthread_t thread1,thread2;
  int iret1, iret2;
  const char *message1 = "Thread 1";
  const char *message2 = "Thread 2";

  iret1 = pthread_create(&thread1,NULL,print_message,(void*)message1);
  if(iret1){
    printf("Deu ruim na thread1");
    exit(EXIT_FAILURE);
  }

  iret2 = pthread_create(&thread2,NULL,print_message,(void*)message2);
  if(iret2){
    printf("Deu ruim na thread2");
    exit(EXIT_FAILURE);
  }

  pthread_join( thread1, NULL);
  pthread_join( thread2, NULL);
  return 0;
}

void *print_message(void *ptr){
  char *message = (char*) ptr;
  int i;
  for(i = 0; i < 100; i++)
    printf("%s, line: %d\n",message,i);
}
