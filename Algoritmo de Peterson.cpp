// Sistemas Operacionais 
// Faculdade Única de Ipatingaa
// Autor: Prof. Júlio Cézar da Silva Costa
// Matéria: Sincronização de processos/threads com exclusão mútua
// Objetivo: Garantir a exclusão mútua com algoritmo de Peterson.
//
//   Existem 5 threads dentro desse programa. Utilize o algoritmo de Peterson para garantir a sincronia entre elas.
//   Dica: execute o programa antes de fazer qualquer alteração para verificar o funcionamento do programa.

//	Uma thread tem que escrever na tela de 1 a 10, a outra de 11 a 20 e a ssim por diante até 50.
//	

//  O código fonte não pode sofrer grandes alterações, somente as necessárias para implementar o algoritmo de Peterson.
//  Será avaliado o código fonte principalmente, em seguida a execução do programa.

#include <stdio.h> /* scanf() */
#include <process.h> /* _beginthread() */
#include <windows.h> // Sleep()

void thread1(void *); // Protótipo da função que representam as threads.
void thread2(void *); // Protótipo da função que representam as threads.
void thread3(void *); // Protótipo da função que representam as threads.
void thread4(void *); // Protótipo da função que representam as threads.
void thread5(void *); // Protótipo da função que representam as threads.

int valor = 0; // recurso compartilhado.
int turn = 0; //
int flag[4];

int main()
{     
	flag[0] = false;
	flag[1] = false;
	flag[2] = false;
	flag[3] = false;
	flag[4] = false;
	
     _beginthread(thread1,0,NULL); // chama a função e faz dela uma thread
     _beginthread(thread2,0,NULL); // chama a função e faz dela uma thread
     _beginthread(thread3,0,NULL); // chama a função e faz dela uma thread
     _beginthread(thread4,0,NULL); // chama a função e faz dela uma thread
     _beginthread(thread5,0,NULL); // chama a função e faz dela uma thread
     
	  system("PAUSE");
	
     return(0);
}

void thread1(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{	
	int i = 1;
	flag[0] = true;
	turn = 4;
    for(;;){
    	if(flag[0] == true && turn != 0){
	     	valor++;
	     	printf("THREAD1 Valor [%d], \n", valor);
	     	if(i == 10){
	     		flag[0] = false;
	     		break;	
			}
			i++;
		}
    }
}

void thread2(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
	int i = 1;
	flag[1] = true;
	turn = 3;
    for(;;){
    	if(flag[1] == true && turn != 1){
		    valor++;
		    printf("THREAD2 Valor [%d], \n", valor);
		    if(i == 10){
	     		flag[1] = false;
	     		break;	
			}
			i++;
		}
	}
}

void thread3(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
	int i = 1;
	flag[2] = true;
	turn = 2;
    for(;;){
    	if(flag[2] == true && turn != 2){
	     	valor++;
	     	printf("THREAD3 Valor [%d], \n", valor);
	     	if(i == 10){
	     		flag[2] = false;
	     		break;	
			}
			i++;
		}
	}
    
}

void thread4(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
	int i = 1;
	flag[3] = true;
	turn = 1;
   for(;;){
   		if(flag[3] == true && turn != 3){
	   	 	valor++;
	     	printf("THREAD4 Valor [%d], \n", valor);
	     	if(i == 10){
	     		flag[3] = false;
	     		break;	
			}
			i++;
		}
	}
}
 
void thread5(void *ignored) // Observe que a função não tem o parâmetro ponteiro
{
	int i = 1;
	flag[4] = true;
	turn = 0;
    for(;;){
    	if(flag[4] == true && turn != 4){
	     	valor++;
	     	printf("THREAD5 Valor [%d], \n", valor);
	     	if(i == 10){
	     		flag[4] = false;
	     		break;	
			}
			i++;
		}
	}
}
 

 
