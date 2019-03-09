#include <stdio.h>

#define THRESHOLD 80
#define MAXLINE 1000

int get_line(char s[], int lim);

int main() {
	char buf[MAXLINE];
	int len;
	while((len=get_line(buf,MAXLINE)) > 0) {
		if (len > THRESHOLD) {
			int i;
			for(i=0; i<len; i++) {
				putchar(buf[i]);
			}
		}
	}
}

int get_line(char s[], int lim) {
	int c, i;
	for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim-1) {
			s[i] = c;
		}
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
