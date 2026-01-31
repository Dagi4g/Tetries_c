#include <stdio.h>

int main(){
	while (1==1){
	for (int i=0; i<10;i++){
		for (int j=0; j<15;j++){
			if (0==i || 9==i){
				printf("—");
			}
			else {
				if (0==j || 14==j){
					printf("|");
				}
				else {
					printf(" ");
				}

			}

		}
		printf("\n");
	}
	}

	return 0;
}
