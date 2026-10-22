#include <stdint.h> 
#include <stdbool.h>

#define RING_BUFFER_SIZE 32

typedef struct{
    uint8_t arr[RING_BUFFER_SIZE];
    int head; // to write
    int tail; // to read
} RingBuffer;


// Write to buffer func
bool push(RingBuffer* rb, uint8_t byte){
    
    // Is buffer full
    if (((rb->head + 1) % RING_BUFFER_SIZE) == rb->tail) {
        return false;
    };

    // Write data
    rb->arr[rb->head] = byte;

    //Move forward
    rb->head = (rb->head + 1) % RING_BUFFER_SIZE;

    return true;
}

// Read from buffer func
bool pop(RingBuffer* rb, uint8_t* byte){

    // Is buffer empty
    if (rb->head == rb->tail){
        return false;
    }

    //Read data
    *byte = rb->arr[rb->tail];

    //Move forward
    rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;

    return true;
}