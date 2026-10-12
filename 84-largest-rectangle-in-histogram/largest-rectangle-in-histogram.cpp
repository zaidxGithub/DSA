class Solution {
public:
    void getPrevSmaller(vector<int>& heights, vector<int>& prevSmaller) {
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < heights.size(); i++) {

            // currentelement
            int element = heights[i];

            while (st.top() !=-1 && heights[st.top()] >= element) {
                st.pop();
            }
            // means smaller value if found

            // store the smaller vakues index in the preSmaller Ans ans push the
            // smaller value index in the st
            prevSmaller.push_back(st.top());
            st.push(i);
        }
    }
    void getNextSmaller(vector<int>& heights, vector<int>& nextSmaller) {
        stack<int> st;
        st.push(-1);

        for (int i = heights.size()-1; i >= 0; i--) {

            // currentelement
            int element = heights[i];

            while (st.top() !=-1 && heights[st.top()] >= element) {
                st.pop();
            }
            // means smaller value if found

            // store the smaller vakues index in the preSmaller Ans ans push the
            // smaller value index in the st
            nextSmaller.push_back(st.top());
            st.push(i);
        }

        reverse(nextSmaller.begin(),nextSmaller.end());
    }



    int largestRectangleArea(vector<int>& heights) {

        vector<int> nextSmaller;
        vector<int> prevSmaller;

        getNextSmaller(heights, nextSmaller);
        getPrevSmaller(heights, prevSmaller);

        // for(auto i:nextSmaller)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:prevSmaller)cout<<i<<" ";

        //NOTE: YE MAI BHUL JATA HU 

        //Next Smaller agr nahi milta h to -1 nhi hona chhye last me , wrna widht nahi nikl payega
        // last me next index hona cchye ..ex heights.size() // wo hona cchye jaha bhi -1 h

        //replace -1 from with size of vec at evey postion in nextSmaller vector

        for(int i=0;i<nextSmaller.size();i++){
            if(nextSmaller[i]==-1) nextSmaller[i]=nextSmaller.size();
        }
        

        //to calcuete the wdith we can do next-prev-1
        vector<int>areas;

        for(int i=0;i<heights.size();i++){

            int maxSpanningWidht=nextSmaller[i]-prevSmaller[i]-1;
            int height=heights[i];
            int area=maxSpanningWidht*height;
            areas.push_back(area);
        }

        int maxArea=*max_element(areas.begin(),areas.end());
        

        return maxArea;

    }
};