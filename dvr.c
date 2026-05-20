#include<stdlib.h>
#include<stdio.h>

int main()
{
        int dist[100][100],cost[100][100],next[100][100];
        int i,k,j,n;
        printf("enter thenumber of routers\n");
        scanf("%d",&n);
        printf("enter the cost matrix\n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&cost[i][j]);
                        dist[i][j]=cost[i][j];
                        if(cost[i][j]==999)
                        {
                                next[i][j]=-1;
                        }
                        else{
                                next[i][j]=j;
                        }
                }
        }
        for(k=0;k<n;k++)
        {
                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                if(dist[i][j]>dist[i][k]+dist[k][j])
                                {
                                        dist[i][j]=dist[i][k]+dist[k][j];
                                        next[i][j]=next[i][k];
                                }
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                printf("Router %d\n",i);
                printf("Router\tdistance\tnext\n");
                for(j=0;j<n;j++)
                {
                        printf("%d\t%d\t%d\n",j,dist[i][j],next[i][j]);
                }
        }
        printf("Cost Matrix\n  \t");
        for(i=0;i<n;i++)
        {
                printf("%d\t",i);
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
                printf("%d |\t",i);
                for(j=0;j<n;j++)
                {
                        printf("%d\t",dist[i][j]);
                }
                printf("\n");
        }

}
