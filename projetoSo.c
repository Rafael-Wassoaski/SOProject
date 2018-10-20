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
		fprintf(arquivo,"PID	AT	BT	CT	TAT	WT\n");
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
		fprintf(arquivo,"%d	%d	%d	%d	%d	%d\n",aux2->pid, aux2->at, aux2->bt, aux2->ct, aux2->tat, aux2->wt);
		
	
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
		
		
while(filaInicio != filaFim->prox){

fprintf(arquivo,"P%d|%d ",filaInicio->pid, filaInicio->ct);
filaInicio = filaInicio->prox;
}
	fclose(arquivo);
		
	}
	
	void main(){
		char escalonador[8];
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
		
		if(strcmp(escalonador, "FCFS ")){
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
				
		
		}else if(strcmp(escalonador, "SJF ")){
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
			
		}else if(strcmp(escalonador, "RR ")){
			//RR
		}else if(strcmp(escalonador, "Priority ")){
			//Priority
		}
	
	
	

	

	}
