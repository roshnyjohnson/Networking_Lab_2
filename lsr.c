#include<stdio.h>
#include<stdlib.h>

int main()
{
        int adj[100][100],dist[100],last[100],flag[100];
        int src;
        int i,j,k,v,n;
        int min;
        printf("Enter the number of nodes");
        scanf("%d",&n);
        printf("Enter the distance matrix\n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&adj[i][j]);
                        if(adj[i][j]==0 && i!=j)
                        {
                                adj[i][j]=1000;
                        }
                }

        }
        printf("Enter the source");
        scanf("%d",&src);
        for(i=0;i<n;i++)
        {
                flag[i]=0;
                dist[i]=adj[src][i];
                last[i]=src;
        }
        flag[src]=1;
        dist[src]=0;
        for(i=0;i<n;i++)
        {
                min=1000;
                for(j=0;j<n;j++)
                {
                        if(flag[j]==0&&dist[j]<min)
                        {
                                min=dist[j];
                                v=j;
                        }
                }
                flag[v]=1;
                for(j=0;j<n;j++)
                {
                        if(flag[j]==0&&dist[j]>adj[v][j]+dist[v])
                        {
                                dist[j]=adj[v][j]+dist[v];
                                last[j]=v;
                        }
                }

        }
        printf("\nRouter\tdist\tnext\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t%d\t%d\n",i,dist[i],last[i]);
        }
}
