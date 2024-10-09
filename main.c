/*
 * FreeRTOS Kernel V10.0.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/******************************************************************************
 * This project provides two demo applications.  A simple blinky style project,
 * and a more comprehensive test and demo application.  The
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY setting is used to select between the two.
 * The simply blinky demo is implemented and described in main_blinky.c.  The
 * more comprehensive test and demo application is implemented and described in
 * main_full.c.
 *
 * This file implements the code that is not demo specific, including the
 * hardware setup and FreeRTOS hook functions.
 *
 *******************************************************************************
 * NOTE: Windows will not be running the FreeRTOS demo threads continuously, so
 * do not expect to get real time behaviour from the FreeRTOS Windows port, or
 * this demo application.  Also, the timing information in the FreeRTOS+Trace
 * logs have no meaningful units.  See the documentation page for the Windows
 * port for further information:
 * http://www.freertos.org/FreeRTOS-Windows-Simulator-Emulator-for-Visual-Studio-and-Eclipse-MingW.html
 *

 *
 *******************************************************************************
 */

/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <conio.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include <queue.h>
#include <semphr.h>

/* This project provides two demo applications.  A simple blinky style demo
application, and a more comprehensive test and demo application.  The
mainCREATE_SIMPLE_BLINKY_DEMO_ONLY setting is used to select between the two.

If mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is 1 then the blinky demo will be built.
The blinky demo is implemented and described in main_blinky.c.

If mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is not 1 then the comprehensive test and
demo application will be built.  The comprehensive test and demo application is
implemented and described in main_full.c. */
#define mainCREATE_SIMPLE_BLINKY_DEMO_ONLY	1

/* This demo uses heap_5.c, and these constants define the sizes of the regions
that make up the total heap.  heap_5 is only used for test and example purposes
as this demo could easily create one large heap region instead of multiple
smaller heap regions - in which case heap_4.c would be the more appropriate
choice.  See http://www.freertos.org/a00111.html for an explanation. */
#define mainREGION_1_SIZE	7201
#define mainREGION_2_SIZE	29905
#define mainREGION_3_SIZE	6407

/*-----------------------------------------------------------*/

/*
 * main_blinky() is used when mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 1.
 * main_full() is used when mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 0.
 */
//extern void main_blinky( void );
//extern void main_full( void );

/*
 * Only the comprehensive demo uses application hook (callback) functions.  See
 * http://www.freertos.org/a00016.html for more information.
 */
//void vFullDemoTickHookFunction( void );
//void vFullDemoIdleFunction( void );

/*
 * This demo uses heap_5.c, so start by defining some heap regions.  It is not
 * necessary for this demo to use heap_5, as it could define one large heap
 * region.  Heap_5 is only used for test and example purposes.  See
 * http://www.freertos.org/a00111.html for an explanation.
 */
static void  prvInitialiseHeap( void );

/*
 * Prototypes for the standard FreeRTOS application hook (callback) functions
 * implemented within this file.  See http://www.freertos.org/a00016.html .
 */
void vApplicationMallocFailedHook( void );
void vApplicationIdleHook( void );
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationTickHook( void );
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize );

/*
 * Writes trace data to a disk file when the trace recording is stopped.
 * This function will simply overwrite any trace files that already exist.
 */
static void prvSaveTraceFile( void );

/*-----------------------------------------------------------*/

/* When configSUPPORT_STATIC_ALLOCATION is set to 1 the application writer can
use a callback function to optionally provide the memory required by the idle
and timer tasks.  This is the stack that will be used by the timer task.  It is
declared here, as a global, so it can be checked by a test that is implemented
in a different file. */
StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

/* Notes if the trace is running or not. */
static BaseType_t xTraceRunning = pdTRUE;

/*-----------------------------------------------------------*/














/*----------------- IN�CIO ------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#define NUM_CRUZAMENTOS 4
#define TEMPO_CICLO 3 // Tempo do ciclo semaf�rico em segundos

// Defini��es das dire��es
#define NS 1
#define SN 2
#define EW 3
#define WE 4

/**
 * @brief Estrutura que representa um cruzamento de tr�nsito.
 *
 * A estrutura cont�m informa��es sobre o estado dos sem�foros do cruzamento
 * e refer�ncias para os cruzamentos adjacentes, conforme a dire��o.
 */
