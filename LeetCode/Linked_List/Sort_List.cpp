// 16m 20s
// 2 try (but, so many compile errors..)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* dummy = new ListNode(0);
    ListNode* mergeSort(ListNode* list){
        assert(list);
        
        int size = 0;
        ListNode* cur = list;
        while(cur) {
            size++;
            cur = cur->next;
        }
        if(size == 1) return list;
        
        cur = list;
        for(int i = 0; i < size / 2 - 1; i++) cur = cur->next;
        ListNode* l = list;
        ListNode* r = cur->next;
        cur->next = NULL;
        l = mergeSort(l);
        r = mergeSort(r);
        
        cur = dummy;
        while(l && r) {
            if(l->val < r->val) cur->next = l, l = l->next;
            else cur->next = r, r = r->next;
            cur = cur->next;
        }
        while(l) cur->next = l, l = l->next, cur = cur->next;
        while(r) cur->next = r, r = r->next, cur = cur->next;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        return mergeSort(head);
    }
};
