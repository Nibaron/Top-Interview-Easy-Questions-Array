class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<set<int>> row(9), col(9), box(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') 
                    continue;
                
                int ch = board[i][j] - '0';
                if (row[i].count(ch) || col[j].count(ch) || box[(i/3)*3+j/3].count(ch)) 
                    return false;
                
                row[i].insert(ch);
                col[j].insert(ch);
                box[(i/3)*3+j/3].insert(ch);
            }
        }
        
        return true;
    }
};