class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        
        def reverse(l, r):
            
            if l < r:
                
                s[l], s[r] = s[r], s[l]
                
                reverse(l + 1, r - 1)
        
        
        reverse(0, len(s) - 1)