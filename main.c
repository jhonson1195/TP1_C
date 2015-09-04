
/* 
 * File:   main.c
 * Author: jhonson
 *
 * Created on 22 de agosto de 2015, 03:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
#include <errno.h>




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
//Esto busca el ide dentro del documento y devuelve el nodo que coincide ya con esto nada maes accede a los datos
struct Documento * BuscarID(struct ListaEnlazada *Lista){
    int ID;
    Label:;
    printf("Identificador: ");
    scanf(" %d", &ID);
    int i=0;
    struct Nodo *Temp;
    Temp=Lista->Raiz;
    while(i!=Lista->size){
        if(Temp->Dato->Identificardor==ID){
            break;
        }
        Temp=Temp->Siguiente;
        i++;
    }
    if(i==Lista->size){
        printf("Identificardor no encontrado \n");
        goto Label;
    }
    return Temp->Dato;
    
}

//Imprime todos lo que contiene los nodos
void imprimir(){
    struct Documento *Docu=BuscarID(&Lista);
    printf("Nombre del archivo: %s\n" ,Docu->NombreArchivo);
    printf("Titulo: %s\n",Docu->Titulo->Titulo1 );
    if(Docu->Titulo->Titulo2!=NULL){
        printf("Titulo2: %s\n",Docu->Titulo->Titulo2 );  
    }
    if(Docu->Titulo->Titulo3!=NULL){
        printf("Titulo3: %s\n",Docu->Titulo->Titulo3 );  
    }
      if(Docu->Titulo->Titulo4!=NULL){
        printf("Titulo4: %s\n",Docu->Titulo->Titulo4 );  
    }
      if(Docu->Titulo->Titulo5!=NULL){
        printf("Titulo5: %s\n",Docu->Titulo->Titulo5 );  
    }
    
    printf("Autor: %s\n",Docu->Autor->Autor1 );
    if(Docu->Autor->Autor2!=NULL){
        printf("Autor2: %s\n",Docu->Autor->Autor2 );  
    }
    if(Docu->Autor->Autor3!=NULL){
        printf("Autor3: %s\n",Docu->Autor->Autor3 );  
    }
      if(Docu->Autor->Autor4!=NULL){
        printf("Autor4: %s\n",Docu->Autor->Autor4 );  
    }
      if(Docu->Autor->Autor5!=NULL){
        printf("Autor5: %s\n",Docu->Autor->Autor5 );  
    }
    
    printf("Descripcion: %s\n",Docu->Descripcion->Descripcion1 );
    if(Docu->Descripcion->Descripcion2!=NULL){
        printf("Descripcion2: %s\n",Docu->Descripcion->Descripcion2 );  
    }
    if(Docu->Descripcion->Descripcion3!=NULL){
        printf("Descripcion3: %s\n",Docu->Descripcion->Descripcion3 );  
    }
      if(Docu->Descripcion->Descripcion4!=NULL){
        printf("Descripcion4: %s\n",Docu->Descripcion->Descripcion4 );  
    }
      if(Docu->Descripcion->Descripcion5!=NULL){
        printf("Descripcion5: %s\n",Docu->Descripcion->Descripcion5 );  
    }
    if(Docu->Contibullentes!=NULL){printf("Contribuyente: %s \n", Docu->Contibullentes);}
    if(Docu->Covertura!=NULL){printf("Covertura: %s \n", Docu->Covertura);}
    if(Docu->Derechos!=NULL){printf("Derechos: %s \n", Docu->Derechos);}
    printf("Fecha: %s \n", Docu->Fecha);
    printf("Formato: %s \n", Docu->Formato);
    if(Docu->Fuente!=NULL){printf("Fuente: %s \n", Docu->Fuente);}
    printf("Identificador: %d \n", Docu->Identificardor);
    printf("Idioma: %s \n", Docu->Lenguaje);
    printf("Palabra Clave: %s \n", Docu->PalabraClave);
    if(Docu->Publicador!=NULL){printf("Publicador: %s \n", Docu->Publicador);}
    if(Docu->Relacion!=NULL){printf("Relacion: %s \n", Docu->Relacion);}
    printf("Tipo: %s \n \n", Docu->Tipo);
    MenuP();
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
    
    int i=0;
    char *Puntero;
    char *Temp;
    while(Arreglo[i]!='\0'){
        i++;
    }
    i++;
    
    Puntero = (char *) malloc (i);
    Temp=Puntero;
    i=0;
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
    char str[100];
    struct Titulo *Titulos;
    Titulos = (struct Titulo *) malloc (sizeof(struct Titulo));
    char SN;
    int i=0;
    while(i!=5){
        Labe:;
        printf("Titulo del archivo: ");
        scanf(" %s", str);
        if(  Titulos->Titulo1 !=NULL){
            if(!strcmp(Titulos->Titulo1, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
         if(  Titulos->Titulo2 !=NULL){
            if(!strcmp(Titulos->Titulo2, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        if(  Titulos->Titulo3 !=NULL){
            if(!strcmp(Titulos->Titulo3, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
         if(  Titulos->Titulo4 !=NULL){
            if(!strcmp(Titulos->Titulo4, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        if(  Titulos->Titulo5 !=NULL){
            if(!strcmp(Titulos->Titulo5, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        
        switch(i){
            case 0: {Titulos->Titulo1=Copiado(str);
                     break;}
            case 1: {Titulos->Titulo2=Copiado(str);
                     break;}
            case 2: {Titulos->Titulo3=Copiado(str);
                     break;}
            case 3: {Titulos->Titulo4=Copiado(str);
                     break;}
            case 4: {Titulos->Titulo5=Copiado(str);
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
        Labe:;
        printf("Autor del archivo: ");
        scanf(" %s", str);
        
        if(  Autores->Autor1 !=NULL){
            if(!strcmp(Autores->Autor1, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
         if(  Autores->Autor2 !=NULL){
            if(!strcmp(Autores->Autor2, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        if(  Autores->Autor3 !=NULL){
            if(!strcmp(Autores->Autor3, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
         if(  Autores->Autor4 !=NULL){
            if(!strcmp(Autores->Autor4, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        if(  Autores->Autor5 !=NULL){
            if(!strcmp(Autores->Autor5, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        
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
        Labe:;
        printf("Descripcion del archivo: ");
        scanf(" %s", str);
        
        if(  Descripcion->Descripcion1 !=NULL){
            if(!strcmp(Descripcion->Descripcion1, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
         if(  Descripcion->Descripcion2 !=NULL){
            if(!strcmp(Descripcion->Descripcion2, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        if(  Descripcion->Descripcion3 !=NULL){
            if(!strcmp(Descripcion->Descripcion3, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
         if(  Descripcion->Descripcion4 !=NULL){
            if(!strcmp(Descripcion->Descripcion4, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        if(  Descripcion->Descripcion5 !=NULL){
            if(!strcmp(Descripcion->Descripcion5, str)){
            printf("Dato duplicado ingrese de nuevo el dato \n");
            goto Labe;}
        }
        
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
    printf("Fecha: ");
    scanf(" %s", str);
    if(isdigit(str[0]) & isdigit(str[1]) & isdigit(str[2]) & isdigit(str[3]) & '\0'== str[4]){
        return Copiado(str);
    }
    if(isdigit(str[0]) & isdigit(str[1]) & isdigit(str[2]) & isdigit(str[3]) & '-'== str[4] & isdigit(str[5]) & isdigit(str[6]) & str[7]=='\0'){
        return Copiado(str);
    }
    
    if(isdigit(str[0]) & isdigit(str[1]) & isdigit(str[2]) & isdigit(str[3]) & str[4]=='-' & isdigit(str[5]) & isdigit(str[6]) & str[7]=='-' & isdigit(str[8]) & isdigit(str[9])){ 
        return Copiado(str);
    }
    else{
        printf("Por favor ingrese la fecha deacuerdo al formato ");
        ValidarFecha();
     
    }
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

char * LenguajeValidacion(){
    printf("Idioma preterminado: SPA\n");
    printf("Desea cambiar el idioma S/N: ");
    char SN;
    scanf(" %c", &SN);
    char IDO[10];
    if('S'==SN || 's'==SN){
        restric:;
        printf("Idioma: ");
        scanf(" %s", IDO);
        //Ingles
        if(!strncmp("ENG", IDO, 3)){
            return Copiado(IDO);
        }
        //Frances
        if(!strncmp("FRA", IDO, 3)){
            return Copiado(IDO);
        }
        //Italiano
        if(!strncmp("ITA", IDO, 3)){
            return Copiado(IDO);
        }
        //Coreano
        if(!strncmp("KOR", IDO, 3)){
            return Copiado(IDO);
        }
        //Latin
        if(!strncmp("LAT", IDO, 3)){
            return Copiado(IDO);
        }
        //Portugues
        if(!strncmp("POR", IDO, 3)){
            return Copiado(IDO);
        }
        //CHino
        if(!strncmp("ZHO", IDO, 3)){
            return Copiado(IDO);
        }
        
        printf("Formato invalido o idioma \n");
        goto restric;
        
        
    }
	return Copiado("SPA");
}

char * itoa(int n)
 {  
    char s[50];
    char *j;
     int i, sign;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     j=s;
     return Copiado(s);
}


char * obtenerPeso(struct Documento *Documentos){
    char ATemp[200]={""};
    FILE *fich;
    //"/home/jhonson/Escritorio/TP1.pdf"
    char *Temp;
    Temp=Documentos->Ruta;
    while(*Temp!='\0'){
        Temp++;
    }
    Temp-=3;
    
    fich=fopen(Documentos->Ruta,"r");
    fseek(fich, 0L, SEEK_END);
    strcat(ATemp, Temp);
    strcat(ATemp, "/");
    strcat(ATemp, itoa(ftell(fich)));
    strcat(ATemp, " bytes");
    fclose(fich);
    return Copiado(ATemp);
}

char Dato1 []={"info:eu-repo/semantics/bacherlorThesis"};
char Dato2 []={"info:eu-repo/semantics/masterThesis"};
char Dato3 []={"info:eu-repo/semantics/doctoralThesis"};
char Dato4 []={"info:eu-repo/semantics/article"};
char Dato5 []={"info:eu-repo/semantics/report"};
char Dato6 []={"info:eu-repo/semantics/book"};
char Dato7 []={"info:eu-repo/semantics/bookPart"};
char Dato8 []={"info:eu-repo/semantics/review"};
char Dato9 []={"info:eu-repo/semantics/conferenceObject"};
char Dato10 []={"info:eu-repo/semantics/lectura"};
char Dato11[]={"info:eu-repo/semantics/workingPaper"};
char Dato12[]={"info:eu-repo/semantics/preprint"};
char Dato13[]={"info:eu-repo/semantics/contributionToPeriodical"};
char Dato14[]={"info:eu-repo/semantics/patent"};
char Dato15[]={"info:eu-repo/semantics/other"};

struct Documento * Tipo(struct Documento *Docu){
    printf("Tipo de documento:  ");
    printf("1. %s\n"
            "2. %s\n"
            "3. %s\n"
            "4. %s\n"
            "5. %s\n"
            "6. %s\n"
            "7. %s\n"
            "8. %s\n"
            "9. %s\n"
            "10. %s\n"
            "11. %s\n"
            "12. %s\n"
            "13. %s\n"
            "14. %s\n"
            "15. %s\n", Dato1, Dato2, Dato3, Dato4, Dato5, Dato6, Dato7, Dato8, Dato9, Dato10, Dato11, Dato12, Dato13, Dato14, Dato15);
    int numero;
    printf("Seleccione una opcion: ");
    scanf("%d", &numero);
    printf("\n");
    switch(numero){
        case 1: {Docu->Tipo=Copiado(Dato1);
                 break;}
        case 2: {Docu->Tipo=Copiado(Dato2);
                 break;}
        case 3: {Docu->Tipo=Copiado(Dato3);
                 break;}
        case 4: {Docu->Tipo=Copiado(Dato4);
                 break;}
        case 5: {Docu->Tipo=Copiado(Dato5);
                 break;}
        case 6: {Docu->Tipo=Copiado(Dato6);
                 break;}
        case 7: {Docu->Tipo=Copiado(Dato7);
                 break;}
        case 8: {Docu->Tipo=Copiado(Dato8);
                 break;}
        case 9: {Docu->Tipo=Copiado(Dato9);
                 break;}
        case 10: {Docu->Tipo=Copiado(Dato10);
                 break;}
        case 11: {Docu->Tipo=Copiado(Dato11);
                  break;}
        case 12: {Docu->Tipo=Copiado(Dato12);
                  break;}
        case 13: {Docu->Tipo=Copiado(Dato13);
                 break;}
        case 14: {Docu->Tipo=Copiado(Dato14);
                 break;}
        case 15: {Docu->Tipo=Copiado(Dato15);
                 break;}
   } 
}

char cwd[300];

void DirectorioActual(){
   getcwd(cwd, sizeof(cwd));
}

int ContarArreglo(char arreglo[]){
    int i=0;
    for(i; arreglo[i]!='\0'; i++){}
    return i;
}
char *  ExtraerNombre(char arreglo []){
    int i=ContarArreglo(arreglo)-1;
    while(arreglo[i]!='/'){
        i--;
    }
    i++;
    return Copiado(&arreglo[i]);
}

void CopiarArchivo(char RutaRaiz[]){
    char strTemp[200]={""};
    strcat(strTemp, "cp ");
    strcat(strTemp, RutaRaiz);
    strcat(strTemp, " ");
    strcat(strTemp, cwd);
    strcat(strTemp, "/Repositorio");
    system(strTemp);
}

char * NuevaRuta(char str[]){
    char strTemp[200]={""};
    strcat(strTemp, cwd);
    strcat(strTemp, "/Repositorio/");
    strcat(strTemp, ExtraerNombre(str));
    return Copiado(strTemp);
}


//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************
//**************************************************************


void recuperarArchivos(){
    char pdf1[200] = "pdftk ";
    char pdf2[200] = " cat output /tmp/salida.pdf";
    char direccion[200]="";
    char espacio[10]=" ";
    strcat(direccion,pdf1);
    struct Documento *informacion= BuscarID(&Lista);
    strcat(direccion,informacion->Ruta);

    int conta=1;
    while(conta){
        printf("Desea recuperar otro documento S/N: ");
        char SN;
        scanf(" %c", &SN);
        if('S'==SN || 's'==SN){
            informacion= BuscarID(&Lista);
            strcat(direccion,espacio);
            strcat(direccion,informacion->Ruta);
    }else{
        conta=0;
    }
}
    strcat(direccion,pdf2);

    printf("%s\n",direccion );
    system (direccion);
    printf("Se ejecuto system ");
MenuP();
}

//Funcion donde se pide toda la informacion del documento
void AgregarMetadatos(){
    ///home/jhonson/Escritorio/TP1.pdf
    char str[200]; 
    struct Documento *Documentos;
    Documentos = (struct Documento *) malloc (sizeof(struct Documento));
    
    printf("Ruta del documento: ");
    scanf(" %s", str);
    CopiarArchivo(str);
    Documentos->NombreArchivo=ExtraerNombre(str);
    Documentos->Ruta=NuevaRuta(str);
    Documentos->Titulo=AgregarTitulos();
    Documentos->Autor=AgregarAutores();
    Documentos->Descripcion=AgregarDescipcion();
    
    printf("Palabra clave: ");
    scanf(" %s", str);
    Documentos->PalabraClave=Copiado(str);
    
    Documentos->Fecha=ValidarFecha();
    Documentos->Identificardor=IdentificardorValidacion(&Lista);
    
    
    
    printf("Publicador: ");
    gets(str);
    gets(str);
    if(0!=str[0]){
        Documentos->Publicador=Copiado(str);
    }
    printf("Contribullentes: ");
    gets(str);
    if(0!=str[0]){
        Documentos->Contibullentes=Copiado(str);
    }
    
    printf("Fuente: ");
    gets(str);
    if(0!=str[0]){
        Documentos->Fuente=Copiado(str);
    }
    printf("Relacion: ");
    gets(str);
    if(0!=str[0]){
        Documentos->Relacion=Copiado(str);
    }
    
    printf("Covertura: ");
    gets(str);
    if(0!=str[0]){
        Documentos->Covertura=Copiado(str);
    }
    
    printf("Derechos: ");
    gets(str);
    if(0!=str[0]){
        Documentos->Derechos=Copiado(str);
    }
    
    Documentos->Lenguaje=LenguajeValidacion();
    
    printf("Formato: %s \n", obtenerPeso(Documentos));
    char SN;
    printf("Desea cambiar el formato S/N: ");
    scanf(" %c", &SN);
    if('S'==SN || 's'==SN){
        printf("Formato: ");
        scanf(" %s", str);
        Documentos->Formato=Copiado(str);
        
    }else{
        Documentos->Formato=obtenerPeso(Documentos);
    }
  
    Tipo(Documentos);
    
    agregar(Documentos, &Lista);
    MenuP();
}






void creaXML(){
    ///home/jhonson/Escritorio/TP1.pdf
    struct Documento *informacion= BuscarID(&Lista);
    char Union[100]={"/tmp/"};
    strcat(Union, itoa(informacion->Identificardor));
    strcat(Union, ".xml");
    printf("%s", Union );
    
    FILE *fb=fopen(Union ,"w");
    fprintf ( fb,"<?xml version=\"1.0\" encoding=\"utf-8\"?> \n");
	fprintf ( fb,"<data>\n");
	fprintf (fb, "<oai_dc:dc>\n");
	fprintf ( fb,"<dc:title> %s </dc:title>\n",informacion->Titulo->Titulo1);
        
	if(informacion->Titulo->Titulo2!=NULL){
        	fprintf(fb,"<dc:title> %s </dc:title>\n",informacion->Titulo->Titulo2 );  
    	}
        
    	if(informacion->Titulo->Titulo3!=NULL){
        	fprintf(fb,"<dc:title> %s </dc:title>\n",informacion->Titulo->Titulo3 );  
    	}
      	if(informacion->Titulo->Titulo4!=NULL){
        	fprintf(fb,"<dc:title> %s </dc:title>\n",informacion->Titulo->Titulo4 );  
    	}
      	if(informacion->Titulo->Titulo5!=NULL){
        	fprintf(fb,"<dc:title> %s </dc:title>\n",informacion->Titulo->Titulo5 );  
    	}
	fprintf ( fb,"<dc:creator> %s </dc:creator>\n",informacion->Autor->Autor1);
	if(informacion->Autor->Autor2!=NULL){
        	fprintf(fb,"<dc:creator> %s </dc:creator>\n",informacion->Autor->Autor2 );  
    	}
    	if(informacion->Autor->Autor3!=NULL){
        	fprintf(fb,"<dc:creator> %s </dc:creator>\n",informacion->Autor->Autor3 );  
    	}
      	if(informacion->Autor->Autor4!=NULL){
        	fprintf(fb,"<dc:creator> %s </dc:creator>\n",informacion->Autor->Autor4 );  
    	}
      	if(informacion->Autor->Autor5!=NULL){
        	fprintf(fb,"<dc:creator> %s </dc:creator>\n",informacion->Autor->Autor5 );  
    	}
	fprintf ( fb,"<dc:subject> %s </dc:subject>\n",informacion->PalabraClave);
	fprintf ( fb,"<dc:description> %s </dc:description>\n",informacion->Descripcion->Descripcion1);
	if(informacion->Descripcion->Descripcion2!=NULL){
        	fprintf(fb,"<dc:description> %s </dc:description>\n",informacion->Descripcion->Descripcion2 );  
    	}
    	if(informacion->Descripcion->Descripcion3!=NULL){
        	fprintf(fb,"<dc:description> %s </dc:description>\n",informacion->Descripcion->Descripcion3 );  
    	}
      	if(informacion->Descripcion->Descripcion4!=NULL){
        	fprintf(fb,"<dc:description> %s </dc:description>\n",informacion->Descripcion->Descripcion4 );  
    	}
      	if(informacion->Descripcion->Descripcion5!=NULL){
        	fprintf(fb,"<dc:description> %s </dc:description>\n",informacion->Descripcion->Descripcion5 );  
    	}
	fprintf ( fb,"<dc:date> %s </dc:date>\n",informacion->Fecha);
	fprintf ( fb,"<dc:type> %s </dc:type>\n",informacion->Tipo);
        fprintf ( fb,"<dc:format> %s </dc:format>\n",informacion->Formato);
	fprintf ( fb,"<dc:identifier> %d </dc:identifier>\n",informacion->Identificardor);
	fprintf ( fb,"<dc:language> %s </dc:language>\n",informacion->Lenguaje);
	fprintf ( fb,"<dc:publisher> %s </dc:publisher>\n",informacion->Publicador);
        fprintf ( fb,"<dc:contributor> %s </dc:contributor>\n",informacion->Contibullentes);
        fprintf ( fb,"<dc:font> %s </dc:font>\n",informacion->Fuente);
        fprintf ( fb,"<dc:relationship> %s </dc:relationship>\n",informacion->Relacion);
        fprintf ( fb,"<dc:coverage> %s </dc:coverage>\n",informacion->Covertura);
        fprintf ( fb,"<dc:rights> %s </dc:rights>\n",informacion->Derechos);
        fprintf ( fb,"<dc:route> %s </dc:route>\n",informacion->Ruta);
        fprintf ( fb,"<dc:File_name> %s </dc:file_name>\n",informacion->NombreArchivo);
        fprintf (fb, "</oai_dc:dc>\n");
        
	fprintf ( fb,"</data>\n");
        fclose(fb);
        MenuP();
}

void guardarDatos(struct ListaEnlazada *Lista){
    ///home/jhonson/Escritorio/TP1.pdf
    FILE *fb=fopen("Repositorio/Metadatos.txt" ,"w");
    int i=0;
    struct Nodo *Temp;
    Temp=Lista->Raiz;
    while(i!=Lista->size){
        fprintf ( fb,"%s\n", Temp->Dato->Autor->Autor1);
        fprintf ( fb,"%s\n", Temp->Dato->Autor->Autor2);
        fprintf ( fb,"%s\n", Temp->Dato->Autor->Autor3);
        fprintf ( fb,"%s\n", Temp->Dato->Autor->Autor4);
        fprintf ( fb,"%s\n", Temp->Dato->Autor->Autor5);
        fprintf ( fb,"%s\n", Temp->Dato->Descripcion->Descripcion1);
        fprintf ( fb,"%s\n", Temp->Dato->Descripcion->Descripcion2);
        fprintf ( fb,"%s\n", Temp->Dato->Descripcion->Descripcion3);
        fprintf ( fb,"%s\n", Temp->Dato->Descripcion->Descripcion4);
        fprintf ( fb,"%s\n", Temp->Dato->Descripcion->Descripcion5);
        fprintf ( fb,"%s\n", Temp->Dato->Titulo->Titulo1);
        fprintf ( fb,"%s\n", Temp->Dato->Titulo->Titulo2);
        fprintf ( fb,"%s\n", Temp->Dato->Titulo->Titulo3);
        fprintf ( fb,"%s\n", Temp->Dato->Titulo->Titulo4);
        fprintf ( fb,"%s\n", Temp->Dato->Titulo->Titulo5);
        fprintf ( fb,"%s\n", Temp->Dato->Contibullentes);
        fprintf ( fb,"%s\n", Temp->Dato->Covertura);
        fprintf ( fb,"%s\n", Temp->Dato->Derechos);
        fprintf ( fb,"%s\n", Temp->Dato->Fecha);
        fprintf ( fb,"%s\n", Temp->Dato->Formato);
        fprintf ( fb,"%s\n", Temp->Dato->Fuente);
        fprintf ( fb,"%d\n", Temp->Dato->Identificardor);
        fprintf ( fb,"%s\n", Temp->Dato->Lenguaje);
        fprintf ( fb,"%s\n", Temp->Dato->NombreArchivo);
        fprintf ( fb,"%s\n", Temp->Dato->PalabraClave);
     
        fprintf ( fb,"%s\n", Temp->Dato->Publicador);
        fprintf ( fb,"%s\n", Temp->Dato->Relacion);
        fprintf ( fb,"%s\n", Temp->Dato->Ruta);
        fprintf ( fb,"%s\n", Temp->Dato->Tipo);
        Temp=Temp->Siguiente;
        i++;
    }
    fclose(fb);
}

char * crearString(char *Inicio, int CantidadChar){
    char *Puntero;
    char *Temp;
    CantidadChar++;
    Puntero = (char *) malloc (CantidadChar);
    Temp=Puntero;
    char indice=0;
    for(indice; indice<CantidadChar; indice++){
        *Temp=*Inicio;
        Temp++;
        Inicio++;
    }
    *Temp='\0';
    return Puntero;
}
int comparar(char *str2){
    char *str1="(null)";
    while(*str1!='\0'){
        if(*str1==*str2){
            str1++;
            str2++; 
        }else{
            break;
        }
    }
    if(*str1==*str2){
        return 1;
    }else{
        return 0;
    }
    
}

void agregarInfoDocumento(struct Documento *Documento, int Linea, char *STRING){
    switch(Linea){
        case 0: {
            Documento->Autor->Autor1=STRING;
            break;}
        case 1: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Autor->Autor2=STRING;
            }
            else{
                Documento->Autor->Autor2=NULL;
            }
            break;}
        case 2: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Autor->Autor3=STRING;
            }
            else{
               Documento->Autor->Autor3=NULL;
            }
            break;}
        case 3: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Autor->Autor4=STRING;
            }
            else{
                Documento->Autor->Autor4=NULL;
            }
            break;}
        case 4: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Autor->Autor5=STRING;
            }
            else{
                Documento->Autor->Autor5=NULL;
            }
            break;}
        case 5: {
            Documento->Descripcion->Descripcion1=STRING;
            break;}
        case 6: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Descripcion->Descripcion2=STRING;
            }
            else{
                Documento->Descripcion->Descripcion2=NULL;
            }
            break;}
        case 7: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Descripcion->Descripcion3=STRING;
            }
            else{
                Documento->Descripcion->Descripcion3=NULL;
            }
            break;}
        case 8: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Descripcion->Descripcion4=STRING;
            }
            else{
                Documento->Descripcion->Descripcion4=NULL;
            }
            break;}
        case 9: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Descripcion->Descripcion5=STRING;
            }
            else{
                Documento->Descripcion->Descripcion5=NULL;
            }
            break;}
        case 10: {
            Documento->Titulo->Titulo1=STRING;
            break;}
        case 11: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Titulo->Titulo2=STRING;
            }
            else{
                Documento->Titulo->Titulo2=NULL; 
            }
            break;}
        case 12: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Titulo->Titulo3=STRING;
            }
            else{
                Documento->Titulo->Titulo3=NULL;
            }
            break;}
        case 13: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Titulo->Titulo4=STRING;
            }
            else{
                Documento->Titulo->Titulo4=NULL;
            }
            break;}
        case 14: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Titulo->Titulo5=STRING;
            }
            else{
                Documento->Titulo->Titulo5=NULL;
            }
            break;}
        case 15: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Contibullentes=STRING;
            }
            else{
                Documento->Contibullentes=NULL;
            }
            break;
        }
        case 16: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Covertura=STRING;
            }
            else{
                Documento->Covertura=NULL;
            }
            break;
        }
        case 17: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Derechos=STRING;
            }
            else{
                Documento->Derechos=NULL;
            }
            break;
        }
        case 18: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Fecha=STRING;
            }
            else{
                Documento->Fecha=NULL;
            }
            break;
        }
        case 19: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Formato=STRING;
            }
            else{
                Documento->Formato=NULL;
            }
            break;
        }
        case 20: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Fuente=STRING;
            }
            else{
                Documento->Fuente=NULL;
            }
            break;
        }
        case 21: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Identificardor=atoi(STRING);
            }
            break;
        }
        case 22: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Lenguaje=STRING;
            }
            else{
                Documento->Lenguaje=NULL;
            }
            break;
        }
        case 23: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->NombreArchivo=STRING;
            }
            else{
                Documento->NombreArchivo=NULL;
            }
            break;
        }
        case 24: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->PalabraClave=STRING;
            }
            else{
                Documento->PalabraClave=NULL;
            }
            break;
        }
        case 25: {
            if((*STRING!='('& *(STRING+1)!='n')){
                
                Documento->Publicador=STRING;
            }
            else{
                
                Documento->Publicador=NULL;
            }
            break;
        }
        case 26: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Relacion=STRING;
            }
            else{
                Documento->Relacion=NULL;
            }
            break;
        }
        case 27: {
            if(*STRING!='('& *(STRING+1)!='n' & *(STRING+2)!='u' & *(STRING+3)!='l'){
                Documento->Ruta=STRING;
            }
            else{
                Documento->Ruta=NULL;
            }
            break;
        } 
    }
    
}

void cargarDatos(){
    FILE *leeido;
    char caracter;
    int i=1;
    int g=0;
    
    leeido = fopen ("Repositorio/Metadatos.txt", "r" );
    if (leeido==NULL){return;}
    while (feof(leeido) == 0){
        caracter = fgetc(leeido);
        if(caracter=='\n'){
            g++;
        }
        i++;
    }
    fclose(leeido);
    char *Puntero;
    char *Temp;
    Puntero = (char *) malloc (i);
    Temp=Puntero;
    leeido = fopen ("Repositorio/Metadatos.txt" , "r");
    while (feof(leeido) == 0){
        caracter = fgetc(leeido);
        *Temp=caracter;
        Temp++;
    }
    
    *Temp='\0';
    fclose(leeido);
    
    char *Inicio;
    char *Final;
    Inicio=Puntero;
    Final=Puntero;
    i=0;
    
    struct Titulo *Titulos;
    struct Documento *Documentos;
    struct Descripcion *Descripcion;
    struct Autor *Autores;
    Documentos = (struct Documento *) malloc (sizeof(struct Documento));
    Titulos = (struct Titulo *) malloc (sizeof(struct Titulo));
    Descripcion = (struct Descripcion *) malloc (sizeof(struct Descripcion));
    Autores = (struct Autor *) malloc (sizeof(struct Autor));
    Documentos->Titulo=Titulos;
    Documentos->Descripcion=Descripcion;
    Documentos->Autor=Autores;
    
    
    
    
    
    int conta=0;
    while(*Final!='\0'){
        if(*Final!='\n'){
            Final++;
            i++;
        }
        else{
            if(conta==28){
                Documentos->Tipo= crearString(Inicio, i-1);
                agregar(Documentos, &Lista);
                conta=0;
                Documentos = (struct Documento *) malloc (sizeof(struct Documento));
                Titulos = (struct Titulo *) malloc (sizeof(struct Titulo));
                Descripcion = (struct Descripcion *) malloc (sizeof(struct Descripcion));
                Autores = (struct Autor *) malloc (sizeof(struct Autor));
                Documentos->Titulo=Titulos;
                Documentos->Descripcion=Descripcion;
                Documentos->Autor=Autores;
                
                i=0;
                Final++;
                Inicio=Final;
                conta=0;
            }else{
          
                
                agregarInfoDocumento(Documentos, conta, crearString(Inicio, i-1));
                i=0;
                Final++;
                Inicio=Final;
                conta++;
                
            }

         }
    }  
}


int  Comparacion(char *STR1, char *STR2){

    int Bandera=1;
    char *TEMP;
    char *TEMP2;
    int cantidadCompa;
    int cantidadstr;
    
    
    while(Bandera){
        TEMP=STR1;
        cantidadstr=0;
        while(*TEMP!='\0'){
            
            if(*TEMP==' '){
                break;
            }
            cantidadstr++;
            TEMP++;
        }
        if(*TEMP=='\0'){
            Bandera=0;
        }
        TEMP=STR1;
        TEMP2=STR2;
        cantidadCompa=0;
        
        while(*TEMP2!='\0'){
            if(*TEMP2==*TEMP){
                cantidadCompa++;
                TEMP++;
                if(cantidadCompa==cantidadstr){
                    return 1;
                }
            }else{
                TEMP=STR1;
                cantidadCompa=0;
            }
            TEMP2++; 
        }
        TEMP2=STR2;
        STR1=STR1+cantidadstr+1;
    }
    return 0;
}

struct Resultados{
    char *Resu;
    int Identi;
};



void BuscarTitulo(char *str){
    struct Resultados ResulratdosBusqueda [Lista.size];
    int i=0;
    int indece=0;
    struct Nodo *Temp;
    Temp=Lista.Raiz;
    while(i!=Lista.size){
        //Comparacion(str, Temp->Dato->Titulo->Titulo1);
        if(Comparacion(str, Temp->Dato->Titulo->Titulo1)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Titulo->Titulo1;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }
        if(Temp->Dato->Titulo->Titulo2!=NULL){
        if(Comparacion(str, Temp->Dato->Titulo->Titulo2)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Titulo->Titulo2;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        if(Temp->Dato->Titulo->Titulo3!=NULL){
        if(Comparacion(str, Temp->Dato->Titulo->Titulo3)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Titulo->Titulo3;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        if(Temp->Dato->Titulo->Titulo4!=NULL){
        if(Comparacion(str, Temp->Dato->Titulo->Titulo4)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Titulo->Titulo4;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        if(Temp->Dato->Titulo->Titulo5!=NULL){
        if(Comparacion(str, Temp->Dato->Titulo->Titulo5)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Titulo->Titulo5;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        Temp=Temp->Siguiente;
        i++;
    }
    if(indece){
        int j=0;
        for(j;j<indece; j++){
            printf("ID:%d Resultado: %s \n", ResulratdosBusqueda[j].Identi, ResulratdosBusqueda[j].Resu);
        }
    }else{
        printf("Dato no encontrado \n");
        MenuP();
        }
    imprimir();
    }

void BuscarAutor(char *str){
    struct Resultados ResulratdosBusqueda [Lista.size];
    int i=0;
    int indece=0;
    struct Nodo *Temp;
    Temp=Lista.Raiz;
    while(i!=Lista.size){
        //Comparacion(str, Temp->Dato->Titulo->Titulo1);
        if(Comparacion(str, Temp->Dato->Autor->Autor1)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Autor->Autor1;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }
        if(Temp->Dato->Autor->Autor2!=NULL){
        if(Comparacion(str, Temp->Dato->Autor->Autor2)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Autor->Autor2;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        if(Temp->Dato->Autor->Autor3!=NULL){
        if(Comparacion(str, Temp->Dato->Autor->Autor3)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Autor->Autor3;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        if(Temp->Dato->Autor->Autor4!=NULL){
        if(Comparacion(str, Temp->Dato->Autor->Autor4)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Autor->Autor4;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        if(Temp->Dato->Autor->Autor5!=NULL){
        if(Comparacion(str, Temp->Dato->Autor->Autor5)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->Autor->Autor5;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        Temp=Temp->Siguiente;
        i++;
    }
    if(indece){
        int j=0;
        for(j;j<indece; j++){
            printf("ID:%d Resultado: %s \n", ResulratdosBusqueda[j].Identi, ResulratdosBusqueda[j].Resu);
        }
    }else{
        printf("Dato no encontrado \n");
        MenuP();
        }
    imprimir();
    }

void BuscarPalabraClave(char *str){
    struct Resultados ResulratdosBusqueda [Lista.size];
    int i=0;
    int indece=0;
    struct Nodo *Temp;
    Temp=Lista.Raiz;
    while(i!=Lista.size){
        //Comparacion(str, Temp->Dato->Titulo->Titulo1);
        if(Temp->Dato->PalabraClave!=NULL){
        if(Comparacion(str, Temp->Dato->PalabraClave)){
            ResulratdosBusqueda[indece].Resu=Temp->Dato->PalabraClave;
            ResulratdosBusqueda[indece].Identi=Temp->Dato->Identificardor;
            indece++;
        }}
        Temp=Temp->Siguiente;
        i++;
    }
    if(indece){
        int j=0;
        for(j;j<indece; j++){
            printf("ID:%d Resultado: %s \n", ResulratdosBusqueda[j].Identi, ResulratdosBusqueda[j].Resu);
        }
    }else{
        printf("Dato no encontrado \n");
        MenuP();
        }
    imprimir();
    }



void BuscarDocumento(){
    ///home/jhonson/Escritorio/TP1.pdf
    
    
    char str[50];
    int selec;
    printf(
            "1.Titulo\n"
            "2.Autor\n"
            "3.Palabra clave\n"
            "Seleccione un modo de busqueda: ");
    scanf(" %d", &selec);
    printf("Ingrese el dato a buscar: ");
    gets(str);
    gets(str);
    switch(selec){
        
        case 1: {BuscarTitulo(&str[0]);
                 break;}
        case 2: {BuscarAutor(&str[0]);
            break;}
                 
        case 3: {BuscarPalabraClave(&str[0]);
                 break;}
    
        }
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
        case 2: {imprimir(&Lista);
                 break;}
        case 3: {BuscarDocumento();
                 break;}
        case 4: {creaXML();
                 break;}
        case 5: {recuperarArchivos();
                break;}
        
        case 6: {guardarDatos(&Lista);
            
            return;}
   }
}



//Funcion que ejecuta las otras funciones
int main() {
    DirectorioActual();
    system("mkdir Repositorio");
    cargarDatos();
    //Guarda en un arreglo el directorio actual donde se ejecuta c
   
    MenuP=Menu;
    MenuP();
    
    return (EXIT_SUCCESS);
}





