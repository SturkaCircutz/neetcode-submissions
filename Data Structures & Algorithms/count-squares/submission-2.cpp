class CountSquares {
private:
    vector<vector<int>> pts;
    unordered_map<long, int> ptCount;

    long returnKey(int x, int y){
        return (static_cast<long>(x)<<32) | (static_cast<long>(y));
    }
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = returnKey(point[0], point[1]);
        ptCount[key]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res =0;
        for(auto pt : pts){
            int px = pt[0], py=pt[1];
            if(px==x || py==y || abs(px - x) != abs(py-y)) continue;
            res += ptCount[returnKey(x, py)] * ptCount[returnKey(px,y )];
        }
        return res;
    }
};
