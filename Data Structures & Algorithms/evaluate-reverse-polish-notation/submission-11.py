class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t == '+':
                item1, item2 = stack.pop(), stack.pop()
                res = int(item2) + int(item1)
                stack.append(res)
            elif t == '-':
                item1, item2 = stack.pop(), stack.pop()
                res = int(item2) - int(item1)
                stack.append(res)
            elif t == '*':
                item1, item2 = stack.pop(), stack.pop()
                res = int(item2) * int(item1)
                stack.append(res)
            elif t == '/':
                item1, item2 = stack.pop(), stack.pop()
                res = int(item2) / int(item1)
                stack.append(res)
            else:
                stack.append(int(t))
        return int(stack[0])