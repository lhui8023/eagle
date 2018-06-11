//
// Created by leihui on 4/17/18.
//
#include <iostream>

namespace listnode2 {
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){

    }
};
class Solution {
public:                     //链表头节点指针
    ListNode* reverseList(ListNode* head) {
        ListNode temp_head(0);
        printf("%d %p %p\n", temp_head.val,temp_head, temp_head.next);
        while (head) {
            ListNode* next = head->next; // 保存10 节点的下一个节点20

            //temp_head = next; // 临时头节点为20的节点
            //temp_head->next = head; // 将20的节点 下一个节点置换为10的节点
            //head = next->next;

            head->next = temp_head.next;

            temp_head.next = head;

            head = next;
        }
        return temp_head.next;
    }

};
//打印head指针指向的链表
void print_list(ListNode *head, const char *list_name) {
    printf("%s :", list_name);
    if(!head){
        printf("NULL\n");
        return;
    }

    while (head) {
        printf("[%d] ", head->val);
        head = head->next;
    }
    printf("\n");
}
int main() {
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    Solution solve;
    ListNode* head = &a;

    printf("%d %p %p\n", head->val,head, head->next);

    printf("Before reverse:\n");
    while (head){
        printf("%d\n", head->val);
        head = head->next;
    }

    head = solve.reverseList(&a);
    printf("After reverse:\n");

    while (head){
        printf("%d\n", head->val);
        head = head->next;
    }


    return 0;
}}