//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-3.
//

void swap(char* s, int i1, int i2) {
    char temp = s[i1];
    s[i1] = s[i2];
    s[i2] = temp;
}

void reverseString(char* s, int sSize) {
    for (int i = 0; i < sSize / 2; i++) {
        swap(s, i, sSize - i - 1);
    }
}