class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         vector<pair<int,int>>posAndSpeed;

        // combine the pos and speed evctors to sort
        for(int i=0;i<position.size();i++){
            posAndSpeed.push_back({position[i],speed[i]});
        }

        //2->sort the posAndSpeed in ASC

        sort(posAndSpeed.begin(),posAndSpeed.end());

        //create a times array 

        vector<float>timeToReach;

        // calauate and insertt time for each card in times array

        for( int i=0;i<posAndSpeed.size();i++){

            //calcuate the absolute time for each car 

            int pos=posAndSpeed[i].first;
            int speed=posAndSpeed[i].second;

            float time=(target-pos)/((float)speed);
            timeToReach.push_back(time);
        }
     

     for(auto i:timeToReach)cout<<i << " ";
        // craete a stack and maintani the car fleet in stack
            stack<float>st;

            // agr curr car ka time zyada h ya barabar h to hi fleet bangi wrna nahi banegi :

            for(int i=0;i<timeToReach.size();i++){
                float currTime=timeToReach[i];

                while(!st.empty() && currTime>=st.top()){
                    st.pop();
                    //yahi curr car dhere chlri h peheli car se jo stack me h

                }

                st.push(currTime);
            }

            return st.size();
    }
};