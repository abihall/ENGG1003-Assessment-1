#include<stdio.h>
 

int main()
{
    char Mes[]={"BMEQ ARE %"}; 
	int i, rotation_amount=1;
	
	FILE *input;               //opening the input.txt file and is reading its content
	 input=fopen("dictionary2", "r");
  	
  		
	while (rotation_amount<=26) { //while rotation amount is <26 and is ++ it will give all possible decrypted messages 
	   char Mes[]={"BMEQ ARE %"};
	
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
 while(feof(input)==0) {    //this function returns 1 if you are at the end of the fil
	                           //block of code is turning input.txt into a string
	      char c;
	      int i=0;
	      fscanf(input, "%c", &c);
	      if (c=Mes[i]){
	            printf("A possible decrypted message is: %s with rotation %d\n", Mes, rotation_amount);
	      }
   }
 
       
         ++rotation_amount;
     }
 }
