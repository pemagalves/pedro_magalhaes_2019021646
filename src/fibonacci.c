#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fibonacci.h"

int recursiveFibonacci(int num){
    if(num < 1){
        return 0;
    } else if(num == 1 || num == 2){
        return 1;
    } else {
        return recursiveFibonacci(num - 1) + recursiveFibonacci(num - 2);
    }
};

int iterativeFibonacci(int num){
    int a = 1, b = 1;
    int aux;
    if(num < 1){
        return 0;
    } else if(num == 1 || num == 2){
        return 1;
    };
    for(int i = 3; i<=num; i++){
        aux = a + b;
        a = b;
        b = aux;
    }
    return aux;
};