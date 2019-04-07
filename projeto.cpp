#include<bits/stdc++.h>

using namespace std;

struct facas
{
    int id;
    int quantidade;
    double valor;
    char descricao[2000];
};
int ids=0,i=1;
struct facas v[1001];
struct facas aux;
int verificaID(int n)
{
    for(int j=0;j<i;j++)
    {
        if(v[j].id==n)return 1;
    }
    return 0;
}
int salvar()
{
    int f=0;
    FILE *pf=fopen("produtos.ifcomp","wb");
    if(fwrite(&v,sizeof(struct facas),i,pf))f=1;
    fclose(pf);
    return f;
}
void carregar()
{
    FILE *fp = fopen("produtos.ifcomp","rb");
    int f=0;
    ids=0;
    while(!feof(fp))
    {
        if(feof(fp))break;
        fread(&aux, sizeof (struct facas),1,fp);
        if(aux.id==0)continue;
        v[ids].id=aux.id;
        v[ids].quantidade = aux.quantidade;
        v[ids].valor = aux.valor;
        cout << aux.id;
        strcpy(v[ids].descricao, aux.descricao);
        ids++,i++;
    }
    fclose(fp);
}
int main()
{
    int n=1;
    carregar();
    while(n)
    {
        // printf("      ______________________________ ______________________\n");
        // printf("    .'                              | (_)     (_)    (_)   \\n");
        // printf("  .'                                |  __________________   }\n");
        // printf(".'_.............................____|_(                  )_/\n");
        scanf("%d",&n);
         
        if(n==1)
        {
            printf(" ██████╗ █████╗ ██████╗  █████╗ ███████╗████████╗██████╗  ██████╗ \n");
            printf("██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔══██╗██╔═══██╗\n");
            printf("██║     ███████║██║  ██║███████║███████╗   ██║   ██████╔╝██║   ██║\n");
            printf("██║     ██╔══██║██║  ██║██╔══██║╚════██║   ██║   ██╔══██╗██║   ██║\n");
            printf("╚██████╗██║  ██║██████╔╝██║  ██║███████║   ██║   ██║  ██║╚██████╔╝\n");
            printf(" ╚═════╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ \n");
            v[ids].id=i;
            scanf("%d",&v[ids].quantidade);
            scanf("%lf",&v[ids].valor);
            scanf(" %[^\n]",v[ids].descricao);
            i++,ids++;
            (salvar())? printf("Cadastrado com sucesso!\n") : printf("Falha no cadastro!\n");
        }
        if(n==2)
        {
            printf(" █████╗ ██╗  ████████╗███████╗██████╗  █████╗ ██████╗ \n");
            printf("██╔══██╗██║  ╚══██╔══╝██╔════╝██╔══██╗██╔══██╗██╔══██╗\n");
            printf("███████║██║     ██║   █████╗  ██████╔╝███████║██████╔╝\n");
            printf("██╔══██║██║     ██║   ██╔══╝  ██╔══██╗██╔══██║██╔══██╗\n");
            printf("██║  ██║███████╗██║   ███████╗██║  ██║██║  ██║██║  ██║\n");
            printf("╚═╝  ╚═╝╚══════╝╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝\n");
            int a;scanf("%d",&a);
            if(verificaID(a))
            {
                scanf("%d",&v[a].quantidade);
                scanf("%lf",&v[a].valor);
                scanf(" %[^\n]",v[a].descricao);
                (salvar())? printf("Alterado com sucesso!\n") : printf("Falha na alteração!\n");
            }
            else printf("ID nao encontrado!\n");
        }
        if(n==3)
        {

            printf("███████╗██╗  ██╗ ██████╗██╗     ██╗   ██╗██╗██████╗ \n");
            printf("██╔════╝╚██╗██╔╝██╔════╝██║     ██║   ██║██║██╔══██╗\n");
            printf("█████╗   ╚███╔╝ ██║     ██║     ██║   ██║██║██████╔╝\n");
            printf("██╔══╝   ██╔██╗ ██║     ██║     ██║   ██║██║██╔══██╗\n");
            printf("███████╗██╔╝ ██╗╚██████╗███████╗╚██████╔╝██║██║  ██║\n");
            printf("╚══════╝╚═╝  ╚═╝ ╚═════╝╚══════╝ ╚═════╝ ╚═╝╚═╝  ╚═╝\n");

            int exc;scanf("%d",&exc);
            FILE *abrir = fopen("produtos.ifcomp","rb");
            if(verificaID(exc))
            {
                ids=0,i=0;
                while(!feof(abrir))
                {
                    if(feof(abrir))break;
                    fread(&aux, sizeof (struct facas),1,abrir);
                    if(aux.id!=0 && aux.id!=exc)
                    {
                        printf("Executou legal!\n");
                        v[ids].id=aux.id;
                        v[ids].quantidade = aux.quantidade;
                        v[ids].valor = aux.valor;
                        cout << aux.id << "------" << endl;
                        strcpy(v[ids].descricao, aux.descricao);
                        ids++,i++;
                    }
                    
                }
                for(int k=0;k<=i;k++)
                {
                    cout << v[k].id << endl;
                }
                //salvar();               
            }
            else printf("ID nao encontrado!\n");
            
            fclose(abrir);
            
        }
        if(n==4)
        {
            //ARRUMAR
            printf(" ██████╗ ██████╗ ███╗   ██╗███████╗██╗   ██╗██╗  ████████╗ █████╗ ██████╗\n");
            printf("██╔════╝██╔═══██╗████╗  ██║██╔════╝██║   ██║██║  ╚══██╔══╝██╔══██╗██╔══██╗\n");
            printf("██║     ██║   ██║██╔██╗ ██║███████╗██║   ██║██║     ██║   ███████║██████╔╝\n");
            printf("██║     ██║   ██║██║╚██╗██║╚════██║██║   ██║██║     ██║   ██╔══██║██╔══██╗\n");
            printf("╚██████╗╚██████╔╝██║ ╚████║███████║╚██████╔╝███████╗██║   ██║  ██║██║  ██║\n");
            printf(" ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚══════╝╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝\n");
            int a;scanf("%d",&a);
            if(verificaID(a))
            {
                printf("%d\n",v[a].id);
                printf("%d\n",v[a].quantidade);
                printf("%lf\n",v[a].valor);
                printf("%s\n",v[a].descricao);
            }
            else printf("ID nao encontrado!\n");
        }
        if(n==5)
        {
            printf("██████╗ ███████╗██╗      █████╗ ████████╗ ██████╗ ██████╗ ██╗ ██████╗ \n");
            printf("██╔══██╗██╔════╝██║     ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗██║██╔═══██╗\n");
            printf("██████╔╝█████╗  ██║     ███████║   ██║   ██║   ██║██████╔╝██║██║   ██║\n");
            printf("██╔══██╗██╔══╝  ██║     ██╔══██║   ██║   ██║   ██║██╔══██╗██║██║   ██║\n");
            printf("██║  ██║███████╗███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║██║╚██████╔╝\n");
            printf("╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝ ╚═════╝ \n");
        }
    }
    return 0;
}
