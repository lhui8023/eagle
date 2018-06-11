//
// Created by leihui on 4/30/18.
//
/**
 * 5
 * 1 2 3 4 5
 * 5 4 1 2 3
 * 0
 * 6
 * 6 5 4 3 2 1
 * 0
 * 0
 */
#include <stdio.h>
#include <stack>
#include <queue>

namespace poj1363rails {
bool check_is_valid_order(std::queue<int> &order) {
    std::stack<int> S;
    int n = order.size();
    for (int i = 1; i < n; ++i) {
        S.push(i);

       /* if (order.front() != S.top()) {
            S.push(i);
        } else {
            order.pop();
            S.pop();
        }*/
       while (!S.empty() && order.front() == S.top()) {
           order.pop();
           S.pop();
       }
    }

    if (!S.empty()) {
        return false;
    }
    return true;

}

int main() {
    int n;
    int train;
    scanf("%d", &n);

    while (n) {
        scanf("%d", &train);
        while (train) {
            std::queue<int> order;
            order.push(train);
            for (int i = 1; i < n; i++) {
                scanf("%d", &train);
                order.push(train);
            }

            if (check_is_valid_order(order)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            scanf("%d", &train);
        }
        printf("\n");
        scanf("%d", &n);
    }

    return 0;
}
}
