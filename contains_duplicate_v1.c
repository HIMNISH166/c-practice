int comp(const void* a, const void* b) {
    int v1 = *(const int*)a;
    int v2 = *(const int*)b;
    if (v1 > v2) return 1;
    if (v1 < v2) return -1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    // Sort the array so duplicates are placed adjacent to each other
    qsort(nums, numsSize, sizeof(int), comp);

    // Loop up to numsSize - 1 to prevent out-of-bounds access
    for (int i = 0; i < numsSize - 1; i++) {
        // If two adjacent elements are equal, a duplicate exists
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    // If the loop finishes without finding duplicates, return false
    return false;
}