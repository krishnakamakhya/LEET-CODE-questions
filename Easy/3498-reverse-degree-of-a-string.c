int reverseDegree(char* s) {
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int reversed_pos = 26 - (s[i] - 'a');
        int string_pos = i + 1;
        total += reversed_pos * string_pos;
    }
    return total;
}
