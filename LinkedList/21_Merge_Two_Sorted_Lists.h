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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

		if (!list1 && !list2)
		{
			return nullptr;
		}

		auto* node1 = list1;
		auto* node2 = list2;

		ListNode* node = new ListNode;
		ListNode* head = node;

		while (node1 || node2)
		{
			if (node1 && node2)
			{
				if (node1->val < node2->val)
				{
					node->val = node1->val;
					node1 = node1->next;
				}
				else
				{
					node->val = node2->val;
					node2 = node2->next;
				}
			}
			else
			{
				if (node1)
				{
					node->val = node1->val;
					node1 = node1->next;
				}
				else if (node2)
				{
					node->val = node2->val;
					node2 = node2->next;
				}
			}

			if (node1 || node2)
			{
				node->next = new ListNode;
				node = node->next;
			}
		}

		return head;

	}
};