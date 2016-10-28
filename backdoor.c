#include <unistd.h> 
#include <stdio.h>

int main (int argc, char *argv[]) {
	if(argc < 2){
		printf("Please enter a program to run\n");
		return -1;
	}
	printf("Starting program %s\n",argv[1]);
	
	return execv(argv[1], argv+2); //argv+2 not passing arguments, I have no idea.
}
