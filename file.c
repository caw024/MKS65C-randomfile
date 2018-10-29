#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("/dev/random", O_RDWR | O_CREAT);

  printf("Generating random values:\n");
  //populate array
  int arr[10];
  int l = read(fd, arr, 10*sizeof(int));
  //Help from Hasif

  //print out value of array
  int n = 0;
  for (n; n<10; n++){
    printf("\t random %d: %d\n",n, arr[n]);
  }

  //problem
  
  //write to array
  int fwd = open("file.txt", O_WRONLY | O_CREAT,777);
  printf("\nWriting to file\n");
  int k = write(fwd,arr,10*sizeof(int));
  int c = close(fwd);

  //read file to different array
  int arr2[10];
  int wfd = open("file.txt", O_RDONLY);
  printf("\nReading the file\n\n");
  int m = read(wfd, arr2, 10*sizeof(int));
  int w = close(wfd);
  

 //print out value of array
  n = 0;
  for (n; n<10; n++){
    printf("\t random %d: %d\n",n, arr2[n]);
  }

}
