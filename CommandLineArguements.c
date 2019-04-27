#include<stdio.h> 
#include<string.h>

/*DIFFERENT FILES USDE AND WHAT THEY ALL CONTAIN
case1.input contains a block of text that any operation can manipulate 
case1.rotation contains the rotation amount as a integer
*/

	
int main() {
 
    int choice;
    
    printf("Before you begin, ensure any message you want to encrypt/decrypt is found within case.input file and the desired rotation amount\nis found in case.rotation\n");
    printf("\n If the above is complete, the following are the avaliable code selections:\n");
    printf("Type '1' and then <enter> if you would like to Encrypt by rotation and message\n");
    printf("Type '2' and then <enter> if you would like to Decrypt by rotation and message\n");
    printf("Type '3' and then <enter> if you would like to Encrypt by a substitution alphabet\n");
    printf("Type '4' and then <enter> if you would like to Decrypt by substitution alphabet\n");
    printf("Type '5' and then <enter> if you would like to Decrypt by rotation cipher without rotation amount\n");
    printf("Type '6' and then <enter> if you would like to quit\n");
    scanf("%d", &choice);
    
    switch(choice){
//CASE 1 ENCRYPTION BY ROTATION CYPHER///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
        case 1: 
        {
            char letter[100];
        	int i, rotation_amount;
        	
        	 FILE *input;               //opening the case.input file and is reading its content
        	 input=fopen("case.input", "r");
        	 
        	 FILE *RAE;
        	 RAE=fopen("case.rotation", "r");
        	 
        	 FILE *output;
        	 output=fopen("case.output", "w");
        	   
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
             printf("see case.output file to read the ecrypted message\n");
        	fprintf(output, "Encrypted message by rotation of amount %d is %s\n", rotation_amount, letter);
        }
            break;
            
//CASE 2 DECRYPTION BY ROTATION CYPHER///////////////////////////////////////////////////////////////////////////////
        case 2: 
        {
            char letter[100];
        	int i, rotation_amount;
        	
        	FILE *input;               //opening the case.input file and is reading its content
        	input=fopen("case.input", "r");
        	 
        	FILE *RAE;
        	RAE=fopen("case.rotation", "r");
        	   
        	FILE *output;
        	output=fopen("case.output", "w"); 
        	 
        	fgets(letter, 100, input);
        	fscanf(RAE, "%d", &rotation_amount);
        	  
        	
        	for(i = 0; letter[i] != '\0'; ++i){
        		if(letter[i] >= 'A' && letter[i] <= 'Z'){
        	      letter[i] = (letter[i]-'A' - rotation_amount)%26+'A';
        	      
        	       while (letter[i]<'A' && letter[i] != ' ')
        		          letter[i]=letter[i]+26;
        		   }	
        	    else if(letter[i]>='a' && letter[i]<='z') {
        		   letter[i]=letter[i]-32;
        		   letter[i] = (letter[i]-'A' - rotation_amount)%26+'A';
        		   
                     while (letter[i]<'A' && letter[i] != ' ')
        		               letter[i]=letter[i]+26;
        	       }	
        
            }   
            printf("see case.output file to read the decrypted message\n");
            fprintf(output, "Decrypted message by rotation of value %d is: %s\n", rotation_amount, letter);
            
                    break;
        }
//CASE 3 ENCRYPTION BY SUBSTITUTION ALPHABET/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 3:
        {
            char msg[100];
            char str[]={"LPEUMVATWCSFJBKXNGYDHZROIQ"};
            int u=0, p=0;
            char c=0, w;
            printf("access case.output to see the message encrypted by substitution:\n");  
        
            FILE *input;               //opening the case.input file and is reading its content
	        input=fopen("case.input", "r");
	        
	        FILE *output;
	        output=fopen("case.output", "w");
	         
	        fgets(msg, 100, input);
	        
            for (c=0; msg[c] != 0; ++c){
                if(msg[c]>='A' && msg[c]<='Z'){
                    w=str[msg[c]-65];
                    fprintf(output, "%c", w); 
                }
                else if(msg[c]<'A'){
                    w = msg[c];
                    fprintf(output, "%c", w); 
                }

            }
        return 0;
        }
//CASE 4 DECRYPTION BY SUBSTITUTION ALPHABET/////////////////////////////////////////////////////////////////////////////////////////////
        case 4: 
        {
            char msg[100];
            char str[]={"LPEUMVATWCSFJBKXNGYDHZROIQ"};
            char alph[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
            int u=0, p=0;
            char c=0, w;
            printf("see case.output to see message decrypted by substitution:\n");  
            
             FILE *input;               //opening the case.input file and is reading its content
        	 input=fopen("case.input", "r");
        	 
             FILE *output;
	         output=fopen("case.output", "w");
        	         
        	 fgets(msg, 100, input); 
            
              for (c=0; msg[c] != 0; ++c){
                   w = msg[c]; 
                    char *tmp;
                    int index;
                if (w>='A' && w<='Z'){
                    tmp = strchr(str, w);
                    index = (int)(tmp-str);
                    w = alph[index]; // key is the alternate alphabet
                    fprintf(output, "%c", w); 
                }
                else
                    fprintf(output, "%c", w);
            }
        }
                break;
                
//DECRYPTION BY ROTATION CIPHER WITHOUT ROTATION AMOUNT/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
        case 5:
       {
            int i, rotation_amount=1;
        	
        	FILE *output;
	        output=fopen("case.output", "w");
	        
	        FILE *input;               //opening the case.input file and is reading its content
            input=fopen("case.input", "r");
          	
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
                fprintf(output, "A possible decrypted message is: %s with rotation %d\n", Mes, rotation_amount);
                ++rotation_amount;
             }
                printf("see case.output file to read the ecrypted message\n");
                    break;
          }         

                
        case 6:
        
            printf("Goodbye!\n"); 
            break;
            
        default: 
        
            printf("incorrect input, please start again and enter 1,2,3,4,5 or 6.\n");
            break;
    }
return 0;
}


