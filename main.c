/* 
 * File:   main.c
 * Author: jhonson
 *
 * Created on 22 de agosto de 2015, 03:57 PM
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * 
 */
//Puntero a la funcion menu para evitar warring
void (* MenuP) ();

//Estructura que almacena todos los metadatos del archivo
struct Documento{
    struct Titulo *Titulo;
    struct Autor *Autor;
    char *PalabraClave;
    struct Descripcion *Descripcion;
    char *Fecha;
    char *Tipo;
    char *Formato;
    int Identificardor;
    char *Lenguaje;
    char *Publicador;
    char *Contibullentes;
    char *Fuente;
    char *Relacion;
    char *Covertura;
    char *Derechos; 
    char *Ruta;
    char *NombreArchivo;
    };
    //Estructura que almacena los titulos
    struct Titulo{
        char *Titulo1;
        char *Titulo2;
        char *Titulo3;
        char *Titulo4;
        char *Titulo5;
    };
    //Estructura que almacena los autores
    struct Autor{
        char *Autor1;
        char *Autor2;
        char *Autor3;
        char *Autor4;
        char *Autor5;
    };
    //Estructura que almacena las descripciones
    struct Descripcion{
        char *Descripcion1;
        char *Descripcion2;
        char *Descripcion3;
        char *Descripcion4;
        char *Descripcion5;
    };
    
//Estructura que almacna los datos nesesarios para hacer un nodo de una lista enlazada y la estructura Documento  
struct Nodo{
    
    struct Documento *Dato;
    struct Nodo *Siguiente; 
    };
//Estructura que almacena la lizta enlazada  
struct ListaEnlazada{
        int size;
        struct Nodo *Raiz;
        struct Nodo *Last;   
    };
    
//Lista enlazada donde se almacena los datos de tipo nodo    
struct ListaEnlazada Lista={0};

//Agrega un nodo a la lista enlazada
void agregar(struct Documento *P, struct ListaEnlazada *Lista){
    if(Lista->size==0){
        Lista->size=0;
    }
    struct Nodo *NodoAgregar;
    NodoAgregar = (struct Nodo *) malloc (sizeof(struct Nodo));
        if(Lista->size==0){
            
        NodoAgregar->Siguiente=NULL;    
        NodoAgregar->Dato=P;
        Lista->Raiz=NodoAgregar;
        Lista->Last=NodoAgregar;
        Lista->size++;
        
        }else{
            Lista->Last->Siguiente=NodoAgregar;
            NodoAgregar->Dato=P;
            NodoAgregar->Siguiente=NULL;
            Lista->size++;
            Lista->Last=NodoAgregar;
        }
    }

//Imprime todos lo que contiene los nodos
void imprimir(struct ListaEnlazada *Lista){
    int i=0;
    struct Nodo *Temp;
    Temp=Lista->Raiz;
    while(i!=Lista->size){
        printf("Indice en la lista %d \n", i);
        printf("Titulos: %s %s %s %s %s \n", Temp->Dato->Titulo->Titulo1, Temp->Dato->Titulo->Titulo2, Temp->Dato->Titulo->Titulo3, Temp->Dato->Titulo->Titulo4,Temp->Dato->Titulo->Titulo5);
        printf("Autores: %s %s %s %s %s \n", Temp->Dato->Autor->Autor1, Temp->Dato->Autor->Autor2, Temp->Dato->Autor->Autor3, Temp->Dato->Autor->Autor4, Temp->Dato->Autor->Autor5);
        printf("Contribuyente: %s \n", Temp->Dato->Contibullentes);
        printf("Covertura: %s \n", Temp->Dato->Covertura);
        printf("Derechos: %s \n", Temp->Dato->Derechos);
        printf("Descripcion1: %s \n", Temp->Dato->Descripcion->Descripcion1);
        printf("Descripcion2: %s \n", Temp->Dato->Descripcion->Descripcion2);
        printf("Descripcion3: %s \n", Temp->Dato->Descripcion->Descripcion3);
        printf("Descripcion4: %s \n", Temp->Dato->Descripcion->Descripcion4);
        printf("Descripcion5: %s \n", Temp->Dato->Descripcion->Descripcion5);
        printf("Fecha: %s \n", Temp->Dato->Fecha);
        printf("Formato: %s \n", Temp->Dato->Formato);
        printf("Fuente: %s \n", Temp->Dato->Fuente);
        printf("Identificador: %d \n", Temp->Dato->Identificardor);
        printf("Lenguaje: %s \n", Temp->Dato->Lenguaje);
        printf("Palabra Clave: %s \n", Temp->Dato->PalabraClave);
        printf("Publicador: %s \n", Temp->Dato->Publicador);
        printf("Relacion: %s \n", Temp->Dato->Relacion);
        printf("Tipo: %s \n \n", Temp->Dato->Tipo);
        Temp=Temp->Siguiente;
        i++;
    }
}
//Devuelve un nodo dependiendo del indice
struct Nodo * Indice(struct ListaEnlazada *Lista, int indice){
    int i=0;
    struct Nodo *Temp;
    Temp=Lista->Raiz;
    while(i!=Lista->size){
        if(indice==i){
            break;
        }
        Temp=Temp->Siguiente;
        i++;
    }
    
