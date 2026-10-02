class Solution {
public:
    bool isValid(string &s)
    {
        cout<<"Current string : "<<s<<"\n";
        stack<char> st;
        for(auto i : s){
            if(i == '('){
                st.push(i);
            }
            else
            {
                if(st.empty())
                    return false;
                st.pop();
            }
        }
        cout<<"Stack size : "<<st.size()<<"\n";
        return st.empty();
    }

    void solve(string curr, int n, vector<string> &ans)
    {
        if(curr.size() == 2*n){
            cout<<"Checking Valid\n";
            if(isValid(curr))
            {
                cout<<"This is valid!\n";
                ans.push_back(curr);
            }
            cout<<"Not valid\n";
            return;
        }

        curr.push_back('(');
        solve(curr,n,ans);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n,ans);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        solve(curr, n,ans);
        return ans;
    }
};
