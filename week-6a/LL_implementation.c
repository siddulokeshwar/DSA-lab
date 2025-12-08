#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head1 = NULL, *head2 = NULL;

void createList(struct node **head) {
    struct node *newNode, *temp = NULL;
    int n, data, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) {
        *head = NULL;
        return;
    }
    *head = NULL;
    for (i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (*head == NULL)
            *head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    printf("List created: ");
    temp = *head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayList(struct node *head) {
    struct node *temp = head;
    if (!head) {
        printf("List is empty\n");
        return;
    }
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseList(struct node **head) {
    struct node *prev = NULL, *next = NULL, *cur = *head;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;

    printf("Reversed list: ");
    displayList(*head);
}

void sortList(struct node **head) {
    struct node *i, *j;
    int t;
    if (!*head) {
        printf("List is empty\n");
        return;
    }
    for (i = *head; i; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
    printf("Sorted list: ");
    displayList(*head);
}

void concatenateList() {
    struct node *temp;
    if (!head1) {
        head1 = head2;
        return;
    }
    if (!head2) return;
    temp = head1;
    while (temp->next)
        temp = temp->next;
    temp->next = head2;
    printf("Concatenated List1 + List2: ");
    displayList(head1);
}

int main() {
    int choice, listChoice;
    while (1) {
        printf("\n1.Create List1\n2.Create List2\n3.Reverse\n4.Sort\n5.Display\n6.Concatenate\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            createList(&head1);
            break;
        case 2:
            createList(&head2);
            break;
        case 3:
            printf("Reverse which list (1/2): ");
            scanf("%d", &listChoice);
            if (listChoice == 1) reverseList(&head1);
            else reverseList(&head2);
           break;
        case 4:
            printf("Sort which list (1/2): ");
            scanf("%d", &listChoice);
            if (listChoice == 1) sortList(&head1);
            else sortList(&head2);
            break;
        case 5:
            printf("Display which list (1/2): ");
            scanf("%d", &listChoice);
            if (listChoice == 1) displayList(head1);
            else displayList(head2);
            break;
        case 6:
            concatenateList();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
