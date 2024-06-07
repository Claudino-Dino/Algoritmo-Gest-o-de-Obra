#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char matricula[20],
	nome[50],
	empresa[30],
	data_admissao[20],
	setor_trabalho[20],
	cargo[20],
	epis[20],
	numero_conselho[20],
	salario_base[20],
	gratificacao[20],
	comissao[20];
} funcionarios;

typedef struct
{
	char codigo[20],
	descricao[50],
	tipo_equipamento[20],
	tipo_protecao[20],
	estoque_minimo[20],
	estoque_maximo[20],
	estoque_atual[20],
	valor_unitario[20],
	data_cadastro[20];
} epis;

typedef struct
{
	char codigo_de_obra[20],
	descricao[20],
	endereco[30],
	engenheiro_responsavel[40],
	tipo_de_obra[20],
	area_total_terreno[20],
	metros_quadrados_construir[20],
	custo_previsto_obra[20],
	custo_mao_de_obra[20],
	custo_materia_prima[20],
	custo_real[20],
	data_inicio[20],
	data_fim[20],
	situacao_atual[20],
	motivo_situacao[20],
	percentual_concluido[20];


} canteiro_de_obra;

typedef struct
{
	char codigo[20],
	descicao_da_materia[20],
	quantidade[20],
	preco_unitario[20];
} materia_prima;

int qtde_f = 0, qtde_e = 0, qtde_c = 0, qtde_m = 0;

void menu();

void submenu_impressao(funcionarios *x, epis *y, canteiro_de_obra *z, materia_prima *w);
void impressao_cadastro_funcionarios(funcionarios *x, int *qtde_f);
void impressao_cadastro_epis(epis *y, int *qtde_e);
void impressao_cadastro_canteiro_de_obra(canteiro_de_obra *z, int *qtde_c);
void impressao_cadastro_materia_prima(materia_prima *w, int *qtde_m);

void submenu_cadastros(funcionarios *x, epis *y, canteiro_de_obra *z, materia_prima *w);
void cadastro_de_funcionario(funcionarios *x, int *qtde_f);
void cadastro_de_epis(epis *y, int *qtde_e);
void cadastro_de_canteiro_de_obra(canteiro_de_obra *z, int *qtde_c);
void cadastro_de_materia_prima(materia_prima *w, int *qtde_m);

void tela_acompanhamento_obra(epis *y, canteiro_de_obra *z, materia_prima *w);
void impressao_acompanhamento_obra(canteiro_de_obra *z, int index);

void menu(){
    printf("+===============================================+\n");
    printf("|          GESTAO DE CANTEIRO DE OBRAS          |\n");
    printf("|===============================================|\n");
    printf("|  1-CADASTRO           |  2-IMPRESSAO          |\n");
    printf("|-----------------------------------------------|\n");
    printf("|  3-ACOMPANHAMENTO     |  4-FINALIZAR          |\n");
    printf("|-----------------------------------------------|\n");
    printf("|          INFORME A OPCAO DESEJADA             |\n");
    printf("+===============================================+\n");
}

void template_submenu_cadastro()
{
    printf("+===============================================+\n");
    printf("|               C A D A S T R O S               |\n");
    printf("|===============================================|\n");
    printf("|  1-FUNCIONARIOS       |  2-EPI'S              |\n");
    printf("|-----------------------------------------------|\n");
    printf("|  3-CANTEIRO DE OBRAS  |  4-MATERIA PRIMA      |\n");
    printf("|-----------------------------------------------|\n");
    printf("|         5 - VOLTAR AO MENU PRINCIPAL          |\n");
    printf("|-----------------------------------------------|\n");
    printf("|           INFORME A OPCAO DESEJADA            |\n");
    printf("+===============================================+\n");
}

