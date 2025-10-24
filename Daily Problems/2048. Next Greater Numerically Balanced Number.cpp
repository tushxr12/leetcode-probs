class Solution {
private:
    bool isBalanced(int num)
    {
        vector<int> freq(10);
        while(num > 0){
            int ld = num%10;
            freq[ld]++;
            num /= 10;
        }
        for(int d = 0;d < 10;d++){
            if(freq[d] != 0 && freq[d] != d)
                return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        for(int num = n + 1;num <= 1224444;num++){
            if(isBalanced(num))
                return num;
        }
        return -1;
    }
};
