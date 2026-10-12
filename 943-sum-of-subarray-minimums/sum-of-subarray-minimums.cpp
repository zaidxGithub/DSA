class Solution {
public:
    void nextSmallerElement(vector<int>& v, vector<int>& ans) {
        stack<int> st;
        st.push(-1);

        for (int i = v.size() - 1; i >= 0; i--) {

            int ele = v[i];
            while (st.top() != -1 && v[st.top()] > ele) {
                st.pop();
            }

            // smaller elemetn found ->store its index and push curr elements
            // index in stack
            ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
    };

    void prevSmallerElement(vector<int>& v, vector<int>& ans) {
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < v.size(); i++) {

            int ele = v[i];
            while (st.top() != -1 && v[st.top()] >= ele) {
                st.pop();
            }

            // smaller elemetn found ->store its index and push curr elements
            // index in stack
            ans.push_back(st.top());
            st.push(i);
        }
    };

    int sumSubarrayMins(vector<int>& arr) {

        // instead to finding the subarrays and then min of every subarray
        // we we will find how many times an element contribute to the sum
        //  an elemnt can be min only if  it is in the subarrray and no element
        //  less than that is present in that subarrray
        // INTUITON: calculate prevSmaller and nexTSmaller of ith element
        //  exclude those indices and calcute the left and right elemebts of ith
        //  ele
        // calcuate total subarrays of ith element
        // calculate the number of times an element contribute

        // repeate for every element and accumulate the sum
        vector<int> prev;
        vector<int> next;

        nextSmallerElement(arr, next);
        prevSmallerElement(arr, prev);

        // mod
        const int MOD = 1e9 + 7;
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {

            // for ith element we take next ad prev smaller of ith
            int prevIdx = prev[i];

            int nextIdx = (next[i] == -1) ? next.size() : next[i]; // to handle -1 error

            int leftEles = i - prevIdx;

            int rightEles = nextIdx - i;

            long long total_appear_times = (1LL *leftEles * rightEles) % MOD;

            long long currSumOfAppNum = (total_appear_times * arr[i]) % MOD;

            sum = (sum + currSumOfAppNum) % MOD;
        }
        return sum;
    }
};