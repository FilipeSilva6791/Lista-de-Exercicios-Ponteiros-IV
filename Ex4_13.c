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

  Exerc�cio 4:
  void cpx_sub(complex_t *op1, complex_t *op2, complex_t *resultado);
  Fun��o : Resultado recebe op1 - op2
  Parametros : op1 e op2 � ponteiro para as variaveis de entrada
  resultado � ponteiro para variavel que armazena resultado da opera��o
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

  void cpx_sub (complex_t *op1, complex_t *op2, complex_t *resultado,int opcao)
  {
    if(opcao==1){                     //subtrai o segundo n�mero do primeiro
    resultado->r=op1->r - op2->r;
    resultado->i=op1->i - op2->i;
    }else{                         //subtrai o primeiro do segundo
    resultado->r=op2->r - op1->r;
    resultado->i=op2->i - op1->i;
    }
  }

  int main ()
  {
    setlocale(LC_ALL,"");

    int aux=0;
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

    //pedindo dois n�meros complexos para o usu�rio e como ele quer subtrair
    printf("Digite dois n�meros complexos na forma retangular, para que possa ser feita a subtra��o:\n\n");

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

    printf("\nPara subtrair o segundo n�mero complexo do primeiro, digite 1.\nSe voc� deseja subtrair o primeiro n�mero complexo do segundo, digite 2.\n");

    while(aux !=1 && aux !=2){
        printf("Digite sua op��o: ");
        fflush(stdin);
        scanf("%d",&aux);
    };

    //chamando a fun��o
    cpx_sub(p_cpx1,p_cpx2,p_soma,aux);

    //apresentando os resultados
    printf("\nSubtra��o dos valores complexos: \n");
    printf("Z = %.2lf + %.2lfi \n\n",soma.r,soma.i);

    system("pause");
    return 0;
  }

