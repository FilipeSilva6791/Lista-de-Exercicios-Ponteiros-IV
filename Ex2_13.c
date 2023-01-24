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

  Exerc�cio 2:

  void cpx_polar_out(complex_t *cpx, double *mod, double *ang);
  Fun��o : Retorna o valor da variavel cpx no formato polar
  Parametros : cpx � ponteiro para variavel tipo complexo_t
  mod � ponteiro para variavel de m�dulo
  ang � ponteiro para variavel de fase
  ***********************************************************************************/

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
  Retangular para polar:

  mod = raiz(real^2 + imaginario^2)
  angulo= arctg ( imaginario / real)
  */

  void cpx_polar_out (complex_t *cpx, double *mod, double *ang)
  {
     *mod=sqrt(pow(cpx->r,2)+pow(cpx->i,2));
     *ang=atan2(cpx->i,cpx->r);  //a fun��o atan2 retorna o arco-tangente de y/x (em radianos)

     *ang/=0.0174533;            //convertendo para graus
  }

  int main ()
  {
    setlocale(LC_ALL, "");

    double angulo,modulo;

    //declarando a estrutura
    complex_t num_retangular;

    //declarando e apontando os ponteiros
    complex_t *p_struct = &num_retangular;
    double *p_angulo=&angulo;
    double *p_modulo=&modulo;

    //pedindo os valores de um n�mero na forma retangular para o usu�rio
    printf("Informe abaixo os valores do n�mero complexo em forma retangular: \n");
    printf("Parte real: ");
    scanf("%lf",&num_retangular.r);
    printf("Parte imagin�ria: ");
    fflush(stdin);                    // serve para limpar o buffer do teclado
    scanf("%lf",&num_retangular.i);

    //chamando a fun��o
    cpx_polar_out(p_struct,p_modulo,p_angulo);

    //exibindo os resultados
    printf("\nConvertendo para forma polar, temos: \n");
    printf("Z = %.2lf[%.2lf�] \n\n",modulo,angulo);

    system("pause");
    return 0;




  }
