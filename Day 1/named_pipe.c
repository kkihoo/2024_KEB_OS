#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *fp;
	char buf[255];
	if((fp = fopen("testfifo","rw")) ==NULL){
		perror("open error :");
		exit(0);
	}
	memset(buf, 0x00, 255);
	while(1){
		while(fgets(buf, 255, fp) != NULL){
			printf("%s\n", buf);
			memset(buf, 0x00, 255);
		}
	}
	return 0;
}


//이  코드를 컴파일 해서 실행파일 만든 다음, 아래를 따라 수행
//(1) mkfifo testfifo를 생성하여 namedpipe를 만들어 줌
//(2) exec 3<> testfifo를 수행, testfifo에프로세스가 file을 사용할대 file에 접근하기 위한 정수값인file descriptor를 붙여주는것
//(참고로 stdin는 0, stdout은 1, stderr는 2가 이미 할당되어 있으므로, 그외의 숫자인 3이상으로 할것)
//(3)echo [testfifo에넣을 아무글] > testfifo 
//(4)./named_pipe.out 실행. 3에서 넣은글이 나올것
//(5) exec 3>&-(file descriptor 붙인거 다시떼기)

