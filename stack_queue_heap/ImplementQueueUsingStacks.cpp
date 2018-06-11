//
// Created by leihui on 4/26/18.
//
#include <stdio.h>
#include <stack>
namespace implement_queue_using_stacks {
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        std::stack<int> reverse_stack;

        while (!custom_stack.empty()) {
            reverse_stack.push(custom_stack.top());
            custom_stack.pop();
        }

        custom_stack.push(x);

        while (!reverse_stack.empty()) {
            custom_stack.push(reverse_stack.top());
            reverse_stack.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = custom_stack.top();
        custom_stack.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        return custom_stack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return custom_stack.empty();
    }

private:
    std::stack<int> custom_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main() {
    MyQueue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);

    printf("%d\n", Q.peek());
    Q.pop();
    printf("%d\n", Q.peek());
    Q.push(5);
    printf("%d\n", Q.peek());
    return 0;
}
}