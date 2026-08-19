class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000;
        int mid = 0b11000011;
        int right = 0b00001111;

        map<int,int>mp;

        for(int i = 0 ; i < reservedSeats.size() ; i++){
           if(reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 9){
               mp[reservedSeats[i][0]] |= 1 << (reservedSeats[i][1] - 2);
           }
        }
        int cnt = 2*(n - mp.size());

        for(auto &[row,bitmask] : mp){
            if((bitmask|left) == left || (bitmask|right) == right || (bitmask|mid) == mid)
            cnt++;
        }
        return cnt;
    }
};