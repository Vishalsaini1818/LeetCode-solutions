class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minH;
    priority_queue<int> maxH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxH.size() == 0 || maxH.top() >= num)
            maxH.push(num);
        else
            minH.push(num);

        if(maxH.size() > minH.size() + 1){
            minH.push(maxH.top());
            maxH.pop();
        }
        else if(maxH.size() < minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()){
            return (double)((maxH.top() + minH.top()) / 2.0);
        }
        else
            return maxH.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */