#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<time.h>

typedef struct equipe
{
    char nom[30];
    int point;

} Equipe;


int existe(int t[],int k,int j)
{
int i;
for(i=0;i<k;i++)
{
if(t[i]==j)
{
    return 1;
}
}
return 0;
}

int egalite(int t1[])
{

   if(t1[0]==t1[1])
    {
      return 1;
    }
    return 0;

}

void  Tour_1()
{
    FILE* fp[4];
    FILE* fpool[8];
    char s[200];
    int i=0;
    int k=0;
    int j;
    int t[8];

    fp[0]=fopen("niveau1.txt","r");
    fp[1]=fopen("niveau2.txt","r");
    fp[2]=fopen("niveau3.txt","r");
    fp[3]=fopen("niveau4.txt","r");
    fpool[0]=fopen("groupes/POUL_A.txt","w");
    fpool[1]=fopen("groupes/POUL_B.txt","w");
    fpool[2]=fopen("groupes/POUL_C.txt","w");
    fpool[3]=fopen("groupes/POUL_D.txt","w");
    fpool[4]=fopen("groupes/POUL_E.txt","w");
    fpool[5]=fopen("groupes/POUL_F.txt","w");
    fpool[6]=fopen("groupes/POUL_G.txt","w");
    fpool[7]=fopen("groupes/POUL_H.txt","w");

  for(i=0;i<4;i++)

	{ while(k<8)
		{

        srand(time(NULL));
            do {

		j=rand()%8;
		}
		while(existe(t,k,j));
	fgets(s,200,fp[i]);

	t[k]=j;
	k++;
	fprintf(fpool[j],"%s\n",s);
	}
	 k=0;
}
for(i=0;i<4;i++){
fclose(fp[i]);}
for(i=0;i<8;i++){
fclose(fpool[i]);}

printf("                                           Tirage au sort effectu%c",130);
}

void Tour_2()
{
    FILE* fp1[8];
    FILE* fp2[8];
    Equipe e[32];
    char s1[200],lettre='A';
    char sh1[30];
    int i=0;
    int f=0;
    int k=0;
    int y,r;
    int j,g,h,l,val;
    int equipe_1_score=0,equipe_2_score=0;
    int t[8];
    fp1[0]=fopen("groupes/POUL_A.txt","r");
    fp1[1]=fopen("groupes/POUL_B.txt","r");
    fp1[2]=fopen("groupes/POUL_C.txt","r");
    fp1[3]=fopen("groupes/POUL_D.txt","r");
    fp1[4]=fopen("groupes/POUL_E.txt","r");
    fp1[5]=fopen("groupes/POUL_F.txt","r");
    fp1[6]=fopen("groupes/POUL_G.txt","r");
    fp1[7]=fopen("groupes/POUL_H.txt","r");

    fp2[0]=fopen("phase2/PHASE_A.txt","w");
    fp2[1]=fopen("phase2/PHASE_B.txt","w");
    fp2[2]=fopen("phase2/PHASE_C.txt","w");
    fp2[3]=fopen("phase2/PHASE_D.txt","w");
    fp2[4]=fopen("phase2/PHASE_E.txt","w");
    fp2[5]=fopen("phase2/PHASE_F.txt","w");
    fp2[6]=fopen("phase2/PHASE_G.txt","w");
    fp2[7]=fopen("phase2/PHASE_H.txt","w");


printf("                                                GROUPES \n\n\n");
srand(time(NULL));
 for(i=0;i<8;i++)
 {
     f=0;
  while(fgets(s1,200,fp1[i]))
 {
    if(strlen(s1)!=1)
    {
    sscanf(s1,"%s",e[f].nom);
    e[f].point=0;
    f++;

    }
    }

printf("                                                POULE %c  :\n\n",lettre);
    printf("                                  Equipe 1        Equipe 2    R%csultat \n \n",130);
    lettre+=1;

    for(j=0;j<f;j++)
    {
     for(k=j+1;k<f;k++)
        {
           equipe_1_score=rand()%5;
           equipe_2_score=rand()%5;
        printf("                                %s       %s :    %d  -  %d \n",e[j].nom,e[k].nom,equipe_1_score,equipe_2_score);

         if(equipe_1_score > equipe_2_score) /* l'equipe 1 à gangnée par raport à l'equipe 2 */
		{
         e[j].point+=3;

		}
		else if(equipe_1_score < equipe_2_score)
		{
		e[k].point+=3;
		}
		else
            {

		     e[j].point++;
             e[k].point++;
             }
        }
        }
        printf("\n");
        printf("                                Equipes        nombres des points");
        printf("\n");



        for(h=0;h<f-1;h++)
        {
            for(l=h+1;l<f;l++)
            {
                if(e[l].point>e[h].point)
                {

                   sscanf(e[h].nom,"%s",sh1);
                   val=e[h].point;
                   sscanf(e[l].nom,"%s",e[h].nom);
                   e[h].point=e[l].point;
                   sscanf(sh1,"%s",e[l].nom);
                   e[l].point=val;
                 }
            }
        }

    for(y=0;y<f;y++)
 {
     printf("                                   %s                 %d \n",e[y].nom,e[y].point);
 }

 for(r=0;r<2;r++)
 {
     fprintf(fp2[i],"%s\n",e[r].nom);
 }

    printf("\n\n\n");
     }

for (i=0;i<8;i++)
{

fclose(fp1[i]);
fclose(fp2[i]);}
    }


