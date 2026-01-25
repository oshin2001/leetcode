class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(nullptr));
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void QuickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[left], nums[pivotIndex]);

        int pivotValue = nums[left];

        int lessEnd = left;
        int current = left + 1;
        int greaterStart = right;

        while (current <= greaterStart) {
            if (nums[current] < pivotValue) {
                swap(nums[lessEnd++], nums[current++]);
            } else if (nums[current] > pivotValue) {
                swap(nums[current], nums[greaterStart--]);
            } else {
                current++;
            }
        }

        QuickSort(nums, left, lessEnd - 1);
        QuickSort(nums, greaterStart + 1, right);
    }
};