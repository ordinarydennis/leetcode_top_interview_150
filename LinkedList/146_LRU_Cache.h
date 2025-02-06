

class LRUCache {
public:
	LRUCache(int capacity) {

		max = capacity;

	}

	int get(int key) {

		if (0 == m.count(key))
			return -1;

		st.push(key);

		return m[key];
	}

	void put(int key, int value) {

		if (0 == m.count(key) && m.size() == max)
		{
			int val = st.top();
			st.pop();
			m.erase(val);
		}

		m[key] = value;
	}


private:
	std::unordered_map<int, int> m;
	std::stack<int> st;
	int max = 0;

};