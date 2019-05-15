#includestdio.h 
#include stdlib.h 

struct Node 
{
    int data;
    struct Node next;
};

void push_front (struct Node head, int data)
{
    struct Node new_node = (struct Node)malloc(sizeof(struct Node));
    new_node-data = data;
    new_node-next = (head);
    (head) = new_node;
    return;
}

void print_List (struct Node head){
    struct Node current = NULL;
    current = head;
    while (current != NULL)
    {
        printf(%d , current-data);
        current = current-next;
    }
    printf(n);
    return;
}

void reverse_List (struct Node head) {
    struct Node prev, next = NULL;
    struct Node current = (head);
    while (current != NULL){
        next = current-next;
        current-next = prev;
        printf(debug %d,current-data);
        prev = current;
        current = next;
    }
    (head) = prev;
    return;
}

int main() 
{ 
	struct Node head_ref = NULL;
	push_front(&head_ref, 5);
	push_front(&head_ref, 4);
	push_front(&head_ref, 3);
	push_front(&head_ref, 2);
	push_front(&head_ref, 1);
	printf(Created Linked List before reversingn);
	print_List(head_ref);
	printf(Created Linked List after reversingn);
	reverse_List(&head_ref);
	print_List(head_ref);
	return 0; 
} 
