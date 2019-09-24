#include "../HeaderFiles/AdminFunctions.h"
#include "../HeaderFiles/SetADT.h"

int AddUser(char username[],char password[]){

  FILE *userFile;

  // open the file
  userFile = fopen("users.dat","a");

  // check whether the file was opened or not
  if(userFile == NULL){
    fprintf(stderr,"\nError opening users from addUser file\n");
    return 0;
  }

  // initialise structures
  user userAdd;

	// define values
	memcpy(userAdd.username,username,20);
	memcpy(userAdd.password,password,20);
	userAdd.password[19] = userAdd.username[19] =0;

  fwrite(&userAdd,sizeof(user),1,userFile);

  if(fwrite == 0){
			printf("error writing users file in addUsers !\n"); 
			return 0;
	}

  // close file 
  fclose (userFile); 

	return 1;
}

