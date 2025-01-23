class MinStack {
public:
    void push(int val) {

		if (st.empty())
		{
			st.push({ val, val });
			return;
		}
			
		st.push( { val, std::min(getMin(), val) } );
    }

    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }

private:
	std::stack<pair<int, int>> st;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

