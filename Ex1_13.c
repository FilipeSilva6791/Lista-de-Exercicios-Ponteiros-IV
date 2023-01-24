 /**********************************************************************************
  Introdu��o:

  Implemente a fun��o descrita nas quest�es a seguir, seguindo as especifica��es.
  No mesmo exerc�cio, construa a fun��o main() que utilize ou teste a fun��o
  desenvolvida. Considerando o tipo de dados complex, declarado abaixo, implemente:
  O �ngulo informado / retornado sempre est� na escala de graus.

  typedef struct {
  double r; // parte real
  double i; // parte imaginaria
  } complex_t;

  Exerc�cio 1:
  1. void cpx_polar_in(complex_t *cpx, double mod, double ang);
  Fun��o : atribui � vari�vel cpx o valor, dado em formato polar (modulo e �ngulo).
  Parametros : cpx � ponteiro para variavel tipo complexo_t
  mod � m�dulo do valor
  ang � fase do valor
  **********************************************************************************/

  #include<stdio.h>
  #include<locale.h>
  #include<stdlib.h>
  #include<math.h>

  //declarando um novo tipo de dado complex_t por meio do typedef
  typedef struct
  {
     double r; //parte real
     double i; //parte imagin�ria
  } complex_t;

  /**
  Para converter n�meros complexos da forma polar para a retangular
  fazemos os seguintes c�luclos:

  parte real = modulo * coss(angulo)
  parte imaginaria = modulo * sen(angulo)
  */

  void cpx_polar (complex_t *cpx, double mod, double ang)
  {
     ang*=0.0174533;        //onvertendo de graus para radianos, para poderem ser usadas as fun��es sin() e cos()
     cpx->r=mod*cos(ang);
     cpx->i=mod*sin(ang);

     // '->' � a forma de se referir a um membro de uma estrutura por meio de ponteiros
  }

  int main ()
  {
    setlocale(LC_ALL, "");

    double angulo,modulo;

    //declarando a estrutura
    complex_t num_retangular;

    //declarando e apontando um ponteiro deste tipo de dados
    complex_t *p_struct = &num_retangular;

    //pedindo os valores de um n�mero na forma polar para o usu�rio
    printf("Informe abaixo os valores do n�mero complexo em forma polar: \n");
    printf("M�dulo: ");
    scanf("%lf",&modulo);
    printf("�ngulo (em graus): ");
    fflush(stdin);                    // serve para limpar o buffer do teclado
    scanf("%lf",&angulo);

    //chamando a fun��o
    cpx_polar(p_struct,modulo,angulo);

    //exibindo os resultados
    printf("\nConvertendo para forma retangular, temos: \n");
    printf("Z = %.2lf + %.2lfi \n\n",num_retangular.r,num_retangular.i);

    system("pause");
    return 0;
  }
