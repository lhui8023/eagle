//
// Created by leihui on 4/21/18.
// https://leetcode.com/problems/merge-two-sorted-lists/description/
//
#include <iostream>
namespace merge_two_sorted_lists {
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode temp_head(0);  //设置临时头节点 temp_head
        ListNode* pre = &temp_head; //no //使用pre 指针指向temp_head
        while (l1 && l2) {
            if (l1->val > l2->val) { //l1与l2同时不为空时，对它们进行比较
                //temp_head.next = l2;
                pre->next = l2;   //将pre与较小的节点进行连接
                l2 = l2->next;
            } else {
                //temp_head.next = l1;
                pre->next = l1;
                l1 = l1->next;
            }
            //temp_head.next = pre;
            pre = pre->next;    //将pre指向新连接的节点
        }

        if (l1) {
            pre->next = l1; //将l1接到pre后
        }

        if (l2) {
            pre->next = l2; //将l2接到pre后
        }

        return temp_head.next;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(4);

    a.next = &b;
    b.next = &c;

    ListNode d(1);
    ListNode e(3);
    ListNode f(4);

    d.next = &e;
    e.next = &f;

    ListNode* l1 = &a;

    ListNode* l2 = &d;

    Solution solver;
    ListNode* head = solver.mergeTwoLists(l1, l2);

    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }

    return 0;
}}