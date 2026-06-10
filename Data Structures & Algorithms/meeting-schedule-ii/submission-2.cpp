/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        priority_queue<int, vector<int>, greater<>> minheap;
        sort(intervals.begin(), intervals.end(), [](Interval&a, Interval&b ){
            return a.start < b.start;
        });
        for(auto i:intervals){
            if(!minheap.empty() && i.start >= minheap.top()){
                minheap.pop();
            }
            minheap.push(i.end);
            
        }
        return minheap.size();
    }
};
