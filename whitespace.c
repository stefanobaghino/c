#include <stdio.h>

int main() {
	int c, nb, nt, nl;

	nb = 0;
	nt = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') ++nb;
		if (c == '\t') ++nt;
		if (c == '\n') ++nl;
	}
	printf("%d\t%d\t%d\n", nb, nt, nl);
}

