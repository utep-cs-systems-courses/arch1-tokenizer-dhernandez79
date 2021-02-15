/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c) {



  (c == ' '||c == '\t') ? return 1:return 0;



}//end space char





/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c) {



  (c != ' ' && c != '\t') ? return 1:return 0;



}//end non_space_char



/* Returns a pointer to the first character of the next 

   space-separated word in zero-terminated str.  Return a zero pointer if 

   str does not contain any words. */

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

  int counter = 0;

  while(*str) {

    if(space_char(*str)) {

      counter++;

    }

    str++;

  }

  return counter += 1;

}//end count_words
