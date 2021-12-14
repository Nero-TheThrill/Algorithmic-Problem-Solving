class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int count = 0;
        int addThis = 1;
        std::vector<int> floor;
        std::string result = "";
        for (auto c : s)
        {
            floor.push_back(count);
            count += addThis;
            if (count == numRows - 1)
            {
                addThis = -1;
            }
            if (count == 0)
            {
                addThis = 1;
            }
        }
        for (int i = 0; i < numRows; i++)
        {
            int order = 0;
            for (auto c : floor)
            {
                if (c == i)
                {
                    result += s[order];
                }
                order++;
            }
        }
        return result;
    }
};