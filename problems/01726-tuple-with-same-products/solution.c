int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    return f-s;
}

int tupleSameProduct(int* nums, int numsSize) {
    if (numsSize<4) return 0;
    int result = 0;
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i=0; i<numsSize-3; i++) {
        for (int j=i+1; j<numsSize-2; j++) {
            for (int k=j+1; k<numsSize-1; k++) {
                for (int l=k+1; l<numsSize; l++) {
                    if (nums[i]*nums[l]==nums[j]*nums[k]) {
                        result+=8;
                        l=numsSize;
                    }
                }
            }
        }
    }
    return result;
}