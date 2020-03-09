#include "threads.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


#define _GNU_SOURCE

int numAnimals;
void countAnimals(){
    int numSheep;
    int numCows;
    while(1){
        if(numSheep >= 500) yeild();
        else numSheep = countSheep(numSheep);
        if(numCows >= 500) yeild();
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
    int numApples;
    int numOranges;
    while(1){
        if(numApples >=500) yeild(); 
        else numApples = countApples(numApples);
        if(numOranges >= 500) yeild();
        else numOranges = countOranges(numOranges);
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