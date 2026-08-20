class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        time = []
        dic = {position[i]: speed[i] for i in range(len(position))}
        position.sort()
        for i in range(len(position)-1, -1, -1):
            time.append((target-position[i]) / dic[position[i]])
        stack = []
        for j in range(len(time)-1, -1, -1):
            while stack and stack[-1] <= time[j]:
                stack.pop()
            stack.append(time[j])
        return len(stack)
