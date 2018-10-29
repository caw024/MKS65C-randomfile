#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("/dev/random", O_RDWR);

  //populate array
  int arr[10];
  read(fd, arr, 10*sizeof(int));
  //Help from Hasif


  int n = 0;
  for (n; n<10; n++){
    printf("\n%d",arr[n]);
  }
  
  //write to array
 int fwd = open("file.txt", O_CREAT | O_RDWR); 
  write(fwd,arr,10*sizeof(int));
  
}
