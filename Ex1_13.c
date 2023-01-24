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

  Exercício 1:
  1. void cpx_polar_in(complex_t *cpx, double mod, double ang);
  Função : atribui à variável cpx o valor, dado em formato polar (modulo e ângulo).
  Parametros : cpx – ponteiro para variavel tipo complexo_t
  mod – módulo do valor
  ang – fase do valor
  **********************************************************************************/

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

  /**
  Para converter números complexos da forma polar para a retangular
  fazemos os seguintes cáluclos:

  parte real = modulo * coss(angulo)
  parte imaginaria = modulo * sen(angulo)
  */

  void cpx_polar (complex_t *cpx, double mod, double ang)
  {
     ang*=0.0174533;        //onvertendo de graus para radianos, para poderem ser usadas as funções sin() e cos()
     cpx->r=mod*cos(ang);
     cpx->i=mod*sin(ang);

     // '->' é a forma de se referir a um membro de uma estrutura por meio de ponteiros
  }

  int main ()
  {
    setlocale(LC_ALL, "");

    double angulo,modulo;

    //declarando a estrutura
    complex_t num_retangular;

    //declarando e apontando um ponteiro deste tipo de dados
    complex_t *p_struct = &num_retangular;

    //pedindo os valores de um número na forma polar para o usuário
    printf("Informe abaixo os valores do número complexo em forma polar: \n");
    printf("Módulo: ");
    scanf("%lf",&modulo);
    printf("Ângulo (em graus): ");
    fflush(stdin);                    // serve para limpar o buffer do teclado
    scanf("%lf",&angulo);

    //chamando a função
    cpx_polar(p_struct,modulo,angulo);

    //exibindo os resultados
    printf("\nConvertendo para forma retangular, temos: \n");
    printf("Z = %.2lf + %.2lfi \n\n",num_retangular.r,num_retangular.i);

    system("pause");
    return 0;
  }
