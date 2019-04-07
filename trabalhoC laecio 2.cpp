#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max_lista 5

struct t_filmes{
	char titulo[20], genero[20],diretor[20],ator_p[30],idioma[15];
	int duracao;
};
struct lista{
	int fim;
	t_filmes filme[max_lista];
};

lista f;
void inicializacao(){
	f.fim= -1;
}
bool listacheia(){
	return (f.fim==max_lista - 1);
}
bool listavazia(){
	return (f.fim== -1);
}
void destruicao(){
	if(listavazia()){
		printf("\n\n Lista Vazia\n\n");
	}
	else{
		f.fim= -1;
		printf("\n\n Lista destruida \n\n ");
	}
	system ("pause");
}
void tamanho(){
	if(listavazia()){
		printf("\n\n Lista Vazia \n\n");
	}
	else{
		printf("\n Tamanho da lista : %d \n", f.fim+1);
	}
	system("pause");
}
void primeiro(){
	if(listavazia()){
		printf("\n\n Lista Vazia \n\n");
	}
	else{
		printf("\n Titulo do primeiro filme : %s \n",f.filme[0].titulo);		
	    printf("\n Genero do  primeiro filme: %s ",f.filme[0].genero);
		printf("\n diretor (a) do  primeiro filme: %s ",f.filme[0].diretor);
		printf("\n Ator ou atriz principal do primeiro filme: %s ",f.filme[0].ator_p);
		printf("\n Idioma do primeiro filme: %s ",f.filme[0].idioma);
		printf("\n Duracao do  primeiro filme: %d  minutos" ,f.filme[0].duracao);
		printf("\n=======================================================\n"); 
		
	}
	system("pause");
}
void ultimo(){
	if(listavazia()){
		printf("\n\n Lista Vazia \n\n");
	}
	else{
		printf("\n\n Titulo do ultimo filme: %s \n", f.filme[f.fim].titulo);		
	   	printf("\n Genero do ultimo  filme: %s ",f.filme[f.fim].genero);
	   	printf("\n diretor (a) do ultimo  filme: %s ",f.filme[f.fim].diretor);
	   	printf("\n Ator ou atriz principal do ultimo  filme: %s ",f.filme[f.fim].ator_p);
	   	printf("\n Idioma do ultimo  filme: %s ",f.filme[f.fim].idioma);
	  	printf("\n Duracao do ultimo filme: %d  minutos" ,f.filme[f.fim].duracao);
	    printf("\n======================================================="); 
	}
	system("pause");
	
}
bool pesquisa(char t[50]){

	int i,posicao = -1;
	for(i=0;i<= f.fim; i = i + 1){
	
		if(strcmp( t , f.filme[i].titulo)==0  ){
		
			posicao=i;			
		}		
	}
	
    if (posicao!= -1)
       return true;   	
		
	else
		return false;

}
void mostrarlista(){
	int i;
	if(listavazia()){
		printf("\n\n Lista Vazia \n\n");
	}
	else{
		printf("\n\n Lista de filmes \n\n");
		for (i=0;i<=f.fim;i=i+1){
			printf("\n Titulo do filme: %s ",f.filme[i].titulo);
			printf("\n Genero do filme: %s ",f.filme[i].genero);
			printf("\n Diretor (a) do filme: %s ",f.filme[i].diretor);
			printf("\n Ator ou atriz principal do filme: %s ",f.filme[i].ator_p);
			printf("\n Idioma do filme: %s ",f.filme[i].idioma);
			printf("\n Duracao do filme: %d  minutos" ,f.filme[i].duracao);
			 printf("\n==================================================\n");  
			
		}
	}
	system("pause");
}
void insercao_final () {
     int i;
     char e[50];
     if (listacheia()) {
        printf("\n\nLista cheia\n");                                                            
     }
     else {
          printf("\n\n Titulo do filme: ");
          scanf("%s",&e);
		   if (pesquisa(e)) {
             printf("\n O filme ja esta cadastrado na lista\n");        
          }       
        
          else { 
		     f.fim++;			  
			 strcpy( f.filme[f.fim].titulo , e);                       
			  printf("\n\nGenero: ");
          	  scanf("%s", &f.filme[f.fim].genero);
          	  printf("\n\nDiretor (a): ");
          	  scanf("%s", &f.filme[f.fim].diretor);
          	  printf("\n\nAtor / Atriz  principal :");
          	  scanf("%s",&f.filme[f.fim].ator_p);
          	  printf("\n\nIdioma:");
          	  scanf("%s",&f.filme[f.fim].idioma);
          	  printf("\n\n Duracao:");
          	  scanf("%i",&f.filme[f.fim].duracao);
          	  printf("\nInclusao realizada  com sucesso.\n\n");
          }
          
     }
     
     system("pause");
}


