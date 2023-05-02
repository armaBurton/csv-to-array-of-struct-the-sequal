#include <iostream>
#include "./data/dirtbikeSpecs/dirtbikeSpecs.h"

int main(void){
  FILE *file;

  file = fopen("./data/dirtbikeSpecs/dirtbikeData.txt", "r");

  if (file == NULL){
    printf("Error opening file.\n");
  }

  DirtbikeSpecs dirtbikeSpecs[100];

  int read = 0,
      records = 0;
    
  do{
    

  }while(!feof(file));


}