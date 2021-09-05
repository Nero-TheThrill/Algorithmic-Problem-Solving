#include<string>
#include<iostream>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, bool> m;
        for(auto c : s)
        {
            auto d = m.find(c);
            if(==m.end())
            {
                
            }
        }
        return ;
    }
};

int main()
{
    Solution s;
   std::cout<<  s.lengthOfLongestSubstring("pwwkew");
   return 0;
}

