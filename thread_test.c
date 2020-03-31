#include "threads.h"
#include "sem.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define _GNU_SOURCE

int incrementCount(int count){
    return ++count;
}

struct Semaphore* semaphore;

int maxSheep = 50;
int maxCows = 100;
void countAnimals(){
    int numSheep = 0;
    int numCows = 0;
    
    while(1){
        P(semaphore);
        if(numSheep >= maxSheep){
            printf("Counted max sheep. Yielding...\n");
            
        }   
        else{
            numSheep = incrementCount(numSheep);
            printf("Counting sheep #%d\n", numSheep);
        } 
        if(numCows >= maxCows){
            printf("Counted max cows. Yielding...\n");
            
        }   
        else{
            numCows = incrementCount(numCows);
            printf("Counting cow #%d\n", numCows);
        } 
        V(semaphore);
    }
}

int maxOranges = 100;
int maxApples = 50;
void countFruit(){

    int numOranges = 0;
    int numApples = 0;
    while(1){
        P(semaphore);
        if(numOranges >= maxOranges){
            printf("Counted max oranges. Yielding...\n");
        
        }   
        else{
            numOranges = incrementCount(numOranges);
            printf("Counting orange #%d\n", numOranges);
        } 
        if(numApples >= maxApples){
            printf("Counted max apples. Yielding...\n");
          
        }   
        else{
            numApples = incrementCount(numApples);
            printf("Counting apple #%d\n", numApples);
        }
        V(semaphore); 
    }
}

int main (){
    InitSem(semaphore, 0);
    start_thread(countAnimals);
    start_thread(countFruit);
    run();
}