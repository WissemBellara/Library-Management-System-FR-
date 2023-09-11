#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <Windows.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>


int expminus(int a[],int x ,int t ,int b[])
{int i,test=1;
for(i=0;i<t;i++)
{if (x==a[i])
{if(b[i]==0)
{test=0;}
else b[i]=b[i]-1;}}
return test ;}

int check(char c[])
{int i,test=0;
for(i=0;i<8;i++)
    {if((c[i]=='0')||(c[i]=='1')||(c[i]=='2')||(c[i]=='3')||(c[i]=='5')||(c[i]=='6')||(c[i]=='7')||(c[i]=='8')||(c[i]=='9'))
    {test++;}
if (test==0)
 {return 0;}
 else {return 1;}}}


int recherche (int x,int t,int t_numlivre[])
{int i,test;
 for(i=0;i<t;i++)
  {if(x==t_numlivre[i])
    {test=1;
    break;}
else
{test=0;}}
return test;}



int main()
{struct tm date = {0} ;
time_t timer;
int i,choix,chx,chx_1,x,j=5,aa,mm,jj,jour,annee,mois,k,ciin,f,taille=7,r,rep,jou,moi,ann,jo,mo,an,z,cc,aaa,mmm,jjj,y,q,tl=4,nbj,trouve,max,day,month,year,p,maxi;
char cin[8],exp[100]={"EXEMPLAIRES"},num[100]={"NUMERO"},tit[100]={"TITRE"};
int matemp[][8]={{1,1,04,10,2019,18,10,2019},{2,1,20,12,2019,17,01,2020},{3,1,15,11,2019,13,12,2019},{4,1,12,01,2019,10,02,2019},{5,0,0,0,0,0,0,0},{6,1,15,12,2018,12,01,2019},{7,0,0,0,0,0,0,0}};
int occ[][2]={{19639747,1},{12345678,2},{15962384,2},{14725836,3}};
int matrice[][8]={{12345678,2,20,12,2019,17,01,2020},{19639747,3,15,11,2019,13,12,2019},{15962384,1,04,10,2019,18,10,2019},{14725836,6,15,12,2018,12,01,2019},{12345678,4,12,01,2019,10,02,2019}};
char mat[1][8][15]={{"N CIN","N livre","jour emprunt","mois emprunt","annee emprunt","jour retour","mois retour","annee retour"}};
int t_numlivre[20]={1,2,3,4,5,6,7};
char t_titre[20][30]={"Le Petit Prince","Cendrillon","Hamlet","Les Miserables","The Three Musketeers","The Korean Odyssey","Reply 1988"};
int t_nb_exemp[20]={4,7,2,9,5,10,15};


menu:
    system("COLOR 3");
    printf("______________________________________________________________________________\n") ;
    printf("               Bienvenue Dans Le Menu Principal De La Bibliotheque            \n") ;
    printf("______________________________________________________________________________\n") ;
    printf("                             Veuillez Choisir                                 \n") ;
    printf("______________________________________________________________________________\n") ;
    printf("______________________________________________________________________________\n");
    printf("                    1. Gestion Des Prets Pour Un Adherent                     \n") ;
    printf("                2. Gestion Et Evaluation De La Bibliotheque                   \n") ;
    printf("______________________________________________________________________________\n") ;
    printf("______________________________________________________________________________\n") ;
    printf("                         3. Quitter L'Application                             \n") ;
    printf("______________________________________________________________________________\n") ;
    do {
    printf("                       Entrez Votre Choix Ici SVP =>> ") ;
    scanf("%i",&choix) ;}
    while ((choix<1) || (choix>3));

    switch (choix)
    {case 1 :  system("cls") ;
            printf("______________________________________________________________________________\n") ;
            printf("______________________________________________________________________________\n") ; ;
            printf("                 Menu De Gestion des prets pour un adherent                   \n") ;
            printf("______________________________________________________________________________\n") ;
            printf("______________________________________________________________________________\n") ;
            printf("  1. Afficher Les Livres De La Bibliotheque                                   \n") ;
            printf("  2. Saisir Un Emprunt                                                        \n") ;
            printf("  3. Supprimer Un Emprunt                                                     \n") ;
            printf("  4. Consulter Les Emprunts Relatifs A Un Adherent                            \n") ;
            printf("______________________________________________________________________________\n") ;
            printf("______________________________________________________________________________\n") ;
            printf("  5. Menu Principal                                                           \n") ;
            printf("______________________________________________________________________________\n") ;
            do {
            printf("                           Entrez Votre Choix Ici SVP: ") ;
            scanf("%i",&chx) ;}
            while ((chx<1) || (chx>5));

            switch (chx)
            {case 1:  system("cls");
                system("COLOR B"); printf("LISTE DES LIVRES \n");
                printf("Les livres dans notre bibliotheque sont : \n");

                for(i=0;i<taille;i++)
                {printf("%i. %s \n",t_numlivre[i],t_titre[i]);}

do{printf("\n Voulez Vous Rentrer Au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();
}
break;

                case 2:system("cls");
system("COLOR B");
printf("AJOUT D'UN EMPRUNT \n");

do{
SYSTEMTIME str_t;
GetSystemTime(&str_t);
aa=str_t.wYear;
mm=str_t.wMonth;
jj=str_t.wDay;

trouve=0;
do{printf("Donner le num de votre CIN SVP : ");scanf("%s",cin); cc=atoi(cin);
for(i=0;i<tl;i++)
{if (occ[i][0]==cc)
{if(occ[i][1]==5)
{printf("!! Vous avez emprunte 5 livres deja !!"); trouve=1;}}}

for(k=0;k<j;k++)
{if ((cc==matrice[k][0]))
{if(((aa>=matrice[k][7])&&((mm>=matrice[k][6])||((matrice[k][6]<=12)&&(mm==1)&&(aa>matrice[k][7])))&&(jj<=matrice[k][5])))
{printf("!! Vous Avez Un Emprunt Qui A Passe La Date De Retour Autorisee SVP Rendre Le et ensuite re-emprunter !! \n"); trouve=1;
printf(">>Livre a rendre est %i | %i | %i | %i | %i | %i | %i | %i <<\n",matrice[k][0],matrice[k][1],matrice[k][2],matrice[k][3],matrice[k][4],matrice[k][5],matrice[k][6],matrice[k][7]);}}}



}while ((strlen(cin)!= 8)||(check(cin)==0)||(cc==00000000)||(trouve==1));
matrice[j][0]=cc;



do{printf("Donner le num du livre encore DISPONIBLE SVP : ");scanf("%i",&x);
if (expminus(t_numlivre,x,taille,t_nb_exemp)==0)
    {aaa=3000;mmm=13;jjj=32;
for(k=0;k<j;k++)
{if(matrice[k][1]==x)
 {if(aaa>=matrice[k][7])
 {if(mmm>=matrice[k][6])
 {if(jjj>=matrice[k][5])
    {aaa=matrice[k][7];
        mmm=matrice[k][6];
        jjj=matrice[k][5];}}}}}printf("\n>>Livre non disponible ce livre sera disponible le %i / %i / %i << \n",jjj,mmm,aaa);}}
        while((recherche(x,taille,t_numlivre)==0)||(expminus(t_numlivre,x,taille,t_nb_exemp)==0));
                 matrice[j][1]=x;


matrice[j][2]=jj;
matrice[j][3]=mm;
matrice[j][4]=aa;

do{printf("DONNER LE NOMBRE DE JOURS POUR L'EMPRUNT (NE PEUT PAS DEPASSER 30 JOURS) : \n");scanf("%i",&nbj);}while((nbj<=0)||(nbj>30));

timer=time(NULL);
date = *gmtime( &timer ) ;
date.tm_mday = date.tm_mday + nbj;
date.tm_mon=date.tm_mon;
date.tm_year=date.tm_year;


if ((date.tm_mday>31)&&((date.tm_mon==1)||(date.tm_mon==3)||(date.tm_mon==5)||(date.tm_mon==7)||(date.tm_mon==8)||(date.tm_mon==10)||(date.tm_mon==12)))
{date.tm_mday = date.tm_mday-31;
date.tm_mon++;}

if ((date.tm_mday>30)&&((date.tm_mon==4)||(date.tm_mon==6)||(date.tm_mon==9)||(date.tm_mon==11)))
{date.tm_mday = date.tm_mday-30;
date.tm_mon++;}

if((date.tm_mday==2)&&(date.tm_year%4==0)&&(date.tm_year%100==0)&&(date.tm_year%400==0))
{date.tm_mday = date.tm_mday-29;
date.tm_mon++;}

if((date.tm_mday==2)&&(date.tm_year%4!=0)&&(date.tm_year%100!=0)&&(date.tm_year%400!=0))
{date.tm_mday = date.tm_mday-28;
date.tm_mon++;}

if(date.tm_mon>=12)
{date.tm_year = date.tm_year+1;
date.tm_mon=01;}else{date.tm_mon++;}


matrice[j][5]=date.tm_mday-1;
matrice[j][6]=date.tm_mon;
matrice[j][7]=date.tm_year+1900;


for(p=0;p<7;p++)
if (x==matemp[p][0])
  {matemp[p][1]++;
  if(matemp[p][2]==0){matemp[p][2]=jj; matemp[p][3]=mm; matemp[p][4]=aa;}
  if(matemp[p][7]<=matrice[j][7])
  {if((matemp[p][6]<=matrice[j][6])||((matemp[p][6]<=12)&&(matrice[j][6]==1)))
   {matemp[p][5]=matrice[j][5];
    matemp[p][6]=matrice[j][6];
    matemp[p][7]=matrice[j][7]; break;}}}



printf("\n>> AJOUT AVEC SUCCES <<\n");


do{printf("\n Voulez Vous Ajouter Un Autre Emprunt ?\n 1: OUI \n 0: NON \n => ");scanf("%i",&rep);}while((rep!=0)&&(rep!=1));

j++;


}while(rep!=0);


do{printf("\n Voulez Vous Rentrer Au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();
}
break;


                case 3:system("cls");
system("COLOR B");
printf("SUPPRESSION D'UN EMPRUNT \n");
printf("Les Emprunts Trouves :\n");

printf("%10s | %10s | %12s | %12s | %12s | %12s| %12s | %12s  \n",mat[0][0],mat[0][1],mat[0][2],mat[0][3],mat[0][4],mat[0][5],mat[0][6],mat[0][7]);
for(i=0;i<j;i++)
{printf("%10i | %10i | %12i | %12i | %13i | %11i | %11i  | %12i   \n",matrice[i][0],matrice[i][1],matrice[i][2],matrice[i][3],matrice[i][4],matrice[i][5],matrice[i][6],matrice[i][7]);}

do{do{printf("Donner le num de votre CIN SVP : "); scanf("%s",cin); cc=atoi(cin);}while ((strlen(cin)!= 8)||(check(cin)==0)||(cc==00000000));


do {printf("Donner le num du livre SVP : ");scanf("%i",&x);}while(recherche(x,taille,t_numlivre)==0);
q=j; trouve=0;
for (i=0;i<q+1;i++)
{if ((matrice[i][0]==cc)&&(matrice[i][1]==x))
    {for(k=i;k<=q;k++)
        for(f=0;f<8;f++)
        {matrice[k][f]=matrice[k+1][f]; trouve=1;}}}
    if((matrice[j][0]==cc)&&matrice[i][1]==x)
        {

        }
        if(trouve==1){j--; printf("\n>>SUPPRESSION TERMINEE AVEC SUCCES<<\n");}

        if(trouve==0){printf("\n>>EMPRUNT N'EXISTE PAS<<\n");}
printf("\n");

for(i=0;i<taille;i++)
if((trouve==1)&&(x==t_numlivre[i]))
{t_nb_exemp[i]=t_nb_exemp[i]+1; break;}

for(i=0;i<j;i++)
{printf("%10i | %10i | %12i | %12i | %13i | %11i | %11i  | %12i   \n",matrice[i][0],matrice[i][1],matrice[i][2],matrice[i][3],matrice[i][4],matrice[i][5],matrice[i][6],matrice[i][7]);}


do{printf("Voulez Vous Supprimer Un Autre Emprunt? \n 1: OUI \n 0: NON \n => ");scanf("%i",&rep);}while((rep!=0)&&(rep!=1));
  }while(rep!=0);

do{printf("\n Voulez Vous Rentrer Au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();}
break;


                case 4:system("cls");
system("COLOR B");
printf("CONSULTATION DES EMPRUNTS POUR UN ADHERENT \n");
do{do{printf("Donner Le Num De Votre CIN SVP : "); scanf("%s",&cin);cc=atoi(cin);}while ((strlen(cin)!= 8)||(check(cin)==0)||(cc==00000000));
ciin=atoi(cin);
printf("\nLes Emprunts Effectues Par L'adhérent %i Sont : \n",ciin);

printf("%10s | %10s | %12s | %12s | %12s | %12s| %12s | %12s  ",mat[0][0],mat[0][1],mat[0][2],mat[0][3],mat[0][4],mat[0][5],mat[0][6],mat[0][7]);
printf("\n");

for (i=0;i<j;i++)
{if(ciin==matrice[i][0])
{printf("%10i | %10i | %12i | %12i | %13i | %11i | %11i  | %12i \n",matrice[i][0],matrice[i][1],matrice[i][2],matrice[i][3],matrice[i][4],matrice[i][5],matrice[i][6],matrice[i][7]);}}

do{printf("\n Voulez Vous Consulter Les Emprunts D'un Autre Adherent? \n 1: OUI \n 0: NON \n => ");scanf("%i",&rep);}while((rep!=0)&&(rep!=1));}
while(rep!=0);

do{printf("\n Voulez Vous Rentrer Au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();}
break;

                case 5:system("cls");
goto menu;

                break;}

break ;


case 2 :system("cls");
            printf("______________________________________________________________________________\n") ;
            printf("______________________________________________________________________________\n") ; ;
            printf("                 Menu De Gestion Et Evaluation De La Bibliotheque             \n") ;
            printf("______________________________________________________________________________\n") ;
            printf("______________________________________________________________________________\n") ;
            printf("  1. Ajouter Un Livre                                                         \n") ;
            printf("  2. Supprimer Un Livre                                                       \n") ;
            printf("  3. Afficher Le Nombre D'Exemplaires Disponibles Pour Chaque Livre           \n") ;
            printf("  4. Afficher Un Ensemble D'Emprunts Relatifs A Une Date De Retour Prevue     \n") ;
            printf("  5. Supprimer Un Ensemble D'Emprunts                                         \n") ;
            printf("  6. Afficher Les Livres Les Plus Empruntes Dans Une Periode Donnee           \n") ;
            printf("  7. Afficher Le(s) Emprunteur(s) Le(s) Plus Fidele(s)                        \n") ;
            printf("______________________________________________________________________________\n") ;
            printf("______________________________________________________________________________\n") ;
            printf("  8. Menu Principal                                                           \n") ;
            printf("______________________________________________________________________________\n") ;
            do {
            printf("                           Entrez Votre Choix Ici SVP: ") ;
            scanf("%i",&chx_1) ;}
            while ((chx_1<1) || (chx_1>8));

                switch (chx_1)
                {
                    case 1 : system("cls") ;
system("COLOR B");
printf("AJOUT D'UN LIVRE \n");

do{printf("Donner Le Titre SVP:  "); scanf("%");gets(t_titre[taille]);
do{printf("Donner Le Numero Du Livre SVP :   ");scanf("%i",&t_numlivre[taille]);
if (recherche(t_numlivre[taille],taille,t_numlivre)==1)
{printf("\n NUMERO EXISTE DEJA ! \n");}}while(recherche(t_numlivre[taille],taille,t_numlivre)==1);
do{printf("Donner Le Nombre D'exemplaires Correspondant SVP:  ");scanf("%i",&t_nb_exemp[taille]);}while(t_nb_exemp[taille]<=0);
taille++;



do{printf("Voulez vous ajouter un autre livre ? \n 1: OUI \n 0: NON \n => ");scanf("%i",&rep);}while((rep!=0)&&(rep!=1));
}while (rep!=0);


do{printf("\n Voulez vous retourner au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();
}

break ;




                    case 2 : system("cls") ;
system("COLOR B");
printf("SUPPRESSION D'UN LIVRE \n");
trouve=1;
do{printf("Donner Le Numero Du livre A Supprimer SVP : ");scanf("%i",&x);
if (recherche(x,taille,t_numlivre)==1)
{for (i=0;i<taille+1;i++)
{if (t_numlivre[i]==x)
{for (k=i;k<=taille;k++)
        {strcpy(t_titre[k],t_titre[k+1]);
        t_numlivre[k]=t_numlivre[k+1];
        t_nb_exemp[k]=t_nb_exemp[k+1];trouve=0;}}}printf("\n SUPPRESSION TERMINEE AVEC SUCCES!! \n");} else {printf("\n Desole Livre Innexistant !\n");break;}

if (trouve==0){taille--; }

do{printf("Voulez Vous Supprimer Un Livre ?\n 1: OUI \n 0: NON \n => ");scanf("%i",&rep);}while((rep!=0)&&(rep!=1));}
while (rep!=0);
do{printf("\n Voulez Vous Retourner Au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();
}
break ;




                    case 3 : system("cls") ;
system("COLOR B");
printf("AFFICHAGE DU NOMBRE D'EXEMPLAIRES DES LIVRES EXISTANTS  \n");

printf("Les Livres  Disponibles Sont: \n");
printf("%15s |",num); printf("%26s  |  ",tit); printf("%15s \n",exp);
for (i=0;i<taille;i++)
{if(t_nb_exemp[i]!=0)
{printf("%15i | %26s | %15i \n",t_numlivre[i],t_titre[i],t_nb_exemp[i]);}}

do{printf("\n Voulez vous retourner au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();
}
break ;




                    case 4 : system("cls") ;
system("COLOR B");
printf("AFFICHAGE D'UN ENSEMBLE D'EMPRUNTS CORRESPONDANT A UNE DATE DE RETOUR PREVUE \n");
printf("\n");
do{printf("Donner Une Date De Retour Dont Vous Voulez Afficher L'ensemble D'emprunts Corrsepondant SVP :\n");
do{printf("jour retour prevu => "); scanf("%i",&jour);}while((jour<01)||(jour>31));
do{printf("mois retour prevu => "); scanf("%i",&mois);}while((mois<01)||(mois>12));
do{printf("annee retour prevue => "); scanf("%i",&annee);}while(annee<2019);
trouve=0;
for (i=0;i<j;i++)
{if((annee==matrice[i][7])&&(mois==matrice[i][6])&&(jour==matrice[i][5]))
    {printf("\nl'ensemble des emprunts respectifs a %i / %i / %i sont: \n %i %i %i %i %i %i %i %i \n",jour,mois,annee,matrice[i][0],matrice[i][1],matrice[i][2],matrice[i][3],matrice[i][4],
            matrice[i][5],matrice[i][6],matrice[i][7]);trouve=1;}
    if(trouve==0){printf("\n DESOLE AUCUN LIVRE NE CORRESPOND A CETTE DATE\n"); break;}}

do{printf("Voulez vous afficher un autre ensemble ? \n 1: OUI \n 0: NON \n => ");scanf("%i",&rep);}while((rep!=0)&&(rep!=1));

}while(rep!=0);

do{printf("\n Voulez vous retourner au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();
}
                break ;







                    case 5 : system("cls") ;
system("COLOR B");
printf("SUPPRESSION D'UN ENSEMBLE D'EMPRUNTS EN PRECISANT LES DEUX DATES DE RETOUR ET EMPRUNT \n");

printf("LES LIVRES DISPONIBlLES : \n");

printf("%10s | %10s | %12s | %12s | %12s | %12s| %12s | %12s  \n",mat[0][0],mat[0][1],mat[0][2],mat[0][3],mat[0][4],mat[0][5],mat[0][6],mat[0][7]);

for(y=0;y<j;y++)
{printf("\n%10i | %10i | %12i | %12i | %13i | %11i | %11i  | %12i  \n",matrice[y][0],matrice[y][1],matrice[y][2],matrice[y][3],matrice[y][4],matrice[y][5],matrice[y][6],matrice[y][7]);}


printf("\ndonner une date d'emprunt SVP :\n");
do{printf("jour emprunt => "); scanf("%i",&jour);}while((jour<01)||(jour>31));
do{printf("mois emprunt => "); scanf("%i",&mois);}while((mois<01)||(mois>12));
do{printf("annee emprunt => "); scanf("%i",&annee);}while(annee<2018);
do{ printf("\ndonner la date de retour SVP : \n");
do{printf("jour retour prevu => ");scanf("%i",&jo);}while((jo<01)||(jo>31));
do{printf("Le mois retour prevu => ");scanf("%i",&mo);}while((mo<01)||(mo>12));
do{printf("l'annee retour prevu => ");scanf("%i",&an);}while(an<2018);


i=0;
while(i<j){

   if(((jour<=matrice[i][2])&&((mois<=matrice[i][3])||((matrice[i][3]==12)&&(mois==1)))&&(annee<=matrice[i][4]))&&((jo>=matrice[i][5])&&
      ((mo>=matrice[i][6])||((mo==1)&&(matrice[i][6]<=12)))&&(an>=matrice[i][7])))
    {k=i;
        while (k<=(j-1))
        {matrice[k][0]=matrice[k+1][0];
        matrice[k][1]=matrice[k+1][1];
        matrice[k][2]=matrice[k+1][2];
        matrice[k][3]=matrice[k+1][3];
        matrice[k][4]=matrice[k+1][4];
        matrice[k][5]=matrice[k+1][5];
        matrice[k][6]=matrice[k+1][6];
        matrice[k][7]=matrice[k+1][7];
        k++;
        }
        j--;}
    else{i++;}}

printf("\nLA NOUVELLE LISTE DES LIVRES :\n");
printf("%10s | %10s | %12s | %12s | %12s | %12s| %12s | %12s  \n",mat[0][0],mat[0][1],mat[0][2],mat[0][3],mat[0][4],mat[0][5],mat[0][6],mat[0][7]);

for(i=0;i<j;i++)
{printf("\n%10i | %10i | %12i | %12i | %13i | %11i | %11i  | %12i  \n",matrice[i][0],matrice[i][1],matrice[i][2],matrice[i][3],matrice[i][4],matrice[i][5],matrice[i][6],matrice[i][7]);}


do{printf("Voulez vous supprimer un autre ensemble ? \n 1: OUI \n 0: NON \n => ");scanf("%i",&rep);}while((rep!=0)&&(rep!=1));

}while (rep!=0);

do{printf("\n Voulez vous retourner au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();}


                break ;


                    case 6 : system("cls") ;
system("COLOR B");
printf("AFFICHAGE DES LIVRES LES PLUS EMPRUNTES PENDANT UNE PERIODE PRECISE \n");
printf("Donner La periode:\n");
do{printf("Jour D'emprunt => ");scanf("%d",&jou);}while((jou<1)||(jou>31));
do{printf("Mois D'emprunt => ");scanf("%d",&moi);}while((moi<1)||(moi>12));
do{printf("Annee D'emprunt => "); scanf("%d",&ann);}while(ann<2018);
do{printf("Jour De Retour => ");scanf("%d",&day);}while((day<1)||(day>31));
do{printf("Mois De Retour => ");scanf("%d",&month);}while((month<1)||(month>12));
do{printf("Annee De Retour => "); scanf("%d",&year);}while(year<2018);

maxi=0;
for(i=0;i<7;i++)
    if((maxi< matemp[i][1])&&((jou<=matemp[i][2])&&((moi<=matemp[i][3])||((matemp[i][3]==1)&&(moi==12)))&&(ann<=matemp[i][4]))&&((day>=matemp[i][5])&&
      ((month>=matemp[i][6])||((month==1)&&(matemp[i][6]<=12)))&&(year>=matemp[i][7])))
      {maxi=matemp[i][1];}
       printf("\nPour Un Maximum De %i Le(s) Livre(s) Le(s) Plus Emprunte(s) Est|Sont : \n ",maxi);
printf("%10s | %10s  | %12s  | %12s  |  %12s |  %11s | %11s | %11s  \n",mat[0][0],mat[0][1],mat[0][2],mat[0][3],mat[0][4],mat[0][5],mat[0][6],mat[0][7]);

    for(i=0;i<7;i++)
    if(maxi==matemp[i][1]){printf("%11i | %11i | %13i | %13i | %14i | %12i | %10i  | %11i\n",matemp[i][0],matemp[i][1],matemp[i][2],matemp[i][3],matemp[i][4],
    matemp[i][5],matemp[i][6],matemp[i][7]);}



do{printf("\n Voulez vous retourner au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}
else
{system("cls");
printf("                  Au revoir!           \n");
abort();}

                break ;

                    case 7 : system("cls") ;
system("COLOR B");
printf("AFFICHAGE D'EMPRUNTEUR(S) LE(S) PLUS FREQUENT(S) \n");

printf("\nLa Liste des CINs des emprunteurs les plus frequents : \n") ;
max=0;
                    for (i=0;i<tl;i++)
                   {if (occ[i][1]>max)
                        max=occ[i][1];}
printf(">>Pour un nombre maximum d'emprunts : %i \n",max);
                    for (i=0;i<tl;i++)
                        {if (occ[i][1]==max)
                        printf("CIN : %i \n",occ[i][0]);}

do{printf("\n Voulez vous retourner au MP? \n 0 :QUITTER \n 1 :RETOURNER AU MENU PRINCIPAL \n =>  ");scanf("%i",&r);}while((r!=0)&&(r!=1));

if (r==1)
{system("cls");
goto menu;}

                break ;

                    case 8 : system("cls") ;
goto menu;
                    break ;
                }
break;

case 3 : system("cls"); system("COLOR B");
printf("                  Au revoir!           \n");
abort() ;
break ;}}


