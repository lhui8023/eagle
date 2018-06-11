//
// Created by leihui on 5/11/18.
// https://leetcode.com/problems/wiggle-subsequence/description/
//
/**
 *
Input: [1,1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
 */

#include <stdio.h>
#include <vector>
namespace wiggle_subsequence {
class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int max_length = 1;

        for (int i = 1; i < nums.size(); i++) {
            switch (STATE) {
                case BEGIN:
                    if (nums[i-1] < nums[i]) {
                        STATE = UP;
                        max_length ++;
                    } else if (nums[i-1] > nums[i]) {
                        STATE = DOWN;
                        max_length ++;
                    }
                    break;
                case UP:
                    if (nums[i-1] > nums[i]) {
                        STATE = DOWN;
                        max_length ++;
                    }
                    break;
                case DOWN:
                    if (nums[i-1] < nums[i]) {
                        STATE = UP;
                        max_length ++;
                    }
                    break;
            }
        }
        return max_length;
    }
};

int main() {
    Solution solution;
    std::vector<int> v1 = {1,7,4,9,2,5};
    printf("%d\n", solution.wiggleMaxLength(v1));

    std::vector<int> v2 = {1,17,5,10,13,15,10,5,16,8};
    printf("%d\n", solution.wiggleMaxLength(v2));

    std::vector<int> v3 = {1,2,3,4,5,6,7,8,9};
    printf("%d\n", solution.wiggleMaxLength(v3));


    return 0;
}
}