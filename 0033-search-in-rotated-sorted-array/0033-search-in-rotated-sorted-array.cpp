class Solution {
public:

    int pivot1(vector<int> &nums, int n) {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s < e) {
            if (nums[mid] >= nums[0]) {
                s = mid + 1;
            } else {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = pivot1(nums, n);

        int s, e;
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            // Search in right sorted part
            s = pivot;
            e = n - 1;
        } else {
            // Search in left sorted part
            s = 0;
            e = pivot - 1;
        }

        int mid;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return -1;
    }
};
