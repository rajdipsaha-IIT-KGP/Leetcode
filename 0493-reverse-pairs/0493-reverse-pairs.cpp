class Solution {
public:
   long long cnt = 0;
    void merge(vector<int>& nums,int low,int mid,int high){
        int l = low;
        int r = mid + 1;
         
        vector<int>temp;

        while(l <= mid && r <= high){
            if(nums[l] <= nums[r]){
                temp.push_back(nums[l++]);
            } else temp.push_back(nums[r++]);
        }
      while(l <= mid){
         temp.push_back(nums[l++]);
      }
      while(r <= high){
        temp.push_back(nums[r++]);
      }

      for(int i = low ; i <= high ; i++){
        nums[i] = temp[i - low];
      }
      return;
    }
    void countPairs(vector<int>& nums, int low, int mid, int high) {
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (right <= high &&
               (long long)nums[i] > 2LL * nums[right]) {
            right++;
        }
        cnt += right - (mid + 1);
    }
}
    void mergeSort(vector<int>& nums,int low,int high){
       if(low >= high){
          return ;
       }
       int mid = low + (high - low) / 2;

       mergeSort(nums,low,mid);
       mergeSort(nums,mid+1,high);
       countPairs(nums,low,mid,high);
       merge(nums,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return (int)cnt;
    }
};