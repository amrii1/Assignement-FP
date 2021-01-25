#include <iostream>
#include <cstdlib>

#define MAX_VAL 15

using namespace std;

typedef struct Node
{
	int val;
	Node *next;
} Node;

/**
 * Create singly linked list containing maxval nodes. 
 * The value of the node is its rank in the linked list.
 * @param head of the linked list
 * @param the current node index incremented after each node creation (will be the node value also)
 * @param the number of nodes in the linked list
 **/
void createSinglyLinkedList(Node **head, int curVal, int maxVal)
{
	if(curVal == maxVal || maxVal < 1)
        return;
    *head = (Node*)malloc(sizeof(Node));
    (*head)->val = curVal;
    (*head)->next = NULL;
    curVal++;
    createSinglyLinkedList(&((*head)->next), curVal, maxVal);
}

/**
 * Print singly linked list in reverse.
 * @param head of the linked list
 **/
void printSinglyLinkedListInReverse(Node *head)
{
	if(head == NULL)
	    return;
	printSinglyLinkedListInReverse(head->next);
	cout << head->val << " | ";
}
/**
 * Delete singly linked list recursively
 * @param head of the linked list
 **/
void freeLinkedListRecursive(Node **head)
{
	if(*head == NULL)
	    return;
	freeLinkedListRecursive(&((*head)->next));
	free(*head);
	*head = NULL;
}

/**
 * Delete singly linked list.
 * @param head of the linked list
 **/
void freeLinkedList(Node **head)
{
	Node *node;
	while (*head != NULL)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		node = NULL;
	}
}

int main()
{    
    Node *head = NULL;
    createSinglyLinkedList(&head, 0, MAX_VAL);
    printSinglyLinkedListInReverse(head);
    cout << endl;
    freeLinkedList(&head); // or freeLinkedListRecursive(&head);
    return 0;
}
