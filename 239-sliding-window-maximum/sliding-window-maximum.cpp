class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> dq;

        for (int index = 0; index < k; index++) {
            // curre element ko store to krna hi hai har haaal me ,no valid call
            // to remove but before inserting the curr element in the dq remove
            // all the elements that are lesser than curr element in the left of
            // curr elemenet as curr is the largest among them

            while (!dq.empty() && nums[dq.back()] < nums[index]) {
                dq.pop_back();
            }
            // insert the current element index in the dq
            dq.push_back(index);
        }
        // answer push karna
        int element = nums[dq.front()];
        ans.push_back(element);

        // remainig window ke liye

        for (int index = k; index < nums.size(); index++) {
            // removal

            if (!dq.empty() && index - dq.front()>= k) {
                dq.pop_front();
            }

            // addition
            while (!dq.empty() && nums[dq.back()] < nums[index]) {
                dq.pop_back();
            }
            // insert the current element index in the dq
            dq.push_back(index);

            // answer
            int element = nums[dq.front()];
            ans.push_back(element);
        }
        return ans;
    }
};