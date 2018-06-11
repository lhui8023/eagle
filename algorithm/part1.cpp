//
// Created by leihui on 6/9/18.
//
#include <stdio.h>
#include <math.h>
namespace part1{
int main(){
    printf("%.2f\n", 8.0 / 5.0);
    printf("%f\n", 8.0 / 5.0);
    printf("%.1f\n", 8 / 5);
    printf("%d\n", 8.0 / 5.0);
    printf("%.8f\n", 1 + 2 * sqrt(3) / (5 - 1.0));


    const double pi = acos(-1.0);
    double r, h, s1, s2, s;
    // scanf("%lf%lf", &r, &h);
    r = 3.5;
    h = 9.0;
    s1 = pi * r * r;
    s2 = 2 * pi * r * h;
    s = s1 * 2.0 + s2;
    printf("Area = %.3f\n", s);

    int num = 500;
    printf("%d%d%d\n", num % 10, num / 10 % 10, num / 100);
    int m = num % 10 * 100 + (num / 10 % 10) * 10 + num / 100;
    printf("%d\n", m);
    printf("%03d\n", m);

    int a = 824;
    int b = 16;
    int t = 0;

    t = a;
    a = b;
    b = t;

    printf("%d %d\n", a, b);


    int e = 824;
    int f = 16;

    /*e = e + f;
    f = e - f;
    e = e - f;*/

   // e ^= f ^= e ^= f;

   // printf("%d %d\n", e, f);

    printf("=======\n");

    int l = 20;
    int j = 7;
    int k = 19;

    if (l <= j && j <= k) printf("%d %d %d\n", l, j, k);
    else if (l <= k && k <= j) printf("%d %d %d\n", l, k, j);
    else if (j <= l && l <= k) printf("%d %d %d\n", j, l, k);
    else if (j <= k && k <= l) printf("%d %d %d\n", j, k, l);
    else if (k <= l && l <= j) printf("%d %d %d\n", k, l, j);
    else if (k <= j && j <= l) printf("%d %d %d\n", k, j, l);

    int tmp;

    if (l > j) {tmp = l; l = j; j = tmp;} // j > l
    if (l > k) {tmp = l; l = k; k = tmp;}
    if (j > k) {tmp = j; j = k; k = tmp;} // k > j
    printf("%d %d %d\n", l, j, k);

    return 0;

}
}