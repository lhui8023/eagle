//
// Created by leihui on 4/16/18.
// https://leetcode.com/problems/reverse-linked-list/description/
// 方法一、就地逆置法
//

#include <stdio.h>
namespace listnode1 {
struct ListNode {       //存储元素的 数据域
    int val;
    ListNode *next; //存储自身地址的 指针域
    ListNode(int x) : val(x), next(NULL) {
    }
};

class Solution {
public:                     //链表头节点指针
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = NULL;
        while (head) {
            ListNode* next = head->next;    //备份head->next
            head->next = new_head;  //更新head->next
            new_head = head; //移动head->next

            head = next; //遍历链表
        }
        //返回链表逆序后的头节点指针
        return new_head;
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
    ListNode b(20); //利用构造函数初始化5个独立的链表节点
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);

    a.next = &b;
    b.next = &c;    //通过指针，将5个节点进行连接
    c.next = &d;
    d.next = &e;
    ListNode *head = &a;    //利用head指针遍历连接后的链表
    ListNode *new_head = NULL;
    ListNode *next = NULL;



    Solution* solution = new Solution();

    //print_list(solution->reverseList(head), "new_new");

    //print_list(head, "old");


    for(int i =0; i< 5; i++){
        next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;

        print_list(head, "old");
        print_list(new_head, "new");
    }


    //print_list(new_head, "new");


    while(head) {
        printf("%d %p %p\n", head->val, head, head->next);

        head = head->next; //填空 没填出来

    }

    return 0;
}
}
