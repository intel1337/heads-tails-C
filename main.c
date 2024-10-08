#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define PILE_NOMBRE 1
#define FACE_NOMBRE 2
#define MAX_LENGTH 4

int main(){
    int inp;
    char input[MAX_LENGTH];
    int win = 0;
    int lose = 0;
    while(1){
        system("clear");
        printf(BLU);
        printf("             [------ %sPile ou %sFace %s? %s------]\n", MAG, CYN, WHT, BLU);
        printf("\n");
        printf("\n");
        printf(MAG);
        printf("  [------[1] - Pile // [2] - Face // [3] - Rules------]\n");
        printf(CYN);
        printf("[------[0] - Exit // [4] - History// [5] - Credits------]\n");
        printf("\n");
        printf("\n");
        printf("%s                   Player%s@%spo%sf--%s#", WHT, GRN, MAG, MAG, WHT);
        fgets(input, MAX_LENGTH, stdin);
        printf("\n");
        if(strncmp(input,"1",1)==0||strncmp(input,"pile",4)==0||strncmp(input,"PILE",4)==0||strncmp(input,"pILe",4)==0||strncmp(input,"p",1)==0){
            inp=PILE_NOMBRE;
        }
        else if(strncmp(input,"2",1)==0||strncmp(input,"face",4)==0||strncmp(input,"FACE",4)==0||strncmp(input,"fACE",4)==0||strncmp(input,"f",1)==0){
            inp=FACE_NOMBRE;
        }
        else if(strncmp(input,"0",1)==0){
            break;
        }
        else if(strncmp(input,"3",1)==0){
            printf("Le but du jeu est de deviner pile ou face\n");
            printf("Vous gagnez si vous devinez correctement\n");
            printf("Vous perdez si vous devinez incorrectement\n");
            printf("Si vous arrivez à 10 pertes, vous perdez\n");
            printf("Press Enter to continue\n");
            getchar();
            continue;
        }
        else if(strncmp(input,"4",1)==0){
            printf("Vous avez gagné %d fois et perdu %d fois\n", win, lose);
            printf("Press Enter to continue\n");
            getchar();
            continue;
        }
        else if(strncmp(input,"5",1)==0){
            printf("\n");
            printf("Crédits : \n");
            printf("github.com/intel1337\n");
            printf("Press Enter to continue\n");
            getchar();
            continue;
        }
        else
            continue;
        printf("La pièce est jetée !\n");
        sleep(1);
        srand(time(NULL));
        int r = (rand() % (FACE_NOMBRE - PILE_NOMBRE + 1)) + PILE_NOMBRE;
        if(r == inp) {
            printf("Vous avez Gagné\n");
            win++;
            if(r==PILE_NOMBRE){
                printf("Vous avez eu Pile\n");
            }
            else if(r==FACE_NOMBRE){
                printf("Vous avez eu Face\n");
            }
            printf("Press Enter to continue\n");
        }
        else{
            printf("Vous avez Perdu\n");
            lose++;
            if(r==PILE_NOMBRE){
                printf("Vous avez eu Pile\n");
            }
            else if(r==FACE_NOMBRE){
                printf("Vous avez eu Face\n");
            }
            printf("Press Enter to continue\n");
        }
        if(lose==10){
            printf("Game Over !\n");
        }
        getchar();
    }
    return 0;
}

