#include "../HeaderFiles/AuthenticationScreen.h"

int compareAndAuthenticate(char username[],char pass[]){

	int isUserVerified=0;

	// initialise a file pointer 
  FILE *userFile;

	// initilaise a structure
	user userRead;

  // open the file
  userFile = fopen("users.dat","r");

	if(userFile==NULL){
		fprintf(stderr, "\nError opening file\n"); 
		return 0;
	}	

	 // read file contents till end of file 
    while(fread(&userRead, sizeof(user), 1, userFile)) {
			if(!strcmp(userRead.password,pass) && !strcmp(userRead.username,username)) 
				isUserVerified=1;
		}
  
    // close file 
    fclose (userFile); 

		return isUserVerified;
}