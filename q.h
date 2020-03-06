//CSE 330 Project 1
//Matthew Acosta + Ross Douglas

#include <unistd.h>
#include <stdlib.h>
#include "TCB.h"

#define _GNU_SOURCE

struct Q {
    struct TCB_t* head;
    struct TCB_t* tail;
};

void InitQueue(struct Q* head){
    struct Q* q; 
    q->head = NULL;
    q->tail = NULL;
    q = head;
};

struct TCB_t* NewItem(){
    struct TCB_t* q_element;
    q_element->next = NULL;
    q_element->prev = NULL;

    return q_element;
};

void AddQueue(struct Q* q, struct TCB_t* item){
    if(q->head == NULL) {
        q -> head = item;
        q-> tail = item;
    } else if(q->tail == q->head) {
        item->prev = q->head;
        item->next = q->head;
        
        q->tail = item;

        q->head->prev = q->tail;
        q->head->next = q->tail;
    } else {
        item->prev = q->tail;
        item->next = q->head;

        q->tail->next = item;
        q->head->prev = item;

        q->tail = item;
    }
}

 struct TCB_t* DelQueue(struct Q* q){
     if(q->head == NULL) {
         return NULL;
     }
     else if(q->head == q->tail) {
         struct TCB_t* temp = q->head;
         q->head = NULL;
         q->tail = NULL;
         return temp;
     }
     else {
         struct TCB_t* temp = q->head;
         q->tail->next = q->head->next;
         q->head = q->head->next;
         q->head->prev = q->tail;
         return temp;
     }
};

void RotateQ(struct Q* q){
    q->tail = q->head;
    q->head = q->head->next;
}

