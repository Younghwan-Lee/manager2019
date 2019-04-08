#include "user.h"
#include "menu.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  char command[50];
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  int count = load_file(userlist, argv[1]);
  printf("Welcome!!\n");

  while(1){
    if(is_login == 0){
      printf(">");
      scanf("%s", command);
      if(ask_command(is_login, command) == 1){
        if(login(userlist, count) == 1)
          is_login += 1;
        else
          continue;      
      }
      else if(ask_command(is_login, command) == 2){
        join(userlist, count);
        count+=1;
      }
      else if(ask_command(is_login, command) == 3){
        list(userlist, count);
      }
      else if(ask_command(is_login, command) == 4){
        break;
      }
      else
        printf("No such command!\n");
    }
    else if(is_login == 1){
      printf("#");
      scanf("%s", command);
      if(ask_command(is_login, command) == 6){
        printf("Bye!\n");
        is_login -= 1;
      }
      else
        printf("%s\n", command);
    }
  }
  save_file(userlist, count, argv[1]);
  return 0;
}
