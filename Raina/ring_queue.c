#include <stdio.h>
#define MAX_QUEUE_LEN 5  

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
    int front;
    int rear;
    int count;
} rq_t;

// Initialize the queue
int rq_init(rq_t *q) {

    if (q == NULL) return -1;

    q->front = 0; // for deletion
    q->rear = 0; // for insertion
    q->count = 0; // // Total number of elements in the queue

    return 0;
}

// Enqueue operation
int rq_enqueue(rq_t *q, int val) {

    if (q == NULL) return -1;

    // Check if the queue is full  
    if (q->count == MAX_QUEUE_LEN)  // First condition to be checked that if queue is full (basic condition)
    {
        return -1;  
    }
    // if not full, insert the value at rear
    q->value[q->rear] = val;

    // if rear was at index 4 (last position), next becomes 0.
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;

    q->count++;

    return 0;
}

// Dequeue operation
int rq_dequeue(rq_t *q, int *val) {

    if (q == NULL || val == NULL) 
    {
        return -1;
    }

    if (q->count == 0) return -1;  // queue is empty

    // now it will store the removed value in the pointer.
    *val = q->value[q->front];

    // now moves front next and check if it at end, make it 0(start idx).
    q->front = (q->front + 1) % MAX_QUEUE_LEN;

    q->count--;

    return 0;
}

// Print queue state
void print_queue(rq_t *q) {

    if (q->count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    int i = q->front;

    for (int c = 0; c < q->count; c++) {

        printf("%d ", q->value[i]);

        i = (i + 1) % MAX_QUEUE_LEN;
    }

    printf("\nFront at: %d, Rear at: %d\n", q->front, q->rear);
}

int main() {

    rq_t q;
    rq_init(&q);

    printf("Enqueue 10:\n");
    rq_enqueue(&q, 10);
    print_queue(&q);

    printf("\nEnqueue 20:\n");
    rq_enqueue(&q, 20);
    print_queue(&q);

    printf("\nEnqueue 30:\n");
    rq_enqueue(&q, 30);
    print_queue(&q);

    printf("\nDequeue:\n");
    int val;
    if (rq_dequeue(&q, &val) == 0) {
        printf("Dequeued: %d\n", val);
    }
    print_queue(&q);

    printf("\nEnqueue 40:\n");
    rq_enqueue(&q, 40);
    print_queue(&q);

    printf("\nEnqueue 50:\n");
    rq_enqueue(&q, 50);
    print_queue(&q);

    printf("\nAttempting Enqueue 60 (should fail - queue full):\n");
    if (rq_enqueue(&q, 60) == -1) {
        printf("Queue is full!\n");
    }
    print_queue(&q);

    printf("\nDequeue:\n");
    if (rq_dequeue(&q, &val) == 0) {
        printf("Dequeued: %d\n", val);
    }
    print_queue(&q);

    printf("\nEnqueue 60 (should succeed now):\n");
    rq_enqueue(&q, 60);
    print_queue(&q);

    return 0;
}


