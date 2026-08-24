class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda i : i[0])
        output = [intervals[0]]
        count = 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < output[-1][1]:
                count +=1
                output[-1][1] = min(output[-1][1], intervals[i][1])
            
            else:
                output.append(intervals[i])
        return count