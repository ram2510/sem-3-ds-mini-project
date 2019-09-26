#include "../HeaderFiles/PropertyFunctions.h"

int AddProperty(propStrut *propertyDetails){
  // printf("\na\n");
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
    // printf("\n%s %s %d\n",areaDetails.name,propertyDetails->area,strcmp(areaDetails.name,propertyDetails->area));
    if(!strcmp(areaDetails.name,propertyDetails->area)){
      doesAreaExist=1;
      break;
    }
  }
  // printf("\n%d\n",doesAreaExist);
  if(!doesAreaExist){
    printf("Area Does not exist\n");
    fclose (propFile); 
    fclose(areaFile);
    return 0;
  }
  isNoOfPropsInc = incrementProps(propertyDetails);
  // printf("\naa%d\n",isNoOfPropsInc);
  if(!isNoOfPropsInc){
    fclose (propFile); 
    fclose(areaFile);

    return 0;
  
  }

  fwrite(propertyDetails,sizeof(propStrut),1,propFile);

  if(fwrite == 0){
			printf("error writing file !\n"); 
      fclose (propFile); 
      fclose(areaFile);

			return 0;
	}
    // printf("\na\n");

  // close file 
  fclose (propFile); 
  fclose(areaFile);
  printf("property Added\n");
	return 1;
}

void displayPropertyAndDescription(char *areaName){
  // printf("\n%s\n",areaName);
  propStrut propDetails;
  FILE *propFile;
  char *propNameArr[100];
  int userChoice;
  propFile = fopen("property.dat","r");
  if(propFile==NULL){
    fprintf(stderr,"\nError opening in display properties file\n");
    return;
  }
  int count=0;
  // printf("\na\n");
  while (fread(&propDetails,sizeof(propStrut),1,propFile)){
    if(!strcmp(propDetails.area,areaName)){
      printf("\n%d) %s\n",count+1,propDetails.name);
      propNameArr[count] = malloc(strlen(propDetails.name)+1);
      if(propNameArr[count]){
        strcpy(propNameArr[(count)++],propDetails.name);
      }
    }
  }
  rewind(propFile);

  if(!count){
    printf("No property to show\n");
    fclose(propFile);
    return;
  }

  printf("\nEnter choice of property you would wish to see\n=");
  scanf("%d",&userChoice);
  count=0;
  // printf("\nb\n");
  while (fread(&propDetails,sizeof(propStrut),1,propFile)){
    // printf("\n%d %s\n",count,propNameArr[userChoice-1]);
    if(!strcmp(propDetails.name,propNameArr[userChoice-1])){
      printf("\nProperty name : %s",propDetails.name);
      printf("\nProperty area : %s",propDetails.area);
      printf("\nProperty details : %s",propDetails.details);
      printf("\nProperty Owner's name : %s",propDetails.sellerName);
      printf("\nProperty Owner phone number : %s",propDetails.phoneNo);
      printf("\nProperty Price : %s\n",propDetails.price);
      break;
    } 
    count++;
  }
  fclose(propFile);
}

