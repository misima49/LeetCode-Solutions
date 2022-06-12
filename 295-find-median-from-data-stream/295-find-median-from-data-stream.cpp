class MedianFinder {
    priority_queue<int> leftH;
    priority_queue<int, vector<int>, greater<int>> rightH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftH.push(num);
        rightH.push(leftH.top());
        leftH.pop();
        if(rightH.size() > leftH.size()) {
            leftH.push(rightH.top());
            rightH.pop();
        }
    }
    
    double findMedian() {
        if(leftH.size() > rightH.size()) {
            return leftH.top();
        } else {
            return (leftH.top()+rightH.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */