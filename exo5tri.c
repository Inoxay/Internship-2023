
#include <stdio.h>


void viderBuffer()     /* code à placer avant le main() */{char c;while ((c=getchar()) != '\n' && c!=EOF);} 

typedef struct{
	char sexe;
	char nom[50];
	int taille;
	int poids;}etu;
	
	void echange(etu *a, etu *b){
	etu c;
	c=*a;
	*a=*b;
	*b=c;}
	

float svelte(etu etudiant){
	float res;
	if  (etudiant.sexe=='F'){
		res=etudiant.taille-100-(etudiant.taille-150)/2;}
	else 
		res=etudiant.taille-100-(etudiant.taille-150)/4;
	return res;}

	
void affichetab(etu T[],int n){
	int i;
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\t%c\t%d\t%d\n",T[i].nom,T[i].sexe,T[i].taille,T[i].poids);
	}
}
void initab(etu T[], int n,int *compt){
	int i;
	for (i = 0; i < n; i++)
	{
		viderBuffer();
		printf("nom ?\n");
		scanf("%s",T[i].nom);
		
		viderBuffer();
		printf("cat ?\n");
		scanf("%c",&T[i].sexe);
		if (T[i].sexe=='F')(*compt)++;
		
		printf("taille ?\n");
		scanf("%d",&T[i].taille);
	
		printf("poids ?\n");
		scanf("%d",&T[i].poids);
		
	}
}

void trisex(etu T[],int n){
	int i,j;
	for (i = 0; i < n-1 ; i++)
	{	if (T[i].sexe=='H')
		{
		for (j=i+1; j < n ; j++)
			{
				if (T[j].sexe=='F')
				 {
				echange(&T[i],&T[j]);
				}
			}
		}
	}
}

void tripoids(etu T[],int n,int compt){
	int i,j,m;
	for (i = 0; i < compt-1 ; i++)
	{
		m=i;
		for (j=i+1; j < compt ; j++)
		{
			if (T[j].poids<T[m].poids) m=j;
		}
	echange(&T[i],&T[m]);
	}
	for (i = compt; i < n-1 ; i++)
	{
		m=i;
		for (j=i+1; j < n ; j++)
		{
			if (T[j].poids<T[m].poids) m=j;
		}
	echange(&T[i],&T[m]);
	}
}

comptpoids(etu T[],int *F,int *H,int compt,int n){
	int i;
	for (i = 0; i < compt ; i++)
	{
		if(T[i].poids>svelte(T[i]))(*F)++;
	}
	for (i = compt; i < n ; i++){
		if(T[i].poids>svelte(T[i]))(*H)++;
	}
}


int main(){
	etu T[250];
	int n,compt,F=0,H=0;
	printf("n?\n");
	scanf("%d",&n);
	initab(T,n,&compt);
	affichetab(T,n);
	trisex(T,n);
	affichetab(T,n);
	tripoids(T,n,compt);
	affichetab(T,n);
	comptpoids(T,&F,&H,compt,n);
	printf("F: nbre surpoids:%d\t min:%d\t max:%d\n",F,T[0].poids,T[compt-1].poids);
	printf("H: nbre surpoids:%d\t min:%d\t max:%d\n",H,T[compt].poids,T[n-1].poids);
	
	return 0;
	}
