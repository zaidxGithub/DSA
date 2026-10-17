class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool alive = true;
           

                while (!st.empty() && st.top() > 0 && asteroid < 0) {

                    // 3 cases are there

                    if (st.top() < abs(asteroid)) {
                        st.pop();
                        continue;

                    } else if (st.top() == abs(asteroid)) {
                        st.pop();
                    }

                    alive = false;
                    break;
                }

                if (alive) {
                    st.push(asteroid);
                }

                //
            
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.insert(ans.begin(), st.top());
            st.pop();
        }
        return ans;
    }
};