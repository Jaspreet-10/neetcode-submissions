class MedianFinder {
public:
    priority_queue<int>minHeap;
    priority_queue<int, vector<int>, greater<int>>maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        while(minHeap.size() < maxHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size())
            return (double)((minHeap.top() + maxHeap.top())/2.0);
        return minHeap.top();
    }
};
