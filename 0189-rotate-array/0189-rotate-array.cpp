class Solution {
public:
void reverse(vector<int>& nums,int start,int end)
{
    int i,j;
    i=start;
    j=end;
    while(i<j)
    {
        nums[i]=nums[i]^nums[j];
        nums[j]=nums[i]^nums[j];
        nums[i]=nums[i]^nums[j];
        i++;
        j--;
    }
}
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size())
        {
            k=k%nums.size();
        }
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};