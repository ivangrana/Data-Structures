#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
    int size;
} Stack;

void initialize(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed, cannot push %d\n", item);
        return;
    }

    newNode->data = item; // Armazena o valor do item no campo 'data' do novo nó
    newNode->next = stack->top; // Define o próximo nó como o atual topo da pilha
    stack->top = newNode;  // O novo nó agora se torna o topo da pilha
    stack->size++;

}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Retorna um valor -1 indicando erro
    }

    Node* poppedNode = stack->top;
    int poppedData = poppedNode->data;
    stack->top = poppedNode->next;
    free(poppedNode);
    stack->size--;

    return poppedData;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot peek\n");
        return -1; // Return a special value to indicate an error
    }
    return stack->top->data;
}

int peek_through(Stack* stack){
    printf("elements from the stack:\n");
    printf("%d\n",stack->top->data);
    Node *a = stack->top->next;
    for (int i = 1; i < stack->size; i++)
    {
        Node *next = a->next;
        printf("%d\n",a->data);
        a = a->next;
    }

    return 1;
    
}

void clear(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

