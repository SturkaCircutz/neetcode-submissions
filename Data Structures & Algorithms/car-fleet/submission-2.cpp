class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ans; // create pairs of pos and speed, res order
        for(int i = 0; i < position.size(); ++i){
            ans.push_back({position[i], speed[i]});
        }
        sort(ans.rbegin(), ans.rend()); // sort items based on position(rever)
        vector<double> time; // the time could also be double
        for(int i = 0; i < ans.size(); ++i){
            time.push_back((double)(target-ans[i].first)/ans[i].second); // store the time to reach the goal for each car
            if(time.size()>=2 && time.back()<=time[time.size()-2]){
                time.pop_back();
            }
        }
        return time.size();
    }
};
