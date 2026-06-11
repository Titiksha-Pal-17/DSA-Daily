class Solution {
public:
    bool isAnagram(string s, string t) {
        //creating the frequency array 
        vector<int>freq(26,0);

        //if length of the arrays are different then ofc not anagram 
        if(s.length()!= t.length()){
            return false;
        
        }
        //storing freq of both the array simulatenously 
        for(int i =0;i< s.length() ;i++ ){
            
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;

        }

        for(int i =0; i<26;i++){
            if(freq[i]!=0){               //if find no 0 in the freq 
                return false;             // that means not anagram 
            }
        }

        return true;


    }
};