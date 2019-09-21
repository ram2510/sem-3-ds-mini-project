#include "../HeaderFiles/AuthenticationScreen.h"

// a struct to read and write 
typedef struct   
{ 
    char username[20];
    char password[20]; 
}user; 
  

int Authenticate(){
	int isAuthenticated;
	isAuthenticated = compareAndAuthenticate("Ram","a");
	printf("\n%d",isAuthenticated);
}

int AddUser(char username[],char password[]){
  // initialise a file pointer 
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

int compareAndAuthenticate(char username[],char pass[]){

	int isUserVerifeid=0;

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
				isUserVerifeid=1;
			
		}
  
    // close file 
    fclose (userFile); 

		return isUserVerifeid;
}