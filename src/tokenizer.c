#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000     /* buffer size */

int getline2(char [], int);

int main() {
  char *s = NULL;
  long size = BUFFER_SIZE;
  int characters;

  printf(">");
  while ((characters = getline(&s, &size, stdin)) != -1) {
    printf("%s", s);
    printf(">");
  }

  free(s);
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
  if (c != ' ' || c != '\t' || c != '\0')
    return 1;

  return 0;
}

/* token_start: returns a pointer to the first character of the next space-separated token in zero-terminated str. Zero pointer if str doesn't contain any tokens */
char *
token_start(char *str) {
  // If pointer doesn't exist return NULL
  if (!str)
    return NULL;

  // skip all the whitespace
  while (space_char(*str))
      str++;

  return str;

  return NULL;
}

/* token_terminator: returns a pointer terminator char following *token */
char *
token_terminator(char *token) {
  // If pointer doesn't exist return NULL
  if (!token)
    return NULL;

  // keep going until we hit a new line or a space
  while (non_space_char(*token) && *token != '\n')
    token++;

  return token;
}

/* count_tokens: counts the number of tokens in the string argument */
int count_tokens(char *str) {
  int count = 0;
  // If pointer doesn't exist return NULL
  if(!str)
    return -1;

  // Keep counting until we hit a space or new line
  while (non_space_char(*str) && *str != '\n') {
    str++;
    count++;
  }

  return count;
}

/* copy_str: returns a freshly allocated new zero-terminated string containing <len> char from <inStr> */
char *
copy_str(char *inStr, short len) {
  // If pointer doesn't exist return NULL
  if(!inStr)
    return NULL;
  
  char *cpyStr;
  cpyStr = (char *)malloc(len);

  // If we failed to allocated return NULL
  if (!cpyStr)
    return NULL;

  // For i to len and inStr not a space copy each char to cpyStr
  for (int i = 0; i < len && non_space_char(*inStr); i++)
    cpyStr[i] = *inStr++;

  cpyStr[len] = '\0';

  return cpyStr;
}

/* tokenize: Returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens from zero-terminated str. */
char **
tokenize(char *str) {}

/* print_tokens: prints all tokens. */
void print_tokens(char **tokens) {}

/* free_tokens: frees all tokens and the vector containing them. */
void free_tokens(char **tokens) {}
