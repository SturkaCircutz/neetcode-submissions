class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>> sta;
        for(int i = 0; i < temperatures.size(); i++){
            while(!sta.empty() && sta.top().first < temperatures[i]){
                res[sta.top().second] = i - sta.top().second;
                sta.pop();
            }
            sta.push({temperatures[i], i});
        }

        return res;
    }
};
