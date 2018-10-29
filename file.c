#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("/dev/random", O_RDWR);

  printf("Generating random values:\n");
  //populate array
  int arr[10];
  read(fd, arr, 10*sizeof(int));
  //Help from Hasif

  //print out value of array
  int n = 0;
  for (n; n<10; n++){
    printf("\t random %d: %d\n",n, arr[n]);
  }
  
  //write to array
  int fwd = open("file.txt", O_RDWR | O_CREAT, 777);
  printf("\nWriting to array\n");
  write(fwd,arr,10*sizeof(int));

  //read file to different array
  int arr2[10];
  printf("\nReading the array\n\n");
  read(fwd, arr2, 10*sizeof(int));

 //print out value of array
  n = 0;
  for (n; n<10; n++){
    printf("\t random %d: %d\n",n, arr2[n]);
  }
  

}
