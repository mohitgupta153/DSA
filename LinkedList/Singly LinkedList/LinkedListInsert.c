#include<stdio.h> 
#include <stdlib.h> 

struct Node 
{
    int data;
    struct Node* next;
};

void push_front (struct Node** head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
    return;
}

void push_back (struct Node** head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        (*head) = new_node;
        return;
    }
    struct Node* current = NULL;
    current = (*head);
    while (current->next != NULL)
    {
        //printf("%d",current->data);
        current = current->next;
    }
    current->next = new_node;
    return;
}

void push_atPosition(struct Node** head, int data, int position)
{
    /* last position out of total nunmber of node not working,
    1st position also not working */
    int prev_position = 1;
    struct Node* temp = (*head);
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (*head == NULL)
        return;
    while (prev_position < position-1 && temp->next != NULL)
    {
        prev_position++;
        //printf("%d",temp->data);
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    struct Node* temp1 = temp->next;
    temp->next = new_node;
    new_node->next = temp1;
    return;
}

void print_List (struct Node* head){
    if (head == NULL)
        return;
    struct Node* current = NULL;
    current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

void reverse_List (struct Node** head) {
    struct Node* prev, *next = NULL;
    struct Node* current = (*head);
    while (current != NULL){
        next = current->next;
        current->next = prev;
        //printf("debug %d",current->data);
        prev = current;
        current = next;
    }
    (*head) = prev;
    return;
}

int main() 
{ 
	struct Node* head_ref = NULL;
	push_front(&head_ref, 5);
	push_front(&head_ref, 4);
	push_front(&head_ref, 3);
	push_front(&head_ref, 2);
	push_front(&head_ref, 1);
	printf("Created Linked List before reversing\n");
	print_List(head_ref);
	push_back(&head_ref, 6);
	push_back(&head_ref, 7);
	printf("Created Linked List after push back\n");
	//reverse_List(&head_ref);
	print_List(head_ref);
	push_atPosition(&head_ref, 10, 3);
	printf("Created Linked List after push atPosition\n");
	print_List(head_ref);
	push_atPosition(&head_ref, 11, 8);
	print_List(head_ref);
	push_atPosition(&head_ref, 12, 10);
	print_List(head_ref);
	push_atPosition(&head_ref, 13, 1);
	print_List(head_ref);
	return 0; 
} 
