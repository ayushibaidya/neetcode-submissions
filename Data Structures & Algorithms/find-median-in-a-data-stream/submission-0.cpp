class MedianFinder {

private: 
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        

    }
    
    void addNum(int num) {
        maxHeap.push(num); 
        minHeap.push(maxHeap.top()); 
        maxHeap.pop(); 

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top()); 
            minHeap.pop(); 
        }
    }
    
    double findMedian() {
        //if list is empty return NULL
        if(maxHeap.empty() && minHeap.empty()){
            return 0.0; 
        }
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top(); 
        } 
        return ((double)maxHeap.top() + (double)minHeap.top())/2.0; 
    }
};
