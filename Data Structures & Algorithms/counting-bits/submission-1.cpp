class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i<=n ; i++){
            int count = 0;
            int temp = i;
            while(!(temp==0 ||  temp==1)){
                if(temp%2!=0){
                    count ++;
                }
                temp/=2;
            }
            if (temp == 1) count ++;
            res.push_back(count);
        }
        return res;
    }
};
