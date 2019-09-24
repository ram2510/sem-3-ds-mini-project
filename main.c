//========================================================================================
/*                                                                                      *
 *                            import essential header files                             *
 *                                                                                      */
//========================================================================================
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//########################################################################################

//========================================================================================
/*                                                                                      *
 *                             import user defined functions                            *
 *                                                                                      */
//========================================================================================
#include "./HeaderFiles/AuthenticationScreen.h"
#include "./HeaderFiles/AdminFunctions.h"
#include "./HeaderFiles/SetADT.h"
#include "./HeaderFiles/AreaFunction.h"
#include "./HeaderFiles/PropertyFunctions.h"
//########################################################################################

//========================================================================================
/*                                                                                      *
 *                                   import structures                                  *
 *                                                                                      */
//========================================================================================
#include "./Strutures/UserStruct.h"
#include "./Strutures/SetStruct.h"
#include "./Strutures/AreaStructure.h"
//########################################################################################

// void clear(){
//     #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
//         system("clear");
//     #endif

//     #if defined(_WIN32) || defined(_WIN64)
//         system("cls");
//     #endif
// }

int main(){
  char isAdminRespo,username[20],password[20],*areaArr[100];
  int isUserAdminVerfied,actionChoiceResp,isPropAdded,isUserAdded;
  user userStruct;
  propStrut propDetails;
  area areaDetails;
  
  while(1){
  // ask whether admin or not
	printf("Are You a admin? y/n.\n=");
	scanf("%c",&isAdminRespo);
  
  isAdminRespo=tolower(isAdminRespo);
  if(isAdminRespo=='y' || isAdminRespo=='n')
    break;
  else
    printf("Please enter a Correct response\n\n");
  
  }

  if(isAdminRespo=='y'){


    // username prompt
    printf("Enter Username\n=");
    scanf("%s",userStruct.username);

    // password prompt
    printf("Enter password\n=");
    scanf("%s",userStruct.password);

    // Authenticate will return 1 or 0
    isUserAdminVerfied = compareAndAuthenticate(userStruct.username,userStruct.password);

    if(isUserAdminVerfied){

      printf("\nWelcome %s what action would you like to perform\n\n",userStruct.username);

      // infinit loop for admin actions
      while(1){

        // clear();

        printf("1) Add property 2) Search for property 3) Add admin credentials 4) Add area 5) Exit\nEnter corresponding number to the action you would like to perform\n=");
        scanf("%d",&actionChoiceResp);
        if(actionChoiceResp!=1 && actionChoiceResp!=2 && actionChoiceResp!=3 && actionChoiceResp!=4 && actionChoiceResp!=5){
          printf("Enter a valid choice\n");
          continue;
        }

        // for exit action
        if(actionChoiceResp==5){
          break;
        }

        if(actionChoiceResp==4){
          printf("Enter area name\n=");
          scanf("%s",areaDetails.name);
          areaDetails.noOfPropertiesAvailable = 0;
          areaDetails.views = 0;
          isPropAdded=AddArea(&areaDetails);
          // printf("\n%d\n",isPropAdded);
        }

        // if the user wants to add another admin
        if(actionChoiceResp==3){
          
          printf("Enter username\n=");
          scanf("%s",username);
          printf("Enter Password\n=");
          scanf("%s",password);
          isUserAdded = AddUser(username,password);
          if(isUserAdded==1)
            printf("Admin details added!\n");
        }

        if(actionChoiceResp==2){
          char* test = displayAreaAndReturnName(areaArr);
          printf("%s\n",test);
        }

        // if the user want to add a property
        if(actionChoiceResp==1){

          printf("Enter name of property\n=");
          scanf("%s",propDetails.name);
        
          printf("Enter details/description of property\n=");
          scanf("%s",propDetails.details);

          printf("Enter name of property owner\n=");
          scanf("%s",propDetails.sellerName);

          printf("Enter phone number of property seller\n=");
          scanf("%s",propDetails.phoneNo);  

          printf("Enter the area of property\n=");
          scanf("%s",propDetails.area);    

          printf("Enter price of property\n=");
          scanf("%s",propDetails.price);

          isPropAdded = AddProperty(&propDetails);

          if(isPropAdded)
            printf("property details Added!\n");
          else
            printf("Failed to add property details\n");
        }

      }

      printf("Bye ! %s",userStruct.username);

    }else{
      printf("Invalid username or password\n");
    }
  } 
}