void Tour_3()
{

    FILE* fp3_1[8];
    FILE* fp3_2[8];
    FILE* fp4[4];
    Equipe e1[32];
    Equipe e2[32];
    char s1[200],s2[200];

    int y,r,v,i;

    int l,val,cpt2,cpt1,t[3];
    int equipe_1_gr1_score,equipe_2_gr2_score,equipe_2_gr1_score,equipe_1_gr2_score;
   // int t[8];
    fp3_1[0]=fopen("phase2/PHASE_A.txt","r");
    fp3_1[1]=fopen("phase2/PHASE_B.txt","r");
    fp3_1[2]=fopen("phase2/PHASE_C.txt","r");
    fp3_1[3]=fopen("phase2/PHASE_D.txt","r");
    fp3_1[4]=fopen("phase2/PHASE_E.txt","r");
    fp3_1[5]=fopen("phase2/PHASE_F.txt","r");
    fp3_1[6]=fopen("phase2/PHASE_G.txt","r");
    fp3_1[7]=fopen("phase2/PHASE_H.txt","r");

    fp3_2[0]=fopen("phase2/PHASE_A.txt","r");
    fp3_2[1]=fopen("phase2/PHASE_B.txt","r");
    fp3_2[2]=fopen("phase2/PHASE_C.txt","r");
    fp3_2[3]=fopen("phase2/PHASE_D.txt","r");
    fp3_2[4]=fopen("phase2/PHASE_E.txt","r");
    fp3_2[5]=fopen("phase2/PHASE_F.txt","r");
    fp3_2[6]=fopen("phase2/PHASE_G.txt","r");
    fp3_2[7]=fopen("phase2/PHASE_H.txt","r");


    fp4[0]=fopen("phase3/PHASE_A.txt","w");
    fp4[1]=fopen("phase3/PHASE_B.txt","w");
    fp4[2]=fopen("phase3/PHASE_C.txt","w");
    fp4[3]=fopen("phase3/PHASE_D.txt","w");

   i=0,v=1;

printf("                                                  1/8  DE FINAL \n\n\n");
printf("                                    Equipe 1        Equipe 2    R%csultat \n \n",130);

srand(time(NULL));
   while(i<7)
    {
   cpt1=0;
   cpt2=0;
   while((fgets(s1,200,fp3_1[i]))&&(fgets(s2,200,fp3_1[v])))
    {
   if(strlen(s1)!=1)
    {
    sscanf(s1,"%s",e1[cpt1].nom);
    cpt1++;
    }
    if(strlen(s2)!=1)
    {
    sscanf(s2,"%s",e2[cpt2].nom);
    cpt2++;
    }
    }


  do
  {
  t[0]= rand()%6;
  t[1]=rand()%5;




  }while(egalite(t));

equipe_1_gr1_score=t[0];
equipe_2_gr2_score=t[1];


   if(equipe_1_gr1_score>equipe_2_gr2_score)/*Equipe premiere de de premier groupe à gangné par raport à equipe deuxieme de deuxieme groupe*/
   {
 printf("                                      %s       %s :    %d  -  %d \n\n",e1[0].nom,e2[1].nom,equipe_1_gr1_score,equipe_2_gr2_score);


  if(i==0 || i==2)
  {
    fprintf(fp4[0],"%s\n",e1[0].nom);
  }else if(i==4 || i==6)
  {
   fprintf(fp4[1],"%s\n",e1[0].nom);
  }





  } else  if(equipe_1_gr1_score<equipe_2_gr2_score)/*Equipe deuxieme de de deuxieme groupe à gangné par raport à equipe premiere de premier groupe*/
   {
  printf("                                     %s       %s :    %d  -  %d \n\n",e1[0].nom,e2[1].nom,equipe_1_gr1_score,equipe_2_gr2_score);

   if(i==0 || i==2)
  {
    fprintf(fp4[0],"%s\n",e2[1].nom);
  }else if(i==4 || i==6)
  {
   fprintf(fp4[1],"%s\n",e2[1].nom);
  }
}

i+=2;
v+=2;
}

 i=0,v=1;

while(i<7)
    {
   cpt1=0;
   cpt2=0;
   while((fgets(s1,200,fp3_2[i]))&&(fgets(s2,200,fp3_2[v])))
    {
   if(strlen(s1)!=1)
    {
    sscanf(s1,"%s",e1[cpt1].nom);
    cpt1++;
    }
    if(strlen(s2)!=1)
    {
    sscanf(s2,"%s",e2[cpt2].nom);
    cpt2++;
    }
    }


  do
  {
  t[1]= rand()%5;
  t[0]=rand()%6;
  }while(egalite(t));

equipe_2_gr1_score=t[1];
equipe_1_gr2_score=t[0];


   if(equipe_1_gr2_score<equipe_2_gr1_score)/*l'equipe deuxieme du premier groupe à gangné par raport à l'equipe premiere du deuxieme groupe*/
   {
 printf("                                      %s       %s :    %d  -  %d \n \n",e2[0].nom,e1[1].nom,equipe_1_gr2_score,equipe_2_gr1_score);

  if(i==0 || i==2)
  {
    fprintf(fp4[2],"%s\n",e1[1].nom);
  }else if(i==4 || i==6)
  {
   fprintf(fp4[3],"%s\n",e1[1].nom);
  }




  } else  if(equipe_1_gr2_score>equipe_2_gr1_score)/*l'equipe deuxieme du premier groupe à perdu par raport à l'equipe premiere du deuxieme groupe*/
   {
  printf("                                     %s       %s :    %d  -  %d \n \n",e2[0].nom,e1[1].nom,equipe_1_gr2_score,equipe_2_gr1_score);

  if(i==0 || i==2)
  {
    fprintf(fp4[2],"%s\n",e2[0].nom);
  }else if(i==4 || i==6)
  {
   fprintf(fp4[3],"%s\n",e2[0].nom);
  }

  }




i+=2;
v+=2;
}

for(i=0;i<8;i++){
fclose(fp3_1[i]);
fclose(fp3_2[i]);
if(i<4)
fclose(fp4[i]);
}
}

