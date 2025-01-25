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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* node = new ListNode;

		ListNode* ret = node;

		int n = 0;

		while (l1 || l2)
		{
			int val = n;
			val += (l1) ? l1->val : 0;
			val += (l2) ? l2->val : 0;

			node->val = val % 10;

			n = val / 10;

			l1 = (l1) ? l1->next : nullptr;
			l2 = (l2) ? l2->next : nullptr;

			if (nullptr == l1 && nullptr == l2)
			{
				if (n)
				{
					node->next = new ListNode;
					node->next->val = n;
				}
			}
			else
			{
				node->next = new ListNode;
				node = node->next;
			}
		}


		return ret;
	}
};
