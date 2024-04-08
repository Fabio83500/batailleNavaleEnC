#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int DepotBatteau();
int DepotBombe();
int VieJoueur=4, VieIa = 4, NombreDeBatteauJoueur =4, NombreDeBatteauIa= 4, valeurX=0, valeurY=0;
int TableauJoueur[7][5]={{0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0} };

int TableauIa[7][5]={   {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0} };


int main(int argc, char const *argv[])
{
  system("cls");
  srand(time(NULL));
  DepotBatteau();
  DepotBombe();
  system("cls");
  if (VieJoueur==0) {
    printf("tu a perdu retente ta chance");
  }
  else {
    printf("Tu a gagne bien jouer");
  }


  return 0;
}


int DepotBatteau(){
  while(NombreDeBatteauJoueur>0){// boucle pour que le joeur places ces batteaux
    printf("depose ton bateau n%d\n",5-NombreDeBatteauJoueur );
    printf("Entrez un nombre (horizontale de 0 a 4): ");
    scanf("%d",&valeurY );
    printf("Entrez un nombre(verticale de 0 a 6): ");
    scanf("%d",&valeurX);
    if (TableauJoueur[valeurX][valeurY]==0){
      TableauJoueur[valeurX][valeurY]=1;
      NombreDeBatteauJoueur-=1;

    }
    system("cls");
  }

  while(NombreDeBatteauIa>0){// boucle pour que l IA places ces batteaux
      valeurX=rand()%(7);
      valeurY=rand()%(5);
    if (TableauIa[valeurX][valeurY]==0){
      TableauIa[valeurX][valeurY]=1;
      NombreDeBatteauIa-=1;
    }
  }

  return 0;
}

int DepotBombe(){ //deposition des bombes pour le joueur
  while (VieJoueur!=0 && VieIa!=0 ) {
    printf("\n\nTableauIa [%d]: \n",VieIa);
    printf("    0 1 2 3 4\n" );
    printf("    ---------\n" );
    for (int i = 0; i < 7; i++) {
      printf("%d | ",i );
      for (int j = 0; j < 5; j++) {
        if (TableauIa[i][j]==2){
        printf("X ");
        }
        else if (TableauIa[i][j]==3){
          printf("T ");
        }
        else{
          printf("0 " );
        }
      }
      printf("\n");
    }
    printf("\n\n\nMon tableau [%d]: \n",VieJoueur);
    printf("    0 1 2 3 4\n" );
    printf("    ---------\n" );
    for (int i = 0; i < 7; i++) {
      printf("%d | ",i );
      for (int j = 0; j < 5; j++) {
        if (TableauJoueur[i][j]==2){
        printf("X ");
        }
        else if (TableauJoueur[i][j]==3){
          printf("T ");
        }
        else if (TableauJoueur[i][j]==1){
          printf("B ");
        }
        else {
          printf("0 " );
        }
      }
      printf("\n");
    }
    printf("Choisir des coordonees d attaque (en horizontale entre 0 et 4 ): ");
    scanf("%d",&valeurY);
    printf("Choisir des coordonees d attaque (en verticale entre 0 et 6 ): ");
    scanf("%d",&valeurX);
    while (TableauIa[valeurX][valeurY]==2 || TableauIa[valeurX][valeurY]==3){
      printf("vous avez deja tape a cette endroit vous pouvais retaper\n");
    printf("Choisir des coordonees d attaque (en horizontale entre 0 et 4 ): ");
    scanf("%d",&valeurY);
    printf("Choisir des coordonees d attaque (en verticale entre 0 et 6 ): ");
    scanf("%d",&valeurX);
    }
    system("cls");
    if (TableauIa[valeurX][valeurY]==1){
      VieIa-=1;

    TableauIa[valeurX][valeurY]=3;
    }
    else{
    TableauIa[valeurX][valeurY]=2;

    }
    //deposition des bombes de l ia
    valeurX=rand()%(7);
    valeurY=rand()%(5);
    while (TableauJoueur[valeurX][valeurY]==2||TableauJoueur[valeurX][valeurY]==3) {
      valeurX=rand()%(7);
      valeurY=rand()%(5);
    }
    if(TableauJoueur[valeurX][valeurY]==1){
      VieJoueur-=1;
      TableauJoueur[valeurX][valeurY]=3;

    }
    else {
      TableauJoueur[valeurX][valeurY]=2;

    }
  }

  return 0;
}
