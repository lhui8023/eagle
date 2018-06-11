//
// Created by leihui on 4/27/18.
//
#include <stdio.h>
#include <stack>
namespace min_stack {
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        data_stack.push(x);

        if (mini_stack.empty()) {
            mini_stack.push(x);
        } else {
            if (x > mini_stack.top()) {
                x = mini_stack.top();
            }
            mini_stack.push(x);
        }

/*        int mini = getMin();
        if (x < mini) {
            mini_stack.push(x);
        } else {
            mini_stack.push(mini);
        }*/
    }

    void pop() {
        data_stack.pop();
        mini_stack.pop();
    }

    int top() {
        return data_stack.top();
    }

    int getMin() {
        return mini_stack.top();
    }

private:
    std::stack<int> data_stack;
    std::stack<int> mini_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {

    return 0;
}}