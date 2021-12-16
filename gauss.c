#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int r = mat->r;
	int c = mat->c;
	if(r<=0||c<=0)
		return -1;
	for(int i = 0; i<c-1;i++){
		for(int j = i+1; j<r; j++){
			if( mat->data[i][i] < 0.0000001)
				return 1;
			double q = mat->data[j][i]/mat->data[i][i];
			for(int k = i; k<r;k++){
				mat->data[j][k] -= q * mat->data[i][k];
			}
			b->data[j][0] -= q*b->data[i][0];
		}
	}
	return 0;
}

