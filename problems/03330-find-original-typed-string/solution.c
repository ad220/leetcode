int possibleStringCount(char* word) {
    char last_letter = 0;
    int result = 1;

    for (int i=0; i<strlen(word); i++) {
        if (word[i] == last_letter) result++;
        last_letter = word[i];
    }

    return result;
}