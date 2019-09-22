#include "../HeaderFiles/AdminFunctions.h"


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

int AddProperty(propStrut *propertyDetails){
  FILE *propFile;

  // open the file
  propFile = fopen("users.dat","a");

  // check whether the file was opened or not
  if(propFile == NULL){
    fprintf(stderr,"\nError opening file\n");
    return 0;
  }

  fwrite(propertyDetails,sizeof(propStrut),1,propFile);

  if(fwrite == 0){
			printf("error writing file !\n"); 
			return 0;
	}

  // close file 
  fclose (propFile); 

	return 1;
}