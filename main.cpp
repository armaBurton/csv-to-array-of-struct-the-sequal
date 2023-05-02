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
    read = fscanf(file, 
                  "%s, %lf, %lf, %lf",
                  &dirtbikeSpecs[records].name,
                  &dirtbikeSpecs[records].length,
                  &dirtbikeSpecs[records].height,
                  &dirtbikeSpecs[records].weight
                 );
    if (read == 4) records++;

    if(read != 4 && !feof(file)){
      printf("File formate incorrect\n");
      return 1;
    }

    if(ferror(file)){
      printf("Error reading file.\n");
      return 1;
    }

  }while(!feof(file));

  fclose(file);

}