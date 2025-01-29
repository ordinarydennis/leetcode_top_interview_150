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

	std::unordered_map<Node*, Node*> m;

public:
	Node* copyRandomList(Node* node) {

		if (!node)
			return nullptr;

		if (m.count(node))
			return m[node];

		auto* newNode = new Node(node->val);

		m[node] = newNode;

		newNode->random = copyRandomList(node->random);
		newNode->next = copyRandomList(node->next);

		return newNode;

	}
};

class Solution {

	std::unordered_map<Node*, Node*> m;

	Node* copy(Node* node)
	{
		if (!node)
			return nullptr;

		if (m.count(node))
			return m[node];

		auto* newNode = new Node(node->val);

		return m[node] = newNode;

	}

public:
	Node* copyRandomList(Node* head) {

		auto* node = head;

		while (node)
		{
			auto* newNode = copy(node);
			newNode->next = copy(node->next);
			newNode->random = copy(node->random);

			newNode = newNode->next;
			node = node->next;
		}

		return m[head];
	}
};