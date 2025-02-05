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
	ListNode* partition(ListNode* head, int x) {

		ListNode* lessNode = nullptr;

		ListNode* curNode = head;
		ListNode* preNode = nullptr;

		while (curNode)
		{
			if (curNode->val < x)
			{
				preNode = curNode;
				curNode = curNode->next;
			}
			else
			{
				auto* lessPreNode = curNode;
				auto* lessNode = curNode->next;
				while (lessNode &&  x <= lessNode->val)
				{
					lessPreNode = lessNode;
					lessNode = lessNode->next;
				}

				if (lessNode)
				{
					preNode->next = lessNode;
					lessPreNode->next = lessNode->next;
					lessNode->next = curNode;
					preNode = curNode;
					curNode = lessNode->next;
				}
				else
				{
					break;
				}

			}

		}

		return head;
	}
};