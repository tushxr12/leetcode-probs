class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);

        if(n == 2){
            return {1,-1};
        }
        
        for(int i = 0;i < n - 1;i++){
            ans[i] = i;
        }
        int sum = (n-1)*(n-2)/2;
        ans[n - 1] = -(sum);
        return ans;
    }
};
