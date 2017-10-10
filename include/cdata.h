/*
 * cdata.h: arquivo de inclus�o de uso apenas na gera��o da libpithread
 *
 * Esse arquivo pode ser modificado. ENTRETANTO, deve ser utilizada a TCB fornecida
 *
 * Vers�o de 11/09/2017
 *
 */
#ifndef __cdata__
#define __cdata__
#include "ucontext.h"

#define	PROCST_CRIACAO	0
#define	PROCST_APTO	1
#define	PROCST_EXEC	2
#define	PROCST_BLOQ	3
#define	PROCST_TERMINO	4

/* Os campos "tid", "state", "prio" e "context" dessa estrutura devem ser mantidos e usados convenientemente
   Pode-se acrescentar outros campos AP�S os campos obrigat�rios dessa estrutura
*/
typedef struct s_TCB {
	int		tid; 		// identificador da thread
	int		state;		// estado em que a thread se encontra
					// 0: Cria��o; 1: Apto; 2: Execu��o; 3: Bloqueado e 4: T�rmino
	unsigned 	int		prio;		// prioridade da thread (higest=0; lowest=3)
	ucontext_t 	context;	// contexto de execu��o da thread (SP, PC, GPRs e recursos)
	int wait_tid; // identificador da thread que está sendo esperada para continuar a execucao

	/* Se necess�rio, pode-se acresecentar campos nessa estrutura A PARTIR DAQUI! */


} TCB_t;

/*typedef struct s_sem { //copiado do professor :)
	int count; // indica se recurso está ocupado ou não (livre > 0, ocupado ≤ 0)
	PFILA2 fila; // ponteiro para uma fila de threads bloqueadas no semáforo.
} csem_t;
*/

#endif