void Tour_4()
{
    FILE* fp1[4];
    FILE* fp2[2];
    Equipe e[32];
    char s[200];

    int i,f,t[2],equipe1,equipe2;

    int equipe_1_score=0,equipe_2_score=0;

    fp1[0]=fopen("phase3/PHASE_A.txt","r");
    fp1[1]=fopen("phase3/PHASE_B.txt","r");
    fp1[2]=fopen("phase3/PHASE_C.txt","r");
    fp1[3]=fopen("phase3/PHASE_D.txt","r");

    fp2[0]=fopen("phase4/PHASE_A.txt","w");
    fp2[1]=fopen("phase4/PHASE_B.txt","w");

    printf("                                       1/4 DE FINAL \n\n");
    printf("                           Equipe 1        Equipe 2    R%csultat \n \n",130);
    srand(time(NULL));

    for(i=0;i<4;i++)
 {
    f=0;
  while(fgets(s,200,fp1[i]))
 {
    if(strlen(s)!=1)
    {
    sscanf(s,"%s",e[f].nom);
    f++;
    }
    }

    do
    {
     t[0]= rand()%5;
     t[1]=rand()%5;
    }while(egalite(t));
    equipe_1_score=t[0];
    equipe_2_score=t[1];

    if(equipe_1_score>equipe_2_score)/*l'equipe 1 a gagné*/
   {
 printf("                                %s       %s :    %d  -  %d \n \n",e[0].nom,e[1].nom,equipe_1_score,equipe_2_score);

  if(i==0 || i==1)
  {
    fprintf(fp2[0],"%s\n",e[0].nom);
  }else if(i==2 || i==3)
  {
   fprintf(fp2[1],"%s\n",e[0].nom);
  }




   }
   else if(equipe_1_score<equipe_2_score)/*l'equipe 2 a gagné*/
   {
     printf("                           %s       %s :    %d  -  %d \n \n",e[0].nom,e[1].nom,equipe_1_score,equipe_2_score);

  if(i==0 || i==1)
  {
   fprintf(fp2[0],"%s\n",e[1].nom);
  }else if(i==2 || i==3)
  {
   fprintf(fp2[1],"%s\n",e[1].nom);
  }

   }
 }
 for(i=0;i<4;i++){
 fclose(fp1[i]);
 if(i<2)
 fclose(fp2[i]);
 }
}


