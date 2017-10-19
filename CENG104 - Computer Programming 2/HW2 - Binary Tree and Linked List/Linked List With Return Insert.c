#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* insertNode (struct node* head, int data); // this function add element to the link list
void display (struct node* head); // this function shows the elements of the link list
struct node* find (struct node* head, int data); // this function finds the elements of the link list
struct node* deleteNode (struct node* head, struct node* element); // this function deletes the elements of the link list
int countNodes (struct node* head); // this function counts number of elements and shows it

int main ()
{
    struct node* head = NULL;
    struct node* nodePtr = NULL;

    printf("1- Insert Node\n");
    printf("2- Find Node\n");
    printf("3- Delete Node\n");
    printf("4- Count Nodes\n");
    printf("0- EXIT\n");

    int choice = 1, data;
    while (choice != 0)
    {
        printf("\nEnter your choice: ");
        scanf("\n%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("\n%d", &data);
                head = insertNode(head, data);
                display(head);
                break;
            case 2:
                printf("Enter the value to find: ");
                scanf("\n%d", &data);
                nodePtr = find (head, data); // if data is unfound, function returns NULL

                if (nodePtr == NULL)
                    printf("%d is not found !\n", data);
                else
                    printf("%d is found !\n", data);

                display(head);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("\n%d", &data);
                nodePtr = find (head, data); // find function returns points of number, or NULL
                head = deleteNode(head, nodePtr);
                display(head);
                break;
            case 4:
                display(head);
                int x, count = countNodes(head);
                printf("Number of nodes are %d\nGraphic: ", count);
                for (x = 0; x < count; x++)
                    printf("*");
                printf("\n");
                break;
            case 0:
                return 0;
        }
    }

    return 0;
}

struct node* insertNode (struct node* head, int data) // this function add element to the link list
{
    struct node* newPtr = NULL;
    struct node* currentPtr = NULL;

    newPtr = (struct node*) malloc(sizeof(struct node));

    if (newPtr != NULL) // successfully created
    {
        newPtr->data = data;
        newPtr->next = NULL;
    }
    else if (newPtr == NULL) // failed, memory is not available
        return head;

    if (head == NULL) // we add first element to the link list
    {
        head = newPtr;
        return newPtr;
    }
    else // we add element to the end of the link list
    {
        for (currentPtr = head; currentPtr->next != NULL; currentPtr = currentPtr->next)
            ;
        currentPtr->next = newPtr;
        return head;
    }
}

void display (struct node* head) // This function shows the elements of the link list
{
    struct node* currentPtr = NULL;

    printf("The list is: ");
    for (currentPtr = head; currentPtr != NULL; currentPtr = currentPtr->next)
        printf("%d --> ", currentPtr->data);

    printf("NULL\n");
}

struct node* find (struct node* head, int data) // this function finds the elements of the link list
{
    struct node* currentPtr = NULL;

    for (currentPtr = head; currentPtr != NULL; currentPtr = currentPtr->next)
    {
        if (currentPtr->data == data) // if we find the data that we are looking in the link list, it is true
            return currentPtr;
    }

    return NULL; // if we not find the data in the link list, return NULL
}

struct node* deleteNode (struct node* head, struct node* element) // this function deletes the elements of the link list
{
    struct node* currentPtr = NULL;
    struct node* temp = NULL;

    for (temp = head; temp != element; temp = temp->next) // we search element that we want delete in the link list
        currentPtr = temp;

    if (temp == NULL) // we not find element that we want delete it
        return head;

    if (currentPtr == NULL) // we want delete the first element of the link list
    {
        head = head->next;
        free(temp);
    }
    else
    {
        currentPtr->next = temp->next;
        free(temp);
    }

    return head;
}

int countNodes (struct node* head) // this function counts number of elements and shows it
{
    if (head == NULL)
        return 0;
    return 1 + countNodes(head->next);
}
