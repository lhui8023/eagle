//
// Created by leihui on 4/23/18.
//
/**
 * Definition for singly-linked list with a random pointer.
 */
#include <stdio.h>
#include <map>
#include <vector>
namespace copy_list_with_random_pointer {

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        std::map<RandomListNode *, int> node_map; //地址到节点位置的map
        std::vector<RandomListNode *> node_vec; //使用vector根据存储节点位置访问地址
        RandomListNode *ptr = head;
        int i = 0;
        while (ptr) {
            node_vec.push_back(new RandomListNode(ptr->label));
            node_map[ptr] = i;//1
            ptr = ptr->next;
            i++;
        }
        node_vec.push_back(0);

        ptr = head;
        i = 0;
        while (ptr) {
            node_vec[i]->next = node_vec[i+1];//2
            if(ptr->random) { //当random指针不空时
                int id = node_map[ptr->random];//根据node_map确认
                node_vec[i]->random = node_vec[id];//3
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};


int main(){
    std::map<RandomListNode *, int> node_map;
    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);

    a.next = &b;
    b.next = &c;

    a.random = &c;
    b.random = &a;
    c.random = &c;

    node_map[&a] = 1;
    node_map[&b] = 2;
    node_map[&c] = 3;

    printf("a.random id = %d\n", node_map[a.random]);
    printf("b.random id = %d\n", node_map[b.random]);
    printf("c.random id = %d\n", node_map[c.random]);


    Solution solution;
    RandomListNode *head = solution.copyRandomList(&a);

    while (head) {
        printf("%d\n", head->label);
        head = head->next;
    }

    return 0;
}
}