typedef struct Cruzamento {
    char id;                      /**< Identificador do cruzamento (A, B, C, D). */
    bool semaforoNS;              /**< Estado do sem�foro na dire��o Norte-Sul (NS). */
    bool semaforoSN;              /**< Estado do sem�foro na dire��o Sul-Norte (SN). */
    bool semaforoEW;              /**< Estado do sem�foro na dire��o Leste-Oeste (EW). */
    bool semaforoWE;              /**< Estado do sem�foro na dire��o Oeste-Leste (WE). */
    SemaphoreHandle_t mutexNS;    /**< Mutex para controlar acesso ao sem�foro NS. */
    SemaphoreHandle_t mutexSN;    /**< Mutex para controlar acesso ao sem�foro SN. */
    SemaphoreHandle_t mutexEW;    /**< Mutex para controlar acesso ao sem�foro EW. */
    SemaphoreHandle_t mutexWE;    /**< Mutex para controlar acesso ao sem�foro WE. */
    struct Cruzamento* proximoNS; /**< Pr�ximo cruzamento na dire��o NS. */
    struct Cruzamento* proximoSN; /**< Pr�ximo cruzamento na dire��o SN. */
    struct Cruzamento* proximoEW; /**< Pr�ximo cruzamento na dire��o EW. */
    struct Cruzamento* proximoWE; /**< Pr�ximo cruzamento na dire��o WE. */
} Cruzamento;

/**
 * @brief Estrutura que representa um ve�culo.
 *
 * A estrutura cont�m informa��es sobre o ve�culo, como velocidade,
 * dire��o, tempo de deslocamento e refer�ncia ao cruzamento atual.
 */
typedef struct {
    int id;                        /**< Identificador do ve�culo. */
    int velocidade;                /**< Velocidade do ve�culo em km/h. */
    int direcao;                   /**< Dire��o do ve�culo (1-NS, 2-SN, 3-EW, 4-WE). */
    int tempoDeslocamento;         /**< Tempo necess�rio para atravessar o cruzamento. */
    Cruzamento* cruzamento;        /**< Cruzamento atual onde o ve�culo est�. */
} Veiculo;

// Array global para armazenar refer�ncias aos cruzamentos
Cruzamento* cruzamentos[NUM_CRUZAMENTOS];

/**
 * @brief Fun��o que simula o comportamento de um cruzamento.
 *
 * A fun��o alterna o estado dos sem�foros em um ciclo pr�-definido,
 * abrindo e fechando cada dire��o de acordo com o tempo configurado.
 *
 * @param pvParameters Ponteiro para os par�metros da fun��o (deve ser um `Cruzamento*`).
 */
void vCruzamentoTask(void* pvParameters) {
    Cruzamento* cruzamento = (Cruzamento*)pvParameters;

    for (;;) {
        // Alterna o estado dos sem�foros
        xSemaphoreTake(cruzamento->mutexNS, portMAX_DELAY);
        cruzamento->semaforoNS = !cruzamento->semaforoNS;
        xSemaphoreGive(cruzamento->mutexNS);

        xSemaphoreTake(cruzamento->mutexSN, portMAX_DELAY);
        cruzamento->semaforoSN = !cruzamento->semaforoSN;
        xSemaphoreGive(cruzamento->mutexSN);

        xSemaphoreTake(cruzamento->mutexEW, portMAX_DELAY);
        cruzamento->semaforoEW = !cruzamento->semaforoEW;
        xSemaphoreGive(cruzamento->mutexEW);

        xSemaphoreTake(cruzamento->mutexWE, portMAX_DELAY);
        cruzamento->semaforoWE = !cruzamento->semaforoWE;
        xSemaphoreGive(cruzamento->mutexWE);

        // Imprime o estado atual do cruzamento
        printf("Cruzamento %c: NS: %s, SN: %s, EW: %s, WE: %s\n",
            cruzamento->id,
            cruzamento->semaforoNS ? "Aberto" : "Fechado",
            cruzamento->semaforoSN ? "Aberto" : "Fechado",
            cruzamento->semaforoEW ? "Aberto" : "Fechado",
            cruzamento->semaforoWE ? "Aberto" : "Fechado");

        // Aguarda o pr�ximo ciclo
        vTaskDelay(pdMS_TO_TICKS(TEMPO_CICLO * 1000));
    }
}

