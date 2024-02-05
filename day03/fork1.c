#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    int counter = 1;
    pid = fork();
    if (pid < 0)
    {
        // error occurred
        fprintf(stderr, "Fork Failed.\n"); // 파일을 지정하여 printf, 현재는 표준에러출력
        exit(-1);                          // 에러로 인한 종료
    }

    else if (pid == 0)
    { // child process / 자식이면 0, 부모는 자식의 pid 값을 받는다.
        printf("Child Here!\n");
        while (counter < 6)
        {
            printf("Child num: %d\n", counter); // 부모와 자식이 개별로 동작하는 것을 알 수 있다.
            counter++;
            sleep(1);
        }
    }
    else
    { // parent process /
        printf("I'm parent!\n");
        while (counter < 6)
        {
            printf("parent num: %d\n", counter);
            counter++;
            sleep(1);
        }
        wait(NULL); // wait
        printf("process finished\n");
    }
    return 0;
}