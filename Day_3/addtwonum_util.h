#ifndef ADDTWONUM_UTIL_H
#define ADDTWONUM_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Adds two numbers represented by linked lists.
 * Each node contains a single digit, and the digits are stored in reverse order.
 *
 * @param l1 Pointer to the first linked list representing the first number.
 * @param l2 Pointer to the second linked list representing the second number.
 * @return Pointer to the head of a new linked list representing the sum of the two numbers.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

#ifdef __cplusplus
}
#endif

#endif // ADDTWONUM_UTIL_H