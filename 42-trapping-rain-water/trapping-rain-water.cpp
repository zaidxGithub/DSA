class Solution {
public:

void getLeftMax(vector<int>&arr){
    
    //start from the 1st index
    for(int i=1;i<arr.size();i++){
        arr[i]=max(arr[i],arr[i-1]);
    }
}
void getRightMax(vector<int>&arr){
    
    //start from the 1st index
    for(int i=arr.size()-2 ;i>0;i--){
        arr[i]=max(arr[i],arr[i+1]);
    }
}
    int trap(vector<int>& height) {


        //applying the intution of leftmax and rightmax building
        // water can only be store if current builde has somebuilding on left or right 
        //water will only be sttore till the height of min of left and right building 
        //for each building calculating the water and summing up to total trap water

        vector<int>leftMaxArray = height;
        vector<int>rightMaxArray = height;

        getLeftMax(leftMaxArray);
        getRightMax(rightMaxArray);


        int totalWater=0;

        for(int i=0;i<height.size();i++){


           int crrBuildingheight=height[i];

           //left max and right max
           int leftmax=leftMaxArray[i];
           int rightMax=rightMaxArray[i];

           if(crrBuildingheight<leftmax && crrBuildingheight <rightMax){
            //then only the water could be stored

            int water=min(leftmax,rightMax)-crrBuildingheight; // subtracting the roof of current building if there.

            totalWater+=water;
           }
        }

        return totalWater;
        
    }
};