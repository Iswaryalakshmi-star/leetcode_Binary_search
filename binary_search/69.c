int mySqrt(int x) {
    if (x < 2) {
        return x;
    }
    
    int low = 2;
    int high = x / 2;
    int ans = 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Using division instead of mid * mid to prevent integer overflow
        if (mid == x / mid) {
            return mid;
        } else if (mid < x / mid) {
            ans = mid;     // Potential answer found
            low = mid + 1; // Try to find a larger integer
        } else {
            high = mid - 1;
        }
    }
    
    return ans;
}
