#include "q.h"

struct Q* RunQ;

void start_thread(void (*function) (void)){
    int* stack = malloc(8192); //allocate a stack of 8192 bytes
    TCB_t* TCB = (TCB_t*)malloc(sizeof(TCB_t)); //allocate a TCB
    init_TCB(TCB, function, stack, sizeof(stack)); //call init_TCB 
    TCB->thread_id = ++global_thread_id; //initialize thread_id
    AddQueue(RunQ, TCB); //call addQ to add this TCB into the "RunQ"
}