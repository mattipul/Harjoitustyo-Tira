#include "cmd.h"

void init_cmd(){
    printf("DIJKSTRAN ALGORITMI\n---------\n\n");
    printf("Solmujen maara: ");
    int count;
    scanf("%d", &count);
    count_v=count;
    init_graph_count(count);
    printf("\n--------\n\n");

    int i;
    for(i=0; i<count; i++){
        init_linked_list(i);
    }

    init_set_source();
    init_start_dijkstra();

    printf("\nAlgoritmi suoritettu.\nValitse paatepiste:");
    int trg;
    scanf("%d", &trg);
    printf("\n\nPolun pituus solmu%d->solmu%d on %d\n", source_y, trg, list[0][trg]->distance);
    printf("\nPolku kokonaisuudessaan:\n\n");

    dNode *a_node = list[0][trg];
    while(a_node!=NULL){
        printf("solmu%d", a_node->index);
        if(a_node->previous != NULL){
            printf(" <-> ");
        }
        a_node = a_node->previous;
    }
    printf("\n\n");
}

void init_graph_count(int c){
    int i;
    for(i=0; i<c; i++){
        list[0][i]=malloc(sizeof(dNode));
        list[0][i]->index=i;
    }
}

void init_linked_list(int c){
    int laskuri=1;
    while(1){
        int n,lng;
        printf("Lisaa solmu solmun %d vieruslistaan: \n", c);
        printf("Solmu: ");
        scanf("%d", &n);
        if(n<0 || n>=count_v){
            printf("\n----------\n\n");
            break;
        }
        printf("\n");
        printf("Polun pituus: ");
        scanf("%d", &lng);
        if(lng<0){
            printf("\n----------\n\n");
            break;
        }
        printf("\n----------\n\n");

        list[laskuri][c]=list[0][n];
        list[0][n]->distances_to[c]=lng;
        list[0][c]->distances_to[n]=lng;
        laskuri++;
    }
}

void init_set_source(int i){
    printf("Lahdesolmu: ");
    scanf("%d", &source_y);
}

void init_start_dijkstra(){
    init(list);
    dijkstra(list[0][source_y]);
}
