#include<pthread.h>
#include<stdio.h>

void *threadRountine(void *arg){
        pthread_t tid = pthread_self();
        //TID를 반환하고 출력
        printf("thread ID:: %lu\n", tid);
        while(1){
                printf("a\n");
        }
        return NULL;
}
int main(){
        pthread_t threadID;
        char tmp[10];

        scanf("%s", tmp); //잠깐 프로세스 실행을 중간에 중지시키고 pstree 보려고
        pthread_create(&threadID, NULL, threadRountine, NULL);

        scanf("%s", tmp);
        pthread_detach(threadID);

        while(1){
                printf("b\n");
        }
}
