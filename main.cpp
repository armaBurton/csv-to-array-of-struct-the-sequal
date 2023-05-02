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
                  "%s, %lf, %lf, %lf, %lf",
                  dirtbikeSpecs[records].name,
                  &dirtbikeSpecs[records].seatHeight,
                  &dirtbikeSpecs[records].length,
                  &dirtbikeSpecs[records].height,
                  &dirtbikeSpecs[records].weight
                 );
    if (read == 5) records++;

    if(read != 5 && !feof(file)){
      printf("File format incorrect\n");
      return 1;
    }

    if(ferror(file)){
      printf("Error reading file.\n");
      return 1;
    }

  }while(!feof(file));

  fclose(file);

  for (int i = 0; i < records; i++){
    printf("%s, %lf in, %lf in %lf in, %.2lf in\n",
            dirtbikeSpecs[i].name, 
            dirtbikeSpecs[i].seatHeight, 
            dirtbikeSpecs[i].length, 
            dirtbikeSpecs[i].height, 
            dirtbikeSpecs[i].weight 
    );
  }
  printf("\n");

  return 0;
}