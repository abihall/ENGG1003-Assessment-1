#include<stdio.h>
 	

int main()
{
    char letter[100];
	int i, rotation_amount;
	printf("Enter a message to encrypt:\n");
	scanf("%s", letter);
	printf("Enter rotation amount:\n ");
	scanf("%d", &rotation_amount);
	   
	for(i = 0; letter[i] != '\0'; ++i){

		if(letter[i] >= 'A' && letter[i] <= 'Z'){
			letter[i] = (letter[i]-'A' - rotation_amount)%26+'A';
	   }

		else if(letter[i]>='a' && letter[i]<='z') {
		    letter[i]=letter[i]-32;
		 
		}
	}
    
	printf("Encrypted message: %s\n", letter);
	return letter[i];
	
}
