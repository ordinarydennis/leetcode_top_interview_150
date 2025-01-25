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
	bool hasCycle(ListNode* head) {

		ListNode* node = head;

		unordered_set<ListNode*> m;

		while (node)
		{
			if (m.count(node))
			{
				return true;
			}
			
			m.insert(node);
			node = node->next;
		}

		return false;

	}
};
