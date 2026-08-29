class Solution {
public:
    void dfs(string& num, int target, int start, long long current_val,
             long long last_operand, string exp, vector<string>& ans) {

                // TIME COMPLEXITY O(4powN)

        // base case-->>
        if (start == num.size()) {
            if (current_val == target) {
                ans.push_back(exp);
                return;
            }
        }

        // looping all the substrings from start

        for (int i = start; i < num.length(); i++) {

            //leading zero skip karne hai always
            if(i>start && num[start]=='0') return;

            string current_num = num.substr(start, i - start + 1);
            long long current_num_val = stoll(current_num);

            // if one the first number jsut startig the dfs

            if (start == 0) {
                dfs(num, target, i + 1, current_num_val, current_num_val,
                    current_num, ans);
            } else {
                dfs(num, target, i + 1, current_val + current_num_val,
                    current_num_val, exp + "+" + current_num, ans);
                dfs(num, target, i + 1, current_val - current_num_val,
                    -current_num_val, exp + "-" + current_num, ans);
                dfs(num, target, i + 1,
                    current_val - last_operand + last_operand * current_num_val,
                    last_operand * current_num_val, exp + "*" + current_num,
                    ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {

        vector<string> ans;
        int start = 0;
        string exp = "";

        dfs(num, target, 0, 0, 0, exp, ans);
        return ans;
    }
};