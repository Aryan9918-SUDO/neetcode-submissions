class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {

        // CHECK ROWS
        for(int i = 0; i < 9; i++) {

            unordered_set<char> st;

            for(int j = 0; j < 9; j++) {

                char ch = board[i][j];

                if(ch == '.') {
                    continue;
                }

                if(st.find(ch) != st.end()) {
                    return false;
                }

                st.insert(ch);
            }
        }

        // CHECK COLUMNS
        for(int j = 0; j < 9; j++) {

            unordered_set<char> st;

            for(int i = 0; i < 9; i++) {

                char ch = board[i][j];

                if(ch == '.') {
                    continue;
                }

                if(st.find(ch) != st.end()) {
                    return false;
                }

                st.insert(ch);
            }
        }

        // CHECK 3x3 BOXES
        for(int row = 0; row < 9; row += 3) {

            for(int col = 0; col < 9; col += 3) {

                unordered_set<char> st;

                for(int i = row; i < row + 3; i++) {

                    for(int j = col; j < col + 3; j++) {

                        char ch = board[i][j];

                        if(ch == '.') {
                            continue;
                        }

                        if(st.find(ch) != st.end()) {
                            return false;
                        }

                        st.insert(ch);
                    }
                }
            }
        }

        return true;
    }
};