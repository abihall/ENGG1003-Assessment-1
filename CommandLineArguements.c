#include<stdio.h> 
#include<string.h>
	
int main() {
    int choice;
    printf("The following are the avaliable code selections:\n");
    printf("Type '1' if you would like to Encrypt by rotation and message\n");
    printf("Type '2' if you would like to Decrypt by rotation and message\n");
    printf("Type '3' if you would like to Encrypt by a substitution alphabet\n");
    printf("Type '4' if you would like to Decrypt by substitution alphabet\n");
    printf("Type '6' if you would like to quit\n");
    scanf("%d", &choice);
    
    switch(choice){
//CASE 1 ENCRYPTION BY ROTATION CYPHER 
        case 1:  {
    char letter[100];
	int i, rotation_amount;
	printf("Enter a message to encrypt:\n");
	scanf(" %[^\n]s", letter);
	printf("Enter rotation amount:\n ");
	scanf("%d", &rotation_amount);
	   
	for(i = 0; letter[i] != '\0'; ++i){
		if(letter[i] >= 'A' && letter[i] <= 'Z'){
			letter[i] = (letter[i]-'A' + rotation_amount)%26+'A';
	    }
		else if(letter[i]>='a' && letter[i]<='z') {
		    letter[i]=letter[i]-32;
		    letter[i] = (letter[i]-'A' + rotation_amount)%26+'A'; 
		}
	}
    
	printf("Encrypted message: %s\n", letter);
	return letter[i];
}
            break;
//CASE 2 DECRYPTION BY ROTATION CYPHER 
        case 2: {
    {
    char letter[100];
	int i, rotation_amount;
	printf("Enter a message to encrypt:\n");
	scanf(" %[^\n]s", letter);
	printf("Enter rotation amount:\n ");
	scanf("%d", &rotation_amount);
	   
	for(i = 0; letter[i] != '\0'; ++i){
		if(letter[i] >= 'A' && letter[i] <= 'Z'){
	      letter[i] = (letter[i]-'A' - rotation_amount)%26+'A';
	       while (letter[i]<'A' && letter[i] != ' ')
		          letter[i]=letter[i]+26;
    }	else if(letter[i]>='a' && letter[i]<='z') {
		   letter[i]=letter[i]-32;
		   letter[i] = (letter[i]-'A' - rotation_amount)%26+'A';
            while (letter[i]<'A' && letter[i] != ' ')
		          letter[i]=letter[i]+26;
	}	

    }   printf("Encrypted message: %s\n", letter);
	return 0;
    }

            break;
}
        case 3:
        {
    char msg[100];
    char str[]={"LPEUMVATWCSFJBKXNQYDHZROIQ"};
    int u=0, p=0;
    char c=0, w;
	printf("Enter a message to encrypt:\n"); 
	scanf(" %[^\n]s", msg);          //scans input from the user and turns it into a string with name msg
    printf("message encrypted by substitution:\n");  
    
      for (c=0; msg[c] != 0; ++c){
            
            w=str[msg[c]-65]; 
            printf("%c", w); 
        }
}
  


        return 0;
    

            break;
        case 4:  {
    char msg[100];
    char str[]={"LPEUMVATWCSFJBKXNQYDHZROIQ"};
    char alph[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int u=0, p=0;
    char c=0, w;
	printf("Enter a message to decrypt:\n"); 
	scanf(" %[^\n]s", msg);          //scans input from the user and turns it into a string with name msg
    printf("message decrypted by substitution:\n");  
    
      for (c=0; msg[c] != 0; ++c){
           w = msg[c]; 
            char *tmp;
            int index;
        if (w>='A' && w<='Z'){
            tmp = strchr(str, w);
            index = (int)(tmp-str);
            w = alph[index]; // key is the alternate alphabet
            printf("%c", w); 
        }
        else printf("%c", w);
        }
}
  
return 0;
            break;
        case 5:
            break;
        case 6: printf("Goodbye!\n"); 
            break;
        default: printf("incorrect input, please enter 1,2,3,4,5 or 6.\n");
            break;
    }
return 0;
}


