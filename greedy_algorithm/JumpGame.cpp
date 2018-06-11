//
// Created by leihui on 6/5/18.
//
#include <stdio.h>
#include <vector>
namespace jump_game{


class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        std::vector<int> indexes;
        for (int i = 0; i < nums.size(); ++i) {
            indexes.push_back(i + nums[i]);
        }

        int jump = 0;
        int max_index = indexes[0];

        while (jump < indexes.size() && jump <= max_index) {

            if(max_index < indexes[jump]){
                max_index = indexes[jump];
            }
            jump++;
        }

        if(jump == indexes.size()){
            return true;
        }

        return false;
    }
};




int main (){
    Solution solution;
    std::vector<int> v1 = {3, 2, 1, 0, 4};//{4,2,0,0,1,1,4,4,4,0,4,0};// {2,3,1,1,4};
    bool res1 = solution.canJump(v1);
    printf("res1: %d\n", res1);

    std::vector<int> v2 = {1};
    bool res2 = solution.canJump(v2);
    printf("res2: %d\n", res2);


    return 0;
}
}