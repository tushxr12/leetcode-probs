class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                for(int k = j+1;k <= n;k++){
                    if(i*i + j*j == k*k){
                        ans+=2;
                    }
                }
            }
        }
        return ans;
    }
};

// Better
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                int sum = i*i + j*j;
                int x = sqrt(sum);

                if(x*x == sum && x <= n){
                    ans += 2;
                }
            }
        }
        return ans;
    }
};