/**
 * @brief Verifica se um sem�foro est� aberto para a dire��o especificada.
 *
 * A fun��o utiliza sem�foros bin�rios para garantir acesso exclusivo ao estado
 * do sem�foro e verifica se o sem�foro na dire��o desejada est� aberto.
 *
 * @param cruzamento Ponteiro para o cruzamento onde o sem�foro ser� verificado.
 * @param direcao Dire��o do sem�foro a ser verificado (NS, SN, EW, WE).
 * @return Retorna 1 se o sem�foro estiver aberto, 0 caso contr�rio.
 */
int verificarSemaforoAberto(Cruzamento* cruzamento, int direcao) {
    bool semaforoAberto = false;

    switch (direcao) {
    case NS:
        xSemaphoreTake(cruzamento->mutexNS, portMAX_DELAY);
        semaforoAberto = cruzamento->semaforoNS;
        xSemaphoreGive(cruzamento->mutexNS);
        break;
    case SN:
        xSemaphoreTake(cruzamento->mutexSN, portMAX_DELAY);
        semaforoAberto = cruzamento->semaforoSN;
        xSemaphoreGive(cruzamento->mutexSN);
        break;
    case EW:
        xSemaphoreTake(cruzamento->mutexEW, portMAX_DELAY);
        semaforoAberto = cruzamento->semaforoEW;
        xSemaphoreGive(cruzamento->mutexEW);
        break;
    case WE:
        xSemaphoreTake(cruzamento->mutexWE, portMAX_DELAY);
        semaforoAberto = cruzamento->semaforoWE;
        xSemaphoreGive(cruzamento->mutexWE);
        break;
    default:
        return 0; // Dire��o inv�lida
    }

    return semaforoAberto ? 1 : 0;
}

/**
 * @brief Simula o comportamento de um ve�culo em um cruzamento.
 *
 * A fun��o controla o movimento do ve�culo, verificando o estado dos sem�foros
 * e movimentando-o entre cruzamentos adjacentes conforme a dire��o escolhida.
 *
 * @param pvParameters Ponteiro para os par�metros da fun��o (deve ser um `Veiculo*`).
 */
void vVeiculoTask(void* pvParameters) {
    Veiculo* veiculo = (Veiculo*)pvParameters;
    char* direcao;

    switch (veiculo->direcao) {
    case NS: direcao = "NS"; break;
    case SN: direcao = "SN"; break;
    case EW: direcao = "EW"; break;
    case WE: direcao = "WE"; break;
    default: direcao = "ERROR"; break;
    }

    printf("Ve�culo ID: %d, Velocidade: %d km/h, Cruzamento: %c, Dire��o: %s\n",
        veiculo->id, veiculo->velocidade, veiculo->cruzamento->id, direcao);

    for (;;) {
        if (verificarSemaforoAberto(veiculo->cruzamento, veiculo->direcao)) {
            // O sem�foro est� aberto, o ve�culo pode atravessar
            printf("Ve�culo ID: %d, Dire��o: %s - Atravessando o sem�foro.\n", veiculo->id, direcao);
            vTaskDelay(pdMS_TO_TICKS(veiculo->tempoDeslocamento)); // Simula a travessia

            // Move para o pr�ximo cruzamento, verificando se � nulo
            switch (veiculo->direcao) {
            case NS: veiculo->cruzamento = veiculo->cruzamento->proximoNS; break;
            case SN: veiculo->cruzamento = veiculo->cruzamento->proximoSN; break;
            case EW: veiculo->cruzamento = veiculo->cruzamento->proximoEW; break;
            case WE: veiculo->cruzamento = veiculo->cruzamento->proximoWE; break;
            }

            if (veiculo->cruzamento == NULL) {
                printf("Ve�culo ID: %d - Saiu da rede de cruzamentos.\n", veiculo->id);
                vTaskDelete(NULL); // Encerra a task quando o ve�culo sai da rede
            }
            else {
                printf("Ve�culo ID: %d - Chegou ao cruzamento %c.\n", veiculo->id, veiculo->cruzamento->id);
            }
        }
        else {
            // O sem�foro est� fechado, o ve�culo deve esperar
            printf("Ve�culo ID: %d, Dire��o: %s - Esperando o sem�foro.\n", veiculo->id, direcao);
            vTaskDelay(pdMS_TO_TICKS(1000)); // Espera antes de tentar novamente
        }
    }
}

