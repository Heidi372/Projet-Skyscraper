#include "fonction_fichiers.h"

char** allouer_tab_2D(int n,int m){
	char** tableau2d = malloc(n*sizeof(char));

	for(int i = 0; i < n; ++i)
	{
		tableau2d[i] = malloc(m*sizeof(char));
	}

	return tableau2d;

}

void desallouer_tab_2D(char** tab, int n){
	for(int i = 0; i < n; ++i)


	{
		free(tab[i]);
	}

	free(tab);
}

void afficher_tab_2D(char** tab, int n, int m){
	for (int i = 0; i < n; ++i)
	{
		printf("Ligne %d\n",i);

		for (int j = 0; j < m; ++j)
		{
			printf("Colonne %d",j);

			printf("%s", &tab[n][m]);
		}
	}

}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol){
	FILE* fichier = fopen(nomFichier, "r");
	

	int c;
	int c2 = '\0';
 
 	rewind(fichier);

	while((c=fgetc(fichier))!= EOF)
	{
		if(c=='\n')
			nbLig++;
		else
			nbCol++;
		c2 = c;
	}
 
	
	if(c2 != '\n')
		nbLig++; 
 
	printf("Nombre de lignes: %ls\n",nbLig );
	printf("Nombre de colonnes: %ls\n",nbCol );
}

char** lire_fichier(const char* nomFichier){
	int n,m;
	char** tableau2d = allouer_tab_2D(n, m);

	char c; 

	FILE* fichier = fopen(nomFichier, "r");

	rewind(fichier);

	for(int i = 0; i < n; ++i)
	{

	 	for (int j = 0; j < m; ++j)
	 	{
			c=fgetc(fichier);
	 		while(c!='\n')
			{
				tableau2d[i][j]=c;
			}
	 	}

	}

	return tableau2d;
}