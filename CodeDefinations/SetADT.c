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
    printf("\n%s %s %s %s",propDetails->area,setRead.arr[0].area,propDetails->name,setRead.arr[0].name);
    if(!strcmp(propDetails->area,setRead.arr[0].area) && !strcmp(propDetails->name,setRead.arr[0].name)){
      printf("\nProperty already exists\n");
      return 1;
    }
  }
  return 0;
}



void initialise(SetADT *set){
  SetADT setRead;
  FILE *propFile;
  
  propFile = fopen("property.dat","r");

  if(propFile==NULL){
    fprintf(stderr,"\nError opening file\n");
    return;
  }
  int count=0;
  
  while(fread(setRead.arr,sizeof(propStrut),1,propFile)){
    // printf("%s%s",set->arr->area,set->arr->name);

    set->arr[++(set->top)] = *setRead.arr;
  }

}