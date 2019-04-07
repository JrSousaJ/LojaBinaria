#include<bits/stdc++.h>

using namespace std;

struct facas
{
    int id;
    int quantidade;
    double valor;
    char descricao[2000];
};
int ids=0,i=0;
struct facas v[1001];
struct facas aux;
int verificaID(int n)
{
    for(int j=0;j<i;j++)
    {
        if(v[i].id==n)return 1;
    }
    return 0;
}
int main()
{
    int n=1;
     FILE *fp = fopen("produtos.ifcomp","rb");
            while(!feof(fp))
            {
                fread(&aux, sizeof (struct facas),1,fp);
                if(feof(fp))break;
                v[i].id=aux.id;
                v[i].quantidade = aux.quantidade;
                v[i].valor = aux.valor;
                cout << aux.id;
                strcpy(v[i].descricao, aux.descricao);
                i++;
                ids=v[i].id;
            }
            fclose(fp);
            ids++;
    while(n)
    {
        scanf("%d",&n);

        if(n==1)
        {
            printf(" ██████╗ █████╗ ██████╗  █████╗ ███████╗████████╗██████╗  ██████╗ \n");
            printf("██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔══██╗██╔═══██╗\n");
            printf("██║     ███████║██║  ██║███████║███████╗   ██║   ██████╔╝██║   ██║\n");
            printf("██║     ██╔══██║██║  ██║██╔══██║╚════██║   ██║   ██╔══██╗██║   ██║\n");
            printf("╚██████╗██║  ██║██████╔╝██║  ██║███████║   ██║   ██║  ██║╚██████╔╝\n");
            printf(" ╚═════╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ \n");                                                    
            v[i].id=i;
            scanf("%d",&v[i].quantidade);
            scanf("%lf",&v[i].valor);
            scanf(" %[^\n]",v[i].descricao);
            FILE *pf=fopen("produtos.ifcomp","wb");
            if(fwrite(&v,sizeof(struct facas),i+1,pf))printf("Cadastrado com sucesso!\n");
            fclose(pf);
            i++;
            
           
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
            FILE *alt = fopen("produtos.ifcomp","wb+");
            if(verificaID(a))
            {
                scanf("%d",&v[a].quantidade);
                scanf("%lf",&v[a].valor);
                scanf(" %[^\n]",v[a].descricao);
                if(fwrite(&v,sizeof(struct facas),i+1,alt))printf("Alterado com sucesso!\n");

                fclose(alt);
<<<<<<< HEAD
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
        }
        if(n==4)
        {
                                                                 
            printf(" ██████╗ ██████╗ ███╗   ██╗███████╗██╗   ██╗██╗  ████████╗ █████╗ ██████╗\n");
            printf("██╔════╝██╔═══██╗████╗  ██║██╔════╝██║   ██║██║  ╚══██╔══╝██╔══██╗██╔══██╗\n");
            printf("██║     ██║   ██║██╔██╗ ██║███████╗██║   ██║██║     ██║   ███████║██████╔╝\n");
            printf("██║     ██║   ██║██║╚██╗██║╚════██║██║   ██║██║     ██║   ██╔══██║██╔══██╗\n");
            printf("╚██████╗╚██████╔╝██║ ╚████║███████║╚██████╔╝███████╗██║   ██║  ██║██║  ██║\n");
            printf(" ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚══════╝╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝\n");
            int a;scanf("%d",&a);
            if(verificaID(a))
            {
                printf("%d\n",v[i].id);
                printf("%d\n",v[i].quantidade);
                printf("%lf\n",v[i].valor);
                printf("%s\n",v[i].descricao);
            }
=======
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
        }
        if(n==4)
        {
                                                                 
            printf(" ██████╗ ██████╗ ███╗   ██╗███████╗██╗   ██╗██╗  ████████╗ █████╗ ██████╗\n");
            printf("██╔════╝██╔═══██╗████╗  ██║██╔════╝██║   ██║██║  ╚══██╔══╝██╔══██╗██╔══██╗\n");
            printf("██║     ██║   ██║██╔██╗ ██║███████╗██║   ██║██║     ██║   ███████║██████╔╝\n");
            printf("██║     ██║   ██║██║╚██╗██║╚════██║██║   ██║██║     ██║   ██╔══██║██╔══██╗\n");
            printf("╚██████╗╚██████╔╝██║ ╚████║███████║╚██████╔╝███████╗██║   ██║  ██║██║  ██║\n");
            printf(" ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚══════╝╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝\n");
            int a;scanf("%d",&a);
            if(verificaID(a))
            {
                printf("%d\n",v[i].id);
                printf("%d\n",v[i].quantidade);
                printf("%lf\n",v[i].valor);
                printf("%s\n",v[i].descricao);
            }
>>>>>>> 437471b856f7af8f923ea45259a43d871edb288c
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
