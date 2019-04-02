#include <stdio.h>

int main()
{
   char letter[100];
   int rotation_amount, i=0;
   printf("Enter a message to encrypt:\n");
	scanf("%s", letter);
	printf("Enter rotation amount:\n ");
	scanf("%d", &rotation_amount);

    if(letter[i]>='a'&& letter[i]<='z'){ //dealing with only uppercase.
        letter[i]=letter[i]-32;          //the 'A' and 'a' are a value of 32 apart
    }
}
