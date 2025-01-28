/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {

		if (nullptr == head)
		{
			return nullptr;
		}

		Node* node = head;

		Node* newHead = new Node(0);

		Node* newNode = newHead;

		unordered_map<int, Node*> m1;
		unordered_map<Node*, int> m2;
 
		int index = 0;

		while (node)
		{
			m2[node] = index;

			m1[index] = newNode;

			newNode->val = node->val;
			newNode->random = node->random;

			if (node->next)
			{
				newNode->next = new Node(0);
				newNode = newNode->next;
			}

			node = node->next;

			index++;
		}

		newNode = newHead;

		while (newNode)
		{
			if (newNode->random)
			{
				int i = m2[newNode->random];

				newNode->random = m1[i];
			}

			newNode = newNode->next;
		}

		return newHead;
	}
};