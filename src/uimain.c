#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  char user_input[100];
  List *history = init_history();
  printf("Welcome to tokenizer!\n\n");

  while(1) {
    printf("************************");
    printf("\nSelect option below:\n");
    printf("t: Tokenize\nq: Quit program\nh: History\n!#: Specific History\n");
    printf("************************\n> ");
    fgets(user_input,100,stdin); //Getting user_input
    
    if (user_input[0] == 't') {  //enter t to tokenize
      char input[100];
      printf("Enter string below: ");
      fgets(input,100,stdin);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      add_history(history,input);
      free_tokens(tokens);
    }
    else if (user_input[0] == 'h') { //enter h to see history
      print_history(history);
    }
    else if (user_input[0] == '!') { //enter !# to see specific history
      int selection = (int)(user_input[1]) - 48; //using ascii to get int
      char *sel = get_history(history,selection);
      char **tokens = tokenize(sel);
      printf("Selected history: %s\n",sel);
      free_tokens(tokens);
    }
    else if (user_input[0] == 'q') {  //enter q to quit
      printf("You have exited\n");
      return 0;
    }
    else {
      printf("Not a valid character, try again\n");
    }
  }//end while loop
  return 0;
}//end main method
