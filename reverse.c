#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[], int len);

int main() {
	int len;
	char line[MAXLINE];
	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s\n", line);
	}
	return 0;
}

int get_line(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], int len) {
	int i = 0, j = len-1;
	while(i < j) {
		char c = s[i];
		s[i]=s[j];
		s[j]=c;
		++i; --j;
	}
}

