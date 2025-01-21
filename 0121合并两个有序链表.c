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