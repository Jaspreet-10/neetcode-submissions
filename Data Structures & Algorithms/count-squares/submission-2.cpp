class CountSquares {
public:
    map<pair<int, int>, int>m;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        m[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int px = point[0], py = point[1], count = 0;
        for(auto it : m){
            int x = it.first.first, y = it.first.second;
            if(abs(x - px) != abs(y - py) || x == px || y == py) continue;
            if(m[{px, y}]>0 and m[{x, py}]>0){
                count+=m[{px, y}]*m[{x, py}]*it.second;
            }
        }
        return count;
    }
};