void template_submenu_impressao()
{
	printf("+===============================================+\n");
    printf("|              MENU DE IMPRESSAO                |\n");
    printf("|===============================================|\n");
    printf("| 1-FUNCIONARIOS      |  2-EPI's                |\n");
    printf("|-----------------------------------------------|\n");
    printf("| 3-CANTEIRO DE OBRAS |  4-MATERIA PRIMA        |\n");
    printf("|-----------------------------------------------|\n");
    printf("|        5 - VOLTAR AO MENU PRINCIPAL           |\n");
    printf("|-----------------------------------------------|\n");
    printf("|          INFORME A OPCAO DESEJADA             |\n");
    printf("+===============================================+\n");
}

void submenu_cadastros(funcionarios *x, epis *y, canteiro_de_obra *z, materia_prima *w)
{
    int opcao = 0;

    while (opcao != 5)
    {
		template_submenu_cadastro();

		scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastro_de_funcionario(x, &qtde_f);
            break;
        case 2:
            cadastro_de_epis(y, &qtde_e);
            break;
        case 3:
            cadastro_de_canteiro_de_obra(z, &qtde_c);
            break;
        case 4:
            cadastro_de_materia_prima(w, &qtde_m);
            break;
        default:
            printf("Digite uma opcao valida!\n");
            break;
        }

		system("cls");
    }
}

void cadastro_de_funcionario(funcionarios *x, int *qtde_f)
{
    int i, n;

    printf("Informe a quantidade de cadastros: ");
    scanf("%d", &n);
	fflush(stdin);

    system("cls");

    if (n == 0) {
        printf("Nenhum cadastro para realizar\n");
        system("pause");
        return;
    }

    for (i = 0; i < n; i++)
    {
        printf("INFORME A MATRICULA: ");
        scanf("%s", x[*qtde_f].matricula);

        printf("INFORME O NOME: ");
        scanf("%s", x[*qtde_f].nome);

        printf("INFORME A EMPRESA: ");
        scanf("%s", x[*qtde_f].empresa);

        printf("INFORME A DATA DE ADMISSAO: ");
        scanf("%s", x[*qtde_f].data_admissao);

        printf("INFORME O SETOR DE TRABALHO: ");
        scanf("%s", x[*qtde_f].setor_trabalho);

        printf("INFORME O CARGO: ");
        scanf("%s", x[*qtde_f].cargo);

        printf("RECEBE EPI's (SIM - S/ NAO - N): ");
        scanf("%s", x[*qtde_f].epis);

        printf("INFORME O NUMERO DO CONSELHO: ");
        scanf("%s", x[*qtde_f].numero_conselho);

        printf("INFORME O SALARIO BASE: ");
        scanf("%s", x[*qtde_f].salario_base);

        printf("INFORME A GRATIFICACAO: ");
        scanf("%s", x[*qtde_f].gratificacao);

        printf("INFORME A COMISSAO: ");
        scanf("%s", x[*qtde_f].comissao);

        printf("Cadastro Realizado Com Sucesso!\n");

        (*qtde_f)++;
    }

	system("pause");

	system("cls");

}

void cadastro_de_epis(epis *y, int *qtde_e) 
{
    int i, n;

    printf("Informe a quantidade de cadastros: ");
    scanf("%d", &n);

    system("cls");

    if (n == 0) {
        printf("Nenhum cadastro para realizar\n");
        system("pause");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("INFORME O CODIGO: ");
        scanf("%s", y[*qtde_e].codigo);

        printf("INFORME A DESCRICAO: ");
        scanf("%s", y[*qtde_e].descricao);

        printf("INFORME O TIPO DE EQUIPAMENTO: ");
        scanf("%s", y[*qtde_e].tipo_equipamento);

        printf("INFORME O TIPO DE PROTECAO: ");
        scanf("%s", y[*qtde_e].tipo_protecao);

        printf("INFORME O ESTOQUE MINIMO: ");
        scanf("%s", y[*qtde_e].estoque_minimo);

        printf("INFORME O ESTOQUE MAXIMO: ");
        scanf("%s", y[*qtde_e].estoque_maximo);

        printf("INFORME O ESTOQUE ANUAL: ");
        scanf("%s", y[*qtde_e].estoque_atual);

        printf("INFORME O VALOR UNITARIO: ");
        scanf("%s", y[*qtde_e].valor_unitario);

        printf("INFORME A DATA DE CADASTRO: ");
        scanf("%s", y[*qtde_e].data_cadastro);

        printf("Cadastro Realizado Com Sucesso!\n");

        (*qtde_e)++;
    }

    system("pause");
    system("cls");
}

