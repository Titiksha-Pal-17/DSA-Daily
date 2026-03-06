class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128,0);

        for(char c : t){
            freq[c]++;
        }

        int left = 0, right = 0;
        int start = 0;
        int minLen = INT_MAX;
        int count = t.size();

        while(right < s.size()){

            if(freq[s[right]] > 0){
                count--;
            }

            freq[s[right]]--;
            right++;

            while(count == 0){

                if(right - left < minLen){
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0){
                    count++;
                }

                left++;
            }
        }

        if(minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};