class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) return true;

            // Left half is sorted
            if (nums[s] < nums[mid]) {
                if (target >= nums[s] && target < nums[mid])
                    e = mid - 1;
                else
                    s = mid + 1;
            }

            // Right half is sorted
            else if (nums[mid] < nums[s]) {
                if (target > nums[mid] && target <= nums[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }

            // nums[s] == nums[mid], skip duplicates
            else {
                s++;
            }
        }

        return false;
    }
};
