/*
Criado por Jairo
    3° Período - Ciência da Computação.
*/
#include<bits/stdc++.h>
#include <locale.h>
//#include<unistd.h> //linux
#include<Windows.h>
using namespace std;

struct facas
{
    int id;
    int quantidade;
    double valor;
    char nome[1000];
    char descricao[2000];
};
int ids=0,i=1;
struct facas v[1001];
struct facas aux;
void limpatela()
{
    for(int i=0;i<50;i++)printf("\n");
}
int verificaID(int n)
{
    for(int j=0;j<ids;j++)
    {
        if(v[j].id==n)return 1;
    }
    return 0;
}
int salvar()
{
    int f=0;
    FILE *pf=fopen("produtos.ifcomp","wb");
    rewind(pf);
    if(fwrite(&v,sizeof(struct facas),ids,pf))f=1;
    fclose(pf);
    return f;
}
void carregar()
{
    FILE *fp;
    if(fopen("produtos.ifcomp","rb")==0)
    {
        return ;
    }
    else
    {
        fp = fopen("produtos.ifcomp","rb");
        int f=0;
        ids=0;
        set<int>conjid;
        while(!feof(fp))
        {
            if(feof(fp))break;
            fread(&aux, sizeof (struct facas),1,fp);
            if(aux.id==0 || conjid.find(aux.id)!=conjid.end())continue;
            conjid.insert(aux.id);
            v[ids].id=aux.id;
            v[ids].quantidade = aux.quantidade;
            v[ids].valor = aux.valor;
            strcpy(v[ids].descricao, aux.descricao);
            strcpy(v[ids].nome, aux.nome);

            ids++;
            i = aux.id+1;
        }
        fclose(fp);
    }


}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n=1;
    carregar();
    string relatorio;
    int rel=1;
    while(n)
    {
        printf("--------------------------------------------------------------------------------\n");
        printf("|                            Cutelaria AK 47                                   |\n");
        printf("|                  A cutelaria perfeita para você!                             |\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("| 1) Cadastro de facas.                                                        |\n");
        printf("| 2) Alteração de dados.                                                       |\n");
        printf("| 3) Exclusão de dados.                                                        |\n");
        printf("| 4) Consultar dados.                                                          |\n");
        printf("| 5) Gerar relatório das facas.                                                |\n");
        printf("| 0) Sair do programa.                                                         |\n");
        printf("--------------------------------------------------------------------------------\n");

        scanf("%d",&n);
        limpatela();
        if(n==1)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("|                            Cutelaria AK 47                                   |\n");
            printf("|                  A cutelaria perfeita para você!                             |\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("Cadastro de produtos.\n");
            v[ids].id=i;
            printf("Nome da faca: ");
            scanf(" %[^\n]",v[ids].nome);
            printf("\nQuantidade : ");
            scanf("%d",&v[ids].quantidade);
            printf("\nValor : R$ ");
            scanf("%lf",&v[ids].valor);
            printf("\nDescrição : ");
            scanf(" %[^\n]",v[ids].descricao);
            printf("\n");
            i++,ids++;
            (salvar())? printf("Cadastrado com sucesso!\n") : printf("Falha no cadastro!\n");
        }
        if(n==2)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("|                            Cutelaria AK 47                                   |\n");
            printf("|                  A cutelaria perfeita para você!                             |\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("Alteração de produto.\n");
            int a;scanf("%d",&a);
            if(verificaID(a))
            {
                int hehe;
                for(int j=0;j<i;j++)
                {
                    if(v[j].id==a)hehe=j;
                }
                printf("Código : %d\n",v[hehe].id);
                printf("Nome da faca: %s\n",v[hehe].nome);
                printf("Quantidade : %d\n",v[hehe].quantidade);
                printf("Valor: R$ %.2lf\n",v[hehe].valor);
                printf("Descrição: %s\n",v[hehe].descricao);

                printf("Novo nome: ");
                scanf(" %[^\n]",v[hehe].nome);
                printf("\nNova quantidade: ");
                scanf("%d",&v[hehe].quantidade);
                printf("\nNovo valor: ");
                scanf("%lf",&v[hehe].valor);
                printf("\nNova descrição: ");
                scanf(" %[^\n]",v[hehe].descricao);
                printf("\n");
                (salvar())? printf("Alterado com sucesso!\n") : printf("Falha na alteração!\n");
            }
            else printf("ID não encontrado!\n");
        }
        if(n==3)
        {

            printf("--------------------------------------------------------------------------------\n");
            printf("|                            Cutelaria AK 47                                   |\n");
            printf("|                  A cutelaria perfeita para você!                             |\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("Exclusão de produto.\n");
            printf("ID da faca a ser excluída: ");
            int exc;scanf("%d",&exc);
            printf("\n");
            if(verificaID(exc))
            {
                int hehe;
                printf("Excluindo...\n");
                for(int j=0;j<i;j++)
                {
                    if(v[j].id==exc)hehe=j;
                }
                for(int j=hehe;j<ids;j++)
                {
                    v[j]=v[j+1];
                }
                ids--;
                salvar();
            }
            else printf("ID não encontrado!\n");
        }
        if(n==4)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("|                            Cutelaria AK 47                                   |\n");
            printf("|                  A cutelaria perfeita para você!                             |\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("Consultar produto.\n");
            printf("Insira o ID a ser consultado: ");
            int a;scanf("%d",&a);
            printf("\n");
            if(verificaID(a))
            {
                int hehe;
                for(int j=0;j<i;j++)
                {
                    if(v[j].id==a)hehe=j;
                }
                printf("Código: %d\n",v[hehe].id);
                printf("Nome da faca: %s\n",v[hehe].nome);
                printf("Estoque: %d\n",v[hehe].quantidade);
                printf("Valor: R$ %lf\n",v[hehe].valor);
                printf("Descrição: %s\n",v[hehe].descricao);
            }
            else printf("ID não encontrado!\n");
        }
        if(n==5)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("|                            Cutelaria AK 47                                   |\n");
            printf("|                  A cutelaria perfeita para você!                             |\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("Gerar relatório\n");

            string xua;
            stringstream help;
            help << rel++;
            help >> xua;
            relatorio = "Relatorio";
            relatorio+=xua;
            char filename[100];
            sprintf(filename, " %s.txt", relatorio.c_str());
            printf("Gerando relatório...\n");
            Sleep(1000); //Windows
            //usleep(1000000); //linux
            printf("Relatório gerado: %s\n",filename);
            FILE *rel = fopen(filename, "wb");
            fprintf(rel, "--------------------------------------------------------------------------------\n");
            fprintf(rel, "|                            Cutelaria AK 47                                   |\n");
            fprintf(rel, "|                  A cutelaria perfeita para você!                             |\n");
            fprintf(rel, "--------------------------------------------------------------------------------\n");
            for(int k=0;k<ids;k++)
            {
                fprintf(rel, "--------------------------------------------------------------------------------\n");
                fprintf(rel, "| Código: %d                                                                   |\n",v[k].id);
                fprintf(rel, "| Nome: %s |\n",v[k].nome );
                fprintf(rel, "| Estoque: %d                                                                  |\n",v[k].quantidade );
                fprintf(rel, "| Valor: R$ %.2lf                                                              |\n",v[k].valor );
                fprintf(rel, "| Descrição: %s |\n",v[k].descricao );
                fprintf(rel, "--------------------------------------------------------------------------------\n");
            }
            fclose(rel);
        }
        if(!n)
        {
            printf("Saindo!\n");

            salvar();
            Sleep(1000); //Windows
            //usleep(1000000); //linux
            break;
        }
    }
    return 0;
}
