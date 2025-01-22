int lengthOfLongestSubstring(char* s) {
    int i=0;
    int j=1;
    int k=0;
    int length=0;

    int slen = strlen(s);

    while (j<slen) {
        for (k=i; k<j; k++) {
            if(s[k]==s[j]) {
                if (j-i>length) {
                    length=j-i;
                }
                i=k+1;
                k=j;
            }
        }
        j++;
    }

    if (j-i>length && slen>0) {
        length=j-i;
    }
    return length;
}