/**
 * @brief Gera ve�culos indefinidamente e atribui-os a cruzamentos.
 *
 * A fun��o cria novos ve�culos com dire��es e velocidades aleat�rias,
 * e os distribui entre os cruzamentos dispon�veis.
 *
 * @param pvParameters Par�metros passados para a fun��o (n�o utilizado neste caso).
 */
void vVeiculoCreator(void* pvParameters) {
    int veiculoCounter = 0;

    while (1) {
        Veiculo* novoVeiculo = (Veiculo*)pvPortMalloc(sizeof(Veiculo));
        if (novoVeiculo == NULL) {
            printf("Erro ao alocar mem�ria para um novo ve�culo.\n");
            vTaskDelay(pdMS_TO_TICKS(1000));
            continue;
        }

        novoVeiculo->id = veiculoCounter++;
        novoVeiculo->direcao = (rand() % 4) + 1; // Dire��o aleat�ria entre 1 e 4

        // Inicializa a velocidade do ve�culo
        novoVeiculo->velocidade = (novoVeiculo->direcao > 2) ? (rand() % 31) + 20 : (rand() % 31) + 30;
        novoVeiculo->tempoDeslocamento = (int)round(500 / (novoVeiculo->velocidade * 0.27778));

        // Escolhe um cruzamento aleat�rio
        int cruzamentoIndex = rand() % NUM_CRUZAMENTOS;
        novoVeiculo->cruzamento = cruzamentos[cruzamentoIndex];

        if (novoVeiculo->cruzamento == NULL) {
            printf("Erro: ve�culo foi atribu�do a um cruzamento nulo.\n");
            vPortFree(novoVeiculo);
            continue;
        }

        // Cria uma task para o novo ve�culo
        if (xTaskCreate(vVeiculoTask, "VeiculoTask", configMINIMAL_STACK_SIZE, (void*)novoVeiculo, 1, NULL) != pdPASS) {
            printf("Falha ao criar ve�culo ID %d\n", novoVeiculo->id);
            vPortFree(novoVeiculo);
        }

        vTaskDelay(pdMS_TO_TICKS((rand() % 3) * 1000)); // Aguarda antes de criar outro ve�culo
    }
}

/**
 * @brief Cria os cruzamentos e define as conex�es entre eles.
 *
 * A fun��o inicializa todos os cruzamentos e define as conex�es de acordo
 * com o layout especificado. Os sem�foros come�am alternadamente abertos.
 */
void CruzamentoCreator() {
    char cruzamentoID = 'A';

    for (int i = 0; i < NUM_CRUZAMENTOS; i++) {
        Cruzamento* cruzamento = (Cruzamento*)pvPortMalloc(sizeof(Cruzamento));
        if (cruzamento == NULL) {
            printf("Erro ao alocar mem�ria para o cruzamento %c.\n", cruzamentoID + i);
            continue;
        }

        cruzamento->id = cruzamentoID++;
        cruzamento->semaforoNS = (i % 2 == 0); // Sem�foros alternados come�am verdes
        cruzamento->semaforoSN = (i % 2 == 0);
        cruzamento->semaforoEW = !(i % 2 == 0);
        cruzamento->semaforoWE = !(i % 2 == 0);

        // Inicializa os sem�foros bin�rios
        cruzamento->mutexNS = xSemaphoreCreateBinary();
        cruzamento->mutexSN = xSemaphoreCreateBinary();
        cruzamento->mutexEW = xSemaphoreCreateBinary();
        cruzamento->mutexWE = xSemaphoreCreateBinary();

        // Libera os mutexes iniciais
        xSemaphoreGive(cruzamento->mutexNS);
        xSemaphoreGive(cruzamento->mutexSN);
        xSemaphoreGive(cruzamento->mutexEW);
        xSemaphoreGive(cruzamento->mutexWE);

        // Inicializa ponteiros para os pr�ximos cruzamentos como NULL
        cruzamento->proximoNS = NULL;
        cruzamento->proximoSN = NULL;
        cruzamento->proximoEW = NULL;
        cruzamento->proximoWE = NULL;

        cruzamentos[i] = cruzamento;

        if (xTaskCreate(vCruzamentoTask, "CruzamentoTask", configMINIMAL_STACK_SIZE, (void*)cruzamento, 1, NULL) != pdPASS) {
            printf("Falha ao criar o cruzamento %c.\n", cruzamento->id);
            vPortFree(cruzamento);
        }
    }

    // Definindo as conex�es entre os cruzamentos
    cruzamentos[0]->proximoSN = cruzamentos[2]; // A -> C (SN)
    cruzamentos[0]->proximoWE = cruzamentos[1]; // A -> B (WE)

    cruzamentos[1]->proximoSN = cruzamentos[3]; // B -> D (SN)
    cruzamentos[1]->proximoEW = cruzamentos[0]; // B -> A (EW)

    cruzamentos[2]->proximoNS = cruzamentos[0]; // C -> A (NS)
    cruzamentos[2]->proximoWE = cruzamentos[3]; // C -> D (WE)

    cruzamentos[3]->proximoNS = cruzamentos[1]; // D -> B (NS)
    cruzamentos[3]->proximoEW = cruzamentos[2]; // D -> C (EW)
}

