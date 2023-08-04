#include <stdio.h>
#include <stdlib.h>

int buscaMulti(int m[][2],int x, int n);

int main(){
	int m[2][2]={{2,1},{3,4}};
	printf("%d",buscaMulti(m,12, 2));
	return 0;
}


int buscaMulti(int m[][2],int x, int n){
	int i=0;int j=0;
	if(n>0){
		for(i=0;i<n; i++){
			for(j=0; j<n;j++){
				
				if(m[i][j]==x){
					return 7;
				}
			}
		}
		return -1;
	}
	
}
