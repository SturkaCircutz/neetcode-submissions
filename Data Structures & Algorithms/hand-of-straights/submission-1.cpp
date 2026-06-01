class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mp;
        for(auto h:hand){
            mp[h]++;
        }
        sort(hand.begin(), hand.end());
        for(auto h:hand){
            if(mp[h]>0){
                for(int i = h; i<h+groupSize; i++){
                    if(mp[i]==0){
                        return false;
                    }
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