void cadastro_de_canteiro_de_obra(canteiro_de_obra *z, int *qtde_c)
{
    int i, n;

    printf("Informe a quantidade de cadastros: ");
    scanf("%d", &n);
	fflush(stdin);

    system("cls");

    if (n == 0) {
        printf("Nenhum cadastro para realizar\n");
        system("pause");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("INFORME O CODIGO DA OBRA: ");
        scanf("%s", z[*qtde_c].codigo_de_obra);
		fflush(stdin);

        printf("INFORME A DESCRICAO: ");
        scanf("%20[^z\n]s", z[*qtde_c].descricao);

        printf("INFORME O ENDERECO: ");
        scanf("%s", z[*qtde_c].endereco);
		fflush(stdin);

        printf("INFORME O ENGENHEIRO RESPONSAVEL: ");
        scanf("%40[^z\n]s", z[*qtde_c].engenheiro_responsavel);

        printf("INFORME O TIPO DE OBRA: ");
        scanf("%s", z[*qtde_c].tipo_de_obra);

        printf("INFORME A AREA TOTAL DO TERRENO: ");
        scanf("%s", z[*qtde_c].area_total_terreno);

        printf("INFORME OS METROS QUADRADOS A CONSTRUIR: ");
        scanf("%s", z[*qtde_c].metros_quadrados_construir);

        printf("INFORME O CUSTO PREVISTO DA OBRA: ");
        scanf("%s", z[*qtde_c].custo_previsto_obra);

        printf("INFORME O CUSTO DA MAO DE OBRA: ");
        scanf("%s", z[*qtde_c].custo_mao_de_obra);
		
		printf("INFORME O CUSTO COM MATERIA PRIMA: ");
        scanf("%s", z[*qtde_c].custo_materia_prima);

        printf("INFORME O CUSTO REAL: ");
        scanf("%s", z[*qtde_c].custo_real);

		printf("INFORME A DATA DE INICIO: ");
        scanf("%s", z[*qtde_c].data_inicio);

        printf("INFORME A DATA DE FIM: ");
        scanf("%s", z[*qtde_c].data_fim);

        printf("INFORME A SITUACAO ATUAL (Parada/Cancelada/Pendente/Concluida): ");
        scanf("%s", z[*qtde_c].situacao_atual);

        printf("INFORME O MOTIVO DA SITUACAO: ");
        scanf("%s", z[*qtde_c].motivo_situacao);

        printf("INFORME O PERCENTUAL CONCLUIDO: ");
        scanf("%s", z[*qtde_c].percentual_concluido);


        printf("Cadastro Realizado Com Sucesso!\n");

        (*qtde_c)++;
    }

    system("pause");
    system("cls");
}

void cadastro_de_materia_prima(materia_prima *w, int *qtde_m)
{

    int i, n;

    printf("Informe a quantidade de cadastros: ");
    scanf("%d", &n);
	fflush(stdin);

    if (n == 0) {
        printf("Nenhum cadastro para realizar\n");
        system("pause");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("INFORME O CODIGO: ");
        scanf("%s", w[*qtde_m].codigo);

        printf("INFORME A DESCRICAO DA MATERIA: ");
        scanf("%s", w[*qtde_m].descicao_da_materia);

        printf("INFORME A QUANTIDADE: ");
        scanf("%s", w[*qtde_m].quantidade);

        printf("INFORME O PRECO UNITARIO: ");
        scanf("%s", w[*qtde_m].preco_unitario);

        printf("Cadastro Realizado Com Sucesso!\n");

        (*qtde_m)++;
    }

    system("pause");
    system("cls");
}

void impressao_cadastro_funcionarios(funcionarios *x, int *qtde_f)
{
    int i;

	system("cls");

    for (i = 0; i < *qtde_f; i++) {
        printf("+===============================================+\n");
        printf("|          F U N C I O N A R I O -> %d\n", i + 1);
        printf("|===============================================|\n");
        printf("|MATRICULA           -> %s\n", x[i].matricula);
        printf("|-----------------------------------------------|\n");
        printf("|NOME                -> %s\n", x[i].nome);
        printf("|-----------------------------------------------|\n");
        printf("|EMPRESA             -> %s\n", x[i].empresa);
        printf("|-----------------------------------------------|\n");
        printf("|DATA DE ADMISSAO    -> %s\n", x[i].data_admissao);
        printf("|-----------------------------------------------|\n");
        printf("|SETOR DE TRABALHO   -> %s\n", x[i].setor_trabalho);
        printf("|-----------------------------------------------|\n");
        printf("|CARGO               -> %s\n", x[i].cargo);
        printf("|-----------------------------------------------|\n");
        printf("|RECEBE EPIS         -> %s\n", x[i].epis);
        printf("|-----------------------------------------------|\n");
        printf("|NUMERO DE CONSELHO  -> %s\n", x[i].numero_conselho);
        printf("|-----------------------------------------------|\n");
        printf("|SALARIO BASE        -> %s\n", x[i].salario_base);
        printf("|-----------------------------------------------|\n");
        printf("|RECEBE GRATIFICACAO -> %s\n", x[i].gratificacao);
        printf("|-----------------------------------------------|\n");
        printf("|COMISSAO            -> %s\n", x[i].comissao);
        printf("+===============================================+\n");

		system("pause");
    }
	system("cls");
}

void impressao_cadastro_epis(epis *y, int *qtde_e)
{
    int i;

	system("cls");

    for (i = 0; i < *qtde_e; i++) {
        printf("+===============================================+\n");
        printf("|                 E P I 's -> %d\n", i + 1);
        printf("|===============================================|\n");
        printf("|CODIGO              -> %s\n", y[i].codigo);
        printf("|-----------------------------------------------|\n");
        printf("|DESCRICAO           -> %s\n", y[i].descricao);
        printf("|-----------------------------------------------|\n");
        printf("|TIPO DE EQUIPAMENTO -> %s\n", y[i].tipo_equipamento);
        printf("|-----------------------------------------------|\n");
        printf("|DATA DE ADMISSAO    -> %s\n", y[i].tipo_protecao);
        printf("|-----------------------------------------------|\n");
        printf("|SETOR DE TRABALHO   -> %s\n", y[i].estoque_minimo);
        printf("|-----------------------------------------------|\n");
        printf("|CARGO               -> %s\n", y[i].estoque_maximo);
        printf("|-----------------------------------------------|\n");
        printf("|RECEBE EPIS         -> %s\n", y[i].estoque_atual);
        printf("|-----------------------------------------------|\n");
        printf("|NUMERO DE CONSELHO  -> %s\n", y[i].valor_unitario);
        printf("|-----------------------------------------------|\n");
        printf("|SALARIO BASE        -> %s\n", y[i].data_cadastro);
        printf("+===============================================+\n");

		system("pause");
    }
	system("cls");
}

