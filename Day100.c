#include <stdio.h>
#include <stdlib.h>

struct Element {
    int val;
    int index;
};

void merge(struct Element* arr, int* count, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int num_right_smaller = 0;
    struct Element* temp = malloc((right - left + 1) * sizeof(struct Element));

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            num_right_smaller++;
            temp[k++] = arr[j++];
        } else {
            count[arr[i].index] += num_right_smaller;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += num_right_smaller;
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
    free(temp);
}

void mergeSort(struct Element* arr, int* count, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    struct Element* arr = malloc(n * sizeof(struct Element));
    int* count = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, count, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    free(arr);
    free(count);
    return 0;
}