class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int rev = 0;
        while (x > rev) {
            int r = x % 10;
            rev = rev * 10 + r;
            x = x / 10;
        }

        // For even-length: x == rev
        // For odd-length: x == rev / 10 (middle digit doesn't matter)
        return (x == rev || x == rev / 10);
    }
};