   return Temp;
}
//Devuelce un puntero de char el cual almacena el nuevo string en memoria dinamica
char * Copiado(char  Arreglo []){
    
    int i=1;
    char *Puntero;
    char *Temp;
    while(Arreglo[i]!='\0'){
        i++;
    }
    i=0;
    Puntero = (char *) malloc (i);
    Temp=Puntero;
    while(Arreglo[i]!='\0'){
        *Temp=Arreglo[i];
        Temp++;
        i++;
    }
    *Temp='\0';
    
    return Puntero;
    
    
}


//Decuelve un puntero de tipo titulo que almacena un maximo de 5 titulos
struct Titulo * AgregarTitulos(){
    char strtitulo[50];
    struct Titulo *Titulos;
    Titulos = (struct Titulo *) malloc (sizeof(struct Titulo));
    char SN;
    int i=0;
    while(i!=5){
        printf("Titulo del archivo: ");
        scanf(" %s", strtitulo);
        switch(i){
            case 0: {Titulos->Titulo1=Copiado(strtitulo);
                     break;}
            case 1: {Titulos->Titulo2=Copiado(strtitulo);
                     break;}
            case 2: {Titulos->Titulo3=Copiado(strtitulo);
                     break;}
            case 3: {Titulos->Titulo4=Copiado(strtitulo);
                     break;}
            case 4: {Titulos->Titulo5=Copiado(strtitulo);
                     break;}
        }
        
        if(i==4){
            break;
        }
        
        printf("Desea agregar otro titulo S/N: ");
        scanf(" %c", &SN);
        if('N'==SN || 'n'==SN){
            break; 
        }
        i++;
    }
    return Titulos;
}

//Devuelve un puntero autor que almacena un maximo de 5 autores
struct Autor * AgregarAutores(){
    char str[50];
    struct Autor *Autores;
    Autores = (struct Autor *) malloc (sizeof(struct Autor));
    char SN;
    int i=0;
    while(i!=5){
        printf("Autor del archivo: ");
        scanf(" %s", str);
        
        switch(i){
            case 0: {Autores->Autor1=Copiado(str);
                     break;}
            case 1: {Autores->Autor2=Copiado(str);
                     break;}
            case 2: {Autores->Autor3=Copiado(str);
                     break;}
            case 3: {Autores->Autor4=Copiado(str);
                     break;}
            case 4: {Autores->Autor5=Copiado(str);
                     break;}
        }
        
        if(i==4){
            break;
        }
        
        printf("Desea agregar otro autor S/N: ");
        scanf(" %c", &SN);
        
        if('N'==SN || 'n'==SN){
            break; 
        }
        i++;
    }
    return Autores;
}
//Devuelve un puntero de tipo descripcion el cual tiene una capacidad maxima de 5 descripciones
struct Descripcion * AgregarDescipcion(){
    char str[200];
    struct Descripcion *Descripcion;
    Descripcion = (struct Descripcion *) malloc (sizeof(struct Descripcion));
    char SN;
    int i=0;
    while(i!=5){
        printf("Descripcion del archivo: ");
        scanf(" %s", str);
        
        switch(i){
            case 0: {Descripcion->Descripcion1=Copiado(str);
                     break;}
            case 1: {Descripcion->Descripcion2=Copiado(str);
                     break;}
            case 2: {Descripcion->Descripcion3=Copiado(str);
                     break;}
            case 3: {Descripcion->Descripcion4=Copiado(str);
                     break;}
            case 4: {Descripcion->Descripcion5=Copiado(str);
                     break;}
        }
        
        if(i==4){
            break;
        }
        
        printf("Desea agregar otra descripcion S/N: ");
        scanf(" %c", &SN);
        
        if('N'==SN || 'n'==SN){
            break; 
        }
        i++;
    }
    return Descripcion;
}
//Valida tres tipos de formatos de las fecha ingresada
char * ValidarFecha(){
    char str[15];
    printf("Fecha (Año-Mes-Dia): ");
    scanf(" %s", str);
    if(isdigit(str[0]) & isdigit(str[1]) & isdigit(str[2]) & isdigit(str[3]) & '\0'== str[4]){
        return Copiado(str);
    }
    if(isdigit(str[0]) & isdigit(str[1]) & isdigit(str[2]) & isdigit(str[3]) & '-'== str[4] & isdigit(str[5]) & isdigit(str[6]) & str[7]=='\0'){
        return Copiado(str);
    }
    
    if(isdigit(str[0]) & isdigit(str[1]) & isdigit(str[2]) & isdigit(str[3]) & isdigit(str[5]) & isdigit(str[6]) & isdigit(str[8]) & isdigit(str[9])){ 
    }
    else{
        printf("Por favor ingrese la fecha deacuerdo al formato ");
        ValidarFecha();
     
    }
    if(str[4]=='-' & str[7]=='-'){  
    }else{
        printf("Por favor ingrese la fecha deacuerdo al formato ");
        ValidarFecha();
    }
    return Copiado(str);
}
//Comprueba el indentificador automatico y manaul el cual es unico
int IdentificardorValidacion(struct ListaEnlazada *Lista){
    int i=0;
    struct Nodo *Temp;
    Temp=Lista->Raiz;
    int ID =Lista->size;
    while(i!=Lista->size){
        if(Temp->Dato->Identificardor==Lista->size){
            ID++;
            Temp=Lista->Raiz;
            i=0;
        }else{
            Temp=Temp->Siguiente;
            i++; 
        }
        
    }
    printf("Identificador numerico automatico %d : ", ID);
    printf("\n");
    printf("Desea cambiar el identificador S/N: ");
    char SN;
    scanf(" %c", &SN);
    if('S'==SN || 's'==SN){
        Salto:;
        int nu;
        printf("Identificador numerico manual: ");
        scanf(" %d", &nu);
        int i=0;
        struct Nodo *Temp;
        Temp=Lista->Raiz;
        
        while(i!=Lista->size){
            if(Temp->Dato->Identificardor==nu){
                printf("Este identificardor no esta disponible \n");
                goto Salto;
            }
            i++; 
        }
        return nu;
    }else{
        return ID;
    }
}

