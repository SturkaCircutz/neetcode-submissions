class Solution:
    def isPalindrome(self, s: str) -> bool:
        clear = ''
        for c in s:
            if c.isalnum():
                clear += c.lower()
        l, r = 0, len(clear)-1
        while l < r:
            if clear[l] != clear[r]:
                return False
            l+=1
            r-=1
        return True
