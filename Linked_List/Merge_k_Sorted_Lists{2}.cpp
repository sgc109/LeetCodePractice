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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> sorted;
        for(ListNode* node : lists){
            while(node){
                sorted.push_back(node->val);
                node = node->next;
            }
        }
        sort(sorted.begin(), sorted.end());
        ListNode* dummy = new ListNode(0);
        ListNode* back = dummy;
        for(int i = 0; i < sorted.size(); i++){
            back->next = new ListNode(sorted[i]);
            back = back->next;
        }
        return dummy->next;
    }
};

