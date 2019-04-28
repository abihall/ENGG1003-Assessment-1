#include<stdio.h> 
#include<string.h> 
#include <ctype.h>
 
 int main() 
  {
            int i=0, rotation_amount=1;
            char str[40000];
            char *D;
            char c;
        	 
        	FILE *output; //*output is a pointer to the next line that opens a file writes to it
	        output=fopen("case.output", "w");
	                   	
    
            FILE *fp=fopen("case.input", "r");
            
            while(fscanf(fp, "%s", &c)==1){
            str[i]=c;
            i++;
             }
             
        	while (rotation_amount<=26) { //while rotation amount is <26 and is ++ it will give all possible decrypted messages 
        	   char Mes[]={"SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"};
               for(i = 0; Mes[i] != '\0'; i++){ //this for loop ensures that the char Mes[] at i in the array isnt equal to \0 or NULL
        	                                    //increments the value of i by 1 every time the loop is executed.
        	                                    //This for loop ensures the program stops executing when the end of the array is reached
            		if(Mes[i] >= 'A' && Mes[i] <= 'Z'){ //loop executes if Mes[i] is found to be upper case
            			Mes[i] = (Mes[i]-'A' - rotation_amount)%26+'A'; //this is the ‘formula’/process used to decrypt the letter at i. The ASCII value of ‘A’ is misused from letter[i] to get a value between 0-25. From this the rotation amount is then minused The %26 ensures if (letter[i]-‘A’ + rotation_amount) exceeds 26 it will rotate back to the corresponding value under 25 eg. 27=>1. From this, the ASCII value of ‘A’ is added on again to get the ASCII back to capital letters.
            			
            		  while (Mes[i]<'A' && Mes[i] != ' ') //checks if Mes[i] is less than the ASCII value of A and isnt the ASCII value for a space 
            		    Mes[i]=Mes[i]+26; //adds 26 to Mes[i] to convert a ASCII value lower than ‘A’ into a ASCII value between ‘A’ and ‘Z’ and hence get the correct decryption
            	   }
            		else if(Mes[i]>='a' && Mes[i]<='z') { //checks if Mes[] is lower case
            		    Mes[i]=Mes[i]-32; //converts lower case into upper case
            		    Mes[i] = (Mes[i]-'A' - rotation_amount)%26+'A'; 
            		    
            		  while (Mes[i]<'A' && Mes[i] != ' ') //checks if Mes[i] is less than the ASCII value of A and isnt the ASCII value for a space 
            		    Mes[i]=Mes[i]+26;  //since it is decryption, this loop is required to convert any character below the ASCII 'A' into the required letter, excluding black spaces.
            		}
            	D= strstr(Mes, str);
                    fprintf(output, "the answer is %s at rotation %d", D, rotation_amount);	
         }
         
    }
                   
                    ++rotation_amount; //increments the rotation_amount to get all 26 rotations
                printf("see case.output file to read the ecrypted message\n");
        

               return 0;
               
           }
       