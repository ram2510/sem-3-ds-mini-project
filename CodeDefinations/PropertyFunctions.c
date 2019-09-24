#include "../HeaderFiles/PropertyFunctions.h"

int AddProperty(propStrut *propertyDetails){

  int isElementAddedToSet = contains(propertyDetails);
  int doesAreaExist=0,isNoOfPropsInc;
  if(isElementAddedToSet)
    return 0;

  FILE *propFile;
  FILE *areaFile;
  area areaDetails;
  // open the file
  propFile = fopen("property.dat","a");
  areaFile = fopen("area.dat","r");
  // check whether the file was opened or not
  if(propFile == NULL && areaFile == NULL){
    fprintf(stderr,"\nError opening file in add property\n");
    return 0;
  }

  while(fread(&areaDetails,sizeof(area),1,areaFile)){
    if(strcmp(areaDetails.name,propertyDetails->area))
      doesAreaExist=1;
  }

  if(!doesAreaExist){
    printf("Area Does not exist");
    return 0;
  }
  isNoOfPropsInc = incrementProps(propertyDetails);
  printf("\naa%d\n",isNoOfPropsInc);
  if(!isNoOfPropsInc){
    return 0;
  }

  fwrite(propertyDetails,sizeof(propStrut),1,propFile);

  if(fwrite == 0){
			printf("error writing file !\n"); 
			return 0;
	}

  // close file 
  fclose (propFile); 
  fclose(areaFile);
  printf("Area Added\n");
	return 1;
}

void displayProperty(char *areaName){

}