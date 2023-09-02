// 第一种方法
struct ListNode* partition(struct ListNode* head, int x){

    // 使用哨兵
    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail1 = head1;
    tail1->next = NULL;

    struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail2 = head2;
    tail2->next = NULL;

    while(head)
    {
        if(head->val < x)
        {
            tail1->next = head;
            tail1 = tail1->next;
        }
        else
        {
            tail2->next = head;
            tail2 = tail2->next;
        }
        head = head->next;
    }
    tail1->next = head2->next;
    tail2->next = NULL;

    return head1->next;
}


// 第二种方法
struct ListNode* partition(struct ListNode* head, int x){

    struct ListNode* phead = NULL;
    struct ListNode* tail = NULL;
    
    while(head)
    {
        if(head->val < x)
        {
            if(phead == NULL)
            {
                phead = tail = head;
                head = head->next;
            }
            else
            {
                struct ListNode* next = head->next;
                head->next = phead;
                phead = head;
                head = next;   
            }
        }
        else
        {
            if(phead == NULL)
            {
                phead = tail = head;
                head = head->next;
            }
            else
            {
                tail->next = head;
                tail = tail->next;
                head = head->next;
            }
        }
    }
    if(phead == NULL)
    {
        return tail;
    }
    else
    {
        tail->next = NULL;
        return phead;
    }
}
