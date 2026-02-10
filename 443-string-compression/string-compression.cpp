class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size(); // length
        int idx=0;
        
        for(int i=0; i<n ;i++){ // time complexity O(n)
            char ch=chars[i]; //character array
            int count=0;
            while( i<n && chars[i]==ch){
                count++;
                i++;

            }
            if(count==1) chars[idx++]=ch;
            else{
                chars[idx++]= ch;
                string str= to_string(count);
                for(char dig : str){
                    chars[idx++]= dig;
                }
            }
            i--; 
        }
        chars.resize(idx);
        return idx;
    }
};