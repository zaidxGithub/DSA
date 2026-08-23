class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // map implementation

        map<int, int> mp;
        vector<int> arr;

        /// 1-> traverse the array from 0-<size
        // 2-> calcumate  the remaiaingValue =target-arr[i];
        // 3-> lookup in map if remaingValue is there

        //    yes-> return the value of that key
        // no-> i++

        // return no
        // we will store the element of arrray as keys , in index  of element as
        // values

        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (mp.find(num) != mp.end()) {
                arr.push_back(mp[num]);
                arr.push_back(i);
            } else {
                mp[nums[i]] = i;
            }
        }
        return arr;
    }
};