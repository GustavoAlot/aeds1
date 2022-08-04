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
    
    FILE * fp;
    fp = fopen("dados.txt","r");
    char linhas[50];
    int i ,j,caunt = 0;

    for(i=0;fgets(linhas,50,fp)!=NULL;i++){
        caunt++;
    }

    livros=malloc(caunt*sizeof(livro));
    fclose(fp);

    fp = fopen("dados.txt","r");

    for(i=0;i<caunt;i++){
        fgets(linhas,50,fp);
        int posicaodebarra=0;
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
        //printf("%s %s %d \n",livros[0].titulo,livros[0].autor,livros[0].paginas);
        //printf("%s %s %d",livros[1].titulo,livros[1].autor,livros[1].paginas);

    //system("clear");
    int op;
    do{
        printf("\n\n\n");
        printf("\n\t\t\t     Sistema de biblioteca\n\n");
        printf("\n\t\t     ( 1 ) Cadastrar livro\n");
        printf("\t\t     ( 2 ) Remover livro\n");
        printf("\t\t     ( 3 ) Listar livros cadastrados\n");
        printf("\t\t     ( 4 ) Buscar livros cadastrados\n");
        printf("\t\t     ( 5 ) Sair do programa\n");
        printf("\nOpcao Desejada: ");
        scanf("%d", &op);      

        switch (op){
            
        case 1:
            //InserirLivro();
            break;
        case 2:
            //RemoverLivro();

            break;
        
        case 3:
           //ListarLivros();

            break;
        
        case 4:
            //BuscarLivro();

            break;
            

        case 5:
            return 0;
            break;

        default:
            printf("\n\t\tOpcao nao valida\n\n");
        } 
    }while (op !=0 );

    system("pause");
    return 0 ;
    }
