class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        // frequency of s1
        for(char c : s1) {
            freq1[c - 'a']++;
        }

        int k = s1.length();

        // first window
        for(int i = 0; i < k; i++) {
            freq2[s2[i] - 'a']++;
        }

        if(isFreqSame(freq1, freq2)) return true;

        // sliding window
        for(int i = k; i < s2.length(); i++) {
            // add new character
            freq2[s2[i] - 'a']++;

            // remove old character
            freq2[s2[i - k] - 'a']--;

            if(isFreqSame(freq1, freq2)) return true;
        }

        return false;
    }
};
