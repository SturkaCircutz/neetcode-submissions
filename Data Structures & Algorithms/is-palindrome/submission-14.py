class Solution:
    def isPalindrome(self, s: str) -> bool:
        count = ''
        for i in s:
            if i.isalnum():
                count += i.lower()
        l, r =0, len(count) - 1
        print(count)
        while l < r:
            if count[l] != count[r]:
                return False
            l+=1
            r-=1
        return True
