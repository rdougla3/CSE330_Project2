#include "threads.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define _GNU_SOURCE

int numAnimals;
void countAnimals(){
    int numSheep = 0;
    int numCows = 0;
    while(1){
        if(numSheep >= 500) yield();
        else numSheep = countSheep(numSheep);
        if(numCows >= 500) yield();
        else numCows = countCows(numCows);
        numAnimals = numSheep + numCows;
        
    }
}

int countSheep(int sheep){
    return ++sheep;
}

int countCows(int cows){
    return ++cows;
}

int numFruit;
void countFruit(){
    int numApples = 0;
    int numOranges = 0;
    while(1){
        if(numApples >=500) yield();
        else numApples = countApples(numApples);
        if(numOranges >= 500) yield();
        else numOranges = countOranges(numOranges);
        numFruit = numApples + numOranges;
        
    }
}

int countApples(int apples){
    return ++apples;
}

int countOranges(int oranges){
    return ++oranges;
}

int main (){
    start_thread(countAnimals);
    start_thread(countFruit);
    run();
}