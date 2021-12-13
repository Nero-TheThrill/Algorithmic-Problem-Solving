class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1)
            return s;
        else
        {
            string result = "";
            int left, right;
            int start = 0, end = 1;
            for (int i = 1; i < s.size(); i++)
            {
                left = i - 1;
                right = i;
                while (left >= 0 && right < s.size() && s[left] == s[right]) {
                    if ((right - left + 1) > end) {
                        start = left;
                        end = right - left + 1;
                    }
                    left--; right++;
                }


                left = i - 1;
                right = i + 1;
                while (left >= 0 && right < s.size() && s[left] == s[right]) {
                    if ((right - left + 1) > end) {
                        start = left;
                        end = right - left + 1;
                    }
                    left--; right++;
                }
            }
            for (int i = start; i < end + start; i++) {
                result += s[i];
            }
            return result;
        }
    }
};