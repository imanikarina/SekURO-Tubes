#include <stdio.h>
#include "stats.h"
#include <string.h>

// Fungsi menampilkan pilihan
void printChoices(){
    printf("------------------------------------------------\n");
    printf("                PILIHAN KEGIATAN                \n");
    printf("------------------------------------------------\n");
    printf("1.  Makan sandwich      6.  Pergi ke dokter\n");
    printf("2.  Main board game     7.  Pergi ke bioskop\n");
    printf("3.  Sikat gigi          8.  Santai di sekre UKJ\n");
    printf("4.  Mandi               9.  Kerja part-time\n");
    printf("5.  Cek LINE            10. Matikan sistem robot\n\n");
    return;
}

// Fungsi pengurangan stats
void decrease(int M, stats *N){
	
    //return;
}

// Fungsi warning message
void warnings(stats *N){
	if(happiness(*N)<5){
		printf("are you not happy?\nhapiness level is low (%)\n",happiness(*N));
	}
	if(health(*N)<5){
		printf("are you sick?\nwarning health level is low(%d)\n",health(*N));
	}
	if(hygiene(*N)<5){
		printf("have you take a bath?\nwarning hygine level is low(%d)\n",hygiene(*N));
	}
	if(money(*N)<5){
		printf("you have less money now, ur money is %d\n",money(*N));
	}
	if(social(*N)<5){
		printf("please don't be antisocial. your social level is %d\n",social(*N));
	} 
    //return;
}

// Fungsi akibat pilihan
void consequences(int M, stats *N){
    if (M == 1){
        if (health(*N) < 18 && money(*N) > 0){
            //setHealth(N, 3);
            setMoney(N, -1);
        } else if (money(*N) > 0){
            health(*N) = 20;
            setMoney(N, -1);
        } else {
            printf("\n***\n\nUang Hilyms tidak cukup!\n\n");
        }
    }
    if (M == 2){
        if (happiness(*N) < 19 && money(*N) > 0){
            setHappiness(N, 2);
            setMoney(N, -1);
        } else if (money(*N) > 0){
            happiness(*N) = 20;
            setMoney(N, -1);
        } else {
            printf("\n***\n\nUang Hilyms tidak cukup!\n\n");
        }
    }
    if (M == 3){
        if (hygiene(*N) < 19 && money(*N) > 0){
            setHygiene(N, 2);
            setMoney(N, -1);
        } else if (money(*N) > 0){
            hygiene(*N) = 20;
            setMoney(N, -1);
        } else {
            printf("\n***\n\nUang Hilyms tidak cukup!\n\n");
        }
    }
    if (M == 4){
        if (hygiene(*N) < 17 && money(*N) > 0){
            setHygiene(N, 4);
            setMoney(N, -1);
        } else if (money(*N) > 0){
            hygiene(*N) = 20;
            setMoney(N, -1);
        } else {
            printf("\n***\n\nUang Hilyms tidak cukup!\n\n");
        }
    }
    if (M == 5){
        if (social(*N) < 19 && money(*N) > 0){
            setSocial(N, 2);
            setMoney(N, -1);
        } else if (money(*N) > 0){
            social(*N) = 20;
            setMoney(N, -1);
        } else {
            printf("\n***\n\nUang Hilyms tidak cukup!\n\n");
        }
    }
    if (M == 6){
        if (health(*N) < 15 && money(*N) > 2){
            setHealth(N, 6);
            setMoney(N, -3);
        } else if (money(*N) > 2){
            health(*N) = 20;
            setMoney(N, -3);
        } else {
            printf("\n***\n\nUang Hilyms tidak cukup!\n\n");
        }
    }
    if (M == 7){
        if (happiness(*N) < 15 && money(*N) > 2){
            setHealth(N, 6);
            setMoney(N, -3);
        } else if (money(*N) > 2){
            health(*N) = 20;
            setMoney(N, -3);
        } else {
            printf("\n***\n\nUang Hilyms tidak cukup!\n\n");
        }
    }
    if (M == 8){
        if (social(*N) < 15 && money(*N) > 2){
            setHealth(N, 6);
            setMoney(N, -3);
        } else if (money(*N) > 2){
            health(*N) = 20;
            setMoney(N, -3);
        } else {
            printf("\n***\n\nUang Hilyms tidak cukup!\n\n");
        }
    }
    if (M == 9){
        if (happiness(*N) > 1 && health(*N) > 2){
            setHealth(N, -1);
            setHappiness(N, -2);
            setMoney(N, 4);
        } else if (happiness(*N) > 1){
            printf("\n***\n\nHilmys terlalu lelah untuk bekerja...\n\n");
        } else {
            printf("\n***\n\nHilmys terlalu depresi untuk bekerja...\n\n");
        }
    }
    return;
}

int main(){
    // Memberi nilai awal untuk semua stats (50%)
    int choice;
    stats state = makeStats(10, 10, 10, 10, 10);

    // Memberi stats dan pilihan kegiatan
    printStats(&state);
    printChoices();

    // Meminta input kegiatan
    printf("Apa yang akan dilakukan Hilmys hari ini? ");
    scanf("%d", &choice);

    consequences(choice, &state);

    // Looping per pilihan
    while (choice != 10 && health(state) > 0){
        // Pengurangan stats
        setHealth(&state, -1);

        // Memberi stats dan pilihan kegiatan
        printStats(&state);
        printChoices();

        // Meminta input kegiatan
        printf("Apa yang akan dilakukan Hilmys hari ini? ");
        scanf("%d", &choice);

        consequences(choice, &state);
        warnings(&state);
    }
    
    // Pesan ketika pemain kalah
    printf("------------------------------------------------\n");
    printf("                   GAME OVER!                   \n");
    printf("------------------------------------------------\n");

    return 0;
}
