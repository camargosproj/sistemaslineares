#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int ordemMax;
double calcularDeterminate(double matriz[][ordemMax], int ordem);
double calcularCofator(double matriz[][ordemMax],int ordem,int linha,int coluna);
double matrizCoef(double matriz[][ordemMax], double det,int ordem);
void mostrar();
bool menu();


int main(){
    while (true){
        if(!menu()){
            break;
        }
    }
    return 0;
}

bool menu(){
    int op;
    printf("\e[1;1H\e[2J");
    printf("Esse programa resolve sistemas Lineares de 2 e 3 Variaveis!\n");
    printf("Digite o número da operação que deseja realizar\n");
    printf("3 - Sistema de 2 variaveis\n");
    printf("4 - Sistema de 3 variaveis\n");
    printf("5 - Sair\n");
    scanf("%d",&ordemMax);
    if (ordemMax == 3){
        mostrar(ordemMax);

    }else if(ordemMax == 4){
        mostrar(ordemMax);
    }else if(ordemMax == 5){
        return false;
    }else{
        printf("Entrada Invalida!\n");
        menu();
       

    }

}
void mostrar(int var){
    double matriz[var-1][var];
    double matrizD[var-1][var-1];
    printf("\e[1;1H\e[2J");
    //Adicionando elementos ao sistema
    printf("Digite seu sistema:\n");
    for(int i = 0; i < var; i++){
        for (int j = 0; j < var-1; j++){
            if(i == 0){
                printf("Digite os valores de x:");
                scanf("%lf", &matriz[j][i]);
            }else if(i == 1){
                printf("Digite os valores de y:");
                scanf("%lf", &matriz[j][i]);
            }else if(i == 2 && var == 3){
                printf("Digite os termos indepenentes:");
                scanf("%lf", &matriz[j][i]);
            }else if(i == 2 && var == 4){
                printf("Digite os valores de Z:");
                scanf("%lf", &matriz[j][i]);
            }else if(i == 3){
                printf("Digite os termos indepenentes:");
                scanf("%lf", &matriz[j][i]);
            }    
            
        }
    }
    //Transformando o sistema em uma matriz
      for(int i = 0; i < var-1; i++){
       for (int j = 0; j < var-1; j++){
           matrizD[i][j] = matriz[i][j];      
       }
      }
    //imprimindo a matriz com os coeficientes
    printf("\e[1;1H\e[2J");  
    //imprimindo o sistema completo
     printf("O sistema Digitado foi:\n");
    for(int i = 0; i < var-1; i++){
       for (int j = 0; j < var; j++){
            if (j ==0){
                printf("%.1lfX", matriz[i][j]);
            }else if(j == 1){
                printf("%.1lfy", matriz[i][j]);
            }else if(j == 2 && var == 3){
                printf("=%.1lf", matriz[i][j]);
            }else if(j == 2 && var == 4){
                printf("%.1lfz", matriz[i][j]);
            }else if(j == 3 && var == 4){
                printf("=%.1lf", matriz[i][j]);
            }    
      
       }
        printf("\n");
    }
    matrizCoef(matriz,calcularDeterminate(matrizD, var-1), var);
}
double matrizCoef(double matriz[][ordemMax],double det, int ordem){
  double matrizDx[ordem-1][ordem-1];
  double matrizDy[ordem-1][ordem-1];
  double matrizDz[ordem-1][ordem-1];

  printf("Ordem aqui %d\n",ordemMax);
  // Adicionando o elemento complementar da ultima coluna 
   for(int i = 0; i < ordem-1; i++){
        for (int j = 0; j < ordem-1; j++){
            if(i == 0){
                matrizDx[j][i] = matriz[j][ordem-1];
            }else if(i == 1){
                matrizDx[j][i] = matriz[j][i];
            }else if(i == 2){
                matrizDx[j][i] = matriz[j][i];
            }
               
            
        }
    }    
     printf("Esse é o Dx:\n");
    for(int i = 0; i < ordem-1; i++){
       for (int j = 0; j < ordem-1; j++){
            printf("\t%.3lf", matrizDx[i][j]);      
       }
        printf("\n");

    }  
    // Add elemntos em Dy
       for(int i = 0; i < ordem-1; i++){
        for (int j = 0; j < ordem-1; j++){
            if(i == 0){
                matrizDy[j][i] = matriz[j][i];
            }else if(i == 1){
                matrizDy[j][i] = matriz[j][ordem-1];
            }else if(i == 2){
                matrizDy[j][i] = matriz[j][i];
            }     
            
        }
    }   
    printf("Esse é o Dy:\n");
    for(int i = 0; i < ordem-1; i++){
       for (int j = 0; j < ordem-1; j++){
            printf("\t%.3lf", matrizDy[i][j]);      
       }
        printf("\n");


    }  
    if(ordem == 4){
         // Adicionando o elemento complementar da ultima coluna 
   for(int i = 0; i < ordem-1; i++){
        for (int j = 0; j < ordem-1; j++){
            if(i == 0){
                matrizDz[j][i] = matriz[j][i];
            }else if(i == 1){
                matrizDz[j][i] = matriz[j][i];
            }else if(i == 2){
                matrizDz[j][i] = matriz[j][ordem-1];
            }
               
            
        }
    }    
     printf("Esse é o Dz:\n");
    for(int i = 0; i < ordem-1; i++){
       for (int j = 0; j < ordem-1; j++){
            printf("\t%.3lf", matrizDz[i][j]);      
       }
        printf("\n");
    } 
}
    printf("O det da matriz é %.3lf\n",det);
    printf("O valor de Dx é %.3lf\n",calcularDeterminate(matrizDx,ordem-1)/det);
    printf("O valor de Dy é %.3lf\n",calcularDeterminate(matrizDy,ordem-1)/det);
    if(ordem ==4 ){
            printf("O valor de Dz é %.3lf\n",calcularDeterminate(matrizDz,ordem-1)/det);
    }
}

double calcularCofator(double matriz[][ordemMax-1],int ordem,int linha,int coluna){
  double matrizCofator[ordemMax-1][ordemMax-1];
  int n = ordem - 1;
  int x = 0;
  int y = 0;

  for (int i = 0; i < ordem; i++)
  {
    for (int j = 0; j < ordem; j++)
    {
      if(i != linha && j != coluna){
        matrizCofator[x][y] = matriz[i][j];
        y++;
        if(y >= n){
          x++;
          y = 0;

        }
      }
    }
    
  }
  // retorna o determinante de cada cofator 
  return pow(-1.0, linha + coluna) * calcularDeterminate(matrizCofator, n);
}

double calcularDeterminate(double matriz[][ordemMax], int ordem){

  int determinante = 0;
    // Calcula Determinante
    if (ordem == 1){
      determinante = matriz[0][0];
    }else{
      for (int coluna = 0; coluna < ordem; coluna++)
      {
        determinante = determinante + matriz[0][coluna] * calcularCofator(matriz,ordem,0, coluna);
      }
      
    }
    return determinante;
}


