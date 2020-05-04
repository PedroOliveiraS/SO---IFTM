#include <stdio.h> 
#include<stdlib.h>
#include <unistd.h> 
#include<sys/wait.h> 
void collatz(int d) 
{ 
 pid_t pid = fork();

    if(pid == 0){
      while(d != 1){
        if(d%2 == 0){
          printf("%d ",d/2);
          d = d/2;
        }
        else{
          printf("%d ",(d*3)+1);
          d = (d*3) + 1;
        }
      }
   }
    else if(pid > 0){
      wait(NULL);
    }
} 
int main() 
{ 
    int d;
    do{
      scanf("%d",&d);
    }while(d <1);
    collatz(d);
    return 0; 
} 
