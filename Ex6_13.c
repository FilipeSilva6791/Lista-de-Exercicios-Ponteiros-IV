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

  Exercício 6:
  int cpx_div(complex_t *op1, complex_t *op2, complex_t *resultado);
  Função : Resultado recebe op1 / op2
  Parametros : op1 e op2 – ponteiro para as variaveis de entrada
  resultado – ponteiro para variavel que armazena resultado da operação
  Retorno : 0 – operação realizada. -1 : divisão por zero
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

   int cpx_div(complex_t *op1, complex_t *op2, complex_t *resultado)
  {
     if(op2->r==0 && op2->i==0)     //divisão por zero
        return -1;

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

     //fazendo a divisão com os valores em forma polar (angulos subtraem e modulos dividem)
     mod3=mod1/mod2;
     ang3=ang1-ang2;

     //transformando para retangular novamente
     resultado->r=mod3*cos(ang3);
     resultado->i=mod3*sin(ang3);

     return 0;
  }

  int main ()
  {
    setlocale(LC_ALL,"");
    int status;

    //declarando as estruturas
    complex_t cpx1,cpx2,result;

    //declarando e apontando os ponteiros
    complex_t *p_cpx1,*p_cpx2,*p_result;

    p_cpx1=&cpx1;
    p_cpx2=&cpx2;
    p_result=&result;

    //pedindo dois números complexos para o usuario, para dividi-los
    printf("Digite dois números complexos na forma retangular, para que possa ser feita a divisão:\n\n");

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
    status=cpx_div(p_cpx1,p_cpx2,p_result);

    //exibindo os resultados
    if(status==0)  //se a função foi executada
    {
        printf("\nDivisão dos valores complexos: \n");
        printf("Z = %.2lf + %.2lfi \n\n",result.r,result.i);
    } else {

        printf("\nERRO - Divisão por zero\n\n");
    }

    system("pause");
    return 0;
  }

