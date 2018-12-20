#include <cstdio>

void print_bytes(char *start, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

int main() {
    int a = 0x15;
    int b = 0x1234;
    int c = 1234;
    print_bytes((char*)&a, sizeof(a));
    print_bytes((char*)&b, sizeof(b));
    print_bytes((char*)&c, sizeof(c));
}
