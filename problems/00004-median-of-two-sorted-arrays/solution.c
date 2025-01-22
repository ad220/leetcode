double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int numsSize = nums1Size + nums2Size;
    int* nums = malloc(numsSize*sizeof(int));

    int i=0;
    int j=0;
    for (int k=0; k<=numsSize/2; k++) {
        if (i==nums1Size || j==nums2Size) {
            int* end_nums = i==nums1Size ? nums2 : nums1;
            int end_count = i==nums1Size ? j : i;
            int end_size = i==nums1Size ? nums2Size : nums1Size;
            while (k<=numsSize/2) {
                nums[k++] = end_nums[end_count++];
            }
        }
        else nums[k] = nums1[i]<nums2[j] ? nums1[i++] : nums2[j++];
    }

    double result = numsSize%2 ? nums[numsSize/2] : (nums[numsSize/2]+nums[numsSize/2-1])/2.0;
    free(nums);
    return result;
}