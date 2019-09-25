#include "../HeaderFiles/AreaFunction.h"

int containsProperty(area *areaDetails){
  area areaStruct;
  FILE *areaFile;

  areaFile = fopen("area.dat","r");

   if(areaFile==NULL){
    fprintf(stderr,"\nError opening file\n");
    return 0;
  }
  
  while(fread(&areaStruct,sizeof(area),1,areaFile)){
    // printf("\n%s %s",areaDetails->name,areaStruct.name);
    if(!strcmp(areaDetails->name,areaStruct.name) ){
      return 1;
    }
  }

  fclose(areaFile);
  return 0;

}

int AddArea(area *areaDetails){

  if(containsProperty(areaDetails)){
    printf("Area Already present\n");
    return 0;
  }

  FILE *areaFile;

  areaFile = fopen("area.dat","a");

  if(areaFile==NULL){
    fprintf(stderr,"\nError opening area from addProperty file\n");
    return 0;
  }

  fwrite(areaDetails,sizeof(area),1,areaFile);

  if(fwrite==0){
    printf("error writing area file in addProperty !\n"); 
		return 0;
  }

  fclose(areaFile);

  return 1;
}

char* displayAreaAndReturnName(char *areaArr[]){
  // printf("\na\n");
  area areaStruct;
  FILE *areaFile;
  int userAreaChoice;
  int isViewIncremented;

  areaFile = fopen("area.dat","r");

  if(areaFile==NULL){
    fprintf(stderr,"\nError opening in display properties file\n");
    return NULL;
  }
  int count=0;
  while(fread(&areaStruct,sizeof(area),1,areaFile)){
    printf("\n%d) %s\nNumber of views : %d Number of properties available : %d\n",count+1,areaStruct.name,areaStruct.views,areaStruct.noOfPropertiesAvailable);
    areaArr[count] = malloc(strlen(areaStruct.name)+1);
    if(areaArr[count]){
      strcpy(areaArr[(count)++],areaStruct.name);
    }
  }

  // printf("\nb\n");
  

  fclose(areaFile);

  printf("Enter number corresponding to the area in which you would like to add property\n=");
  scanf("%d",&userAreaChoice);

  // printf("\nc\n");
  isViewIncremented= incrementView(areaArr[userAreaChoice-1]);
  if(!isViewIncremented)
    printf("\nError While ncrementingproperty view\n");
  // printf("\nd\n");
  return areaArr[userAreaChoice-1];
    
}

int incrementView(char *areaName){
  area areaStruct,areaDetails;
  FILE *areaFile,*tempFile;

  areaFile = fopen("area.dat","r");
  tempFile = fopen("temp.dat","a");
  if(areaFile==NULL){
    fprintf(stderr,"\nError opening in display properties file\n");
    return 0;
  }
  while(fread(&areaStruct,sizeof(area),1,areaFile)){
    // printf("\n %s\nNumber of views : %d Number of properties available : %d\n",areaStruct.name,areaStruct.views,areaStruct.noOfPropertiesAvailable);
    strcpy(areaDetails.name,areaStruct.name);
    areaDetails.noOfPropertiesAvailable = areaStruct.noOfPropertiesAvailable;

    if(strcmp(areaStruct.name,areaName)!=0){
      
    areaDetails.views = areaStruct.views;

    }else{
      areaDetails.views = areaStruct.views + 1;
    }

    fwrite(&areaDetails,sizeof(area),1,tempFile); 

    if(fwrite==0){
      printf("error writing temo file in deleteProperty !\n"); 
      return 0;
    }
  }
  fclose(areaFile);
  fclose(tempFile);
  remove("area.dat");
  rename("temp.dat","area.dat");
  return 1;
}

int incrementProps(propStrut *propDetails){
  area areaStruct,areaDetails;
  FILE *areaFile,*tempFile;

  areaFile = fopen("area.dat","r");
  tempFile = fopen("temp.dat","a");
  if(areaFile==NULL){
    fprintf(stderr,"\nError opening in display properties file\n");
    return 0;
  }
  while(fread(&areaStruct,sizeof(area),1,areaFile)){
    // printf("\n %s\nNumber of views : %d Number of properties available : %d\n",areaStruct.name,areaStruct.views,areaStruct.noOfPropertiesAvailable);
    strcpy(areaDetails.name,areaStruct.name);
    areaDetails.views = areaStruct.views;

    if(strcmp(areaStruct.name,propDetails->area)!=0){
      
    areaDetails.noOfPropertiesAvailable = areaStruct.noOfPropertiesAvailable;

    }else{
    areaDetails.noOfPropertiesAvailable = areaStruct.noOfPropertiesAvailable + 1;
    }

    fwrite(&areaDetails,sizeof(area),1,tempFile); 

    if(fwrite==0){
      printf("error writing temo file in deleteProperty !\n"); 
      return 0;
    }
  }
  fclose(areaFile);
  fclose(tempFile);
  remove("area.dat");
  rename("temp.dat","area.dat");
  return 1;
}


