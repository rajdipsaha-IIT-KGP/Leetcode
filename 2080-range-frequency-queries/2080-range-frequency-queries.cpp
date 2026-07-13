class RangeFreqQuery {
public:

    vector<int>nums;
    map<int,vector<int>>mp;

    RangeFreqQuery(vector<int>& arr) {
        nums = arr;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]].push_back(i);
        }

    }
    
    int query(int left, int right, int value) {
        auto &v = mp[value];
       auto  l = lower_bound(v.begin(),v.end(),left);
       auto r = upper_bound(v.begin(),v.end(),right);

       return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */