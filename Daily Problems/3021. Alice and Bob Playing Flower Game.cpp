class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        int e1=0,o1=0,e2=0,o2=0;

        for(int i = 1;i <= n;i++){
            if(i%2) o1++;
            else e1++;
        }

        for(int i = 1;i <= m;i++){
            if(i%2) o2++;
            else e2++;
        }

        // Doing below thing so that integer shouldn't overflow
        long long pair1 = e1;
        pair1 *= o2;
        long long pair2 = e2;
        pair2*=o1;
        ans = pair1;
        ans += pair2;
        return ans;
    }
};
