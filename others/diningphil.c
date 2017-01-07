#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define n 5
#define thinking 0
#define hungry 1
#define eating 2
#define left (ph_num + 4) % n
#define right (ph_num + 1) %n

sem_t mutex;
sem_t s[n];
int state[n];
int phil_num[n] = {0,1,2,3,4};
void test(int ph_num) {
if(state[ph_num] == hungry && state[left] != eating && state[right] != eating) {
state[ph_num] = eating;
sleep(2);
printf("philosopher %d takes fork %d and %d\n", ph_num+1, left+1,right+1);
printf("philosopher %d is eating\n",ph_num+1);

sem_post(&s[ph_num]);
}

}
void take_fork(int ph_num){
sem_wait(&mutex);
state[ph_num] = hungry;
printf("philosopher %d is hungry \n",ph_num+1);
test(ph_num);
sem_post(&mutex);
sem_wait(&s[ph_num]);
sleep(1);
}
void put_fork(int ph_num) {
sem_wait(&mutex);
state[ph_num] = thinking;
printf("philosopher %d putting fork %d and %d down\n",ph_num+1,left+1,right+1);
printf("philosopher %d is thinking",ph_num);
test(left);
test(right);
sem_post(&mutex);
}
void *philospher(void *num)
{
int *i = num;
while(1){
sleep(1);
take_fork(*i);
sleep(0);
put_fork(*i);
}
}
int main()
{
int i;
pthread_t thread_id[n];
sem_init(&mutex,0,1);
for(i = 0; i < n; i++) 
sem_init(&s[i],0,0);

for(i = 0 ; i < n; i++){
pthread_create(&thread_id[i], NULL,philospher,&phil_num[i]);
printf("philosopher %d is thinking", i+1);
}
for(i = 0; i < n; i++)
pthread_join(thread_id[i],NULL);

return 0;
}

