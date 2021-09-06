class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int result=0,order=0,startpoint=-1;
        std::unordered_map<char,int> map;
        
        for(auto c: s)
        {
            if(map.find(c)==map.end())
            {
                map.insert(std::pair<char, int>(c, order));
            }
            else
            {
                startpoint = std::max(startpoint, map[c]);
                map[c] = order;
            }
            result = std::max(result, order - startpoint);
            order++;
        }


        return result;
    }
};
