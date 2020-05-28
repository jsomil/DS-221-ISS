#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>


int main()
{ // The two input values

FILE *inputFile1;
FILE *inputFile2;

int i,j,k;

int rows1,cols1,rows2,cols2;

char fileName[100];
bool fileFound=false;

bool multiplcation = true;

int sum=0;
//first matrix
do
{
    printf("Enter File name of matrix #1 - with extention - : ");
    scanf("%[^\n]%*c",fileName);
    inputFile1 = fopen(fileName,"r");
    if(!inputFile1)
    {
            printf("File Not Found!!\n");
            fileFound=true;
    }
    else
        fileFound=false;

}while(fileFound);

// Second matrix
do
{
    printf("Enter File name of matrix #2 - with extention - : ");
    scanf("%[^\n]%*c",fileName);
    inputFile2 = fopen(fileName,"r");
    if(!inputFile2)
    {
            printf("File Not Found!!\n");
            fileFound=true;
    }
    else
        fileFound=false;

}while(fileFound);
// determine the rows and columns in each matrix
fscanf(inputFile1,"%i",&rows1);
fscanf(inputFile1,"%i",&cols1);
fscanf(inputFile2,"%i",&rows2);
fscanf(inputFile2,"%i",&cols2);

printf("\n\nRows1 = %d",rows1);
printf("\nCols1 = %d",cols1);
printf("\n\nRows2 = %d",rows2);
printf("\nCols2 = %d",cols2);


if(cols1!=rows2)
    multiplcation=false;
else
    multiplcation=true;

if(multiplcation==false)
{
    printf("Cant multiply those two matrices \n");
    fclose(inputFile1);
    fclose(inputFile2);
    return 0;
}

else
{
    //allocate Matrcies

    int **mat1 = (int **)malloc(rows1 * sizeof(int*));
    for(i = 0; i < rows1; i++)
        mat1[i] = (int *)malloc(cols1 * sizeof(int));

    i=0;

    int **mat2 = (int **)malloc(rows2 * sizeof(int*));
    for(i = 0; i < rows2; i++)
        mat2[i] = (int *)malloc(cols2 * sizeof(int));

    i=0;

    int **mat3 = (int **)malloc(rows1 * sizeof(int*));
    for(i = 0; i < rows1; i++)
        mat3[i] = (int *)malloc(cols2 * sizeof(int));

    i=0;

    ////////////////////////////

    while(!feof(inputFile1))
    {
        for(i=0;i<rows1;i++)
        {
            for(j=0;j<cols1;j++)
                fscanf(inputFile1,"%d%*[^\n]%*c",&mat1[i][j]);
        }
    }

    i=0;
    j=0;

    while(!feof(inputFile2))
    {
        for(i=0;i<rows2;i++)
        {
            for(j=0;j<cols2;j++)
                fscanf(inputFile2,"%d%*[^\n]%*c",&mat2[i][j]);
        }
    }

    /*/////////////////////////
    i=0;
    j=0;
    printf("\n\n");
    //print matrix 1
    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols1;j++)
            printf("%d\t",mat1[i][j]);

        printf("\n");
    }
    ////////////////////////////
    i=0;
    k=0;
    printf("\n\n");
    //print matrix 2
    for(i=0;i<rows2;i++)
    {
        for(j=0;j<cols2;j++)
            printf("%d\t",mat2[i][j]);

        printf("\n");
    }
  */
     
     clock_t start, end;
     double cpu_time_used;
     
     start = clock();

  

    //multiplication statements
    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols2;j++)
        {
            mat3[i][j]=0;
            
            for(k=0;k<rows2;k++)
                mat3[i][j] += mat1[i][k]*mat2[k][j];
        }
      
    }

     end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  
 


    i=0;
    j=0;
    k=0;

    //print multiplication result
    printf("\n\nTime taken = %lf seconds\n\n", cpu_time_used);

  /*  for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols2;j++)
            printf("%d\t",mat3[i][j]);

        printf("\n");
    }*/

// close the input files
    fclose(inputFile1);
    fclose(inputFile2);
}

}

