#include <gtest/gtest.h>
#include "addtwonum_util.h"

// Helper to create a linked list from an array of digits
ListNode* createList(const int* digits, int size) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < size; ++i) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = digits[i];
        node->next = NULL;
        if (!head) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

// Helper to compare two linked lists
bool compareList(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == NULL && l2 == NULL;
}

// Helper to free a linked list
void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }
}

TEST(AddTwoNumbersTest, HandlesListSum) {
    int a[] = {2, 4, 3}; // represents 342
    int b[] = {5, 6, 4}; // represents 465
    int expected[] = {7, 0, 8}; // represents 807

    ListNode* l1 = createList(a, 3);
    ListNode* l2 = createList(b, 3);
    ListNode* result = addTwoNumbers(l1, l2);
    ListNode* expectedList = createList(expected, 3);

    EXPECT_TRUE(compareList(result, expectedList));

    freeList(l1);
    freeList(l2);
    freeList(result);
    freeList(expectedList);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}