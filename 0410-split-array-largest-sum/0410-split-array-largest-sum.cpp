class Solution {
public:
    typedef long long ll;

    int countSubarrays(vector<int>& a, ll mxSum){
        int n = a.size();

        ll currSum = 0;
        int numberOfSubarrays = 1;

        for(int i = 0 ; i < n ; i++){
            currSum += a[i];

            if(currSum > mxSum){
                numberOfSubarrays++;
                currSum = a[i];
            }
        }

        return numberOfSubarrays;
    }

    int splitArray(vector<int>& a, int k) {

        ll low = *max_element(a.begin(),a.end());
        ll high = accumulate(a.begin(),a.end(),0LL);

        ll ans = high;

        while(low <= high){

            ll mid = low + (high-low)/2;

            if(countSubarrays(a,mid) <= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};