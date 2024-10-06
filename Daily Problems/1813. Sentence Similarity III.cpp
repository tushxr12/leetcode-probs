class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int n1 = (int)s1.size();
        int n2 = (int)s2.size();
        if(n1 == n2)
            return (s1 == s2);
        deque<string> a,b;
        string temp = "";
        s1.push_back(' ');
        s2.push_back(' ');
        for(int i = 0;i <= n1;i++)
        {
            if(s1[i] == ' ')
            {
                a.push_back(temp);
                temp = "";
            }
            else
            {
                temp.push_back(s1[i]);
            }
        }

        for(int i = 0;i <= n2;i++)
        {
            if(s2[i] == ' ')
            {
                b.push_back(temp);
                temp = "";
            }
            else
            {
                temp.push_back(s2[i]);
            }
        }
        while(a.size() && b.size() && a.front() == b.front())
        {
            a.pop_front();
            b.pop_front();
        }

        while(a.size() && b.size() && a.back() == b.back())
        {
            a.pop_back();
            b.pop_back();
        }

        return (a.size() == 0 || b.size() == 0);
    }
};
