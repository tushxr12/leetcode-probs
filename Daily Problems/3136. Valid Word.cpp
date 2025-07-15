class Solution {
private:
    bool isVowel(char c)
    {
        set<char> st = {'a', 'e' ,'i' ,'o' ,'u', 'A' , 'E', 'I', 'O', 'U'};
        return (st.find(c) != st.end());
    }

    bool isConsonant(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if(isVowel(c))
                return false;
            return true;
        }
        return false;
    }

public:
    bool isValid(string word) {
        int n = word.size();
        if(n < 3)
        {
            return false;
        }

        bool vf = false, cf = false;

        for(int i = 0;i < n;i++)
        {
            cout<<"Curr char : "<<word[i]<<endl;
            if((isVowel(word[i])))
            {
                cout<<"Inside vowel : ";
                vf = true;
            }   
            else if(isConsonant(word[i]))
            {
                cout<<"Inside consonant : ";
                cf = true;
            }   
            else if(isdigit(word[i])){
                cout<<"Inside digit : ";
            }
            else
            {
                cout<<"Inside special char : ";
                return false;
            }
                
        }

        if(vf && cf)
            return true;
        return false;
    }
};

//Better
class Solution {
private:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u');
    }
public:
    bool isValid(string word) {
        int n = word.size();

        if(n < 3)
            return false;
        
        bool hasVowel = false, hasConsonant = false;

        for(auto ch : word)
        {
            if(isalpha(ch))
            {
                ch = tolower(ch);
                cout<<"Current char : "<<ch<<endl;
                if(isVowel(ch))
                {
                    hasVowel = true;
                }
                else
                {
                    hasConsonant = true;
                }
            }
            else if(!isdigit(ch))
            {
                return false;
            }
        }
        return (hasVowel && hasConsonant);
    }
};
