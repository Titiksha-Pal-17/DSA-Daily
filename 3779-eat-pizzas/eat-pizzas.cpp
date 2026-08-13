class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        
        int n = pizzas.size() ;
        int d= n/4 ;

        sort(pizzas.rbegin() , pizzas.rend());

        int odd =(d+1)/2 ;
        int even = d-odd ;

        long long ans =0;
        int  i = 0;

        //Odd days : take the largest
        for(int j =0 ;j<odd ;j++){
            ans+= pizzas[i];
            i++;
        }

        //Even days :skip one and take the second largest 
        for(int j =0 ;j<even ;j++){
            i++ ; //skip the largest 
            ans+= pizzas[i];
            i++ ;
        }
        return ans ;
    }
};