//
// Created by leihui on 4/18/18.
//
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */
namespace addtownumbers{
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;
        while (!head) {
            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            head = new_head;
        }
        return head;
    }
};


int main() {

    ListNode a(2);
    ListNode b(4);
    ListNode c(3);

    a.next = &b;
    b.next = &c;


    ListNode d(5);
    ListNode e(6);
    ListNode f(4);

    d.next = &e;
    e.next = &f;

    ListNode* head = &a;

    Solution solve;


    solve.reverseList(&a);

    solve.reverseList(&d);




    return 0;
}}