class Solution {
public:
    // APPROACH1---->  using the Set data Structure to prevent the duplicate
    // permutations.
    void permuteUniqueAll(vector<int>& nums, int j, vector<vector<int>>& ans) {
        // base case

        if (j == nums.size()) {
            ans.push_back(nums);
            return;
        }
        // unordered_map to keep track wether an element is used before or not
        unordered_map<int, bool> mpp;
        // 1 case i will solve

        for (int i = j; i < nums.size(); i++) {

            if (mpp.find(nums[i]) != mpp.end()) {
                // enetry found
                continue;
            }

            // if not then we will add in tmap
            mpp[nums[i]] = false;

            // swap
            swap(nums[j], nums[i]);

            // insert the permuatoin in the set

            permuteUniqueAll(nums, j + 1, ans);

            // backtracck

            swap(nums[j], nums[i]);
        }

        // recursion call
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int index = 0;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        // fin call

        permuteUniqueAll(nums, index, ans);

        return ans;
    }
};