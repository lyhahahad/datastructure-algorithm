
//기존의 linked list에서 tail을 첫번째 요소와 이어준 것과 같다.
//next가 null값에 도달하면 끝내는 기존의 traversal과 달리 첫번째 노드에 다시 도달하면 탐색을 중단한다.
// C program to implement
// the above approach
#include<stdio.h>
#include<stdlib.h>
 
/* structure for a node */
struct Node
{
    int data;
    struct Node *next;
};
 
/* Function to insert a node at the beginning of a Circular
   linked list */
void push(struct Node **head_ref, int data)
{
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
 
    /* If linked list is not NULL then set the next of last node */
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
    //singly linked list와 이부분만 다른 것
        ptr1->next = ptr1; /*For the first node */
 
    *head_ref = ptr1;
}
 
/* Function to print nodes in a given Circular linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}
 
/* Driver program to test above functions */
int main()
{
    /* Initialize lists as empty */
    struct Node *head = NULL;
 
    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
 
    printf("Contents of Circular Linked List\n ");
    printList(head);
 
    return 0;
}

/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head nodes of
    the two resultant linked lists */
void splitList(struct Node *head, struct Node **head1_ref,
                                            struct Node **head2_ref)
{
  struct Node *slow_ptr = head;
  struct Node *fast_ptr = head;
 
  if(head == NULL)
    return;
  
  /* If there are odd nodes in the circular list then
     fast_ptr->next becomes head and for even nodes
     fast_ptr->next->next becomes head */
  while(fast_ptr->next != head &&
         fast_ptr->next->next != head)
  {
     fast_ptr = fast_ptr->next->next;
     slow_ptr = slow_ptr->next;
  } 
 
 /* If there are even elements in list then move fast_ptr */
  if(fast_ptr->next->next == head)
    fast_ptr = fast_ptr->next;     
   
  /* Set the head pointer of first half */
  *head1_ref = head;   
      
  /* Set the head pointer of second half */
  if(head->next != head)
    *head2_ref = slow_ptr->next;
   
  /* Make second half circular */  
  fast_ptr->next = slow_ptr->next;
   
  /* Make first half circular */  
  slow_ptr->next = head;      
}