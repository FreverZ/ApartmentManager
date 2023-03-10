/**
 * @authors Carlos Brandão(26025), Pedro Simões(26535)
 * Written in VSCode
**/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define TAM 100

typedef struct praticante
{
    char num[5];  //utilizamos strings para o codigo do usuário para que no ficheiro grave com os zeros (ex: 0012)
    char nome[20]; 
    int tlm;    
    int age;     
} Praticante;

typedef struct atividade
{
    char num[5];
    char ativ[15];
    char data[20];
    int duracao, dist;
} Atividade;

typedef struct plano
{
    char num[5];
    char ativ[15];
    int dist;
    char data[20];
    char datain[20];
    char datafim[20];
    char hora[20];  
    char horain[20];  
    char horafim[20]; 
} Plano;
/*-----------------------------FUNCAO UTILIZADA PARA CONTAR O NÚMERO DE ATLETAS ATRAVÉS DO NÚMERO DE LINHAS-----------------------------*/
int numatletas()
{
        int linhas = 0;
        char c;
        FILE *fp = fopen("dados.txt", "r");
        if (fp != NULL)
        {
        do
        {
                if (c == '\n')
                {
                        linhas++;
                }
        } while ((c = fgetc(fp)) != EOF);
        fclose(fp);
        return linhas;
        }
}
/*-----------------------------FUNCAO UTILIZADA PARA REMOVER /n QUE "fgets()"" COLOCA NO FIM DE CADA STRING-----------------------------*/
void removebarran(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
            if (str[i] == '\n')
            {
                    str[i] = '\0';
            }
    }
}
/*-----------------------------FUNCAO UTILIZADA PARA ADICIONAR ATLETAS À BASE DE DADOS-----------------------------*/
void addatleta()
{
    Praticante atleta;
    FILE* fp;

    fp = fopen("dados.txt", "a");
    if (fp != NULL)
    {
        fflush(stdin);
        printf("Indique o seu codigo (com os zeros, ex: 0123)\n");
        fgets(atleta.num, 5, stdin);
        atleta.num[5] = '\0'; // remover /n que fgets coloca desnecessariamente
        fflush(stdin);

        printf("Indique o seu nome\n");
        fgets(atleta.nome, 20, stdin);
        removebarran(atleta.nome); // remover /n que fgets coloca desnecessariamente
        fflush(stdin);

        printf("Indique o seu numero de telemovel\n");
        scanf("%d", &atleta.tlm);
        fflush(stdin);

        printf("Indique a sua idade\n");
        scanf("%d", &atleta.age);
        fflush(stdin);

        fprintf(fp, "%s;%s;%d;%d\n", atleta.num, atleta.nome, atleta.tlm, atleta.age); // escreve no ficheiro
    }
    fclose(fp);
}
/*-----------------------------FUNCAO UTILIZADA PARA ADICIONAR AS ATIVIDADES DE CADA ATLETA À BASE DE DADOS-----------------------------*/
void addativ()
{
    Atividade atleta;
    FILE *fp;

    fp = fopen("info_ativ.txt", "a");
    if (fp != NULL)
    {
        fflush(stdin);
        printf("Indique o seu codigo (com os zeros, ex: 0123)\n");
        fgets(atleta.num, 5, stdin);
        removebarran(atleta.num); // remover /n que fgets coloca desnecessariamente
        fflush(stdin);

        printf("Indique a atividade que planeia realizar\n");
        fgets(atleta.ativ, 15, stdin);
        removebarran(atleta.ativ); // remover /n que fgets coloca desnecessariamente
        fflush(stdin);

        printf("Indique a data em que planeia realizar a atividade (formato: dd-mm-aaaa)\n");
        fgets(atleta.data, 20, stdin);
        removebarran(atleta.data);
        fflush(stdin);

        printf("Indique a duracao da atividade em minutos (horas * 60 = minutos)\n");
        scanf("%d", &atleta.duracao);
        fflush(stdin);

        printf("Indique quantos kilometros planeia fazer (nao pode conter virgulas)\n");
        scanf("%d", &atleta.dist);
        fflush(stdin);

        fprintf(fp, "%s;%s;%s;%d;%dkm\n", atleta.num, atleta.data, atleta.ativ, atleta.duracao, atleta.dist); // escreve no ficheiro
    }
    fclose(fp);
}
/*-----------------------------FUNCAO UTILIZADA PARA ADICIONAR OS PLANOS DE ATIVIDADES DE CADA ATLETA À BASE DE DADOS-----------------------------*/
void addplanativ()
{
    Plano atleta;
    FILE *fp;

    fp = fopen("plan_ativ.txt", "a");
    if (fp != NULL)
    {
        fflush(stdin);
        printf("Indique o seu codigo (com os zeros, ex: 0123)\n");
        fgets(atleta.num, 5, stdin);
        removebarran(atleta.num); // remover /n que fgets coloca desnecessariamente
        fflush(stdin);

        printf("Indique a data de inicio da atividade (formato: dd-mm-aaaa)\n");
        fgets(atleta.datain, 20, stdin);
        removebarran(atleta.datain); // remover /n que fgets coloca desnecessariamente
        printf("Indique as horas a que comecou (formato: 12h34)");
        fgets(atleta.horain, 20, stdin);
        removebarran(atleta.horain); // remover /n que fgets coloca desnecessariamente
        fflush(stdin);

        printf("Indique a data de fim da atividade (formato: dd-mm-aaaa)\n");
        fgets(atleta.datafim, 20, stdin);
        removebarran(atleta.datafim); // remover /n que fgets coloca desnecessariamente
        printf("Indique as horas a que acabou (formato: 12h34)\n");
        fgets(atleta.horafim, 20, stdin);
        removebarran(atleta.horafim); // remover /n que fgets coloca desnecessariamente
        fflush(stdin);

        printf("Indique a atividade que planeia realizar (Exemplos: Btt, Natacao, Marcha, etc.)\n");
        fgets(atleta.ativ, 15, stdin);
        removebarran(atleta.ativ); // remover /n que fgets coloca desnecessariamente
        fflush(stdin);

        printf("Indique quantos kilometros planeia realizar (nao pode conter virgulas)\n");
        scanf("%d", &atleta.dist);
        fflush(stdin);

        fprintf(fp, "%s;%s;%s;%s;%s;%s;%dkm\n", atleta.num, atleta.datain, atleta.horain, atleta.datafim, atleta.horafim, atleta.ativ, atleta.dist);
        // escreve no ficheiro
    }
    fclose(fp);
}
/*-----------------------------FUNCAO UTILIZADA PARA CONTAR O NÚMERO DE PRATICANTES QUE REALIZARAM X ATIVIDADE ENTRE Y DATAS-----------------------------*/
void numpraticantes()
{
        Atividade atleta[TAM];
        FILE *fp;
        int dist;
        int dia[TAM], mes[TAM], ano[TAM];
        int dia1, mes1, ano1;
        int dia2, mes2, ano2;
        int scoredata1, scoredata2, scoredataatleta;
        char ativididade[15];
        int i = 0, contador = 0;

        printf("Indique a atividade (Exemplos: Btt, Natacao, Marcha, etc.)\n");
        scanf("%s", ativididade);
        printf("Indique a data de inicio (formato: dd-mm-aaaa)\n");
        scanf("%d-%d-%d", &dia1,&mes1,&ano1);
        printf("Indique a data final (formato: dd-mm-aaaa)\n");
        scanf("%d-%d-%d", &dia2, &mes2, &ano2);

                scoredata1 = dia1 + mes1 * 100 + ano1 * 2000;
                scoredata2 = dia2 + mes2 * 100 + ano2 * 2000;

        fp = fopen("info_ativ.txt", "r");
        if (fp != NULL)
        {
        do
        {
                fscanf(fp, "%[^;];%d-%d-%d;%[^;];%d;%d\n", atleta[i].num, &dia[i], &mes[i], &ano[i], atleta[i].ativ, &atleta[i].duracao, &atleta[i].dist);
                scoredataatleta = dia[i] + mes[i] * 100 + ano[i] * 2000;

                if (strcmp(atleta[i].ativ, ativididade) == 0 && scoredataatleta > scoredata1 && scoredataatleta < scoredata2)
                contador++;
                i++;
        } while (!feof(fp));
        }
        printf("Nesse espaco de tempo, %d atletas praticaram %s.\n", contador, ativididade);
        fclose(fp);
}
/*-----------------------------FUNCAO UTILIZADA PARA MOSTRAR O NÚMERO DOS PRATICANTES QUE REALIZARAM X ATIVIDADE ENTRE Y DATAS-----------------------------*/
void listpraticantes()
{
        Atividade atleta[TAM];
        FILE *fp;
        int dist, num[TAM];
        int dia[TAM], mes[TAM], ano[TAM];
        int dia1, mes1, ano1;
        int dia2, mes2, ano2;
        int scoredata1, scoredata2, scoredataatleta;
        int i = 0;

        printf("Indique a data de inicio (formato: dd-mm-aaaa)\n");
        scanf("%d-%d-%d", &dia1, &mes1, &ano1);
        printf("Indique a data final (formato: dd-mm-aaaa)\n");
        scanf("%d-%d-%d", &dia2, &mes2, &ano2);

        scoredata1 = dia1 + mes1 * 100 + ano1 * 2000;  //isto dá um "score" à data para que possamos utilizar esse "score" para comparar com outras datas. Desta forma digamos que o score do ano é 2000* mais importante do que o dia, e que o mês é 100* mais importante que o dia
        scoredata2 = dia2 + mes2 * 100 + ano2 * 2000;

        printf("Praticantes que realizaram alguma atividade nesse espaco de tempo:\n");

        fp = fopen("info_ativ.txt", "r");
        if (fp != NULL)
        {
        do
        {
                fscanf(fp, "%[^;];%d-%d-%d;%[^;];%d;%d\n", atleta[i].num, &dia[i], &mes[i], &ano[i], atleta[i].ativ, &atleta[i].duracao, &atleta[i].dist);

                scoredataatleta = dia[i] + mes[i] * 100 + ano[i] * 2000;

                if (scoredataatleta > scoredata1 && scoredataatleta < scoredata2)
                {
                printf("%s\n", atleta[i].num);
                i++;
                }
        } while (!feof(fp));
        }
        fclose(fp);
}
/*-----------------------------FUNCAO UTILIZADA PARA MOSTRAR PLANO DE CERTO ATLETA-----------------------------*/
void planoativatleta()
{
        Plano plan[TAM];
        FILE *fp;
        int dist;
        int diain[TAM], mesin[TAM], anoin[TAM];
        int diafim[TAM], mesfim[TAM], anofim[TAM];
        int dia1, mes1, ano1;
        int dia2, mes2, ano2;
        int scoredata1, scoredata2, scoredataatletain, scoredataatletafim;
        int i = 0;

        printf("Indique a data de inicio (formato: dd-mm-aaaa)\n");
        scanf("%d-%d-%d", &dia1, &mes1, &ano1);
        printf("Indique a data final (formato: dd-mm-aaaa)\n");
        scanf("%d-%d-%d", &dia2, &mes2, &ano2);

        scoredata1 = dia1 + mes1 * 100 + ano1 * 2000;
        scoredata2 = dia2 + mes2 * 100 + ano2 * 2000;

        fp = fopen("plan_ativ.txt", "r");
        if (fp != NULL)
        {
        do
        {
                fscanf(fp, "%[^;];%d-%d-%d;%[^;];%d-%d-%d;%[^;];%[^;];%d\n", plan[i].num, &diain[i], &mesin[i], &anoin[i], plan[i].horain, &diafim[i], &mesfim[i], &anofim[i], plan[i].horafim, plan[i].ativ, &plan[i].dist);
                scoredataatletain = diain[i] + mesin[i] * 100 + anoin[i] * 2000;
                scoredataatletafim = diafim[i] + mesfim[i] * 100 + anofim[i] * 2000;

                if (scoredataatletain > scoredata1 && scoredataatletafim < scoredata2)
                {
                        printf("O atleta de numero %s planeia realizar %s entre essas datas.\n", plan[i].num, plan[i].ativ);
                }
                i++;
        } while (!feof(fp));
        }
        printf("");
        fclose(fp);
}
/*-----------------------------FUNCAO UTILIZADA PARA MOSTRAR AS MÉDIAS DE TEMPOS DE PRÁTICA DAS ATIVIDADES DE TODOS OS ATLETAS-----------------------------*/
void mediastempo()
{
        Atividade atleta[TAM];
        FILE *fp;
        float media = 0;
        int i=0;
        int dia[TAM], mes[TAM], ano[TAM];

        fp = fopen("info_ativ.txt", "r");
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%d-%d-%d;%[^;];%d;%d\n", atleta[i].num, &dia[i], &mes[i], &ano[i], atleta[i].ativ, &atleta[i].duracao, &atleta[i].dist);
                        i++;
                }
                while (!feof(fp));
        };
        for (i = 0; i < numatletas(); i++)
        {
                media += atleta[i].duracao;
        }
        media /= numatletas();

        printf("A media dos tempos que os atletas praticaram foi %.2f minutos.\n", media);
        fclose(fp);
}
/*-----------------------------TABELA DE ATIVIDADES PLANEADAS E REALIZADAS-----------------------------*/
void tabelaplanreal()
{
        Praticante atleta[TAM];
        Atividade ativ[TAM];
        Plano plan[TAM];
        FILE *fp;
        int i = 0;

        fp = fopen("dados.txt", "r");
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%[^;];%d;%d\n", atleta[i].num, atleta[i].nome, &atleta[i].tlm, &atleta[i].age);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        fp = fopen("info_ativ.txt", "r");
        i = 0;
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%[^;];%[^;];%d;%d\n", ativ[i].num, ativ[i].data, ativ[i].ativ, &ativ[i].duracao, &ativ[i].dist);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        fp = fopen("plan_ativ.txt", "r");
        i = 0;
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d\n", plan[i].num, plan[i].datain, plan[i].horain, plan[i].datafim, plan[i].horafim, plan[i].ativ, &plan[i].dist);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        printf("| Numero |   Nome   | Ativ. Plan. | Distancia (km) | Ativ. Real. |    Data    | Distancia (km) |\n");
        for (i = 0; i < numatletas() ; i++)
        {
                printf("------------------------------------------------------------------------------------------------\n");
                printf("|  %s  |   %s   |   %s   |       %d       |   %s   |   %s   |       %d       |\n", atleta[i].num, atleta[i].nome, plan[i].ativ, plan[i].dist, ativ[i].ativ, ativ[i].data, ativ[i].dist);
        }
}
/*-----------------------------TABELA FINAL-----------------------------*/
void tabelafinal()
{
        Praticante atleta[TAM];
        Atividade ativ[TAM];
        Plano plan[TAM];
        FILE *fp;
        int i = 0;
        int diain, mesin, anoin, diafim, mesfim, anofim;
        int scoredata1, scoredata2;
        int scoredataatleta[TAM];
        int dia[TAM], mes[TAM], ano[TAM];

        fp = fopen("dados.txt", "r");
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%[^;];%d;%d\n", atleta[i].num, atleta[i].nome, &atleta[i].tlm, &atleta[i].age);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        fp = fopen("info_ativ.txt", "r");
        i = 0;
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%d-%d-%d;%[^;];%d;%d\n", ativ[i].num, &dia[i], &mes[i], &ano[i], ativ[i].ativ, &ativ[i].duracao, &ativ[i].dist);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        fp = fopen("plan_ativ.txt", "r");
        i = 0;
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d\n", plan[i].num, plan[i].datain, plan[i].horain, plan[i].datafim, plan[i].horafim, plan[i].ativ, &plan[i].dist);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        fflush(stdin);
        printf("Indique a data de inicio\n");
        scanf("%d-%d-%d", &diain, &mesin, &anoin);
        fflush(stdin);
        printf("Indique a data de fim\n");
        scanf("%d-%d-%d", &diafim, &mesfim, &anofim);
        fflush(stdin);

        scoredata1 = diain + mesin * 100 + anoin * 2000;
        scoredata2 = diafim + mesfim * 100 + anofim * 2000;

        printf("| Numero |   Nome   | Data Inicio | Data Fim | Dist Total (km) | Duracao Total (minutos) | Dia em que praticou |\n");
        for (i = 0; i < numatletas(); i++)
        {
                scoredataatleta[i] = dia[i] + mes[i] * 100 + ano[i] * 2000;
                if (scoredataatleta[i] > scoredata1 && scoredataatleta[i] < scoredata2)
                {
                        printf("----------------------------------------------------------------------------------------------------------------\n");
                        printf("|  %s  |   %s   |  %d-%d-%d  |  %d-%d-%d  |       %d       |        %d        |     %d-%d-%d     |\n", atleta[i].num, atleta[i].nome, diain, mesin, anoin, diafim, mesfim, anofim, ativ[i].dist, ativ[i].duracao, dia[i], mes[i], ano[i]);
                }
        }
}
/*-----------------------------EXPORTAR PARA FICHEIRO BINARIO-----------------------------*/
void exportarbinario()
{
             Praticante atleta[TAM];
        Atividade ativ[TAM];
        Plano plan[TAM];
        FILE *fp;
        FILE *fd;
        int i = 0;
        int diain, mesin, anoin, diafim, mesfim, anofim;
        int scoredata1, scoredata2;
        int scoredataatleta[TAM];
        int dia[TAM], mes[TAM], ano[TAM];

        fp = fopen("dados.txt", "r");
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%[^;];%d;%d\n", atleta[i].num, atleta[i].nome, &atleta[i].tlm, &atleta[i].age);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        fp = fopen("info_ativ.txt", "r");
        i = 0;
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%d-%d-%d;%[^;];%d;%d\n", ativ[i].num, &dia[i], &mes[i], &ano[i], ativ[i].ativ, &ativ[i].duracao, &ativ[i].dist);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        fp = fopen("plan_ativ.txt", "r");
        i = 0;
        if (fp != NULL)
        {
                do
                {
                        fscanf(fp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d\n", plan[i].num, plan[i].datain, plan[i].horain, plan[i].datafim, plan[i].horafim, plan[i].ativ, &plan[i].dist);
                        i++;
                } while (!feof(fp));
        };
        fclose(fp);

        fflush(stdin);
        printf("Indique a data de inicio\n");
        scanf("%d-%d-%d", &diain, &mesin, &anoin);
        fflush(stdin);
        printf("Indique a data de fim\n");
        scanf("%d-%d-%d", &diafim, &mesfim, &anofim);
        fflush(stdin);

        scoredata1 = diain + mesin * 100 + anoin * 2000;
        scoredata2 = diafim + mesfim * 100 + anofim * 2000;
        
        fd = fopen("tabela_final.bin", "wb");
        if (fp != NULL)
        {
                fprintf(fd, "| Numero |   Nome   | Data Inicio | Data Fim | Dist Total (km) | Duracao Total (minutos) | Dia em que praticou |\n");
                for (i = 0; i < numatletas(); i++)
                {
                        scoredataatleta[i] = dia[i] + mes[i] * 100 + ano[i] * 2000;
                        if (scoredataatleta[i] > scoredata1 && scoredataatleta[i] < scoredata2)
                        {
                        fprintf(fd, "----------------------------------------------------------------------------------------------------------------\n");
                        fprintf(fd, "|  %s  |   %s   |  %d-%d-%d  |  %d-%d-%d  |       %d       |        %d        |     %d-%d-%d     |\n", atleta[i].num, atleta[i].nome, diain, mesin, anoin, diafim, mesfim, anofim, ativ[i].dist, ativ[i].duracao, dia[i], mes[i], ano[i]);
                        }
                }
                printf("Tabela exportada com sucesso.\n");
        }
        fclose(fd);   
}

/*-----------------------------MENU PRINCIPAL-----------------------------*/
int main()
{
        int op;
        do
        {
        printf("\n---------------------MENU---------------------\n");
        printf("\n");
        printf("1 - Adicionar atleta\n");
        printf("2 - Adicionar atividade\n");
        printf("3 - Adicionar plano de atividade\n");
        printf("4 - Numero atletas por atividade e periodo\n");
        printf("5 - Lista de praticantes por atividade e periodo\n");
        printf("6 - Mostrar plano de X atleta entre Y e Z datas\n");
        printf("7 - Medias de tempos de pratica de atividades dos atletas\n");
        printf("8 - Tabela Planos VS Realizados\n");
        printf("9 - Tabela Avaliacao\n");
        printf("10- Exportar tabela da opcao 9 para ficheiro binario\n");
        printf("11- Sair");
        printf("\n----------------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &op);
        printf("\n");
        switch (op)
        {
        case 1:
                addatleta();
                break;
        case 2:
                addativ();
                break;
        case 3:
                addplanativ();
                break;
        case 4:
                numpraticantes();
                break;
        case 5:
                listpraticantes();
                break;
        case 6:
                planoativatleta();
                break;
        case 7:
                mediastempo();
                break;
        case 8:
                tabelaplanreal();
                break;
        case 9:
                tabelafinal();
                break;
        case 10:
                exportarbinario();
                break;
        case 11:
                break;
        default:
                break;
        }
    } while (op != 11);
    return 0;
}