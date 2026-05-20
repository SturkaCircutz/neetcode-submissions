class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long ans=0;
        for(int i = 31; i>=0; --i){
            if((n&1)==1){
                ans += pow(2, i);
            }
            n = n>>1;
        }
        return ans;
    }
};
