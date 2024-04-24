#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

No *alocar(int x);
void inserir_inicio(No **lista, int x);
void inserir_final(No **lista, int x); // x
void remover_inicio(No **lista);
int *buscar_lista(No *buscar, int x);
void imprimir_lista(No *lista);
void enderecos_lista(No *lista);
void maior_menor(No *lista);
int soma_valores(No *lista);
int tamanho_lista(No *lista);
int frequencia_elemento(No *lista, int x);
void remover_elemento(No **lista, int x);
void remover_final(No **lista);
No *copiar_lista(No *lista, int y);
void desalocar_lista(No **lista);
int comparar_listas(No *lista1, No *lista2);
No *juntar_listas(No *lista1, No *lista2);

int main(){

	No *lista = NULL, *copia_lista = NULL, *fusao_listas = NULL;
	int menu = 1, valor;
	while(menu != 0){
		printf("-------------------------------------\n");
		printf(" 1. Adicionar elemento(s) no ínicio da lista [1]\n");
		printf(" 2. Adicionar elemento(s) no final da lista [1]\n");
		printf(" 3. Remover o primeiro elemento da lista [1]\n");
		printf(" 4. Buscar elemento lista [1]\n");
		printf(" 5. Endereço(s) do(s) elemento(s) da lista [1]\n");
		printf(" 6. Maior e menor elemento lista [1]\n");
		printf(" 7. Soma dos elementos da lista [1]\n");
		printf(" 8. Total de elementos da lista [1]\n");
		printf(" 9. Frequência de um elemento da lista [1]\n");
		printf("10. Remover toda a ocorrência de um elemento\n da lista [1]");
		printf("11. Remover o último elemento da lista [1]\n");
		printf("12. Copiar lista [1] para [2]\n");
		printf("13. Desalocar lista [1]\n");
		printf("14. Desalocar lista [2]\n");
		printf("15. Comparar listas [1] e [2]\n");
		printf("16. Juntar listas [1] e [2]\n");
		printf(" 0. Sair\n\n");
		printf("               [LISTAS]              \n");
		printf("-------------------------------------\n");
		printf("Lista [1]: ");
		if(lista != NULL){	
			imprimir_lista(lista);
		}	
		printf("\nLista [2]: ");
		if(copia_lista != NULL){
			imprimir_lista(copia_lista);
		}
		printf("\nLista [3]: ");
		if(fusao_listas != NULL){
			imprimir_lista(fusao_listas);
		}
		printf("\n-------------------------------------\n");
		scanf("%d",&menu);
		switch(menu){
			case 0:
				return 0;
				break;
			case 1:
				printf("Digite o(s) elemento(s), 0 para confirmar\n");
				while(1){
					scanf("%d",&valor);	
					if(valor == 0){
						break;
					}
					inserir_inicio(&lista, valor);
				}
				system("clear");
				break;
			case 2:
				printf("Digite o(s) elemento(s), 0 para confirmar\n");
				while(1){
					scanf("%d",&valor);	
					if(valor == 0){
						break;
					}
					inserir_final(&lista, valor);
				}
				system("clear");
				break;
			case 3:
				if(lista == NULL){
					system("clear");
					printf("Não há elementos para remover\n");
					break;
				}
				system("clear");
				remover_inicio(&lista);
				break;
			case 4:
				int elemento;
				if(lista == NULL){
					system("clear");
					printf("Não há elementos para busca\n");
					break;
				}
				printf("Elemento para busca: ");
				scanf("%d",&elemento);
				system("clear");	
				buscar_lista(lista, elemento);
				break;
			case 5:
				if(lista == NULL){
					system("clear");
					printf("Não há elementos para busca\n");
					break;
				}
				system("clear");
				enderecos_lista(lista);
				break;
			case 6:
				if(lista == NULL){
					system("clear");
					printf("Não há elementos para busca\n");
					break;
				}
				system("clear");
				maior_menor(lista);
				break;
			case 7:
				if(lista == NULL){
					system("clear");
					printf("Não há elementos para busca\n");
					break;
				}
				system("clear");
				soma_valores(lista);
				break;
			case 8:
				system("clear");
				tamanho_lista(lista);
				break;
			case 9:
				if(lista == NULL){
					system("clear");
					printf("Não há elementos para busca\n");
					break;
				}
				printf("Elemento para busca: ");
				scanf("%d",&elemento);
				system("clear");
				frequencia_elemento(lista, elemento);
				break;
			case 10:
				if(lista == NULL){
					system("clear");
					printf("Não há elementos para remover\n");
					break;
				}
				printf("Elemento para remover: ");
				scanf("%d",&elemento);
				system("clear");
				remover_elemento(&lista, elemento);
				break;
			case 11:
				if(lista == NULL){
					system("clear");
					printf("Não há elementos para remover\n");
					break;
				}
				system("clear");
				remover_final(&lista);
				break;
			case 12:
				int opcao;
				printf("1. Copiar lista idêntica\n");
				printf("2. Copiar e inverter lista\n");
				scanf("%d",&opcao);
				if(copia_lista != NULL){
					printf("Erro! Desaloque a lista primeiro\n");
					printf("1. Desalocar lista [2]\n");
					printf("2. Voltar\n");
					scanf("%d",&opcao);
					if(opcao == 1){
						desalocar_lista(&copia_lista);
						system("clear");
					}
					else{
						system("clear");
						break;
					}
					break;
				}
				system("clear");
				copia_lista = copiar_lista(lista,opcao);
				break;
			case 13:
				if(lista == NULL){
					system("clear");
					printf("Lista vazia, não há o que desalocar\n");
					break;
				}
				desalocar_lista(&lista);
				system("clear");
				break;
			case 14:
				if(copia_lista == NULL){
					system("clear");
					printf("Lista vazia, não há o que desalocar\n");
					break;
				}
				desalocar_lista(&copia_lista);
				system("clear");
			case 15:
				system("clear");
				comparar_listas(lista, copia_lista);
				break;
			case 16:
				if(fusao_listas != NULL){
					printf("Erro! Desaloque a lista primeiro\n");
					printf("1. Desalocar lista [3]\n");
					printf("2. Voltar\n");	
					scanf("%d",&opcao);
					if(opcao == 1){
						desalocar_lista(&fusao_listas);
						system("clear");
					}
					else{
						system("clear");
						break;
					}
					break;
				}
				system("clear");
				fusao_listas = juntar_listas(lista, copia_lista);
				break;
		}
	}
}

