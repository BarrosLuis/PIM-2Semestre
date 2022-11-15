#include<stdio.h>
#include<locale.h>
#include"modulos.h"

void menu()
{
    system("cls");
    puts("-=-=-=-=-=- SISTEMA DE GEST�O -=-=-=-=-=-");
    puts("[1] - CADASTRAR CLIENTE");
    puts("[2] - MOSTRAR CLIENTES CADASTRADOS");
    puts("[3] - CADASTRAR FUNCION�RIO");
    puts("[4] - MOSTRAR FUNCIN�RIOS CADASTRADOS");
    puts("[5] - SAIR");
    puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-");
    puts("ESOLHA UMA OP��O: ");
}

// FUN��O PARA CADASTRAR CLIENTES E SALVAR OS DADOS.
void cadastro_cliente()
{
    CLIENTE cliente;
    int opcao;

    do
    {
        system("cls");
        puts("-=-=-=-=-=- CADASTRO DE CLIENTE -=-=-=-=-=-");
        getchar();
        puts("NOME DO CLIENTE: ");
        scanf("%[^\n]s", &cliente.nome);

        getchar();
        puts("\nDATA DE NASCIMNETO: ");
        scanf("%[^\n]s", &cliente.nascimento);

        getchar();
        puts("\nCPF: ");
        scanf("%s", &cliente.cpf);

        getchar();
        puts("\nTELEFONE: ");
        scanf("%[^\n]s", &cliente.telefone);

        getchar();
        puts("\nCIDADE ONDE MORA: ");
        scanf("%[^\n]s", &cliente.cidade);

        salvar_cliente(cliente);

        puts("\nDESEJA CONTINUAR? [1 - SIM/ 2 - N�O]");
        scanf("%d", &opcao);

    }while(opcao == 1);
}

// FUN��O QUE RECEBE UMA VARI�VEL DO TIPO CLIENTE E SALVA OS DADOS EM UM ARQUIVO TXT.
void salvar_cliente(CLIENTE cliente)
{
    FILE *fp;
    fp = fopen("clientes.txt", "a");

    fprintf(fp, "%s, ", cliente.nome);
    fprintf(fp, "%s, ", cliente.nascimento);
    fprintf(fp, "%s, ", cliente.cpf);
    fprintf(fp, "%s, ", cliente.telefone);
    fprintf(fp, "%s\n", cliente.cidade);

    fclose(fp);
}

// FUN��O PARA CADASTRAR FUNCION�RIOS E SALVAR OS DADOS.
void cadastro_funcinario()
{
    FUNCIONARIO funcionario;
    int opcao;

    do
    {
        system("cls");
        puts("-=-=-=-=-=- CADASTRO DE FUNCION�RIO -=-=-=-=-=-");
        getchar();
        puts("NOME DO FUNCION�RIO: ");
        scanf("%[^\n]s", &funcionario.nome);

        getchar();
        puts("\nDATA DE NASCIMENTO: ");
        scanf("%[^\n]s", &funcionario.nascimento);

        getchar();
        puts("\nCPF: ");
        scanf("%[^\n]s", &funcionario.cpf);

        getchar();
        puts("\nTELEFONE: ");
        scanf("%[^\n]s", &funcionario.telefone);


        getchar();
        puts("\nCARGO DO FUNCION�RIO: ");
        scanf("%[^\n]s", &funcionario.cargo);

        getchar();
        puts("\nDATA DE INGRESSO: ");
        scanf("%[^\n]s", &funcionario.data_ingresso);


        salvar_funcionario(funcionario);

        puts("\nDESEJA CONTINUAR? [1 - SIM/ 2 - N�O]");
        scanf("%d", &opcao);

    }while(opcao == 1);
}

// FUN��O QUE RECEBE UMA VARI�VEL DO TIPO FUNCION�RIO E SALVA OS DADOS EM UM ARQUIVO TXT.
void salvar_funcionario(FUNCIONARIO funcionario)
{
    FILE *fp;
    fp = fopen("funcionarios.txt", "a");

    fprintf(fp, "%s, ", funcionario.nome);
    fprintf(fp, "%s, ", funcionario.nascimento);
    fprintf(fp, "%s, ", funcionario.cpf);
    fprintf(fp, "%s, ", funcionario.telefone);
    fprintf(fp, "%s, ", funcionario.cargo);
    fprintf(fp, "%s\n", funcionario.data_ingresso);

    fclose(fp);
}

// MOSTRA O CADASTRO DE CLIENTES OU DE FUNCION�RIO DE ACORDO COM A OP��O ESCOLHIDA NO MENU.
void mostrar_cadastro(int opc)
{
    FILE *fp;
    char linha[136];

    if(opc == 2)
    {
        fp = fopen("clientes.txt", "r");

        system("cls");
        puts("-=-=-=-=-=- CLIENTES CADASTRADOS -=-=-=-=-=-");
        while(fgets(linha, 136, fp) != NULL)
        {
            printf("%s", linha);
            puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-");
        }
    }else if(opc == 4)
    {
        fp = fopen("funcionarios.txt", "r");

        system("cls");
        puts("-=-=-=-=-=- FUNCION�RIOS CADASTRADOS -=-=-=-=-=-");
        while(fgets(linha, 136, fp) != NULL)
        {
            printf("%s", linha);
            puts("-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-=-=-=--=-=-");
        }
    }
    puts("\n(aperte qualquer tecla para voltar!)");
    getchar();
    getchar();
}