void impressao_cadastro_canteiro_de_obra(canteiro_de_obra *z, int *qtde_c)
{
    int i;

	system("cls");

    for (i = 0; i < *qtde_c; i++) {
        printf("+===============================================+\n");
        printf("|              CANTEIRO DE OBRA -> %d\n", i + 1);
        printf("|===============================================|\n");
        printf("|CODIGO DA OBRA               -> %s\n", z[i].codigo_de_obra);
        printf("|-----------------------------------------------|\n");
        printf("|DESCRICAO                    -> %s\n", z[i].descricao);
        printf("|-----------------------------------------------|\n");
        printf("|ENDERECO                     -> %s\n", z[i].endereco);
        printf("|-----------------------------------------------|\n");
        printf("|ENGENHEIRO RESPOSAVEL        -> %s\n", z[i].engenheiro_responsavel);
        printf("|-----------------------------------------------|\n");
        printf("|TIPO DE OBRA                 -> %s\n", z[i].tipo_de_obra);
        printf("|-----------------------------------------------|\n");
        printf("|AREA TOTAL DO TERRENO        -> %s\n", z[i].area_total_terreno);
        printf("|-----------------------------------------------|\n");
        printf("|METROS QUADRADOS A CONSTRUIR -> %s\n", z[i].metros_quadrados_construir);
        printf("|-----------------------------------------------|\n");
        printf("|CUSTO PREVISTO DA OBRA       -> %s\n", z[i].custo_previsto_obra);
        printf("|-----------------------------------------------|\n");
        printf("|CUSTO DA MAO DE OBRA         -> %s\n", z[i].custo_mao_de_obra);
        printf("|-----------------------------------------------|\n");
        printf("|CUSTO COM MATERIA PRIMA      -> %s\n", z[i].custo_materia_prima);
        printf("|-----------------------------------------------|\n");
        printf("|CUSTO REAL                   -> %s\n", z[i].custo_real);
		printf("|-----------------------------------------------|\n");
        printf("|DATA DE INICIO               -> %s\n", z[i].custo_previsto_obra);
        printf("|-----------------------------------------------|\n");
        printf("|DATA DE FIM                  -> %s\n", z[i].custo_mao_de_obra);
        printf("|-----------------------------------------------|\n");
        printf("|SITUACAO ATUAL               -> %s\n", z[i].custo_materia_prima);
        printf("|-----------------------------------------------|\n");
        printf("|MOTIVO DA SITUACAO           -> %s\n", z[i].custo_real);
        printf("+===============================================+\n");

		system("pause");
    }
	system("cls");
}

void impressao_cadastro_materia_prima(materia_prima *w, int *qtde_m)
{
    int i;

	system("cls");

    for (i = 0; i < *qtde_m; i++) {
        printf("+===============================================+\n");
        printf("|             MATERIA PRIMA -> %d\n", i + 1);
        printf("|===============================================|\n");
        printf("|CODIGO              -> %s\n", w[i].codigo);
        printf("|-----------------------------------------------|\n");
        printf("|DESCRICAO           -> %s\n", w[i].descicao_da_materia);
        printf("|-----------------------------------------------|\n");
        printf("|TIPO DE EQUIPAMENTO -> %s\n", w[i].quantidade);
        printf("|-----------------------------------------------|\n");
        printf("|DATA DE ADMISSAO    -> %s\n", w[i].preco_unitario);
        printf("+===============================================+\n");

		system("pause");
    }
	system("cls");
}

void submenu_impressao(funcionarios *x, epis *y, canteiro_de_obra *z, materia_prima *w)
{
    int op = 0;

    while (op != 5)
    {
        template_submenu_impressao();

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            impressao_cadastro_funcionarios(x, &qtde_f);
            break;
        case 2:
			impressao_cadastro_epis(y, &qtde_e);
            break;
        case 3:
            impressao_cadastro_canteiro_de_obra(z, &qtde_c);
            break;
        case 4:
            impressao_cadastro_materia_prima(w, &qtde_m);
            break;
        case 5:
            system("cls");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    }
}

