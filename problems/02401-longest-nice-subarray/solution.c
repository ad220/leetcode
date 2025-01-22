int longestNiceSubarray(int* nums, int numsSize) {
    int i=0, j=0;
    int length=0;

    int mask = 0;
    while (j<numsSize) {
        if(mask & nums[j]) {
            if (j-i>length) {
                length=j-i;
            }
            mask ^= nums[i++];
        } else {
            mask |= nums[j++];
        }
    }

    if (j-i>length && numsSize>0) {
        length=j-i;
    }
    return length;
}