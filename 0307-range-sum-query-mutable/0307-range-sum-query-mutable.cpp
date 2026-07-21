class NumArray {
public:
    vector<int>segmentTree;
    int n;
    
    NumArray(vector<int>& nums) {
         n = nums.size();
         segmentTree.resize(4*n,0);
         buildSegmentTree(nums,0,n - 1,0);
    }

    void buildSegmentTree(vector<int>& nums,int l,int r,int index){
        if(l == r){
         segmentTree[index] = nums[l];
          return ;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(nums,l,mid,2*index + 1);
        buildSegmentTree(nums,mid + 1,r,2*index + 2);
        
        segmentTree[index] = segmentTree[2*index + 1] + segmentTree[2 * index + 2];
    }

    void updateSegmentTree(int l,int r,int givenIndex,int val,int index){
        if(l == r)
        {
            segmentTree[index] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(givenIndex <= mid){
            updateSegmentTree(l,mid,givenIndex,val,2 * index + 1);
        } else {
            updateSegmentTree(mid + 1,r,givenIndex,val,2 * index + 2);
        }

        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
    }

    void update(int index, int val) {
         updateSegmentTree(0,n-1,index,val,0);
    }
    
    int query(int left,int right,int l,int r,int index){
        if(r < left || l > right)
        return 0;
        
        if(l >= left && r <= right)
        return segmentTree[index];

        int mid = l + (r - l) / 2;
        return query(left,right,l,mid,2*index + 1) + query(left,right,mid + 1,r,2*index + 2);
    }
    int sumRange(int left, int right) {
        return query(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */