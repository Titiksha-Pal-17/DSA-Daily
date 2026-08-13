class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin() , coins.end());
        int n = coins.size();

        long long reach =0;
        for(int i=0 ; i<n ;i++){
            if(coins[i]> reach +1)
            break ;

            reach += coins[i] ;
        }
        return reach+1 ;
    }
};