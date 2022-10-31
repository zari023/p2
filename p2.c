#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 512

float Mat[N][N], MatDD[N][N];
float V1[N], V2[N], V3[N], V4[N];
float Vectres[N];       
float alfa =10.0;

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

void PrintRow( float mat[N][N], int row, int from, int numel){
	int i;
	for(i=from;i<=numel;i++){
	printf("%f\n",mat[row][i]);
 }
}	

void MultEscalar( float vect[N], float vectres[N], float alfa ){
	int i;
	//scanf("%f\n", &alfa);
	for(i=0;i<N;i++){
		vectres[i] = vect[i] * alfa;
		//printf("%f\n",vectres[i]);
 }
}

float Scalar( float vect1[N], float vqct2[N] ){
	int i;
	float prod = 0.0;
	for(i=0;i<N;i++){
	prod += vect1[i]*vqct2[i];
	}
	return prod;
}	

float Magnitude( float vect[N] ){
	int i;
	float vmag = 0.0;
	for(i=0;i<N;i++){
	vmag += vect[i]*vect[i];
	}
	return vmag;
}

int Ortogonal( float vect[N], float vect2[N] ){
	int i; 
	float result;
	result = Scalar(vect, vect2);
	if( result == 0 ){
	return 1;
	}
	else{
	return 0;
	}
}

void Projection( float vect1[N], float vect2[N], float vectres[N] ){
	int rort, rmag, rdiv, resc, i;
	/*for(i=0;i<N;i++){
	rort=Ortogonal(float vect1[i], vect2[i]);
	rmag=Magnitude(float vect2[i]);
	rdiv=rort/rmag;
	resc=Scalar(vect1[i],vect2[i]);
	vectres[i]=resc*/

	MultEscalar( vect2, vectres, Scalar(vect1, vect2) );
	for(i=0;i<N;i++){
	vectres[i]=vectres[i]/Magnitude(vect2);
	}
}



int main(){
	InitData();
	PrintVect(V1,3,10);
	PrintRow(Mat,1,3,10);
	MultEscalar(V2,Vectres,alfa);
	

}
