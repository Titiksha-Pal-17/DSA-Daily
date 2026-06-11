class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //creating fre arrays for both the strings 
        vector<int>v1(128,-1);
        vector<int>v2(128,-1);

        //checking if strings are of same length
        if(s.length()!=t.length()){
            return false;
        }

        for(int i=0;i<s.length();i++){

            if( v1[s[i]] != v2[t[i]] ){//checking if value at idx i in the both arrays is same 
                return false;
            }
            v1[s[i]] = v2[t[i]] =i;//storing string position in vectors 
        }
          return true;
    }
};