void insercao_pos () {
     int pos;
     char titulo_filme[20];
     if (listacheia()) {
        printf("\n\nLista cheia\n");                                                            
     }
     else {
          printf("\nDigite a Posicao em que deseja realizar uma insercao : ");
          scanf("%i", &pos);
          if ((pos > f.fim + 1 ) || (pos < 0)) {
             printf("\nPosicao invalida\n"); 
			            
          }
          else {
          	   printf("\n\nTitulo do filme: ");
          	   scanf("%s", &titulo_filme);
               if (pesquisa(titulo_filme)) {
                  printf("\n O filme jah estar cadastrado na lista\n");        
               }
               else {
               		//movimentação para a direita
                   	for (int i = f.fim; i >= pos; i--){
                        strcpy (f.filme[i+1].titulo , f.filme[i].titulo);
                        strcpy(f.filme[i+1].genero , f.filme[i].genero);
                        strcpy( f.filme[i+1].diretor , f.filme[i].diretor);
                        strcpy( f.filme[i+1].ator_p , f.filme[i].ator_p);
                        strcpy( f.filme[i+1].idioma , f.filme[i].idioma);
                        f.filme[i+1].duracao= f.filme[i].duracao;
                        
                   	}
                    strcpy(f.filme[pos].titulo , titulo_filme);
                    printf("\n\nGenero: ");
          	  		scanf("%s", &f.filme[pos].genero);
          	  		printf("\n\nDiretor (a): ");
          	  		scanf("%s", &f.filme[pos].diretor);
          	  		printf("\n\nAtor / Atriz  principal :");
          	  		scanf("%s",&f.filme[pos].ator_p);
          	  		printf("\n\nIdioma:");
          	  		scanf("%s",&f.filme[pos].idioma);
          	  		printf("\n\n Duracao:");
          	  		scanf("%i",&f.filme[pos].duracao);
                    f.fim++;
                    printf("\nInclusao efetuada com sucesso.\n");
               }
          }
     }
     system("pause");
}

void remocao_final(){//remocao do final da lista
	if(listavazia()){
		printf("\n\nA lista estar vazia \n ");
	}
	else{
		char escolha[10];
	    	printf("\n Titulo do filme: %s ",f.filme[f.fim].titulo);
			printf("\n Genero do filme: %s ",f.filme[f.fim].genero);
			printf("\n Diretor (a) do filme: %s ",f.filme[f.fim].diretor);
			printf("\n Ator ou atriz principal do filme: %s ",f.filme[f.fim].ator_p);
			printf("\n Idioma do filme: %s ",f.filme[f.fim].idioma);
			printf("\n Duracao do filme: %d  minutos" ,f.filme[f.fim].duracao);
			 printf("\n========================");  
		    printf("Tem certeza que deseja eliminar esse registro? -digite  sim/nao\n\n");
		    scanf("%s",&escolha);
		    if(strcmp(escolha,"sim")==0){
		    	f.fim--;
		    	printf("\n\nO elemento foi eliminado com sucesso \n");
			}		
	}
	system("pause");	
}

