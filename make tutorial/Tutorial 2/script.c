#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int main(void)
{
    
    FILE    *fptr;


    fptr = fopen("matrix.txt", "w");
    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
   
 for (int i = 0; i < MAX; ++i)
{
  fprintf(fptr, "%d", rand() % 1000);
  fprintf(fptr, "\n");  
} 
   
   /* while (str[i] != '\0')
    {
        num = rand() % 10;
        num2 = num + '0';
        str[i] = num2;
        i += 1;
    }
    puts(str);
    fprintf(fptr,"%s", str);*/
    fclose(fptr);
    return (0);
}
