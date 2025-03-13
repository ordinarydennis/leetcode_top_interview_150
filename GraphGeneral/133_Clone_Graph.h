/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/

class Solution {

	Node* dfs(const Node* node)
	{
		if (!node)
			return nullptr;

		if (m.count(node->val))
			return m[node->val];
		
		Node* newNode = new Node(node->val);

		m[node->val] = newNode;

		for (const auto* nnode : node->neighbors)
		{
			newNode->neighbors.push_back(dfs(nnode));
		}

		return newNode;
	}

	unordered_map<int, Node*> m;

public:
	Node* cloneGraph(Node* node) {

		return dfs(node);

	}
};