void LenguajeValidacion(){
    printf("Idioma preterminado: SPA\n");
    printf("Desea cambiar el idioma S/N: ");
    char SN;
    scanf(" %c", &SN);
    if('S'==SN || 's'==SN){
        
    }
}
//Funcion donde se pide todad la informacion del documento
void AgregarMetadatos(){
    char str[200];
    struct Documento *Documentos;
    Documentos = (struct Documento *) malloc (sizeof(struct Documento));
    Documentos->Titulo=AgregarTitulos();
    Documentos->Autor=AgregarAutores();
    Documentos->Descripcion=AgregarDescipcion();
    
    printf("Palabra clave: ");
    scanf(" %s", str);
    Documentos->PalabraClave=Copiado(str);
    
    Documentos->Fecha=ValidarFecha();
    Documentos->Identificardor=IdentificardorValidacion(&Lista);
    
    printf("Publicador: ");
    scanf(" %s", str);
    Documentos->Publicador=Copiado(str);
    
    printf("Contribullentes: ");
    scanf(" %s", str);
    Documentos->Contibullentes=Copiado(str);
    
    printf("Fuente: ");
    scanf(" %s", str);
    Documentos->Fuente=Copiado(str);
    
    printf("Relacion: ");
    scanf(" %s", str);
    Documentos->Relacion=Copiado(str);
    
    printf("Covertura: ");
    scanf(" %s", str);
    Documentos->Covertura=Copiado(str);
    
    printf("Derechos: ");
    scanf(" %s", str);
    Documentos->Derechos=Copiado(str);
    
    
    agregar(Documentos, &Lista);
    MenuP();
}
//Menu de las funcionalidades del programa
void Menu(){
    int numero;
    printf("\n"
            "Menu \n"
            "1. Agregar documento \n"
            "2. Consultar documento \n"
            "3. Buscar documento \n"
            "4. Exportar metadatos \n"
            "5. Recuperar archivos \n"
            "6. Salir \n"
            "Por favor ingrese el numero de la accion correspondiente: ");
    
    scanf("%d", &numero);
    printf("\n");
    switch(numero){
        case 1: {AgregarMetadatos();
                 break;}
        case 2: {
            imprimir(&Lista);
                 break;}
        case 3: {;
                 break;}
        case 4: {;
                 break;}
        case 5: {return;}
        
        case 6: {return;}
   }
}



//Funcion que ejecuta las otras funciones
int main() {
    MenuP=Menu;
    MenuP();
    
    return (EXIT_SUCCESS);
}



