#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "factorial.h"

int recursiveFactorial(int num){
    if(num<1){
        return 0;
    }else if(num == 1 || num == 2){
        return num;
    }else{
        return num*recursiveFactorial(num-1);
    }
}

int iterativeFactorial(int num){
    int factorialAux = 1;
    if(num<1){
        return 0;
    }else{
        for(int i = 1; i<=factorialAux; i++){
            factorialAux*=i;
        }
    }
    return factorialAux;
}