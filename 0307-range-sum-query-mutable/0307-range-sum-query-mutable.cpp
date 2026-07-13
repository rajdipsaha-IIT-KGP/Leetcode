class NumArray {
public:
   vector<int>segmentTree;
   int n;
    NumArray(vector<int>& nums) {
         n = nums.size();
        segmentTree.resize(4*n,0);
        buildSegmentTree(nums,segmentTree,0,n-1,0);
    }

    void buildSegmentTree(vector<int>& nums,vector<int>& segmentTree,int l,int r,int index){
        if( l == r ){
        segmentTree[index] = nums[l];
         return;
        }
        int mid = l + (r - l) / 2;

        buildSegmentTree(nums,segmentTree,l,mid,2 * index + 1);
        buildSegmentTree(nums,segmentTree,mid + 1,r,2 * index + 2);

        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2]; 
    }

    void updateSegmentTree(int index,int val,int i,int l,int r){

        if(l == r)
        {
            segmentTree[i] = val;
            return ;
        }
        int mid = l + (r - l ) / 2;
        if(index <= mid){
            updateSegmentTree(index,val,2 * i + 1, l,mid);
        }
        else {
            updateSegmentTree(index,val,2 * i + 2, mid + 1,r);
        }
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }
    
    void update(int index, int val) {
        updateSegmentTree(index,val,0,0,n-1);
    }

    int query(int index,int left,int right,int l,int r){
        if(l > right || r < left)
        return 0;
        if(l >= left && r <= right){
           return segmentTree[index];
        }
        int mid = l + (r - l) / 2;
        return query(2*index+1,left,right,l,mid) + query(2*index+2,left,right,mid+1,r);
    }
    
    int sumRange(int left, int right) {
        return query(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */ 