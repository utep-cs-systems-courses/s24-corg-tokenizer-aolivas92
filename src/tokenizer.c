#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000     /* buffer size */

int getline2(char [], int);

int main() {
  char *line = NULL;
  long size = BUFFER_SIZE;
  int characters;

  printf(">");
  while ((characters = getline(&line, &size, stdin)) != -1) {
    printf("%s", line);
    printf(">");
  }

  free(line);
  return 0;
}

/* space_char: returns non-zero if c is a whitespace character */
int space_char(char c) {
  if (c == ' ' || c == '\t')
    return 1;

  return 0;
}

/* non_space_char: returns non-zero if c is a non-whitespace */
int non_space_char(char c) {
  if (c != ' ' || c != '\t')
    return 1;

  return 0;
}

/* token_start: returns a pointer to the first character of the next space-separated token in zero-terminated str. Zero pointer if str doesn't contain any tokens */
char *
token_start(char *str) {}

/* token_terminator: returns a pointer terminator char following *token */
char *
token_terminator(char *token) {}

/* count_tokens: counts the number of tokens in the string argument */
int count_tokens(char *str) {}

/* copy_str: returns a freshly allocated new zero-terminated string containing <len> char from <inStr> */
char *
copy_str(char *inStr, short len) {}

/* tokenize: Returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens from zero-terminated str. */
char **
tokenize(char *str) {}

/* print_tokens: prints all tokens. */
void print_tokens(char **tokens) {}

/* free_tokens: frees all tokens and the vector containing them. */
void free_tokens(char **tokens) {}
