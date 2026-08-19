#include <limits.h>

// Helper macro to find maximum of two integers
#define MAX(a, b) ((a) > (b) ? (a) : (b))
// Helper macro to find minimum of two integers
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to minimize the binary search range
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;
    int halfLen = (m + n + 1) / 2;
    
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = halfLen - partitionX;
        
        // If partitionX is 0, nothing is on the left side of nums1. Use INT_MIN.
        // If partitionX is m, nothing is on the right side of nums1. Use INT_MAX.
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        
        // Apply the same logic for nums2
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
        
        // Correct partition found
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // If total length is odd
            if ((m + n) % 2 == 1) {
                return (double)MAX(maxLeftX, maxLeftY);
            }
            // If total length is even
            return ((double)MAX(maxLeftX, maxLeftY) + MIN(minRightX, minRightY)) / 2.0;
        }
        // Partition is too far right in nums1, move left
        else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        }
        // Partition is too far left in nums1, move right
        else {
            low = partitionX + 1;
        }
    }
    
    return 0.0; // Fallback return statement
}
