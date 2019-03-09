#include <stdio.h>

int main() {
	int c;
	
	c = getchar();
	while (c != EOF) {
		if (c != '\n') {
			printf("read '%c', c != EOF evaluates to %d\n", c, c != EOF);
		}
		c = getchar();
	}
	printf("read EOF, c != EOF evaluates to %d\n", c != EOF);
}