void tela_acompanhamento_obra(epis *y, canteiro_de_obra *z, materia_prima *w) {
    char codigo_procurado[20];
    int i;

    printf("Informe o codigo da obra: ");
    scanf("%s", codigo_procurado);

    for (i = 0; i < qtde_c; i++) {
        if (strcmp(z[i].codigo_de_obra, codigo_procurado) == 0) {
            impressao_acompanhamento_obra(z, i);
            return;
        }
    }
    printf("Obra nao encontrada!\n");
    system("pause");
}

void impressao_acompanhamento_obra(canteiro_de_obra *z, int index) {
    printf("\n+==============================================+\n");
    printf("|          ACOMPANHAMENTO DA OBRA               |\n");
    printf("+===============================================+\n");
    printf("|CODIGO DA OBRA: %s\n", z[index].codigo_de_obra);
	printf("|-----------------------------------------------|\n");
    printf("|DESCRICAO: %s\n", z[index].descricao);
	printf("|-----------------------------------------------|\n");
    printf("|ENDERECO: %s\n", z[index].endereco);
	printf("|-----------------------------------------------|\n");
    printf("|ENGENHEIRO RESPONSAVEL: %s\n", z[index].engenheiro_responsavel);
	printf("|-----------------------------------------------|\n");
    printf("|TIPO DE OBRA: %s\n", z[index].tipo_de_obra);
	printf("|-----------------------------------------------|\n");
    printf("|ARE TOTAL DO TERRENO: %s\n", z[index].area_total_terreno);
	printf("|-----------------------------------------------|\n");
    printf("|METROS QUADRADOS A CONSTRUIR: %s\n", z[index].metros_quadrados_construir);
	printf("|-----------------------------------------------|\n");
    printf("|CUSTO PREVISTO DA OBRA: %s\n", z[index].custo_previsto_obra);
	printf("|-----------------------------------------------|\n");
    printf("|CUSTO DA MAO DE OBRA: %s\n", z[index].custo_mao_de_obra);
	printf("|-----------------------------------------------|\n");
    printf("|CUSTO DA MATERIA PRIMA: %s\n", z[index].custo_materia_prima);
	printf("|-----------------------------------------------|\n");
    printf("|CUSTO REAL: %s\n", z[index].custo_real);
	printf("|-----------------------------------------------|\n");
    printf("|DATA DE INICIO: %s\n", z[index].data_inicio);
	printf("|-----------------------------------------------|\n");
    printf("|DATA DE FIM: %s\n", z[index].data_fim);
	printf("|-----------------------------------------------|\n");
    printf("|SITUACAO ATUAL: %s\n", z[index].situacao_atual);
	printf("|-----------------------------------------------|\n");
    printf("|MOTIVO DA SITUACAO: %s\n", z[index].motivo_situacao);
	printf("|-----------------------------------------------|\n");
    printf("|PERCENTUAL CONCLUIDO: %s\n", z[index].percentual_concluido);
	printf("+===============================================+\n");

    if (strcmp(z[index].situacao_atual, "Concluida") == 0) {
        printf("Custo Final da Obra: %s\n", z[index].custo_real);
    }

    printf("+===============================================+\n");
    system("pause");
}

int main()
{
    funcionarios lista_funcionarios[100];
	epis lista_epis[100];
	canteiro_de_obra lista_canteiro_de_obra[100];
	materia_prima lista_materia_prima[100];

    int op = 0;

    while (op != 4)
    {
        system("cls");
        menu();
        printf("Selecione uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            submenu_cadastros(lista_funcionarios, lista_epis, lista_canteiro_de_obra, lista_materia_prima);
            break;
        case 2:
            system("cls");
            submenu_impressao(lista_funcionarios, lista_epis, lista_canteiro_de_obra, lista_materia_prima);
            break;
        case 3:
            system("cls");
            tela_acompanhamento_obra(lista_epis, lista_canteiro_de_obra, lista_materia_prima);
            break;
        case 4:
            system("cls");
            printf("Finalizando...\n");
            exit(0);
        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    }

    return 0;
}
