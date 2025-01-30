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
	ListNode* reverseBetween(ListNode* head, int left, int right) {

		vector<int> vec;

		auto* node = head;

		while (node)
		{
			vec.push_back(node->val);
			node = node->next;
		}

		reverse(vec.begin() + left - 1, vec.begin() + right);

		ListNode* newHead = nullptr;
		ListNode* pre = nullptr;

		for (int i = 0; i < vec.size(); i++)
		{
			auto* node2 = new ListNode(vec[i]);

			if (i == 0)
				newHead = node2;

			if (nullptr == pre)
			{
				pre = node2;
			}
			else
			{
				pre->next = node2;
				pre = node2;
			}
		}

		return newHead;
	}
};
