#include <stdio.h>

#define SIZE 1000005

int main() {
    int arr[SIZE] = {0}, n;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int temp[SIZE];

        for (int size = 1; size < n; size *= 2) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = left + 2 * size - 1;
                if (mid >= n) break;
                if (right >= n) right = n - 1;

                int i = left, j = mid + 1, k = left;
                while (i <= mid && j <= right) {
                    if (arr[i] <= arr[j]) {
                        temp[k++] = arr[i++];
                    } else {
                        temp[k++] = arr[j++];
                    }
                }

                while (i <= mid) {
                    temp[k++] = arr[i++];
                }

                while (j <= right) {
                    temp[k++] = arr[j++];
                }

                for (i = left; i <= right; i++) {
                    arr[i] = temp[i];
                }
            }
        }

        int mid1 = arr[(n - 1) / 2];
        int mid2 = arr[n / 2];

        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == mid1 || arr[i] == mid2) {
                counter++;
            }
        }

        printf("%d %d %d\n", mid1, counter, mid2 - mid1 + 1);
    }

    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000005

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[SIZE] = {0}, n;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Sort the array using qsort
        qsort(arr, n, sizeof(int), compare);

        int mid1 = arr[(n - 1) / 2];
        int mid2 = arr[n / 2];

        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == mid1 || arr[i] == mid2) {
                counter++;
            }
        }

        printf("%d %d %d\n", mid1, counter, mid2 - mid1 + 1);
    }

    return 0;
}
*/