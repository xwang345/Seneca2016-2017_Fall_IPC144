#include <stdio.h>
//TODO: include the string library
#include <string.h>
#include <stdlib.h>
//TODO: define constants for array sizes
const int a = 9;

int main(void){
	/*TODO: declare an input string that can hold up to 100 characters plus one terminating null character. Initialize to empty string*/
//	int len;
	char str[9];
	char password[9];
	char realpassword[9]= "SGQHKKGN";
	int i=9;
		
	char abc[9] = "abcdefg";
	
	str[ strlen(abc) - 2]= '\0';
		
	printf("%s\n",abc);	
	printf("Password Game\n");
	printf("=============\n");
	printf("Enter your name (up to 8 characters): ");
	scanf("%s", input);
	printf("WELCOME %s\n", input);
	printf("Guess the password (up to 8 characters) %s: ", input);
	scanf("%s", password);
	printf("-----------------------------------------------------------%s\n",input);
	str[ strlen(input) - 1]= '\0';
	printf("%s\n",input);
	
	for(i=1;i<strlen(input)-1;i++){
		if(strcmp(realpassword,password) == 0){
			printf("You got it, %s!!!\n",input);
			printf("Game Over!");
			exit(1);
		}else{
			printf("FALSE: Guess the password (up to 8 characters) %s :", input);
			scanf("%s", password);
		}
	}
				
	return 0;
}
