#ifndef STATS_H
#define STATS_H

typedef struct{
    int health;
	int happiness, hygiene, social, money;
} stats;

#define health(S) (S).health
#define happiness(S) (S).happiness
#define hygiene(S) (S).hygiene
#define social(S) (S).social
#define money(S) (S).money

stats makeStats(int A, int B, int C, int D, int E);

void printStats(stats *S);

void setHealth(stats *S, int X);
void setHappiness(stats *S, int X);
void setHygiene(stats *S, int X);
void setSocial(stats *S, int X);
void setMoney(stats *S, int X);

#endif
