class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;

        // 1️⃣ Find first index from the right where nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;

        if (i >= 0) {                     // there is a valid pivot
            // 2️⃣ Find the rightmost element greater than nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) --j;

            // 3️⃣ Swap pivot with successor
            swap(nums[i], nums[j]);
        }

        // 4️⃣ Reverse the suffix (whether pivot existed or not)
        reverse(nums.begin() + i + 1, nums.end());
    }
};

