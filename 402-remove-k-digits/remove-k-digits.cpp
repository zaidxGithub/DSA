class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.length()) return "0";
        stack<char> st;

        for (int i = 0; i < num.length(); i++) {

            while (!st.empty() && k > 0 && (st.top() - '0' > num[i] - '0')) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        

        // check if no elements are remove from the stack then remove
        while (k > 0) {
            st.pop();
            k--;
        }
        // check if stack is empty
        if (st.empty())
            return "0";

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // check for the leading zerors

        while (ans.size() != 0 &&  ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty())
            return "0";

        cout << ans;

        // step1:
        return ans;
    }
};