No *alocar(int x){
	No *p = (No*)malloc(sizeof(No));
	if (p == NULL) return NULL;
	p->dado = x;
	p->prox = NULL;
	return p;
}

void inserir_inicio(No **lista, int x){ 
	No *aux = alocar(x);
	if(aux == NULL) return;
	aux->prox = *lista;
	*lista = aux;
}

void inserir_final(No **lista, int x){
	No *aux, *novo = alocar(x);
	if(*lista == NULL){ // Verificar se será o primeiro a ser adicionado
		*lista = novo;	
	}
	else{
		aux = *lista;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}
void remover_inicio(No **lista){
	if(*lista == NULL) return;
	No *aux = *lista;
	*lista = (*lista)->prox;
	free(aux);
}

int *buscar_lista(No *lista, int x){
	if(lista == NULL) return NULL;
	while(lista != NULL){
		if(lista->dado == x){
			printf("Encontrado: %d\n",lista->dado);
			printf("Endereço: %p\n",&lista->dado);
			return &lista->dado;
		}
		lista = lista->prox;
	}
	return NULL;
}

void imprimir_lista(No *lista){
	if(lista == NULL) return;
	while(lista != NULL){
		printf("%d ",lista->dado);
		lista = lista->prox;
	}
}

void enderecos_lista(No *lista){
	if(lista == NULL) return;
	int i = 0;
	while(lista != NULL){
		printf("Posição: %d\t Conteúdo: %d\t Endereço: %p\n",i,lista->dado,&lista->dado);
		i++;
		lista = lista->prox;
	}
}

void maior_menor(No *lista){
	int maior = lista->dado, menor = lista->dado;
	while(lista != NULL){
		if(lista->dado > maior){
			maior = lista->dado;
		}
		if(lista->dado < menor){
			menor = lista->dado;
		}
		lista = lista->prox;
	}
	if(maior == menor){
		printf("Elementos iguais\n");
		return;
	}
	printf("Maior: %d\n",maior);
	printf("Menor: %d\n",menor);
}

int soma_valores(No *lista){
	int soma = 0;
	while(lista != NULL){
		soma += lista->dado;
		lista = lista->prox;
	}
	printf("Soma dos elementos: %d\n",soma);
	return soma;
}

int tamanho_lista(No *lista){
	int elementos = 0;
	while(lista != NULL){
		lista = lista->prox;
		elementos++;
	}
	printf("Total de elementos: %d\n",elementos);
	return elementos;
}

int frequencia_elemento(No *lista, int x){
	int frequencia = 0, encontrado = 0;
	while(lista != NULL){
		if(lista->dado == x){
			frequencia++;
			encontrado = 1;
		}
		lista = lista->prox;
	}
	if(encontrado == 1){
		printf("Frequência do elemento %d: %d\n",x,frequencia);
	}
	else{
		printf("Não há esse elemento na lista\n");
	}
	
	return frequencia;
}

void remover_elemento(No **lista, int x){ // Remove todos os elementos iguais a x
	No *atual, *aux = NULL;
	atual = *lista;
	while(atual != NULL){
		if(atual->dado == x){	
			if(aux == NULL){
				*lista = atual->prox; // Caso o valor seja o primeiro da lista
			}
			else{
				aux->prox = atual->prox;
			}
			free(atual);
			atual = *lista;
		}
		else{
			aux = atual;
			atual = atual->prox;
		}
	}
}

void remover_final(No **lista){
	No *aux, *remover;
	aux = *lista;
	if(aux->prox == NULL){ // Caso a lista tenha um elemento
		*lista = (*lista)->prox;
		free(aux);
	}
	else{
		while(aux != NULL){
			if(aux->prox->prox == NULL){
				remover = aux->prox;
				aux->prox = remover->prox;
				free(remover);
			}
			aux = aux->prox;
		}
	}
}

No *copiar_lista(No *lista, int y){
	No *nova_l = NULL;
	if(y == 1){
		while(lista != NULL){
			inserir_final(&nova_l,lista->dado);
			lista = lista->prox;
		}
	}
	if(y == 2){
		while(lista != NULL){
			inserir_inicio(&nova_l,lista->dado);
			lista = lista->prox;
		}
	}
	return nova_l;
}

void desalocar_lista(No **lista){
    while (*lista != NULL){
        remover_final(lista);
    }
}

int comparar_listas(No *lista1, No *lista2){
	int listas_identicas = 0;
	while(lista1 && lista2){
		if(lista1->dado != lista2->dado){
			printf("Listas diferentes\n");
			return 0;
		}
		else{
			listas_identicas = 1;
		}
		lista1 = lista1->prox;
		lista2 = lista2->prox;
	}
	if(listas_identicas == 1){
		printf("Listas idênticas\n");
		return 1;
	}
}

No *juntar_listas(No *lista1, No *lista2){
	No* fusao_l = NULL, *aux;
	fusao_l = copiar_lista(lista1, 1);
	aux = fusao_l;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = copiar_lista(lista2,1);
	return fusao_l;
}