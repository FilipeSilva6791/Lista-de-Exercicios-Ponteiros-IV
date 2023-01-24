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

  Exercício:
  void cpx_mul(complex_t *op1, complex_t *op2, complex_t *resultado);
  Função : Resultado recebe op1 * op2
  Parametros : op1 e op2 – ponteiro para as variaveis de entrada
  resultado – ponteiro para variavel que armazena resultado da operação
  *********************************************************************************/

  #include<stdio.h>
  #include<stdlib.h>
  #include<locale.h>
  #include<math.h>

  //declarando um novo tipo de dados
   typedef struct {
    double r; // parte real
    double i; // parte imaginaria
  } complex_t;

  void cpx_mul(complex_t *op1, complex_t *op2, complex_t *resultado)
  {
     //transformando o número em polar, para poder fazer a operação
     double ang1,mod1,ang2,mod2,ang3,mod3;

     mod1=sqrt(pow(op1->i,2)+pow(op1->r,2));
     ang1=atan2(op1->i,op1->r);

     mod2=sqrt(pow(op2->i,2)+pow(op2->r,2));
     ang2=atan2(op2->i,op2->r);

     /**
     a funcao atan2 já nos devolve o valor do angulo em radiano, por isso não precisa ser transformado
     para graus, podemos usar diretamente as funções sin e cos
     */

     //fazendo a multiplação com os valores em forma polar (angulos somam e modulos multiplicam)
     mod3=mod1*mod2;
     ang3=ang1+ang2;

     //transformando para retangular novamente
     resultado->r=mod3*cos(ang3);
     resultado->i=mod3*sin(ang3);
  }

  int main ()
  {
    setlocale(LC_ALL,"");

    //declarando as estruturas
    complex_t cpx1,cpx2,result;

    //declarando e apontando os ponteiros
    complex_t *p_cpx1,*p_cpx2,*p_result;

    p_cpx1=&cpx1;
    p_cpx2=&cpx2;
    p_result=&result;

    //pedindo dois números complexos para o usuario, para multiplica-los
    printf("Digite dois números complexos na forma retangular, para que possa ser feita a multiplicação:\n\n");

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
    cpx_mul(p_cpx1,p_cpx2,p_result);

    //exibindo os resultados
    printf("\nMultiplicação dos valores complexos: \n");
    printf("Z = %.2lf + %.2lfi \n\n",result.r,result.i);

    system("pause");
    return 0;
  }
