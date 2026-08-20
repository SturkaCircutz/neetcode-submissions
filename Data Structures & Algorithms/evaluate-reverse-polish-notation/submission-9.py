class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        res = 0

        for i in range(len(tokens)):
            if tokens[i] == '+':
                tmp = stack.pop()
                tmp1 = stack.pop()
                res = tmp + tmp1
                stack.append(res)
            elif tokens[i] == '-':
                tmp = stack.pop()
                tmp1 = stack.pop()
                res = tmp1 - tmp
                stack.append(res)
            elif tokens[i] == '*':
                tmp = stack.pop()
                tmp1 = stack.pop()
                res = tmp * tmp1
                stack.append(res)
            elif tokens[i] == '/':
                tmp = stack.pop()
                tmp1 = stack.pop()
                res = tmp1 / tmp
                stack.append(int(res))
            else:
                stack.append(int(tokens[i]))
        return int(stack[-1])