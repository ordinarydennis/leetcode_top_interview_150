class RandomizedSet {
public:
	RandomizedSet() {
		std::srand(static_cast<unsigned>(time(nullptr)));
	}

	bool insert(int val) {

		if (set.count(val))
		{
			return false;
		}

		set.insert(val);
		return true;
	}

	bool remove(int val) {

		if (set.count(val))
		{
			set.erase(val);
			return true;
		}

		return false;

	}

	int getRandom() {

		auto it = set.begin();
		std::advance(it, rand() % set.size());

		return *(it);

	}



private:
	unordered_set<int> set;

};
