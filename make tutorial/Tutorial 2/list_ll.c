#include <stdio.h>
#include <malloc.h>
struct node
{
    int value;
    struct node *next;
};

typedef struct node snode;
snode *newnode, *ptr, *prev, *temp;
snode *first = NULL, *last = NULL;


snode* create_node(int);
void insert_node_first();
void insert_node_last();
void insert_node_pos();
void delete_pos();
void search();
void display();

snode* create_node(int val)
{
    newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}
 
/*
 * Inserting Node at First
 */
void insert_node_first()
{
    int val;
 
    printf("\nEnter the value for the node:");
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && first == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        temp = first;
        first = newnode;
        first->next = temp;
    }
    printf("\n----INSERTED----");    
}
 
/*
 * Inserting Node at Last
 */
void insert_node_last()
{
    int val;
 
    printf("\nEnter the value for the Node:");    
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
 printf("\n----INSERTED----");
}    
 
/*
 * Inserting Node at position
 */
void insert_node_pos()
{
    int pos, val, cnt = 0, i;
 
    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode = create_node(val);
     printf("\nEnter the position ");
    scanf("%d", &pos);
    ptr = first;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (pos == 1)
    {
        if (first == last && first == NULL)
        {
            first = last = newnode;
            first->next = NULL;
            last->next = NULL;
        }
        else
        {
            temp = first;
            first = newnode;
            first->next = temp;
        }
        printf("\nInserted");
    }
    else if (pos>1 && pos<=cnt)
    {
        ptr = first;
        for (i = 1;i < pos;i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newnode;
        newnode->next = ptr;
        printf("\n----INSERTED----");
    }
    else
    {
        printf("Position is out of range");
    }
}

void delete_pos()
{
    int pos, cnt = 0, i;
 
    if (first == NULL)
    {
        printf(":No node to delete\n");
    }
    else
    {
        printf("\nEnter the position of value to be deleted:");
        scanf(" %d", &pos);
        ptr = first;
        if (pos == 1)
        {
            first = ptr->next;
            printf("\nElement deleted");    
        }
        else 
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)    
            {
                ptr = first;
                for (i = 1;i < pos;i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range");
            }
        free(ptr);
        printf("\nElement deleted");
        }
    }
}

void search()
{
    int flag = 0, key, pos = 0;
 
    if (first == NULL)
    {
        printf(":No nodes in the list\n");
    }
    else
    {
        printf("\nEnter the value to search");
        scanf("%d", &key);
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            pos = pos + 1;
            if (ptr->value == key)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nElement %d found at %d position\n", key, pos);
        }
        else
        {
            printf("\nElement %d not found in list\n", key);
        }
    }    
}
/*
 * Displays non-empty List from Beginning to End
 */
void display()
{
    if (first == NULL)
    {
        printf(":No nodes in the list to display\n");
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {    
            printf("%d\t", ptr->value);
        }
    }
}

int main()
{ 
  
  insert_node_last();
  insert_node_last();
  insert_node_last();
  insert_node_last();
  insert_node_last();
  printf("Inserted \n");
  display();

  delete_pos(3);
  printf("Deleted \n");
  display();

  search(4);
  printf("\n");
  
  search(10);

return 0;
}
