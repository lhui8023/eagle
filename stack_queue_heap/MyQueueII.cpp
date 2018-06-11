//
// Created by leihui on 4/26/18.
//

#include <stdio.h>
#include <stack>

namespace my_queue_ii{

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        input_stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = 0;
        if (!output_stack.empty()) {
            x = output_stack.top();
            output_stack.pop();
        } else {
            while (!input_stack.empty()) {
                output_stack.push(input_stack.top());
                input_stack.pop();
            }
            x = output_stack.top();
            output_stack.pop();
        }
        return x;
    }

    /** Get the front element. */
    int peek() {
        int x = 0;
        if (!output_stack.empty()) {
            x = output_stack.top();
        } else {
            while (!input_stack.empty()) {
                output_stack.push(input_stack.top());
                input_stack.pop();
            }
            x = output_stack.top();
        }
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input_stack.empty() && output_stack.empty();
    }

private:
    std::stack<int> input_stack;
    std::stack<int> output_stack;
};

int main() {
    //MyQueue Q;

    //printf("Q.peek = %d\n", Q.peek());

    //Q.pop();

   // printf("Q.peek = %d\n", Q.peek());

/*    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);

    printf("%d\n", Q.peek());
    Q.pop();
    printf("%d\n", Q.peek());
    Q.push(5);
    printf("%d\n", Q.peek());*/

    MyQueue obj;
    obj.push(1);
    int param_2 = obj.pop();
    printf("param_2 = %d\n", param_2);
    //int param_3 = obj.peek();
    //printf("param_3 = %d\n", param_3);
    bool param_4 = obj.empty();
    printf("param_4 = %d\n", param_4);

}
}














