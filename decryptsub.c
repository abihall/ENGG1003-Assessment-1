 #include<stdio.h> 
#include<string.h>
/*
int main() 
 
     {
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
            printf("%d %d %d %c\n", index, tmp, str, w);
        }
    }


            return 0;
        }

         /*   w = alph[index]; // key is the alternate alphabet
            printf("%c", w); 
        }
        else
            printf("%c", w);
    }
}
return 0;
*/