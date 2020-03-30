#include "threads.h"

#define _GNU_SOURCE

struct Semaphore{
    int value;
    struct Q* TCB_Q;
};

void InitSem(Semaphore* semaphore, int value){
    semaphore->value = value;
}

void P(Semaphore* semaphore){
    semaphore->value--;
    
    if(semaphore->value < 0) {
        Prev_Thread = RunQ->head;
        AddQueue(semaphore->TCB_Q, DelQueue(RunQ)); //Delete the head TCB from RunQ and add it to the semaphore queue
        Curr_Thread = RunQ->head;
        swapcontext(&(Prev_Thread->context), &(Curr_Thread->context)); //a new head of RunQ is started using swapcontext
    }
}

void V(Semaphore* semaphore){
    semaphore->value++;

    if(semaphore->value <= 0){
        AddQueue(RunQ, DelQueue(semaphore->TCB_Q)); //Delete the head TCB from the semaphore and add it to the RunQ
        yield(); //yield to the next runnable thread 
    }
}