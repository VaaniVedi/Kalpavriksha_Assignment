//Sort a stack in ascending order.

#include <stdio.h>
#define size 100

struct stack{
    int arr[size];
    int index;
};

void push(int data, struct stack *st){
    if(st->index > size) return ;
    st->arr[st->index] = data;
    st->index++;
}

int pop(struct stack *st){
    if(st->index == 0){
        return -1;
    }
    st->index--;
    return st->arr[st->index];
}

int isEmpty(struct stack st){
    return st.index == 0;
}

void sortStack(struct stack *st){
    struct stack temp;
    temp.index = 0;
    while(!isEmpty(*st)){
        int value = pop(st);
        while ((!isEmpty(temp)) && (temp.arr[temp.index - 1] > value))
        {
            push(pop(&temp), st);
        }
        push(value, &temp);        
    }
    while(!isEmpty(temp)){
        push(pop(&temp), st);
    }
}

void printSt(struct stack *st){
    struct stack temp;
    temp.index = 0;
    while(!isEmpty(*st)){
        int value = pop(st);
        printf("%d\n", value);
        push(value, &temp);
    }
    printf("\n");
    while(!isEmpty(temp)){
        push(pop(&temp), st);
    }
}

int main(){
    struct stack st;
    st.index = 0;
    int totElements;
    scanf("%d",&totElements);
    for(int index = 0; index<totElements; index++){
        int value;
        scanf("%d",&value);
        push(value, &st);
    }
    printf("Original:\n");
    printSt(&st);
    sortStack(&st);
    printf("Sorted:\n");
    printSt(&st);
    return 0;
}

