/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == headB)
    {
      return headA;
    }
    // 长度相等时，一一对应找，因为尾部一样
    struct ListNode *h1 = headA;
    struct ListNode *h2 = headB;
    // 计算长度，找最长的，然后长的先走长度之差步
    int count1 = 0;
    int count2 = 0;
    while(h1)
    {
      count1++;
      h1 = h1->next;
    }
    while(h2)
    {
      count2++;
      h2 = h2->next;
    }
    h1 = headA;
    h2 = headB;
    int i = count1<count2?count2-count1:count1-count2;

    // 移步
    if(count1 < count2)
    {
      while(i)
      {
        h2 = h2->next;
        i--;
      }
    }
    if(count1 > count2)
    {
      while(i)
      {
        h1 = h1->next;
        i--;
      }
    }

    // 寻找相交节点
    while(h1 && h2)
    {
        if(h1 == h2)
        {
          return h1;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;

}
