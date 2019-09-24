#include "../HeaderFiles/SetADT.h"

int contains(propStrut *propDetails){
  
  SetADT setRead;
  FILE *propFile;
  
  propFile = fopen("property.dat","r");

  if(propFile==NULL){
    fprintf(stderr,"\nError opening file\n");
    return 0;
  }
  int count=0;
  
  while(fread(setRead.arr,sizeof(propStrut),1,propFile)){
    if(!strcmp(propDetails->area,setRead.arr[0].area) && !strcmp(propDetails->name,setRead.arr[0].name)){
      printf("\nProperty already exists\n");
      return 1;
    }
  }
  return 0;
}
