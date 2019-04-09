#include<stdio.h>
 	

int main()
{
    char msg[100];
    char str[26];
    int u=0, p=0;
    char c=0, v;
	printf("Enter a message to encrypt:\n");
	scanf("%s", msg);
	  
	  FILE *input;
	  input=fopen("input.txt", "r");
	  
	

	while(feof(input)==0) {
	      char c, z;
	      int i=0, u=0;
	      //read a character
	      fscanf(input, "%c", &c);
	      
	      str[i]=c;
	      i++;
    }
    for(c=0 ; msg[c]!=0 ; c++){
        
         v=str[c-65];
         printf("%c\n", v);
         
    }
        
    }
    //msg contains the text to be encrypted
    //key contains 26 letters, representing substitutions for A-Z
    
    //for each character c of msg
        //find the substitution for c
        //key[c-65]
        //replace c in msg with that substitution

	  

        
		    
		
		




