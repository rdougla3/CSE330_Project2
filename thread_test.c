#include "threads.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define _GNU_SOURCE

int incrementCount(int count){
    return ++count;
}

int numAnimals;
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
        numAnimals = numCows + numSheep;
        
    }
}

int numFruit;
void countFruit(){
    int numOranges = 0;
    int numApples = 0;
    while(1){
        if(numOranges >= 250)
            yield();
        else numOranges = incrementCount(numOranges);
        if(numApples >= 500)
            yield();
        else numApples = incrementCount(numApples);
        numFruit = numOranges + numApples;
    }
}

int main (){
    
    start_thread(countAnimals);
    start_thread(countFruit);
    run();
}