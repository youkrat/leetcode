#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;
                return ans;
            }
        }
    }

    *returnSize = 0;
    return NULL; 
}


/*
Hash Table implementation
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

int hash(int key, int size) {
    long long k = key;
    k = (k < 0) ? -k : k;
    return k % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int tableSize = numsSize * 2;
    Pair* hashTable = calloc(tableSize, sizeof(Pair));

    for (int i = 0; i < tableSize; i++)
        hashTable[i].key = 2147483647;

    int* ans = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int idx = hash(complement, tableSize);

        while (hashTable[idx].key != 2147483647) {
            if (hashTable[idx].key == complement) {
                ans[0] = hashTable[idx].value;
                ans[1] = i;
                *returnSize = 2;
                free(hashTable);
                return ans;
            }
            idx = (idx + 1) % tableSize;
        }

        idx = hash(nums[i], tableSize);
        while (hashTable[idx].key != 2147483647)
            idx = (idx + 1) % tableSize;

        hashTable[idx].key = nums[i];
        hashTable[idx].value = i;
    }

    free(hashTable);
    *returnSize = 0;
    return NULL;
}

*/