class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(), cols = strs[0].size();
        int deletions = 0;
        vector<bool> alreadySorted(rows, false);
        int row = 0, col = 0;

        for(col = 0; col < cols; col++){
            bool deleted = false;

            for(row = 0; row < rows-1;row++){
                if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]){
                    deletions++;
                    deleted = true;
                    break;
                }
            }

            if(deleted)
                continue;
            
            for(int i = 0;i < rows-1;i++){
                alreadySorted[i] = alreadySorted[i] | (strs[i][col] < strs[i + 1][col]);
            }
        }
        return deletions;
    }
};
