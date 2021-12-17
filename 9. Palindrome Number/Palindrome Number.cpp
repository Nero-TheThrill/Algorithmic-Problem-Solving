class Solution {
public:
    bool isPalindrome(int x) {
        string s1,s2;
        if(x<0)
            return false;
        while(x>0)
        {
            s1+=std::to_string(x%10);
            x/=10;
        }
        int j=s1.length()-1;
        s2=s1;
        for(int i=0;i<s1.length()/2;i++)
        {
            std::swap(s2[i],s2[j]);
            j--;
        }
        std::cout<< s1<<" "<<s2;
        return s1==s2;
        
    }
};