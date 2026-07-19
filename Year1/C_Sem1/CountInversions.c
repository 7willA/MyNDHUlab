#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int L;
        scanf("%d", &L);

        int arr[L];
        for (int i = 0; i < L; i++) {
            scanf("%d", &arr[i]);
        }

        int temp[L];
        int inv_count = 0;

        for (int size = 1; size < L; size *= 2) {
            for (int left_start = 0; left_start < L; left_start += 2 * size) {
                int mid = left_start + size - 1;
                int right_end = left_start + 2 * size - 1;
                if (mid >= L) break;
                if (right_end >= L) right_end = L - 1;

                int i = left_start;
                int j = mid + 1;
                int k = left_start;

                while (i <= mid && j <= right_end) {
                    if (arr[i] <= arr[j]) {
                        temp[k++] = arr[i++];
                    } else {
                        temp[k++] = arr[j++];
                        inv_count += (mid - i + 1);
                    }
                }

                while (i <= mid) {
                    temp[k++] = arr[i++];
                }

                while (j <= right_end) {
                    temp[k++] = arr[j++];
                }

                for (i = left_start; i <= right_end; i++) {
                    arr[i] = temp[i];
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", inv_count);
    }

    return 0;
}
