class Solution {
public:

    bool subsetSum(int index , int target ,vector<int>& nums , vector<vector<int>>& dp){
        if(index==nums.size()) return false;
        if(target == 0) return true;
        if(dp[index][target] != -1)  return dp[index][target];

         
        bool notTake=subsetSum(index+1, target , nums , dp);

        bool take=false;
        if(nums[index]<= target)
            take = subsetSum(index+1, target- nums[index], nums , dp);

          return dp[index][target]=take||notTake ;


    }
    bool canPartition(vector<int>& nums) { 
        int sum =0;
        for(int i=0 ;i< nums.size() ;i++){
              sum=sum+nums[i];
        }

        if(sum%2!=0) return false;
         int target =sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        
        return subsetSum( 0 , sum/2 , nums , dp);
        
    }
};