void remocao_pos(){//remocao em uma determinada posicao
	int pos;
	
	if(listavazia()){
		printf("\n\n A lista estah vazia ");
	}
	
	else{
		printf("\n\n digite  a posicao que deseja realizar uma remocao \n ");
		scanf("%i",&pos);
		if ((pos > f.fim + 1 ) || (pos < 0)) {
             printf("\nPosicao invalida\n"); 
			            
          }
         else{//movimentacao para esquerda
            char escolha[10];         
            
           	printf("\n Titulo do filme: %s ",f.filme[pos].titulo);
			printf("\n Genero do filme: %s ",f.filme[pos].genero);
			printf("\n Diretor (a) do filme: %s ",f.filme[pos].diretor);
			printf("\n Ator ou atriz principal do filme: %s ",f.filme[pos].ator_p);
			printf("\n Idioma do filme: %s ",f.filme[pos].idioma);
			printf("\n Duracao do filme: %d  minutos" ,f.filme[pos].duracao);
		    printf("\n=====================================================\n"); 			 
		    printf("\n\nVoce deseja realmente realizar a remocao desse registro? - digite sim/nao\n\n");
            scanf("%s",&escolha);            
            if(strcmp(escolha,"sim")==0){
            	f.fim--;          	
            
         	for(int i=pos;i<= f.fim;i++){
         		strcpy(f.filme[i].ator_p,f.filme[i+1].ator_p);
         		strcpy(f.filme[i].titulo,f.filme[i+1].titulo);
         		strcpy(f.filme[i].genero,f.filme[i+1].genero);
         		strcpy(f.filme[i].idioma,f.filme[i+1].idioma);
         		strcpy(f.filme[i].diretor,f.filme[i+1].diretor);
         	    f.filme[i].duracao = f.filme[i+1].duracao;
         		
			  }
			  printf("\n\nO elemento foi eliminado com sucesso\n ");
			 
	     	}
         	
		 } 
		
	}
	
	system("pause");
}

 void consulta_pos(){ 
    int pos = -1; 
	char titulo[50];
	if(listavazia()){
		printf("\n\n A lista estar vazia");
	}
	else{
    printf("\n\nDigite o titulo de um filme a ser consultado: \n ");
    scanf("%s",&titulo);     		
    for (int i=0; i<= f.fim; i = i+1){
		  if(strcmp (f.filme[i].titulo, titulo)==0){
		      	pos= i;
			}		
      	} 
        if(pos != -1){
        	printf( "\n\nEsse elemento estar na posicao %i  da lista \n",pos);	
		} 
		else{
			printf("\n\nEsse elemento nao estar cadastrado na lista \n ");
		}		
   }
	system("pause");	
    
 }
 
 void consulta_elemento(){
 	  int pos;
 	  if(listavazia()){
 	  	printf("\n\n A lista estar vazia ");
	   }
	   else{
	   	   printf("\n\nDigite  a posicao da lista que deseja realizar uma consulta : \n ");
	   	   scanf("%d",&pos);
	   	   if((pos<0) || (pos > f.fim)){
	   	   	   printf("\n\n Posicao invalida \n");
			  }
		    else{
		    printf("\n Titulo do filme: %s ",f.filme[pos].titulo);
			printf("\n Genero do filme: %s ",f.filme[pos].genero);
			printf("\n Diretor (a) do filme: %s ",f.filme[pos].diretor);
			printf("\n Ator ou atriz principal do filme: %s ",f.filme[pos].ator_p);
			printf("\n Idioma do filme: %s ",f.filme[pos].idioma);
			printf("\n Duracao do filme: %d  minutos" ,f.filme[pos].duracao);
			 printf("\n==================================================\n");  
		    	
			}	  
	   }
 	system("pause");
 }
 
 void sucessor(){
 	  char titulo_filme[50];
 	  int pos = -1;
 	 if(listavazia()){
 	 	printf("\n\n A lista estar vazia \n");
	  }
	  else{
	  	printf("\n\nDigite o titulo do filme a ser buscado o seu sucessor na lista: \n ");
	  	scanf("%s",&titulo_filme);
	  	for(int i=0;i<=f.fim; i=i+1){
	  		if(strcmp(f.filme[i].titulo, titulo_filme)==0){
	  			pos= i;	  			
			  }
		  }
		 if(pos!= -1){
		 		printf("\n-----------SUCESSOR---------\n") ; 
	        	printf("\n Titulo do filme: %s ",f.filme[pos+1].titulo);
	        	printf("\n Genero do filme: %s ",f.filme[pos+1].genero);
		    	printf("\n Diretor (a) do filme: %s ",f.filme[pos+1].diretor);
		    	printf("\n Ator ou atriz principal do filme: %s ",f.filme[pos+1].ator_p);
		    	printf("\n Idioma do filme: %s ",f.filme[pos+1].idioma);
		    	printf("\n Duracao do filme: %d  minutos" ,f.filme[pos+1].duracao);
			    printf("\n=======================================================");  
		 }
		 else{
		 	printf("\n\n O filme procurado nao estah cadastrado na lista \n");
		 } 
	
	  }
	 system("pause"); 
 }
 void antecessor(){
 	  char titulo_filme[50];
 	  int pos = -1;
 	 if(listavazia()){
 	 	printf("\n\n A lista estar vazia \n");
	  }
	  else{
	  	printf("\n\nDigite o titulo do filme a ser buscado o seu antecessor na lista \n ");
	  	scanf("%s",&titulo_filme);
	  	for(int i=0;i<=f.fim; i=i+1){
	  		if(strcmp(f.filme[i].titulo, titulo_filme)==0){
	  			pos= i;	  			
			  }
		  }
		 if(pos!= -1){
		 		printf("\n-----------ANTECESSOR---------\n") ; 
	        	printf("\n Titulo do filme: %s \n ",f.filme[pos-1].titulo);	        
	        	printf("\n Genero do filme: %s ",f.filme[pos-1].genero);
		    	printf("\n Diretor (a) do filme: %s ",f.filme[pos-1].diretor);
		    	printf("\n Ator ou atriz principal do filme: %s ",f.filme[pos-1].ator_p);
		    	printf("\n Idioma do filme: %s ",f.filme[pos-1].idioma);
		    	printf("\n Duracao do filme: %d  minutos" ,f.filme[pos-1].duracao);
			    printf("\n=======================================================\n"); 
		 }
		 else{
		 	printf("\n\n O filme procurado nao estah cadastrado na lista \n");
		 } 
	
	  }
	 system("pause"); 
 }
  void remocao_elemento(){
  	char titulo_filme[50];
  	int pos= -1;
  	if(listavazia()){
  		printf("\n\nA lista estah vazia ");
	  }
	  else{
	  	int i;
	    char escolha[20];
	  	printf("\n\n Digite o titulo do filme que voce deseja remover \n");
	  	scanf("%s",&titulo_filme);	  
	  	for(i=0;i<=f.fim;i++){
	  		if(strcmp(f.filme[i].titulo,titulo_filme)==0){
	  			pos=i;	  			
			  }
		  }
		  if(pos!= -1){
		    printf("\n Titulo do filme: %s ",f.filme[pos].titulo);
			printf("\n Genero do filme: %s ",f.filme[pos].genero);
			printf("\n Diretor (a) do filme: %s ",f.filme[pos].diretor);
			printf("\n Ator ou atriz principal do filme: %s ",f.filme[pos].ator_p);
			printf("\n Idioma do filme: %s ",f.filme[pos].idioma);
			printf("\n Duracao do filme: %d  minutos" ,f.filme[pos].duracao);
			printf("\n====================================================\n");
		  	printf("\n Voce tem certeza que deseja excluir  esse filme ? -digite sim/nao \n");
		  	scanf("%s",escolha);
		  	if(strcmp(escolha,"sim")==0){
		  		f.fim--;		  	
		  	  for(i=pos;i<=f.fim;i++){
		  		strcpy(f.filme[i].titulo,f.filme[i+1].titulo);
		  		strcpy(f.filme[i].diretor,f.filme[i+1].diretor);
		  		strcpy(f.filme[i].ator_p,f.filme[i+1].ator_p);
		  		strcpy(f.filme[i].genero,f.filme[i+1].genero);
		  		strcpy(f.filme[i].idioma,f.filme[i+1].idioma);
		  		f.filme[i].duracao = f.filme[i+1].duracao;			  
		    } 
			printf("\n\n Remocao efetuada com sucesso \n"); 
		  }
		 else{
		      printf("\n\n Voce nao quis remover o filme da lista \n");		  		
			  }
		 }
		 else{
		 	printf("\n\n Nao eh possivel remover este filme , pois ele nao estah cadastrado na lista \n");
		 }
		 
	  }
 	system("pause");
 }
   
