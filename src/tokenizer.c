#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define BUFFER_SIZE 1000     /* buffer size */

int main() {
  char *s = NULL;
  long size = BUFFER_SIZE;
  int characters;

  printf(">");
  while ((characters = getline(&s, &size, stdin)) != -1) {
    printf("%s", s);
    char ** tokens = tokenize(s);
    print_tokens(tokens);
    free_tokens(tokens);
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
  if (c != ' ' && c != '\t' && c != '\0')
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

  // Verify it's valid
  if (non_space_char(*str) && *str != '\0' && *str != '\n')
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
  int inWord = 0;
  // If pointer doesn't exist return NULL
  if(!str)
    return -1;

  // ship whitespace
  while (space_char(*str))
    str++;

  // Keep counting until we hit a terminating zero or new line
  while (*str != '\0' && *str != '\n') {
    if (space_char(*str) || *str == '\n') {
      if (inWord) {
	count++;
	inWord = 0;
      }
    } else {
      if (!inWord)
	inWord = 1;
    }
    str++;
  }

  if (inWord)
    count++;

  return count;
}

/* copy_str: returns a freshly allocated new zero-terminated string containing <len> char from <inStr> */
char *
copy_str(char *inStr, short len) {
  // If pointer doesn't exist return NULL
  if(!inStr)
    return NULL;
  
  char *cpyStr = malloc(len+1);
  // If we failed to allocated return NULL
  if (!cpyStr)
    return NULL;

  // For i to len and inStr not a space copy each char to cpyStr
  int i;
  for (i = 0; i < len; i++) {
    *(cpyStr + i) = *(inStr + i);
  }

  *(cpyStr + len) = '\0';

  return cpyStr;
}

/* tokenize: Returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens from zero-terminated str. */
char **
tokenize(char *str) {
  // If pointer doesn't exist return NULL
  if (!str)
    return NULL;

  // Get the number of tokens and verify number
  int numTokens = count_tokens(str);
  if (numTokens < 1)
    return NULL;

  // Allocate the space for the tokens and verify, extra space for terminator
  char **tokens = (char **)malloc((numTokens + 1) * sizeof(char *));
  if (!tokens)
    return NULL;

  int i = 0;
  // While we aren't at the end of the string
  while (numTokens) {
    // get the start of the token and verify
    char *tokenStrtPtr = token_start(str);
    if (tokenStrtPtr == NULL)
      break;

    // Get the end of the token and use that to get the len
    char *tokenEndPtr = token_terminator(tokenStrtPtr);
    short tokenLen = tokenEndPtr - tokenStrtPtr;

    // Copy the token to our current tokens location
    tokens[i] = copy_str(tokenStrtPtr, tokenLen);

    // Set the start of the string to the end of our token
    str = tokenEndPtr;
    // Move on to the next point in the tokens
    i++;
    numTokens--;
  }

  tokens[i] = NULL;
  return tokens;
}

/* print_tokens: prints all tokens. */
void print_tokens(char **tokens) {
  // If pointer doesn't exist return
  if (!tokens)
    return;

  int i = 0;
  // Iterate through the tokens and print the strings
  while (tokens[i] != NULL) {
    printf("token[%d] = %s\n", i, tokens[i]);
    i++;
  }
}

/* free_tokens: frees all tokens and the vector containing them. */
void free_tokens(char **tokens) {
  // If pointer doesn't exist return
  if (!tokens)
    return;

  int i = 0;
  // Iterate through the tokens and free each one
  while (tokens[i] != NULL) {
    free(tokens[i]);
    i++;
  }

  // Free the tokens ptrs
  free(tokens);
}
