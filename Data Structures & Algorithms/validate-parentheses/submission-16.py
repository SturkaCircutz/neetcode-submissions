class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mp = {
            ')' : '(',
            '}' : '{',
            ']' : '['
        }
        for r in range(len(s)):
            if s[r] in mp:
                if stack and mp[s[r]] == stack[-1]:
                    stack.pop()
                else:
                    return False

            
            else:
                stack.append(s[r])
        return len(stack) == 0