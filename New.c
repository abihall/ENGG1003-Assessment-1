#include<stdio.h> 
#include<string.h>

/*DIFFERENT FILES USDE AND WHAT THEY ALL CONTAIN
case.input contains a block of text that any operation can manipulate 
case.rotation contains the rotation amount as a integer
case.output contains a black of test that has been encrypted or decripted, it is the output
*/

	
int main() {
 
    int choice; 
    
    //gives instructions to the user of inputting text and rotation amount. Ensures the user has placed the text into case.input
    //lists the code selections which refers to how the user wants to encrypt of decript, also gives the use user a option to quit
   
    printf("Before you begin, ensure any message you want to encrypt/decrypt is found within case.input file and the desired rotation amount\nis found in case.rotation\n");
    printf("\n If the above is complete, the following are the avaliable code selections:\n");
    printf("Type '1' and then <enter> if you would like to Encrypt by rotation and message\n"); 
    printf("Type '2' and then <enter> if you would like to Decrypt by rotation and message\n"); 
    printf("Type '3' and then <enter> if you would like to Encrypt by a substitution alphabet\n"); 
    printf("Type '4' and then <enter> if you would like to Decrypt by substitution alphabet\n"); 
    printf("Type '5' and then <enter> if you would like to Decrypt by rotation cipher without rotation amount\n");
    printf("Type '6' and then <enter> if you would like to quit\n");
    scanf("%d", &choice); //goes to the corrosponding switch case based on the users input
    
    switch(choice){
//CASE 1 ENCRYPTION BY ROTATION CYPHER///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
        case 1: 
        {
            char letter[100]; //initalises a array of type char 
        	int i, rotation_amount;
        	
        	 FILE *input;               //*input is a pointer to the next line that opens a file and reads its content
        	 input=fopen("case.input", "r"); //fopen opens the file called 'case.input' and reads its content
        	 
        	 FILE *RAE;                //*RAE is a pointer to the next line that opens a file and reads its content
        	 RAE=fopen("case.rotation", "r"); //fopen opens the file called 'case.rotation' and reads its content
        	 
        	 FILE *output;             //*output is a pointer to the next line that opens a file writes to it
        	 output=fopen("case.output", "w"); //fopen opens 'case.output' and writes to it
        	   
        	 fgets(letter, 100, input); //this function gets a string called 'letter' that is 100 characters long. 
                                        //'input’ is the pointer to a FILE object that identifies the stream where characters are read from.
             fscanf(RAE, "%d", &rotation_amount); //fscanf scans a int and stors it in rotation_amount.  
                                                  //RAE is the pointer to a FILE object that identifies the stream.
        	  
        	for(i = 0; letter[i] != '\0'; ++i){ //this for loop ensures that the char letter[] at i in the array isnt equal to \0 or NULL. 
                                                //Increments the value of i by 1 every time the loop is executed. 
        	                                    //This for loop ensures the program stops executing when the end of the array is reached
        
                if(letter[i] >= 'A' && letter[i] <= 'Z'){ //tests if letter[] at point i in the string is between the ASCII values of A and Z. 
        			letter[i] = (letter[i]-'A' + rotation_amount)%26+'A'; //this is the ‘formula’/process used to encrypt the letter at i. 
                                                                          //The ASCII value of ‘A’ is misused from letter[i] to get a value between 0-25. 
                                                                          //From this the rotation amount is then added. The %26 ensures if (letter[i]-‘A’ + rotation_amount) exceeds 26 it will rotate back to the corresponding value under 25 
                                                                          //eg. 27=>1. From this, the ASCII value of ‘A’ is added on again to get the ASCII back to capital letters.
        	    }
        		else if(letter[i]>='a' && letter[i]<='z') { //tests if letter[] at i is lower case by testing if letter[i] is between the ASCII values for a and z. 
        		    letter[i]=letter[i]-32; //minusing 32 converts all lower case letters into the corresponding upper case letter. 
        		    letter[i] = (letter[i]-'A' + rotation_amount)%26+'A'; 
        		}
        	}
             printf("see case.output file to read the ecrypted message\n"); 
        	fprintf(output, "Encrypted message by rotation of amount %d is %s\n", rotation_amount, letter); //outputs text to case.output. outputs int rotation_amount and letter.
        }
            break;
            
//CASE 2 DECRYPTION BY ROTATION CYPHER///////////////////////////////////////////////////////////////////////////////
        case 2: 
        {
            char letter[100]; 
        	int i, rotation_amount;
        	
        	FILE *input;               //opening the case.input file and is reading its content
        	input=fopen("case.input", "r"); //fopen opens the file called 'case.input' and reads its content

        	 
        	FILE *RAE; //*RAE is a pointer to the next line that opens a file and reads its content
        	RAE=fopen("case.rotation", "r");  //fopen opens the file called 'case.rotation' and reads its content
        	   
        	FILE *output; //*output is a pointer to the next line that opens a file writes to it
        	output=fopen("case.output", "w"); 
        	 
        	fgets(letter, 100, input); //this function gets a string called 'letter' that is 100 characters long. 'input’ is the pointer to a FILE object that identifies the stream where characters are read from.
        	fscanf(RAE, "%d", &rotation_amount); //fscanf scans a int and stors it in rotation_amount. RAE is the pointer to a FILE object that identifies the stream.

        	  
        	
        	for(i = 0; letter[i] != '\0'; ++i){ //this for loop ensures that the char letter[] at i in the array isnt equal to \0 or NULL
        	                                    //increments the value of i by 1 every time the loop is executed.
        	                                    //This for loop ensures the program stops executing when the end of the array is reached
        	                                    
        		if(letter[i] >= 'A' && letter[i] <= 'Z'){ //tests if letter[] at point i in the string is between the ASCII values of A and Z. 
        	      letter[i] = (letter[i]-'A' - rotation_amount)%26+'A'; //this is the ‘formula’/process used to decrypt the letter at i. 
        	                                                            //The ASCII value of ‘A’ is misused from letter[i] to get a value between 0-25. 
        	                                                            //From this the rotation amount is then minused. The %26 ensures if (letter[i]-‘A’ + rotation_amount) exceeds 26 it will rotate back to the corresponding value under 25 
        	                                                            //eg. 27=>1. From this, the ASCII value of ‘A’ is added on again to get the ASCII back to capital letters.
        	      
        	       while (letter[i]<'A' && letter[i] != ' ') //since it is decryption, this loop is required to convert any character below the ASCII 'A' that may be formed into the required letter
        		          letter[i]=letter[i]+26;//adds 26 to letter[i] to convert a ASCII value lower than ‘A’ into a ASCII value between 'A' and 'Z' and hence get the correct decryption
        		   }	
        	    else if(letter[i]>='a' && letter[i]<='z') { //tests if letter[] at i is lower case by testing if letter[i] is between the ASCII values for a and z. 
        		   letter[i]=letter[i]-32; //misusing 32 transforms any lower case letter into the corresponding upper case. This process is based off the ASCII table. 
        		   letter[i] = (letter[i]-'A' - rotation_amount)%26+'A'; //this is the ‘formula’/process used to decrypt the letter at i. The ASCII value of ‘A’ is misused from letter[i] to get a value between 0-25. From this the rotation amount is then minused The %26 ensures if (letter[i]-‘A’ + rotation_amount) exceeds 26 it will rotate back to the corresponding value under 25 eg. 27=>1. From this, the ASCII value of ‘A’ is added on again to get the ASCII back to capital letters.
        		   
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
            char c=0, w;
            printf("access case.output to see the message encrypted by substitution:\n");  
        
            FILE *input;               //opening the case.input file and is reading its content
	        input=fopen("case.input", "r");
	        
	        FILE *output; //*output is a pointer to the next line that opens a file writes to it
	        output=fopen("case.output", "w");
	         
	        fgets(msg, 100, input); //this function gets a string called 'msg' that is 100 characters long. 'input’ is the pointer to a FILE object that identifies the stream where characters are read from.
	        
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
            char c=0, w;
            printf("see case.output to see message decrypted by substitution:\n");  
            
             FILE *input;               //opening the case.input file and is reading its content
        	 input=fopen("case.input", "r");
        	 
             FILE *output; //*output is a pointer to the next line that opens a file writes to it
	         output=fopen("case.output", "w");
        	         
        	 fgets(msg, 100, input); //this function gets a string called 'letter' that is 100 characters long. 'input’ is the pointer to a FILE object that identifies the stream where characters are read from.
            
              for (c=0; msg[c] != 0; ++c){      //this for loop ensures that the char Mes[] at c in the array isnt equal to \0 or NULL
        	                                    //increments the value of c by 1 every time the loop is executed.
        	                                    //This for loop ensures the program stops executing when the end of the array is reached
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
        	 
        	FILE *output; //*output is a pointer to the next line that opens a file writes to it
	        output=fopen("case.output", "w");
	        
	        FILE *input;               //opening the case.input file and is reading its content
            input=fopen("case.input", "r");
          	
        	while (rotation_amount<=26) { //while rotation amount is <26 and is ++ it will give all possible decrypted messages 
        	   char Mes[]={"SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"};
               for(i = 0; Mes[i] != '\0'; i++){ //this for loop ensures that the char Mes[] at i in the array isnt equal to \0 or NULL
        	                                    //increments the value of i by 1 every time the loop is executed.
        	                                    //This for loop ensures the program stops executing when the end of the array is reached
            		if(Mes[i] >= 'A' && Mes[i] <= 'Z'){
            			Mes[i] = (Mes[i]-'A' - rotation_amount)%26+'A';
            			
            		  while (Mes[i]<'A' && Mes[i] != ' ')
            		    Mes[i]=Mes[i]+26; //adds 26 to Mes[i] to convert a ASCII value lower than ‘A’ into a ASCII value between ‘A’ and ‘Z’ and hence get the correct decryption
            	   }
            		else if(Mes[i]>='a' && Mes[i]<='z') {
            		    Mes[i]=Mes[i]-32;
            		    Mes[i] = (Mes[i]-'A' - rotation_amount)%26+'A'; //this is the ‘formula’/process used to decrypt Mes at i. The ASCII value of ‘A’ is misused from Mes[i] to get a value between 0-25. From this the rotation amount is then minused The %26 ensures if (Mes[i]-‘A’ + rotation_amount) exceeds 26 it will rotate back to the corresponding value under 25 eg. 27=>1. From this, the ASCII value of ‘A’ is added on again to get the ASCII back to capital letters.
            		    
            		  while (Mes[i]<'A' && Mes[i] != ' ')
            		    Mes[i]=Mes[i]+26;  //adds 26 to Mes[i] to convert a ASCII value lower than ‘A’ into a ASCII value between ‘A’ and ‘Z’ and hence get the correct decryption
            		}
         }
                fprintf(output, "A possible decrypted message is: %s with rotation %d\n", Mes, rotation_amount); //sends output to case.output.
                ++rotation_amount; //increments the rotation_amount to get all 26 rotations
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

