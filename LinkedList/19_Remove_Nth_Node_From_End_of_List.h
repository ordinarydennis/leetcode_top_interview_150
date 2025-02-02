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
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		int len = 0;

		ListNode* node = head;
		ListNode* pre = nullptr;

		while (node)
		{
			pre = node;
			node = node->next;
			len++;
		}

		if (n == 1 && len == 1)
			return nullptr;

		if (len == n)
			return head->next;

		int pos = len - n - 1;

		node = head;

		while (0 < pos)
		{
			node = node->next;
			pos--;
		}

		node->next = node->next->next;

		return head;
	}
};
