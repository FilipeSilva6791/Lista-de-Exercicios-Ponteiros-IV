 /**********************************************************************************
  Introdução:

  Implemente a função descrita nas questões a seguir, seguindo as especificações.
  No mesmo exercício, construa a função main() que utilize ou teste a função
  desenvolvida. Considerando o tipo de dados complex, declarado abaixo, implemente:
  O ângulo informado / retornado sempre está na escala de graus.

  typedef struct {
  double r; // parte real
  double i; // parte imaginaria
  } complex_t;

  Exercício 3:

  void cpx_soma(complex_t *op1, complex_t *op2, complex_t *resultado);
  Função : Resultado recebe op1 + op2
  Parametros : op1 e op2 – ponteiro para as variaveis de entrada
  resultado – ponteiro para variavel que armazena resultado da operação
  ***********************************************************************************/

  #include<stdio.h>
  #include<locale.h>
  #include<stdlib.h>
  #include<math.h>

  //declarando um novo tipo de dado complex_t por meio do typedef
  typedef struct
  {
     double r; //parte real
     double i; //parte imaginária
  } complex_t;

  void cpx_soma (complex_t *op1, complex_t *op2, complex_t *resultado)
  {
    //apenas soma os dois valores imaginarios, e os dois reais, e atribui ao resultado
    resultado->r=op1->r + op2->r;
    resultado->i=op1->i + op2->i;
  }

  int main ()
  {
    setlocale(LC_ALL,"");

    //declarando as estruturas do tipo complex_t
    complex_t cpx1,cpx2,soma;
    /*
    indice:
    cpx1 - complexo 1
    cpx2 - complexo 2
    soma - resultado da soma entre os dois complexos
    */

    //declarando e apontando os ponteiros
    complex_t *p_cpx1,*p_cpx2,*p_soma;
    p_cpx1=&cpx1;
    p_cpx2=&cpx2;
    p_soma=&soma;

    //pedindo dois números complexos para o usuário
    printf("Digite dois números complexos na forma retangular, para que possa ser feita a soma:\n\n");

    printf("Complexo 1: \n");
    printf("Parte real: ");
    scanf("%lf",&cpx1.r);
    printf("Parte imaginária:");
    scanf("%lf",&cpx1.i);

    printf("\nComplexo 2: \n");
    printf("Parte real: ");
    scanf("%lf",&cpx2.r);
    printf("Parte imaginária:");
    scanf("%lf",&cpx2.i);

    //chamando a função
    cpx_soma(p_cpx1,p_cpx2,p_soma);

    //apresentando os resultados
    printf("\nSoma dos valores complexos: \n");
    printf("Z = %.2lf + %.2lfi \n\n",soma.r,soma.i);

    system("pause");
    return 0;
  }
