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
    ListNode* sortList(ListNode* head) {

        ListNode* node = head;

        vector<int> list;

        while (node)
        {
            list.push_back(node->val);
            node = node->next;
        }

        std::sort(list.begin(), list.end());

        node = head;
        int i = 0;
        while (node)
        {
            node->val = list[i++];

            node = node->next;
        }

        return head;
    }
};