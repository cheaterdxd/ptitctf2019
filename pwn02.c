#include <stdio.h>
#include <stdlib.h>

void init(){
	setbuf(stdin,0);
	setbuf(stdout,0);
	setbuf(stderr,0);
}
void flag(){
	char flag[] = "cat /home/pwn02/flag.txt";
	system(flag);
}
int main(){
	init();
	char s[6];
	int check = 0xDEADBEEF;
	puts("Welcome to pwnable");
	puts("Again, just give me your name and I give you the flag:");
	gets(s);
	if(check == 0x13371337){
		flag();
	}
	else{
		puts("You can do better!");
	}
	return 0;
}

