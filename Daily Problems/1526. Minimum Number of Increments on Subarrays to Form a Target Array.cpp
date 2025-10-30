class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        long long res = 0;
        int curr = 0, prev = 0;

        for(int i = 0;i < n;i++){
            curr = target[i];

            if(abs(curr) > abs(prev))
            {
                res += abs(curr - prev);
            }
            prev = curr;
        }
        return res;
    }
};
