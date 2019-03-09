#include <stdio.h>

int main() {
	char c, p;

	p = EOF;

	while ((c = getchar()) != EOF) {
		if (c != ' ' || p != ' ') {
			putchar(c);
		}
		p = c;
	}
}
