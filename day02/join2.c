#include<stdio.h>
#include<pthread.h>
void *threadRoutine(void *arg){
        int count = 0;
        pthread_t tid = pthread_self();
        //TID를 반환하고 출력
        printf("thread ID :: %lu\n",tid);
        while(count < 100){
                printf("a\n");
                count++;
        }
        pthread_exit(arg);//추가 변경
}
int main(){
        pthread_t threadID;
        int status;
        void *result;
        char tmp[10];

        scanf("%s", tmp);
        pthread_create(&threadID, NULL, threadRoutine, NULL);

        scanf("%s", tmp);

        status = pthread_join(threadID, &result);
        if(status != 0){
                exit(1);
        }
        while(1){
                printf("b\n");
        }
}
