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
    fp = fopen("dados.txt","rw");
    char linhas[50];
    int i ,j,caunt;

    for(i=0;fgets(linhas,50,fp)!=NULL;i++){
        caunt++;
    }

    livros=malloc(caunt*sizeof(livro));
    fclose(fp);

    for(i=0;i<caunt;i++){
        fgets(linhas,50,fp);
        int posicaodebarra=0;
        int tamanho=strlen(linhas);
        for(j=0;linhas[j] == "/";j++){
        }
        titulo = 0 ate j-1;
        posicaodebarra = j;
        for(j;linhas[j] == "/";j++){
        }
        autor = posicaodebarra ate j-1;
        }
        char *paginas = "536";
        int paginass = atoi(paginas);
        
    
        
    

    system("clear");
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
            InserirLivro();
            break;
        case 2:

            break;
        
        case 3:
            ListarLivros();

            break;
        
        case 4:
            BuscarLivro();

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



void InserirLivro(){    
    livro DadosLivro;
    FILE * fp;
    fp = fopen("dados.txt","a");
    

        printf("\n\t\t\t  Voce escolheu cadastrar livro!\n");

        printf("digite o nome do livro\n"); 
        scanf("%s", &DadosLivro.titulo);
        fprintf(fp," %s/",DadosLivro.titulo);
        printf("digite os autores do livro\n");
        scanf("%s", &DadosLivro.autor);
        fprintf(fp," %s/",DadosLivro.autor);
        printf("Digite o numero de paginas\n");
        scanf("%d", &DadosLivro.paginas);
        fprintf(fp," %d/\n",DadosLivro.paginas);

        fclose(fp);
}


void BuscarLivro (){
    char testetitulo[200];
    
     
    printf("\n\n\t\t\t    Campo: Buscar livros\n\n\n");
    printf("\t\t\t Busca de livros por Título:\n\n");
        
    printf("\nTítulo: ");
    scanf(" %s",testetitulo); 
 
}


    
void ListarLivros(){


}


