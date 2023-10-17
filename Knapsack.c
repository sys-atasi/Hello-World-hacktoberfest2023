#include<stdio.h>
int parent[10];
int find(int);
int unin(int,int);
int cost[100][100];
void krushkal(int n)
{
    int i,j,ne=1,u,v,a,b,min=0,mincost=0;
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(unin(u,v))
        {
            printf("%d-->%d=%d\n",u,v,min);
            mincost=mincost+min;
            ne++;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Minimum cost=%d",mincost);
}
int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}
int unin(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main()
{
    int i,j,n;
    printf("Enter the number of node:");
    scanf("%d",&n);
    printf("Enter the cost :");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }
        }
    }
    krushkal(n);
}
