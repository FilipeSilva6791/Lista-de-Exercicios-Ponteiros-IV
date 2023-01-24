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

  Exerc�cio 6:
  int cpx_div(complex_t *op1, complex_t *op2, complex_t *resultado);
  Fun��o : Resultado recebe op1 / op2
  Parametros : op1 e op2 � ponteiro para as variaveis de entrada
  resultado � ponteiro para variavel que armazena resultado da opera��o
  Retorno : 0 � opera��o realizada. -1 : divis�o por zero
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
     if(op2->r==0 && op2->i==0)     //divis�o por zero
        return -1;

     //transformando o n�mero em polar, para poder fazer a opera��o
     double ang1,mod1,ang2,mod2,ang3,mod3;

     mod1=sqrt(pow(op1->i,2)+pow(op1->r,2));
     ang1=atan2(op1->i,op1->r);

     mod2=sqrt(pow(op2->i,2)+pow(op2->r,2));
     ang2=atan2(op2->i,op2->r);

     /**
     a funcao atan2 j� nos devolve o valor do angulo em radiano, por isso n�o precisa ser transformado
     para graus, podemos usar diretamente as fun��es sin e cos
     */

     //fazendo a divis�o com os valores em forma polar (angulos subtraem e modulos dividem)
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

    //pedindo dois n�meros complexos para o usuario, para dividi-los
    printf("Digite dois n�meros complexos na forma retangular, para que possa ser feita a divis�o:\n\n");

    printf("Complexo 1: \n");
    printf("Parte real: ");
    scanf("%lf",&cpx1.r);
    printf("Parte imagin�ria:");
    scanf("%lf",&cpx1.i);

    printf("\nComplexo 2: \n");
    printf("Parte real: ");
    scanf("%lf",&cpx2.r);
    printf("Parte imagin�ria:");
    scanf("%lf",&cpx2.i);

    //chamando a fun��o
    status=cpx_div(p_cpx1,p_cpx2,p_result);

    //exibindo os resultados
    if(status==0)  //se a fun��o foi executada
    {
        printf("\nDivis�o dos valores complexos: \n");
        printf("Z = %.2lf + %.2lfi \n\n",result.r,result.i);
    } else {

        printf("\nERRO - Divis�o por zero\n\n");
    }

    system("pause");
    return 0;
  }

