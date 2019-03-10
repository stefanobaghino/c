#include <stdio.h>

#define MAXLINE 1000
#define MARGIN 20

int nextline(char line[], int maxline);
int nextword(char line[], int from, char word[]);
int triml(char s[], char t[]);
void first(int n, char s[], char t[]);

int main() {
	int len, caret = 0;
	char line[MAXLINE], word[MAXLINE], trim[MAXLINE];
	while ((len = nextline(line, MAXLINE)) > 0) {
		int i = 0;
		int wl = 0;
		while ((wl = nextword(line, i, word)) > 0) {
			if (wl >= MARGIN) {
				int gap = MARGIN - (i % MARGIN);
				i += gap;
				first(gap, word, trim);
				printf("%s=\n", trim);
				caret = 0;
			} else {
				i += wl;
				caret += wl;
				if (caret > MARGIN) {
					putchar('\n');
					caret = triml(word, trim);
					printf("%s", trim);
				} else {
					printf("%s", word);
				}
			}
		}
		putchar('\n');
		caret = 0;
	}
	return 0;
}

int nextline(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int nextword(char line[], int from, char word[]) {
	int i = from, j = 0;
	while (line[i] != '\0' && line[i] != '\n' && (line[i] == ' ' || line[i] == '\t')) {
		word[j++] = line[i++];
	}
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ' && line[i] != '\t') {
		word[j++] = line[i++];
	}
	word[j]='\0';
	return j;
}

int triml(char s[], char t[]) {
	int i = 0, j = 0;
	while (s[i] == ' ' || s[i] == '\t') {
		i++;
	}
	while (s[i] != '\0') {
		t[j++] = s[i++];
	}
	t[j] = '\0';
	return j;
}

void first(int n, char s[], char t[]) {
	int i = 0;
	while (i < n && s[i] != '\0') {
		t[i] = s[i];
		++i;
	}
	t[i]='\0';
}

