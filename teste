#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct 
{
    char titulo[200];
    char autor[200];
    int paginas;
}livro;

livro *livros;

int main(){
    //abrindo arquivo e alocando um vetor dinamicamente a partir da sua quantidade de linhas;
    FILE * fp;
    fp = fopen("dados.txt","r");
    char linhas[50];
    int i ,j,caunt = 0;

    for(i=0;fgets(linhas,50,fp)!=NULL;i++){
        caunt++;
    }

    livros=malloc(caunt*sizeof(livro));
    fclose(fp);


    //separar dados do arquivo (o qu é titulo, autor e paginas)
    fp = fopen("dados.txt","r");


    for(i=0;i<caunt;i++){
        fgets(linhas,50,fp);
        
        int tamanho=strlen(linhas);
        char titulo[200];
        char autor[200];
        char aux[200];
        int paginas;
        int j = 0, k = 0;
        while (linhas[j] != '/')
        {
            titulo[j] = linhas[j];
            j++;
        }
        titulo[j] = '\0';
        j++;
        while (linhas[j] != '/')
        {

            autor[k] = linhas[j];
            k++;
            j++;
        }
        j++;
        autor[k] = '\0';
        for(int l = 0; j < tamanho; j++, l++)
        {
            aux[l] = linhas[j];
        }

        paginas = atoi(aux);
        strcpy(livros[i].titulo, titulo);
        strcpy(livros[i].autor, autor);
        livros[i].paginas = paginas;
    }
        printf("%s %s %d \n",livros[0].titulo,livros[0].autor,livros[0].paginas);
        

    
        int InserirLivro(int caut);
    }


   int InserirLivro(int caut) {

        
        printf("\t\nVoce escolheu inserir um novo livro!");
        char newautor[200], newtitulo[200];
        int newpaginas;

        printf("\t\ndigite o Titulo do livro ");
        scanf("%s", newtitulo);
        strcpy(livros[caut+1].titulo, newautor);
        
        printf("\t\ndigite o nome do autor ");
        scanf("%s", newautor);
        strcpy(livros[caut+1].autor, newautor);

        printf("\t\ndigite o numero de paginas ");
        scanf("%d", &newpaginas);
        livros[caut+1].paginas= newpaginas;

        printf("%s %s %d \n",livros[0].titulo,livros[0].autor,livros[0].paginas);
        printf("%s %s %d",livros[1].titulo,livros[1].autor,livros[1].paginas);
        
    }   
