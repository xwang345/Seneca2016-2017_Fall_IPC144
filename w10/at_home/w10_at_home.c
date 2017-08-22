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
	char save_str[9];
	char password[9];
	char realpassword[9]= "SGQHKKGN";
	int i;

	printf("Password Game\n");
	printf("=============\n");
	printf("Enter your name (up to 8 characters): ");
	scanf("%s", str);
	strcpy(save_str, str);
	printf("WELCOME %s\n", str);
	printf("Guess the password (up to 8 characters) %s: ", str);
	scanf("%s", password);
	
	for(i=1;i<strlen(str)-1;i++){
		if(strcmp(realpassword,password) == 0){	
			printf("You got it, %s!!!\n",save_str);
			printf("Game Over!\n");
			exit(1);
		}else{
			str[ strlen(str) - 1]= '\0';
			printf("FALSE: Guess the password (up to 8 characters) %s :", str);
			scanf("%s", password);
		}
	}
				
	return 0;
}
