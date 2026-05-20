class Solution {
public:
    priority_queue<int, vector<int>, less<int>> qu;
    int lastStoneWeight(vector<int>& stones) {
        for(auto stone: stones){
            qu.push(stone);
        }
        while(qu.size()>1){
            auto stone1 =qu.top();
            qu.pop();
            auto stone2 =qu.top();
            qu.pop();
            if(stone1== stone2){
                continue;
            }
            else{
                int maxi = max(stone1, stone2);
                int mini = min(stone1, stone2);
                int diff = maxi - mini;
                qu.push(diff);
            }
        }
        cout<<qu.size();
        if(qu.size()==0) return 0;
        return qu.top();
    }
};
