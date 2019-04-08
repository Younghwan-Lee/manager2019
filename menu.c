#include "menu.h"

int ask_command(int is_login, char command[]){
#ifdef DEBUG_MODE
	printf("DEBUG: ask_command()\n");
#endif
  int yes_or_no;
  if(is_login==0){
    if(strcmp(command, "login") == 0)
      yes_or_no = 1;
    else if(strcmp(command, "join") == 0)
      yes_or_no = 2;
    else if(strcmp(command, "list") == 0)
      yes_or_no = 3;
    else if(strcmp(command, "exit") == 0)
      yes_or_no = 4;
    else
      yes_or_no = 5;
  }

  else{
    if(strcmp(command, "logout") == 0)
      yes_or_no = 6;
    else
      yes_or_no = 7;
  }

  return yes_or_no;
}
