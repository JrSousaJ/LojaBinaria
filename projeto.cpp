#include<bits/stdc++.h>

using namespace std;

struct facas
{
    int id;
    int quantidade;
    double valor;
    string descricao;
};

vector<facas>v;
int main()
{
    int n=1;
    while(n)
    {
        scanf("%d",&n);

        if(n==1)
        {
            int id,quantidade;
            double valor;
            string descricao;
            scanf("%d",&id);
            scanf("%d",&quantidade);
            scanf("%lf",&valor);
            cin >> descricao;
            v.push_back({id,quantidade,valor,descricao});
            FILE *pf=fopen("produtos.ifcomp","wb");
            if(fwrite(v.data(),sizeof v[0], v.size(),pf))printf("Cadastrado com sucesso!\n");
            fclose(pf);
            FILE *fpf = fopen("produtos.ifcomp","rb");
            vector<facas>output;
            fread(output.data(), sizeof output[0], output.size(),fpf);
            fclose(fpf);
            for(int i=0;i<output.size();i++)
            {
                printf("%d\n",output[i].id);
            }
        }
    }
    return 0;
}
