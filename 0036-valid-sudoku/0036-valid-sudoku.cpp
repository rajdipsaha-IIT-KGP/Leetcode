class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set<string>st;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == '.')
                continue;
                string s1 = string(1,board[i][j]) + "_ROW_" + to_string(i);
                string s2 = string(1,board[i][j]) + "_COL_" + to_string(j);
                string s3 = string(1,board[i][j]) + "_ROW_" + to_string(i/3) + "_COL_" + to_string(j/3);

                if(st.find(s1) != st.end()|| st.find(s2) != st.end()|| st.find(s3) != st.end())
                return false;

                st.insert(s1);
                st.insert(s2);
                st.insert(s3);
            }
        }
        return true;
    }
};