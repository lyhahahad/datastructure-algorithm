// A simple C program for traversal of a linked list
#include <stdio.h>
#include <stdlib.h>
 
 /**
 삽입 시 맨뒤에 추가할 경우에는 배열이 더 좋을 수 있지만 중간에 삽입하거나 첫 번째에 삽입하는 경우 훨씬 더 좋은 성능을 보여준다.
 **/
struct Node {
    int data;
    struct Node* next;
};
 
// This function prints contents of linked list starting from
// the given node
void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}
 
int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
 
    // allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
 
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second
 
    second->data = 2; // assign data to second node
    second->next = third;
 
    third->data = 3; // assign data to third node
    third->next = NULL;
 
    printList(head);
 
    return 0;
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int,  inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
    /* 2. put in the data  */
    new_node->data  = new_data;
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
  
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}
// 시간 복잡도는  o(1)이다.

void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    /* 2. allocate new node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}
//특정 노드 뒤에 추가할 경우, 해당 노드의 포인터를 입력으로 받으면 o(1)이다.

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data  = new_data;
 
    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    } 
      
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
  
    /* 6. Change the next of last node */
    last->next = new_node;
    return;   
}
//맨 뒤에 추가할 경우 마지막 노드를 찾아야 하기 때문에 o(n)이 소요된다.

void deleteNode(struct Node** head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
}


// Simple C code to delete node at particular position
 
#include<stdio.h>
#include<stdlib.h>
 
void insert(int );
void display_List();
void delete(int );
 
struct node             // Structure declaration
{
    int data;
    struct node *next;  // Self referral pointer
}*head=NULL,*tail=NULL; // Initial value of Head and Tail pointer is NULL
 
 
 //주어진 위치의 Node 삭제하기.
void delete(int pos)
{
    struct node *temp = head;       // Creating a temporary variable pointing to head
    int i;                    
    //주어진 노드의 위치가 header일 경우 
    if(pos==0)
    {
        printf("\nElement deleted is : %d\n",temp->data);
        head=head->next;        // Advancing the head pointer
        temp->next=NULL;
        free(temp);             // Node is deleted
    }
    else
    {
        //제거하고자 하는 포지션의 전 포지션까지 가고 제거 포지션을 저장한 뒤 나머지 리스트를 연결한다.
        //제거 포지션의 포인터를 저장하는 이유는 메모리를 해체하기 위함이다.
        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        // Now temp pointer points to the previous node of the node to be deleted
        struct node *del =temp->next;       // del pointer points to the node to be deleted
        temp->next=temp->next->next;
        printf("\nElement deleted is : %d\n",del->data);      
        del->next=NULL;
        free(del);                          // Node is deleted
    }
    printf("\nUpdated Linked List is : \n");
    display_List();
    return ;
}
 