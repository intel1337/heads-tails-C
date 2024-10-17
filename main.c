    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    #include <unistd.h>
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
            if(strncmp(input,"1",1)==0||strncasecmp(input,"p",1)==0||strncasecmp(input,"pile",4)==0){
                inp=PILE_NOMBRE;
            }
            else if(strncmp(input,"2",1)==0||strncasecmp(input,"f",1)==0||strncasecmp(input,"face",4)==0){
                inp=FACE_NOMBRE;
            }else if(strncmp(input,"0",1)==0){
                break;
            }
            else if(strncmp(input,"3",1)==0){
                printf("Le but du jeu est de deviner pile ou face\n");
                printf("Aucune règles précise hors de ca");
                printf("Vous gagnez si vous devinez correctement\n");
                printf("Si vous arrivez à 10 lose, vous perdez\n");
                sleep(3);
            }
            else if(strncmp(input,"4",1)==0){
                printf("Vous avez gagné %d fois et perdu %d fois\n", win, lose);
                sleep(3);
            }
            else if(strncmp(input,"5",1)==0){
                printf("\n");
                printf("Crédits : \n");
                printf("github.com/intel1337\n");
                sleep(3);
            }
            printf(".\n");
            sleep(1);
            printf("..\n");
            sleep(1);
            printf("...\n");
            printf("La pièce est jetée !\n");
            sleep(1);
            srand(time(NULL));
            int r = (rand() % (FACE_NOMBRE - PILE_NOMBRE + 1)) + PILE_NOMBRE;
            if(r == inp) {
                if(win>=1){
                    printf("Réussites !");
                }
                else{
                printf("Réussite !\n");
                }
                win++;
                if(inp==PILE_NOMBRE){
                    printf("Rappel :Vous avez choisi Pile\n");
                    printf("Press Enter to continue\n");
                    getchar();
                }
                else if(inp==FACE_NOMBRE){
                    printf("Rappel : Vous avez choisi Face\n");
                    printf("Press Enter to continue\n");
                    getchar();
                }
    
            }
            else{
                if(lose>=1){
                    printf("Défaites !");
                }
                else{
                    printf("Défaite !");
                }
                printf("Vous avez Perdu\n");
                lose++;
                if(inp==PILE_NOMBRE){
                    printf("Rappel : Vous avez choisi Pile\n");
                    printf("Press enter to continue");
                    getchar();
                }
                
                else if(inp==FACE_NOMBRE){
                    printf("Rappel : Vous avez choisi Face\n");
                    printf("Press Enter to continue\n");
                    getchar();
                }
            }
            if(lose==10){
                printf("Game Over !\n");
                getchar();
                exit(0);
            }
        }
        return 0;
    }

