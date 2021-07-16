class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    MedianFinder() {  
        while(maxHeap.size()){
            maxHeap.pop();
        }
        while(minHeap.size()){
            minHeap.pop();
        }
    }
    
    void addNum(int num) {
        
        if(minHeap.size() > 0 && num > minHeap.top()){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
        
        if(minHeap.size() - maxHeap.size() == 2){
            int ele = minHeap.top();
            minHeap.pop();
            maxHeap.push(ele);
        }
        else if(maxHeap.size() - minHeap.size() == 2){
            int ele = maxHeap.top();
            maxHeap.pop();
            minHeap.push(ele);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }
        else if(minHeap.size() > maxHeap.size()){
            return minHeap.top();
        }
        else if(minHeap.size() == maxHeap.size()){
            return (double)(minHeap.top() + maxHeap.top())/2;
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
