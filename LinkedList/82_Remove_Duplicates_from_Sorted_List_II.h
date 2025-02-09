
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
	ListNode* deleteDuplicates(ListNode* head) {

		ListNode* ret = new ListNode(0, head);
		ListNode* pre = ret;
		ListNode* node = head;

		while (node)
		{
			if (node->next && node->val == node->next->val)
			{
				while (node->next && node->val == node->next->val)
				{
					node = node->next;
				}

				pre->next = node->next;
			}
			else
			{
				pre = node;
			}

			node = node->next;

		}

		return ret->next;
	}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		// sentinel
		ListNode* sentinel = new ListNode(0, head);
		// predecessor = the last node
		// before the sublist of duplicates
		ListNode* pred = sentinel;
		while (head != NULL) {
			// If it's a beginning of duplicates sublist
			// skip all duplicates
			if (head->next != NULL && head->val == head->next->val) {
				// Move till the end of duplicates sublist
				while (head->next != NULL && head->val == head->next->val) {
					head = head->next;
				}
				// Skip all duplicates
				pred->next = head->next;
				// otherwise, move predecessor
			}
			else {
				pred = pred->next;
			}
			// move forward
			head = head->next;
		}
		return sentinel->next;
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
	ListNode* deleteDuplicates(ListNode* head) {

		ListNode* node = head;
		ListNode* pre = head;

		while (node)
		{
			if (nullptr == pre && node->next && node->val != node->next->val)
			{
				pre = node;
			}
			else if(pre && node->next && node->val != node->next->val)
			{
				pre->next = node->next;
				pre = nullptr;
			}
			
			node = node->next;
		}

		return head;
	}
};

