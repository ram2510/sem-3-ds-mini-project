#include "../HeaderFiles/PropertyFunctions.h"

int AddProperty(propStrut *propertyDetails){

  int isElementAddedToSet = contains(propertyDetails);

  if(isElementAddedToSet)
    return 0;

  FILE *propFile;

  // open the file
  propFile = fopen("property.dat","a");

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