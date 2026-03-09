#include "ListaEncadeada.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


static int id_paciente = 0 ;

int temConflito(No *inicio,int dia, int mes, int ano, int hora, int min,int id_ignorados){
    No *temp = inicio;
    int minutosTotais = (hora*60)+min;
    while(temp!=NULL){
        if(temp->codPaciente != id_ignorados)
        {
            if(temp->Data.dia == dia && temp->Data.mes == mes && temp->Data.ano == ano){
            int minutoslistados = (temp->Horario.hora*60)+ temp->Horario.minuto;
            if(abs(minutosTotais-minutoslistados)<30){
                printf("\nHorario Ocupado!\n");
                return 1;
                }
            }
        }
        temp = temp->prox;
    } return 0;

}

void inserir_final(No** p,char nomePaciente[], int dia, int mes, int ano, int hora, int min, char nomeMedico[], char tipoConsulta[]){
    No *n, *p_aux;
    if(!temConflito(*p,dia,mes,ano,hora,min,-1) && validarGeral(dia, mes, ano, hora, min, nomePaciente, nomeMedico, tipoConsulta)){
        n = (No*) malloc(sizeof(No));
        transformarTitulo(nomePaciente);
        transformarTitulo(nomeMedico);
        transformarTitulo(tipoConsulta);
        n -> codPaciente = id_paciente;
        strcpy(n -> nomePaciente, nomePaciente);
        n -> Data.dia = dia;
        n -> Data.mes = mes;
        n -> Data.ano = ano;
        n -> Horario.hora = hora;
        n -> Horario.minuto = min;
        strcpy(n -> nomeMedico,nomeMedico);
        strcpy(n -> tipoConsulta, tipoConsulta);
        n->prox = NULL;
        if(*p == NULL){
            *p = n;
        } else{
            p_aux = *p;
            while (p_aux->prox != NULL)
            {
                p_aux = p_aux->prox;
            }
            p_aux->prox = n;
        }
        
        id_paciente+=1;
        }
}

No* buscarID(int codBusca, No *inicio){
    No *temp = inicio;
    while(temp!=NULL){
        if(codBusca == temp->codPaciente){
            return temp;
        }
        temp = temp->prox;
    }
    return NULL;
}

No* buscarNome(char nomeBusca[],No *inicio){

    No *temp = inicio;
    while(temp!=NULL){
        if(!strcmp(nomeBusca,temp->nomePaciente)){
            return temp;
        }
        temp = temp->prox;
    }
    return NULL;

}

void removerConsulta(int codBusca, No **inicio){
    No *atual = *inicio;
    No*anterior = NULL;
    while(atual!=NULL && atual->codPaciente != codBusca){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual==NULL){return;}

    if(anterior==NULL){
        *inicio = atual->prox;
        free(atual);
    }else{
        anterior->prox = atual->prox;
        free(atual);
    }
    
}

int alterarConsulta(int codBusca, No *inicio,char nomePaciente[], int dia, int mes, int ano, int hora, int min, char nomeMedico[], char tipoConsulta[]){
    No *temp = inicio;

    No* consultaAchada = buscarID(codBusca,temp);
    if(consultaAchada ==NULL){return 0;}
    if(!temConflito(consultaAchada,dia,mes,ano,hora,min,codBusca) && validarGeral(dia, mes, ano, hora, min, nomePaciente, nomeMedico, tipoConsulta)){
        transformarTitulo(nomePaciente);
        transformarTitulo(nomeMedico);
        transformarTitulo(tipoConsulta);
        strcpy(consultaAchada -> nomePaciente, nomePaciente);
        consultaAchada -> Data.dia = dia;
        consultaAchada -> Data.mes = mes;
        consultaAchada -> Data.ano = ano;
        consultaAchada -> Horario.hora = hora;
        consultaAchada -> Horario.minuto = min;
        strcpy(consultaAchada -> nomeMedico,nomeMedico);
        strcpy(consultaAchada -> tipoConsulta, tipoConsulta);
        printf("\nConsulta alterada com sucesso!\n");
        return 1;
    }
    return 0;
} 

void imprimir_lista(No* p){
    if(p!=NULL){
    printf("\n=== CONSULTAS MARCADAS ===\n");
    while(p!=NULL){
        printf("\nCodigo do Paciente: %d\n", p->codPaciente);
        printf("Nome do Paciente: %-15s\n", p->nomePaciente);
        printf("Data da Consulta: %02d/%02d/%d\n", p->Data.dia,p->Data.mes,p->Data.ano);
        printf("Horario da Consulta: %02d:%02d\n", p->Horario.hora,p->Horario.minuto);
        printf("Nome do medico: %s\n", p->nomeMedico);
        printf("Tipo da consulta: %s\n\n", p->tipoConsulta);
        printf("==========================");
        p = p->prox;
        }
    }else{
        printf("\nLista Vazia!\n");
    }
}

void liberarLista(No **inicio){
    No *atual = *inicio;
    No *proximo;

    while (atual !=NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio= NULL;
}