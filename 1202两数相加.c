struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode*p1=l1;
    struct ListNode*p2=l2;
    struct ListNode*head=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*pCurrent=head;
    int carry=0;//放在循环外面以免初始化为0
    while(p1!=NULL||p2!=NULL||carry!=0)
    {
        struct ListNode*newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        int a=0,b=0;
        if(p1!=NULL)
        {
            a=p1->val;
            p1=p1->next;
        }
        if(p2!=NULL)
        {
            b=p2->val;
            p2=p2->next;
        }

        int sum=a+b+carry;
        carry=sum/10;
        newNode->val=sum%10;
        newNode->next=NULL;
        
        pCurrent->next=newNode;
        pCurrent=pCurrent->next;

    }  

    
    return head->next;
}