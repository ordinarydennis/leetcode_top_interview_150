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

		ListNode* node = head;
		ListNode* leftNode = nullptr;
		ListNode* rightNode = nullptr;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;

		int index = 1;

		while (node && index <= right + 1)
		{
			if (left - 1 == index)
			{
				pre = node;
			}
			else if (right + 1 == index)
			{
				next = node;
			}
			else if (left == index)
			{
				leftNode = node;
			}
			else if (right == index)
			{
				rightNode = node;
			}

			node = node->next;

			index++;
		}

		bool isLast = (nullptr != rightNode && nullptr == rightNode->next);
		if (leftNode && rightNode)
		{
			node = leftNode;

			ListNode* pre2 = nullptr;
			int i = right - left + 1;
			while (i)
			{
				auto* temp = node->next;
				node->next = pre2;
				pre2 = node;
				node = temp;
				i--;
			}

			if (pre)
			{
				pre->next = rightNode;
			}
			
			leftNode->next = next;
		}

		if (isLast)
		{
			return rightNode;
		}

		return head;
	}
};


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
