class Solution {
private:
    long long solve(int l, int r){
        long long L = 1; // R = 4*L - 1
        long long S = 1;
        long long steps = 0;

        while(L <= r){
            long long R = 4*L - 1;

            long long start = max(L, (long long)l);
            long long end = min(R, (long long)r);

            if(start <= end){
                steps += (end - start + 1)*S;
            }

            S += 1;
            L *= 4;
        }

        return steps;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto i : queries){
            int l = i[0];
            int r = i[1];

            long long steps = solve(l, r);

            ans += (steps + 1)/2;
        }
        return ans;
    }
};
