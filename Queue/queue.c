#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define the structure for the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new queue node
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to enqueue (add) an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue (remove) an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1; // Return a sentinel value indicating an empty queue
    }
    
    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL; // The queue is now empty
    }
    
    free(temp);
    return data;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to free the memory used by the queue
void freeQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 3);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue)); // Trying to dequeue from an empty queue

    freeQueue(queue);

    return 0;
}
