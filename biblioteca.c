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
        printf("\t\t     ( 2 ) Remover livro\n");
        printf("\t\t     ( 3 ) Listar livros cadastrados\n");
        printf("\t\t     ( 4 ) Buscar livros cadastrados\n");
        printf("\t\t     ( 5 ) Sair do programa\n");
        printf("\nOpcao Desejada: ");
        scanf("%d", &op);      

        switch (op){
            
        case 1:
            Inserir(DadosLivros.titulo, DadosLivros.autor, DadosLivros.paginas);
            break;



        case 4:
            BuscarLivro(DadosLivros.titulo);
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




    
    void BuscarLivro (char *titulo){
        FILE * fp;
        livro DadosLivro;
        char testetitulo[200];
        int result;
        
      
        fp = fopen("dados.txt","r+b");
     
        printf("\n\n\t\t\t    Campo: Buscar livros\n\n\n");
        printf("\t\t\t Busca de livros por Título:\n\n");
        
        printf("\nTítulo: ");
        scanf(" %s",testetitulo); 

        
               
        fread(&DadosLivro,sizeof(livro),1,fp);
         
           
        result = strcasecmp (testetitulo,DadosLivro.titulo);
            if (result == 0){
                printf("o livro existe no acervo");
                //fscanf(fp,"%s",&DadosLivro.titulo);
                printf("Titulo..........................: %s\n", DadosLivro.titulo);
                //fscanf(fp, "%s",&DadosLivro.autor);
                //printf("Autor...........................: %s\n", DadosLivro.autor);
                //fscanf(fp, "%d", &DadosLivro.paginas);
                //printf("Numero de paginas...............: %d\n", DadosLivro.paginas);
                //break;
            }else{
                if(feof(fp)){
                    printf("Nao ha livro no acervo com o titulo: %s\n\n", testetitulo );
                }
            }    
      
          

    }       

 
       
                            
