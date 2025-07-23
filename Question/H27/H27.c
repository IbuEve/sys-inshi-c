#include <stdio.h>

int *func(int *sp, int *ep){
    int *ip, *jp, pv, temp;

    ip = sp;
    jp = ep;
    pv = *jp;

    while(1){
        while(*ip++ < pv)
            ;
        【3】;

        while(【4】 && pv < *jp)
        if (ip >= jp) 
            【5】;
        【6】
        ip++;
    }
    【7】
    return ip;

}

void sort(int *sp, int *ep){
    int *vp;
    vp = func(sp, ep);
    if(【1】)
        sort(sp, vp-1)
    if(【2】)
        sort(vp+1, ep);
}