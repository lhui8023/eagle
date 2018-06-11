//
// Created by leihui on 5/5/18.
//

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

namespace perceptron {
const double lr = 1;
const int dim = 2;
const int n = 3;
double w[dim] = {0, 0};
double b = 0;
double samples[n][dim] = {3,3,      4,3,    1,1};
int labels[n] = {1, 1, -1};

//计算两个向量的內积
double dot(double *w, double *feature) {
    double sum = 0;
    for(int i = 0; i < dim; i++){
        printf("%d\n", *w);
        printf("%d\n", *feature);
        printf("%ld\n", (*w) * (*feature));
        sum += (*w) * (*feature);
        w++;
        feature++;
    }
    return sum;
}

//感知机算法
void perceptron(){
    while (true) {
        int i;
        for (int i = 0; i < n; ++i) {
            if(labels[i] * (dot(w, samples[i]) + b) <= 0){
                cout << "w：(";
                for (int j = 0; j < dim; ++j) {
                    w[j] = w[j] + lr * labels[i] * samples[i][j];
                    cout << w[j];
                    if (j != dim - 1) {
                        cout << ",";
                    }
                }
                b = b + lr * labels[i];
                cout << ") b: " << b << endl;
                break;
            }
        }
        if (i == n) {
            break;
        }

    }
}

int main(){

    //0x561c0a15f260

    perceptron();

    char   szValue[]  =   "0x561c0a15f260";
    int    nValude    =   0;
    sscanf(szValue,"%x",&nValude);
    printf("%d\n",nValude);
    return 0;
}
}
