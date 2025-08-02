#include <stdio.h>
#include <stdlib.h>

int n;
int s1[100], s2[100];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data) {
    if (top1 == n - 1) {
        printf("Queue is full\n");
    } else {
    	top1++;
        s1[top1] = data;
    }
}

void push2(int data) {
    if (top2 == n - 1) {
        printf("Queue is full\n");
    } else {
    	top2++;
        s2[top2] = data;
    }
}

int pop1() {
    if (top1 == -1) {
        return -1;  
    } else {
        return s1[top1--];
    }
}

int pop2() {
    if (top2 == -1) {
        return -1;  
    } else {
        return s2[top2--];
    }
}

void enqueue(int x) {
    push1(x);
    count++;
}

void dequeue() {
    if (top1 == -1) {
        printf("Queue is empty\n");
        return;
    }

    while (top1 != -1) {
        int temp = pop1();
        push2(temp);
    }

    
    int dequeued = pop2();
    printf("Dequeued: %d\n", dequeued);
    count--;

    // Move elements back to s1
    while (top2 != -1) {
        int temp = pop2();
        push1(temp);
    }
}

void display() {
    if (top1 == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue contents: ");
    for (i = 0; i <= top1; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
}

int main() {
    int num, data;
    printf("Enter size of the queue: ");
    scanf("%d", &n);

    printf("Enter number of elements you want to insert: ");
    scanf("%d", &num);

    if (num > n) {
        printf("Only %d elements can be inserted (queue limit).\n", n);
        num = n;
    }
	int i;
    for (i = 0; i < num; i++) {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        enqueue(data);
    }

    display();
    dequeue();
    display();

    return 0;
}

