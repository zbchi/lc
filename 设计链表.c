#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct {
    int size;
    struct ListNode* head;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;
    struct ListNode* pCurrent = obj->head;
    for (int i = 0; i < index; i++)
        pCurrent = pCurrent->next;
    return pCurrent->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->val = val;
    newHead->next = obj->head;
    obj->head = newHead;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    if (obj->head == NULL) {
        obj->head = newNode;
        return;
    }
    struct ListNode* pCurrent = obj->head;
    while (pCurrent->next != NULL) {
        pCurrent = pCurrent->next;
    }
    pCurrent->next = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    if (index == 0) {
        newNode->next = obj->head;
        obj->head = newNode;
        obj->size++;
        return;
    }
    if(index==obj->size)
    {
        myLinkedListAddAtTail(MyLinkedList* obj, int val)
    }
    struct ListNode* pCurrent = obj->head;
    for (int i = 0; i < index - 1; i++) {
        pCurrent = pCurrent->next;
    }
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;
    struct ListNode* tmp = NULL;
    if (index == 0) {
        tmp = obj->head;
        obj->head = tmp->next;
        free(tmp);
    }else{
        struct ListNode* pCurrent = obj->head;
        for (int i = 0; i < index - 1; i++) {
             pCurrent = pCurrent->next;
             }
        tmp = pCurrent->next;
        pCurrent->next = tmp->next;
        free(tmp);
    }
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode* pCurrent = obj->head;
    struct ListNode* tmp;
    while (pCurrent != NULL) {
        tmp = pCurrent->next;
        free(pCurrent);
        pCurrent = tmp;
    }
    free(obj);
}

// 打印链表所有节点的值
void printList(MyLinkedList* obj) {
    struct ListNode* pCurrent = obj->head;
    while (pCurrent != NULL) {
        printf("%d ", pCurrent->val);
        pCurrent = pCurrent->next;
    }
    printf("\n");
}

int main() {
    // 创建链表
    MyLinkedList* obj = myLinkedListCreate();
    
    // 执行操作并打印每次后的链表
    myLinkedListAddAtIndex(obj, 0, 10);  // [10]
    printf("After adding 10 at index 0: ");
    printList(obj);

    myLinkedListAddAtIndex(obj, 0, 20);  // [20, 10]
    printf("After adding 20 at index 0: ");
    printList(obj);

    myLinkedListAddAtIndex(obj, 1, 30);  // [20, 30, 10]
    printf("After adding 30 at index 1: ");
    printList(obj);

    // 获取索引 0 的值（预期输出 20）
    printf("Get index 0: %d\n", myLinkedListGet(obj, 0));

    // 释放链表
    myLinkedListFree(obj);
    
    return 0;
}
