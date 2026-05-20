class Solution {
public:
    bool isHappy(int n) {
        vector <int> store;
        int ret = 0;  // init the result for each number
        while(ret != 1){  // if ret is not 1, keep on going
        ret = 0;  // init the result for each number
        while(n!=0){
            int digit = n % 10;
            n /= 10;
            ret += digit * digit;
        }
        if(find(store.begin(), store.end(), ret)!=store.end()){ // if it has the same result with the one appeared before
            return false;
        }
        store.push_back(ret);  // put the result to the vector
        n = ret;
        }
        return true;
    }
};
