#include "stack.c"

int main() {
    Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);

    printf("Top element: %d\n", peek(&myStack));

    peek_through(&myStack);

    pop(&myStack);
    pop(&myStack);

    printf("Top element after popping: %d\n", peek(&myStack));

    clear(&myStack);

    return 0;
}
