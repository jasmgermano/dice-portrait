/*-------------------------------------------------------------------------
 *          UNIFAL - Universidade Federal de Alfenas.
 *            BACHARELADO EM CIÊNCIA DA COMPUTAÇÃO.
 * Trabalho..: Imagem de dados
 * Disciplina: Processamento de Imagens
 * Professor.: Luiz Eduardo da Silva
 * Aluno.....: Jasmine Germano França
 * Data......: 21/06/2022
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "imagelib.h"


// imagem de entrada, imagem de saida, n. de linhas e n. de colunas (saida, imagem original, dado), nível de cinza
void dados(image In, image Out, int nl_out, int nc_out, int nl, int nc, int nld, int ncd, int mnd)
{
    int aux = 0; 
    int cont = 0;

    //-- ler imagens dos dados
    image dado0 = img_get("0.pgm", &nld, &ncd, &mnd, GRAY);
    image dado1 = img_get("1.pgm", &nld, &ncd, &mnd, GRAY);
    image dado2 = img_get("2.pgm", &nld, &ncd, &mnd, GRAY);
    image dado3 = img_get("3.pgm", &nld, &ncd, &mnd, GRAY);
    image dado4 = img_get("4.pgm", &nld, &ncd, &mnd, GRAY);
    image dado5 = img_get("5.pgm", &nld, &ncd, &mnd, GRAY);
    image dado6 = img_get("6.pgm", &nld, &ncd, &mnd, GRAY);


    //-- percorrer imagem de saida
    for (int i = 0; i < nl_out; i = i+nld) {
        for (int j = 0; j < nc_out; j = j+ncd) {
            cont = 0;
                // verificar se o pixel está dentro do intervalo de cinza
            if (In[aux] >= 0 && In[aux] < 38) {
                    // percorrer região da imagem de entrada
                for (int k = i; k <= (nld+i)-1; k++) {
                    for (int l = j; l <= (ncd+j)-1; l++) {
                            // colocar imagem do dado na imagem de saida
                        Out[k*nc_out+l] = dado0[cont];
                        cont++;
                    }
                }
            } else {
                if (In[aux] >= 38 && In[aux] < 74) {
                    for (int k = i; k <= (nld+i)-1; k++) {
                        for (int l = j; l <= (ncd+j)-1; l++) {
                            Out[k*nc_out+l] = dado1[cont];
                            cont++;
                        }
                    }
                } else {
                    if (In[aux] >= 74 && In[aux] < 111) {
                        for (int k = i; k <= (nld+i)-1; k++) {
                            for (int l = j; l <= (ncd+j)-1; l++) {
                                Out[k*nc_out+l] = dado2[cont];
                                cont++;
                            }
                        }
                    } else {
                        if (In[aux] >= 111 && In[aux] < 147) {
                            for (int k = i; k <= (nld+i)-1; k++) {
                                for (int l = j; l <= (ncd+j)-1; l++) {
                                    Out[k*nc_out+l] = dado3[cont];
                                    cont++;
                                }
                            }
                        } else {
                             if (In[aux] >= 147 && In[aux] < 184) {
                                for (int k = i; k <= (nld+i)-1; k++) {
                                    for (int l = j; l <= (ncd+j)-1; l++) {
                                        Out[k*nc_out+l] = dado4[cont];
                                        cont++;
                                    }
                                }
                            } else {
                                if (In[aux] >= 184 && In[aux] < 219) {
                                    for (int k = i; k <= (nld+i)-1; k++) {
                                        for (int l = j; l <= (ncd+j)-1; l++) {
                                            Out[k*nc_out+l] = dado5[cont];
                                            cont++;
                                        }
                                    }
                                } else {
                                    if (In[aux] >= 219 && In[aux] < 256) {
                                        for (int k = i; k <= (nld+i)-1; k++) {
                                            for (int l = j; l <= (ncd+j)-1; l++) {
                                                Out[k*nc_out+l] = dado6[cont];
                                                cont++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }                      
        aux++;
        }
    }

}
  

   

void msg(char *s)
{
    printf("\nAtividade 1 - Imagem de dados");
    printf("\n-------------------------------");
    printf("\nUso:  %s  nome-imagem[.pgm] \n\n", s);
    printf("    nome-imagem[.pgm] é o nome do arquivo da imagem \n");
    exit(1);
}

/*-------------------------------------------------------------------------
 * main function
 *-------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int nc, nr, ml, nrd, ncd, mld;
    char *p, nameIn[100], nameOut[100], cmd[110];
    image In, Out, imgMenor, dado;
    int num_dado = 0;
    int fator;
    int soma = 0;
    int aux = 0;
    int linhas, colunas;
    if (argc < 2)
        msg(argv[0]);

    img_name(argv[1], nameIn, nameOut, GRAY);
    //-- ler imagem
    In = img_get(nameIn, &nr, &nc, &ml, GRAY);

    //-- redimensionar imagem
    fator = (nc/100);
    linhas = nr/fator; 
    colunas = nc/fator;
    imgMenor = img_alloc(linhas, colunas);
    
        // percorrer imagem de entrada
    for (int i = 0; i < linhas*fator; i = i+fator) {
        for (int j = 0; j < colunas*fator; j = j+fator) {
            soma = 0;
                // percorrer região da imagem de entrada
            for (int k = i; k <= (fator+i)-1; k++) {
                for (int l = j; l <= (fator+j)-1; l++) {
                    soma = soma + In[k*nc+l];
                }
            }
                // média dos pixels da região
            imgMenor[aux] = soma/(fator*fator);
            aux++;             
            
        }
    }

    // img_put(imgMenor, "imagem_menor.pgm", linhas, colunas, ml, GRAY);
    dado = img_get("0.pgm", &nrd, &ncd, &mld, GRAY);    

    Out = img_alloc(linhas*nrd, colunas*ncd);

    //-- transformação
    dados(imgMenor, Out, linhas*nrd, colunas*ncd, linhas, colunas, nrd, ncd, mld);
    printf("teset");
    //-- salvar imagem
    img_put(Out, nameOut, linhas*nrd, colunas*ncd, ml, GRAY);
    sprintf(cmd, "%s %s &", VIEW, nameOut);
    system(cmd);
    img_free(In);
    img_free(Out);
    return 0;
}
