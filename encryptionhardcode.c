#include <stdio.h>

/*
int main()
{
    char letter[5]= "DOGs ARE COoL";
	int i, rotation_amount=5;
	   
	for(i = 0; letter[i] != '\0'; ++i){
	
	
	    
		if(letter[i] >= 'A' && letter[i] <= 'Z'){
			letter[i] = (letter[i]-'A' + rotation_amount)%26+'A';
	   }

		else if(letter[i]>='a' && letter[i]<='z') {
		    letter[i]=letter[i]-32;
		    letter[i] = (letter[i]-'A' + rotation_amount)%26+'A';
		
		 }
		}
	}
    
	printf("Encrypted message: %s\n", letter);
	return letter[i];
	
}