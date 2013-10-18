#include "structure.h"

void init(dNode *list[V][V])
{
    int i,j;

        for(j=0; j<V; j++)
        {
            if(list[0][j]!=NULL)
            {
                list[0][j]->ok=0;
                list[0][j]->previous=NULL;
                list[0][j]->distance=INT_MAX;
            }
        }

}

int dist_between(dNode *a, dNode *b)
{
    int vrt=0;
    int i;
    for(i=0; i<V; i++)
    {
        if(list[0][i] == a)
        {
            vrt=i;
            break;
        }
    }
    //printf("dist:%d\n", b->distances_to[vrt]);
    return b->distances_to[vrt];
}

int smallest_distance_q()
{
    int dist_ret=INT_MAX;
    int u=0;
    int ret;
    int i,j;
    for(j=0; j<V; j++)
    {
        if(list[0][j]!=NULL)
        {
            if(list[0][j]->distance<dist_ret && list[0][j]->ok==0)
            {
                dist_ret=list[0][j]->distance;
                //list[0][j]->ok=1;
                ret=j;
                u=1;
                //printf("OKs: %d %d\n", j, dist_ret);

            }
        }
        else
        {
            break;
        }
    }

    if(u==0)
    {
        return -1;
    }

    list[0][ret]->ok=1;

    return ret;
}

void dijkstra(dNode* source)
{

    source->distance=0;

    while(1)
    {
        int u = smallest_distance_q();
        //printf("Solmu %d\n",u);
        if(u==-1)
        {
            break;
        }

        if(list[0][u]->distance==INT_MAX)
        {
            break;
        }
        //puts("OK");
        int i;
        for(i=1; i<V; i++)
        {
            if(list[i][u]!=NULL)
            {
                // puts("OK kasittely");
                //int alt = list[0][u]->distance + dist_between(list[0][u], list[i][u]);
                int alt = list[0][u]->distance + list[i][u]->distances_to[u];
                if(alt < list[i][u]->distance)
                {
                    list[i][u]->distance=alt;
                    list[i][u]->previous=list[0][u];
                }
            }
        }

    }

}
