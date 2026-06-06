class MedianFinder {
public:
    vector<double> li;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        li.push_back(static_cast<double>(num));
        sort(li.begin(), li.end());
    }
    
    double findMedian() {
        if(li.empty()) return -1;
        if(li.size()%2==0){
            return (li[li.size()/2]+li[li.size()/2-1])/2.0;
        }
        else{
            return li[li.size()/2];
        }
    }
};
