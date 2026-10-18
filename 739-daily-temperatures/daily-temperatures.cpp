class Solution {
public:

    vector<int>nextGreater(vector<int>&temp){
        stack<int>st;
        st.push(-1);
        vector<int>tempDayLocation;

        for(int i=temp.size()-1;i>=0;i--){
            int currTemp=temp[i];
            while(!st.empty() && st.top()!=-1 && temp[st.top()]<=currTemp){
                st.pop();
            }

            //a greater or -1 temp day found 
            //store
            tempDayLocation.push_back(st.top());
            st.push(i);

        }

        reverse(tempDayLocation.begin(),tempDayLocation.end());
        return tempDayLocation;
        
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int>nextT=nextGreater(temperatures);
        vector<int>ans;
        // for(auto i:nextT)cout<<i<<" ";

        for(int i=0;i<nextT.size();i++){

            //for currTemp find the index of the next Greater temp day in nextT

            int nextWarmDayIndex=nextT[i]==-1 ? i:nextT[i];


            int daysToWait= nextWarmDayIndex-i; 
            ans.push_back(daysToWait);
        }

        return ans;
        
    }
};