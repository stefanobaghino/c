#include <stdio.h>

#define TAB 4

int main() {
	char c;
	while((c=getchar()) != EOF) {
		if (c == '\t') {
			for(int i=0;i<TAB;i++) {
				putchar(' ');
			}
		} else {
			putchar(c);
		}
	}
	return 0;
}
