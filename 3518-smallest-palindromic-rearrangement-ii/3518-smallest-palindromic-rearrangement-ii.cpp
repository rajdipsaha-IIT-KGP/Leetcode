class Solution {
public:
    typedef long long ll;
    ll nCr(int n,int r,int k){
        r = min(r,n-r);
        ll res = 1LL;

        for(int i = 1; i <= r ; i++){
            res = res * (n - r  + i) / i;
            if(res >= k)
            return k;
        }
        return res;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        char mid = '$';

        if(n % 2 != 0){
         mid = s[n / 2];
        }

        vector<int>h(26,0);

        for(int i = 0 ; i < n ; i++){
            h[s[i] - 'a']++;
        }

        for(int i = 0 ; i < 26 ; i++){
            h[i] = h[i] / 2;
        }
        
        string halfRes = "";
        int half = n / 2;
         
        for(int i = 0 ; i < n / 2 ; i++){
            bool found = false;
            for(int j = 0 ; j < 26 ; j++){
                if(h[j] > 0){
                    h[j] -= 1;
                    ll ways = 1; 
                    int letters = 0;
                   for(int c = 0 ; c < 26 ; c++){
                     letters += h[c];
                   }

                   for(int c = 0 ; c < 26 ;c++){
                    if(h[c] > 0){
                      ways *= nCr(letters,h[c],k);
                     letters -= h[c];
                    }
                     if(ways >= k)
                     break;
                   }

                   if(ways >= k){
                    found = true;
                     halfRes.push_back(j+'a');
                     break;
                     }
                     else {
                        k -= ways;
                        h[j] += 1;
                     }
                }
            }
             if(!found)
        return "";
        }
       
        string rev = halfRes;
        reverse(rev.begin(),rev.end());

        if(mid != '$')
        {
            return halfRes + mid + rev;
        }
        return halfRes  + rev;

    }
};