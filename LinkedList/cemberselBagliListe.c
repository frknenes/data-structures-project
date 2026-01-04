#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int data) {
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    ptr1->data = data;
    ptr1->next = *head;

    if (*head != NULL) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = ptr1;
    } else {
        ptr1->next = ptr1;
        *head = ptr1;
    }
}

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev;

    while (curr->data != key) {
        if (curr->next == *head) {
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == *head && prev == NULL) {
        *head = NULL;
        free(curr);
        return;
    }

    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = curr->next;
        prev->next = *head;
        free(curr);
    } else if (curr->next == *head) {
        prev->next = *head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Liste: ");
    printList(head);

    deleteNode(&head, 20); 
    
    printf("Silme sonrasi: ");
    printList(head);

    deleteNode(&head, 10); 
    
    printf("Bas eleman silindikten sonra: ");
    printList(head);

    return 0;
}