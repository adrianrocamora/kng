#include <stdio.h>

//using namespace std;

int N;
char x[110];

int main() {
	scanf("%d\n", &N);
	while (N--) {
		scanf("0.%[0-9]...\n", &x);
		printf("The digits are 0.%s\n",x);
	}
	return 0;
}

