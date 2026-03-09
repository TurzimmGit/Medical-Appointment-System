#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "Modelo.h"

int temConflito(No *inicio,int dia, int mes, int ano, int hora, int min,int id_ignorados);
void inserir_final(No** p,char nomePaciente[], int dia, int mes, int ano, int hora, int min, char nomeMedico[], char tipoConsulta[]);
No* buscarID(int codBusca, No *inicio);
No* buscarNome(char nomeBusca[],No *inicio);
void removerConsulta(int codBusca, No **inicio);
int alterarConsulta(int codBusca, No *inicio,char nomePaciente[], int dia, int mes, int ano, int hora, int min, char nomeMedico[], char tipoConsulta[]); 
void imprimir_lista(No* p);
void liberarLista(No **inicio);

#endif