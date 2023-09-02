struct ListNode *detectCycle(struct ListNode *head) {

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    // 找相遇点（看笔记：相遇点到入环点的距离 == 起始点到入环点的距离）
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            struct ListNode *meet = slow;
            while(meet != head)
            {
                meet = meet->next;
                head = head->next;
            }
            return meet;
        }
    }
    
    return NULL;  
}
