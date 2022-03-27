#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//codificador
void codificar(char texto[], char str1[], char str2[]){
  //primer ciclo recorre el texto
  for(int i=0;i<9;i++){
    char ct=texto[i];
    for (int e=0;e<3;e++){
      //segundo ciclo recorre las palabras claves 
      char p1=str1[e];
      char p2=str2[e];
      //si la palabra del texto selecionada coincide con 
      //una de las palabras claves.
      if(p1==ct){
        //si coinciden se reemplaza con la otra palabra en la misma posicion.
        texto[i]=p2;
      }
      else if(p2==ct){
        texto[i]=p1;
      }
    }
  }
  // mostas codificado 
  printf("Texto : \n");
  printf("%s",texto);
}
//Función que verifica que las palabras cumplan los requisitos
int requisito(char str1[], char str2[]){

  //Se definen las variables necesarias
  int len1 = strlen(str1); //Se cuenta el largo de las palabras claves
  int len2 = strlen(str2); 
  int i,j;
  int pass = 0;

  //Si se cumplen los requisitos (largo 5 e igual largo ambas) entra al if
  if(len1==len2 && len1==5){
    
    for(j=0; j<5; j++){

      // Si pass es igual a 1 (Que alguna letra este repetida) todo se rompe 
      if (pass==1){
        break;
      }

      //ciclo anidado donde i y j es la posición de las letras de las palabras
      for(i=0; i<5; i++){

        //Se comprueba que las letras sean mayusculas o no
        int r = isupper(str1[i]);
        int r2 = isupper(str2[j]);

        //Si son mayusculas (alguna de las 2), entran al siguiente if, donde se vuelven minusculas y se comparan. Si son iguales, se termina todo
        if (r ==  256 || r2 ==256){
          if (tolower(str1[i])==tolower(str2[j])){
            printf("Te equivocaste");
            pass = 1;
            break;
          }
        }

        //En caso contrario, se comprueban de manera normal
        else{
          if (str1[i] == str2[j]){
            printf("Te equivocaste");
            pass = 1;
            break;
          }
        }
      }
    }
  }
  return pass;
}

//Procedimiento base de enigma, donde se dan 5 variables (Nombre entrada archivo, acción decode o encode, palabra clave 1 y palabra clave 2, y por ultimo nombre salida archivo)
void enigma(char nombreE[], char accion[], , char mensaje[], char palabra1[], char palabra2[], char nombreS[]) {
  
  printf("\n%s\n", nombreE);

  //Corroboramos que las palabras cumplan los requisitos
  int corroborar = requisito(palabra1, palabra2);

  //Si cumplen, entra a la condición principal donde se genera lo pedido
  if (corroborar==0){
    
    //Aquí se ve si la acción pedida es encode o decode
    int valor = strcmp(accion, "encode");
    int valor2 = strcmp(accion, "decode");
    if (valor==0){
      printf("encode");
      }
    if (valor2==0){
      printf("decode");
      }
    if (valor!=0 && valor2!=0) {
      printf("Error, corralo de nuevo");
      }
    
    printf("\n%s\n\n", nombreS);
    
  }
}
  
int main(void) {
  enigma("Hola.txt", "decode", "Wena waxho qlo", "qwerv", "Tsdfg",   "Chao.txt");
  return 0;
}
