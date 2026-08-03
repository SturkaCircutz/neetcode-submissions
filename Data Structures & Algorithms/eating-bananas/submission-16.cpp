class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = 0;
        while(l <= r){
            int m = (l+r)/2;
            int t = 0;
            for(auto p : piles){
                t += ceil(static_cast<double>(p)/m);
            }
            if(t <= h){
                res = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return res;
    }
};
