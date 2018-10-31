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
					}else if(aux->pid < aux2->pid){
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
					}else if(aux->bt == aux2->bt && aux->pid < aux2->pid){
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
	
	
	void priority(processData *inicio, FILE *arquivo, int min, int max){
		int tempo = 0, i;
		processData *aux = inicio, *aux2 = NULL, *filaInicio, *filaFim;
		char how;
		filaInicio = filaFim = NULL;
		arquivo=fopen("resultadoEscalonamento.txt","w");
	
		if(min < max){
			how = '>';
		}else if(min > max){
			how = '<';
		}
			
	
		while(aux->prox != NULL){
		
		while(aux->prox != NULL){
			if(aux->at <= tempo){
		if(aux2 == NULL){
			aux2 = aux;
		
		}
			switch(how){
				
				case '>':
					//quanto maior melhor
					
						if(aux2->priority < aux->priority){
							aux2 = aux;
								
						}else if(aux2->priority == aux->priority && aux2->pid > aux->pid){
							aux2 = aux;
						}
					break;
					case '<':
						//quanto menor melhor
					
						if(aux2->priority > aux->priority){
							aux2 = aux;
						
						}else if(aux2->priority == aux->priority && aux2->pid > aux->pid){
							aux2 = aux;
						}
						break;
			
		}
		
	
	}
	
		if(aux2!=NULL && aux2->bt > 0){
			aux2->bt--;
		}
		if(aux2->bt == 0){
		
	
			if(aux2 == inicio){
				inicio = inicio->prox;
			}else{
			
			aux2->ant->prox = aux2->prox;
			aux2->prox->ant = aux2->ant;
			
			}
			aux2->ct = tempo;
		aux2->tat = abs(aux2->ct - aux2->at);
		aux2->wt = abs(aux2->tat - aux2->bt);
		printf("P%d|%d|", aux2->pid, tempo);
		fprintf(arquivo,"P%d|%d|", aux2->pid, tempo);
		
	
	
		if(filaInicio == NULL){
			filaInicio = filaFim = aux2;
		}else{
			filaFim->prox = aux2;
			filaFim = filaFim->prox;
			
		}
			aux2 = NULL;
		}
		
		
	tempo++;
	
	aux = aux->prox;
	}
	aux = inicio;
}
	aux = inicio;
	while(aux->prox!=NULL){
		printf("%d ",aux->pid);
		aux = aux->prox;
	}
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
