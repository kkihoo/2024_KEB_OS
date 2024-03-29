#include<stdio.h>
#include<pthread.h>

#define NUM_THREADS 3

void runner(void *param){
        printf("Tread runner\n");
        //여기에 스레드가 할 일들을 나중에 넣으면 됨
        pthread_exit(0);
}
int main(){
        int i , policy;
        pthread_t tid[NUM_THREADS];
        pthread_attr_t attr;

        pthread_attr_init(&attr);
        if(pthread_attr_getschedpolicy(&attr, &policy) != 0)
                fprintf(stderr,"Unable to get policy\n");
        else{
                if(policy == SCHED_OTHER)
                        printf("SCHED_OTHER\n");
                else if(policy == SCHED_RR)
                        printf("SCHED_RR\n");
                else if(policy == SCHED_FIFO)
                        printf("SCHED_FIFO\n");
        }
//여기까지 현재 스레드 속성의 스레드 스케쥴링 방법( 디폴트값)이 뭔지 확인
        if(pthread_attr_setschedpolicy(&attr, SCHED_RR) != 0)
                fprintf(stderr, "Unable to set policy\n");
        //스레드 속성의 스레드 스케쥴링 방법을 RR로 설정
        if(pthread_attr_getschedpolicy(&attr, &policy) != 0)
                fprintf(stderr, "Unable to get policy\n");
        else{
                if(policy == SCHED_RR)
                printf("RR SET SUCCESS!\n");
                else
                        printf("RR SET FAIL.\n");
        }
        //스레드 속성 객체의 속성을 가진 스레드를 생성함
        for(i = 0; i< NUM_THREADS; i++){
                pthread_create(&tid[i], &attr, runner, NULL);
        }
        for(i = 0; i < NUM_THREADS; i++){
                pthread_join(tid[i],NULL);
        }
        return 0;
}
