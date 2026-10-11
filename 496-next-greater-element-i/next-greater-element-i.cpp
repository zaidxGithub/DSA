class Solution {
public:
    void nextGreaterE(vector<int>& arr, vector<int>& ans) {
        stack<int> st;
        st.push(-1);

        for (int i = arr.size()-1; i >= 0; i--) {
            // top is smaller than element
            int ele = arr[i];
            if (st.top() <= ele) {

                while (st.top()!=-1 && st.top() <=ele ) {
                    st.pop();
                }
                ans.push_back(st.top());
                st.push(ele);
            } else {
                // top is grater than element
                ans.push_back(st.top());
                st.push(ele);
            }
        }

        reverse(ans.begin(),ans.end());
    }

    int getIndex(int crrE,vector<int>&v){
        for(int i=0;i<v.size();i++){
            if(v[i]==crrE){
                return i;
            }
        }
        return -1;
    };
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>vans;
        nextGreaterE(nums2,ans);

      for(int i=0;i<nums1.size();i++){
        int crrE=nums1[i];

          int index=getIndex(crrE,nums2);

          vans.push_back(ans[index]);


      }
     return vans;
    }
};