/**
 * @brief Fun��o principal que inicializa o sistema de controle de tr�fego.
 *
 * A fun��o configura a mem�ria do FreeRTOS, cria os cruzamentos e inicializa
 * a task respons�vel por criar ve�culos.
 *
 * @return Sempre retorna 0.
 */
int main(void) {
    // Inicializa o heap
    prvInitialiseHeap();

    // Habilita o trace recorder (opcional)
    vTraceEnable(TRC_START);

    // Cria os cruzamentos
    CruzamentoCreator();

    // Cria a task respons�vel por gerar ve�culos indefinidamente
    xTaskCreate(vVeiculoCreator, "VeiculoCreator", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Inicia o agendador do FreeRTOS
    vTaskStartScheduler();

    // Loop infinito para manter o programa ativo
    for (;;);
    return 0;
}



/*-----------------------------------------------------------*/






















void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c, heap_2.c or heap_4.c is being used, then the
	size of the	heap available to pvPortMalloc() is defined by
	configTOTAL_HEAP_SIZE in FreeRTOSConfig.h, and the xPortGetFreeHeapSize()
	API function can be used to query the size of free heap space that remains
	(although it does not provide information on how the remaining heap might be
	fragmented).  See http://www.freertos.org/a00111.html for more
	information. */
	vAssertCalled( __LINE__, __FILE__ );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If application tasks make use of the
	vTaskDelete() API function to delete themselves then it is also important
	that vApplicationIdleHook() is permitted to return to its calling function,
	because it is the responsibility of the idle task to clean up memory
	allocated by the kernel to any task that has since deleted itself. */

	/* Uncomment the following code to allow the trace to be stopped with any
	key press.  The code is commented out by default as the kbhit() function
	interferes with the run time behaviour. */
	/*
		if( _kbhit() != pdFALSE )
		{
			if( xTraceRunning == pdTRUE )
			{
				vTraceStop();
				prvSaveTraceFile();
				xTraceRunning = pdFALSE;
			}
		}
	*/

	#if ( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY != 1 )
	{
		/* Call the idle task processing used by the full demo.  The simple
		blinky demo does not use the idle task hook. */
		vFullDemoIdleFunction();
	}
	#endif
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected.  This function is
	provided as an example only as stack overflow checking does not function
	when running the FreeRTOS Windows port. */
	vAssertCalled( __LINE__, __FILE__ );
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()). */
	#if ( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY != 1 )
	{
		vFullDemoTickHookFunction();
	}
	#endif /* mainCREATE_SIMPLE_BLINKY_DEMO_ONLY */
}
/*-----------------------------------------------------------*/

void vApplicationDaemonTaskStartupHook( void )
{
	/* This function will be called once only, when the daemon task starts to
	execute	(sometimes called the timer task).  This is useful if the
	application includes initialisation code that would benefit from executing
	after the scheduler has been started. */
}
/*-----------------------------------------------------------*/

