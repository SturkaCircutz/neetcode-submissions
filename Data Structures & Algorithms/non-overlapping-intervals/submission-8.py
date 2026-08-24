class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda i : -i[0])
        output = [intervals[0]]
        count = 0
        for i in range(1, len(intervals)):
            if intervals[i][1] > output[-1][0]:
                count +=1
                continue
            else:
                output.append(intervals[i])
        return count
