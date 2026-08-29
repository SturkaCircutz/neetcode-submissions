class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        time = []
        for i in range(len(speed)):
            time.append((position[i], (target-position[i])/speed[i]))
        time.sort(reverse = True)
        stack = []
        for t in range(0, len(time)):
            if stack and stack[-1] >= time[t][1]:
                continue  
            stack.append(time[t][1])
        return len(stack)