#include <stdio.h>

#define SIZE 4       // size of the queue
int queue[SIZE];     // initially unknown
int front = -1;      // empty condition
int rear = -1;       // empty condition

void enqueue(int val) {
    // If queue is full
    if ((rear + 1) % SIZE == front) {
        printf("Full: cannot add %d in the queue\n", val);
    }
    // If queue is empty
    else if (front == -1) {
        // Add the first value in the queue
        front = 0;
        rear = 0;
        queue[rear] = val;

        printf("Add %d in the queue\n", val);
    }
    else {
        // Calculate the next position to add a value
        rear = (rear+1) % SIZE;

        // Add the value in the queue
        queue[rear] = val;

        printf("Add %d in the queue\n", val);
    }
}

int dequeue() {
    // If queue is empty
    if (front == -1) {
        printf("Empty: no return value\n");
        return -1; // Return a sentinel value indicating an error
    }
    // If there is only one element
    else if (front == rear) {
        // A variable to store the value to be returned
        int out;

        // Get the return value
        out = queue[front];
        
        // Reset `front` and `rear` to the empty condition
        front = -1;
        rear = -1;
        
        // Return the value
        printf("Dequeue returns %d\n", out);
        return out;
    }
    else {
        // A variable to store the value to be returned
        int out;

        // Get the return value
        out = queue[front];
        
        // Update the `front` position
        front = (front +1) % SIZE;
        
        // Return the value
        printf("Dequeue returns %d\n", out);
        return out;
    }
}

void display() {
    printf("** queue: ");
    // Empty
    if (front == -1) {
        printf("empty");
    }
    // Only one element
    else if (front == rear) {
        printf("%d", queue[front]);
    }
    else {
        // When `rear` is after `front`
        if (rear >= front) {
            // Print from `front` to `rear`
            for (int i=front ; i<=rear ; i++) {
                printf("%d ", queue[i]);
            }
        }
        // When `front` is after `rear`
        else {
            // Print from `front` to SIZE-1
            for (int i=front ; i<SIZE ; i++) {
                printf("%d ", queue[i]);
            }
            // Print from 0 to `rear`
            for (int i=0 ; i<=rear ; i++) {
                printf("%d ", queue[i]);
            }
        }
        
    }
    printf("\n");
}

int main() {
    int temp;
    display();
    enqueue(5);
    enqueue(0);
    enqueue(-1);
    enqueue(3);
    enqueue(2);
    display();
    temp = dequeue();
    temp = dequeue();
    display();
    enqueue(42);
    enqueue(11);
    enqueue(39);
    display();
    temp = dequeue();
    temp = dequeue();
    temp = dequeue();
    temp = dequeue();
    temp = dequeue();
    display();
    enqueue(8);
    temp = dequeue();
    display();
    return 0;
}
