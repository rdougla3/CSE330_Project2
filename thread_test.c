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
            printf("counted max sheep. yielding...\n");
            yield();
        }   
        else{
            numSheep = incrementCount(numSheep);
            printf("Counting sheep #%d\n", numSheep);
        } 
        if(numCows >= maxCows){
            printf("countet max cows. yielding...\n");
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
            printf("counted max oranges. yielding...\n");
            yield();
        }   
        else{
            numOranges = incrementCount(numOranges);
            printf("Counting orange #%d\n", numOranges);
        } 
        if(numApples >= maxApples){
            printf("counted max apples. yielding...\n");
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