//
// Created by leihui on 4/26/18.
//
#include <stdio.h>
#include <stack>
#include <queue>

namespace implement_stack_using_queues{


class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        std::queue<int> temp_queue;
        temp_queue.push(x);

        while (!custom_queue.empty()) {
            temp_queue.push(custom_queue.front());
            custom_queue.pop();
        }

        while (!temp_queue.empty()) {
            custom_queue.push(temp_queue.front());
            temp_queue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = custom_queue.front();
        custom_queue.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return custom_queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return custom_queue.empty();
    }

private:
    std::queue<int> custom_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main() {

    MyStack S;

    S.pop();

    printf("%d\n", S.top());

    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);

    printf("%d\n", S.top());
    S.pop();
    printf("%d\n", S.top());
    S.push(5);
    printf("%d\n", S.top());


    return 0;
}
}