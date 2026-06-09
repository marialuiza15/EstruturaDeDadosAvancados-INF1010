#define MAX 4
#define MIN 2

typedef struct no t_no;
struct no {
    int ndesc;
    int chave[MAX];      /* não inclui overflow da chave */
    t_no *ramo[MAX+1];
};

void intervalo(t_no *arv, int lim_inf, int lim_sup) {
    int i;

    if (arv == NULL)
        return;

    for (i = 0; i < arv->ndesc; i++) {
        /* Visita o filho à esquerda da chave i (ramo[i]),
           mas só vale a pena se lim_inf < chave[i],
           pois todas as chaves nessa sub-árvore são < chave[i] */
        if (lim_inf < arv->chave[i])
            intervalo(arv->ramo[i], lim_inf, lim_sup);

        /* Imprime a chave i se estiver no intervalo aberto */
        if (arv->chave[i] > lim_inf && arv->chave[i] < lim_sup)
            printf("%d\n", arv->chave[i]);

        /* Se a chave já é >= lim_sup, todas as próximas
           chaves e filhos à direita também são — podamos */
        if (arv->chave[i] >= lim_sup)
            return;
    }

    /* Visita o último filho (à direita de todas as chaves),
       ramo[ndesc], que contém chaves maiores que todas as chaves do nó */
    intervalo(arv->ramo[arv->ndesc], lim_inf, lim_sup);
}