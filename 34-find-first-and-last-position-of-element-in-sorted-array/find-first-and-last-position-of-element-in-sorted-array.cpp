class Solution {
public:

    int firstPos(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int ans = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return ans;
    }

    int lastPos(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int ans = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPos(nums, target);
        int last = lastPos(nums, target);

        return {first, last};
    }
};
