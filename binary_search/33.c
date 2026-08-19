int search(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1; // Target is in the left half
            } else {
                low = mid + 1;  // Target is in the right half
            }
        } 
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;  // Target is in the right half
            } else {
                high = mid - 1; // Target is in the left half
            }
        }
    }
    
    return -1; // Target not found
}
