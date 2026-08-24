class Solution {
public:
    void countArranmentHelper(int& n, vector<int>& v, int& ans, int currNum) {

        // base case'

        // all placed means beatuful arrangement -> ans++;

        if (currNum == n + 1) {
            ans++;
            return;
        }
        // 1 case mera -->
        // I have to place the first number on a suitbale index

        for (int i = 1; i <= n; i++) {

            if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0)) {
                // possible to place the curent number
                v[i] = currNum;
                countArranmentHelper(n, v, ans, currNum + 1);

                // backtrack
                v[i] = 0;
            }
        }

        // other numbers ->> recursion will place
    }
    int countArrangement(int n) {

        vector<int> v(n + 1); // 1 index based vector h so n+1 size

        int ans = 0;
        int crrNum = 1;

        countArranmentHelper(n, v, ans, crrNum);
        return ans;
    }
};