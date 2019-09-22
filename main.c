//========================================================================================
/*                                                                                      *
 *                            import essential header files                             *
 *                                                                                      */
//========================================================================================
#include<stdio.h>
#include<string.h>
//########################################################################################

//========================================================================================
/*                                                                                      *
 *                             import user defined functions                            *
 *                                                                                      */
//========================================================================================
#include "./HeaderFiles/AuthenticationScreen.h"
#include "./HeaderFiles/AdminFunctions.h"
#include "./Strutures/UserStruct.h"
//########################################################################################

int main(){
  char isAdminRespo,username[20],password[20];
  int isUserAdminVerfied;

  while(1){
  // ask whether admin or not
	printf("Are You a admin? y/n. \n=");
	scanf("%c",&isAdminRespo);
  if(isAdminRespo=='y' || isAdminRespo=='n')
    break;
  else
    printf("Please enter a Correct response\n");
  }

  if(isAdminRespo=='y'){

    // username prompt
    printf("Enter Username\n=");
    scanf("%s",username);

    // password prompt
    printf("Enter password\n=");
    scanf("%s",password);

    // Authenticate will return 1 or 0
    isUserAdminVerfied = compareAndAuthenticate(username,password);

    if(isUserAdminVerfied){
      user userStruct;

      int actionChoiceResp;

      // store the data
      memcpy(userStruct.username,username,20);
      memcpy(userStruct.password,password,20);
      userStruct.password[19] = userStruct.username[19] = 0;
      printf("Welcome %s what action would you like to perform\n",userStruct.username);

      // infinit loop for admin actions
      while(1){
        printf("1) Add property 2) Search for property 3) Add admin credentials 4) Exit\nEnter corresponding number to the action you would like to perform\n=");
        scanf("%d",&actionChoiceResp);
        if(actionChoiceResp!=1 && actionChoiceResp!=2 && actionChoiceResp!=3 && actionChoiceResp!=4){
          printf("Enter a valid choice");
          continue;
        }

        // for exit action
        if(actionChoiceResp==4){
          break;
        }

        // if the user wants to add another admin
        if(actionChoiceResp==3){
          int isUserAdded;
          printf("Enter username\n=");
          scanf("%s",username);
          printf("Enter Password\n=");
          scanf("%s",password);
          isUserAdded = AddUser(username,password);
          if(isUserAdded==1)
            printf("Admin details added!\n");
        }

        // if the user want to add a property
        if(actionChoiceResp==2){
          
        }

      }

      printf("Bye! %s",userStruct.username);

    }else{
      printf("Invalid username or password\n");
    }
  } 
}