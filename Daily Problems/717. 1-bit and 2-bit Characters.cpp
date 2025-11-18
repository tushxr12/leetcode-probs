// Approach - 1
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while(i < n - 1){
            i += (bits[i] == 1) ? 2 : 1;
        }

        return (i == n - 1);
    }
};

// Approach - 2
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        
        int cnt = 0;

        for(int i = n - 2; i >= 0 && bits[i] == 1;i--){
            cnt++;
        }

        return (cnt%2 == 0) ? true : false;
    }
};
