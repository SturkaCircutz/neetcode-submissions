class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for i in s:
            curr = ""
            if i == "]":
                while stack[-1] != '[':
                    curr = stack.pop() + curr
                stack.pop()
                num = ''
                while stack and stack[-1].isdigit():
                    num = stack.pop() + num
                stack.append(int(num) * curr)
            else:
                stack.append(i)
        return ''.join(stack)