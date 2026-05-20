class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1, right = piles[piles.size()-1];
        int ans = 0;
        while(left <= right){
            int mid = (left + right)/2;
            int count = 0;
            for(auto item : piles){
                count += ceil(static_cast<double>(item)/mid);

            }
            cout<<count<<endl;
            if(count <= h){
                ans = mid;
                right = mid -1;

            }
            else{
                
                left = mid+1;
                cout<<left<<endl;

            }

        }
    return ans;
    }
};
