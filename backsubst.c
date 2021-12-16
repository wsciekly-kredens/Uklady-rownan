#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
							
	if (mat->r < x->r || mat->r != mat->c ) 
		return 2;
	
	int i;
	int j=mat->c;
	double substract=0;
	for (i = x->r; i>0; i--) 
	{			
		if (mat->data[i][j]=0)
		return 1;
			int m=i;
			int n;	
			for(n= mat->c; mat->data[i][n]!=0; n--)
				{
					substract+=mat->data[i][n]*x->data[m][0];
					m--;		
				}	
			
		x->data[i][0]=(b->data[i][0]-substract)/mat->data[i][j];
	       j--;
		
	}
	return 0;
}


