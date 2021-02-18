#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  char user_input[100];
  
  while(1) {
    printf("\nSelect option below:\n");
    printf("t: Tokenize\nq: Quit program\nh: History\n");
    printf("> ");
    fgets(user_input,100,stdin); //Getting user_input
    
    if (user_input[0] == 't') {
      printf("Enter string below: ");
      fgets(user_input,100,stdin);
      char **tokens = tokenize(user_input);
      print_tokens(tokens);
    }
    else if (user_input[0] == 'q') {
      printf("You have exited");
      return 0;
    }
    else {
      printf("Not a valid character, try again");
    }
  }//end while loop

  return 0;

}//end main
