#include "fonction_fichiers.h"

char** allouer_tab_2D(int n,int m){
	char** tableau2d = malloc(n*sizeof(char*));

	for(int i = 0; i < n; ++i)
	{
		tableau2d[i] = malloc(m*sizeof(char));
	}
	for (int j=0;j<n;j++){
		for (int k=0;k<m; k++){
			tableau2d[j][k]=' ';
		}
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

		for (int j = 0; j < m; ++j)
		{
			printf("%c", tab[i][j]);
		}
		printf("\n");
	}

}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol){
	FILE* fichier = fopen(nomFichier, "r");
	if(fichier==NULL){
		printf("c'EST NULLE");
	}

	char c; 
	int nl=0,nc=0,tmp;
 	*nbLig=0;
 	*nbCol=0;
	while((c=(char) fgetc(fichier))!= EOF)
	{
		if(c=='\n'){
			if (nl==0){
				tmp=nc;
			}
			else{
				if (nc>tmp){
					tmp=nc;
				}
			}
			nl++;
			nc=0;
		}
		else{
			nc++;
		}
	}
	*nbLig=nl;
	*nbCol=tmp;
	fclose(fichier);

	//printf("Nombre de lignes: %d\n",*nbLig );
	//printf("Nombre de colonnes: %d\n",*nbCol );
}

char** lire_fichier(const char* nomFichier){
	int nl=0,nc=0;
	taille_fichier(nomFichier,&nl,&nc);
	char** tableau2d = allouer_tab_2D(nl, nc);
	FILE* fichier = fopen(nomFichier, "r");
	if (fichier!=NULL)
	{

	 	for (int j = 0; j < nl; ++j)
	 	{
			fscanf(fichier,"%s",tableau2d[j]);
	 	}
	 	fclose(fichier);
	}
	else {
		printf("le fichier est null");
	}
	return tableau2d;
}

char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(tab[i][j]==ancien){
				tab[i][j]=nouveau;
			}
		}
	}
	return tab;
}

void ecrire_fichier(const char* nomFichier, char** tab, int n, int m){
	FILE* fichier=fopen(nomFichier,"w");
	if(fichier!=NULL){
		for(int j=0;j<n;j++){
			fprintf(fichier,"%s\n",tab[j]);
		}
		fclose(fichier);
	}
	else{
		printf("Le fichier est null");
	}
}