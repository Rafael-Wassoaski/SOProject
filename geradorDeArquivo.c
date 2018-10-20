#include <stdio.h>

void main(){
	
	int valor[3];
	int algoritmo;
	int coringa;
	FILE *arquivo;
	int cont, cont2=0;
	printf("Escolha o algoritmo: \nDigite 1 para FCFS\n 2 para SJF\n 3 para RR\n 4 para Priority: ");
	scanf("%d", &algoritmo);
	arquivo=fopen("arquivoGerado.txt","w");
	if(algoritmo < 3 && algoritmo > 0){


		if(algoritmo==1){
			fprintf(arquivo,"FCFS\n");
		}else{
			fprintf(arquivo, "SJF\n");
		}
		do{
			printf("Digite o tempo de chegada (AT) e o tempo de CPU (BT): ");
			
			

			for(cont=0;cont<2;cont++){

			scanf("%d",&valor[cont]);
			}
				if(valor[1] > 0){
			if(valor[1]!= 0){

				fprintf(arquivo, "%d ", cont2 );

				for (cont = 0; cont < 2; cont++){

					fprintf(arquivo,"%d ", valor[cont]);

				}

				fprintf(arquivo, "\n");

			}
			cont2++;
		}
		}while(valor[0]!= 0 || valor[1]!= 0 );
		
	}else if(algoritmo <= 4){
			
			if(algoritmo==3){
							fprintf(arquivo,"RR\n");
							printf("Digite o valor do Quantum: ");
							scanf("%d", &coringa);	
							fprintf(arquivo,"%d\n", coringa);
			}else{
							fprintf(arquivo,"Priority\n");
							printf("Digite o maior valor de prioridade: ");
							scanf("%d", &coringa);	
							fprintf(arquivo,"%d ", coringa);
							printf("Digite o menor valor de prioridade: ");
							scanf("%d", &coringa);	
							fprintf(arquivo,"%d\n", coringa);
			}

			do{
						if(algoritmo==3){
												
							printf("Digite o tempo de chegada (AT), o Tempo de Chegada e o tempo de CPU (BT): ");
					}else {
								
							printf("Digite o tempo de chegada (AT), a Prioridade e o tempo de CPU (BT): ");			
					}
			for(cont=0;cont<3;cont++){

			scanf("%d",&valor[cont]);
			}

			if(valor[1]!= 0){

				fprintf(arquivo, "%d ", cont2 );

				for (cont = 0; cont < 3; cont++){

					fprintf(arquivo,"%d ", valor[cont]);

				}

				fprintf(arquivo, "\n");

			}
			cont2++;
		}while(valor[0]!= 0 || valor[1]!= 0 );
		
		
	}
	fclose(arquivo);

}
