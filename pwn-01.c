#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(){
	setbuf(stdin,0);
	setbuf(stdout,0);
	setbuf(stderr,0);
}
int main(){
	char s[6];
	char name[6];
	init();
	puts("Welcome to pwnable - Chao mung ban den voi pwnable");
	puts("I have some gifts for you - Minh co mot vai mon qua danh cho ban");
	do{
		puts("First, give me your name - Truoc het, cho minh xin ten ban: ");
		gets(s);
		if(strncmp(s,"admin",5) == 0){
			puts("You don't have permission - Ban khong co quyen truy cap");
			exit(0);
		}
		else{
			memcpy(&name, &s, strlen(s));
			if(strncmp(name,"admin",5) == 0){
				puts("Thank you for coming - cam on ban da den");
				puts("Here is your flag - Flag cua ban day:");
				system("cat flag");
				exit(0);
			}
			else{
				printf("Nice to meet you, %s\n", name);
			}
		}
				
	}while(1);
	
}
