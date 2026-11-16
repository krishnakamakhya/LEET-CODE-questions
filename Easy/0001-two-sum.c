#include <stdlib.h>

#define HASH_SIZE 20011

typedef struct Node {
    int key;
    int val;
    struct Node* next;
} Node;

int hash(int key) {
    int h = key % HASH_SIZE;
    return h < 0 ? h + HASH_SIZE : h;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[HASH_SIZE] = {NULL};
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int h = hash(complement);

        Node* curr = table[h];
        while (curr != NULL) {
            if (curr->key == complement) {
                result[0] = curr->val;
                result[1] = i;
                return result;
            }
            curr = curr->next;
        }

        int idx = hash(nums[i]);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = nums[i];
        newNode->val = i;
        newNode->next = table[idx];
        table[idx] = newNode;
    }

    *returnSize = 0;
    return NULL;
}
