//
// Created by leihui on 5/2/18.
//
#include <stdio.h>
#include <vector>
#include <queue>

/*class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> big_heap;

        for (int i = 0; i < nums.size(); ++i) {
            big_heap.push(nums[i]);
        }
        printf("big_heap.top = %d\n", big_heap.top());
        for (int j = 0; j < k - 1; ++j) {
            big_heap.pop();
        }

        return big_heap.top();
    }
};*/
namespace kth_largest_element_in_an_array {
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
        //std::priority_queue<int> Q;

        for (int i = 0; i < nums.size(); ++i) {
            if (Q.size() < k) {
                Q.push(nums[i]);
            } else {
                if (Q.top() < nums[i]) {
                    Q.pop();
                    Q.push(nums[i]);
                }
            }
        }

        return Q.top();
    }
};

int main() {
    Solution solution;

    std::vector<int> vector1 = {3,2,1,5,6,4};
    printf("%d\n", solution.findKthLargest(vector1, 2));


    std::vector<int> vector2 = {3,2,3,1,2,4,5,5,6};
    printf("%d\n", solution.findKthLargest(vector2, 4));


    return 0;
}
}