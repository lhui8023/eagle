//
// Created by leihui on 4/25/18.
//
#include <stdio.h>
#include <stack>
namespace my_stack {
int main() {
    std::stack<int> S;
    if (S.empty()) {
        printf("S is empty\n");
    }

    S.push(5);
    S.push(6);
    S.push(10);

    printf("S.top = %d\n", S.top());

    S.pop();
    S.pop();
    printf("S.top = %d\n", S.top());
    printf("S.size = %ld\n", S.size());

    return 0;
};
}