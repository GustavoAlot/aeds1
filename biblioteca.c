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
int caunt = 0;
char linhas[50];


void contarLinhas(){
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

void diferencia(){
    FILE * fp;
    fp = fopen("dados.txt","r");
    int i, j = 0;

    for(i = 0; i<caunt; i++){
        fgets(linhas,50,fp);
        int posicaodebarra=0;
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


void InserirLivro() {
    FILE *fp;
    fp = fopen("dados.txt","a");
    char titulo[200],autor[200];
    int paginas;

        printf("Escreva o titulo\n");
        scanf("%s" ,titulo);
        fprintf(fp,"%s/",titulo);
        printf("Escreva o autor\n");
        scanf("%s" ,autor);
        fprintf(fp,"%s/",autor);
        printf("Escreva o número de páginas\n");
        scanf("%d" ,&paginas);
        fprintf(fp,"%d/\n",paginas);
        fclose(fp);

        contarLinhas();
        diferencia();
}  



void ListarLivros(int caunt){
    int i, c;
    typedef struct 
    {
    char titulo[200];
    char autor[200];
    int paginas;
    }aux;

    aux *newstruc; 
        
    for (int i=0; i<caunt-1; i++){
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


void BuscarLivro(caunt){
    int i, existelivro;
    char quertitulo[200];
        
    printf("\t\n Voce escolheu buscar por um livro");
    printf("\n Digite o titulo do livro\n");
    scanf("%s", quertitulo);

    for(i=0;i<caunt;i++){
        if(strcmp(livros[i].titulo,quertitulo)==0){
            printf("\t\no livro existe no nosso acervo\n");
            printf("%s %s %d\n",livros[i].titulo,livros[i].autor,livros[i].paginas);
            existelivro=1;
        }
    }
    if(existelivro != 1){
        printf("o livro nao existe no nosso acervo");
    }

}

    

int main(){

    int i ,j;
    contarLinhas();


    livros=malloc(caunt*sizeof(livro));

    FILE * fp;
    fp = fopen("dados.txt","r");

    diferencia();

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
            //RemoverLivro();

            break;
        
        case 3:
           ListarLivros(caunt);

            break;
        
        case 4:
            BuscarLivro(caunt);

            break;
            

        case 5:
            return 0;
            break;

        default:
            printf("\n\t\tOpcao nao valida\n\n");
        } 
    } while (op !=0 );

    system("pause");
    return 0 ;
    }






   







    




    
    
