#include <stdio.h>

#define TAB 4

int main() {
	char c;
       	int nb = 0;
	while((c=getchar()) != EOF) {
		if (c == ' ') {
			if (++nb == TAB) {
				putchar('\t');
				nb = 0;
			}
		} else {
			for (int i = 0; i < nb; i++) putchar(' ');
			nb = 0;
			putchar(c);
		}
	}
	return 0;
}
