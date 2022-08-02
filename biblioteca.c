#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct 
{
    char titulo[200];
    char autor[200];
    int paginas;
}livro;



void Inserir(char*titulo ,char*autor,int paginas);
void RemoverLivro();
void ListarLivros();
void BuscarLivro();



int main(){
    livro DadosLivros;



    int op;
    do{
        printf("\n\n\n");
        printf("\n\t\t\t     Sistema de biblioteca\n\n");
        printf("\n\t\t     ( 1 ) Cadastrar livro\n");
        printf("\t\t     ( 2 )   Remover livro\n");
        printf("\t\t     ( 3 ) Listar livros cadastrados\n");
        printf("\t\t     ( 4 ) Buscar livros cadastrados\n");
        printf("\t\t     ( 5 ) Sair do programa\n");
        printf("\nOpcao Desejada: ");
        scanf("%d", &op);      

        switch (op){
            
        case 1:
            Inserir(DadosLivros.titulo, DadosLivros.autor, DadosLivros.paginas);
            break;


            
        
        case 5:
            break;
    
        
          

        default:
            printf("Opcao nao valida\n\n");
        } 
    }while (op !=0 );

    system("pause");
    return 0 ;
    }








    void Inserir(char*titulo ,char*autor,int paginas){
        livro DadosLivro;
        FILE * fp;
         fp = fopen("dados.txt","a");
    

        printf("\n\t\t\t  Voce escolheu cadastrar livro!\n");

            printf("digite o nome do livro\n"); 
            scanf("%s", &DadosLivro.titulo);
            fprintf(fp," %s",DadosLivro.titulo);
            printf("digite os autores do livro\n");
            scanf("%s", &DadosLivro.autor);
            fprintf(fp," %s",DadosLivro.autor);
            printf("Digite o numero de paginas\n");
            scanf("%d", &DadosLivro.paginas);
            fprintf(fp," %d",DadosLivro.paginas);

            fclose(fp);
    }




    

            
        
    





    
       
       
    









