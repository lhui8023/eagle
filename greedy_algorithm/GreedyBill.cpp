//
// Created by leihui on 5/11/18.
//
#include <stdio.h>
namespace greedy_bill {
    int main() {
        const int RMB[] = {200, 100, 20, 10, 5, 1};
        const int NUM = 6; //6种面值
        int X = 628;
        int count = 0;

        for (int i = 0; i < NUM; ++i) {
            int use = X / RMB[i];
            //X = X % RMB[i];
            X = X - RMB[i] * use;
            printf("需要面额为%d的%d张，剩余需要支付金额%d.\n",RMB[i] ,use, X);
            count += use;
        }
        printf("总共需要%d张", count);
    }
}