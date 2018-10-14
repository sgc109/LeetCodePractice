// 13m 3s O(nlgn)
// 2 try

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
    priority_queue<pair<int,int>> pq;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] == NULL) continue;
            pq.push({-lists[i]->val, i});
        }
        ListNode* ans = NULL;
        ListNode* cur = NULL;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            if(cur != NULL) cur->next = lists[p.second];
            cur = lists[p.second];
            if(ans == NULL) ans = cur;
            lists[p.second] = lists[p.second]->next;
            if(lists[p.second] != NULL) {
                pq.push({-lists[p.second]->val, p.second});
            }
        }
        return ans;
    }
};
