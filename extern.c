#include <stdio.h>
#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line();
void copy();

int main() {
	int len;
	extern int max;
	extern char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
			copy(longest, line);
			if (line[len-1] != '\n') {
				copy(longest+len-3, "...");
				int c;
				while ((c=getchar()) != EOF && c != '\n') {
					++len;
				}
				++len;
			}
			max = len;
		}
	}
	if (max > 0) {
		printf("%d|%s\n", max, longest);
	}
	return 0;
}

int get_line() {
	int c, i;
	extern char line[];
	for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

void copy() {
	int i;
	extern char line[], longest[];
	i = 0;
	while((longest[i] = line[i]) != '\0') {
		++i;
	}
}

