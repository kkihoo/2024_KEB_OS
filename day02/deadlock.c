#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t semaphore[3];

void *threadRountine(void *argumentsPointer){
        long id = (long)argumentsPointer;
        int i;
        for(i = 0; i < 1; i++){
                printf("sem_wait_%ld를 시도중입니다.\n", id);
                sem_wait(&semaphore[id]);
                printf("sem_wait_%ld 성공!\n", id);
                sem_post(&semaphore[id]);//해결책

                printf("sem_wait_%ld를 시도중입니다.\n", 1-id);
                sem_wait(&semaphore[1-id]);
                printf("sem_wait_%ld 성공.\n", 1-id);
                sem_post(&semaphore[1-id]);//해결책

                printf("sem_wait_%ld를 시도중입니다.\n", id);
                sem_wait(&semaphore[id]);
                printf("sem_wait_%ld 성공!\n", id);
                sem_post(&semaphore[id]);//해결책

                printf("sem_wait_%ld를 시도중입니다.\n", 1-id);
                sem_wait(&semaphore[1-id]);
                printf("sem_wait_%ld 성공.\n", 1-id);
                sem_post(&semaphore[1-id]);//해결책
        }
        return NULL;
}

int main(){
        pthread_t threadDs[3];

        // 두 개의 세마포어를 형성하여 각 세마포어에 하나의 입장권을 부여함
        sem_init(&semaphore[0], 0, 1);
        sem_init(&semaphore[1], 0, 1);

        pthread_create(&threadDs[0], NULL, threadRountine, (void*)0);
        pthread_create(&threadDs[1], NULL, threadRountine, (void*)0);

        pthread_join(threadDs[0], NULL);
        pthread_join(threadDs[1], NULL);

        printf("No Deadlock!\n");
        return 0;
}
