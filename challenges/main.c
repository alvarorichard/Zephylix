#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para um nó da lista
typedef struct Node {
    char* data; // Ponteiro para a string alocada dinamicamente (heap)
    struct Node* prev; // Ponteiro para o nó anterior
    struct Node* next; // Ponteiro para o próximo nó
} Node;

// Estrutura para a lista duplamente vinculada
typedef struct {
    Node* head; // Ponteiro para o início da lista
    Node* tail; // Ponteiro para o fim da lista
} DoublyLinkedList;

// Função para criar um novo nó
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para um novo nó.\n");
        exit(1);
    }
    newNode->data = strdup(data); // Duplica a string para o heap
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Função para inicializar a lista
DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (list == NULL) {
        printf("Erro ao alocar memória para a lista.\n");
        exit(1);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Função para inserir um item no fim da lista
void insertEnd(DoublyLinkedList* list, const char* data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

// Função para encontrar um item na lista
Node* find(DoublyLinkedList* list, const char* data) {
    Node* current = list->head;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Não encontrado
}

// Função para excluir um item da lista
void deleteItem(DoublyLinkedList* list, const char* data) {
    Node* toDelete = find(list, data);
    if (toDelete == NULL) {
        printf("Item não encontrado.\n");
        return;
    }
    if (toDelete->prev != NULL) {
        toDelete->prev->next = toDelete->next;
    } else {
        list->head = toDelete->next;
    }
    if (toDelete->next != NULL) {
        toDelete->next->prev = toDelete->prev;
    } else {
        list->tail = toDelete->prev;
    }
    free(toDelete->data); // Libera a memória da string
    free(toDelete); // Libera a memória do nó
}

// Função para imprimir a lista
void printList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Função para liberar toda a memória alocada pela lista
void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current->data); // Libera a string
        free(current); // Libera o nó
        current = next;
    }
    free(list); // Libera a estrutura da lista
}

int main() {
    DoublyLinkedList* list = createList();

    insertEnd(list, "Hello");
    insertEnd(list, "World");
    insertEnd(list, "!");
    printList(list); // Deve imprimir: Hello World !

    Node* found = find(list, "World");
    if (found != NULL) {
        printf("Item encontrado: %s\n", found->data);
    } else {
        printf("Item não encontrado.\n");
    }

    deleteItem(list, "World");
    printList(list); // Deve imprimir: Hello !

    freeList(list); // Libera a memória alocada pela lista

    return 0;
}
