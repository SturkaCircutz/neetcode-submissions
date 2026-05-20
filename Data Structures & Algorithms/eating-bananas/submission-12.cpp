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
                cout<<mid<<endl;
                if (item > mid){
                    
                    int res = item / mid;
                    count += res ;
                    if(item%mid!=0){
                        count++;
                    }

                    continue;
                }
                count ++;

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
