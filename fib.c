#include <stdio.h>
#include <stdlib.h>

unsigned long long fibRecursive(int num);
unsigned long long fibIterative(int num);

int main(int argc, char* argv[]) {
    // Set argument as variables
    int integer = atoi(argv[1]);
    char type = argv[2][0];
    char* filename = argv[3];


    FILE *fileTxt = fopen(filename, "r");
    char content[100];
    fgets(content, 100, fileTxt);

    int number2 = atoi(content);
    int N = number2 + integer;

    // Resolve the -1 indexing by substracing value
    if(type == 'r') {
        printf("%llu\n", fibRecursive(N - 1)); // Recursive call
    }
    else if(type == 'i') {
        printf("%llu\n", fibIterative(N - 1)); // Iterative call
    }

    return 0;
}

unsigned long long fibRecursive(int num) {
    if(num <= 1) return num;
    else return fibRecursive(num - 2) + fibRecursive(num - 1);
}

unsigned long long fibIterative(int num) {
    unsigned long long prevPrevNumber = 0;
    unsigned long long prevNumber = 1;
    unsigned long long summation;

    for(int iter = 0; iter < num - 1; iter++) {
        summation = prevNumber + prevPrevNumber;
        prevPrevNumber = prevNumber;
        prevNumber = summation;
    }

    return summation;
}
