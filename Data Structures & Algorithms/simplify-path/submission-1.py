class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        paths = path.split('/')
        for p in paths:
            if stack and p == '..':
                stack.pop()
            elif p != '' and p!='.' and p != "..":
                stack.append(p)
        return '/'+'/'.join(stack)