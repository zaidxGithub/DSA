class MinStack {
public:
    // initlizing a vecttor
    // we can use the push_back() , back(), empty() efficientky in O(1) as a top
    // element

    // store the pair <curr element , min till now > in vector ;

    vector<pair<int, int>> v;

    MinStack() {}

    void push(int value) {

        // coditons

        // 1 if the vector is empty
        if (v.empty()) {

            // directy insert the value and minTilNow
            pair<int, int> p = {value, value};
            v.push_back(p);
            return;
        }

        // have some elements

        // 1 step: get minTillNow -> udpate minTillNow
        pair<int, int> p = v.back();
        int minTillNow = p.second;

        minTillNow = min(value, minTillNow);
        v.push_back({value, minTillNow});
    }

    void pop() {

        v.pop_back();
    }

    int top() {
                //get the back of vector as top
    int top=v.back().first;
    return top;
        
    }

    int getMin() {
        int minVal=v.back().second;
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */