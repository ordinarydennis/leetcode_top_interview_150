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
	ListNode* rotateRight(ListNode* head, int k) {

		if (0 == k)
			return head;

		if (nullptr == head)
			return nullptr;

		auto* node = head;

		int len = 0;

		while (node)
		{
			len++;
			node = node->next;
		}

		int m = k % len;

		if (0 == m)
			return head;
	   
		node = head;

		for (int i = 0; i < len - m; i++)
		{
			node = node->next;
		}

		auto ret = node;

		for(int i = 0; i < len; i++)
		{
			if (i == len - 1)
			{
				node->next = nullptr;
				break;
			}

			if (nullptr == node->next)
			{
				node->next = head;
			}

			node = node->next;
		}   

		return ret;
	}
};