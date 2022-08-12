 #include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


typedef struct                  //estrutura dos livros
{
    char titulo[200];
    char autor[200];
    int paginas;
}livro;

livro *livros;
int caunt = 0;               
char linhas[50];



void contarLinhas(){            //funcao para contar linhas do txt.
    FILE * fp;
    caunt=0;
    fp = fopen("dados.txt","r");

    if((fp = fopen("dados.txt","r"))==NULL){
        fp = fopen("dados.txt","w");
    }

    char linhas[50];
    int i ,j;

    for(i=0;fgets(linhas,50,fp)!=NULL;i++){
        caunt++;
    }
    fclose(fp);
}


void diferencia(){                //funcao que diferencia titulo,autor e paginas colocando dentro do vetor de livros.
    FILE * fp;
    fp = fopen("dados.txt","r");
    int i, j = 0;

    for(i = 0; i<caunt; i++){
        fgets(linhas,50,fp);
        int tamanho=strlen(linhas);
        char titulo[200];
        char autor[200];
        char aux[200];
        int paginas;
        int j = 0, k = 0;
        while (linhas[j] != '/'){
            titulo[j] = linhas[j];
            j++;
        }

        titulo[j] = '\0';
        j++;
        while (linhas[j] != '/'){
            autor[k] = linhas[j];
            k++;
            j++;
        }

        j++;
        autor[k] = '\0';
        for(int l = 0; j < tamanho; j++, l++){
            aux[l] = linhas[j];
        }

        paginas = atoi(aux);
        strcpy(livros[i].titulo, titulo);
        strcpy(livros[i].autor, autor);
        livros[i].paginas = paginas;
    }
}



void InserirLivro() {                //função para inserir um novo livro no arqquivo txt
    FILE *fp;
    fp = fopen("dados.txt","a");
    char titulo[200],autor[200];
    int paginas,i,existelivro=0;
    contarLinhas();
        
        printf("\tVocê escolheu inserir um novo livro!\n");
        printf("\tEscreva o titulo\n");
        scanf("%s" ,titulo);
        
        for(i=0;i<caunt;i++){
            if(strcmp(livros[i].titulo,titulo)==0){             //conferindo se o livro ja existe para nao inserir repetido
            printf("\t\n O livro já existe no nosso acervo! ");
            existelivro=1;
            }
        }

        if (existelivro!=1){        
            fprintf(fp,"%s/",titulo);
            printf("\tEscreva o autor\n");
            scanf("%s" ,autor);
            fprintf(fp,"%s/",autor);
            int true = 0;
            char numpag[10000];
            do{
                true = 1;
                printf("\tEscreva o número de páginas\n");
                scanf("%s" ,&numpag);
                for (int i = 0; numpag[i] != '\0'; i++) {           //garantindo que digite um inteiro
                    if (numpag[i] > 'a' && numpag[i] < 'z') { 
                        true=0;
                    }
                }
            }while (true != 1);
            paginas = atoi(numpag);
            fprintf(fp,"%d/\n",paginas);
        }

    fclose(fp);
    contarLinhas();
    diferencia();
}  



void ListarLivros(){                //funcao parar listar os livros em ordem alfabetica.
    
    int i, c;

    typedef struct {
    char titulo[200];
    char autor[200];
    int paginas;
    }aux;

    contarLinhas();
    diferencia();

    aux newstruc[caunt]; 

    printf("\n\t\tVocê escolheu listar todos os livros, aqui estão em ordem alfabética:\n\n");
        
    for (int i=0; i<caunt-1; i++){                 //percorre as linhas fazendo ordenação
        for (int j=0; j<caunt-1-i; j++){
            if (strcmp(livros[j].titulo,livros[j+1].titulo) > 0){

                strcpy(newstruc[j].titulo,livros[j].titulo);
                strcpy(newstruc[j].autor,livros[j].autor);
                newstruc[j].paginas=livros[j].paginas;

                strcpy(livros[j].titulo,livros[j+1].titulo);
                strcpy(livros[j].autor,livros[j+1].autor);
                livros[j].paginas=livros[j+1].paginas;
                
                strcpy(livros[j+1].titulo, newstruc[j].titulo);
                strcpy(livros[j+1].autor, newstruc[j].autor);
                livros[j+1].paginas =newstruc[j].paginas;
            }
        }
    }
    for(i=0;i<caunt;i++){
        printf("%s %s %d\n",livros[i].titulo,livros[i].autor,livros[i].paginas);
    }
}




