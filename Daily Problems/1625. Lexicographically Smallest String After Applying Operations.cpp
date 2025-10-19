class Solution {
private:
    void rotate(string &s, int b)
    {
        reverse(begin(s) , end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string smallestString = s;
        queue<string> que;
        unordered_set<string> visited;

        que.push(s);
        visited.insert(s);

        while(!que.empty())
        {
            string curr = que.front();
            que.pop();

            if(curr < smallestString)
                smallestString = curr;
            
            string temp = curr;
            for(int i = 1;i < temp.size();i+=2){
                temp[i] = ((temp[i]- '0' + a)%10) + '0';
            }

            if(!visited.count(temp)){
                visited.insert(temp);
                que.push(temp);
            }

            rotate(curr, b);
            if(!visited.count(curr)){
                visited.insert(curr);
                que.push(curr);
            }
        }
        return smallestString;
    }
};
