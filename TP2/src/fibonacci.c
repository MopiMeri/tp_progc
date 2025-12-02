#include <stdio.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int u0 = 0, u1 = 1, un;

    printf("%d %d ", u0, u1);

    for (int i = 2; i <= n-1; i++) {
        un = u0 + u1;
        printf("%d ", un);
        u0 = u1;
        u1 = un;
    }

    return 0;
}
