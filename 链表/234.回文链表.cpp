/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head){

    if(head == NULL)
    {
        return false;
    }

    // 快慢指针:找中间指针
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 反转中间指针之后的链表
    struct ListNode* cur = NULL;

    while(slow)
    {
        struct ListNode* next = slow->next;
        slow->next = cur;
        cur = slow;
        slow = next;
    }

    // 对应比大小
    while(cur && head)           // 考虑奇数个数的链表，slow指向中间节点，反转后多一个节点
    {
        if(head->val != cur->val)
        {
            return false;
        }
        head = head->next;
        cur = cur->next;
    }

    return true;

}
