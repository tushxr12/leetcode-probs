class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int n = boxes.size();
        for(int i = 0;i < n;i++)
        {
            int cnt = 0;
            for(int j = 0;j < n;j++)
            {
                if(boxes[j] == '1')
                {
                    cnt += abs(j - i);
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

//Better
class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        vector<int> ans(n), left(n), right(n);
        left[0] = 0;
        right[n - 1] = 0;
        int balls = s[0] - '0';
        for(int i = 1;i < n;i++)
        {
            left[i] = left[i - 1] + balls;
            balls+=(s[i] - '0');
        }
        balls = (s[n - 1] - '0');
        for(int i = n - 2;i >= 0;i--)
        {
            right[i] = right[i + 1] + balls;
            balls+=(s[i] - '0');
        }

        for(int i = 0;i < n;i++)
        {
            ans[i] = (left[i] + right[i]);
        }
        return ans;
    }
};