void Tour_5()
{
    FILE* fp1[4];
    FILE* fp2[2];
    char s[200];
    Equipe e[32];

    int i,f,t[2],equipe1,equipe2;

    int equipe_1_score=0,equipe_2_score=0;

    fp1[0]=fopen("phase4/PHASE_A.txt","r");
    fp1[1]=fopen("phase4/PHASE_B.txt","r");

    fp2[0]=fopen("phase5/FINAL.txt","w");
    fp2[1]=fopen("phase5/TROISIEME_PLACE.txt","w");

    printf("                                            1/2 FINAL \n\n");
    printf("                                  Equipe 1        Equipe 2    R%csultat \n \n",130);
    srand(time(NULL));

    for(i=0;i<2;i++)
 {
    f=0;
  while(fgets(s,200,fp1[i]))
 {
    if(strlen(s)!=1)
    {
    sscanf(s,"%s",e[f].nom);
    f++;
    }
    }

    do
    {
     t[0]= rand()%5;
     t[1]=rand()%5;
    }while(egalite(t));
    equipe_1_score=t[0];
    equipe_2_score=t[1];

    if(equipe_1_score>equipe_2_score)/*l'equipe 1 a gagné*/
   {

     printf("                                   %s       %s :    %d  -  %d \n \n",e[0].nom,e[1].nom,equipe_1_score,equipe_2_score);
     fprintf(fp2[0],"%s\n",e[0].nom);
     fprintf(fp2[1],"%s\n",e[1].nom);
   }
   else if(equipe_1_score<equipe_2_score)/*l'equipe 2 a gagné*/
   {
     printf("                                   %s       %s :    %d  -  %d \n \n",e[0].nom,e[1].nom,equipe_1_score,equipe_2_score);
     fprintf(fp2[0],"%s\n",e[1].nom);
     fprintf(fp2[1],"%s\n",e[0].nom);
  }

   }
   for(i=0;i<2;i++){
 fclose(fp1[i]);
 fclose(fp2[i]);
 }
 }


 void Tour_6()
{
    FILE* fp1[4];
    FILE* fp2[2];
    char s[200];
    Equipe e[32];

    int i,f,t[2],equipe1,equipe2;

    int equipe_1_score=0,equipe_2_score=0;

    fp1[0]=fopen("phase5/FINAL.txt","r");
    fp1[1]=fopen("phase5/TROISIEME_PLACE.txt","r");

    fp2[0]=fopen("phase6/FINAL.txt","w");
    fp2[1]=fopen("phase6/TROISIEME_PLACE.txt","w");

    printf("                                                  FINAL\n\n");
    printf("                                Equipe 1        Equipe 2    R%csultat \n \n",130);
    srand(time(NULL));

    for(i=0;i<2;i++)
 {
    f=0;
  while(fgets(s,200,fp1[i]))
 {
    if(strlen(s)!=1)
    {
    sscanf(s,"%s",e[f].nom);
    f++;
    }
    }

    do
    {
     t[0]= rand()%5;
     t[1]=rand()%5;
    }while(egalite(t));
    equipe_1_score=t[0];
    equipe_2_score=t[1];

    if(equipe_1_score>equipe_2_score)/*l'equipe 1 a gagné*/
   {

     if(i==1){  printf("                                           MATCH CLASSEMENT\n\n");}
     printf("                                     %s       %s :    %d  -  %d \n \n",e[0].nom,e[1].nom,equipe_1_score,equipe_2_score);
     if(i==0)
     {
     fprintf(fp2[0],"%s     LE CHAMPION DU MONDE\n",e[0].nom);
     fprintf(fp2[0],"%s     DEUXIEME PLACE\n",e[1].nom);
     }else
     {
      fprintf(fp2[1],"%s     TROISIEME PLACE\n",e[0].nom);
      fprintf(fp2[1],"%s     QUATRIEME PLACE\n",e[1].nom);
     }
   }
   else if(equipe_1_score<equipe_2_score)/*l'equipe 2 a gagné*/
   {

     if(i==1){  printf("                                           MATCH CLASSEMENT\n\n");}
     printf("                                     %s       %s :    %d  -  %d \n \n",e[0].nom,e[1].nom,equipe_1_score,equipe_2_score);
      if(i==0)
     {
     fprintf(fp2[0],"%s     LE CHAMPION DU MONDE\n",e[1].nom);
     fprintf(fp2[0],"%s     DEUXIEME PLACE\n",e[0].nom);
     }else
     {
      fprintf(fp2[1],"%s    TROISIEME PLACE\n",e[1].nom);
      fprintf(fp2[1],"%s    QUATRIEME PLACE\n",e[0].nom);
     }
  }



 }
 int l;
 for(l=0;l<2;l++){

 fclose(fp1[l]);
 fclose(fp2[l]);

 }
}


int main()
{
    int num;
do
	{
		system("cls");
		 printf("******************************MENU******************************\n");
		printf("\n\n\n\t Coupe_du_monde_Tableau");
		printf("\n\n\t01. Tour 1");
		printf("\n\n\t02. Tour 2");
		printf("\n\n\t03. Tour 3");
		printf("\n\n\t04. Tour 4");
		printf("\n\n\t05. Tour 5");
		printf("\n\n\t06. Tour 6");
		printf("\n\n\t07. Quiter");
		printf("\n\n\tS%clectionnez votre option (1-7) ",130);
		scanf("%d",&num);
		system("cls");
		switch(num)
		{
		case 1:
			Tour_1();
			break;
		case 2:
		    Tour_2();
		   break;
		case 3:
		    Tour_3();
			break;
		case 4:
		    Tour_4();
			break;
		case 5:
            Tour_5();
            break;
		case 6:
            Tour_6();
			break;
		case 7:
			printf("\n\n\t Au revoir!!!!");
			break;

		default :printf("\a");
		}
    getch();
	}while(num!=7);

	return 0;
}

