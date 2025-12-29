#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);

int main(void){
    int nums[] = {1,1,2,2,3,4,4,5,6,9,9};
    int size = sizeof(nums)/sizeof(nums[0]);
    int newSize = removeDuplicates(nums, size);
    printf("New size after removing duplicates: %d\n", newSize);
    printf("Array after removing duplicates: ");
    for(int i = 0; i < newSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    int count = 1;
    
    for(int i = 1; i < numsSize; i++){
        if(nums[i] != nums[i-1]){
            nums[count++] = nums[i];
        }
    }
    return count;
}
void print_array(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}