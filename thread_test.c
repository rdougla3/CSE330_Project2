#include "threads.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define _GNU_SOURCE

int incrementCount(int count){
    return ++count;
}

int maxSheep = 5;
int maxCows = 10;
void countAnimals(){
    int numSheep = 0;
    int numCows = 0;
    while(1){
        if(numSheep >= maxSheep){
            printf("Counted max sheep. Yielding...\n");
            yield();
        }   
        else{
            numSheep = incrementCount(numSheep);
            printf("Counting sheep #%d\n", numSheep);
        } 
        if(numCows >= maxCows){
            printf("Counted max cows. Yielding...\n");
            yield();
        }   
        else{
            numCows = incrementCount(numCows);
            printf("Counting cow #%d\n", numCows);
        } 
    }
}

int maxOranges = 10;
int maxApples = 5;
void countFruit(){
    int numOranges = 0;
    int numApples = 0;
    while(1){
        if(numOranges >= maxOranges){
            printf("Counted max oranges. Yielding...\n");
            yield();
        }   
        else{
            numOranges = incrementCount(numOranges);
            printf("Counting orange #%d\n", numOranges);
        } 
        if(numApples >= maxApples){
            printf("Counted max apples. Yielding...\n");
            yield();
        }   
        else{
            numApples = incrementCount(numApples);
            printf("Counting apple #%d\n", numApples);
        } 
    }
}

int main (){
    
    start_thread(countAnimals);
    start_thread(countFruit);
    run();
}