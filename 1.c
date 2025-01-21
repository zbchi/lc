#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建一个新节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 合并两个有序链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode head;
    struct ListNode* current=&head;
    while(list1!=NULL&&list2!=NULL)
    {
        if(list1->val<list2->val)
        {
            current->next=list1;
            list1=list1->next;
        }
        else
        {
            current->next=list2;
            list2=list2->next;
        }
        current=current->next;
    }
    current->next=(list1!=NULL)?list1:list2;
    return head.next;
}
// 打印链表
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

// 释放链表占用的内存
void freeList(struct ListNode* node) {
    while (node != NULL) {
        struct ListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    // 构建 list1: 1 -> 2 -> 4
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    // 构建 list2: 1 -> 3 -> 4
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    // 合并两个链表
    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    // 打印合并后的链表
    printf("Merged List:\n");
    printList(mergedList);

    // 释放分配的内存
    freeList(mergedList);

    return 0;
}