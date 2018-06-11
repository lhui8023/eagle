//
// Created by leihui on 5/4/18.
//
#include <stdio.h>
#include <vector>
#include <queue>
namespace find_median_from_data_stream {
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (small.size() == 0) {
            small.push(num);
            return;
        }

        int tmp;
        if (small.size() == large.size()) {
            tmp = large.top();
            if (num <= tmp)
                small.push(num);
            else {
                large.pop();
                small.push(tmp);
                large.push(num);
            }
        } else {
            tmp = small.top();
            if (num < tmp) {
                small.pop();
                large.push(tmp);
                small.push(num);
            } else {
                large.push(num);
            }
        }
        /*if (big_queue.empty()) {
            big_queue.push(num);
            return;
        }

        if (big_queue.size() == small_queue.size()) {
            if (num < big_queue.top()) {
                //small_queue.push(num);
                big_queue.push(num);
            } else {
                //big_queue.push(num);
                small_queue.push(num);
            }
        } else if (big_queue.size() > small_queue.size()) {
            if (num > big_queue.top()) {
                small_queue.push(num);
            } else {
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }
        } else if (big_queue.size() < small_queue.size()) {
            if (num < small_queue.top()) {
                big_queue.push(num);
            } else {
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
        }*/
    }

    double findMedian() {
        if (small.size() == large.size())
            return (small.top() + large.top())/2.0;
        else
            return small.top();

/*        if (big_queue.size() == small_queue.size()) {
            return (big_queue.top() + small_queue.top()) / 2.0d;

        } else if (big_queue.size() > small_queue.size()) {

            return big_queue.top() / 1.0d;
        }
        return small_queue.top();*/

    }

private:
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, std::greater<int> > large;
    //std::priority_queue<int, std::vector<int>, std::greater<int> > big_queue;
    //std::priority_queue<int, std::vector<int>, std::less<int>> small_queue;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main() {

/*    std::priority_queue<int, std::vector<int>, std::less<int> > big_queue;
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue;

    big_queue.push(1);
    big_queue.push(2);
    big_queue.push(3);
    big_queue.push(4);

    printf("%d\n", big_queue.top());
    small_queue.push(8);
    small_queue.push(6);
    small_queue.push(5);
    small_queue.push(7);

    printf("%d\n", small_queue.top());*/

    MedianFinder m;

    //std::vector<int> v;
  /*  medianFinder.addNum(1);
    medianFinder.addNum(2);
    medianFinder.addNum(5);
    medianFinder.addNum(4);
    medianFinder.addNum(3)*/;

    int test[] = {6, 10, 1, 7, 99, 4, 33};

    for (int i = 0; i < 7; ++i) {
        m.addNum(test[i]);
        printf("%lf\n", m.findMedian());
    }

    return 0;
}
}