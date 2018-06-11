//
// Created by leihui on 6/10/18.
//
#include <stdio.h>

int main() {
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            printf("%d\n",a * 1000 + a * 100 + b * 10 + b);
        }
    }
    return 0;
}

