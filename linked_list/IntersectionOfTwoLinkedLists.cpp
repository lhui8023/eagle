//
// Created by leihui on 4/21/18.
//
/**
 * Definition for singly-linked list.
 *
 */
#include <stdio.h>
#include <set>
namespace intersection_of_two_linked_list {
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
/*public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> temp_set;
        while (headA) {
            temp_set.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if(temp_set.find(headB) != temp_set.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};*/
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int list_A_len = get_list_length(headA);
    int list_B_len = get_list_length(headB);

    int d_len = 0;
    if(list_A_len > list_B_len) {
        d_len = list_A_len - list_B_len;
        while (headA && d_len--) {
            headA = headA->next;
        }
    } else {
        d_len = list_B_len - list_A_len;
        while (headB && d_len--) {
            headB = headB->next;
        }
    }

    while (headA && headB) {
        if(headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int get_list_length(ListNode* head) {
    int len = 0;
    while (head) {
        len += 1;
        head = head->next;
    }
    return len;
}
};


int main() {
/*    std::set<int> test_set;
    const int A_LEN = 7;
    const int B_LEN = 8;

    int a[A_LEN] = {5, 1, 4, 8, 10, 1, 3};
    int b[B_LEN] = {2, 7, 6, 3, 1, 6, 0, 1};

    for (int i = 0; i < A_LEN; ++i) {
        test_set.insert(a[i]);
    }
    for (int j = 0; j < B_LEN; ++j) {
        if(test_set.find(b[j]) != test_set.end()) {
            printf("b[%d] = %d in array A.\n", j, b[j]);
        }
    }*/

    ListNode a(3);
    ListNode b(5);
    ListNode c(2);

    a.next = &b;
    b.next = &c;

    ListNode d(1);
    ListNode e(2);

    d.next = &e;
    e.next = &c;

    ListNode* l1 = &a;

    ListNode* l2 = &d;

    Solution solver;
    ListNode* head = solver.getIntersectionNode(l1, l2);

    printf("%d\n", head->val);



    return 0;
}
}