#include <stdio.h>

#define MAXBUF 1000

int main() {
	char buf[MAXBUF];
	char b = 0;
	char c;
	while ((c=getchar()) != EOF) {
		if (c == ' ' || c == '\t' && b < MAXBUF) {
			buf[b++] = c;
		} else {
			if (c != '\n') {
				for (int i=0; i<b; i++) {
					putchar(buf[i]);
				}
			}
			b=0;
			putchar(c);
		}
	}
}
