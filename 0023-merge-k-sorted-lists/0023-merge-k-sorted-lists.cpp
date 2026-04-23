/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Step 1: push all heads
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Step 2: process heap
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = curr;

            if (curr->next) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};