//
// Created by leihui on 5/11/18.
// https://leetcode.com/problems/assign-cookies/description/
//
#include <stdio.h>
#include <vector>
#include <algorithm>

/**
 * Input: g = [4, 5, 10, 2, 9, 15, 9], s = [6, 4, 1, 20, 3, 8]
 * Output: 3
 * Input: [1,2], [1,2,3]
 * Output: 2
 */

 namespace assign_cookies {
/*
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < g.size(); ++j) {
                if (s[i] >= g[j]) {
                    count ++;
                    g.erase(g.begin() + j);
                    break;
                }
            }
        }
        return count;
    }
};
*/
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int child = 0;
        int candy = 0;

        while (child < g.size() && candy < s.size()){
            if(g[child] <= s[candy]) {
                child++;
            }
            candy++;
        }




        return child;
    }
};
int main() {
   // g = [4, 5, 10, 2, 9, 15, 9], s = [6, 4, 1, 20, 3, 8]
    std::vector<int> v1 = {5, 10, 2, 9, 15, 9};
    std::vector<int> v2 = {6, 1, 20, 3, 8};

    Solution solution;

    int count = solution.findContentChildren(v1, v2);

    printf("%d\n",count);

    /*std::vector<int> v3 = {1, 2};
    std::vector<int> v4 = {1, 2, 3};*/
    std::vector<int> v3 = {1, 2, 3};
    std::vector<int> v4 = {3};

    int count2 = solution.findContentChildren(v3, v4);

    printf("%d\n",count2);
}}

