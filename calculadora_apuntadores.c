#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char ch;

/////////////////////////////////////////////////////////////////////////
void exitmenu(void);

void sumArray(float *array, int size ){
    float suma=0;
    for (int i = 0; i < size ; i++){
       suma += array[i];
        }
    printf("La suma es : %12.5e\n",suma);
    exitmenu();
    }
void resArray(float *array, int size ){
    float resta=array[0];
    for(int i = 1; i < size ; i++){
       resta-=array[i];
        }
    printf("La resta es : %12.5e\n",resta);
    exitmenu();
    }
void divArray(float *array, int size ){
    float division=array[0];
    for(int i = 1; i < size ; i++){
        division/=array[i];
        }
    printf("La division es :%12.5e\n", division);
    exitmenu();
}
void modArray(float *array, int size ){
    int mod_usr,mod_out;
    
    printf("Introduzca el modulo : \n");
    scanf("%d",&mod_usr);
    
    for (int i = 0; i < size ; i++){
        mod_out=(int)array[i]%(int)mod_usr;
        printf("%d\n",mod_out);
        
        }
    exitmenu();
}
void multArray(float *array, int size ){
    float mult=array[0];
    for (int i = 1; i < size ; i++){
        mult *= array[i];
        }
    printf("La multiplicacion es :%12.5e\n",mult);
    exitmenu();
    }
void potencia(float *array, int size ){
    float potencias;
    float y;
    printf("Introduzca la potencia : \n");
    scanf("%f",&y);
    for (int i = 0; i < size ; i++){
        potencias=pow(array[i],y);
        printf("El cubo de %f : %12.5e \n",array[i],potencias);
        }
    exitmenu();
    }
/////////////////////////////////////////////////////////////////////////

void exitmenu(void){
    printf ("Realizar otro calculo? s/n: ");
    scanf (" %c", &ch);
    system("cls");
    }
void view(char *Ops[]){
    int ItOps;
    printf("Operaciones Aritmeticas\n");
    for (ItOps = 0; ItOps < 6 ; ItOps++){
        printf("%d -> %s \n",ItOps+1,Ops[ItOps]);
    }
}

////////////////////////////////////////////////////////////////////////

int main(){
    int count;
    int user_input;
    char *Ops[] = {"Suma","Resta","Division","Multiplicacion","Modulo","Cubo"};
    
    do{
        
    printf("==========================================================\n");
    printf("                C A L C U L A D O R A                     \n");
    printf("==========================================================\n");
    
    printf("Introduzca la cantidad de valores:\n");
    scanf("%d", &count);

    float *array = malloc(count * sizeof(*array));
    if (!array) {
        printf("Problema con malloc.");
        exit(EXIT_FAILURE);
    }
    printf("Introduzca los valores :\n");
    for (int i = 0; i < count; i++) scanf("%f", &array[i]);
    view(Ops);
    printf("Seleccione la opcion:\n");
    scanf("%d",&user_input);
    
    switch(user_input){
        case 1:
        sumArray(array,count);
        break;
        case 2:
        resArray(array,count);
        break;
        case 3:
        divArray(array,count);
        break;
        case 4:
        multArray(array,count);
        break;
        case 5:
        modArray(array,count);
        break;
        case 6:
        potencia(array,count);
        break;
        }
        
    }while(ch=='s' || ch == 'S');
}