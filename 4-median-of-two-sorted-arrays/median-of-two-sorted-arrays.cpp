class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Do some initial preprocessing to handle cases where one of the
        // vectors has a zero size
        // nums1 size is 0
        if (nums1.size() == 0 && nums2.size() == 1) {
            return nums2.at(0);
        }
        if (nums1.size() == 0 && nums2.size() > 1 && (nums2.size() % 2 != 0)) {
            return (static_cast<double>(
                nums2.at(static_cast<int>(nums2.size() / 2 + 0.5))));
        }
        if (nums1.size() == 0 && nums2.size() > 1 && (nums2.size() % 2 != 0)) {
            return ((static_cast<double>(nums2.at(nums2.size() / 2)) +
                     static_cast<double>(nums2.at(nums2.size() / 2 - 1))) /
                    2);
        }

        // nums2 size is 0
        if (nums2.size() == 0 && nums1.size() == 1) {
            return nums1.at(0);
        }
        if (nums2.size() == 0 && nums1.size() > 1 && (nums1.size() % 2 != 0)) {
            return (static_cast<double>(
                nums1.at(static_cast<int>(nums1.size() / 2 + 0.5))));
        }
        if (nums2.size() == 0 && nums1.size() > 1 && (nums1.size() % 2 == 0)) {
            return ((static_cast<double>(nums1.at(nums1.size() / 2)) +
                     static_cast<double>(nums1.at(nums1.size() / 2 - 1))) /
                    2);
        }

        // At this point we know neither vector is of size 0
        // Iterate through nums2 and add each num to nums1
        for (auto num : nums2) {
            nums1.push_back(num);
        }

        // Now re-sort nums1
        std::sort(nums1.begin(), nums1.end());

        // Finally, return the median
        if (nums1.size() % 2 != 0) {
            // ODD size
            return (static_cast<double>(
                nums1.at(static_cast<int>(nums1.size() / 2))));
        } else {
            // EVEN size
            return ((static_cast<double>(nums1.at(nums1.size() / 2)) +
                     static_cast<double>(nums1.at(nums1.size() / 2 - 1))) /
                    2);
        }
    }
};