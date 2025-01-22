/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2*sizeof(int));
    int i=0;
    int j=1;

    while (nums[i]+nums[j]!=target) {
        if (++j==numsSize) {
            i++;
            j=i+1;
        }
    }

    result[0]=i;
    result[1]=j;
    returnSize[0] = 2;
    return result;
}