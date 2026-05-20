class CountSquares {
private:
    unordered_map<long, int> ptCount;
    vector<vector<int>> pts;

public:
    CountSquares() {
        
    }
    long long trans(int x, int y){
        return (static_cast<long long>(x)<< 32 | static_cast<long long>(y));
    }
    void add(vector<int> point) {
        long long ptt = trans(point[0], point[1]);
        ptCount[ptt]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int count1 = 0;
        for(auto ps : pts){
            int px = ps[0], py = ps[1];
            if(px == x|| py == y || abs(px - x) != abs(py-y) ) continue;
            count1 += ptCount[trans(px, y)] * ptCount[trans(x, py)];
        }
        return count1;
    }
};
