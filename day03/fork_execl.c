#include <stdio.h>
#include <stdlib.h>   // for system(exit() etc)
#include <unistd.h>   // for execl(), fork()
#include <sys/wait.h> // for wait()

int main()
{
    int pid;
    int counter = 1;
    pid = fork();
    if (pid < 0)
    {
        // error occured
        fprintf(stderr, "Fork failed");
        exit(-1);
    }

    else if (pid == 0)
    { // child process / 자식이면 0, 부모는 자식의 pid 값을 받는다.
        printf("Child Here!\n");
        printf("execl start!!\n"); //자식 프로세스는 exec를 호출하여 새로운 프로세스를 생성, 자식프로세스 종료
        //다른말로는 자식프로세스는 exec를 호출하여 새로운 코드로 덮어쓰게된다.
        execl("/usr/bin/ls", "ls", "-l, NULL");
        printf("if you read this message, fail creationg execl func..\n");
    }
    else
    { // parent process /
        printf("I'm parent!\n");
        wait(NULL); // wait 자식이 종료될때까지 대기
        printf("process finished\n");
    }
    return 0;
}
