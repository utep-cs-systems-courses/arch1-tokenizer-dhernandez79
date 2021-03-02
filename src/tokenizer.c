#include <stdio.h>
#include <stdlib.h>

short string_length(char *str) {
  int counter = 0;
  while (*str){
    counter++;
    str++;
  }
  return counter;
}

/*Returns 1 if char is a space */
int space_char(char c) {
  if (c == ' ' || c == '\t') {
    return 1;
  }
  else {
    return 0;
  }
}//end space char


//IF RETURN 1 is not a space
int non_space_char(char c) {
  if (c != ' ' && c != '\t') {
    return 1;
  }
  else {
    return 0;
  }
}//end non_space_char


/* Returns a pointer to start of word */
char *word_start(char *str) {
  while(*str) {
    if (non_space_char(*str)) {
      return str;
    }
    str++;
  }
  return str;
}//end *word_start


/* Returns a pointer terminator char following *word */
char *word_terminator(char *word) {
  while(*word) {
    if (space_char(*word)) {
      return word;
    }
    word++;
  }
  return word;
}//end *word_terminator


/* Counts the number of words in the string argument. */
int count_words(char *str) {
  int wordCount = 0;
  while(*str) {
    if(space_char(*str)) {
      wordCount++;
    }
    str++;
  }
  return wordCount += 1;
}//end count_words


/* copying string */
char *copy_str(char *inStr, short len) {
  //Allocating memory
  // copiedStr derefrenced
  int i = 0;
  char *copiedStr = malloc(sizeof(char) * (len+1));
  //copy input
  for (i = 0; i < len; i++) {
    copiedStr[i] = inStr[i];
  }
  copiedStr[i] = 0;
  return copiedStr;
}//end *copy_str


/* find length of word */
int word_length(char *str) {
  int length = 0;
  int i;
  for (i = 0; i < *(str+i) != '\0'; i++) {
    if (non_space_char(*(str+i))) {
      length += 1;
    }
    else {
      break;
    }
  }
  return length;
}//end word_length method

/* Tokenizes string */
char **tokenize(char* str) {
  int num_words = count_words(str);
  char **tokens = malloc((sizeof(char *)) * (num_words+1));
  char *p = str;
  int i;
  for (i = 0; i < num_words; i++) {
    p = word_start(p);
    int length = word_length(p);
    tokens[i] = copy_str(p, length);
    p = word_terminator(p);
  }
  tokens[i] = 0;
  return tokens;
}//end tokenize method


/* Prints all tokens. */
void print_tokens(char **tokens) {
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    printf("%s\n",tokens[i]);
  }
}//end print_tokens method


void free_tokens(char **tokens) {
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    free(tokens[i]);
  }
  free(tokens);
}//end free_tokens
