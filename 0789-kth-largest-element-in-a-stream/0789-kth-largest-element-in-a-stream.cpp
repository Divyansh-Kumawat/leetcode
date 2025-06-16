class KthLargest {
public:        
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int it:nums){
            minHeap.push(it);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        if(minHeap.size()<k){
            minHeap.push(val);
            return minHeap.top();
        }
        minHeap.push(val);
        minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */