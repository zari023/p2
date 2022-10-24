#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 512

float Mat[N][N], MatDD[N][N];
float V1[N], V2[N], V3[N], V4[N];
       

void InitData(){
 int i,j;
 srand(8824553);
 for( i = 0; i < N; i++ )
  for( j = 0; j < N; j++ ){
   Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))); 
    if ( (abs(i - j) <= 3) && (i != j))
     MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
    else if ( i == j )
     MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
    else MatDD[i][j] = 0.0;
  }
for( i = 0; i < N; i++ ){
 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0; 
 V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0; 
 V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 }
}


void PrintVect( float vect[N], int from, int numel){
	int i;
	for(i=from;i<=numel;i++){
	printf("%f\n",vect[i]);	
 }
}	
int main(){
	InitData();
	PrintVect(V1,3,10);
}
