class Solution {
public:

// APPROACH1---->  using the Set data Structure to prevent the duplicate permutations.
    void permuteUniqueAll(vector<int>& nums, int index, vector<int>& perm,
                          set<vector<int>>& st) {
        // base case

        if (index >= nums.size())
            return;

        // 1 case i will solve

        for (int j = index; j < nums.size(); j++) {

            // swap
            swap(nums[index], nums[j]);

            // insert the permuatoin in the set
            st.insert(nums);

            permuteUniqueAll(nums, index + 1, perm, st);

            // backtracck

            swap(nums[index], nums[j]);
        }

        // recursion call
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // brute force ->>> genrate all the permutatins and insert in the set

        vector<int> perm;
        int index = 0;
        set<vector<int>> st;

        // fin call

        permuteUniqueAll(nums, index, perm, st);

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};