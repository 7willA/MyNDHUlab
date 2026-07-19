#include <stdio.h>
#include <string.h>

#define MAX_BLOCKS 25
int blocks[MAX_BLOCKS][MAX_BLOCKS];
int stack_size[MAX_BLOCKS];  

int find_stack(int b) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        for (int j = 0; j < stack_size[i]; j++) {
            if (blocks[i][j] == b) return i;
        }
    }
    return -1; 
}

void reset_above(int stack, int block) {
    while (blocks[stack][stack_size[stack] - 1] != block) {
        int top = blocks[stack][--stack_size[stack]];
        blocks[top][stack_size[top]++] = top;
    }
}

void move_block(int stack_a, int stack_b, int a) {
    blocks[stack_b][stack_size[stack_b]++] = blocks[stack_a][--stack_size[stack_a]];
}

void pile_blocks(int stack_a, int stack_b, int a) {
    int start = 0;
    while (blocks[stack_a][start] != a) start++;

    for (int i = start; i < stack_size[stack_a]; i++) {
        blocks[stack_b][stack_size[stack_b]++] = blocks[stack_a][i];
    }
    stack_size[stack_a] = start;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        blocks[i][0] = i;
        stack_size[i] = 1;
    }

    char cmd[5], prep[5];
    int a, b;

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "quit") == 0) break;

        scanf("%d %s %d", &a, prep, &b);

        int stack_a = find_stack(a);
        int stack_b = find_stack(b);

        if (a == b || stack_a == stack_b) continue;

        if (strcmp(cmd, "move") == 0 && strcmp(prep, "onto") == 0) {
            reset_above(stack_a, a);
            reset_above(stack_b, b);
            move_block(stack_a, stack_b, a);
        } else if (strcmp(cmd, "move") == 0 && strcmp(prep, "over") == 0) {
            reset_above(stack_a, a);
            move_block(stack_a, stack_b, a);
        } else if (strcmp(cmd, "pile") == 0 && strcmp(prep, "onto") == 0) {
            reset_above(stack_b, b);
            pile_blocks(stack_a, stack_b, a);
        } else if (strcmp(cmd, "pile") == 0 && strcmp(prep, "over") == 0) {
            pile_blocks(stack_a, stack_b, a);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < stack_size[i]; j++) {
            printf(" %d", blocks[i][j]);
        }
        printf("\n");
    }
    return 0;
}
