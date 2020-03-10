#include "threads.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define _GNU_SOURCE

int incrementCount(int count){
    return ++count;
}

void countAnimals(){
    int numSheep = 0;
    int numCows = 0;
    while(1){
        if(numSheep >= 250)
            yield();
        else numSheep = incrementCount(numSheep);
        if(numCows >= 500) 
            yield();
        else numCows = incrementCount(numCows);
    }
}

int numFruit;
void countFruit(){
    int i = 0;
    while(1){
        if(numFruit >=500)
            yield();
        else numFruit = incrementCount(numFruit);
    }
}

int main (){
    
    start_thread(countAnimals);
    start_thread(countFruit);
    run();
}