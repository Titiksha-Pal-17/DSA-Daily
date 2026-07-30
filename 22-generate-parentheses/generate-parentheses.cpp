class Solution {
public:

   void backtrack(string current , int open , int close , vector<string>& result){
    
    //base case 
    if(open==0 && close==0){
       result.push_back(current);
       return ;
    }

    //recursive calls

    if(open>0){
        backtrack(current+"(" , open-1 , close, result);
    }

    if(close>open){
        backtrack(current+")" , open , close-1, result);

    }
   }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack("" , n , n , result);
        return result;
    }
};