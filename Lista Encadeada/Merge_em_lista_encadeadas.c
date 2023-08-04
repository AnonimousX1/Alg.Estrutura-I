#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do n� da lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Fun��o para mesclar duas listas ordenadas
struct Node* merge(struct Node* left, struct Node* right) {
    // Caso base: se uma das listas estiver vazia, retorna a outra lista
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    // Escolhe o menor valor como o n� atual e mescla as listas restantes recursivamente
    struct Node* result;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Fun��o para dividir a lista em duas partes
void split(struct Node* head, struct Node** left, struct Node** right) {
    struct Node* slow = head;
    struct Node* fast = head->next;

    // O ponteiro "fast" avan�a duas vezes mais r�pido que o ponteiro "slow"
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // "slow" est� no ponto m�dio da lista, divide em duas partes
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

// Fun��o principal de ordena��o Merge Sort
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* left;
    struct Node* right;

    // Caso base: lista vazia ou com apenas um elemento
    if (head == NULL || head->next == NULL) {
        return;
    }

    // Divide a lista em duas partes
    split(head, &left, &right);

    // Recursivamente ordena as duas partes
    mergeSort(&left);
    mergeSort(&right);

    // Mescla as partes ordenadas
    *headRef = merge(left, right);
}

// Fun��o para inserir um novo n� no in�cio da lista
void push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Fun��o para imprimir a lista encadeada
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Fun��o de teste
int main() {
    struct Node* head = NULL;

    // Insere elementos na lista encadeada
    push(&head, 8);
    push(&head, 4);
    push(&head, 12);
    push(&head, 2);
    push(&head, 10);

    printf("Lista original: ");
    printList(head);

    // Ordena a lista usando o Merge Sort
    mergeSort(&head);

    printf("Lista ordenada: ");
    printList(head);

    return 0;
}

