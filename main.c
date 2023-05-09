#include <stdio.h>
#include <string.h>
#define MAX 100

int max(int num1,int num2){
  return(num1 > num2) ? num1 : num2;
}

int LIS(int num[],int i){
  int maior;
  if (i == 0)
    return 1;
  else{
    maior = 1;
    for(int j = 0;j<i;j++){
      if (num[j] < num[i]){
        maior = max(maior,LIS(num,j) + 1);
      }
    }
  }
  return maior;
}

int subsequencia(int num[],int n){
  int maior = 1;
  for(int i =0;i<n;i++)
    maior = max(maior,LIS(num,i));
  return maior;
}

int main() {
  int num[] = {1,3,2,5,4,8,10,16,11,20}, n = 10;
  int maior = subsequencia(num, n);
  printf("\nMaior subsequencia: %i",maior);
}