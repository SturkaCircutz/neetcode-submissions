class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n<= 0){
            x= 1/x;
            n=-n;
        }
        double fast= myPow(x, n/2);
        if(n%2==0){
            return fast*fast;
        }
        else{
            return fast * fast * x;
        }
    }
};
