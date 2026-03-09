#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#include "Modelo.h"
#include "ListaEncadeada.h"


void obterDados(char nomeP[], int *d, int *m, int *a, int *h, int *min, char nomeM[], char tipo[]){
    printf("Nome Paciente: ");
    setbuf(stdin, NULL);
    fgets(nomeP, 50, stdin);
    nomeP[strcspn(nomeP, "\n")] = 0;

    printf("Data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", d, m, a); 

    printf("Hora (hh:mm): ");
    scanf("%d:%d", h, min);
    while (getchar() != '\n'); 

    printf("Nome Medico: ");
    setbuf(stdin, NULL);
    fgets(nomeM, 50, stdin);
    nomeM[strcspn(nomeM, "\n")] = 0;

    printf("Tipo: ");
    fgets(tipo, 15, stdin);
    tipo[strcspn(tipo, "\n")] = 0;
}

int menu(){
    int op;
    int resultado;

    printf("\n=== MENU PRINCIPAL ===");
    printf("\n1. Agendar Consulta");
    printf("\n2. Listar Consultas");
    printf("\n3. Alterar Consulta");
    printf("\n4. Remover Consulta");
    printf("\n5. Buscar por Nome");
    printf("\n0. Sair");
    printf("\nEscolha uma opcao: ");
    resultado = scanf("%d", &op);

    if(resultado == 0){
        printf("\nErro: Digite apenas numeros!\n");
        while (getchar() != '\n'); 
        return -1;
    }
    while (getchar() != '\n');
    return op;
}

void limparTela() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear"); 
    #endif
}

void pausa(){

    printf("\nPressione qualquer tecla para continuar...\n");
    getchar();
}

int main(void) {
    No* lista = NULL;
    int op,id_aux;

    char nP[50], nM[50], tipo[20];
    int d, m, a, h, min;
    int codBusca=0;
    char nomeBusca[50];
    No* achado;
    
    while(1){
        limparTela();
        op = menu();
    switch (op)
    {
    
    case 0:
        liberarLista(&lista);
        printf("\nSaindo...\n");
        return 0;
        break;
    case 1:
        limparTela();
        obterDados(nP,&d,&m,&a,&h,&min,nM,tipo);
        inserir_final(&lista,nP,d,m,a,h,min,nM,tipo);

        pausa();
        break;
    case 2:
        limparTela();
        imprimir_lista(lista);
        pausa();
        break;
    
    case 3:
        limparTela();
        printf("\nQual consulta deseja alterar?(ID's apenas)\n");
        while(scanf("%d",&codBusca)==0){
            printf("\nTente novamente! Codigo nao valido!\n");
        }
        getchar();
        obterDados(nP,&d,&m,&a,&h,&min,nM,tipo);
        if(alterarConsulta(codBusca,lista,nP,d,m,a,h,min,nM,tipo)){
            achado = buscarID(codBusca,lista);
            printf("\nConsulta alterada com sucesso!\n");
            printf("\n=== Consulta ===");
            printf("\n Codigo da Consulta: %d",achado->codPaciente);
            printf("\n Paciente: %s",achado->nomePaciente);
            printf("\n Data: %02d/%02d/%d",achado->Data.dia,achado->Data.mes,achado->Data.ano);
            printf("\n Horario: %02d:%02d",achado->Horario.hora,achado->Horario.minuto);
            printf("\n Nome do Medico: %s",achado->nomeMedico);
            printf("\n Tipo de Consulta: %s",achado->tipoConsulta);
            getchar();
        }else{
            printf("\nConsulta nao encontrada!\n");
            pausa();
        }
        break;
    case 4:
        limparTela();
        printf("\nQual consulta deseja remover/cancelar?(ID's apenas)\n");
        while(scanf("%d",&codBusca)==0){
            printf("\nTente novamente! Codigo nao valido!\n");
        }
        achado = buscarID(codBusca,lista);

        if(achado){
            
            printf("\nConsulta Removida com Sucesso!\n");
            printf("\n=== Consulta Removida ===");
            printf("\n Codigo da Consulta: %d",achado->codPaciente);
            printf("\n Paciente: %s",achado->nomePaciente);
            printf("\n Data: %02d/%02d/%d",achado->Data.dia,achado->Data.mes,achado->Data.ano);
            printf("\n Horario: %02d:%02d",achado->Horario.hora,achado->Horario.minuto);
            printf("\n Nome do Medico: %s",achado->nomeMedico);
            printf("\n Tipo de Consulta: %s",achado->tipoConsulta);
            removerConsulta(codBusca,&lista);
            pausa();
            getchar();
        }
        else{
            printf("\nConsulta nao encontrada!\n");
            pausa();
        }
        break;
    
    case 5:
        limparTela();
        printf("\nQual consulta deseja buscar?(Nome apenas)\n");
        setbuf(stdin, NULL);
        char* resultado = fgets(nomeBusca, 50, stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = 0;
        while(resultado==NULL){
            printf("\nTente novamente! Nome invalido!\n");
            scanf("%s",nomeBusca);
        }
        transformarTitulo(nomeBusca);
        achado = buscarNome(nomeBusca,lista);
        if(buscarNome(nomeBusca,lista)){
            printf("\nConsulta encontrada com Sucesso!\n");

            printf("\n=== Consulta Encontrada ===");

            printf("\n Codigo da Consulta: %d",achado->codPaciente);
            printf("\n Paciente: %s",achado->nomePaciente);
            printf("\n Data: %02d/%02d/%d",achado->Data.dia,achado->Data.mes,achado->Data.ano);
            printf("\n Horario:%02d:%02d",achado->Horario.hora,achado->Horario.minuto);
            printf("\n Nome do Medico: %s",achado->nomeMedico);
            printf("\n Tipo de Consulta: %s",achado->tipoConsulta);
            getchar();
        }else{
            printf("\nConsulta nao encontrada!\n");
            pausa();
        }
        pausa();
        break;
    
    default:
        continue;
    }
}
}