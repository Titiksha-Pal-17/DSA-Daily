class Solution {
public:
    int countMagicalPairs(string s) {
         int n = s.length();
        int totalTriplets = 0;

        for (int j = 0; j < n - 1; j++) {
        
            vector<int> leftDistinctFreq(27, 0);
            
           
            int leftMask = 0;
            for (int i = j; i >= 0; i--) {
                leftMask |= (1 << (s[i] - 'a')); // Add character to mask
                int distinctCount = __builtin_popcount(leftMask);
                leftDistinctFreq[distinctCount]++;
            }

            int rightMask = 0;
            for (int k = j + 1; k < n; k++) {
                rightMask |= (1 << (s[k] - 'a')); // Add character to mask
                int distinctCount = __builtin_popcount(rightMask);
                
               
                totalTriplets += leftDistinctFreq[distinctCount];
            }
        }

        return totalTriplets;
    }
};