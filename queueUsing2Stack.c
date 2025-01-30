#include <stdio.h>
#define MAX_SIZE 100

struct Stack
{
    int arr[MAX_SIZE];
    int indexOfStack;
};

struct Queue{
    struct Stack inputStack, outputStack;
    int size;
};

int isEmptyStack(struct Stack *stack){
    if(stack->indexOfStack == 0){
        return 1;
    }
    return 0;
}

void push(struct Stack *stack, int value){
    if(stack->indexOfStack >= MAX_SIZE){
        printf("Stack Overflow!\n");
        return;
    }    
    stack->arr[(stack->indexOfStack)] = value;
    stack->indexOfStack++;    
}

void pop(struct Stack *stack){
    if(stack->indexOfStack <= 0){
        printf("Stack Underflow!\n");
        return;
    }
    stack->indexOfStack--;
}

int top(struct Stack * stack){
    if (stack->indexOfStack == 0)
    {
        return -1;
    }
    return stack->arr[(stack->indexOfStack)-1];
}

void enqueue(struct Queue *queue){
    int value;
    printf("Enter the value which you want to enqueue to the queue:\n");
    scanf("%d", &value);
    push(&queue->inputStack,value);
    queue->size++;
}

void dequeue(struct Queue *queue){
    if(isEmptyStack(&queue->outputStack) == 0){
        pop(&queue->outputStack);
    }
    else{
        while(isEmptyStack(&queue->inputStack) == 0){
            int value = top(&queue->inputStack);
            push(&queue->outputStack, value);
            pop(&queue->inputStack);
        }
        int value = top(&queue->outputStack);
        pop(&queue->outputStack);
        printf("The dequeued value is %d.\n",value);
    }
    queue->size--;
}

int peek(struct Queue *queue){
    if(isEmptyStack(&queue->outputStack)==0){
        int topOfQueue = top(&queue->outputStack);
        return topOfQueue;
    }
    else{
        if (isEmptyStack(&queue->inputStack)) {
            printf("Queue is empty!\n");
            return -1;
        }
        while(isEmptyStack(&queue->inputStack) == 0){
            int value = top(&queue->inputStack);
            push(&queue->outputStack, value);
            pop(&queue->inputStack);
        }
        return top(&queue->outputStack);
    }
}

int size(struct Queue queue){
    return queue.size;
}

void isEmpty(struct Queue queue){
    if(size(queue) == 0){
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack is not empty.\n");
}

int main(){
    struct Queue queue;
    queue.inputStack.indexOfStack = 0;
    queue.outputStack.indexOfStack = 0;
    queue.size = 0;
    int choice;
    while (1)
    {
        printf("\nQueue Operations are:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Size\n6. Exit\nChoose the operation you want to perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&queue);
            break;

        case 2:
            dequeue(&queue);
            break;

        case 3:
            printf("The value at the front of the queue is %d.\n", peek(&queue));
            break;

        case 4:
            isEmpty(queue);
            break;

        case 5:
            printf("The size of the queue is %d.\n", size(queue));
            break;

        case 6:
            printf("The program is exiting...");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }
    return 0;
}
