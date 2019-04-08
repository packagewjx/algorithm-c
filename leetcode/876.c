//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-3.
//

#include "datastructures.h"

#define NULL 0

struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* p1 = head;
    struct ListNode* p2 = head->next;

    while (p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
        if (p2 == NULL)
            break;
        p2 = p2->next;
    }

    return p1;
}