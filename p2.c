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
	for(i=from;i<=from+numel;i++){
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

float Infininorm( float M[N][N] ){
	int i,j;
	float max=0;
	float max_tmp=0;
	for(i=0;i<N;i++){
		max_tmp=0;
		for(j=0;j<N;j++){
			max_tmp+=fabs(M[i][j]);
	if (max<max_tmp)
		max=max_tmp;

  }
 }
	return max;
}


float Onenorm( float M[N][N] ){
        int i,j;
        float max=0;
        float max_tmp=0;
        for(i=0;i<N;i++){
                max_tmp=0;
                for(j=0;j<N;j++){
                        max_tmp+=fabs(M[j][i]);
        if (max<max_tmp)
                max=max_tmp;
        
  }
 }
        return max;
}

double NormFrobenius( float M[N][N] ){
	int i,j;
	int s;
        for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                        s+=M[i][j]*M[i][j]; // problema con al potencia
			
	}
    }
	return sqrt(s);
}	

int DiagonalDom( float M[N][N] ){
	int i,j;
	float sumd = 0.0;
	float sumn = 0.0;
	 for(i=0;i<N;i++){
                for(j=0;j<N;j++){
			if (i==j){
				sumd+=fabs(M[i][j]);
		        }else{
				sumn+=fabs(M[i][j]);
			}	
		}
	}	
	if (sumd >= sumn){
		return 1;
	}
	else{
  		return 0;
   }	


}


int main(){
	
	int i, j, m, n, x, y, f, g;
	InitData();
	PrintVect(V1,0,10);
	PrintVect(V1,256,10);
	PrintVect(V2,0,10);
	PrintVect(V2,256,10);
	PrintVect(V3,0,10);

	PrintRow(Mat,0,0,10);
 	PrintRow(Mat,100,0,10);

	PrintRow(MatDD,0,0,10);
	PrintRow(MatDD,100,90,10);
	
	i = Infininorm(Mat);
	j = Infininorm(MatDD);	

	m = Onenorm(Mat);
	n = Onenorm(MatDD);

	x = NormFrobenius(Mat);
	y = NormFrobenius(MatDD);
	
	f = DiagonalDom(Mat);
	g = DiagonalDom(MatDD);
	MultEscalar(V2,Vectres,alfa);
	printf("Infininorma de la matriu Mat: %d \n",i);
	printf("Infininorma de la matriu MatDD: %d \n",j);
	printf("Onenorm de la matriu Mat: %d \n",m);
        printf("Onenorm de la matriu MatDD: %d \n",n);
	printf("NormFrobenius de la matriu Mat:%d \n",x);
        printf("NormFrobenius de la matriu MatDD: %d \n",y);
	printf("DiagonalDom de la matriu Mat:%d \n",f);
        printf("DiagonalDom de la matriu MatDD: %d \n",g);
}
