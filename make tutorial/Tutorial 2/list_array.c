#include<stdio.h>
#include<stdbool.h>
#define MAX 20 //maximum no of elements in the list//user defined datatypes

struct list
{
int arr[MAX];
int length;//total no of elements
}l;

void create(void)
{	int element;
	int flag=1;
	while(flag==1)
	{ 	printf("Enter an element : ");
		scanf("%d", &element);
		l.arr[l.length] = element;
		l.length++; 
		printf("To insert another element press '1' : ");
		scanf("%d", &flag);
	}
}

void insert(int element, int pos)

{	int i;

	if (pos == 0)
	{
 
	 printf("\n\nCannot insert at zeroth position");
         return;

	}

	if (pos-1 > l.length)
	{ 
	
	printf("\n\nOverflow"); 
	
	}


	else
	{
		for (i=l.length; i>=pos-1; i--)
			{l.arr[i+1] = l.arr[i];}
		l.arr[pos-1] = element;
		l.length++;
	}
}


void delet(int pos)
{	int i;
	if(pos == 0)
	{ 
		printf("\n\nCannot delete at zeroth position");
		return;
	}
	if (pos > l.length)
	{	 printf("\n\nElement doesn't exist"); 
		 return;
	}
	for (i=pos-1; i<l.length; i++)
	{	l.arr[i] = l.arr[i+1]; }	
	l.length--;

}

void find(int element)

{	int i;
	int flag = 1;
 	for (i=0; i<l.length; i++)
	{	if(l.arr[i] == element)
		{ printf ("%d exists at %d position",element, i+1);flag = 0; 
		  break;
		}
	}
	if(flag == 1)
	{ printf("Element not found.\n");
          
	}
}

bool islistfull(void)
{	if (l.length == MAX)
		return true;
	else
		return false;
}//function to check whether the list is empty or not boolean 


bool islistempty(void)
{	if (l.length == 0)return true;
	else
		return false;
}

void display(void)
{	int i;
	for (i=0; i<l.length; i++) 
	printf("Element %d : %d \n", i+1, l.arr[i]);
}

int main()
{ 
  create();
  printf("Created \n");
  display();
  
  insert(6,5);
  printf("Inserted \n");
  display();

  delet(3);
  printf("Deleted \n");
  display();

  find(4);
  printf("\n");
  
  find(10);

return 0;
}


