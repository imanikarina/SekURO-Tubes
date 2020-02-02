#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

// Untuk membuat stats awal

stats makeStats(int A, int B, int C, int D, int E){
    stats S;
    health(S) = A;
    happiness(S) = B;
    hygiene(S) = C;
    social(S) = D;
    money(S) = E;
    return S;
}

// Untuk menampilkan stats //

void printStats(stats *S){
    printf("------------------------------------------------\n");
    printf("                 KONDISI HILMYS                 \n");
    printf("------------------------------------------------\n");
    printf("Health    : %d\n", health(*S));
    printf("Happiness : %d\n", happiness(*S));
    printf("Hygiene   : %d\n", hygiene(*S));
    printf("Social    : %d\n", social(*S));
    printf("Money     : %d\n\n", money(*S));
    return;
}

// Untuk menambahkan atau mengurangi stats

void setHealth(stats *S, int X){
    health(*S) = health(*S) + X;
    return;
}
void setHappiness(stats *S, int X){
    happiness(*S) = happiness(*S) + X;
    return;
}
void setHygiene(stats *S, int X){
    hygiene(*S) = hygiene(*S) + X;
    return;
}
void setSocial(stats *S, int X){
    social(*S) = social(*S) + X;
    return;
}
void setMoney(stats *S, int X){
    money(*S) = money(*S) + X;
    return;
}

