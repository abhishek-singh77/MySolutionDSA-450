#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();
void display(struct Node *head);


 // } Driver Code Ends
//User function Template for C

void removeDuplicates(struct Node* head)
{
    /* Pointer to traverse the linked list */
    struct Node* current = head;
 
    /* Pointer to store the next pointer of a node to be deleted*/
    struct Node* next_next;
   
    /* do nothing if the list is empty */
    if (current == NULL)
       return;
 
    /* Traverse the list till last node */
    while (current->next != NULL)
    {
       /* Compare current node with next node */
       if (current->data == current->next->data)
       {
           /* The sequence of steps is important*/              
           next_next = current->next->next;
           free(current->next);
           current->next = next_next; 
       }
       else /* This is tricky: only advance if no deletion */
       {
          current = current->next;
       }
    }
}
// { Driver Code Starts.

    
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      insert();
      removeDuplicates(start);
      display(start);
      printf("\n");
    }
    return 0;

}


 void insert()
 {
     int n,value,i;
     scanf("%d",&n);
     struct Node *temp;
     for(i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }
 
 void display(struct Node *head)
{
   while(head!=NULL)
  {
   printf("%d ",head->data);
    head=head->next;
  }
}




  // } Driver Code Ends
