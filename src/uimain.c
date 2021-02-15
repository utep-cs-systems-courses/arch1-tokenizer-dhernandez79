#include <stdio.h>



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

      for (int i=0; user_input[i]!='\0'; i++) {

	printf("%c", user_input[i]);}



    }

    else if (user_input[0] == 'q') {

      printf("You have exited");

      return 0;

    }

    else {

      printf("Not a valid character, try again");

    }



  }



  return 0;

}
