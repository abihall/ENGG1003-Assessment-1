#include<stdio.h>
 
/*
 int main()
{
    char msg[100];
    char str[]={"LPEUMVATWCSFJBKXNQYDHZROIQ"};
    int u=0, p=0;
    char c=0, w;
	printf("Enter a message to encrypt:\n"); 
	scanf("%s", msg);          //scans input from the user and turns it into a string with name msg
    printf("message encrypted by substitution:\n");  
	  
	/*FILE *input;               //opening the input.txt file and is reading its content
	 input=fopen("input.txt", "r");
	  

	while(feof(input)==0) {    //this function returns 1 if you are at the end of the fil
	                           //block of code is turning input.txt into a string
	      char c;
	      int i=0;
	      fscanf(input, "%c", &c);
	      str[i]=c;
	      i++;
	      printf("%s", str);   
   }
   
        for (c=0; msg[c] != 0; ++c){
            
            w=str[msg[c]-65]; 
            printf("%c", w); 
        }
                 
           //prints the encrypted character to user
        
    
   // fclose(input);
     return 0;         
             
}    

            

 
    //msg contains the text to be encrypted
    //str contains 26 letters, representing substitutions for A-Z
    
    //for each character c of msg
        //find the substitution for c
        //key[c-65]
        
        //replace c in msg with that substitution

	  

        
		    
		