class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> nextSmaller(vector<int>& nums) {
        // we will store the indices in the ans array and return
        vector<int> ans;

        stack<int> st;
        st.push(-1);

        for (int i = nums.size() - 1; i >= 0; i--) {
            long long currEle = nums[i];
            while (st.top() != -1 && nums[st.top()] >= currEle) {
                st.pop();
            }
            // reaching here means we got some smaller value Index in top

            ans.push_back(st.top());
            st.push(i);
        }

        // reverse

        reverse(ans.begin(), ans.end());
        return ans;
    };

    vector<int> prevSmaller(vector<int>& nums) {
        // we will store the indices in the ans array and return
        vector<int> ans;

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < nums.size(); i++) {
            long long currEle = nums[i];

            while (st.top() != -1 && nums[st.top()] > currEle) {
                st.pop();
            }
            // reaching here means we got some smaller value Index in top

            ans.push_back(st.top());
            st.push(i);
        }

        // reverse

        return ans;
    };

    long long sumOfMinimums(vector<int>& nums) {

        // calculate the nextSmallet
        vector<int> prevI = prevSmaller(nums);

        vector<int> nextI = nextSmaller(nums);
        long long minSum = 0;

       

        for (int i = 0; i < nums.size(); i++) {

            int nxt = nextI[i] == -1 ? nums.size() : nextI[i];
            int prev = prevI[i];
            int left = i - prev;
            int right = nxt - i;

            long long total = (left * right) %
                              MOD; // total times an elemebt appear  in subarray
            minSum = minSum + (nums[i] * total);
            // total minSum of that element;
        }
        return minSum;
        // calcuate the prevSmalleest
        // calcuate the number of times it appears in subarrays
        //  caculet the minSum
    }

    vector<int> nextGreater(vector<int>& nums) {
        // we will store the indices in the ans array and return
        vector<int> ans;

        stack<int> st;
        st.push(-1);

        for (int i = nums.size() - 1; i >= 0; i--) {
            long long currEle = nums[i];

            while (st.top() != -1 && nums[st.top()] <= currEle) {
                st.pop();
            }
            // reaching here means we got some smaller value Index in top

            ans.push_back(st.top());
            st.push(i);
        }

        // reverse

        reverse(ans.begin(), ans.end());
        return ans;
    };
    vector<int> prevGreater(vector<int>& nums) {
        // we will store the indices in the ans array and return
        vector<int> ans;

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < nums.size(); i++) {
            long long currEle = nums[i];

            while (st.top() != -1 && nums[st.top()] < currEle) {
                st.pop();
            }
            // reaching here means we got some smaller value Index in top

            ans.push_back(st.top());
            st.push(i);
        }

        // reverse

        // reverse(ans.begin(),ans.end());
        return ans;
    };

    long long sumOfMaximums(vector<int>& nums) {

        // calculate the nextSmallet
        // calcuate the prevSmalleest
        vector<int> prevI = prevGreater(nums);
        vector<int> nextI = nextGreater(nums);
        long long maxSum = 0;

        //  for (auto i : prevI)
        //     cout << i << " ";
        // cout << endl;

        // for (auto i : nextI)
        //     cout << i << " ";
        // cout << endl;

        for (int i = 0; i < nums.size(); i++) {

            int nxt = nextI[i] == -1 ? nums.size() : nextI[i];
            int prev = prevI[i];
            int left = i - prev;
            int right = nxt - i;

            long long total =
                (left * right); // total times an elemebt appear  in subarray
            maxSum = (maxSum + nums[i] * total);
            // total minSum of that element;
        }
        return maxSum;
        
        // calcuate the number of times it appears in subarrays
        //  caculet the minSum
    };

    long long subArrayRanges(vector<int>& nums) {

        // find the next Sum Of All Minimums

        long long minSums = sumOfMinimums(nums);
            long long maxSums = sumOfMaximums(nums);
        cout<<minSums<<endl;
        cout<<maxSums<<endl;
    
        return maxSums - minSums;

        // find the sum of all maximums

        // Ans=maximums-minimums
    }
};