//
// Created by leihui on 4/22/18.
//https://leetcode.com/problems/partition-list/description/
//
/**
 * Definition for singly-linked list.
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 */
#include <stdio.h>
namespace partition_list {
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode pre_head(0);
        ListNode* pre = &pre_head;
        ListNode tail_head(0);
        ListNode* tail = &tail_head;

        while (head) {
            if (head->val < x) {
                pre->next = head;
                //pre = pre->next;
                pre = head;
            } else {
                tail->next = head;
                //tail = tail->next;
                tail = head;
            }
            head = head->next;
        }

        pre->next = tail_head.next;

        tail->next = NULL; //no

        return pre_head.next;

    }
};

int main() {

    ListNode a(1);
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(2);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;


    Solution solution;
    ListNode* head = solution.partition(&a, 3);

    while (head ) {
        printf("%d\n", head->val);

        head = head->next;
    }


    return 0;
}}