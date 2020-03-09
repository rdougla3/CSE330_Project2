#include "q.h"

struct Q* RunQ;
struct TCB_t* Curr_Thread;
struct TCB_t* Prev_Thread;

void start_thread(void (*function) (void)){
    
    int* stack = malloc(8192); //allocate a stack of 8192 bytes
    TCB_t* TCB = (TCB_t*)malloc(sizeof(TCB_t)); //allocate a TCB
    init_TCB(TCB, function, stack, sizeof(stack)); //call init_TCB
    if(global_thread_id == 1){
        RunQ = (struct Q*) malloc(sizeof(struct Q));
        InitQueue(RunQ, TCB);
    }
    else AddQueue(RunQ, TCB); //call addQ to add this TCB into the "RunQ"
}

void run(){   // real code
    Curr_Thread = RunQ->head;
    ucontext_t parent; // get a place to store the main context, for faking
    getcontext(&parent); // magic sauce
    swapcontext(&parent, &(Curr_Thread->context)); // start the first thread
}

void yield(){
    Prev_Thread = RunQ->head;
    RotateQ(RunQ);
    Curr_Thread = RunQ->head;
    swapcontext(&(Prev_Thread->context), &(Curr_Thread->context)); //swap the context, from Prev_Thread to the thread pointed to by Curr_Thread
}