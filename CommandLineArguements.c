#include<stdio.h> 
#include<string.h>

/*DIFFERENT FILES USDE AND WHAT THEY ALL CONTAIN
case1.input contains a block of text to be encrypted
case1.rotation contains the rotation amount as a integer
case2.input contains a block of text to be decrypted 
case2.rotation contains the rotation amount as a int
case3.input contains the block of text to be encrypted by substitution cipher (this alternate alphabet is hard coded)
case4.input contains the block of text to be decrypted by substitution sipher (this alternate alphabet is hard coded)
case5.input contains 
*/

	
int main() {
 
    int choice;
    printf("The following are the avaliable code selections:\n");
    printf("Type '1' if you would like to Encrypt by rotation and message\n");
    printf("Type '2' if you would like to Decrypt by rotation and message\n");
    printf("Type '3' if you would like to Encrypt by a substitution alphabet\n");
    printf("Type '4' if you would like to Decrypt by substitution alphabet\n");
    printf("Type '5' if you would like to Decrypt by rotation cipher without key\n");
    printf("Type '6' if you would like to quit\n");
    scanf("%d", &choice);
    
    switch(choice){
//CASE 1 ENCRYPTION BY ROTATION CYPHER 
        case 1:  {
 
    char letter[100];
	int i, rotation_amount;
	
	   FILE *input;               //opening the input.txt file and is reading its content
	 input=fopen("case1.input", "r");
	 
	   FILE *RAE;
	   RAE=fopen("case1.rotation", "r");
	 
	   fgets(letter, 100, input);
	 fscanf(RAE, "%d", &rotation_amount);
	  
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
}
            break;
//CASE 2 DECRYPTION BY ROTATION CYPHER 
        case 2: {
    
    char letter[100];
	int i, rotation_amount;
	
	  FILE *input;               //opening the input.txt file and is reading its content
	 input=fopen("case2.input", "r");
	 
	   FILE *RAE;
	   RAE=fopen("case2.rotation", "r");
	 
	   fgets(letter, 100, input);
	 fscanf(RAE, "%d", &rotation_amount);
	  
	
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
    
            break;
}
        case 3:
        {
            char msg[100];
            char str[]={"LPEUMVATWCSFJBKXNGYDHZROIQ"};
            int u=0, p=0;
            char c=0, w;
            printf("message encrypted by substitution:\n");  
        
            FILE *input;               //opening the case3.input file and is reading its content
	        input=fopen("case3.input", "r");
	         
	         fgets(msg, 100, input);
	        
            for (c=0; msg[c] != 0; ++c){
                if(msg[c]>='A' && msg[c]<='Z'){
                    w=str[msg[c]-65];
                    printf("%c", w); 
                }
                else if(msg[c]<'A'){
                    w = msg[c];
                    printf("%c", w); 
            }

            }
        return 0;
        }

        case 4:  {
    char msg[100];
    char str[]={"LPEUMVATWCSFJBKXNGYDHZROIQ"};
    char alph[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int u=0, p=0;
    char c=0, w;
    printf("message decrypted by substitution:\n");  
    
     FILE *input;               //opening the case4.input file and is reading its content
	        input=fopen("case4.input", "r");
	         
	         fgets(msg, 100, input); 
    
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
        else
            printf("%c", w);
    }
}
return 0;
            break;
            
            
        case 5:
        {
    char Mes[]={"SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"};
	int i, rotation_amount=1;
  	
	while (rotation_amount<=26) { //while rotation amount is <26 and is ++ it will give all possible decrypted messages 
	   char Mes[]={"SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"};
	for(i = 0; Mes[i] != '\0'; i++){ //i is incrumented so it sifts through the string and encrypts it
		if(Mes[i] >= 'A' && Mes[i] <= 'Z'){
			Mes[i] = (Mes[i]-'A' - rotation_amount)%26+'A';
		  while (Mes[i]<'A' && Mes[i] != ' ')
		    Mes[i]=Mes[i]+26;
	   }
		else if(Mes[i]>='a' && Mes[i]<='z') {
		    Mes[i]=Mes[i]-32;
		    Mes[i] = (Mes[i]-'A' - rotation_amount)%26+'A';
		  while (Mes[i]<'A' && Mes[i] != ' ')
		    Mes[i]=Mes[i]+26;  
		}
 }
        printf("A possible decrypted message is: %s with rotation %d\n", Mes, rotation_amount);
         ++rotation_amount;
     }
 }
            break;
            
        case 6: printf("Goodbye!\n"); 
            break;
            
        default: printf("incorrect input, please enter 1,2,3,4,5 or 6.\n");
            break;
    }
return 0;
}


