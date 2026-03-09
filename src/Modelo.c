#include "Modelo.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int nomeValido(char nomePaciente[]){
    for (int i = 0; nomePaciente[i] != '\0'; i++) { 
        if (isdigit(nomePaciente[i])) 
        {
            return 0;}
    }
    return 1;
}

int tipoValido(char tipoConsulta[]){
    const char *tiposValidos[] = {"particular","conveniado"};
    for (int i=0; tipoConsulta[i] !='\0';i++){
        tipoConsulta[i] = (char)tolower((unsigned char)tipoConsulta[i]);
    }
    for(int i=0;i<2;i++){
    
        if(strcmp(tiposValidos[i],tipoConsulta) == 0 ){
            return 1;
        }
} return 0;
}

int dataValida(int dia,int mes,int ano){
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int mes_max = 12;

    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        diasNoMes[1] = 29;
    }
    
    if(mes<1 || mes>12){
        return 0;
    }else{
        mes-=1;
        if(diasNoMes[mes] <dia || dia<1){
            return 0;
        }else{
            return 1;
        }
    }
}

int horarioValido(int horas,int min){
    int horaMaxima = 23;
    int minMaximo = 59;
    

    if( (horas<=horaMaxima && min<=minMaximo) && (horas>=0 && min>=0) ){
        return 1;
    }
    return 0;
}
void transformarTitulo(char *nome){
    int inWord = 0;

    while(*nome){
        if(isspace(*nome) || ispunct(*nome)){
            inWord = 0;
        }else if(!inWord){
            *nome = (char)toupper((unsigned char)*nome);
            inWord = 1;
        }else{
            *nome = (char)tolower((unsigned char)*nome);
        }
        nome++;
    }
}

int validarGeral(int dia,int mes, int ano, int hora, int min, char nomePaciente[], char nomeMedico[],char tipoConsulta[]){
    
    if(!nomeValido(nomePaciente)){
        printf("\nNome do Paciente invalido!\n");
        return 0;
    }

    if(!nomeValido(nomeMedico)){
        printf("\nNome do Medico invalido!\n");
        return 0;
    }

    if(!dataValida(dia,mes,ano)){
        printf("\nData invalida!\n");
        return 0;
    }
    if(!horarioValido(hora,min)){
        printf("\nHorario invalido!\n");
        return 0;
    }

    if(!tipoValido(tipoConsulta)){
        printf("\nTipo Consulta invalido!\n");
        return 0;
    }

    return 1;
}
