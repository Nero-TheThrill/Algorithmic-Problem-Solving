#include <algorithm>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        std::sort(std::begin(nums1), std::end(nums1));

        if (nums1.size() % 2 == 0)
        {
            int mid = (nums1.size() - 1) / 2;
            return double(nums1[mid] + nums1[mid + 1]) / 2;
        }
        else
        {
            return nums1[nums1.size() / 2];
        }
    }
};
