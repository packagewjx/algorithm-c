//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-16.

#include <memory.h>
#include <stdio.h>

int nonRevertible(int a, int b) {
    return (a * b) ^ b;
}

int hashes[100];
int sizeHashes = 0;

int existHash(int hash) {
    for (int i = 0; i < sizeHashes; i++) {
        if (hashes[i] == hash)
            return 1;
    }
    return 0;
}

int existEmail(char *email, int *hashloc) {
    *hashloc = 0;
    int loc = 0;
    for (loc = 0; email[loc] != '@'; loc++) {
        if (email[loc] == '.')
            continue;
        else if (email[loc] == '+') {
            // 一直跳到@位置
            while (email[++loc] != '@');
            break;
        }
        *hashloc = nonRevertible(*hashloc, email[loc]);
    }

    // 这里email[loc]应该是@

    while (loc < strlen(email)) {
        *hashloc = nonRevertible(*hashloc, email[loc++]);
    }


    if (existHash(*hashloc)) {
        return 1;
    } else {
        return 0;
    }
}

void addUniqueHash(int hash) {
    hashes[sizeHashes++] = hash;
}


int numUniqueEmails(char **emails, int emailsSize) {
    for (int i = 0; i < emailsSize; i++) {
        int hash;
        if (!existEmail(emails[i], &hash)) {
            addUniqueHash(hash);
        }
    }

    return sizeHashes;
}

int main() {
    char *mails[3];
    mails[0] = "test.email+alex@leetcode.com";
    mails[1] = "test.e.mail+bob.cathy@leetcode.com";
    mails[2] = "testemail+david@lee.tcode.com";

    printf("%d", numUniqueEmails(mails, 3));
}