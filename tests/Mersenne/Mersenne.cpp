#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void write_N(uint64_t *N, int idx)
{
    char name[3];
    sprintf(name, "%d", idx);
    FILE *f = fopen(name, "wb");
    fwrite(N, sizeof(uint64_t), 1, f);
    fclose(f);
}
int main()
{
    for (int i = 0; i < 63; ++i) {
        uint64_t N = (1<<i) + 1;
        printf("2^%d=%llu\n", i, N);
        write_N(&N, i);
    }
    printf("sizeof(int64_t)=%lu\n", sizeof(int64_t));
    return 0;

}
