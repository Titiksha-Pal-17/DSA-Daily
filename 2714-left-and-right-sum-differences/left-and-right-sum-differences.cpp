class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n =nums.size();
        int rightSum =0;
        int leftSum=0;

        //calculating the rightsum
        for(int num:nums){
            rightSum+=num;
        } 
         
        //iterate through the array
        for(int i=0;i<n ;i++){
            int val=nums[i];

            //update rightSum
            rightSum -=val;

            //Calculate the entire sum
            nums[i] = abs(leftSum-rightSum);

            //update leftsum
            leftSum+= val;
        }

        return nums;


        
    }
};