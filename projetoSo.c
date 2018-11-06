	#include <stdio.h>
	
	struct processData{
	
		int pid;
		int priority;
		int at;
		int bt;
		int wt;
		int ct;
		int tat;
		struct processData *prox, *ant;
		
	} *inicio=NULL, *fim=NULL;
	
	typedef struct processData processData;
	
	
	void fcfs(processData *inicio, FILE *arquivo){
		
		processData *aux=inicio, *aux2, *filaInicio, *filaFim;
		int tempo = 0;
		filaInicio = filaFim = NULL;
		
		
		arquivo=fopen("resultadoEscalonamento.txt","w");
		
	int i;
		
		while(aux->prox!=NULL){
		
			aux2 = NULL;
			while(aux->prox!=NULL){
				
			if(aux->at <= tempo){
			
				if(aux2!=NULL){
					if(aux->at < aux2->at){
						aux2 = aux;
					}else if(aux->pid < aux2->pid && aux->at == aux2->at){
						aux2 = aux;
					}
					
					
				}else{
					aux2 = aux;
				}
			}
			
				aux = aux->prox;
			}
			
			if(aux2==NULL){
			tempo++;
		}else{
		
		tempo += aux2->bt;
		aux2->ct = tempo;
		aux2->tat = abs(aux2->ct - aux2->at);
		aux2->wt = abs(aux2->tat - aux2->bt);
		printf("P%d|%d|", aux2->pid, tempo);
		fprintf(arquivo,"P%d|%d|", aux2->pid, tempo);
		
	
		if(aux2 == inicio){
			
			inicio = inicio->prox;
		}else{
			aux2->ant->prox = aux2->prox;
			aux2->prox->ant = aux2->ant;
		}
		if(filaInicio == NULL){
			filaInicio = filaFim = aux2;
		}else{
			filaFim->prox = aux2;
			filaFim = filaFim->prox;
			
		}
	
		
		
		
		}
		
		aux = inicio;
	}
	
 fprintf(arquivo,"\n\n");
 printf("\n\n");
 fprintf(arquivo,"PID	AT	BT	CT	TAT	WT\n");
 printf("PID	AT	BT	CT	TAT	WT\n");
		
while(filaInicio != filaFim->prox){
		printf("%d	%d	%d	%d	%d	%d\n",filaInicio->pid, filaInicio->at, filaInicio->bt, filaInicio->ct, filaInicio->tat, filaInicio->wt);
		fprintf(arquivo,"%d	%d	%d	%d	%d	%d\n",filaInicio->pid, filaInicio->at, filaInicio->bt, filaInicio->ct, filaInicio->tat, filaInicio->wt);


filaInicio = filaInicio->prox;
}
	fclose(arquivo);
		
	}
	
	
		void sjf(FILE *arquivo, processData *inicio){
		processData *aux=inicio, *aux2, *filaInicio, *filaFim;
		int tempo = 0;
		filaInicio = filaFim = NULL;
		
		
		arquivo=fopen("resultadoEscalonamento.txt","w");
	
	int i;
	
		
		while(aux->prox!=NULL){

			aux2 = NULL;
			while(aux->prox!=NULL){
				
			if(aux->at <= tempo){
			
				if(aux2!=NULL){
					if(aux->bt < aux2->bt){
						aux2 = aux;
					}else if(aux->at < aux2->at){
						aux2 = aux;
					
					}else if(aux->bt == aux2->bt && aux->at < aux2->at){
						aux2 = aux;
					}else if (aux->at == aux2->at && aux->pid < aux2->pid){
						aux2 = aux;
					}
					
					
				}else{
					aux2 = aux;
				}
			}
			
				aux = aux->prox;
			}
			
			if(aux2==NULL){
			tempo++;
		}else{
		
		tempo += aux2->bt;
		aux2->ct = tempo;
		aux2->tat = abs(aux2->ct - aux2->at);
		aux2->wt = abs(aux2->tat - aux2->bt);
		printf("P%d|%d|", aux2->pid, tempo);
		fprintf(arquivo,"P%d|%d|", aux2->pid, tempo);
		
	
		if(aux2 == inicio){
			
			inicio = inicio->prox;
		}else{
			aux2->ant->prox = aux2->prox;
			aux2->prox->ant = aux2->ant;
		}
		if(filaInicio == NULL){
			filaInicio = filaFim = aux2;
		}else{
			filaFim->prox = aux2;
			filaFim = filaFim->prox;
			
		}
	
		
		
		
		}
		
		aux = inicio;
	}
	

fprintf(arquivo,"\n\n");
 printf("\n\n");
 fprintf(arquivo,"PID	AT	BT	CT	TAT	WT\n");
 printf("PID	AT	BT	CT	TAT	WT\n");
		
while(filaInicio != filaFim->prox){
		printf("%d	%d	%d	%d	%d	%d\n",filaInicio->pid, filaInicio->at, filaInicio->bt, filaInicio->ct, filaInicio->tat, filaInicio->wt);
		fprintf(arquivo,"%d	%d	%d	%d	%d	%d\n",filaInicio->pid, filaInicio->at, filaInicio->bt, filaInicio->ct, filaInicio->tat, filaInicio->wt);


filaInicio = filaInicio->prox;
}
	fclose(arquivo);
		
	}
	
	
	
	void rr(processData *inicio, int quantum, FILE *arquivo){
		processData *aux = inicio, *aux2 , *filaInicio, *filaFim, *liga = NULL, *filaEscrita = NULL, *filaEscritaFim;
		int tempo = 0, i;
		filaInicio = filaFim = NULL;
			
		arquivo=fopen("resultadoEscalonamento.txt","w");
//for(i=0;i<2;i++){
//		while(aux->prox != NULL){
//		
//			
//				if(aux->at <= tempo){
//					if(filaInicio == NULL){
//						filaFim = filaInicio = aux;
//					
//					}else{
//						
//						filaFim->prox = aux;
//						aux2 = aux->ant;
//						aux->ant = filaFim;
//						filaFim = filaFim->prox;
//						
//					
//					}
//						if(aux == inicio && aux->prox != NULL){
//							
//							inicio = inicio->prox;
//						
//						}else if(aux->prox != NULL){
//					
//							aux->prox->ant = aux2;
//						aux2->prox = aux->prox;
//						
//						}
//				}
//					
//				aux = aux->prox;
//				filaFim->prox = NULL;
//					
//			}
//			aux = filaInicio;
//			while(aux!= NULL){
//				printf("%d ", aux->pid);
//				aux = aux->prox;
//			}
//	
//		
////			if(filaInicio == NULL){
////				filaInicio = liga;
////			}else if(liga != NULL){
////				filaFim->prox = liga;
////			}
////				aux2 = filaInicio;
////			
////				
////				
////				while(aux2 != NULL){
////			
////						if(aux2->bt <= quantum){
////								tempo = tempo + aux2->bt;
////							aux2->bt = 0;
////							
////							
////						}else{
////								tempo = tempo + quantum;
////							aux2->bt -= quantum;
////						
////						
////						}
////						
////						if(aux2->bt == 0){
////					
////								if(aux2 == filaInicio){
////			
////									filaInicio = filaInicio->prox;
////							}else{
////								aux2->ant->prox = aux2->prox;
////								aux2->prox->ant = aux2->ant;
////								}
////								
////								if(filaEscrita == NULL){
////							filaEscrita = filaEscritaFim = aux2;
////						}else{
////							filaEscritaFim->prox = aux2;
////							filaEscritaFim = filaEscritaFim->prox;
////							
////							}
////							
////						}
////				
////					
////							printf("P%d|%d|", aux2->pid, tempo);
////							fprintf(arquivo,"P%d|%d|", aux2->pid, tempo);
////						
////					aux2 = aux2->prox;
////				}
////		
////				
////			liga = filaInicio;
////			filaInicio = filaFim = NULL;
////			aux = inicio;
//		
//		
		
		
			
		fclose(arquivo);
					
			
//			while(filaInicio->prox != NULL){
//				printf("%d ",filaInicio->pid);
//				filaInicio = filaInicio->prox;
//			}
		
		
	}

	
	
	void priority(processData *inicio, FILE *arquivo, int min, int max){
		int tempo = 0, i=0;
		processData *aux = inicio, *aux2 = NULL, *aux3 = NULL,*filaInicio, *filaFim;
		char how;
		filaInicio = filaFim = NULL;
		arquivo=fopen("resultadoEscalonamento.txt","w");
	
		if(min < max){
			how = '>';
		}else if(min > max){
			how = '<';
		}
			
	
	while(aux->prox !=NULL){
		if(aux2 != NULL){
			aux3 = aux2;
		}
	
	while(aux->prox != NULL){
		
		if(aux->at <= tempo){
	
			if(aux2 == NULL){	
				aux2 = aux;
			
			}else{
			
			switch(how){
				case '<':
					//quanto menor mais prioritario
		
					if(aux->priority < aux2->priority){
								
						aux2 = aux;
					}else if(aux->priority == aux2->priority && aux->at < aux2->at){
						aux2 = aux;
					}else if (aux->at == aux2->at && aux->pid < aux2->pid){
						aux2 = aux;
					}
					break;
					
					case'>':
				
						//quanto maior mais prioritario
							if(aux->priority > aux2->priority){
					
						
						aux2 = aux;
					}else if(aux->priority == aux2->priority && aux->at < aux2->at){
						aux2 = aux;
					}else if (aux->at == aux2->at && aux->pid < aux2->pid){
						aux2 = aux;
					}
						break;
			}
			
			
		}
		
	
		
	
		}
	
		aux = aux->prox;
			
}

if(aux3 != aux2 && aux3!=NULL && aux3->bt > 0 && aux2!=NULL){

		printf("P%d|%d|", aux3->pid, tempo);
		fprintf(arquivo,"P%d|%d|", aux3->pid, tempo);
}



tempo++;
	

	if(aux2 != NULL){
	if(aux2->bt > 0){
		aux2->bt--;
	
	}
	

	 if(aux2->bt == 0){
		
		aux2->ct = tempo;
		aux2->tat = abs(aux2->ct - aux2->at);
		aux2->wt = abs(aux2->tat - aux2->bt);
	printf("P%d|%d|", aux3->pid, tempo);
		fprintf(arquivo,"P%d|%d|", aux3->pid, tempo);
		
		if(aux2 == inicio){
			
			inicio = inicio->prox;
		}else{
			aux2->ant->prox = aux2->prox;
			aux2->prox->ant = aux2->ant;
		}
		if(filaInicio == NULL){
			filaInicio = filaFim = aux2;
		}else{
			filaFim->prox = aux2;
			filaFim = filaFim->prox;
			
		}
		
		aux2 = NULL;
	

}

}

aux = inicio;
}


printf("\n");

//
//	aux = inicio;
//	while(aux->prox!=NULL){
//		printf("%d ",aux->pid);
//		aux = aux->prox;
//	}
	close(arquivo);
		
	}
	
	void main(){
		char escalonador[10];
		int quantum;
		int minPrio;
		int maxPrio;
		int cont;
	FILE *arquivo;
	
	
	arquivo=fopen("arquivoGerado.txt", "r");
	

	
	

	inicio = fim = malloc(sizeof(processData));
	inicio->prox=NULL;
	inicio->ant=NULL;
	
		fscanf(arquivo,"%s", &escalonador);
	
		
		if(strcmp(escalonador, "FCFS") == 0){
			//fcfs
		
			do{
				fscanf(arquivo,"%d ", &fim->pid);
				fscanf(arquivo,"%d ", &fim->at);
				fscanf(arquivo,"%d ", &fim->bt);
			
				
				fim->prox=malloc(sizeof(processData));
				fim->prox->ant=fim;
				fim=fim->prox;
				fim->prox=NULL;

			}while(!feof(arquivo));
				fclose(arquivo);
			
			fcfs(inicio, arquivo);
				
		
		}else if(strcmp(escalonador, "SJF") == 0){
			//sjf

			do{
				fscanf(arquivo,"%d ", &fim->pid);
				fscanf(arquivo,"%d ", &fim->at);
				fscanf(arquivo,"%d ", &fim->bt);
			
				
				fim->prox=malloc(sizeof(processData));
				fim->prox->ant=fim;
				fim=fim->prox;
				fim->prox=NULL;

			}while(!feof(arquivo));
				fclose(arquivo);
				sjf(arquivo, inicio);
			
		}else if(strcmp(escalonador, "RR") == 0){
			//RR
			
			fscanf(arquivo, "%d", &quantum);
			
		
			
			do{
				fscanf(arquivo,"%d ", &fim->pid);
				fscanf(arquivo,"%d ", &fim->at);
				fscanf(arquivo,"%d ", &fim->bt);
			
				
				fim->prox=malloc(sizeof(processData));
				fim->prox->ant=fim;
				fim=fim->prox;
				fim->prox=NULL;

			}while(!feof(arquivo));
				fclose(arquivo);
				
				rr(inicio, quantum, arquivo);
				
		
		}else if(strcmp(escalonador, "Priority") == 0){
			//Priority
			
				fscanf(arquivo,"%d ", &maxPrio);
				fscanf(arquivo,"%d ", &minPrio);
				
				do{
				fscanf(arquivo,"%d ", &fim->pid);
				fscanf(arquivo,"%d ", &fim->at);
				fscanf(arquivo,"%d ", &fim->priority);
				fscanf(arquivo,"%d ", &fim->bt);
			
				
				fim->prox=malloc(sizeof(processData));
				fim->prox->ant=fim;
				fim=fim->prox;
				fim->prox=NULL;

			}while(!feof(arquivo));
				fclose(arquivo);
		
				priority(inicio, arquivo, minPrio, maxPrio);
		
		}
	
	
	
	fclose(arquivo);
	

	}
