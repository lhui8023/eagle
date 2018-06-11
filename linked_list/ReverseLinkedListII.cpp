//
// Created by leihui on 4/19/18.
//https://leetcode.com/problems/reverse-linked-list-ii/description/


#include <iostream>
namespace reverse_linked_list_II{
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n - m + 1;
        ListNode* pre_head = NULL;
        ListNode* result = head;

        while (head && --m) {
            pre_head = head;
            head = head->next;
        }

        ListNode* modify_list_tail = head;
        ListNode* new_head = NULL;

        while (head && change_len) {
            //ListNode* next = head;  bug bug bug ....
            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            //head = head->next;   bug bug bug ....
            head = next;
            change_len --;
        }

        //new_head->next = head; //已经是逆序的头元素了擦。。

        modify_list_tail->next = head;

        if(pre_head) {
            pre_head->next = new_head;
        } else {
            //new_head->next = modify_node_list; //已经在在modify_list_tail->next = head; 中拼接完成了
            result = new_head;
        }

        return result;
    }
};


int main() {

    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);
    ListNode f(60);
    ListNode g(70);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;

    ListNode* head = &a;

    Solution solver;
    head = solver.reverseBetween(&a, 3, 4);

    while (head){
        printf("%d\n", head->val);
        head = head->next;
    }












    return 0;
}
}