int main(){ // programa principal
   int opcao;
   inicializacao();
   do {
      system("cls");
      printf("\n\t****** LISTA ESTATICA NAO ORDENADA ******\n\n" );   
	  printf("0 - Inserir elemento no final\n");	     
      printf("1 - Inserir elemento numa determinada posicao\n");
      printf("2 - Remover elemento no final\n");         
      printf("3 - Consultar posicao do elemento\n");               
      printf("4 - Mostrar lista\n");
      printf("5 - Primeiro elemento\n");
      printf("6 - Ultimo elemento\n");
      printf("7 - Sucessor\n");      
      printf("8 - Antecessor\n");            
      printf("9 - Tamanho da lista\n");      
      printf("10 - Destruir lista\n");
	  printf("11- Remocao elemento em uma determinada posicao \n");
	  printf("12 - Consultar elemento de uma determinada posicao \n");  
	  printf("13 - Remocao de um determinado elemento \n");    
      printf("99 - Sair\n\n");   
      printf("Opcao: ");
	  scanf("%i", &opcao);   
      switch (opcao) {
      		 case 0 : {
                  insercao_final();
                  break;
             }
            case 1 : {
                insercao_pos();
                break;
           }
             case 2 : {
                 remocao_final();
                 break;
           }
           case 3 : {           	            	   
                consulta_pos();                
                 break;
            }
             case 4 : {
                  mostrarlista();
                  break;
             }
             case 5 : {
                  primeiro();
                  break;
             }
             case 6 : {
                  ultimo();
                  break;
             }
           case 7 : {
                  sucessor();
                  break;
          }
            case 8 : {
                antecessor();
                break;
           }
             case 9 : {
                  tamanho();
                  break;
            }
             case 10 : {
                  destruicao();
                  break;
             }
             
             case 11 : {
             	remocao_pos();
				break;
			 }
			 
			 case 12 :{
			 	consulta_elemento();
				break;
			 }
			 
			 case 13:{
			 	remocao_elemento();
				break;
			 }
      }
   }
   while (opcao != 99);
}



