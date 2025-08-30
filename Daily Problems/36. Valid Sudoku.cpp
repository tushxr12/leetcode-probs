// Approach - 1
class Solution {
private:
    bool validBox(vector<vector<char>> &board, int sr, int er, int sc, int ec){
        unordered_set<char> st;

        for(int i = sr;i <= er;i++){
            for(int j = sc; j <= ec;j++){
                if(board[i][j] == '.')
                    continue;
                
                if(st.find(board[i][j]) != st.end())
                    return false;
                
                st.insert(board[i][j]);
            }
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate rows
        for(int row = 0; row < 9; row++){
            unordered_set<char> st;

            for(int col = 0; col < 9;col++){
                if(board[row][col] == '.')
                    continue;
                if(st.find(board[row][col]) != st.end())
                    return false;
                st.insert(board[row][col]);
            }
        }

        // Validate cols
        for(int col = 0; col < 9; col++){
            unordered_set<char> st;

            for(int row = 0; row < 9;row++){
                if(board[row][col] == '.')
                    continue;
                if(st.find(board[row][col]) != st.end())
                    return false;
                st.insert(board[row][col]);
            }
        }

        // Validate Sub-Boxes
        for(int sr = 0;sr < 9;sr+=3){
            int er = sr + 2;

            for(int sc = 0;sc < 9;sc+=3){
                int ec = sc + 2;

                if(!validBox(board, sr, er, sc, ec)){
                    return false;
                }
            }
        }

        return true;
    }
};


// Approach - 2 (Try kro ki string bna kr store kro for row, col and box in set and fr match krne ka try kro)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
                string col = string(1, board[i][j]) + "_COL_" + to_string(j);
                string box = string(1, board[i][j]) + "_BOX_" + to_string(i / 3) + "_" + to_string(j / 3);

                if (st.find(row) != st.end() ||
                    st.find(col) != st.end() ||
                    st.find(box) != st.end()) {
                    return false;
                }

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};
