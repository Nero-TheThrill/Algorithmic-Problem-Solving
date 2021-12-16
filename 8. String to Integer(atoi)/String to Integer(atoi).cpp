class Solution {
public:
    int myAtoi(string s) {
        bool signChecked=false;
        bool isSign=true;
        bool foundNum=false;
        int result=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                if(result>214748364||(result==214748364&&(s[i]-'0')>7))
                {
                    return isSign?2147483647:-2147483648;
                }
                result*=10;
                result+=s[i]-'0';
                signChecked=true;
                foundNum=true;
            }
            else if(!signChecked&&i<s.length()-1&& (s[i+1]>='0'&&s[i+1]<='9') &&s[i]=='-')
            {
                isSign=false;
                signChecked=true;
            }
            else if(!signChecked&&i<s.length()-1&& (s[i+1]>='0'&&s[i+1]<='9') &&s[i]=='+')
            {
                isSign=true;
                signChecked=true;
            }
            else if(s[i]!=' '||foundNum)
            {
                if(result==0)
                    return 0;
                else
                    return isSign?result:-result;
            }
            
        }
        
        return isSign?result:-result;
    }
};