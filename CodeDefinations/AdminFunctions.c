#include "../HeaderFiles/AdminFunctions.h"

//a struct to handle user data
typedef struct   
{ 
    char username[20];
    char password[20]; 
}user; 

int AddUser(char username[],char password[]){

  FILE *userFile;
  // open the file
  userFile = fopen("users.dat","a");

  // check whether the file was opened or not
  if(userFile == NULL){
    fprintf(stderr,"\nError opening file\n");
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
			printf("error writing file !\n"); 
			return 0;
	}

  // close file 
  fclose (userFile); 

	return 1;
}
