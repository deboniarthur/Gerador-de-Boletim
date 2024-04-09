#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funcao da média aritmética
float calc_media_arit(float a,float b,float c){
	return (a+b+c)/3;
}

// funcao da média ponderada
float calc_media_pond(float a,float b,float c){
	return  (a*2 + b*3 + c*5)/10;
}

int main(){
	float nota1, nota2, nota3;
	char nomeDo_aluno_X[50];
	char tipoMedia; // A/a ou P/p
	// variável media vai ser o resultado da aritmética ou ponderada
	float media;
	float media_arit_geral;
	float media_pond_geral;
	int totalAlunos = 0;
	int aprovados = 0;
	int reprovados = 0;
	float media_geral = 0;
	printf("Bem vindo a calculadora de notas em C!\n");
	
	//inicio da execucao
	while(true){
	printf("Digite um nome para iniciar ou X/x para encerrar: ");
	scanf("%s", nomeDo_aluno_X);
	
	// condicao para encerrar
	if (nomeDo_aluno_X[0] == 'X' || nomeDo_aluno_X[0] == 'x'){
		system("cls");
	    break;}
	
	// pede e guarda as notas
	printf("Digite as 3 notas do aluno: \n");
	printf("Primeira Nota: ");
	scanf("%f", &nota1);
	
	printf("Segunda nota: ");
	scanf("%f", &nota2);
	
	printf("Terceira Nota: ");
	scanf("%f", &nota3);
	
	
	printf("Agora digite A/a para media aritmetica ou P/p para media ponderada: ");
	escolhaDa_media:
	scanf("%s", &tipoMedia);
	
	if (tipoMedia != 'A' && tipoMedia != 'a' && tipoMedia != 'P' && tipoMedia != 'p') {
		printf("Nao entendi, digite P/p ou A/a novamente: ");
		goto escolhaDa_media;
	}
	
	if (tipoMedia == 'A' || tipoMedia == 'a'){ 
		media = calc_media_arit(nota1, nota2, nota3);
		totalAlunos++;
		media_geral = media_geral + media;
	}
		else {
			media = calc_media_pond(nota1, nota2, nota3);
			totalAlunos++;
			media_geral = media_geral + media;
	}
	
	
	// imprime o relatório individual
	printf("Relatorio individual: \n");
	printf("Nome do aluno: %s\n", nomeDo_aluno_X);
	printf("Notas: %.1f | %.1f | %.1f\n", nota1, nota2, nota3);
	
	if (tipoMedia == 'A' || tipoMedia == 'a'){
		printf("Tipo de media: Aritmetica\n");
	}
		else {
			printf("Tipo de media: Ponderada\n");
	}

	printf("Media do aluno: %.3f\n", media);
	
	if (media >= 6.0) {
            printf("Situacao: Aprovado\n");
            aprovados++;
        } 
		else {
			printf("Situacao: Reprovado\n");
            reprovados++;
        }
    }
    // imprime o relatório final quando o usuário encerra
    printf("Relatorio final: \n");
    printf("Total de alunos: %d\n", totalAlunos);
    printf("Media geral dos alunos: %.2f\n", media_geral / totalAlunos);
    printf("Total de alunos aprovados: %d\n", aprovados);
    printf("Total de alunos reprovados: %d\n", reprovados);
    
    system("pause");
    return 0; 
	}


