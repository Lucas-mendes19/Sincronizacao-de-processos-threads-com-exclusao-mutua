// Sistemas Operacionais 
// Faculdade �nica de Ipatingaa
// Autor: Prof. J�lio C�zar da Silva Costa
// Mat�ria: Sincroniza��o de processos/threads com exclus�o m�tua
// Objetivo: Garantir a exclus�o m�tua com algoritmo de Peterson.
//
//   Existem 5 threads dentro desse programa. Utilize o algoritmo de Peterson para garantir a sincronia entre elas.
//   Dica: execute o programa antes de fazer qualquer altera��o para verificar o funcionamento do programa.

//	Uma thread tem que escrever na tela de 1 a 10, a outra de 11 a 20 e a ssim por diante at� 50.
//	

//  O c�digo fonte n�o pode sofrer grandes altera��es, somente as necess�rias para implementar o algoritmo de Peterson.
//  Ser� avaliado o c�digo fonte principalmente, em seguida a execu��o do programa.

#include <stdio.h> /* scanf() */
#include <process.h> /* _beginthread() */
#include <windows.h> // Sleep()

void thread1(void *); // Prot�tipo da fun��o que representam as threads.
void thread2(void *); // Prot�tipo da fun��o que representam as threads.
void thread3(void *); // Prot�tipo da fun��o que representam as threads.
void thread4(void *); // Prot�tipo da fun��o que representam as threads.
void thread5(void *); // Prot�tipo da fun��o que representam as threads.

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
	
     _beginthread(thread1,0,NULL); // chama a fun��o e faz dela uma thread
     _beginthread(thread2,0,NULL); // chama a fun��o e faz dela uma thread
     _beginthread(thread3,0,NULL); // chama a fun��o e faz dela uma thread
     _beginthread(thread4,0,NULL); // chama a fun��o e faz dela uma thread
     _beginthread(thread5,0,NULL); // chama a fun��o e faz dela uma thread
     
	  system("PAUSE");
	
     return(0);
}

void thread1(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
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

void thread2(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
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

void thread3(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
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

void thread4(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
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
 
void thread5(void *ignored) // Observe que a fun��o n�o tem o par�metro ponteiro
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
 

 