void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
static BaseType_t xPrinted = pdFALSE;
volatile uint32_t ulSetToNonZeroInDebuggerToContinue = 0;

	/* Called if an assertion passed to configASSERT() fails.  See
	http://www.freertos.org/a00110.html#configASSERT for more information. */

	/* Parameters are not used. */
	( void ) ulLine;
	( void ) pcFileName;

	printf( "ASSERT! Line %ld, file %s, GetLastError() %ld\r\n", ulLine, pcFileName, GetLastError() );

 	taskENTER_CRITICAL();
	{
		/* Stop the trace recording. */
		if( xPrinted == pdFALSE )
		{
			xPrinted = pdTRUE;
			if( xTraceRunning == pdTRUE )
			{
				vTraceStop();
				prvSaveTraceFile();
			}
		}

		/* You can step out of this function to debug the assertion by using
		the debugger to set ulSetToNonZeroInDebuggerToContinue to a non-zero
		value. */
		while( ulSetToNonZeroInDebuggerToContinue == 0 )
		{
			__asm{ NOP };
			__asm{ NOP };
		}
	}
	taskEXIT_CRITICAL();
}
/*-----------------------------------------------------------*/

static void prvSaveTraceFile( void )
{
FILE* pxOutputFile;

	fopen_s( &pxOutputFile, "Trace.dump", "wb");

	if( pxOutputFile != NULL )
	{
		fwrite( RecorderDataPtr, sizeof( RecorderDataType ), 1, pxOutputFile );
		fclose( pxOutputFile );
		printf( "\r\nTrace output saved to Trace.dump\r\n" );
	}
	else
	{
		printf( "\r\nFailed to create trace dump file\r\n" );
	}
}
/*-----------------------------------------------------------*/

static void  prvInitialiseHeap( void )
{
/* The Windows demo could create one large heap region, in which case it would
be appropriate to use heap_4.  However, purely for demonstration purposes,
heap_5 is used instead, so start by defining some heap regions.  No
initialisation is required when any other heap implementation is used.  See
http://www.freertos.org/a00111.html for more information.

The xHeapRegions structure requires the regions to be defined in start address
order, so this just creates one big array, then populates the structure with
offsets into the array - with gaps in between and messy alignment just for test
purposes. */
static uint8_t ucHeap[ configTOTAL_HEAP_SIZE ];
volatile uint32_t ulAdditionalOffset = 19; /* Just to prevent 'condition is always true' warnings in configASSERT(). */
const HeapRegion_t xHeapRegions[] =
{
	/* Start address with dummy offsets						Size */
	{ ucHeap + 1,											mainREGION_1_SIZE },
	{ ucHeap + 15 + mainREGION_1_SIZE,						mainREGION_2_SIZE },
	{ ucHeap + 19 + mainREGION_1_SIZE + mainREGION_2_SIZE,	mainREGION_3_SIZE },
	{ NULL, 0 }
};

	/* Sanity check that the sizes and offsets defined actually fit into the
	array. */
	configASSERT( ( ulAdditionalOffset + mainREGION_1_SIZE + mainREGION_2_SIZE + mainREGION_3_SIZE ) < configTOTAL_HEAP_SIZE );

	/* Prevent compiler warnings when configASSERT() is not defined. */
	( void ) ulAdditionalOffset;

	vPortDefineHeapRegions( xHeapRegions );
}
/*-----------------------------------------------------------*/

/* configUSE_STATIC_ALLOCATION is set to 1, so the application must provide an
implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
used by the Idle task. */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
/* If the buffers to be provided to the Idle task are declared inside this
function then they must be declared static - otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

	/* Pass out a pointer to the StaticTask_t structure in which the Idle task's
	state will be stored. */
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

	/* Pass out the array that will be used as the Idle task's stack. */
	*ppxIdleTaskStackBuffer = uxIdleTaskStack;

	/* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
	Note that, as the array is necessarily of type StackType_t,
	configMINIMAL_STACK_SIZE is specified in words, not bytes. */
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
/*-----------------------------------------------------------*/

/* configUSE_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )
{
/* If the buffers to be provided to the Timer task are declared inside this
function then they must be declared static - otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xTimerTaskTCB;

	/* Pass out a pointer to the StaticTask_t structure in which the Timer
	task's state will be stored. */
	*ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

	/* Pass out the array that will be used as the Timer task's stack. */
	*ppxTimerTaskStackBuffer = uxTimerTaskStack;

	/* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
	Note that, as the array is necessarily of type StackType_t,
	configMINIMAL_STACK_SIZE is specified in words, not bytes. */
	*pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

