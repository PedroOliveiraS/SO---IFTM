#include <stdio.h>
#include <pthread.h>

void *imprimePrimos(void *arguments)
{  
  int i,j, fat;
  int* value = (int*) arguments;
   for(i = 1; i <= *value; i++){
     fat = 0;
     for(j = 1; j <= *value; j++){
       if(i%j == 0){
         fat++;
       }
     }
     if(fat == 2){
       printf("Prime: [%d]\n",i);
     }
   }
   return NULL;
}

int main()
{
    int valor;
    pthread_t some_thread;

    printf("Entre com um valor: \n->");
    scanf("%d",&valor);
    printf("Creating THREAD: VALUE = [%d]\n",valor);
    pthread_create(&some_thread, NULL, &imprimePrimos, (void *)&valor);
    return pthread_join(some_thread, NULL); /* Wait until thread is finished */
  }