void BuscarLivro(){                 //funcao para buscar algum livro pelo titulo.
    int i, existelivro=0;
    char quertitulo[200];

    contarLinhas();
    diferencia();
        
    printf("\t\n Você escolheu buscar por um livro no nosso acervo!");
    printf("\n\t Digite o titulo do livro.\n");
    scanf("%s", quertitulo);

    for(i=0;i<caunt;i++){           //verifica se o livro existe
        if(strcmp(livros[i].titulo,quertitulo)==0){          
            printf("\t\n O livro pesquisado existe no nosso acervo,aqui está:  ");
            printf("%s %s %d\n",livros[i].titulo,livros[i].autor,livros[i].paginas);
            existelivro=1;
        }
    }
    if(existelivro != 1){
        printf("Desculpe, o livro pesquisado não existe no nosso acervo.");
    }
}


void RemoverLivro(){                 //função que remove livro do acervo a partir do título
    char quertitulo[200];
    int i ,j,existelivro=0,position,newcaunt;
    FILE  *fp;
    
    
    fp = fopen("dados.txt","a");
    contarLinhas();
    diferencia();
    newcaunt=caunt;
    fclose(fp);

    printf("\n\n\t\tVocê escolheu remover um livro do acervo\n");
    printf("Digite o titulo a ser removido\n\n");
    scanf("%s", quertitulo);

    for(i=0;i<caunt;i++){                 //verifica se o livro existe e salva o indicie do livro escolhido para remoção
        if(strcmp(livros[i].titulo,quertitulo)==0){ 
            existelivro=1;
            position=i;
        }
    }
    if(existelivro!= 1){
        printf("\n\n\t\tO livro ja nao existe no acervo!\n");
        return 0;
    }

    fp = fopen("dados.txt","w");


    for(i=0;i<caunt-1;i++){             //reescreve o arquivo pulando o livro que desejou ser removido
        if(i != position){
            fprintf(fp,"%s/%s/%d/\n",livros[i].titulo,livros[i].autor,livros[i].paginas);
        }else if (i == position && i != caunt-1){
            caunt++;
            fprintf(fp,"%s/%s/%d/\n",livros[i+1].titulo,livros[i+1].autor,livros[i+1].paginas);
            i++;
        }
    }
    
fclose(fp);           
}
    

       





int main(){

    int i ,j;
    contarLinhas();

    livros=malloc(caunt*sizeof(livro));     //alocando dinamicamente o veotor de struct livro


    diferencia();

    char op[50];
    int newop;
    do{
        printf("\n\n\n");
        printf("\n\t\t    Sistema de biblioteca\n\n");
        printf("\n\t\t     ( 1 ) Cadastrar novo livro\n");
        printf("\t\t     ( 2 ) Remover livro\n");
        printf("\t\t     ( 3 ) Listar livros cadastrados\n");
        printf("\t\t     ( 4 ) Buscar por livro cadastrado\n");
        printf("\t\t     ( 5 ) Sair do programa\n");
        printf("\nOpcao Desejada: ");
        scanf("%s", &op);
        newop = atoi(op) ;     

        switch (newop){
            
        case 1:
            InserirLivro();
            break;
            
        case 2:
            RemoverLivro();
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
            printf("\n\t\tOpção não válida\n\n");
        } 
    } while (op !=0);

    system("pause");
    return 0 ;
}
