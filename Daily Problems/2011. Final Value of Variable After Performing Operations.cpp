class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for(auto i : operations){
            auto currOperation = i;
            if(currOperation.find('+') != string::npos){
                x += 1;
            }
            else
            {
                x -= 1;
            }
        }
        return x;
    }
};
