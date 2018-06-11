//
// Created by leihui on 6/3/18.
// int tmp = num[i] - '0';
//
#include <stdio.h>
#include <string>
#include <vector>
namespace remove_digits{
class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::vector<int> S;
        std::string result = "";

        for (int i = 0; i < num.length(); ++i) {
            int number = num[i] - '0';
            while (S.size() != 0 && S[S.size() - 1] > number && k > 0) {
                S.pop_back();
                k--;
            }
            if (S.size() != 0 || number != 0) {
                S.push_back(number);
            }
        }
        while (S.size() != 0 && k > 0){
            S.pop_back();
            k--;
        }

        for (int j = 0; j < S.size(); j++) {
            result.append(1, '0' + S[j]);
        }

        if (result == "") {
            result = "0";
        }

        return result;
    }
};



int main(){
    Solution solution;
    std::string result = solution.removeKdigits("1432219", 3);
    printf("%s\n", result.c_str());
    return 0;
}
}