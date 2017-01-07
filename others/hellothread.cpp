#include <iostream>
#include<pthread.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define BufferSize 10
int BufferIndex = 0;
int BUFFER[10];
pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

/*void *hello(void *threadid){
long tmp;
tmp = (long)threadid;
cout<<"hello its thread number "<<tmp<<endl;
pthread_exit(NULL);
}*/
void *producer()
{
while(1){
pthread_mutex_lock(&mutex);
if (BufferIndex == BufferSize-1)
pthread_cond_wait(Buffer_Not_Full,&mutex);
BUFFER[BufferIndex++] = rand()%100;
printf("item produce: %d\n",BUFFER[BufferIndex]);
pthread_mutex_unlock(&mutex);
pthread_cond_signal(Buffer_Not Empty);
}
}
void *consumer(){
while(1){
pthread_mutex_lock(&mutex);
if(BufferIndex == 0){
pthread_cond_wait(&Buffer_Not_Empty,&mutex);
}
printf("consume : %d\n",BufferIndex--);
pthread_mutex_unlock(&mutex);
pthread_cond_signal(Buffer_Not_Full);
}
}

int main()
{
pthread_t  n[5];
int rc;
long t;
/*for(t = 0; t < 5; t++) {
rc = pthread_create(&n[t],NULL,hello,(void *)t);
 if (rc){
       //  printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
}*/
pthread_t pro;
pthread_t con;
pthread_create(&pro,NULL,producer,NULL;);
pthread_creat(&con,NULL,consumer,NULL);

pthread_join(pro,NULL);
pthread_join(con,NULL);
return 0;
//pthread_exit(NULL);
}
