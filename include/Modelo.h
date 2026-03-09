#ifndef MODELO_H
#define MODELO_H

typedef struct no No;

struct no{

    int codPaciente;

    char nomePaciente[50];

    struct {
        int dia, mes, ano;
    } Data;

    struct {
        int hora, minuto;
    } Horario;

    char nomeMedico[50];

    char tipoConsulta[20];

    No* prox; 
};

int nomeValido(char nomePaciente[]);
int tipoValido(char tipoConsulta[]);
int dataValida(int dia,int mes,int ano);
int horarioValido(int horas,int min);
void transformarTitulo(char *nome);
int validarGeral(int dia, int mes, int ano, int hora, int min, char nomePaciente[], char nomeMedico[], char tipoConsulta[]);

#endif