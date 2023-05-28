// TRABAJO INFORMÁTICA
/*
	Integrantes:
	David Cano Pérez
	Gonzalo Morcillo Garcia
	Jose Eduardo Arauz Yllanez
	Álvaro Cuesta Sanz
*/

#include <stdio.h>
#include<string.h>
#include<math.h>
#define C 5
#define N 2

//ESTRUCTURAS

/*Estructuras David*/
/*Estructura para NOMBRE APELLIDO1 APELLIDO2*/
typedef struct denominacion
{
	char nombre[20];
	char primer_apellido[20];
	char segundo_apellido[20];
}denominacion;

/*Estructura DNI*/
typedef struct dni
{
	int parte_numerica;
	char letra;
}dni;

/*Estructura para FECHA DE NACIMIENTO*/
typedef struct nacimiento
{
	int ano;
	int mes;
	int dia;
}nacimiento;

/*Estructura CORREO ELECTRONICO*/
typedef struct ce
{
	char correo[50];
	char contrasena[50];
}ce;

/*Estructuras dentro de Estructura CREAR CUENTA*/
typedef struct crear_cuenta
{
	denominacion usuario;
	dni persona;
	nacimiento fecha;
	ce CCPersona;
	char provincia[50];
	char cp[C];
}crear_cuenta;

/*Estructuras dentro de Estructura INICIAR SESION*/
typedef struct iniciar_sesion
{
	ce ISpersona;
}iniciar_sesion;


/*Estructuras Gonzalo*/
/*Estructura para los Tipos de Datos a Analizar*/
typedef struct 
{
    int hidraulica [N];
    int eolica [N];
    int solar_fotovoltaica [N];
    int solar_termica [N];
    int otras_renovables [N];
    int residuos_renovables [N];
    int Generacion_Renovable [N];
    int turbinacion_bombeo [N];
    int nuclear [N];
    int ciclo_combinado [N];
    int carbon [N];
    int cogeneracion [N];
    int residuos_no_renovables [N];
    int Generacion_No_Renovable [N];
    int consumos_en_bombeo [N];
    int enlace_peninsula_baleares [N];
    int saldo_intercambios_internacionales [N];
    int Demanda [N];
} datos_mes;


/*Estructuras Eduardo*/
/*Estructuras para guardar datos de ficheros y leer los ficheros*/
typedef struct
{
	char nombre[30];
	double datos[100];
}energias;
					
typedef struct
{
	float datos[100];
}prediccion;
					
typedef struct
{
	char lector0_e[5000];
}lectores_e;



//FUNCIONES

/*Funciones David*/
/*Crear Cuenta*/
int CrearCuenta();
/*Iniciar Sesion*/
int IniciarSesion();
/*Cambio de minusculas a Mayusculas*/
void cambio_mayusculas(char nombre[], char apellido1[],  char apellido2[]);
/*Menu*/
int menu();
/*INFORMACION*/
int informacion();

/*Funciones Gonzalo*/
/*Funcion Comparacion*/
void f_comparacion ();
void f_comparacion_menu (char *eleccion_comparacion);
/*Funcion Eleccion del Mes en la Parte de Comparacion Mensual*/ 
int f_comparacion_eleccion_mes (int eleccion_mes_int);
/*Funcion para Abrir y Cerrar los Ficheros donde se encuentran los datos de cada mes*/
void f_comparacion_ficheros (int anio_mes_void, int mes_void, int *hidraulica_0, int *hidraulica_1, int *eolica_0, int *eolica_1, int *solar_fotovoltaica_0, int *solar_fotovoltaica_1, int *solar_termica_0, int *solar_termica_1, int *otras_renovables_0, int *otras_renovables_1, int *residuos_renovables_0, int *residuos_renovables_1, int *Generacion_Renovable_0, int *Generacion_Renovable_1, int *turbinacion_bombeo_0, int *turbinacion_bombeo_1, int *nuclear_0, int *nuclear_1, int *ciclo_combinado_0, int *ciclo_combinado_1, int *carbon_0, int *carbon_1, int *cogeneracion_0, int *cogeneracion_1, int *residuos_no_renovables_0, int *residuos_no_renovables_1, int *Generacion_No_Renovable_0, int *Generacion_No_Renovable_1, int *consumos_en_bombeo_0, int *consumos_en_bombeo_1, int *enlace_peninsula_baleares_0, int *enlace_peninsula_baleares_1, int *saldo_intercambios_internacionales_0, int *saldo_intercambios_internacionales_1, int *Demanda_0, int *Demanda_1);

/*Funciones Eduardo*/
/*Funcion para predicciones*/
void predicciones();


//COMIENZO CON EL CREAR CUENTA O INICIO DE SESION
int main()
{
	printf("%cBIENVENIDO A TEAM SANGRE%c\n", 126, 126);
	
	/*Selecion de Crear Cuenta o Inicio de Sesion*/
	
	int seleccion;
	int i = 1;
	do
	{
		printf("\n1.-CREAR CUENTA");
		printf("\n2.-INICIAR SESION");
		printf("\nSeleccion (1 | 2): ");
		scanf("%i", &seleccion);
		
		if((seleccion < 1) || (seleccion > 2))
		{
			printf("\nERROR; la seleccion no es valida\n");
		}
		
		/*Si el usuario no pulsa lo exigido en tres intento se cierra*/
		i++;
		if(i > 3) 
		{
			return -1;
		}
		
	}
	while((seleccion < 1) || (seleccion > 2));
	
	int comprobacion_error = 0;
	
	//CREAR CUENTA
	/*Si el usuario seleccion 1(CREAR CUENTA)*/
	
	if(seleccion == 1)
	{
		/*Si en la funcion salta un return -1, en el main también se hace el return -1*/
		comprobacion_error = CrearCuenta();
		if(comprobacion_error == -1)
		{
			return -1;
		}
		
	}
	
	
	//INICIAR SESIï¿½N
	/*Si el usuario selecciona 2(INICIAR SESIï¿½N)*/
	
	if(seleccion == 2)
	{
		/*Si en la función salta un return -1, en el main también se hace el return -1*/
		comprobacion_error = IniciarSesion();
		if(comprobacion_error == -1)
		{
			return -1;
		}
		
		
	}
	return 0;
}


//FUNCIONES

/*Función Crear Cuenta*/

int CrearCuenta()
{
	/*Creamos las variables que utilizaremos en esta parte*/
	crear_cuenta CCusuario;
	int i, j, k;
	printf("\n\n\n\nCREAR CUENTA");
		
	/*Creamos y abrimos el fichero donde vamos a guardar los datos del usuario*/
	FILE *pf;
	pf = fopen("Ficheros/Crear_Cuenta.txt", "a");
	if(pf == NULL)
	{
		printf("ERROR; no he encontrado el archivo");
		return -1;
	}
	else
	{
		/*Creamos y abrimos el fichero donde solo se va a guardar los correos de los usuarios*/
		FILE *pf1;
		pf1 = fopen("Ficheros/Crear_Cuenta_Correo.txt", "a");
			
		if(pf1 == NULL)
		{
			printf("ERROR; no he encontrado el archivo");
			return -1;
		}
		else
		{
			/*Abrimos el fichero(sólo lectura) donde almacenamos los correos de los usurios, aquí comprobaremos con el correo introducido
			si el usuario ya tiene una cuenta creada con ese mismo correo, en caso afirmativo le advetimos que ya tiene una cuenta creada con ese correo*/
			FILE *pf2;
			
			pf2 = fopen("Ficheros/Crear_Cuenta_Correo.txt","r");				
			if(pf2 == NULL)
			{
				printf("ERROR; no he encontrado el archivo");
				return -1;
			}
			else
			{
				/*CORREO ELECTRONICO*/
				
				int i = 0;
				int j = 0;
				int k = 0;
				printf("\n\n-Introduce tu Correo Electronico: ");
				scanf("%s", &CCusuario.CCPersona.correo);
				
				/*Creamos un dominio @gmail.com, es decir cualquier otra terminación no es válida*/
				while(CCusuario.CCPersona.correo[i] != '\0')
				{
					i++;
				}
				int longitud = i;
				while(CCusuario.CCPersona.correo[j] != '\0')
				{
					if(CCusuario.CCPersona.correo[j] == '@')
					{
						if((CCusuario.CCPersona.correo[j] != '@') || (CCusuario.CCPersona.correo[j+1] != 'g') || (CCusuario.CCPersona.correo[j+2] != 'm') || (CCusuario.CCPersona.correo[j+3] != 'a') || (CCusuario.CCPersona.correo[j+4] != 'i') || (CCusuario.CCPersona.correo[j+5] != 'l') || (CCusuario.CCPersona.correo[j+6] != '.') || (CCusuario.CCPersona.correo[j+7] != 'c') || (CCusuario.CCPersona.correo[j+8] != 'o') || (CCusuario.CCPersona.correo[j+9] != 'm'))
						{
							do
							{
								printf("ERROR; la cuenta de correo ha de ser tipo: @gmail.com");
								printf("\n\n-Introduce tu Correo Electronico: ");
								scanf("%s", &CCusuario.CCPersona.correo);
							}
							while((CCusuario.CCPersona.correo[j] != '@') || (CCusuario.CCPersona.correo[j+1] != 'g') || (CCusuario.CCPersona.correo[j+2] != 'm') || (CCusuario.CCPersona.correo[j+3] != 'a') || (CCusuario.CCPersona.correo[j+4] != 'i') || (CCusuario.CCPersona.correo[j+5] != 'l') || (CCusuario.CCPersona.correo[j+6] != '.') || (CCusuario.CCPersona.correo[j+7] != 'c') || (CCusuario.CCPersona.correo[j+8] != 'o') || (CCusuario.CCPersona.correo[j+9] != 'm'));
						}
					}
					j++;
				}
				int longitud_correo = j;
				
				char correo_pf2[500];
				i = 0;
				
				/*Guardo el contenido del fichero*/
				while(fscanf(pf2,"%c",&correo_pf2[i]) != EOF)
				{		
					i++;
				}
				int longitud_cadena = i;
				
				k = 0;
				j = 0;
				i = 0;
					
				/*Comienzo el bucle en el que compruebo si ya existe una cuenta con el correo introducido por el ususario*/	
				for(i = 0 ; i < longitud_cadena ; i++)
				{
					if(CCusuario.CCPersona.correo[0] == correo_pf2[i])
					{
						j = i;
						
						for(k = 0 ; k < longitud_correo ; k++)
						{
							if(CCusuario.CCPersona.correo[k] != correo_pf2[j])
							{
								break;
							}
							else
							{
								j++;
							}
								
						}
					}
					/*Si confirmamos que el correo ya existe, pues enviamos al usuario a iniciar sesión*/	
					if(k == longitud_correo)
					{
						printf("\nYa existe una cuenta con este correo\n");
						IniciarSesion();
						return 0;
					}
				}
					
			fclose(pf2);
			}
					
			printf("Correo: %s\n", CCusuario.CCPersona.correo);
			fprintf(pf,"%s;",CCusuario.CCPersona.correo);
			fprintf(pf1,"%s\n", CCusuario.CCPersona.correo);
			
			
			/*CONTRASEÑA DEL CORREO*/
			
			/*Creamos y abrimos un fichero donde almacenaremos las contraseñas y correos de los usuarios, se utilizará para el INICIO DE SESIÓN*/
			FILE *pf3;
			pf3 = fopen("Ficheros/Crear_Cuenta_contrasena.txt","a");
			
			if(pf3 == NULL)
			{
				printf("ERROR; no he encontrado el archivo");
				return -1;
			}
			else
			{
				printf("\n-Introduce una contrasena\n(Solamente puede contener letras y numeros): ");
				scanf("%s", &CCusuario.CCPersona.contrasena);
			
				int i = 0;
				int j = 0;
				int k = 0;
				while(CCusuario.CCPersona.contrasena[i] != '\0')
				{
					i++;
				}
				int longitud1 = i;
				
				/*Hacemos que la contraseña solo pueda tener letras y numeros*/
				while(CCusuario.CCPersona.contrasena[j] != '\0')
				{
					if(((CCusuario.CCPersona.contrasena[j] < 48) || (CCusuario.CCPersona.contrasena[j] > 57)) && ((CCusuario.CCPersona.contrasena[j] < 65) || (CCusuario.CCPersona.contrasena[j] > 90)) && ((CCusuario.CCPersona.contrasena[j] < 97) || (CCusuario.CCPersona.contrasena[j] > 122)))
					{
						do
						{
							printf("ERROR; la contrasena solo puede tener letras y numeros");
							printf("\n\n-Introduce una contrasena\n(Solamente puede contener letras y numeros): ");
							scanf("%s", CCusuario.CCPersona.contrasena);
						}
						while(((CCusuario.CCPersona.contrasena[j] < 48) || (CCusuario.CCPersona.contrasena[j] > 57)) && ((CCusuario.CCPersona.contrasena[j] < 65) || (CCusuario.CCPersona.contrasena[j] > 90)) && ((CCusuario.CCPersona.contrasena[j] < 97) || (CCusuario.CCPersona.contrasena[j] > 122)));
			
					}	
					j++;
				}
							
				/*Simplemente por hacerlo algo más real imprimimos (*) en lugar de la contraseña*/
				printf("Contrasena: ");
				for(k = 0 ; k < longitud1 ; k++)
				{
					printf("*");
				}
			
				fprintf(pf,"%s;", CCusuario.CCPersona.contrasena);
				fprintf(pf3,"%s;%s\n", CCusuario.CCPersona.correo, CCusuario.CCPersona.contrasena);
				fclose(pf3);	
			}
		fclose(pf1);	
		}
			
		/*NOMBRE APELLIDO1 APELLIDO2*/
			
		/*Pedimos al usuario el primer apellido, en el caso de poner cualquier otra cosa que no sea una letra saltaría ERROR*/
		printf("\n\n-Primer Apellido: ");
		scanf("%s", &CCusuario.usuario.primer_apellido);
		
		i = 0;
		while(CCusuario.usuario.primer_apellido[i] != '\0')
		{
			if(((CCusuario.usuario.primer_apellido[i] < 65) || (CCusuario.usuario.primer_apellido[i] > 90)) && ((CCusuario.usuario.primer_apellido[i] < 97) || (CCusuario.usuario.primer_apellido[i] > 122)))
			{
				do
				{
					printf("ERROR; un apellido no puede tener otra cosa que no sea letras");
					printf("\n\n-Primer Apellido: ");
					scanf("%s", &CCusuario.usuario.primer_apellido);
				}
				while(((CCusuario.usuario.primer_apellido[i] < 65) || (CCusuario.usuario.primer_apellido[i] > 90)) && ((CCusuario.usuario.primer_apellido[i] < 97) || (CCusuario.usuario.primer_apellido[i] > 122)));
			}
		i++;
		}
			
		/*Pedimos al usuario el segundo apellido, en el caso de poner cualquier otra cosa que no sea una letra saltaría ERROR*/
		printf("-Segundo Apellido: ");
		scanf("%s", CCusuario.usuario.segundo_apellido);
			
		i = 0;
		while(CCusuario.usuario.segundo_apellido[i] != '\0')
		{
			if(((CCusuario.usuario.segundo_apellido[i] < 65) || (CCusuario.usuario.segundo_apellido[i] > 90)) && ((CCusuario.usuario.segundo_apellido[i] < 97) || (CCusuario.usuario.segundo_apellido[i] > 122)))
			{
				do
				{
					printf("ERROR; un apellido no puede tener otra cosa que no sea letras");
					printf("\n\n-Segundo Apellido: ");
					scanf("%s", CCusuario.usuario.segundo_apellido);
				}
				while(((CCusuario.usuario.segundo_apellido[i] < 65) || (CCusuario.usuario.segundo_apellido[i] > 90)) && ((CCusuario.usuario.segundo_apellido[i] < 97) || (CCusuario.usuario.segundo_apellido[i] > 122)));
			}
			i++;
		}
		
		/*Pedimos al usuario el nombre, en el caso de poner cualquier otra cosa que no sea un aletra saltaría ERROR*/
		printf("-Nombre: ");
		scanf("%s", CCusuario.usuario.nombre);
		
		i = 0;
		while(CCusuario.usuario.nombre[i] != '\0')
		{
			if(((CCusuario.usuario.nombre[i] < 65) || (CCusuario.usuario.nombre[i] > 90)) && ((CCusuario.usuario.nombre[i] < 97) || (CCusuario.usuario.nombre[i] > 122)))
			{
				do
				{
					printf("ERROR; un nombre no otra cosa que no sea letras");
					printf("\n\n- Nombre: ");
					scanf("%s", CCusuario.usuario.nombre);
				}
				while(((CCusuario.usuario.nombre[i] < 65) || (CCusuario.usuario.nombre[i] > 90)) && ((CCusuario.usuario.nombre[i] < 97) || (CCusuario.usuario.nombre[i] > 122)));
			}
			i++;
		}
		
		cambio_mayusculas(CCusuario.usuario.nombre, CCusuario.usuario.primer_apellido, CCusuario.usuario.segundo_apellido);
		printf("\nNombre Completo: %s %s %s", CCusuario.usuario.nombre, CCusuario.usuario.primer_apellido, CCusuario.usuario.segundo_apellido);
		fprintf(pf,"%s%s%s;", CCusuario.usuario.nombre, CCusuario.usuario.primer_apellido, CCusuario.usuario.segundo_apellido);
		
		
		/*FECHA DE NACIMIENTO*/
		
		printf("\n\n-Fecha de nacimiento");
		
		/*Pedimos que Introduzca el Año*/
		do
		{
			printf("\nAno: ");
			scanf("%i", &CCusuario.fecha.ano);
			
			if((CCusuario.fecha.ano < 1933) || (CCusuario.fecha.ano > 2023))
			{
				printf("ERROR; el ano introducido no es valido");
			}
		}
		while((CCusuario.fecha.ano < 1923) || (CCusuario.fecha.ano > 2023));
			
		/*Comprobamos si el aï¿½o de su nacimiento es Bisiesto*/
		/*Cubrimos todos los casos en caso de aï¿½os bisiestos o no, es decir, solo se permiten fechas reales*/
		
		if((CCusuario.fecha.ano % 4 == 0) && (CCusuario.fecha.ano % 100 != 0) || (CCusuario.fecha.ano % 400 == 0))/*Si el aï¿½o es bisiesto*/
		{
			/*Pedimos que Introduzca el Mes*/
			do
			{
				printf("Mes: ");
				scanf("%i", &CCusuario.fecha.mes);
			
				if((CCusuario.fecha.mes < 1) || (CCusuario.fecha.mes > 12))
				{
					printf("ERROR; el mes introducido no es valido\n");
				}
			
			}
			while((CCusuario.fecha.mes < 1) || (CCusuario.fecha.mes > 12));
			
			/*Pedimos que Introduzca el dia*/	
			switch (CCusuario.fecha.mes)
			{
				case 1:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;	
					}
				case 2:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 29))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 29));
						break;
					}
				case 3:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 4:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30));
						break;
					}
				case 5:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 6:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
							
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30));
						break;
					}
				case 7:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 8:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
					
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 9:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30));
						break;
					}
				case 10:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 11:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30));
						break;
					}
				case 12:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
							
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				default:
					{
						printf("Se ha producido un error");
						return -1;
					}
			}
		}
		else /*Si el año no es Bisiesto*/
		{
			/*Pedimos que Introduzca el Mes*/
			do
			{
				printf("Mes: ");
				scanf("%i", &CCusuario.fecha.mes);
			
				if((CCusuario.fecha.mes < 1) || (CCusuario.fecha.mes > 12))
				{
					printf("ERROR; el mes introducido no es valido\n");
				}
			
			}
			while((CCusuario.fecha.mes < 1) || (CCusuario.fecha.mes > 12));
		
			/*Pedimos que Introduzca el dia*/	
			switch (CCusuario.fecha.mes)
			{
				case 1:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;	
					}
				case 2:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
				
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 28))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 28));
						break;
					}
				case 3:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 4:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30));
						break;
					}
				case 5:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 6:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
							
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30));
						break;
					}
				case 7:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 8:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
					
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 9:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30));
						break;
					}
				case 10:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
					
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				case 11:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 30));
						break;
					}
				case 12:
					{
						do
						{
							printf("Dia: ");
							scanf("%i", &CCusuario.fecha.dia);
						
							if((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31))
							{
								printf("ERROR; el dia introducido no es valido\n");
							}
						}
						while((CCusuario.fecha.dia < 1) || (CCusuario.fecha.dia > 31));
						break;
					}
				default:
					{
						printf("Se ha producido un error");
						return -1;
					}
			}
			
		}
		printf("\nNacimiento: %i/%i/%i",CCusuario.fecha.dia,CCusuario.fecha.mes,CCusuario.fecha.ano);
		fprintf(pf,"%i/%i/%i;",CCusuario.fecha.dia,CCusuario.fecha.mes,CCusuario.fecha.ano);
			
			
		/*DNI*/
		/*Exigimos que tenga el tamaño real de un numero de DNI*/
		do
		{
			printf("\n\n-Introduce la parte numerica de tu DNI");
			printf("\nNumero: ");
			scanf("%i", &CCusuario.persona.parte_numerica);
				
			if((CCusuario.persona.parte_numerica < 10000000) || (CCusuario.persona.parte_numerica > 99999999))
			{
				printf("ERROR; un numero de DNI no tiene esas cifras");
			}
		}
		while((CCusuario.persona.parte_numerica < 10000000) || (CCusuario.persona.parte_numerica > 99999999));
		
		do
		{
			printf("-Introduce la letra de tu DNI");
			printf("\nLetra: ");
			scanf(" %c", &CCusuario.persona.letra);
		
			if(((CCusuario.persona.letra < 65) || (CCusuario.persona.letra > 90)) && ((CCusuario.persona.letra < 97) || (CCusuario.persona.letra > 122)))
			{
				printf("\n\nERROR; introduzca solo la letra");
			}
		}
		while(((CCusuario.persona.letra < 65) || (CCusuario.persona.letra > 90)) && ((CCusuario.persona.letra < 97) || (CCusuario.persona.letra > 122)));
		
		/*En el caso de introducir una letra minuscula, la cambiamos por mayuscula*/
		if((CCusuario.persona.letra < 65) || (CCusuario.persona.letra > 90))
		{
			CCusuario.persona.letra = CCusuario.persona.letra - 32;
		}
		
		printf("\nDNI: %i %c", CCusuario.persona.parte_numerica, CCusuario.persona.letra);
		
		fprintf(pf,"%i %c;",CCusuario.persona.parte_numerica, CCusuario.persona.letra);
		
		
		/*PROVINCIA Y CÓDIGO POSTAL*/
			
		do
		{
			printf("\n\n-Introduzca su Codigo Postal");
			printf("\nCodigo Postal: ");
			scanf("%5s", &CCusuario.cp);
			
			if(((CCusuario.cp[0] < 48) || (CCusuario.cp[0] > 57)) && ((CCusuario.cp[1] < 48) || (CCusuario.cp[1] > 57)) && ((CCusuario.cp[2] < 48) || (CCusuario.cp[2] > 57)) && ((CCusuario.cp[3] < 48) || (CCusuario.cp[3] > 57)) && ((CCusuario.cp[4] < 48) || (CCusuario.cp[4] > 57)))
			{
				printf("ERROR; el codigo postal no existe");
			}
		}	
		while(((CCusuario.cp[0] < 48) || (CCusuario.cp[0] > 57)) && ((CCusuario.cp[1] < 48) || (CCusuario.cp[1] > 57)) && ((CCusuario.cp[2] < 48) || (CCusuario.cp[2] > 57)) && ((CCusuario.cp[3] < 48) || (CCusuario.cp[3] > 57)) && ((CCusuario.cp[4] < 48) || (CCusuario.cp[4] > 57)));
		
		
		printf("\nCodigo Postal: %s", CCusuario.cp);
		fprintf(pf,"%s;",CCusuario.cp);
		
		/*Declaramos las variables de seleccion que utilizaremos a continuación*/
		int selec1, selec2, selec3, selec4, selec5, selec6, selec7, selec8, selec9;
		int selec10, selec11, selec12, selec13, selec14, selec15, selec16, selec17, selec18, selec19;
		int selec20, selec21, selec22, selec23, selec24, selec25, selec26, selec27, selec28, selec29;
		int selec30, selec31, selec32, selec33, selec34, selec35, selec36, selec37, selec38, selec39;
		int selec40, selec41, selec42, selec43, selec44, selec45, selec46, selec47, selec48, selec49;
		int selec50, selec51, selec52;
		
		/*Sabemos que cada proviancia española tiene un inicio de codigo postal diferente, segun el codigo postal que meta el usuario, preguntamos si reside en la provincia corrspondiente*/
		if(CCusuario.cp[0] == '0')
		{	
			if(CCusuario.cp[1] == '1')
			{
				printf("\n01: Alava\n");
				do
				{
					printf("\nResides en Alava");
					printf("\n1.-Si");
					printf("\n2.-No");
					printf("\nSeleccion (1 | 2): ");
					scanf("%i", &selec1);
				}
				while((selec1 < 1) || (selec1 > 2));
				
				switch (selec1)
				{
					case 1:
						{
							printf("\nProvincia: Alava");
							fprintf(pf,"Alava;",CCusuario.provincia);
							break;
						}
					case 2:
						{
							printf("\n-Introduce la provincia en la que reside");
							printf("\nProvincia: ");
							scanf("%s", &CCusuario.provincia);
					
							fprintf(pf,"%s",CCusuario.provincia);
							break;
						}
				}
			}
			if(CCusuario.cp[1] == '2')
			{
				printf("\n02: Albacete\n");
				do
				{
					printf("\nResides en Albacete");
					printf("\n1.-Si");
					printf("\n2.-No");
					printf("\nSeleccion (1 | 2): ");
					scanf("%i", &selec2);
				}
				while((selec2 < 1) || (selec2 > 2));
				
				switch (selec2)
				{
					case 1:
						{
							printf("\nProvincia: Albacete");
							fprintf(pf,"Albacete;",CCusuario.provincia);
							break;
						}
					case 2:
						{
							printf("\n-Introduce la provincia en la que reside");
							printf("\nProvincia: ");
							scanf("%s", &CCusuario.provincia);
					
							fprintf(pf,"%s",CCusuario.provincia);
							break;
						}
				}
			}
			if(CCusuario.cp[1] == '3')
			{
				printf("\n03: Alicante\n");
				do
				{
					printf("\nResides en Alicante");
					printf("\n1.-Si");
					printf("\n2.-No");
					printf("\nSeleccion (1 | 2): ");
					scanf("%i", &selec3);
				}
				while((selec3 < 1) || (selec3 > 2));
				
				switch (selec3)
				{
					case 1:
						{
							printf("\nProvincia: Alicante");
							fprintf(pf,"Alicante;",CCusuario.provincia);
							break;
						}
					case 2:
						{
							printf("\n-Introduce la provincia en la que reside");
							printf("\nProvincia: ");
							scanf("%s", &CCusuario.provincia);
					
							fprintf(pf,"%s",CCusuario.provincia);
							break;
						}
				}
			}
			if(CCusuario.cp[1] == '4')
			{
				printf("\n04: Almeria\n");
				do
				{
					printf("\nResides en Almeria");
					printf("\n1.-Si");
					printf("\n2.-No");
					printf("\nSeleccion (1 | 2): ");
					scanf("%i", &selec4);
				}
				while((selec4 < 1) || (selec4 > 2));
				
				switch (selec4)
				{
					case 1:
						{
							printf("\nProvincia: Almeria");
							fprintf(pf,"Almeria;",CCusuario.provincia);
							break;
						}
					case 2:
						{
							printf("\n-Introduce la provincia en la que reside");
							printf("\nProvincia: ");
							scanf("%s", &CCusuario.provincia);
					
							fprintf(pf,"%s",CCusuario.provincia);
							break;
						}
				}
			}
			if(CCusuario.cp[1] == '5')
				{
					printf("\n05: Avila\n");
					do
					{
						printf("\nResides en Avila");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec5);
					}
					while((selec5 < 1) || (selec5 > 2));
					
					switch (selec5)
					{
						case 1:
							{
								printf("\nProvincia: Avila");
								fprintf(pf,"Avila;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '6')
				{
					printf("\n06: Badajoz\n");
					do
					{
						printf("\nResides en Badajoz");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec6);
					}
					while((selec6 < 1) || (selec6 > 2));
					
					switch (selec6)
					{
						case 1:
							{
								printf("\nProvincia: Badajoz");
								fprintf(pf,"Badajoz;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '7')
				{
					printf("\n07: Baleares\n");
					do
					{
						printf("\nResides en Baleares");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec7);
					}
					while((selec7 < 1) || (selec7 > 2));
					
					switch (selec7)
					{
						case 1:
							{
								printf("\nProvincia: Baleares");
								fprintf(pf,"Baleares;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '8')
				{
					printf("\n08: Barcelona\n");
					do
					{
						printf("\nResides en Barcelona");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec8);
					}
					while((selec8 < 1) || (selec8 > 2));
					
					switch (selec8)
					{
						case 1:
							{
								printf("\nProvincia: Barcelona");
								fprintf(pf,"Barcelona;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '9')
				{
					printf("\n09: Burgos\n");
					do
					{
						printf("\nResides en Burgos");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec9);
					}
					while((selec9 < 1) || (selec9 > 2));
					
					switch (selec9)
					{
						case 1:
							{
								printf("\nProvincia: Burgos");
								fprintf(pf,"Burgos;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}	
			}
			else if(CCusuario.cp[0] == '1')
			{
				if(CCusuario.cp[1] == '0')
				{
					printf("\n10: Caceres\n");
					do
					{
						printf("\nResides en Caceres");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec10);
					}
					while((selec10 < 1) || (selec10 > 2));
					
					switch (selec10)
					{
						case 1:
							{
								printf("\nProvincia: Caceres");
								fprintf(pf,"Caceres;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '1')
				{
					printf("\n11: Cadiz\n");
					do
					{
						printf("\nResides en Cadiz");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec11);
					}
					while((selec11 < 1) || (selec11 > 2));
					
					switch (selec11)
					{
						case 1:
							{
								printf("\nProvincia: Cadiz");
								fprintf(pf,"Cadiz;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '2')
				{
					printf("\n12: Castellon\n");
					do
					{
						printf("\nResides en Castellon");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec12);
					}
					while((selec12 < 1) || (selec12 > 2));
					
					switch (selec12)
					{
						case 1:
							{
								printf("\nProvincia: Castellon");
								fprintf(pf,"Castellon;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '3')
				{
					printf("\n13: Ciudad Real\n");
					do
					{
						printf("\nResides en Ciudad Real");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec13);
					}
					while((selec13 < 1) || (selec13 > 2));
					
					switch (selec13)
					{
						case 1:
							{
								printf("\nProvincia: Ciudad Real");
								fprintf(pf,"Ciudad Real;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '4')
				{
					printf("\n14: Cordoba\n");
					do
					{
						printf("\nResides en Cordoba");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec14);
					}
					while((selec14 < 1) || (selec14 > 2));
					
					switch (selec14)
					{
						case 1:
							{
								printf("\nProvincia: Cordoba");
								fprintf(pf,"Cordoba;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '5')
				{
					printf("\n15: La Coruna\n");
					do
					{
						printf("\nResides en La Coruna");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec15);
					}
					while((selec15 < 1) || (selec15 > 2));
					
					switch (selec15)
					{
						case 1:
							{
								printf("\nProvincia: La Coruna");
								fprintf(pf,"La Coruna;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '6')
				{
					printf("\n16: Cuenca\n");
					do
					{
						printf("\nResides en Cuenca");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec16);
					}
					while((selec16 < 1) || (selec16 > 2));
					
					switch (selec16)
					{
						case 1:
							{
								printf("\nProvincia: Cuenca");
								fprintf(pf,"Cuenca;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '1')
				{
					printf("\n17: Gerona\n");
					do
					{
						printf("\nResides en Gerona");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec17);
					}
					while((selec17 < 1) || (selec17 > 2));
					
					switch (selec17)
					{
						case 1:
							{
								printf("\nProvincia: Gerona");
								fprintf(pf,"Gerona;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '8')
				{
					printf("\n18: Granada\n");
					do
					{
						printf("\nResides en Granada");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec18);
					}
					while((selec18 < 1) || (selec18 > 2));
					
					switch (selec18)
					{
						case 1:
							{
								printf("\nProvincia: Granada");
								fprintf(pf,"Granada;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '9')
				{
					printf("\n19: Guadalajara\n");
					do
					{
						printf("\nResides en Guadalajara");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec19);
					}
					while((selec19 < 1) || (selec19 > 2));
					
					switch (selec19)
					{
						case 1:
							{
								printf("\nProvincia: Guadalajara");
								fprintf(pf,"Guadalajara;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
			}
			else if(CCusuario.cp[0] == '2')
			{
				if(CCusuario.cp[1] == '0')
				{
					printf("\n20: Guipuzcoa\n");
					do
					{
						printf("\nResides en Guipuzcoa");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec20);
					}
					while((selec20 < 1) || (selec20 > 2));
					
					switch (selec20)
					{
						case 1:
							{
								printf("\nProvincia: Guipuzcoa");
								fprintf(pf,"Guipuzcoa;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '1')
				{
					printf("\n21: Huelva\n");
					do
					{
						printf("\nResides en Huelva");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec21);
					}
					while((selec21 < 1) || (selec21 > 2));
					
					switch (selec21)
					{
						case 1:
							{
								printf("\nProvincia: Huelva");
								fprintf(pf,"Huelva;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '2')
				{
					printf("\n22: Huesca\n");
					do
					{
						printf("\nResides en Huesca");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec22);
					}
					while((selec22 < 1) || (selec22 > 2));
					
					switch (selec22)
					{
						case 1:
							{
								printf("\nProvincia: Huesca");
								fprintf(pf,"Huesca;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '3')
				{
					printf("\n23: Jaen\n");
					do
					{
						printf("\nResides en Jaen");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec23);
					}
					while((selec23 < 1) || (selec23 > 2));
					
					switch (selec23)
					{
						case 1:
							{
								printf("\nProvincia: Jaen");
								fprintf(pf,"Jaen;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '4')
				{
					printf("\n24: Leon\n");
					do
					{
						printf("\nResides en Leon");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec24);
					}
					while((selec24 < 1) || (selec24 > 2));
					
					switch (selec24)
					{
						case 1:
							{
								printf("\nProvincia: Leon");
								fprintf(pf,"Leon;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '5')
				{
					printf("\n25: \n");
					do
					{
						printf("\nResides en Lerida");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec25);
					}
					while((selec25 < 1) || (selec25 > 2));
					
					switch (selec25)
					{
						case 1:
							{
								printf("\nProvincia: Lerida");
								fprintf(pf,"Lerida;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '6')
				{
					printf("\n26: La Rioja\n");
					do
					{
						printf("\nResides en La Rioja");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec26);
					}
					while((selec26 < 1) || (selec26 > 2));
					
					switch (selec26)
					{
						case 1:
							{
								printf("\nProvincia: La Rioja");
								fprintf(pf,"La Rioja;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '7')
				{
					printf("\n27: Lugo\n");
					do
					{
						printf("\nResides en Lugo");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec27);
					}
					while((selec27 < 1) || (selec27 > 2));
					
					switch (selec27)
					{
						case 1:
							{
								printf("\nProvincia: Lugo");
								fprintf(pf,"Lugo;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '8')
				{
					printf("\n28: Madrid\n");
					do
					{
						printf("\nResides en Madrid");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec28);
					}
					while((selec28 < 1) || (selec28 > 2));
					
					switch (selec28)
					{
						case 1:
							{
								printf("\nProvincia: Madrid");
								fprintf(pf,"Madrid;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '9')
				{
					printf("\n29: Malaga\n");
					do
					{
						printf("\nResides en Malaga");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec29);
					}
					while((selec29 < 1) || (selec29 > 2));
					
					switch (selec29)
					{
						case 1:
							{
								printf("\nProvincia: Malaga");
								fprintf(pf,"Malaga;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
			}
			else if(CCusuario.cp[0] == '3')
			{
				if(CCusuario.cp[1] == '0')
				{
					printf("\n30: Murcia\n");
					do
					{
						printf("\nResides en Murcia");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec30);
					}
					while((selec30 < 1) || (selec30 > 2));
					
					switch (selec30)
					{
						case 1:
							{
								printf("\nProvincia: Murcia");
								fprintf(pf,"Murcia;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '1')
				{
					printf("\n31: Navarra\n");
					do
					{
						printf("\nResides en Guipuzcoa");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec31);
					}
					while((selec31 < 1) || (selec31 > 2));
					
					switch (selec31)
					{
						case 1:
							{
								printf("\nProvincia: Navarra");
								fprintf(pf,"Navarra;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '3')
				{
					printf("\n33: Asturias\n");
					do
					{
						printf("\nResides en Asturias");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec33);
					}
					while((selec33 < 1) || (selec3 > 2));
					
					switch (selec33)
					{
						case 1:
							{
								printf("\nProvincia: Asturias");
								fprintf(pf,"Asturias;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '4')
				{
					printf("\n34: Palencia\n");
					do
					{
						printf("\nResides en Palencia");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec34);
					}
					while((selec34 < 1) || (selec34 > 2));
					
					switch (selec34)
					{
						case 1:
							{
								printf("\nProvincia: Palencia");
								fprintf(pf,"Palencia;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '5')
				{
					printf("\n35: Las Palmas\n");
					do
					{
						printf("\nResides en Las Palmas");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec35);
					}
					while((selec35 < 1) || (selec35 > 2));
					
					switch (selec35)
					{
						case 1:
							{
								printf("\nProvincia: Las Palmas");
								fprintf(pf,"Las Palmas;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '6')
				{
					printf("\n36: Pontevedra\n");
					do
					{
						printf("\nResides en Pontevedra");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec36);
					}
					while((selec36 < 1) || (selec36 > 2));
					
					switch (selec36)
					{
						case 1:
							{
								printf("\nProvincia: Pontevedra");
								fprintf(pf,"Pontevedra;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '7')
				{
					printf("\n37: Salamanca\n");
					do
					{
						printf("\nResides en Salamanca");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec37);
					}
					while((selec37 < 1) || (selec37 > 2));
					
					switch (selec37)
					{
						case 1:
							{
								printf("\nProvincia: Salamanca");
								fprintf(pf,"Salamanca;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '8')
				{
					printf("\n38: Santa Cruz de Tenerife\n");
					do
					{
						printf("\nResides en Santa Cruz de Tenerife");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec38);
					}
					while((selec38 < 1) || (selec38 > 2));
					
					switch (selec38)
					{
						case 1:
							{
								printf("\nProvincia: Santa Cruz de Tenerife");
								fprintf(pf,"Santa Cruz de Tenerife;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '9')
				{
					printf("\n39: Cantabria\n");
					do
					{
						printf("\nResides en Guipuzcoa");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec39);
					}
					while((selec39 < 1) || (selec39 > 2));
					
					switch (selec39)
					{
						case 1:
							{
								printf("\nProvincia: Cantabria");
								fprintf(pf,"Cantabria;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
			}
			else if(CCusuario.cp[0] == '4')
			{
				if(CCusuario.cp[1] == '0')
				{
					printf("\n40: Segovia\n");
					do
					{
						printf("\nResides en Segovia");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec40);
					}
					while((selec40 < 1) || (selec40 > 2));
					
					switch (selec40)
					{
						case 1:
							{
								printf("\nProvincia: Segovia");
								fprintf(pf,"Segovia;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '1')
				{
					printf("\n41: Sevilla\n");
					do
					{
						printf("\nResides en Sevilla");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec41);
					}
					while((selec41 < 1) || (selec41 > 2));
					
					switch (selec41)
					{
						case 1:
							{
								printf("\nProvincia: Sevilla");
								fprintf(pf,"Sevilla;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '2')
				{
					printf("\n42: Soria\n");
					do
					{
						printf("\nResides en Soria");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec42);
					}
					while((selec42 < 1) || (selec42 > 2));
					
					switch (selec42)
					{
						case 1:
							{
								printf("\nProvincia: Soria");
								fprintf(pf,"Soria;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '3')
				{
					printf("\n43: Tarragona\n");
					do
					{
						printf("\nResides en Tarragona");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec43);
					}
					while((selec43 < 1) || (selec43 > 2));
					
					switch (selec43)
					{
						case 1:
							{
								printf("\nProvincia: Tarragona");
								fprintf(pf,"Tarragona;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '4')
				{
					printf("\n44: Teruel\n");
					do
					{
						printf("\nResides en Teruel");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec44);
					}
					while((selec44 < 1) || (selec44 > 2));
					
					switch (selec44)
					{
						case 1:
							{
								printf("\nProvincia: Teruel");
								fprintf(pf,"Teruel;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '5')
				{
					printf("\n45: Toledo\n");
					do
					{
						printf("\nResides en Toledo");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec45);
					}
					while((selec45 < 1) || (selec45 > 2));
					
					switch (selec45)
					{
						case 1:
							{
								printf("\nProvincia: Toledo");
								fprintf(pf,"Toledo;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '6')
				{
					printf("\n46: Valencia\n");
					do
					{
						printf("\nResides en Valencia");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec46);
					}
					while((selec46 < 1) || (selec46 > 2));
					
					switch (selec46)
					{
						case 1:
							{
								printf("\nProvincia: Valencia");
								fprintf(pf,"Valencia;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '7')
				{
					printf("\n47: Valladolid\n");
					do
					{
						printf("\nResides en Valladolid");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec47);
					}
					while((selec47 < 1) || (selec47 > 2));
					
					switch (selec47)
					{
						case 1:
							{
								printf("\nProvincia: Valladolid");
								fprintf(pf,"Valladolid;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '8')
				{
					printf("\n48: Vizcaya\n");
					do
					{
						printf("\nResides en Vizcaya");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec48);
					}
					while((selec48 < 1) || (selec48 > 2));
					
					switch (selec48)
					{
						case 1:
							{
								printf("\nProvincia: Vizcaya");
								fprintf(pf,"Vizcaya;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '9')
				{
					printf("\n49: Zamora\n");
					do
					{
						printf("\nResides en Zamora");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec49);
					}
					while((selec49 < 1) || (selec49 > 2));
					
					switch (selec49)
					{
						case 1:
							{
								printf("\nProvincia: Zamora");
								fprintf(pf,"Zamora;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
			}
			else if(CCusuario.cp[0] == '5')
			{
				if(CCusuario.cp[1] == '0')
				{
					printf("\n50: Zaragoza\n");
					do
					{
						printf("\nResides en Zaragoza");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec50);
					}
					while((selec50 < 1) || (selec50 > 2));
					
					switch (selec50)
					{
						case 1:
							{
								printf("\nProvincia: Zaragoza");
								fprintf(pf,"Zaragoza;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '1')
				{
					printf("\n51: Ceuta\n");
					do
					{
						printf("\nResides en Ceuta");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec51);
					}
					while((selec51 < 1) || (selec51 > 2));
					
					switch (selec51)
					{
						case 1:
							{
								printf("\nProvincia: Ceuta");
								fprintf(pf,"Ceuta;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
				if(CCusuario.cp[1] == '2')
				{
					printf("\n52: Melilla\n");
					do
					{
						printf("\nResides en Melilla");
						printf("\n1.-Si");
						printf("\n2.-No");
						printf("\nSeleccion (1 | 2): ");
						scanf("%i", &selec52);
					}
					while((selec52 < 1) || (selec52 > 2));
					
					switch (selec52)
					{
						case 1:
							{
								printf("\nProvincia: Melilla");
								fprintf(pf,"Melilla;",CCusuario.provincia);
								break;
							}
						case 2:
							{
								printf("\n-Introduce la provincia en la que reside");
								printf("\nProvincia: ");
								scanf("%s", &CCusuario.provincia);
						
								fprintf(pf,"%s",CCusuario.provincia);
								break;
							}
					}
				}
			}
			
			fprintf(pf,"\n");
			fclose(pf);
			
			IniciarSesion();
		}

}

int IniciarSesion()
{
	/*Abrimos el fichero en modo solo lectura, aqui comprobaremos si el correo y la contraseï¿½a introducida ya estan registradas*/
	FILE *pf5;
	pf5 = fopen("Ficheros/Crear_Cuenta_contrasena.txt","r");
		
	if(pf5 == NULL)
	{
		printf("ERROR; no he encontrado el archivo");
		return -1;
	}
	else
	{
		/*Creamos la variable que utilizaremos en esta parte*/
		iniciar_sesion ISusuario;
		int i, j, k;
		printf("\n\n\n\nINICIAR SESION");
		
		printf("\n\n-Introduce el Correo Electronico: ");
		scanf("%s", &ISusuario.ISpersona.correo);
		
		/*Medimos la longitud del correo introducido por el usuario*/
		i = 0;
		while(ISusuario.ISpersona.correo[i] != '\0')
		{
			i++;
		}
		int longitud_correo = i;
		
		/*Creamos una variable donde guardaremos el contenido del fichero*/		
		char correo_pf5[10000];
		i = 0;
		
		/*Medimos la longitud del fichero del cual leeremos todos los correos*/		
		while(fscanf(pf5,"%c",&correo_pf5[i]) != EOF)
		{		
			i++;
		}
		int longitud_cadena = i;

		/*Comenzamos el bucle para comprobar si el correo introducido ya existe o el usuario debe crear cuenta*/			
		k = 0;
		j = 0;
		i = 0;
		
		int check = 0;
		int principio_contrasena = 0;
					
		for(i = 0 ; i < longitud_cadena ; i++)
		{
			if(ISusuario.ISpersona.correo[0] == correo_pf5[i])
			{
				j = i;
							
				for(k = 0 ; k < longitud_correo ; k++)
				{
					if(ISusuario.ISpersona.correo[k] != correo_pf5[j])
					{
						k = longitud_correo;
					}
					else
					{
						j++;
					}			
				}
				if(j == i + longitud_correo)
				{
					check = 1;
					principio_contrasena = i + longitud_correo + 1;
				}
			}
		}
		
		if(check == 1)
		{
			int comprobacion = 0;
			int c = 0;
			do
			{
				printf("-Introduce la contrasena: ");
				scanf("%s", &ISusuario.ISpersona.contrasena);
			
				j = 0;
				k = 0;
					
					
				/*Medimos la longitud de la contraseï¿½a introducida por el usuario*/
					
				while(ISusuario.ISpersona.contrasena[k] != '\0')
				{
					k++;
				}
				int longitud_contrasena = k;
				
					
				/*Comenzamos el bucle para comprobar si la contraseï¿½a introducida por el usuario es correcta*/
				
				for(i = 0 ; i < longitud_contrasena ; i++)
				{
					if(ISusuario.ISpersona.contrasena[i] != correo_pf5[principio_contrasena + i])
					{
						break;
					}
					
				}
					
				/*Observamos que serï¿½ correcta si el valor que tenemos en longitud_contrasena es igual al valor de i*/
					
				if(longitud_contrasena == i)
				{
					printf("\nInicio de Sesion completado\n");
					comprobacion = 1;
					menu();
				}
				/*Si la contraseï¿½a introducida no es correcta, el usuario tiene tres intentos para escribirla bien*/
				else
				{
					printf("CONTRASENA INCORRECTA\n\n");
					comprobacion = 0;
				
				}
				c++;
			}
			/*Si en esos tres intentos no la pone bien el programa le expulsarï¿½ del INICIO DE SESIï¿½N*/
			while((comprobacion != 1) && (c < 3));
			return 0;
		}
		else
		{
			printf("No existe una cuenta con este correo");
			CrearCuenta();
			return 0;
		}		
	}
	fclose(pf5);		
}



/*Cambio de minusculas a Mayusculas*/

void cambio_mayusculas(char nombre[], char apellido1[], char apellido2[])
{
	int i = 0;
	while(nombre[i] != '\0')
	{
		if((nombre[i] > 96) && (nombre[i] < 123))
		{
			nombre[i] = nombre[i] - 32;
		}
		i++;
	}
	
	i = 0;
	while(apellido1[i] != '\0')
	{
		if((apellido1[i] > 96) && (apellido1[i] < 123))
		{
			apellido1[i] = apellido1[i] - 32;
		}
		i++;
	}
	i = 0;
	while(apellido2[i] != '\0')
	{
		if((apellido2[i] > 96) && (apellido2[i] < 123))
		{
			apellido2[i] = apellido2[i] - 32;
		}
		i++;
	}
}


/*Una vez finalizado el Inicio de sesiónn llevamos al usuario al menu*/
int menu()
{
	int seleccion;
	/*El usuario seleccion que desea realizar*/
	
	do
	{
		printf("\n\n\n\n\n\nSeleccione que desea realizar");
		printf("\n1.-Comparaciones");
		printf("\n2.-Predicciones");
		printf("\n3.-Informacion");
		printf("\n4.-Salir");
		printf("\nSeleccion( 1 | 2 | 3 | 4 ): ");
		scanf("%i", &seleccion);
		
		if((seleccion < 1) || (seleccion > 4))
		{
			printf("ERROR; la seleccion no es valida");
		}
	}
	while((seleccion < 1) || (seleccion > 4));
	
	switch (seleccion)
	{
		case 1:
			{
				f_comparacion();
				menu();	
				break;
			}
		case 2:
			{
				printf("\n\nPREDICCIONES");
				predicciones();
				
				break;
			}
		case 3:
			{
				printf("\n\nINFORMACION");
				int comprobacion_error1 = informacion();
				if(comprobacion_error1 == -1)
				{
					return -1;
				}
				
				break;
			}
		case 4:
			{
				printf("\n\nSALIR");
				return 0;
			}
		default:
		{
			printf("Fallo en el servidor");
			return -1;
		}
	}
}


/*Tratamos de explicar de forma sencilla que es REE*/
int informacion()
{
	printf("\n\nInformacion Extraida de Red.Electrica: https://www.ree.es/es/datos/publicaciones");
	
	FILE *pfin;
	pfin = fopen("Ficheros/Informacion.txt","r");
	
	if(pfin == NULL)
	{
		printf("ERROR; no he encontrado el archivo");
		return -1;
	}
	else
	{
		char info[10000];
		int i = 0;
		
		printf("\nQUE ES RED ELECTRICA DE ESPANA?\n");
		while(fscanf(pfin,"%c",&info[i]) != EOF)
		{
			i++;
		}
		printf("%s",info);
		printf("\n(Fuente: https://www.pepeenergy.com/blog/glosario/definicion-ree-red-electrica-de-espana/)\n\n\n\n");
		
		int pulsa;
		do
		{
			printf("Pulse 1 para volver al menu: ");
			scanf("%i", &pulsa);
			
			if(pulsa != 1)
			{
				printf("\nERROR; la seleccion no es correcta\n\n");
			}
			
			if(pulsa == 1)
			{
				menu();
			}
		}
		while(pulsa != 1);
	}
	fclose(pfin);
}



void f_comparacion () /*Funcion Comparacion*/
{
    char eleccion_comparacion;
    
    f_comparacion_menu(&eleccion_comparacion); /*Esto esta metido en una funcion por que salia el menu duplicado y de esta manera esto no sucede*/

    switch (eleccion_comparacion) /* Switch para la Eleccion de Datos a Comparar (Meses | Anios)*/
    {
        case 'a': // Parte de Alvaro//
        {
            break;
        }
        
        case 'b': /* Datos Mensuales */
        {
            int anio_mes_1;

            do /* Seleccion del Anio del Primer Mes */
            {
                printf("Seleccione en que anio se encuentra el mes que quiere comparar: \n");
                printf("2020 \n");
                printf("2021 \n");
                printf("2022 \n");
                printf("2023 \n");
                printf("Indique el anio seleccionado introduciendolo por el teclado (2020 | 2021 | 2022 | 2023) \n");
                scanf("%i",&anio_mes_1);
                printf("\n");
            } while ((anio_mes_1 < 2020)||(anio_mes_1 > 2023));

            int mes_1 = f_comparacion_eleccion_mes (anio_mes_1);


            int anio_mes_2;
            int mes_2;

            do
            {
                do /* Seleccion del Año del Segundo Mes */
                {
                    printf("Seleccione en que anio se encuentra el otro mes que quiere comparar: \n");
                    printf("No seleccione el mismo mes que ha seleccionado anteriormente. \n");
                    printf("2020 \n");
                    printf("2021 \n");
                    printf("2022 \n");
                    printf("2023 \n");
                    printf("Indique el anio seleccionado introduciendolo por el teclado (2020 | 2021 | 2022 | 2023) \n");
                    scanf("%i",&anio_mes_2);
                    printf("\n");
                    } while ((anio_mes_2 < 2020)||(anio_mes_2 > 2023));

                    mes_2 = f_comparacion_eleccion_mes (anio_mes_2);

            } while ((anio_mes_1 == anio_mes_2) && (mes_1 == mes_2));
            
            /*Declaramos las variables necesarias para la funcion de apertura, lectura y cierre de los ficheros*/

            int hidraulica_0, hidraulica_1, eolica_0, eolica_1, solar_fotovoltaica_0, solar_fotovoltaica_1, solar_termica_0, solar_termica_1, otras_renovables_0, otras_renovables_1, residuos_renovables_0, residuos_renovables_1, Generacion_Renovable_0, Generacion_Renovable_1, turbinacion_bombeo_0, turbinacion_bombeo_1, nuclear_0, nuclear_1, ciclo_combinado_0, ciclo_combinado_1, carbon_0, carbon_1, cogeneracion_0, cogeneracion_1, residuos_no_renovables_0, residuos_no_renovables_1, Generacion_No_Renovable_0, Generacion_No_Renovable_1, consumos_en_bombeo_0, consumos_en_bombeo_1, enlace_peninsula_baleares_0, enlace_peninsula_baleares_1, saldo_intercambios_internacionales_0, saldo_intercambios_internacionales_1, Demanda_0, Demanda_1;
    
            f_comparacion_ficheros (anio_mes_1,mes_1, &hidraulica_0, &hidraulica_1, &eolica_0, &eolica_1, &solar_fotovoltaica_0, &solar_fotovoltaica_1, &solar_termica_0, &solar_termica_1, &otras_renovables_0, &otras_renovables_1, &residuos_renovables_0, &residuos_renovables_1, &Generacion_Renovable_0, &Generacion_Renovable_1, &turbinacion_bombeo_0, &turbinacion_bombeo_1, &nuclear_0, &nuclear_1, &ciclo_combinado_0, &ciclo_combinado_1, &carbon_0, &carbon_1, &cogeneracion_0, &cogeneracion_1, &residuos_no_renovables_0, &residuos_no_renovables_1, &Generacion_No_Renovable_0, &Generacion_No_Renovable_1, &consumos_en_bombeo_0, &consumos_en_bombeo_1, &enlace_peninsula_baleares_0, &enlace_peninsula_baleares_1, &saldo_intercambios_internacionales_0, &saldo_intercambios_internacionales_1, &Demanda_0, &Demanda_1);
            
            /*Declaramos las variables y asignamos su valor extraido de los ficheros (mediante punteros) */
            
			/*Primer Mes*/ 
            int datos_mes_1_hidraulica_1 = hidraulica_0;
            int datos_mes_1_eolica_1 = eolica_0;
            int datos_mes_1_solar_fotovoltaica_1 = solar_fotovoltaica_0;
            int datos_mes_1_solar_termica_1 = solar_termica_0;
            int datos_mes_1_otras_renovables_1 = otras_renovables_0;
            int datos_mes_1_residuos_renovables_1 = residuos_renovables_0;
            int datos_mes_1_Generacion_Renovable_1 = Generacion_Renovable_0;
            int datos_mes_1_turbinacion_bombeo_1 = turbinacion_bombeo_0;
            int datos_mes_1_nuclear_1 = nuclear_0;
            int datos_mes_1_ciclo_combinado_1 = ciclo_combinado_0;
            int datos_mes_1_carbon_1 = carbon_0;
            int datos_mes_1_cogeneracion_1 = cogeneracion_0;
            int datos_mes_1_residuos_no_renovables_1 = residuos_no_renovables_0;
            int datos_mes_1_Generacion_No_Renovable_1 = Generacion_No_Renovable_0;
            int datos_mes_1_consumos_en_bombeo_1 = consumos_en_bombeo_0;
            int datos_mes_1_enlace_peninsula_baleares_1 = enlace_peninsula_baleares_0;
            int datos_mes_1_saldo_intercambios_internacionales_1 = saldo_intercambios_internacionales_0;
            int datos_mes_1_Demanda_1 = Demanda_0;
            
            /*Primer Mes Acumuladas*/
            int datos_mes_1_hidraulica_2 = hidraulica_1;
            int datos_mes_1_eolica_2 = eolica_1;
            int datos_mes_1_solar_fotovoltaica_2 = solar_fotovoltaica_1;
            int datos_mes_1_solar_termica_2 = solar_termica_1;
            int datos_mes_1_otras_renovables_2 = otras_renovables_1;
            int datos_mes_1_residuos_renovables_2 = residuos_renovables_1;
            int datos_mes_1_Generacion_Renovable_2 = Generacion_Renovable_1;
            int datos_mes_1_turbinacion_bombeo_2 = turbinacion_bombeo_1;
            int datos_mes_1_nuclear_2 = nuclear_1;
            int datos_mes_1_ciclo_combinado_2 = ciclo_combinado_1;
            int datos_mes_1_carbon_2 = carbon_1;
            int datos_mes_1_cogeneracion_2 = cogeneracion_1;
            int datos_mes_1_residuos_no_renovables_2 = residuos_no_renovables_1;
            int datos_mes_1_Generacion_No_Renovable_2 = Generacion_No_Renovable_1;
            int datos_mes_1_consumos_en_bombeo_2 = consumos_en_bombeo_1;
            int datos_mes_1_enlace_peninsula_baleares_2 = enlace_peninsula_baleares_1;
            int datos_mes_1_saldo_intercambios_internacionales_2 = saldo_intercambios_internacionales_1;
            int datos_mes_1_Demanda_2 = Demanda_1;

            f_comparacion_ficheros (anio_mes_2,mes_2, &hidraulica_0, &hidraulica_1, &eolica_0, &eolica_1, &solar_fotovoltaica_0, &solar_fotovoltaica_1, &solar_termica_0, &solar_termica_1, &otras_renovables_0, &otras_renovables_1, &residuos_renovables_0, &residuos_renovables_1, &Generacion_Renovable_0, &Generacion_Renovable_1, &turbinacion_bombeo_0, &turbinacion_bombeo_1, &nuclear_0, &nuclear_1, &ciclo_combinado_0, &ciclo_combinado_1, &carbon_0, &carbon_1, &cogeneracion_0, &cogeneracion_1, &residuos_no_renovables_0, &residuos_no_renovables_1, &Generacion_No_Renovable_0, &Generacion_No_Renovable_1, &consumos_en_bombeo_0, &consumos_en_bombeo_1, &enlace_peninsula_baleares_0, &enlace_peninsula_baleares_1, &saldo_intercambios_internacionales_0, &saldo_intercambios_internacionales_1, &Demanda_0, &Demanda_1);
            
			/*Segundo Mes*/
            int datos_mes_2_hidraulica_1 = hidraulica_0;
            int datos_mes_2_eolica_1 = eolica_0;
            int datos_mes_2_solar_fotovoltaica_1 = solar_fotovoltaica_0;
            int datos_mes_2_solar_termica_1 = solar_termica_0;
            int datos_mes_2_otras_renovables_1 = otras_renovables_0;
            int datos_mes_2_residuos_renovables_1 = residuos_renovables_0;
            int datos_mes_2_Generacion_Renovable_1 = Generacion_Renovable_0;
            int datos_mes_2_turbinacion_bombeo_1 = turbinacion_bombeo_0;
            int datos_mes_2_nuclear_1 = nuclear_0;
            int datos_mes_2_ciclo_combinado_1 = ciclo_combinado_0;
            int datos_mes_2_carbon_1 = carbon_0;
            int datos_mes_2_cogeneracion_1 = cogeneracion_0;
            int datos_mes_2_residuos_no_renovables_1 = residuos_no_renovables_0;
            int datos_mes_2_Generacion_No_Renovable_1 = Generacion_No_Renovable_0;
            int datos_mes_2_consumos_en_bombeo_1 = consumos_en_bombeo_0;
            int datos_mes_2_enlace_peninsula_baleares_1 = enlace_peninsula_baleares_0;
            int datos_mes_2_saldo_intercambios_internacionales_1 = saldo_intercambios_internacionales_0;
            int datos_mes_2_Demanda_1 = Demanda_0;
            
            /*Segundo Mes Acumuladas*/
            int datos_mes_2_hidraulica_2 = hidraulica_1;
            int datos_mes_2_eolica_2 = eolica_1;
            int datos_mes_2_solar_fotovoltaica_2 = solar_fotovoltaica_1;
            int datos_mes_2_solar_termica_2 = solar_termica_1;
            int datos_mes_2_otras_renovables_2 = otras_renovables_1;
            int datos_mes_2_residuos_renovables_2 = residuos_renovables_1;
            int datos_mes_2_Generacion_Renovable_2 = Generacion_Renovable_1;
            int datos_mes_2_turbinacion_bombeo_2 = turbinacion_bombeo_1;
            int datos_mes_2_nuclear_2 = nuclear_1;
            int datos_mes_2_ciclo_combinado_2 = ciclo_combinado_1;
            int datos_mes_2_carbon_2 = carbon_1;
            int datos_mes_2_cogeneracion_2 = cogeneracion_1;
            int datos_mes_2_residuos_no_renovables_2 = residuos_no_renovables_1;
            int datos_mes_2_Generacion_No_Renovable_2 = Generacion_No_Renovable_1;
            int datos_mes_2_consumos_en_bombeo_2 = consumos_en_bombeo_1;
            int datos_mes_2_enlace_peninsula_baleares_2 = enlace_peninsula_baleares_1;
            int datos_mes_2_saldo_intercambios_internacionales_2 = saldo_intercambios_internacionales_1;
            int datos_mes_2_Demanda_2 = Demanda_1;
            
            /*Impresion de la diferencia de valores del Primer y el Segundo mes*/

            printf("Los valores obtenidos tras realizar la comparacion son: \n");
            printf("\n");

            printf("                     Variacion Mensual (GWh) ||  Variacion Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",datos_mes_1_hidraulica_1-datos_mes_2_hidraulica_1, datos_mes_1_hidraulica_2-datos_mes_2_hidraulica_2);
                printf("  Eolica:                               %i   %i  \n",datos_mes_1_eolica_1-datos_mes_2_eolica_1, datos_mes_1_eolica_2-datos_mes_2_eolica_2);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",datos_mes_1_solar_fotovoltaica_1-datos_mes_2_solar_fotovoltaica_1, datos_mes_1_solar_fotovoltaica_2-datos_mes_2_solar_fotovoltaica_2);
                printf("  Solar Termica:                        %i   %i  \n",datos_mes_1_solar_termica_1-datos_mes_2_solar_termica_1, datos_mes_1_solar_termica_2-datos_mes_2_solar_termica_2);
                printf("  Otras Renovables:                     %i   %i  \n",datos_mes_1_otras_renovables_1-datos_mes_2_otras_renovables_1, datos_mes_1_otras_renovables_2-datos_mes_2_otras_renovables_2);
                printf("  Residuos Renovables:                  %i   %i  \n",datos_mes_1_residuos_renovables_1-datos_mes_2_residuos_renovables_1, datos_mes_1_residuos_renovables_2-datos_mes_2_residuos_renovables_2);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",datos_mes_1_Generacion_Renovable_1-datos_mes_2_Generacion_Renovable_1, datos_mes_1_Generacion_Renovable_2-datos_mes_2_Generacion_Renovable_2);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",datos_mes_1_turbinacion_bombeo_1-datos_mes_2_turbinacion_bombeo_1, datos_mes_1_turbinacion_bombeo_2-datos_mes_2_turbinacion_bombeo_2);
                printf("  Nuclear:                              %i   %i  \n",datos_mes_1_nuclear_1-datos_mes_2_nuclear_1, datos_mes_1_nuclear_2-datos_mes_2_nuclear_2);
                printf("  Ciclo Combinado:                      %i   %i  \n",datos_mes_1_ciclo_combinado_1-datos_mes_2_ciclo_combinado_1, datos_mes_1_ciclo_combinado_2-datos_mes_2_ciclo_combinado_2);
                printf("  Carbon:                               %i   %i  \n",datos_mes_1_carbon_1-datos_mes_2_carbon_1, datos_mes_1_carbon_2-datos_mes_2_carbon_2);
                printf("  Cogeneracion:                         %i   %i  \n",datos_mes_1_cogeneracion_1-datos_mes_2_cogeneracion_1, datos_mes_1_cogeneracion_2-datos_mes_2_cogeneracion_2);
                printf("  Residuos No Renovables:               %i   %i  \n",datos_mes_1_residuos_no_renovables_1-datos_mes_2_residuos_no_renovables_1, datos_mes_1_residuos_no_renovables_2-datos_mes_2_residuos_no_renovables_2);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",datos_mes_1_Generacion_No_Renovable_1-datos_mes_2_Generacion_No_Renovable_1, datos_mes_1_Generacion_No_Renovable_2-datos_mes_2_Generacion_No_Renovable_2);
                printf("  Consumos en Bombeo:                   %i   %i  \n",datos_mes_1_consumos_en_bombeo_1-datos_mes_2_consumos_en_bombeo_1, datos_mes_1_consumos_en_bombeo_2-datos_mes_2_consumos_en_bombeo_2);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",datos_mes_1_enlace_peninsula_baleares_1-datos_mes_2_enlace_peninsula_baleares_1, datos_mes_1_enlace_peninsula_baleares_2-datos_mes_2_enlace_peninsula_baleares_2);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",datos_mes_1_saldo_intercambios_internacionales_1-datos_mes_2_saldo_intercambios_internacionales_1, datos_mes_1_saldo_intercambios_internacionales_2-datos_mes_2_saldo_intercambios_internacionales_2);
                printf("  DEMANDA:                              %i   %i  \n",datos_mes_1_Demanda_1-datos_mes_2_Demanda_1, datos_mes_1_Demanda_2-datos_mes_2_Demanda_2);
                printf("\n");

            break;
        }

        case 'c': /*Salir al Menu*/
        {
            menu();
        }
        
        default: /* Primer Switch */
        {
            printf("Se ha producido un error, por favor, intentelo mas tarde. \n");
            printf("\n");
            break;
        }
	}
}

void f_comparacion_menu (char *eleccion_comparacion) /*Funcion Menu de Comparaciones*/ /*Esta dentro de una funcion para evitar que se produzca un bug de duplicado*/
{
	char eleccion_comparacion_char;
	
	do /*Seleccion de la Funcion a Realizar */
    {	
        printf("\n");
		printf("Seleccione que datos desea comparar \n");
        printf("a.-Comparacion de Datos Anuales \n");
        printf("b.-Comparacion de Datos Mensuales \n");
        printf("c.-Salir al Menu \n ");
        printf("Seleccione la opcion a realizar introduciendo (a | b | c). \n");
        scanf("%c",&eleccion_comparacion_char);
        printf("\n");
        
        *eleccion_comparacion = eleccion_comparacion_char;
        
    } while ((eleccion_comparacion_char!='a')&&(eleccion_comparacion_char!='b')&&(eleccion_comparacion_char!='c'));
}

int f_comparacion_eleccion_mes (int comparacion_eleccion_mes_int) /* Funcion Seleccion de Meses a Comparar */ 
{
    int comparacion_eleccion_mes;
    
    if (comparacion_eleccion_mes_int == 2020)
    {       
            do
            {
                printf("Seleccione el mes del que desea comparar los datos: \n");
                printf("1.- Enero 2020 \n");
                printf("2.- Febrero 2020 \n");
                printf("3.- Marzo 2020 \n");
                printf("4.- Abril 2020 \n");
                printf("5.- Mayo 2020 \n");
                printf("6.- Junio 2020 \n");
                printf("7.- Julio 2020 \n");
                printf("8.- Agosto 2020 \n");
                printf("9.- Septiembre 2020 \n");
                printf("10.- Octubre 2020 \n");
                printf("11.- Noviembre 2020 \n");
                printf("12.- Diciembre 2020 \n");
                scanf("%i",&comparacion_eleccion_mes);
                printf("\n");
            } while ((comparacion_eleccion_mes < 1)||(comparacion_eleccion_mes > 12));

    }

    if (comparacion_eleccion_mes_int == 2021)
    {       
            do
            {
                printf("Seleccione el mes del que desea comparar los datos: \n");
                printf("1.- Enero 2021 \n");
                printf("2.- Febrero 2021 \n");
                printf("3.- Marzo 2021 \n");
                printf("4.- Abril 2021 \n");
                printf("5.- Mayo 2021 \n");
                printf("6.- Junio 2021 \n");
                printf("7.- Julio 2021 \n");
                printf("8.- Agosto 2021 \n");
                printf("9.- Septiembre 2021 \n");
                printf("10.- Octubre 2021 \n");
                printf("11.- Noviembre 2021 \n");
                printf("12.- Diciembre 2021 \n");
                scanf("%i",&comparacion_eleccion_mes);
                printf("\n");
            } while ((comparacion_eleccion_mes < 1)||(comparacion_eleccion_mes > 12));

    }

    if (comparacion_eleccion_mes_int == 2022)
    {       
            do
            {
                printf("Seleccione el mes del que desea comparar los datos: \n");
                printf("1.- Enero 2022 \n");
                printf("2.- Febrero 2022 \n");
                printf("3.- Marzo 2022 \n");
                printf("4.- Abril 2022 \n");
                printf("5.- Mayo 2022 \n");
                printf("6.- Junio 2022 \n");
                printf("7.- Julio 2022 \n");
                printf("8.- Agosto 2022 \n");
                printf("9.- Septiembre 2022 \n");
                printf("10.- Octubre 2022 \n");
                printf("11.- Noviembre 2022 \n");
                printf("12.- Diciembre 2022 \n");
                scanf("%i",&comparacion_eleccion_mes);
                printf("\n");
            } while ((comparacion_eleccion_mes < 1)||(comparacion_eleccion_mes > 12));

    }

    if (comparacion_eleccion_mes_int == 2023)
    {       
            do
            {
                printf("Seleccione el mes del que desea comparar los datos: \n");
                printf("1.- Enero 2023 \n");
                printf("2.- Febrero 2023 \n");
                printf("3.- Marzo 2023 \n");
                printf("4.- Abril 2023 \n");
                scanf("%i",&comparacion_eleccion_mes);
                printf("\n");
            } while ((comparacion_eleccion_mes < 1)||(comparacion_eleccion_mes > 4));
    }
    return comparacion_eleccion_mes;
}

/*Funcion Abrir y Cerrar Ficheros con los Datos Mensuales*/
void f_comparacion_ficheros (int anio_mes_void, int mes_void, int *hidraulica_0, int *hidraulica_1, int *eolica_0, int *eolica_1, int *solar_fotovoltaica_0, int *solar_fotovoltaica_1, int *solar_termica_0, int *solar_termica_1, int *otras_renovables_0, int *otras_renovables_1, int *residuos_renovables_0, int *residuos_renovables_1, int *Generacion_Renovable_0, int *Generacion_Renovable_1, int *turbinacion_bombeo_0, int *turbinacion_bombeo_1, int *nuclear_0, int *nuclear_1, int *ciclo_combinado_0, int *ciclo_combinado_1, int *carbon_0, int *carbon_1, int *cogeneracion_0, int *cogeneracion_1, int *residuos_no_renovables_0, int *residuos_no_renovables_1, int *Generacion_No_Renovable_0, int *Generacion_No_Renovable_1, int *consumos_en_bombeo_0, int *consumos_en_bombeo_1, int *enlace_peninsula_baleares_0, int *enlace_peninsula_baleares_1, int *saldo_intercambios_internacionales_0, int *saldo_intercambios_internacionales_1, int *Demanda_0, int *Demanda_1)
{
    int i;

    if (anio_mes_void == 2020)
    {
        if (mes_void == 1)
        {
            FILE *plectura_2020_enero;
            plectura_2020_enero = fopen("Ficheros_Comparaciones/2020/2020_enero.csv", "r");
            if (plectura_2020_enero == NULL)
            {
                printf("Error al abrir el fichero de lectura (01/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (01/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes enero_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_enero, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &enero_2020.hidraulica [i], &enero_2020.eolica [i], &enero_2020.solar_fotovoltaica [i], &enero_2020.solar_termica [i], &enero_2020.otras_renovables [i], &enero_2020.residuos_renovables [i], &enero_2020.Generacion_Renovable [i], &enero_2020.turbinacion_bombeo [i], &enero_2020.nuclear [i], &enero_2020.ciclo_combinado [i], &enero_2020.carbon [i],&enero_2020.cogeneracion [i], &enero_2020.residuos_no_renovables [i], &enero_2020.Generacion_No_Renovable [i], &enero_2020.consumos_en_bombeo [i], &enero_2020.enlace_peninsula_baleares [i], &enero_2020.saldo_intercambios_internacionales [i], &enero_2020.Demanda [i]);
                }

                printf("                           Enero 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",enero_2020.hidraulica[0], enero_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",enero_2020.eolica[0], enero_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",enero_2020.solar_fotovoltaica[0], enero_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",enero_2020.solar_termica[0], enero_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",enero_2020.otras_renovables[0], enero_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",enero_2020.residuos_renovables[0], enero_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",enero_2020.Generacion_Renovable[0], enero_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",enero_2020.turbinacion_bombeo[0], enero_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",enero_2020.nuclear[0], enero_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",enero_2020.ciclo_combinado[0], enero_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",enero_2020.carbon[0], enero_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",enero_2020.cogeneracion[0], enero_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",enero_2020.residuos_no_renovables[0], enero_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",enero_2020.Generacion_No_Renovable[0], enero_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",enero_2020.consumos_en_bombeo[0], enero_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",enero_2020.enlace_peninsula_baleares[0], enero_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",enero_2020.saldo_intercambios_internacionales[0], enero_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",enero_2020.Demanda[0], enero_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = enero_2020.hidraulica[0];
                *hidraulica_1 = enero_2020.hidraulica[1];
                *eolica_0 = enero_2020.eolica[0];
                *eolica_1 = enero_2020.eolica[1];
                *solar_fotovoltaica_0 = enero_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = enero_2020.solar_fotovoltaica[1];
                *solar_termica_0 = enero_2020.solar_termica[0];
                *solar_termica_1 = enero_2020.solar_termica[1];
                *otras_renovables_0 = enero_2020.otras_renovables[0];
                *otras_renovables_1 = enero_2020.otras_renovables[1];
                *residuos_renovables_0 = enero_2020.residuos_renovables[0];
                *residuos_renovables_1 = enero_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = enero_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = enero_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = enero_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = enero_2020.turbinacion_bombeo[1];
                *nuclear_0 = enero_2020.nuclear[0];
                *nuclear_1 = enero_2020.nuclear[1];
                *ciclo_combinado_0 = enero_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = enero_2020.ciclo_combinado[1];
                *carbon_0 = enero_2020.carbon[0];
                *carbon_1 = enero_2020.carbon[1];
                *cogeneracion_0 = enero_2020.cogeneracion[0];
                *cogeneracion_1 = enero_2020.cogeneracion[1];
                *residuos_no_renovables_0 = enero_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = enero_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = enero_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = enero_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = enero_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = enero_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = enero_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = enero_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = enero_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = enero_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = enero_2020.Demanda[0];
                *Demanda_1 = enero_2020.Demanda[1];
            }

            fclose(plectura_2020_enero);
        }

        if (mes_void == 2)
        {
            FILE *plectura_2020_febrero;
            plectura_2020_febrero = fopen("Ficheros_Comparaciones/2020/2020_febrero.csv", "r");
            if (plectura_2020_febrero == NULL)
            {
                printf("Error al abrir el fichero de lectura (02/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (02/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes febrero_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_febrero, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &febrero_2020.hidraulica [i], &febrero_2020.eolica [i], &febrero_2020.solar_fotovoltaica [i], &febrero_2020.solar_termica [i], &febrero_2020.otras_renovables [i], &febrero_2020.residuos_renovables [i], &febrero_2020.Generacion_Renovable [i], &febrero_2020.turbinacion_bombeo [i], &febrero_2020.nuclear [i], &febrero_2020.ciclo_combinado [i], &febrero_2020.carbon [i],&febrero_2020.cogeneracion [i], &febrero_2020.residuos_no_renovables [i], &febrero_2020.Generacion_No_Renovable [i], &febrero_2020.consumos_en_bombeo [i], &febrero_2020.enlace_peninsula_baleares [i], &febrero_2020.saldo_intercambios_internacionales [i], &febrero_2020.Demanda [i]);
                }

                printf("                           Febrero 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",febrero_2020.hidraulica[0], febrero_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",febrero_2020.eolica[0], febrero_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",febrero_2020.solar_fotovoltaica[0], febrero_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",febrero_2020.solar_termica[0], febrero_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",febrero_2020.otras_renovables[0], febrero_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",febrero_2020.residuos_renovables[0], febrero_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",febrero_2020.Generacion_Renovable[0], febrero_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",febrero_2020.turbinacion_bombeo[0], febrero_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",febrero_2020.nuclear[0], febrero_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",febrero_2020.ciclo_combinado[0], febrero_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",febrero_2020.carbon[0], febrero_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",febrero_2020.cogeneracion[0], febrero_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",febrero_2020.residuos_no_renovables[0], febrero_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",febrero_2020.Generacion_No_Renovable[0], febrero_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",febrero_2020.consumos_en_bombeo[0], febrero_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",febrero_2020.enlace_peninsula_baleares[0], febrero_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",febrero_2020.saldo_intercambios_internacionales[0], febrero_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",febrero_2020.Demanda[0], febrero_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = febrero_2020.hidraulica[0];
                *hidraulica_1 = febrero_2020.hidraulica[1];
                *eolica_0 = febrero_2020.eolica[0];
                *eolica_1 = febrero_2020.eolica[1];
                *solar_fotovoltaica_0 = febrero_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = febrero_2020.solar_fotovoltaica[1];
                *solar_termica_0 = febrero_2020.solar_termica[0];
                *solar_termica_1 = febrero_2020.solar_termica[1];
                *otras_renovables_0 = febrero_2020.otras_renovables[0];
                *otras_renovables_1 = febrero_2020.otras_renovables[1];
                *residuos_renovables_0 = febrero_2020.residuos_renovables[0];
                *residuos_renovables_1 = febrero_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = febrero_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = febrero_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = febrero_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = febrero_2020.turbinacion_bombeo[1];
                *nuclear_0 = febrero_2020.nuclear[0];
                *nuclear_1 = febrero_2020.nuclear[1];
                *ciclo_combinado_0 = febrero_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = febrero_2020.ciclo_combinado[1];
                *carbon_0 = febrero_2020.carbon[0];
                *carbon_1 = febrero_2020.carbon[1];
                *cogeneracion_0 = febrero_2020.cogeneracion[0];
                *cogeneracion_1 = febrero_2020.cogeneracion[1];
                *residuos_no_renovables_0 = febrero_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = febrero_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = febrero_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = febrero_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = febrero_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = febrero_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = febrero_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = febrero_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = febrero_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = febrero_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = febrero_2020.Demanda[0];
                *Demanda_1 = febrero_2020.Demanda[1];
            }

            fclose(plectura_2020_febrero);
        }

        if (mes_void == 3)
        {
            FILE *plectura_2020_marzo;
            plectura_2020_marzo = fopen("Ficheros_Comparaciones/2020/2020_marzo.csv", "r");
            if (plectura_2020_marzo == NULL)
            {
                printf("Error al abrir el fichero de lectura (03/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (03/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes marzo_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_marzo, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &marzo_2020.hidraulica [i], &marzo_2020.eolica [i], &marzo_2020.solar_fotovoltaica [i], &marzo_2020.solar_termica [i], &marzo_2020.otras_renovables [i], &marzo_2020.residuos_renovables [i], &marzo_2020.Generacion_Renovable [i], &marzo_2020.turbinacion_bombeo [i], &marzo_2020.nuclear [i], &marzo_2020.ciclo_combinado [i], &marzo_2020.carbon [i],&marzo_2020.cogeneracion [i], &marzo_2020.residuos_no_renovables [i], &marzo_2020.Generacion_No_Renovable [i], &marzo_2020.consumos_en_bombeo [i], &marzo_2020.enlace_peninsula_baleares [i], &marzo_2020.saldo_intercambios_internacionales [i], &marzo_2020.Demanda [i]);
                }

                printf("                           Marzo 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",marzo_2020.hidraulica[0], marzo_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",marzo_2020.eolica[0], marzo_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",marzo_2020.solar_fotovoltaica[0], marzo_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",marzo_2020.solar_termica[0], marzo_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",marzo_2020.otras_renovables[0], marzo_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",marzo_2020.residuos_renovables[0], marzo_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",marzo_2020.Generacion_Renovable[0], marzo_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",marzo_2020.turbinacion_bombeo[0], marzo_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",marzo_2020.nuclear[0], marzo_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",marzo_2020.ciclo_combinado[0], marzo_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",marzo_2020.carbon[0], marzo_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",marzo_2020.cogeneracion[0], marzo_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",marzo_2020.residuos_no_renovables[0], marzo_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",marzo_2020.  Generacion_No_Renovable[0], marzo_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",marzo_2020.consumos_en_bombeo[0], marzo_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",marzo_2020.enlace_peninsula_baleares[0], marzo_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",marzo_2020.saldo_intercambios_internacionales[0], marzo_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",marzo_2020.Demanda[0], marzo_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = marzo_2020.hidraulica[0];
                *hidraulica_1 = marzo_2020.hidraulica[1];
                *eolica_0 = marzo_2020.eolica[0];
                *eolica_1 = marzo_2020.eolica[1];
                *solar_fotovoltaica_0 = marzo_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = marzo_2020.solar_fotovoltaica[1];
                *solar_termica_0 = marzo_2020.solar_termica[0];
                *solar_termica_1 = marzo_2020.solar_termica[1];
                *otras_renovables_0 = marzo_2020.otras_renovables[0];
                *otras_renovables_1 = marzo_2020.otras_renovables[1];
                *residuos_renovables_0 = marzo_2020.residuos_renovables[0];
                *residuos_renovables_1 = marzo_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = marzo_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = marzo_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = marzo_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = marzo_2020.turbinacion_bombeo[1];
                *nuclear_0 = marzo_2020.nuclear[0];
                *nuclear_1 = marzo_2020.nuclear[1];
                *ciclo_combinado_0 = marzo_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = marzo_2020.ciclo_combinado[1];
                *carbon_0 = marzo_2020.carbon[0];
                *carbon_1 = marzo_2020.carbon[1];
                *cogeneracion_0 = marzo_2020.cogeneracion[0];
                *cogeneracion_1 = marzo_2020.cogeneracion[1];
                *residuos_no_renovables_0 = marzo_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = marzo_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = marzo_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = marzo_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = marzo_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = marzo_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = marzo_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = marzo_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = marzo_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = marzo_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = marzo_2020.Demanda[0];
                *Demanda_1 = marzo_2020.Demanda[1];
            }

            fclose(plectura_2020_marzo);
        }

        if (mes_void == 4)
        {
            FILE *plectura_2020_abril;
            plectura_2020_abril = fopen("Ficheros_Comparaciones/2020/2020_abril.csv.txt", "r");
            if (plectura_2020_abril == NULL)
            {
                printf("Error al abrir el fichero de lectura (04/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (04/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes abril_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_abril, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &abril_2020.hidraulica [i], &abril_2020.eolica [i], &abril_2020.solar_fotovoltaica [i], &abril_2020.solar_termica [i], &abril_2020.otras_renovables [i], &abril_2020.residuos_renovables [i], &abril_2020.Generacion_Renovable [i], &abril_2020.turbinacion_bombeo [i], &abril_2020.nuclear [i], &abril_2020.ciclo_combinado [i], &abril_2020.carbon [i],&abril_2020.cogeneracion [i], &abril_2020.residuos_no_renovables [i], &abril_2020.Generacion_No_Renovable [i], &abril_2020.consumos_en_bombeo [i], &abril_2020.enlace_peninsula_baleares [i], &abril_2020.saldo_intercambios_internacionales [i], &abril_2020.Demanda [i]);
                }

                printf("                           Abril 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",abril_2020.hidraulica[0], abril_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",abril_2020.eolica[0], abril_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",abril_2020.solar_fotovoltaica[0], abril_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",abril_2020.solar_termica[0], abril_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",abril_2020.otras_renovables[0], abril_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",abril_2020.residuos_renovables[0], abril_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",abril_2020.Generacion_Renovable[0], abril_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",abril_2020.turbinacion_bombeo[0], abril_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",abril_2020.nuclear[0], abril_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",abril_2020.ciclo_combinado[0], abril_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",abril_2020.carbon[0], abril_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",abril_2020.cogeneracion[0], abril_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",abril_2020.residuos_no_renovables[0], abril_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",abril_2020.  Generacion_No_Renovable[0], abril_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",abril_2020.consumos_en_bombeo[0], abril_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",abril_2020.enlace_peninsula_baleares[0], abril_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",abril_2020.saldo_intercambios_internacionales[0], abril_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",abril_2020.Demanda[0], abril_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = abril_2020.hidraulica[0];
                *hidraulica_1 = abril_2020.hidraulica[1];
                *eolica_0 = abril_2020.eolica[0];
                *eolica_1 = abril_2020.eolica[1];
                *solar_fotovoltaica_0 = abril_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = abril_2020.solar_fotovoltaica[1];
                *solar_termica_0 = abril_2020.solar_termica[0];
                *solar_termica_1 = abril_2020.solar_termica[1];
                *otras_renovables_0 = abril_2020.otras_renovables[0];
                *otras_renovables_1 = abril_2020.otras_renovables[1];
                *residuos_renovables_0 = abril_2020.residuos_renovables[0];
                *residuos_renovables_1 = abril_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = abril_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = abril_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = abril_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = abril_2020.turbinacion_bombeo[1];
                *nuclear_0 = abril_2020.nuclear[0];
                *nuclear_1 = abril_2020.nuclear[1];
                *ciclo_combinado_0 = abril_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = abril_2020.ciclo_combinado[1];
                *carbon_0 = abril_2020.carbon[0];
                *carbon_1 = abril_2020.carbon[1];
                *cogeneracion_0 = abril_2020.cogeneracion[0];
                *cogeneracion_1 = abril_2020.cogeneracion[1];
                *residuos_no_renovables_0 = abril_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = abril_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = abril_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = abril_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = abril_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = abril_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = abril_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = abril_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = abril_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = abril_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = abril_2020.Demanda[0];
                *Demanda_1 = abril_2020.Demanda[1]; 
            }

            fclose(plectura_2020_abril);
        }

        if (mes_void == 5)
        {
            FILE *plectura_2020_mayo;
            plectura_2020_mayo= fopen("Ficheros_Comparaciones/2020/2020_mayo.csv", "r");
            if (plectura_2020_mayo == NULL)
            {
                printf("Error al abrir el fichero de lectura (05/2020).\n");
            }
            else
            {
                printf("Fichero de lectura (05/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes mayo_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_mayo, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &mayo_2020.hidraulica [i], &mayo_2020.eolica [i], &mayo_2020.solar_fotovoltaica [i], &mayo_2020.solar_termica [i], &mayo_2020.otras_renovables [i], &mayo_2020.residuos_renovables [i], &mayo_2020.Generacion_Renovable [i], &mayo_2020.turbinacion_bombeo [i], &mayo_2020.nuclear [i], &mayo_2020.ciclo_combinado [i], &mayo_2020.carbon [i],&mayo_2020.cogeneracion [i], &mayo_2020.residuos_no_renovables [i], &mayo_2020.Generacion_No_Renovable [i], &mayo_2020.consumos_en_bombeo [i], &mayo_2020.enlace_peninsula_baleares [i], &mayo_2020.saldo_intercambios_internacionales [i], &mayo_2020.Demanda [i]);
                }

                printf("                           Mayo 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",mayo_2020.hidraulica[0], mayo_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",mayo_2020.eolica[0], mayo_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",mayo_2020.solar_fotovoltaica[0], mayo_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",mayo_2020.solar_termica[0], mayo_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",mayo_2020.otras_renovables[0], mayo_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",mayo_2020.residuos_renovables[0], mayo_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",mayo_2020.Generacion_Renovable[0], mayo_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",mayo_2020.turbinacion_bombeo[0], mayo_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",mayo_2020.nuclear[0], mayo_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",mayo_2020.ciclo_combinado[0], mayo_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",mayo_2020.carbon[0], mayo_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",mayo_2020.cogeneracion[0], mayo_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",mayo_2020.residuos_no_renovables[0], mayo_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",mayo_2020.Generacion_No_Renovable[0], mayo_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",mayo_2020.consumos_en_bombeo[0], mayo_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",mayo_2020.enlace_peninsula_baleares[0], mayo_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",mayo_2020.saldo_intercambios_internacionales[0], mayo_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",mayo_2020.Demanda[0], mayo_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = mayo_2020.hidraulica[0];
                *hidraulica_1 = mayo_2020.hidraulica[1];
                *eolica_0 = mayo_2020.eolica[0];
                *eolica_1 = mayo_2020.eolica[1];
                *solar_fotovoltaica_0 = mayo_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = mayo_2020.solar_fotovoltaica[1];
                *solar_termica_0 = mayo_2020.solar_termica[0];
                *solar_termica_1 = mayo_2020.solar_termica[1];
                *otras_renovables_0 = mayo_2020.otras_renovables[0];
                *otras_renovables_1 = mayo_2020.otras_renovables[1];
                *residuos_renovables_0 = mayo_2020.residuos_renovables[0];
                *residuos_renovables_1 = mayo_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = mayo_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = mayo_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = mayo_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = mayo_2020.turbinacion_bombeo[1];
                *nuclear_0 = mayo_2020.nuclear[0];
                *nuclear_1 = mayo_2020.nuclear[1];
                *ciclo_combinado_0 = mayo_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = mayo_2020.ciclo_combinado[1];
                *carbon_0 = mayo_2020.carbon[0];
                *carbon_1 = mayo_2020.carbon[1];
                *cogeneracion_0 = mayo_2020.cogeneracion[0];
                *cogeneracion_1 = mayo_2020.cogeneracion[1];
                *residuos_no_renovables_0 = mayo_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = mayo_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = mayo_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = mayo_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = mayo_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = mayo_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = mayo_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = mayo_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = mayo_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = mayo_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = mayo_2020.Demanda[0];
                *Demanda_1 = mayo_2020.Demanda[1];
            }

            fclose(plectura_2020_mayo);
        }

        if (mes_void == 6)
        {
            FILE *plectura_2020_junio;
            plectura_2020_junio = fopen("Ficheros_Comparaciones/2020/2020_junio.csv", "r");
            if (plectura_2020_junio == NULL)
            {
                printf("Error al abrir el fichero de lectura (06/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (06/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes junio_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_junio, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &junio_2020.hidraulica [i], &junio_2020.eolica [i], &junio_2020.solar_fotovoltaica [i], &junio_2020.solar_termica [i], &junio_2020.otras_renovables [i], &junio_2020.residuos_renovables [i], &junio_2020.Generacion_Renovable [i], &junio_2020.turbinacion_bombeo [i], &junio_2020.nuclear [i], &junio_2020.ciclo_combinado [i], &junio_2020.carbon [i],&junio_2020.cogeneracion [i], &junio_2020.residuos_no_renovables [i], &junio_2020.Generacion_No_Renovable [i], &junio_2020.consumos_en_bombeo [i], &junio_2020.enlace_peninsula_baleares [i], &junio_2020.saldo_intercambios_internacionales [i], &junio_2020.Demanda [i]);
                }

                printf("                           Junio 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",junio_2020.hidraulica[0], junio_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",junio_2020.eolica[0], junio_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",junio_2020.solar_fotovoltaica[0], junio_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",junio_2020.solar_termica[0], junio_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",junio_2020.otras_renovables[0], junio_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",junio_2020.residuos_renovables[0], junio_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",junio_2020.Generacion_Renovable[0], junio_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",junio_2020.turbinacion_bombeo[0], junio_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",junio_2020.nuclear[0], junio_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",junio_2020.ciclo_combinado[0], junio_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",junio_2020.carbon[0],junio_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",junio_2020.cogeneracion[0], junio_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",junio_2020.residuos_no_renovables[0], junio_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",junio_2020.Generacion_No_Renovable[0], junio_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",junio_2020.consumos_en_bombeo[0], junio_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",junio_2020.enlace_peninsula_baleares[0], junio_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",junio_2020.saldo_intercambios_internacionales[0], junio_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",junio_2020.Demanda[0], junio_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = junio_2020.hidraulica[0];
                *hidraulica_1 = junio_2020.hidraulica[1];
                *eolica_0 = junio_2020.eolica[0];
                *eolica_1 = junio_2020.eolica[1];
                *solar_fotovoltaica_0 = junio_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = junio_2020.solar_fotovoltaica[1];
                *solar_termica_0 = junio_2020.solar_termica[0];
                *solar_termica_1 = junio_2020.solar_termica[1];
                *otras_renovables_0 = junio_2020.otras_renovables[0];
                *otras_renovables_1 = junio_2020.otras_renovables[1];
                *residuos_renovables_0 = junio_2020.residuos_renovables[0];
                *residuos_renovables_1 = junio_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = junio_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = junio_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = junio_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = junio_2020.turbinacion_bombeo[1];
                *nuclear_0 = junio_2020.nuclear[0];
                *nuclear_1 = junio_2020.nuclear[1];
                *ciclo_combinado_0 = junio_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = junio_2020.ciclo_combinado[1];
                *carbon_0 = junio_2020.carbon[0];
                *carbon_1 = junio_2020.carbon[1];
                *cogeneracion_0 = junio_2020.cogeneracion[0];
                *cogeneracion_1 = junio_2020.cogeneracion[1];
                *residuos_no_renovables_0 = junio_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = junio_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = junio_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = junio_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = junio_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = junio_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = junio_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = junio_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = junio_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = junio_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = junio_2020.Demanda[0];
                *Demanda_1 = junio_2020.Demanda[1];  
            }

            fclose(plectura_2020_junio);
        }

        if (mes_void == 7)
        {
            FILE *plectura_2020_julio;
            plectura_2020_julio = fopen("Ficheros_Comparaciones/2020/2020_julio.csv", "r");
            if (plectura_2020_julio == NULL)
            {
                printf("Error al abrir el fichero de lectura (07/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (07/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes julio_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_julio, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &julio_2020.hidraulica [i], &julio_2020.eolica [i], &julio_2020.solar_fotovoltaica [i], &julio_2020.solar_termica [i], &julio_2020.otras_renovables [i], &julio_2020.residuos_renovables [i], &julio_2020.Generacion_Renovable [i], &julio_2020.turbinacion_bombeo [i], &julio_2020.nuclear [i], &julio_2020.ciclo_combinado [i], &julio_2020.carbon [i],&julio_2020.cogeneracion [i], &julio_2020.residuos_no_renovables [i], &julio_2020.Generacion_No_Renovable [i], &julio_2020.consumos_en_bombeo [i], &julio_2020.enlace_peninsula_baleares [i], &julio_2020.saldo_intercambios_internacionales [i], &julio_2020.Demanda [i]);
                }

                printf("                           Julio 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",julio_2020.hidraulica[0], julio_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",julio_2020.eolica[0], julio_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",julio_2020.solar_fotovoltaica[0], julio_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",julio_2020.solar_termica[0], julio_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",julio_2020.otras_renovables[0], julio_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",julio_2020.residuos_renovables[0], julio_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",julio_2020.Generacion_Renovable[0], julio_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",julio_2020.turbinacion_bombeo[0], julio_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",julio_2020.nuclear[0], julio_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",julio_2020.ciclo_combinado[0], julio_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",julio_2020.carbon[0],julio_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",julio_2020.cogeneracion[0], julio_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",julio_2020.residuos_no_renovables[0], julio_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",julio_2020.Generacion_No_Renovable[0], julio_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",julio_2020.consumos_en_bombeo[0], julio_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",julio_2020.enlace_peninsula_baleares[0], julio_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",julio_2020.saldo_intercambios_internacionales[0], julio_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",julio_2020.Demanda[0], julio_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = julio_2020.hidraulica[0];
                *hidraulica_1 = julio_2020.hidraulica[1];
                *eolica_0 = julio_2020.eolica[0];
                *eolica_1 = julio_2020.eolica[1];
                *solar_fotovoltaica_0 = julio_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = julio_2020.solar_fotovoltaica[1];
                *solar_termica_0 = julio_2020.solar_termica[0];
                *solar_termica_1 = julio_2020.solar_termica[1];
                *otras_renovables_0 = julio_2020.otras_renovables[0];
                *otras_renovables_1 = julio_2020.otras_renovables[1];
                *residuos_renovables_0 = julio_2020.residuos_renovables[0];
                *residuos_renovables_1 = julio_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = julio_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = julio_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = julio_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = julio_2020.turbinacion_bombeo[1];
                *nuclear_0 = julio_2020.nuclear[0];
                *nuclear_1 = julio_2020.nuclear[1];
                *ciclo_combinado_0 = julio_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = julio_2020.ciclo_combinado[1];
                *carbon_0 = julio_2020.carbon[0];
                *carbon_1 = julio_2020.carbon[1];
                *cogeneracion_0 = julio_2020.cogeneracion[0];
                *cogeneracion_1 = julio_2020.cogeneracion[1];
                *residuos_no_renovables_0 = julio_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = julio_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = julio_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = julio_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = julio_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = julio_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = julio_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = julio_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = julio_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = julio_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = julio_2020.Demanda[0];
                *Demanda_1 = julio_2020.Demanda[1];
            }

            fclose(plectura_2020_julio);
        }

        if (mes_void == 8)
        {
            FILE *plectura_2020_agosto;
            plectura_2020_agosto = fopen("Ficheros_Comparaciones/2020/2020_agosto.csv", "r");
            if (plectura_2020_agosto == NULL)
            {
                printf("Error al abrir el fichero de lectura (08/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (08/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes agosto_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_agosto, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &agosto_2020.hidraulica [i], &agosto_2020.eolica [i], &agosto_2020.solar_fotovoltaica [i], &agosto_2020.solar_termica [i], &agosto_2020.otras_renovables [i], &agosto_2020.residuos_renovables [i], &agosto_2020.Generacion_Renovable [i], &agosto_2020.turbinacion_bombeo [i], &agosto_2020.nuclear [i], &agosto_2020.ciclo_combinado [i], &agosto_2020.carbon [i],&agosto_2020.cogeneracion [i], &agosto_2020.residuos_no_renovables [i], &agosto_2020.Generacion_No_Renovable [i], &agosto_2020.consumos_en_bombeo [i], &agosto_2020.enlace_peninsula_baleares [i], &agosto_2020.saldo_intercambios_internacionales [i], &agosto_2020.Demanda [i]);
                }

                printf("                           Agosto 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",agosto_2020.hidraulica[0], agosto_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",agosto_2020.eolica[0], agosto_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",agosto_2020.solar_fotovoltaica[0], agosto_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",agosto_2020.solar_termica[0], agosto_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",agosto_2020.otras_renovables[0], agosto_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",agosto_2020.residuos_renovables[0], agosto_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",agosto_2020.Generacion_Renovable[0], agosto_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",agosto_2020.turbinacion_bombeo[0], agosto_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",agosto_2020.nuclear[0], agosto_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",agosto_2020.ciclo_combinado[0], agosto_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",agosto_2020.carbon[0],agosto_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",agosto_2020.cogeneracion[0], agosto_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",agosto_2020.residuos_no_renovables[0], agosto_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",agosto_2020.Generacion_No_Renovable[0], agosto_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",agosto_2020.consumos_en_bombeo[0], agosto_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",agosto_2020.enlace_peninsula_baleares[0], agosto_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",agosto_2020.saldo_intercambios_internacionales[0], agosto_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",agosto_2020.Demanda[0], agosto_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = agosto_2020.hidraulica[0];
                *hidraulica_1 = agosto_2020.hidraulica[1];
                *eolica_0 = agosto_2020.eolica[0];
                *eolica_1 = agosto_2020.eolica[1];
                *solar_fotovoltaica_0 = agosto_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = agosto_2020.solar_fotovoltaica[1];
                *solar_termica_0 = agosto_2020.solar_termica[0];
                *solar_termica_1 = agosto_2020.solar_termica[1];
                *otras_renovables_0 = agosto_2020.otras_renovables[0];
                *otras_renovables_1 = agosto_2020.otras_renovables[1];
                *residuos_renovables_0 = agosto_2020.residuos_renovables[0];
                *residuos_renovables_1 = agosto_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = agosto_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = agosto_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = agosto_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = agosto_2020.turbinacion_bombeo[1];
                *nuclear_0 = agosto_2020.nuclear[0];
                *nuclear_1 = agosto_2020.nuclear[1];
                *ciclo_combinado_0 = agosto_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = agosto_2020.ciclo_combinado[1];
                *carbon_0 = agosto_2020.carbon[0];
                *carbon_1 = agosto_2020.carbon[1];
                *cogeneracion_0 = agosto_2020.cogeneracion[0];
                *cogeneracion_1 = agosto_2020.cogeneracion[1];
                *residuos_no_renovables_0 = agosto_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = agosto_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = agosto_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = agosto_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = agosto_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = agosto_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = agosto_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = agosto_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = agosto_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = agosto_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = agosto_2020.Demanda[0];
                *Demanda_1 = agosto_2020.Demanda[1];
            }

            fclose(plectura_2020_agosto);
        }

        if (mes_void == 9)
        {
            FILE *plectura_2020_septiembre;
            plectura_2020_septiembre = fopen("Ficheros_Comparaciones/2020/2020_septiembre.csv", "r");
            if (plectura_2020_septiembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (09/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (09/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes septiembre_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_septiembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &septiembre_2020.hidraulica [i], &septiembre_2020.eolica [i], &septiembre_2020.solar_fotovoltaica [i], &septiembre_2020.solar_termica [i], &septiembre_2020.otras_renovables [i], &septiembre_2020.residuos_renovables [i], &septiembre_2020.Generacion_Renovable [i], &septiembre_2020.turbinacion_bombeo [i], &septiembre_2020.nuclear [i], &septiembre_2020.ciclo_combinado [i], &septiembre_2020.carbon [i],&septiembre_2020.cogeneracion [i], &septiembre_2020.residuos_no_renovables [i], &septiembre_2020.Generacion_No_Renovable [i], &septiembre_2020.consumos_en_bombeo [i], &septiembre_2020.enlace_peninsula_baleares [i], &septiembre_2020.saldo_intercambios_internacionales [i], &septiembre_2020.Demanda [i]);
                }

                printf("                           Septiembre 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",septiembre_2020.hidraulica[0], septiembre_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",septiembre_2020.eolica[0], septiembre_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",septiembre_2020.solar_fotovoltaica[0], septiembre_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",septiembre_2020.solar_termica[0], septiembre_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",septiembre_2020.otras_renovables[0], septiembre_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",septiembre_2020.residuos_renovables[0], septiembre_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",septiembre_2020.Generacion_Renovable[0], septiembre_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",septiembre_2020.turbinacion_bombeo[0], septiembre_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",septiembre_2020.nuclear[0], septiembre_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",septiembre_2020.ciclo_combinado[0], septiembre_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",septiembre_2020.carbon[0],septiembre_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",septiembre_2020.cogeneracion[0], septiembre_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",septiembre_2020.residuos_no_renovables[0], septiembre_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",septiembre_2020.Generacion_No_Renovable[0], septiembre_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",septiembre_2020.consumos_en_bombeo[0], septiembre_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",septiembre_2020.enlace_peninsula_baleares[0], septiembre_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",septiembre_2020.saldo_intercambios_internacionales[0], septiembre_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",septiembre_2020.Demanda[0], septiembre_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = septiembre_2020.hidraulica[0];
                *hidraulica_1 = septiembre_2020.hidraulica[1];
                *eolica_0 = septiembre_2020.eolica[0];
                *eolica_1 = septiembre_2020.eolica[1];
                *solar_fotovoltaica_0 = septiembre_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = septiembre_2020.solar_fotovoltaica[1];
                *solar_termica_0 = septiembre_2020.solar_termica[0];
                *solar_termica_1 = septiembre_2020.solar_termica[1];
                *otras_renovables_0 = septiembre_2020.otras_renovables[0];
                *otras_renovables_1 = septiembre_2020.otras_renovables[1];
                *residuos_renovables_0 = septiembre_2020.residuos_renovables[0];
                *residuos_renovables_1 = septiembre_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = septiembre_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = septiembre_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = septiembre_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = septiembre_2020.turbinacion_bombeo[1];
                *nuclear_0 = septiembre_2020.nuclear[0];
                *nuclear_1 = septiembre_2020.nuclear[1];
                *ciclo_combinado_0 = septiembre_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = septiembre_2020.ciclo_combinado[1];
                *carbon_0 = septiembre_2020.carbon[0];
                *carbon_1 = septiembre_2020.carbon[1];
                *cogeneracion_0 = septiembre_2020.cogeneracion[0];
                *cogeneracion_1 = septiembre_2020.cogeneracion[1];
                *residuos_no_renovables_0 = septiembre_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = septiembre_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = septiembre_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = septiembre_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = septiembre_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = septiembre_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = septiembre_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = septiembre_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = septiembre_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = septiembre_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = septiembre_2020.Demanda[0];
                *Demanda_1 = septiembre_2020.Demanda[1];
            }

            fclose(plectura_2020_septiembre);
        }

        if (mes_void == 10)
        {
            FILE *plectura_2020_octubre;
            plectura_2020_octubre = fopen("Ficheros_Comparaciones/2020/2020_octubre.csv", "r");
            if (plectura_2020_octubre == NULL)
            {
                printf("Error al abrir el fichero de lectura (10/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (10/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes octubre_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_octubre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &octubre_2020.hidraulica [i], &octubre_2020.eolica [i], &octubre_2020.solar_fotovoltaica [i], &octubre_2020.solar_termica [i], &octubre_2020.otras_renovables [i], &octubre_2020.residuos_renovables [i], &octubre_2020.Generacion_Renovable [i], &octubre_2020.turbinacion_bombeo [i], &octubre_2020.nuclear [i], &octubre_2020.ciclo_combinado [i], &octubre_2020.carbon [i],&octubre_2020.cogeneracion [i], &octubre_2020.residuos_no_renovables [i], &octubre_2020.Generacion_No_Renovable [i], &octubre_2020.consumos_en_bombeo [i], &octubre_2020.enlace_peninsula_baleares [i], &octubre_2020.saldo_intercambios_internacionales [i], &octubre_2020.Demanda [i]);
                }

                printf("                           Octubre 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",octubre_2020.hidraulica[0], octubre_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",octubre_2020.eolica[0], octubre_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",octubre_2020.solar_fotovoltaica[0], octubre_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",octubre_2020.solar_termica[0], octubre_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",octubre_2020.otras_renovables[0], octubre_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",octubre_2020.residuos_renovables[0], octubre_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",octubre_2020.Generacion_Renovable[0], octubre_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",octubre_2020.turbinacion_bombeo[0], octubre_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",octubre_2020.nuclear[0], octubre_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",octubre_2020.ciclo_combinado[0], octubre_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",octubre_2020.carbon[0],octubre_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",octubre_2020.cogeneracion[0], octubre_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",octubre_2020.residuos_no_renovables[0], octubre_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",octubre_2020.Generacion_No_Renovable[0], octubre_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",octubre_2020.consumos_en_bombeo[0], octubre_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",octubre_2020.enlace_peninsula_baleares[0], octubre_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",octubre_2020.saldo_intercambios_internacionales[0], octubre_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",octubre_2020.Demanda[0], octubre_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = octubre_2020.hidraulica[0];
                *hidraulica_1 = octubre_2020.hidraulica[1];
                *eolica_0 = octubre_2020.eolica[0];
                *eolica_1 = octubre_2020.eolica[1];
                *solar_fotovoltaica_0 = octubre_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = octubre_2020.solar_fotovoltaica[1];
                *solar_termica_0 = octubre_2020.solar_termica[0];
                *solar_termica_1 = octubre_2020.solar_termica[1];
                *otras_renovables_0 = octubre_2020.otras_renovables[0];
                *otras_renovables_1 = octubre_2020.otras_renovables[1];
                *residuos_renovables_0 = octubre_2020.residuos_renovables[0];
                *residuos_renovables_1 = octubre_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = octubre_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = octubre_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = octubre_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = octubre_2020.turbinacion_bombeo[1];
                *nuclear_0 = octubre_2020.nuclear[0];
                *nuclear_1 = octubre_2020.nuclear[1];
                *ciclo_combinado_0 = octubre_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = octubre_2020.ciclo_combinado[1];
                *carbon_0 = octubre_2020.carbon[0];
                *carbon_1 = octubre_2020.carbon[1];
                *cogeneracion_0 = octubre_2020.cogeneracion[0];
                *cogeneracion_1 = octubre_2020.cogeneracion[1];
                *residuos_no_renovables_0 = octubre_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = octubre_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = octubre_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = octubre_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = octubre_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = octubre_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = octubre_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = octubre_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = octubre_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = octubre_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = octubre_2020.Demanda[0];
                *Demanda_1 = octubre_2020.Demanda[1];
            }

            fclose(plectura_2020_octubre);
        }

        if (mes_void == 11)
        {
            FILE *plectura_2020_noviembre;
            plectura_2020_noviembre = fopen("Ficheros_Comparaciones/2020/2020_noviembre.csv", "r");
            if (plectura_2020_noviembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (11/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (11/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes noviembre_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_noviembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &noviembre_2020.hidraulica [i], &noviembre_2020.eolica [i], &noviembre_2020.solar_fotovoltaica [i], &noviembre_2020.solar_termica [i], &noviembre_2020.otras_renovables [i], &noviembre_2020.residuos_renovables [i], &noviembre_2020.Generacion_Renovable [i], &noviembre_2020.turbinacion_bombeo [i], &noviembre_2020.nuclear [i], &noviembre_2020.ciclo_combinado [i], &noviembre_2020.carbon [i],&noviembre_2020.cogeneracion [i], &noviembre_2020.residuos_no_renovables [i], &noviembre_2020.Generacion_No_Renovable [i], &noviembre_2020.consumos_en_bombeo [i], &noviembre_2020.enlace_peninsula_baleares [i], &noviembre_2020.saldo_intercambios_internacionales [i], &noviembre_2020.Demanda [i]);
                }

                printf("                           Noviembre 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",noviembre_2020.hidraulica[0], noviembre_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",noviembre_2020.eolica[0], noviembre_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",noviembre_2020.solar_fotovoltaica[0], noviembre_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",noviembre_2020.solar_termica[0], noviembre_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",noviembre_2020.otras_renovables[0], noviembre_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",noviembre_2020.residuos_renovables[0], noviembre_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",noviembre_2020.Generacion_Renovable[0], noviembre_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",noviembre_2020.turbinacion_bombeo[0], noviembre_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",noviembre_2020.nuclear[0], noviembre_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",noviembre_2020.ciclo_combinado[0], noviembre_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",noviembre_2020.carbon[0],noviembre_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",noviembre_2020.cogeneracion[0], noviembre_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",noviembre_2020.residuos_no_renovables[0], noviembre_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",noviembre_2020.Generacion_No_Renovable[0], noviembre_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",noviembre_2020.consumos_en_bombeo[0], noviembre_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",noviembre_2020.enlace_peninsula_baleares[0], noviembre_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",noviembre_2020.saldo_intercambios_internacionales[0], noviembre_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",noviembre_2020.Demanda[0], noviembre_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = noviembre_2020.hidraulica[0];
                *hidraulica_1 = noviembre_2020.hidraulica[1];
                *eolica_0 = noviembre_2020.eolica[0];
                *eolica_1 = noviembre_2020.eolica[1];
                *solar_fotovoltaica_0 = noviembre_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = noviembre_2020.solar_fotovoltaica[1];
                *solar_termica_0 = noviembre_2020.solar_termica[0];
                *solar_termica_1 = noviembre_2020.solar_termica[1];
                *otras_renovables_0 = noviembre_2020.otras_renovables[0];
                *otras_renovables_1 = noviembre_2020.otras_renovables[1];
                *residuos_renovables_0 = noviembre_2020.residuos_renovables[0];
                *residuos_renovables_1 = noviembre_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = noviembre_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = noviembre_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = noviembre_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = noviembre_2020.turbinacion_bombeo[1];
                *nuclear_0 = noviembre_2020.nuclear[0];
                *nuclear_1 = noviembre_2020.nuclear[1];
                *ciclo_combinado_0 = noviembre_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = noviembre_2020.ciclo_combinado[1];
                *carbon_0 = noviembre_2020.carbon[0];
                *carbon_1 = noviembre_2020.carbon[1];
                *cogeneracion_0 = noviembre_2020.cogeneracion[0];
                *cogeneracion_1 = noviembre_2020.cogeneracion[1];
                *residuos_no_renovables_0 = noviembre_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = noviembre_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = noviembre_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = noviembre_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = noviembre_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = noviembre_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = noviembre_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = noviembre_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = noviembre_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = noviembre_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = noviembre_2020.Demanda[0];
                *Demanda_1 = noviembre_2020.Demanda[1];
            }

            fclose(plectura_2020_noviembre);
        }

        if (mes_void == 12)
        {
            FILE *plectura_2020_diciembre;
            plectura_2020_diciembre = fopen("Ficheros_Comparaciones/2020/2020_diciembre.csv", "r");
            if (plectura_2020_diciembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (12/2020).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (12/2020) abierto correctamente.\n");
                printf("\n");

                datos_mes diciembre_2020;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2020_diciembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &diciembre_2020.hidraulica [i], &diciembre_2020.eolica [i], &diciembre_2020.solar_fotovoltaica [i], &diciembre_2020.solar_termica [i], &diciembre_2020.otras_renovables [i], &diciembre_2020.residuos_renovables [i], &diciembre_2020.Generacion_Renovable [i], &diciembre_2020.turbinacion_bombeo [i], &diciembre_2020.nuclear [i], &diciembre_2020.ciclo_combinado [i], &diciembre_2020.carbon [i],&diciembre_2020.cogeneracion [i], &diciembre_2020.residuos_no_renovables [i], &diciembre_2020.Generacion_No_Renovable [i], &diciembre_2020.consumos_en_bombeo [i], &diciembre_2020.enlace_peninsula_baleares [i], &diciembre_2020.saldo_intercambios_internacionales [i], &diciembre_2020.Demanda [i]);
                }

                printf("                           Diciembre 2020 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",diciembre_2020.hidraulica[0], diciembre_2020.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",diciembre_2020.eolica[0], diciembre_2020.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",diciembre_2020.solar_fotovoltaica[0], diciembre_2020.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",diciembre_2020.solar_termica[0], diciembre_2020.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",diciembre_2020.otras_renovables[0], diciembre_2020.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",diciembre_2020.residuos_renovables[0], diciembre_2020.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",diciembre_2020.Generacion_Renovable[0], diciembre_2020.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",diciembre_2020.turbinacion_bombeo[0], diciembre_2020.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",diciembre_2020.nuclear[0], diciembre_2020.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",diciembre_2020.ciclo_combinado[0], diciembre_2020.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",diciembre_2020.carbon[0],diciembre_2020.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",diciembre_2020.cogeneracion[0], diciembre_2020.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",diciembre_2020.residuos_no_renovables[0], diciembre_2020.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",diciembre_2020.Generacion_No_Renovable[0], diciembre_2020.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",diciembre_2020.consumos_en_bombeo[0], diciembre_2020.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",diciembre_2020.enlace_peninsula_baleares[0], diciembre_2020.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",diciembre_2020.saldo_intercambios_internacionales[0], diciembre_2020.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",diciembre_2020.Demanda[0], diciembre_2020.Demanda[1]);
                printf("\n");

                *hidraulica_0 = diciembre_2020.hidraulica[0];
                *hidraulica_1 = diciembre_2020.hidraulica[1];
                *eolica_0 = diciembre_2020.eolica[0];
                *eolica_1 = diciembre_2020.eolica[1];
                *solar_fotovoltaica_0 = diciembre_2020.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = diciembre_2020.solar_fotovoltaica[1];
                *solar_termica_0 = diciembre_2020.solar_termica[0];
                *solar_termica_1 = diciembre_2020.solar_termica[1];
                *otras_renovables_0 = diciembre_2020.otras_renovables[0];
                *otras_renovables_1 = diciembre_2020.otras_renovables[1];
                *residuos_renovables_0 = diciembre_2020.residuos_renovables[0];
                *residuos_renovables_1 = diciembre_2020.residuos_renovables[1];
                *Generacion_Renovable_0 = diciembre_2020.Generacion_Renovable[0];
                *Generacion_Renovable_1 = diciembre_2020.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = diciembre_2020.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = diciembre_2020.turbinacion_bombeo[1];
                *nuclear_0 = diciembre_2020.nuclear[0];
                *nuclear_1 = diciembre_2020.nuclear[1];
                *ciclo_combinado_0 = diciembre_2020.ciclo_combinado[0];
                *ciclo_combinado_1 = diciembre_2020.ciclo_combinado[1];
                *carbon_0 = diciembre_2020.carbon[0];
                *carbon_1 = diciembre_2020.carbon[1];
                *cogeneracion_0 = diciembre_2020.cogeneracion[0];
                *cogeneracion_1 = diciembre_2020.cogeneracion[1];
                *residuos_no_renovables_0 = diciembre_2020.residuos_no_renovables[0];
                *residuos_no_renovables_1 = diciembre_2020.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = diciembre_2020.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = diciembre_2020.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = diciembre_2020.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = diciembre_2020.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = diciembre_2020.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = diciembre_2020.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = diciembre_2020.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = diciembre_2020.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = diciembre_2020.Demanda[0];
                *Demanda_1 = diciembre_2020.Demanda[1];
            }

            fclose(plectura_2020_diciembre);
        }
    }

    if (anio_mes_void == 2021)
    {
        if (mes_void == 1)
        {
            FILE *plectura_2021_enero;
            plectura_2021_enero = fopen("Ficheros_Comparaciones/2021/2021_enero.csv", "r");
            if (plectura_2021_enero == NULL)
            {
                printf("Error al abrir el fichero de lectura (01/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (01/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes enero_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_enero, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &enero_2021.hidraulica [i], &enero_2021.eolica [i], &enero_2021.solar_fotovoltaica [i], &enero_2021.solar_termica [i], &enero_2021.otras_renovables [i], &enero_2021.residuos_renovables [i], &enero_2021.Generacion_Renovable [i], &enero_2021.turbinacion_bombeo [i], &enero_2021.nuclear [i], &enero_2021.ciclo_combinado [i], &enero_2021.carbon [i],&enero_2021.cogeneracion [i], &enero_2021.residuos_no_renovables [i], &enero_2021.Generacion_No_Renovable [i], &enero_2021.consumos_en_bombeo [i], &enero_2021.enlace_peninsula_baleares [i], &enero_2021.saldo_intercambios_internacionales [i], &enero_2021.Demanda [i]);
                }

                printf("                           Enero 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",enero_2021.hidraulica[0], enero_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",enero_2021.eolica[0], enero_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",enero_2021.solar_fotovoltaica[0], enero_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",enero_2021.solar_termica[0], enero_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",enero_2021.otras_renovables[0], enero_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",enero_2021.residuos_renovables[0], enero_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",enero_2021.Generacion_Renovable[0], enero_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",enero_2021.turbinacion_bombeo[0], enero_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",enero_2021.nuclear[0], enero_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",enero_2021.ciclo_combinado[0], enero_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",enero_2021.carbon[0], enero_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",enero_2021.cogeneracion[0], enero_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",enero_2021.residuos_no_renovables[0], enero_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",enero_2021.Generacion_No_Renovable[0], enero_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",enero_2021.consumos_en_bombeo[0], enero_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",enero_2021.enlace_peninsula_baleares[0], enero_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",enero_2021.saldo_intercambios_internacionales[0], enero_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",enero_2021.Demanda[0], enero_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = enero_2021.hidraulica[0];
                *hidraulica_1 = enero_2021.hidraulica[1];
                *eolica_0 = enero_2021.eolica[0];
                *eolica_1 = enero_2021.eolica[1];
                *solar_fotovoltaica_0 = enero_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = enero_2021.solar_fotovoltaica[1];
                *solar_termica_0 = enero_2021.solar_termica[0];
                *solar_termica_1 = enero_2021.solar_termica[1];
                *otras_renovables_0 = enero_2021.otras_renovables[0];
                *otras_renovables_1 = enero_2021.otras_renovables[1];
                *residuos_renovables_0 = enero_2021.residuos_renovables[0];
                *residuos_renovables_1 = enero_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = enero_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = enero_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = enero_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = enero_2021.turbinacion_bombeo[1];
                *nuclear_0 = enero_2021.nuclear[0];
                *nuclear_1 = enero_2021.nuclear[1];
                *ciclo_combinado_0 = enero_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = enero_2021.ciclo_combinado[1];
                *carbon_0 = enero_2021.carbon[0];
                *carbon_1 = enero_2021.carbon[1];
                *cogeneracion_0 = enero_2021.cogeneracion[0];
                *cogeneracion_1 = enero_2021.cogeneracion[1];
                *residuos_no_renovables_0 = enero_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = enero_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = enero_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = enero_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = enero_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = enero_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = enero_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = enero_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = enero_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = enero_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = enero_2021.Demanda[0];
                *Demanda_1 = enero_2021.Demanda[1];
            }

            fclose(plectura_2021_enero);
        }

        if (mes_void == 2)
        {
            FILE *plectura_2021_febrero;
            plectura_2021_febrero = fopen("Ficheros_Comparaciones/2021/2021_febrero.csv", "r");
            if (plectura_2021_febrero == NULL)
            {
                printf("Error al abrir el fichero de lectura (02/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (02/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes febrero_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_febrero, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &febrero_2021.hidraulica [i], &febrero_2021.eolica [i], &febrero_2021.solar_fotovoltaica [i], &febrero_2021.solar_termica [i], &febrero_2021.otras_renovables [i], &febrero_2021.residuos_renovables [i], &febrero_2021.Generacion_Renovable [i], &febrero_2021.turbinacion_bombeo [i], &febrero_2021.nuclear [i], &febrero_2021.ciclo_combinado [i], &febrero_2021.carbon [i],&febrero_2021.cogeneracion [i], &febrero_2021.residuos_no_renovables [i], &febrero_2021.Generacion_No_Renovable [i], &febrero_2021.consumos_en_bombeo [i], &febrero_2021.enlace_peninsula_baleares [i], &febrero_2021.saldo_intercambios_internacionales [i], &febrero_2021.Demanda [i]);
                }

                printf("                           Febrero 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",febrero_2021.hidraulica[0], febrero_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",febrero_2021.eolica[0], febrero_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",febrero_2021.solar_fotovoltaica[0], febrero_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",febrero_2021.solar_termica[0], febrero_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",febrero_2021.otras_renovables[0], febrero_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",febrero_2021.residuos_renovables[0], febrero_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",febrero_2021.Generacion_Renovable[0], febrero_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",febrero_2021.turbinacion_bombeo[0], febrero_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",febrero_2021.nuclear[0], febrero_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",febrero_2021.ciclo_combinado[0], febrero_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",febrero_2021.carbon[0], febrero_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",febrero_2021.cogeneracion[0], febrero_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",febrero_2021.residuos_no_renovables[0], febrero_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",febrero_2021.Generacion_No_Renovable[0], febrero_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",febrero_2021.consumos_en_bombeo[0], febrero_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",febrero_2021.enlace_peninsula_baleares[0], febrero_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",febrero_2021.saldo_intercambios_internacionales[0], febrero_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",febrero_2021.Demanda[0], febrero_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = febrero_2021.hidraulica[0];
                *hidraulica_1 = febrero_2021.hidraulica[1];
                *eolica_0 = febrero_2021.eolica[0];
                *eolica_1 = febrero_2021.eolica[1];
                *solar_fotovoltaica_0 = febrero_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = febrero_2021.solar_fotovoltaica[1];
                *solar_termica_0 = febrero_2021.solar_termica[0];
                *solar_termica_1 = febrero_2021.solar_termica[1];
                *otras_renovables_0 = febrero_2021.otras_renovables[0];
                *otras_renovables_1 = febrero_2021.otras_renovables[1];
                *residuos_renovables_0 = febrero_2021.residuos_renovables[0];
                *residuos_renovables_1 = febrero_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = febrero_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = febrero_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = febrero_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = febrero_2021.turbinacion_bombeo[1];
                *nuclear_0 = febrero_2021.nuclear[0];
                *nuclear_1 = febrero_2021.nuclear[1];
                *ciclo_combinado_0 = febrero_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = febrero_2021.ciclo_combinado[1];
                *carbon_0 = febrero_2021.carbon[0];
                *carbon_1 = febrero_2021.carbon[1];
                *cogeneracion_0 = febrero_2021.cogeneracion[0];
                *cogeneracion_1 = febrero_2021.cogeneracion[1];
                *residuos_no_renovables_0 = febrero_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = febrero_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = febrero_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = febrero_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = febrero_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = febrero_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = febrero_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = febrero_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = febrero_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = febrero_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = febrero_2021.Demanda[0];
                *Demanda_1 = febrero_2021.Demanda[1];
            }

            fclose(plectura_2021_febrero);
        }

        if (mes_void == 3)
        {
            FILE *plectura_2021_marzo;
            plectura_2021_marzo = fopen("Ficheros_Comparaciones/2021/2021_marzo.csv", "r");
            if (plectura_2021_marzo == NULL)
            {
                printf("Error al abrir el fichero de lectura (03/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (03/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes marzo_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_marzo, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &marzo_2021.hidraulica [i], &marzo_2021.eolica [i], &marzo_2021.solar_fotovoltaica [i], &marzo_2021.solar_termica [i], &marzo_2021.otras_renovables [i], &marzo_2021.residuos_renovables [i], &marzo_2021.Generacion_Renovable [i], &marzo_2021.turbinacion_bombeo [i], &marzo_2021.nuclear [i], &marzo_2021.ciclo_combinado [i], &marzo_2021.carbon [i],&marzo_2021.cogeneracion [i], &marzo_2021.residuos_no_renovables [i], &marzo_2021.Generacion_No_Renovable [i], &marzo_2021.consumos_en_bombeo [i], &marzo_2021.enlace_peninsula_baleares [i], &marzo_2021.saldo_intercambios_internacionales [i], &marzo_2021.Demanda [i]);
                }

                printf("                           Marzo 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",marzo_2021.hidraulica[0], marzo_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",marzo_2021.eolica[0], marzo_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",marzo_2021.solar_fotovoltaica[0], marzo_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",marzo_2021.solar_termica[0], marzo_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",marzo_2021.otras_renovables[0], marzo_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",marzo_2021.residuos_renovables[0], marzo_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",marzo_2021.Generacion_Renovable[0], marzo_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",marzo_2021.turbinacion_bombeo[0], marzo_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",marzo_2021.nuclear[0], marzo_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",marzo_2021.ciclo_combinado[0], marzo_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",marzo_2021.carbon[0], marzo_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",marzo_2021.cogeneracion[0], marzo_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",marzo_2021.residuos_no_renovables[0], marzo_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",marzo_2021.  Generacion_No_Renovable[0], marzo_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",marzo_2021.consumos_en_bombeo[0], marzo_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",marzo_2021.enlace_peninsula_baleares[0], marzo_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",marzo_2021.saldo_intercambios_internacionales[0], marzo_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",marzo_2021.Demanda[0], marzo_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = marzo_2021.hidraulica[0];
                *hidraulica_1 = marzo_2021.hidraulica[1];
                *eolica_0 = marzo_2021.eolica[0];
                *eolica_1 = marzo_2021.eolica[1];
                *solar_fotovoltaica_0 = marzo_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = marzo_2021.solar_fotovoltaica[1];
                *solar_termica_0 = marzo_2021.solar_termica[0];
                *solar_termica_1 = marzo_2021.solar_termica[1];
                *otras_renovables_0 = marzo_2021.otras_renovables[0];
                *otras_renovables_1 = marzo_2021.otras_renovables[1];
                *residuos_renovables_0 = marzo_2021.residuos_renovables[0];
                *residuos_renovables_1 = marzo_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = marzo_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = marzo_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = marzo_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = marzo_2021.turbinacion_bombeo[1];
                *nuclear_0 = marzo_2021.nuclear[0];
                *nuclear_1 = marzo_2021.nuclear[1];
                *ciclo_combinado_0 = marzo_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = marzo_2021.ciclo_combinado[1];
                *carbon_0 = marzo_2021.carbon[0];
                *carbon_1 = marzo_2021.carbon[1];
                *cogeneracion_0 = marzo_2021.cogeneracion[0];
                *cogeneracion_1 = marzo_2021.cogeneracion[1];
                *residuos_no_renovables_0 = marzo_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = marzo_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = marzo_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = marzo_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = marzo_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = marzo_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = marzo_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = marzo_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = marzo_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = marzo_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = marzo_2021.Demanda[0];
                *Demanda_1 = marzo_2021.Demanda[1];
            }

            fclose(plectura_2021_marzo);
        }

        if (mes_void == 4)
        {
            FILE *plectura_2021_abril;
            plectura_2021_abril = fopen("Ficheros_Comparaciones/2021/2021_abril.csv", "r");
            if (plectura_2021_abril == NULL)
            {
                printf("Error al abrir el fichero de lectura (04/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (04/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes abril_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_abril, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &abril_2021.hidraulica [i], &abril_2021.eolica [i], &abril_2021.solar_fotovoltaica [i], &abril_2021.solar_termica [i], &abril_2021.otras_renovables [i], &abril_2021.residuos_renovables [i], &abril_2021.Generacion_Renovable [i], &abril_2021.turbinacion_bombeo [i], &abril_2021.nuclear [i], &abril_2021.ciclo_combinado [i], &abril_2021.carbon [i],&abril_2021.cogeneracion [i], &abril_2021.residuos_no_renovables [i], &abril_2021.Generacion_No_Renovable [i], &abril_2021.consumos_en_bombeo [i], &abril_2021.enlace_peninsula_baleares [i], &abril_2021.saldo_intercambios_internacionales [i], &abril_2021.Demanda [i]);
                }

                printf("                           Abril 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",abril_2021.hidraulica[0], abril_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",abril_2021.eolica[0], abril_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",abril_2021.solar_fotovoltaica[0], abril_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",abril_2021.solar_termica[0], abril_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",abril_2021.otras_renovables[0], abril_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",abril_2021.residuos_renovables[0], abril_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",abril_2021.Generacion_Renovable[0], abril_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",abril_2021.turbinacion_bombeo[0], abril_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",abril_2021.nuclear[0], abril_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",abril_2021.ciclo_combinado[0], abril_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",abril_2021.carbon[0], abril_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",abril_2021.cogeneracion[0], abril_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",abril_2021.residuos_no_renovables[0], abril_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",abril_2021.  Generacion_No_Renovable[0], abril_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",abril_2021.consumos_en_bombeo[0], abril_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",abril_2021.enlace_peninsula_baleares[0], abril_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",abril_2021.saldo_intercambios_internacionales[0], abril_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",abril_2021.Demanda[0], abril_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = abril_2021.hidraulica[0];
                *hidraulica_1 = abril_2021.hidraulica[1];
                *eolica_0 = abril_2021.eolica[0];
                *eolica_1 = abril_2021.eolica[1];
                *solar_fotovoltaica_0 = abril_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = abril_2021.solar_fotovoltaica[1];
                *solar_termica_0 = abril_2021.solar_termica[0];
                *solar_termica_1 = abril_2021.solar_termica[1];
                *otras_renovables_0 = abril_2021.otras_renovables[0];
                *otras_renovables_1 = abril_2021.otras_renovables[1];
                *residuos_renovables_0 = abril_2021.residuos_renovables[0];
                *residuos_renovables_1 = abril_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = abril_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = abril_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = abril_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = abril_2021.turbinacion_bombeo[1];
                *nuclear_0 = abril_2021.nuclear[0];
                *nuclear_1 = abril_2021.nuclear[1];
                *ciclo_combinado_0 = abril_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = abril_2021.ciclo_combinado[1];
                *carbon_0 = abril_2021.carbon[0];
                *carbon_1 = abril_2021.carbon[1];
                *cogeneracion_0 = abril_2021.cogeneracion[0];
                *cogeneracion_1 = abril_2021.cogeneracion[1];
                *residuos_no_renovables_0 = abril_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = abril_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = abril_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = abril_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = abril_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = abril_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = abril_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = abril_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = abril_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = abril_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = abril_2021.Demanda[0];
                *Demanda_1 = abril_2021.Demanda[1]; 
            }

            fclose(plectura_2021_abril);
        }

        if (mes_void == 5)
        {
            FILE *plectura_2021_mayo;
            plectura_2021_mayo= fopen("Ficheros_Comparaciones/2021/2021_mayo.csv", "r");
            if (plectura_2021_mayo == NULL)
            {
                printf("Error al abrir el fichero de lectura (05/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (05/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes mayo_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_mayo, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &mayo_2021.hidraulica [i], &mayo_2021.eolica [i], &mayo_2021.solar_fotovoltaica [i], &mayo_2021.solar_termica [i], &mayo_2021.otras_renovables [i], &mayo_2021.residuos_renovables [i], &mayo_2021.Generacion_Renovable [i], &mayo_2021.turbinacion_bombeo [i], &mayo_2021.nuclear [i], &mayo_2021.ciclo_combinado [i], &mayo_2021.carbon [i],&mayo_2021.cogeneracion [i], &mayo_2021.residuos_no_renovables [i], &mayo_2021.Generacion_No_Renovable [i], &mayo_2021.consumos_en_bombeo [i], &mayo_2021.enlace_peninsula_baleares [i], &mayo_2021.saldo_intercambios_internacionales [i], &mayo_2021.Demanda [i]);
                }

                printf("                           Mayo 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",mayo_2021.hidraulica[0], mayo_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",mayo_2021.eolica[0], mayo_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",mayo_2021.solar_fotovoltaica[0], mayo_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",mayo_2021.solar_termica[0], mayo_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",mayo_2021.otras_renovables[0], mayo_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",mayo_2021.residuos_renovables[0], mayo_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",mayo_2021.Generacion_Renovable[0], mayo_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",mayo_2021.turbinacion_bombeo[0], mayo_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",mayo_2021.nuclear[0], mayo_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",mayo_2021.ciclo_combinado[0], mayo_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",mayo_2021.carbon[0], mayo_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",mayo_2021.cogeneracion[0], mayo_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",mayo_2021.residuos_no_renovables[0], mayo_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",mayo_2021.Generacion_No_Renovable[0], mayo_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",mayo_2021.consumos_en_bombeo[0], mayo_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",mayo_2021.enlace_peninsula_baleares[0], mayo_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",mayo_2021.saldo_intercambios_internacionales[0], mayo_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",mayo_2021.Demanda[0], mayo_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = mayo_2021.hidraulica[0];
                *hidraulica_1 = mayo_2021.hidraulica[1];
                *eolica_0 = mayo_2021.eolica[0];
                *eolica_1 = mayo_2021.eolica[1];
                *solar_fotovoltaica_0 = mayo_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = mayo_2021.solar_fotovoltaica[1];
                *solar_termica_0 = mayo_2021.solar_termica[0];
                *solar_termica_1 = mayo_2021.solar_termica[1];
                *otras_renovables_0 = mayo_2021.otras_renovables[0];
                *otras_renovables_1 = mayo_2021.otras_renovables[1];
                *residuos_renovables_0 = mayo_2021.residuos_renovables[0];
                *residuos_renovables_1 = mayo_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = mayo_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = mayo_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = mayo_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = mayo_2021.turbinacion_bombeo[1];
                *nuclear_0 = mayo_2021.nuclear[0];
                *nuclear_1 = mayo_2021.nuclear[1];
                *ciclo_combinado_0 = mayo_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = mayo_2021.ciclo_combinado[1];
                *carbon_0 = mayo_2021.carbon[0];
                *carbon_1 = mayo_2021.carbon[1];
                *cogeneracion_0 = mayo_2021.cogeneracion[0];
                *cogeneracion_1 = mayo_2021.cogeneracion[1];
                *residuos_no_renovables_0 = mayo_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = mayo_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = mayo_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = mayo_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = mayo_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = mayo_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = mayo_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = mayo_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = mayo_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = mayo_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = mayo_2021.Demanda[0];
                *Demanda_1 = mayo_2021.Demanda[1];
            }

            fclose(plectura_2021_mayo);
        }

        if (mes_void == 6)
        {
            FILE *plectura_2021_junio;
            plectura_2021_junio = fopen("Ficheros_Comparaciones/2021/2021_junio.csv", "r");
            if (plectura_2021_junio == NULL)
            {
                printf("Error al abrir el fichero de lectura (06/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (06/2021) abierto correctamente.\n");
                printf("\n");

                 datos_mes junio_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_junio, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &junio_2021.hidraulica [i], &junio_2021.eolica [i], &junio_2021.solar_fotovoltaica [i], &junio_2021.solar_termica [i], &junio_2021.otras_renovables [i], &junio_2021.residuos_renovables [i], &junio_2021.Generacion_Renovable [i], &junio_2021.turbinacion_bombeo [i], &junio_2021.nuclear [i], &junio_2021.ciclo_combinado [i], &junio_2021.carbon [i],&junio_2021.cogeneracion [i], &junio_2021.residuos_no_renovables [i], &junio_2021.Generacion_No_Renovable [i], &junio_2021.consumos_en_bombeo [i], &junio_2021.enlace_peninsula_baleares [i], &junio_2021.saldo_intercambios_internacionales [i], &junio_2021.Demanda [i]);
                }

                printf("                           Junio 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",junio_2021.hidraulica[0], junio_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",junio_2021.eolica[0], junio_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",junio_2021.solar_fotovoltaica[0], junio_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",junio_2021.solar_termica[0], junio_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",junio_2021.otras_renovables[0], junio_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",junio_2021.residuos_renovables[0], junio_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",junio_2021.Generacion_Renovable[0], junio_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",junio_2021.turbinacion_bombeo[0], junio_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",junio_2021.nuclear[0], junio_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",junio_2021.ciclo_combinado[0], junio_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",junio_2021.carbon[0],junio_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",junio_2021.cogeneracion[0], junio_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",junio_2021.residuos_no_renovables[0], junio_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",junio_2021.Generacion_No_Renovable[0], junio_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",junio_2021.consumos_en_bombeo[0], junio_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",junio_2021.enlace_peninsula_baleares[0], junio_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",junio_2021.saldo_intercambios_internacionales[0], junio_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",junio_2021.Demanda[0], junio_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = junio_2021.hidraulica[0];
                *hidraulica_1 = junio_2021.hidraulica[1];
                *eolica_0 = junio_2021.eolica[0];
                *eolica_1 = junio_2021.eolica[1];
                *solar_fotovoltaica_0 = junio_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = junio_2021.solar_fotovoltaica[1];
                *solar_termica_0 = junio_2021.solar_termica[0];
                *solar_termica_1 = junio_2021.solar_termica[1];
                *otras_renovables_0 = junio_2021.otras_renovables[0];
                *otras_renovables_1 = junio_2021.otras_renovables[1];
                *residuos_renovables_0 = junio_2021.residuos_renovables[0];
                *residuos_renovables_1 = junio_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = junio_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = junio_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = junio_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = junio_2021.turbinacion_bombeo[1];
                *nuclear_0 = junio_2021.nuclear[0];
                *nuclear_1 = junio_2021.nuclear[1];
                *ciclo_combinado_0 = junio_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = junio_2021.ciclo_combinado[1];
                *carbon_0 = junio_2021.carbon[0];
                *carbon_1 = junio_2021.carbon[1];
                *cogeneracion_0 = junio_2021.cogeneracion[0];
                *cogeneracion_1 = junio_2021.cogeneracion[1];
                *residuos_no_renovables_0 = junio_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = junio_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = junio_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = junio_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = junio_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = junio_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = junio_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = junio_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = junio_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = junio_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = junio_2021.Demanda[0];
                *Demanda_1 = junio_2021.Demanda[1];
            }

            fclose(plectura_2021_junio);
        }

        if (mes_void == 7)
        {
            FILE *plectura_2021_julio;
            plectura_2021_julio = fopen("Ficheros_Comparaciones/2021/2021_julio.csv", "r");
            if (plectura_2021_julio == NULL)
            {
                printf("Error al abrir el fichero de lectura (07/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (07/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes julio_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_julio, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &julio_2021.hidraulica [i], &julio_2021.eolica [i], &julio_2021.solar_fotovoltaica [i], &julio_2021.solar_termica [i], &julio_2021.otras_renovables [i], &julio_2021.residuos_renovables [i], &julio_2021.Generacion_Renovable [i], &julio_2021.turbinacion_bombeo [i], &julio_2021.nuclear [i], &julio_2021.ciclo_combinado [i], &julio_2021.carbon [i],&julio_2021.cogeneracion [i], &julio_2021.residuos_no_renovables [i], &julio_2021.Generacion_No_Renovable [i], &julio_2021.consumos_en_bombeo [i], &julio_2021.enlace_peninsula_baleares [i], &julio_2021.saldo_intercambios_internacionales [i], &julio_2021.Demanda [i]);
                }

                printf("                           Julio 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",julio_2021.hidraulica[0], julio_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",julio_2021.eolica[0], julio_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",julio_2021.solar_fotovoltaica[0], julio_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",julio_2021.solar_termica[0], julio_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",julio_2021.otras_renovables[0], julio_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",julio_2021.residuos_renovables[0], julio_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",julio_2021.Generacion_Renovable[0], julio_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",julio_2021.turbinacion_bombeo[0], julio_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",julio_2021.nuclear[0], julio_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",julio_2021.ciclo_combinado[0], julio_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",julio_2021.carbon[0],julio_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",julio_2021.cogeneracion[0], julio_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",julio_2021.residuos_no_renovables[0], julio_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",julio_2021.Generacion_No_Renovable[0], julio_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",julio_2021.consumos_en_bombeo[0], julio_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",julio_2021.enlace_peninsula_baleares[0], julio_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",julio_2021.saldo_intercambios_internacionales[0], julio_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",julio_2021.Demanda[0], julio_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = julio_2021.hidraulica[0];
                *hidraulica_1 = julio_2021.hidraulica[1];
                *eolica_0 = julio_2021.eolica[0];
                *eolica_1 = julio_2021.eolica[1];
                *solar_fotovoltaica_0 = julio_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = julio_2021.solar_fotovoltaica[1];
                *solar_termica_0 = julio_2021.solar_termica[0];
                *solar_termica_1 = julio_2021.solar_termica[1];
                *otras_renovables_0 = julio_2021.otras_renovables[0];
                *otras_renovables_1 = julio_2021.otras_renovables[1];
                *residuos_renovables_0 = julio_2021.residuos_renovables[0];
                *residuos_renovables_1 = julio_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = julio_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = julio_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = julio_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = julio_2021.turbinacion_bombeo[1];
                *nuclear_0 = julio_2021.nuclear[0];
                *nuclear_1 = julio_2021.nuclear[1];
                *ciclo_combinado_0 = julio_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = julio_2021.ciclo_combinado[1];
                *carbon_0 = julio_2021.carbon[0];
                *carbon_1 = julio_2021.carbon[1];
                *cogeneracion_0 = julio_2021.cogeneracion[0];
                *cogeneracion_1 = julio_2021.cogeneracion[1];
                *residuos_no_renovables_0 = julio_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = julio_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = julio_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = julio_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = julio_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = julio_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = julio_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = julio_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = julio_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = julio_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = julio_2021.Demanda[0];
                *Demanda_1 = julio_2021.Demanda[1];
            }

            fclose(plectura_2021_julio);
        }

        if (mes_void == 8)
        {
            FILE *plectura_2021_agosto;
            plectura_2021_agosto = fopen("Ficheros_Comparaciones/2021/2021_agosto.csv", "r");
            if (plectura_2021_agosto == NULL)
            {
                printf("Error al abrir el fichero de lectura (08/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (08/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes agosto_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_agosto, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &agosto_2021.hidraulica [i], &agosto_2021.eolica [i], &agosto_2021.solar_fotovoltaica [i], &agosto_2021.solar_termica [i], &agosto_2021.otras_renovables [i], &agosto_2021.residuos_renovables [i], &agosto_2021.Generacion_Renovable [i], &agosto_2021.turbinacion_bombeo [i], &agosto_2021.nuclear [i], &agosto_2021.ciclo_combinado [i], &agosto_2021.carbon [i],&agosto_2021.cogeneracion [i], &agosto_2021.residuos_no_renovables [i], &agosto_2021.Generacion_No_Renovable [i], &agosto_2021.consumos_en_bombeo [i], &agosto_2021.enlace_peninsula_baleares [i], &agosto_2021.saldo_intercambios_internacionales [i], &agosto_2021.Demanda [i]);
                }

                printf("                           Agosto 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",agosto_2021.hidraulica[0], agosto_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",agosto_2021.eolica[0], agosto_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",agosto_2021.solar_fotovoltaica[0], agosto_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",agosto_2021.solar_termica[0], agosto_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",agosto_2021.otras_renovables[0], agosto_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",agosto_2021.residuos_renovables[0], agosto_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",agosto_2021.Generacion_Renovable[0], agosto_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",agosto_2021.turbinacion_bombeo[0], agosto_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",agosto_2021.nuclear[0], agosto_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",agosto_2021.ciclo_combinado[0], agosto_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",agosto_2021.carbon[0],agosto_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",agosto_2021.cogeneracion[0], agosto_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",agosto_2021.residuos_no_renovables[0], agosto_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",agosto_2021.Generacion_No_Renovable[0], agosto_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",agosto_2021.consumos_en_bombeo[0], agosto_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",agosto_2021.enlace_peninsula_baleares[0], agosto_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",agosto_2021.saldo_intercambios_internacionales[0], agosto_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",agosto_2021.Demanda[0], agosto_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = agosto_2021.hidraulica[0];
                *hidraulica_1 = agosto_2021.hidraulica[1];
                *eolica_0 = agosto_2021.eolica[0];
                *eolica_1 = agosto_2021.eolica[1];
                *solar_fotovoltaica_0 = agosto_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = agosto_2021.solar_fotovoltaica[1];
                *solar_termica_0 = agosto_2021.solar_termica[0];
                *solar_termica_1 = agosto_2021.solar_termica[1];
                *otras_renovables_0 = agosto_2021.otras_renovables[0];
                *otras_renovables_1 = agosto_2021.otras_renovables[1];
                *residuos_renovables_0 = agosto_2021.residuos_renovables[0];
                *residuos_renovables_1 = agosto_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = agosto_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = agosto_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = agosto_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = agosto_2021.turbinacion_bombeo[1];
                *nuclear_0 = agosto_2021.nuclear[0];
                *nuclear_1 = agosto_2021.nuclear[1];
                *ciclo_combinado_0 = agosto_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = agosto_2021.ciclo_combinado[1];
                *carbon_0 = agosto_2021.carbon[0];
                *carbon_1 = agosto_2021.carbon[1];
                *cogeneracion_0 = agosto_2021.cogeneracion[0];
                *cogeneracion_1 = agosto_2021.cogeneracion[1];
                *residuos_no_renovables_0 = agosto_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = agosto_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = agosto_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = agosto_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = agosto_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = agosto_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = agosto_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = agosto_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = agosto_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = agosto_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = agosto_2021.Demanda[0];
                *Demanda_1 = agosto_2021.Demanda[1];
            }

            fclose(plectura_2021_agosto);
        }

        if (mes_void == 9)
        {
            FILE *plectura_2021_septiembre;
            plectura_2021_septiembre = fopen("Ficheros_Comparaciones/2021/2021_septiembre.csv", "r");
            if (plectura_2021_septiembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (09/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (09/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes septiembre_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_septiembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &septiembre_2021.hidraulica [i], &septiembre_2021.eolica [i], &septiembre_2021.solar_fotovoltaica [i], &septiembre_2021.solar_termica [i], &septiembre_2021.otras_renovables [i], &septiembre_2021.residuos_renovables [i], &septiembre_2021.Generacion_Renovable [i], &septiembre_2021.turbinacion_bombeo [i], &septiembre_2021.nuclear [i], &septiembre_2021.ciclo_combinado [i], &septiembre_2021.carbon [i],&septiembre_2021.cogeneracion [i], &septiembre_2021.residuos_no_renovables [i], &septiembre_2021.Generacion_No_Renovable [i], &septiembre_2021.consumos_en_bombeo [i], &septiembre_2021.enlace_peninsula_baleares [i], &septiembre_2021.saldo_intercambios_internacionales [i], &septiembre_2021.Demanda [i]);
                }

                printf("                           Septiembre 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",septiembre_2021.hidraulica[0], septiembre_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",septiembre_2021.eolica[0], septiembre_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",septiembre_2021.solar_fotovoltaica[0], septiembre_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",septiembre_2021.solar_termica[0], septiembre_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",septiembre_2021.otras_renovables[0], septiembre_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",septiembre_2021.residuos_renovables[0], septiembre_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",septiembre_2021.Generacion_Renovable[0], septiembre_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",septiembre_2021.turbinacion_bombeo[0], septiembre_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",septiembre_2021.nuclear[0], septiembre_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",septiembre_2021.ciclo_combinado[0], septiembre_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",septiembre_2021.carbon[0],septiembre_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",septiembre_2021.cogeneracion[0], septiembre_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",septiembre_2021.residuos_no_renovables[0], septiembre_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",septiembre_2021.Generacion_No_Renovable[0], septiembre_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",septiembre_2021.consumos_en_bombeo[0], septiembre_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",septiembre_2021.enlace_peninsula_baleares[0], septiembre_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",septiembre_2021.saldo_intercambios_internacionales[0], septiembre_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",septiembre_2021.Demanda[0], septiembre_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = septiembre_2021.hidraulica[0];
                *hidraulica_1 = septiembre_2021.hidraulica[1];
                *eolica_0 = septiembre_2021.eolica[0];
                *eolica_1 = septiembre_2021.eolica[1];
                *solar_fotovoltaica_0 = septiembre_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = septiembre_2021.solar_fotovoltaica[1];
                *solar_termica_0 = septiembre_2021.solar_termica[0];
                *solar_termica_1 = septiembre_2021.solar_termica[1];
                *otras_renovables_0 = septiembre_2021.otras_renovables[0];
                *otras_renovables_1 = septiembre_2021.otras_renovables[1];
                *residuos_renovables_0 = septiembre_2021.residuos_renovables[0];
                *residuos_renovables_1 = septiembre_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = septiembre_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = septiembre_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = septiembre_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = septiembre_2021.turbinacion_bombeo[1];
                *nuclear_0 = septiembre_2021.nuclear[0];
                *nuclear_1 = septiembre_2021.nuclear[1];
                *ciclo_combinado_0 = septiembre_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = septiembre_2021.ciclo_combinado[1];
                *carbon_0 = septiembre_2021.carbon[0];
                *carbon_1 = septiembre_2021.carbon[1];
                *cogeneracion_0 = septiembre_2021.cogeneracion[0];
                *cogeneracion_1 = septiembre_2021.cogeneracion[1];
                *residuos_no_renovables_0 = septiembre_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = septiembre_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = septiembre_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = septiembre_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = septiembre_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = septiembre_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = septiembre_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = septiembre_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = septiembre_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = septiembre_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = septiembre_2021.Demanda[0];
                *Demanda_1 = septiembre_2021.Demanda[1];
            }

            fclose(plectura_2021_septiembre);
        }

        if (mes_void == 10)
        {
            FILE *plectura_2021_octubre;
            plectura_2021_octubre = fopen("Ficheros_Comparaciones/2021/2021_octubre.csv", "r");
            if (plectura_2021_octubre == NULL)
            {
                printf("Error al abrir el fichero de lectura (10/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (10/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes octubre_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_octubre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &octubre_2021.hidraulica [i], &octubre_2021.eolica [i], &octubre_2021.solar_fotovoltaica [i], &octubre_2021.solar_termica [i], &octubre_2021.otras_renovables [i], &octubre_2021.residuos_renovables [i], &octubre_2021.Generacion_Renovable [i], &octubre_2021.turbinacion_bombeo [i], &octubre_2021.nuclear [i], &octubre_2021.ciclo_combinado [i], &octubre_2021.carbon [i],&octubre_2021.cogeneracion [i], &octubre_2021.residuos_no_renovables [i], &octubre_2021.Generacion_No_Renovable [i], &octubre_2021.consumos_en_bombeo [i], &octubre_2021.enlace_peninsula_baleares [i], &octubre_2021.saldo_intercambios_internacionales [i], &octubre_2021.Demanda [i]);
                }

                printf("                           Octubre 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",octubre_2021.hidraulica[0], octubre_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",octubre_2021.eolica[0], octubre_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",octubre_2021.solar_fotovoltaica[0], octubre_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",octubre_2021.solar_termica[0], octubre_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",octubre_2021.otras_renovables[0], octubre_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",octubre_2021.residuos_renovables[0], octubre_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",octubre_2021.Generacion_Renovable[0], octubre_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",octubre_2021.turbinacion_bombeo[0], octubre_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",octubre_2021.nuclear[0], octubre_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",octubre_2021.ciclo_combinado[0], octubre_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",octubre_2021.carbon[0],octubre_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",octubre_2021.cogeneracion[0], octubre_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",octubre_2021.residuos_no_renovables[0], octubre_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",octubre_2021.Generacion_No_Renovable[0], octubre_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",octubre_2021.consumos_en_bombeo[0], octubre_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",octubre_2021.enlace_peninsula_baleares[0], octubre_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",octubre_2021.saldo_intercambios_internacionales[0], octubre_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",octubre_2021.Demanda[0], octubre_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = octubre_2021.hidraulica[0];
                *hidraulica_1 = octubre_2021.hidraulica[1];
                *eolica_0 = octubre_2021.eolica[0];
                *eolica_1 = octubre_2021.eolica[1];
                *solar_fotovoltaica_0 = octubre_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = octubre_2021.solar_fotovoltaica[1];
                *solar_termica_0 = octubre_2021.solar_termica[0];
                *solar_termica_1 = octubre_2021.solar_termica[1];
                *otras_renovables_0 = octubre_2021.otras_renovables[0];
                *otras_renovables_1 = octubre_2021.otras_renovables[1];
                *residuos_renovables_0 = octubre_2021.residuos_renovables[0];
                *residuos_renovables_1 = octubre_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = octubre_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = octubre_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = octubre_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = octubre_2021.turbinacion_bombeo[1];
                *nuclear_0 = octubre_2021.nuclear[0];
                *nuclear_1 = octubre_2021.nuclear[1];
                *ciclo_combinado_0 = octubre_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = octubre_2021.ciclo_combinado[1];
                *carbon_0 = octubre_2021.carbon[0];
                *carbon_1 = octubre_2021.carbon[1];
                *cogeneracion_0 = octubre_2021.cogeneracion[0];
                *cogeneracion_1 = octubre_2021.cogeneracion[1];
                *residuos_no_renovables_0 = octubre_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = octubre_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = octubre_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = octubre_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = octubre_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = octubre_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = octubre_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = octubre_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = octubre_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = octubre_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = octubre_2021.Demanda[0];
                *Demanda_1 = octubre_2021.Demanda[1];
            }

            fclose(plectura_2021_octubre);
        }

        if (mes_void == 11)
        {
            FILE *plectura_2021_noviembre;
            plectura_2021_noviembre = fopen("Ficheros_Comparaciones/2021/2021_noviembre.csv", "r");
            if (plectura_2021_noviembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (11/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (11/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes noviembre_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_noviembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &noviembre_2021.hidraulica [i], &noviembre_2021.eolica [i], &noviembre_2021.solar_fotovoltaica [i], &noviembre_2021.solar_termica [i], &noviembre_2021.otras_renovables [i], &noviembre_2021.residuos_renovables [i], &noviembre_2021.Generacion_Renovable [i], &noviembre_2021.turbinacion_bombeo [i], &noviembre_2021.nuclear [i], &noviembre_2021.ciclo_combinado [i], &noviembre_2021.carbon [i],&noviembre_2021.cogeneracion [i], &noviembre_2021.residuos_no_renovables [i], &noviembre_2021.Generacion_No_Renovable [i], &noviembre_2021.consumos_en_bombeo [i], &noviembre_2021.enlace_peninsula_baleares [i], &noviembre_2021.saldo_intercambios_internacionales [i], &noviembre_2021.Demanda [i]);
                }

                printf("                           Noviembre 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",noviembre_2021.hidraulica[0], noviembre_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",noviembre_2021.eolica[0], noviembre_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",noviembre_2021.solar_fotovoltaica[0], noviembre_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",noviembre_2021.solar_termica[0], noviembre_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",noviembre_2021.otras_renovables[0], noviembre_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",noviembre_2021.residuos_renovables[0], noviembre_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",noviembre_2021.Generacion_Renovable[0], noviembre_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",noviembre_2021.turbinacion_bombeo[0], noviembre_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",noviembre_2021.nuclear[0], noviembre_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",noviembre_2021.ciclo_combinado[0], noviembre_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",noviembre_2021.carbon[0],noviembre_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",noviembre_2021.cogeneracion[0], noviembre_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",noviembre_2021.residuos_no_renovables[0], noviembre_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",noviembre_2021.Generacion_No_Renovable[0], noviembre_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",noviembre_2021.consumos_en_bombeo[0], noviembre_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",noviembre_2021.enlace_peninsula_baleares[0], noviembre_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",noviembre_2021.saldo_intercambios_internacionales[0], noviembre_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",noviembre_2021.Demanda[0], noviembre_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = noviembre_2021.hidraulica[0];
                *hidraulica_1 = noviembre_2021.hidraulica[1];
                *eolica_0 = noviembre_2021.eolica[0];
                *eolica_1 = noviembre_2021.eolica[1];
                *solar_fotovoltaica_0 = noviembre_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = noviembre_2021.solar_fotovoltaica[1];
                *solar_termica_0 = noviembre_2021.solar_termica[0];
                *solar_termica_1 = noviembre_2021.solar_termica[1];
                *otras_renovables_0 = noviembre_2021.otras_renovables[0];
                *otras_renovables_1 = noviembre_2021.otras_renovables[1];
                *residuos_renovables_0 = noviembre_2021.residuos_renovables[0];
                *residuos_renovables_1 = noviembre_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = noviembre_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = noviembre_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = noviembre_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = noviembre_2021.turbinacion_bombeo[1];
                *nuclear_0 = noviembre_2021.nuclear[0];
                *nuclear_1 = noviembre_2021.nuclear[1];
                *ciclo_combinado_0 = noviembre_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = noviembre_2021.ciclo_combinado[1];
                *carbon_0 = noviembre_2021.carbon[0];
                *carbon_1 = noviembre_2021.carbon[1];
                *cogeneracion_0 = noviembre_2021.cogeneracion[0];
                *cogeneracion_1 = noviembre_2021.cogeneracion[1];
                *residuos_no_renovables_0 = noviembre_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = noviembre_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = noviembre_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = noviembre_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = noviembre_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = noviembre_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = noviembre_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = noviembre_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = noviembre_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = noviembre_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = noviembre_2021.Demanda[0];
                *Demanda_1 = noviembre_2021.Demanda[1];
            }

            fclose(plectura_2021_noviembre);
        }

        if (mes_void == 12)
        {
            FILE *plectura_2021_diciembre;
            plectura_2021_diciembre = fopen("Ficheros_Comparaciones/2021/2021_diciembre.csv", "r");
            if (plectura_2021_diciembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (12/2021).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (12/2021) abierto correctamente.\n");
                printf("\n");

                datos_mes diciembre_2021;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2021_diciembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &diciembre_2021.hidraulica [i], &diciembre_2021.eolica [i], &diciembre_2021.solar_fotovoltaica [i], &diciembre_2021.solar_termica [i], &diciembre_2021.otras_renovables [i], &diciembre_2021.residuos_renovables [i], &diciembre_2021.Generacion_Renovable [i], &diciembre_2021.turbinacion_bombeo [i], &diciembre_2021.nuclear [i], &diciembre_2021.ciclo_combinado [i], &diciembre_2021.carbon [i],&diciembre_2021.cogeneracion [i], &diciembre_2021.residuos_no_renovables [i], &diciembre_2021.Generacion_No_Renovable [i], &diciembre_2021.consumos_en_bombeo [i], &diciembre_2021.enlace_peninsula_baleares [i], &diciembre_2021.saldo_intercambios_internacionales [i], &diciembre_2021.Demanda [i]);
                }

                printf("                           Diciembre 2021 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",diciembre_2021.hidraulica[0], diciembre_2021.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",diciembre_2021.eolica[0], diciembre_2021.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",diciembre_2021.solar_fotovoltaica[0], diciembre_2021.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",diciembre_2021.solar_termica[0], diciembre_2021.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",diciembre_2021.otras_renovables[0], diciembre_2021.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",diciembre_2021.residuos_renovables[0], diciembre_2021.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",diciembre_2021.Generacion_Renovable[0], diciembre_2021.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",diciembre_2021.turbinacion_bombeo[0], diciembre_2021.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",diciembre_2021.nuclear[0], diciembre_2021.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",diciembre_2021.ciclo_combinado[0], diciembre_2021.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",diciembre_2021.carbon[0],diciembre_2021.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",diciembre_2021.cogeneracion[0], diciembre_2021.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",diciembre_2021.residuos_no_renovables[0], diciembre_2021.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",diciembre_2021.Generacion_No_Renovable[0], diciembre_2021.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",diciembre_2021.consumos_en_bombeo[0], diciembre_2021.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",diciembre_2021.enlace_peninsula_baleares[0], diciembre_2021.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",diciembre_2021.saldo_intercambios_internacionales[0], diciembre_2021.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",diciembre_2021.Demanda[0], diciembre_2021.Demanda[1]);
                printf("\n");

                *hidraulica_0 = diciembre_2021.hidraulica[0];
                *hidraulica_1 = diciembre_2021.hidraulica[1];
                *eolica_0 = diciembre_2021.eolica[0];
                *eolica_1 = diciembre_2021.eolica[1];
                *solar_fotovoltaica_0 = diciembre_2021.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = diciembre_2021.solar_fotovoltaica[1];
                *solar_termica_0 = diciembre_2021.solar_termica[0];
                *solar_termica_1 = diciembre_2021.solar_termica[1];
                *otras_renovables_0 = diciembre_2021.otras_renovables[0];
                *otras_renovables_1 = diciembre_2021.otras_renovables[1];
                *residuos_renovables_0 = diciembre_2021.residuos_renovables[0];
                *residuos_renovables_1 = diciembre_2021.residuos_renovables[1];
                *Generacion_Renovable_0 = diciembre_2021.Generacion_Renovable[0];
                *Generacion_Renovable_1 = diciembre_2021.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = diciembre_2021.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = diciembre_2021.turbinacion_bombeo[1];
                *nuclear_0 = diciembre_2021.nuclear[0];
                *nuclear_1 = diciembre_2021.nuclear[1];
                *ciclo_combinado_0 = diciembre_2021.ciclo_combinado[0];
                *ciclo_combinado_1 = diciembre_2021.ciclo_combinado[1];
                *carbon_0 = diciembre_2021.carbon[0];
                *carbon_1 = diciembre_2021.carbon[1];
                *cogeneracion_0 = diciembre_2021.cogeneracion[0];
                *cogeneracion_1 = diciembre_2021.cogeneracion[1];
                *residuos_no_renovables_0 = diciembre_2021.residuos_no_renovables[0];
                *residuos_no_renovables_1 = diciembre_2021.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = diciembre_2021.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = diciembre_2021.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = diciembre_2021.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = diciembre_2021.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = diciembre_2021.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = diciembre_2021.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = diciembre_2021.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = diciembre_2021.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = diciembre_2021.Demanda[0];
                *Demanda_1 = diciembre_2021.Demanda[1];
            }

            fclose(plectura_2021_diciembre);
        }
    }

    if (anio_mes_void == 2022)
    {
        if (mes_void == 1)
        {
            FILE *plectura_2022_enero;
            plectura_2022_enero = fopen("Ficheros_Comparaciones/2022/2022_enero.csv", "r");
            if (plectura_2022_enero == NULL)
            {
                printf("Error al abrir el fichero de lectura (01/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (01/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes enero_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_enero, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &enero_2022.hidraulica [i], &enero_2022.eolica [i], &enero_2022.solar_fotovoltaica [i], &enero_2022.solar_termica [i], &enero_2022.otras_renovables [i], &enero_2022.residuos_renovables [i], &enero_2022.Generacion_Renovable [i], &enero_2022.turbinacion_bombeo [i], &enero_2022.nuclear [i], &enero_2022.ciclo_combinado [i], &enero_2022.carbon [i],&enero_2022.cogeneracion [i], &enero_2022.residuos_no_renovables [i], &enero_2022.Generacion_No_Renovable [i], &enero_2022.consumos_en_bombeo [i], &enero_2022.enlace_peninsula_baleares [i], &enero_2022.saldo_intercambios_internacionales [i], &enero_2022.Demanda [i]);
                }

                printf("                           Enero 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",enero_2022.hidraulica[0], enero_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",enero_2022.eolica[0], enero_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",enero_2022.solar_fotovoltaica[0], enero_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",enero_2022.solar_termica[0], enero_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",enero_2022.otras_renovables[0], enero_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",enero_2022.residuos_renovables[0], enero_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",enero_2022.Generacion_Renovable[0], enero_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",enero_2022.turbinacion_bombeo[0], enero_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",enero_2022.nuclear[0], enero_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",enero_2022.ciclo_combinado[0], enero_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",enero_2022.carbon[0], enero_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",enero_2022.cogeneracion[0], enero_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",enero_2022.residuos_no_renovables[0], enero_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",enero_2022.Generacion_No_Renovable[0], enero_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",enero_2022.consumos_en_bombeo[0], enero_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",enero_2022.enlace_peninsula_baleares[0], enero_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",enero_2022.saldo_intercambios_internacionales[0], enero_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",enero_2022.Demanda[0], enero_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = enero_2022.hidraulica[0];
                *hidraulica_1 = enero_2022.hidraulica[1];
                *eolica_0 = enero_2022.eolica[0];
                *eolica_1 = enero_2022.eolica[1];
                *solar_fotovoltaica_0 = enero_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = enero_2022.solar_fotovoltaica[1];
                *solar_termica_0 = enero_2022.solar_termica[0];
                *solar_termica_1 = enero_2022.solar_termica[1];
                *otras_renovables_0 = enero_2022.otras_renovables[0];
                *otras_renovables_1 = enero_2022.otras_renovables[1];
                *residuos_renovables_0 = enero_2022.residuos_renovables[0];
                *residuos_renovables_1 = enero_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = enero_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = enero_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = enero_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = enero_2022.turbinacion_bombeo[1];
                *nuclear_0 = enero_2022.nuclear[0];
                *nuclear_1 = enero_2022.nuclear[1];
                *ciclo_combinado_0 = enero_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = enero_2022.ciclo_combinado[1];
                *carbon_0 = enero_2022.carbon[0];
                *carbon_1 = enero_2022.carbon[1];
                *cogeneracion_0 = enero_2022.cogeneracion[0];
                *cogeneracion_1 = enero_2022.cogeneracion[1];
                *residuos_no_renovables_0 = enero_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = enero_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = enero_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = enero_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = enero_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = enero_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = enero_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = enero_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = enero_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = enero_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = enero_2022.Demanda[0];
                *Demanda_1 = enero_2022.Demanda[1];
            }

            fclose(plectura_2022_enero);
        }

        if (mes_void == 2)
        {
            FILE *plectura_2022_febrero;
            plectura_2022_febrero = fopen("Ficheros_Comparaciones/2022/2022_febrero.csv", "r");
            if (plectura_2022_febrero == NULL)
            {
                printf("Error al abrir el fichero de lectura (02/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (02/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes febrero_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_febrero, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &febrero_2022.hidraulica [i], &febrero_2022.eolica [i], &febrero_2022.solar_fotovoltaica [i], &febrero_2022.solar_termica [i], &febrero_2022.otras_renovables [i], &febrero_2022.residuos_renovables [i], &febrero_2022.Generacion_Renovable [i], &febrero_2022.turbinacion_bombeo [i], &febrero_2022.nuclear [i], &febrero_2022.ciclo_combinado [i], &febrero_2022.carbon [i],&febrero_2022.cogeneracion [i], &febrero_2022.residuos_no_renovables [i], &febrero_2022.Generacion_No_Renovable [i], &febrero_2022.consumos_en_bombeo [i], &febrero_2022.enlace_peninsula_baleares [i], &febrero_2022.saldo_intercambios_internacionales [i], &febrero_2022.Demanda [i]);
                }

                printf("                           Febrero 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",febrero_2022.hidraulica[0], febrero_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",febrero_2022.eolica[0], febrero_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",febrero_2022.solar_fotovoltaica[0], febrero_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",febrero_2022.solar_termica[0], febrero_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",febrero_2022.otras_renovables[0], febrero_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",febrero_2022.residuos_renovables[0], febrero_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",febrero_2022.Generacion_Renovable[0], febrero_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",febrero_2022.turbinacion_bombeo[0], febrero_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",febrero_2022.nuclear[0], febrero_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",febrero_2022.ciclo_combinado[0], febrero_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",febrero_2022.carbon[0], febrero_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",febrero_2022.cogeneracion[0], febrero_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",febrero_2022.residuos_no_renovables[0], febrero_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",febrero_2022.  Generacion_No_Renovable[0], febrero_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",febrero_2022.consumos_en_bombeo[0], febrero_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",febrero_2022.enlace_peninsula_baleares[0], febrero_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",febrero_2022.saldo_intercambios_internacionales[0], febrero_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",febrero_2022.Demanda[0], febrero_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = febrero_2022.hidraulica[0];
                *hidraulica_1 = febrero_2022.hidraulica[1];
                *eolica_0 = febrero_2022.eolica[0];
                *eolica_1 = febrero_2022.eolica[1];
                *solar_fotovoltaica_0 = febrero_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = febrero_2022.solar_fotovoltaica[1];
                *solar_termica_0 = febrero_2022.solar_termica[0];
                *solar_termica_1 = febrero_2022.solar_termica[1];
                *otras_renovables_0 = febrero_2022.otras_renovables[0];
                *otras_renovables_1 = febrero_2022.otras_renovables[1];
                *residuos_renovables_0 = febrero_2022.residuos_renovables[0];
                *residuos_renovables_1 = febrero_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = febrero_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = febrero_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = febrero_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = febrero_2022.turbinacion_bombeo[1];
                *nuclear_0 = febrero_2022.nuclear[0];
                *nuclear_1 = febrero_2022.nuclear[1];
                *ciclo_combinado_0 = febrero_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = febrero_2022.ciclo_combinado[1];
                *carbon_0 = febrero_2022.carbon[0];
                *carbon_1 = febrero_2022.carbon[1];
                *cogeneracion_0 = febrero_2022.cogeneracion[0];
                *cogeneracion_1 = febrero_2022.cogeneracion[1];
                *residuos_no_renovables_0 = febrero_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = febrero_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = febrero_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = febrero_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = febrero_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = febrero_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = febrero_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = febrero_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = febrero_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = febrero_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = febrero_2022.Demanda[0];
                *Demanda_1 = febrero_2022.Demanda[1];
            }

            fclose(plectura_2022_febrero);
        }

        if (mes_void == 3)
        {
            FILE *plectura_2022_marzo;
            plectura_2022_marzo = fopen("Ficheros_Comparaciones/2022/2022_marzo.csv", "r");
            if (plectura_2022_marzo == NULL)
            {
                printf("Error al abrir el fichero de lectura (03/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (03/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes marzo_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_marzo, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &marzo_2022.hidraulica [i], &marzo_2022.eolica [i], &marzo_2022.solar_fotovoltaica [i], &marzo_2022.solar_termica [i], &marzo_2022.otras_renovables [i], &marzo_2022.residuos_renovables [i], &marzo_2022.Generacion_Renovable [i], &marzo_2022.turbinacion_bombeo [i], &marzo_2022.nuclear [i], &marzo_2022.ciclo_combinado [i], &marzo_2022.carbon [i],&marzo_2022.cogeneracion [i], &marzo_2022.residuos_no_renovables [i], &marzo_2022.Generacion_No_Renovable [i], &marzo_2022.consumos_en_bombeo [i], &marzo_2022.enlace_peninsula_baleares [i], &marzo_2022.saldo_intercambios_internacionales [i], &marzo_2022.Demanda [i]);
                }

                printf("                           Marzo 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",marzo_2022.hidraulica[0], marzo_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",marzo_2022.eolica[0], marzo_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",marzo_2022.solar_fotovoltaica[0], marzo_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",marzo_2022.solar_termica[0], marzo_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",marzo_2022.otras_renovables[0], marzo_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",marzo_2022.residuos_renovables[0], marzo_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",marzo_2022.Generacion_Renovable[0], marzo_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",marzo_2022.turbinacion_bombeo[0], marzo_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",marzo_2022.nuclear[0], marzo_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",marzo_2022.ciclo_combinado[0], marzo_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",marzo_2022.carbon[0], marzo_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",marzo_2022.cogeneracion[0], marzo_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",marzo_2022.residuos_no_renovables[0], marzo_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",marzo_2022.Generacion_No_Renovable[0], marzo_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",marzo_2022.consumos_en_bombeo[0], marzo_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",marzo_2022.enlace_peninsula_baleares[0], marzo_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",marzo_2022.saldo_intercambios_internacionales[0], marzo_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",marzo_2022.Demanda[0], marzo_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = marzo_2022.hidraulica[0];
                *hidraulica_1 = marzo_2022.hidraulica[1];
                *eolica_0 = marzo_2022.eolica[0];
                *eolica_1 = marzo_2022.eolica[1];
                *solar_fotovoltaica_0 = marzo_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = marzo_2022.solar_fotovoltaica[1];
                *solar_termica_0 = marzo_2022.solar_termica[0];
                *solar_termica_1 = marzo_2022.solar_termica[1];
                *otras_renovables_0 = marzo_2022.otras_renovables[0];
                *otras_renovables_1 = marzo_2022.otras_renovables[1];
                *residuos_renovables_0 = marzo_2022.residuos_renovables[0];
                *residuos_renovables_1 = marzo_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = marzo_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = marzo_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = marzo_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = marzo_2022.turbinacion_bombeo[1];
                *nuclear_0 = marzo_2022.nuclear[0];
                *nuclear_1 = marzo_2022.nuclear[1];
                *ciclo_combinado_0 = marzo_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = marzo_2022.ciclo_combinado[1];
                *carbon_0 = marzo_2022.carbon[0];
                *carbon_1 = marzo_2022.carbon[1];
                *cogeneracion_0 = marzo_2022.cogeneracion[0];
                *cogeneracion_1 = marzo_2022.cogeneracion[1];
                *residuos_no_renovables_0 = marzo_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = marzo_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = marzo_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = marzo_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = marzo_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = marzo_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = marzo_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = marzo_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = marzo_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = marzo_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = marzo_2022.Demanda[0];
                *Demanda_1 = marzo_2022.Demanda[1];
            }

            fclose(plectura_2022_marzo);
        }

        if (mes_void == 4)
        {
            FILE *plectura_2022_abril;
            plectura_2022_abril = fopen("Ficheros_Comparaciones/2022/2022_abril.csv", "r");
            if (plectura_2022_abril == NULL)
            {
                printf("Error al abrir el fichero de lectura (04/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (04/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes abril_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_abril, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &abril_2022.hidraulica [i], &abril_2022.eolica [i], &abril_2022.solar_fotovoltaica [i], &abril_2022.solar_termica [i], &abril_2022.otras_renovables [i], &abril_2022.residuos_renovables [i], &abril_2022.Generacion_Renovable [i], &abril_2022.turbinacion_bombeo [i], &abril_2022.nuclear [i], &abril_2022.ciclo_combinado [i], &abril_2022.carbon [i],&abril_2022.cogeneracion [i], &abril_2022.residuos_no_renovables [i], &abril_2022.Generacion_No_Renovable [i], &abril_2022.consumos_en_bombeo [i], &abril_2022.enlace_peninsula_baleares [i], &abril_2022.saldo_intercambios_internacionales [i], &abril_2022.Demanda [i]);
                }

                printf("                           Abril 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",abril_2022.hidraulica[0], abril_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",abril_2022.eolica[0], abril_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",abril_2022.solar_fotovoltaica[0], abril_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",abril_2022.solar_termica[0], abril_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",abril_2022.otras_renovables[0], abril_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",abril_2022.residuos_renovables[0], abril_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",abril_2022.Generacion_Renovable[0], abril_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",abril_2022.turbinacion_bombeo[0], abril_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",abril_2022.nuclear[0], abril_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",abril_2022.ciclo_combinado[0], abril_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",abril_2022.carbon[0], abril_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",abril_2022.cogeneracion[0], abril_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",abril_2022.residuos_no_renovables[0], abril_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",abril_2022.Generacion_No_Renovable[0], abril_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",abril_2022.consumos_en_bombeo[0], abril_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",abril_2022.enlace_peninsula_baleares[0], abril_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",abril_2022.saldo_intercambios_internacionales[0], abril_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",abril_2022.Demanda[0], abril_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = abril_2022.hidraulica[0];
                *hidraulica_1 = abril_2022.hidraulica[1];
                *eolica_0 = abril_2022.eolica[0];
                *eolica_1 = abril_2022.eolica[1];
                *solar_fotovoltaica_0 = abril_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = abril_2022.solar_fotovoltaica[1];
                *solar_termica_0 = abril_2022.solar_termica[0];
                *solar_termica_1 = abril_2022.solar_termica[1];
                *otras_renovables_0 = abril_2022.otras_renovables[0];
                *otras_renovables_1 = abril_2022.otras_renovables[1];
                *residuos_renovables_0 = abril_2022.residuos_renovables[0];
                *residuos_renovables_1 = abril_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = abril_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = abril_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = abril_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = abril_2022.turbinacion_bombeo[1];
                *nuclear_0 = abril_2022.nuclear[0];
                *nuclear_1 = abril_2022.nuclear[1];
                *ciclo_combinado_0 = abril_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = abril_2022.ciclo_combinado[1];
                *carbon_0 = abril_2022.carbon[0];
                *carbon_1 = abril_2022.carbon[1];
                *cogeneracion_0 = abril_2022.cogeneracion[0];
                *cogeneracion_1 = abril_2022.cogeneracion[1];
                *residuos_no_renovables_0 = abril_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = abril_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = abril_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = abril_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = abril_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = abril_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = abril_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = abril_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = abril_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = abril_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = abril_2022.Demanda[0];
                *Demanda_1 = abril_2022.Demanda[1]; 
            }

            fclose(plectura_2022_abril);
        }

        if (mes_void == 5)
        {
            FILE *plectura_2022_mayo;
            plectura_2022_mayo= fopen("FICHEROS/2022_mayo.csv", "r");
            if (plectura_2022_mayo == NULL)
            {
                printf("Error al abrir el fichero de lectura (05/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (05/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes mayo_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_mayo, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &mayo_2022.hidraulica [i], &mayo_2022.eolica [i], &mayo_2022.solar_fotovoltaica [i], &mayo_2022.solar_termica [i], &mayo_2022.otras_renovables [i], &mayo_2022.residuos_renovables [i], &mayo_2022.Generacion_Renovable [i], &mayo_2022.turbinacion_bombeo [i], &mayo_2022.nuclear [i], &mayo_2022.ciclo_combinado [i], &mayo_2022.carbon [i],&mayo_2022.cogeneracion [i], &mayo_2022.residuos_no_renovables [i], &mayo_2022.Generacion_No_Renovable [i], &mayo_2022.consumos_en_bombeo [i], &mayo_2022.enlace_peninsula_baleares [i], &mayo_2022.saldo_intercambios_internacionales [i], &mayo_2022.Demanda [i]);
                }

                printf("                           Mayo 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",mayo_2022.hidraulica[0], mayo_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",mayo_2022.eolica[0], mayo_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",mayo_2022.solar_fotovoltaica[0], mayo_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",mayo_2022.solar_termica[0], mayo_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",mayo_2022.otras_renovables[0], mayo_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",mayo_2022.residuos_renovables[0], mayo_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",mayo_2022.Generacion_Renovable[0], mayo_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",mayo_2022.turbinacion_bombeo[0], mayo_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",mayo_2022.nuclear[0], mayo_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",mayo_2022.ciclo_combinado[0], mayo_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",mayo_2022.carbon[0], mayo_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",mayo_2022.cogeneracion[0], mayo_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",mayo_2022.residuos_no_renovables[0], mayo_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",mayo_2022.Generacion_No_Renovable[0], mayo_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",mayo_2022.consumos_en_bombeo[0], mayo_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",mayo_2022.enlace_peninsula_baleares[0], mayo_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",mayo_2022.saldo_intercambios_internacionales[0], mayo_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",mayo_2022.Demanda[0], mayo_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = mayo_2022.hidraulica[0];
                *hidraulica_1 = mayo_2022.hidraulica[1];
                *eolica_0 = mayo_2022.eolica[0];
                *eolica_1 = mayo_2022.eolica[1];
                *solar_fotovoltaica_0 = mayo_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = mayo_2022.solar_fotovoltaica[1];
                *solar_termica_0 = mayo_2022.solar_termica[0];
                *solar_termica_1 = mayo_2022.solar_termica[1];
                *otras_renovables_0 = mayo_2022.otras_renovables[0];
                *otras_renovables_1 = mayo_2022.otras_renovables[1];
                *residuos_renovables_0 = mayo_2022.residuos_renovables[0];
                *residuos_renovables_1 = mayo_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = mayo_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = mayo_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = mayo_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = mayo_2022.turbinacion_bombeo[1];
                *nuclear_0 = mayo_2022.nuclear[0];
                *nuclear_1 = mayo_2022.nuclear[1];
                *ciclo_combinado_0 = mayo_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = mayo_2022.ciclo_combinado[1];
                *carbon_0 = mayo_2022.carbon[0];
                *carbon_1 = mayo_2022.carbon[1];
                *cogeneracion_0 = mayo_2022.cogeneracion[0];
                *cogeneracion_1 = mayo_2022.cogeneracion[1];
                *residuos_no_renovables_0 = mayo_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = mayo_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = mayo_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = mayo_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = mayo_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = mayo_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = mayo_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = mayo_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = mayo_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = mayo_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = mayo_2022.Demanda[0];
                *Demanda_1 = mayo_2022.Demanda[1];
            }

            fclose(plectura_2022_mayo);
        }

        if (mes_void == 6)
        {
            FILE *plectura_2022_junio;
            plectura_2022_junio = fopen("Ficheros_Comparaciones/2022/2022_junio.csv", "r");
            if (plectura_2022_junio == NULL)
            {
                printf("Error al abrir el fichero de lectura (06/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (06/2022) abierto correctamente.\n");
                printf("\n");

                 datos_mes junio_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_junio, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &junio_2022.hidraulica [i], &junio_2022.eolica [i], &junio_2022.solar_fotovoltaica [i], &junio_2022.solar_termica [i], &junio_2022.otras_renovables [i], &junio_2022.residuos_renovables [i], &junio_2022.Generacion_Renovable [i], &junio_2022.turbinacion_bombeo [i], &junio_2022.nuclear [i], &junio_2022.ciclo_combinado [i], &junio_2022.carbon [i],&junio_2022.cogeneracion [i], &junio_2022.residuos_no_renovables [i], &junio_2022.Generacion_No_Renovable [i], &junio_2022.consumos_en_bombeo [i], &junio_2022.enlace_peninsula_baleares [i], &junio_2022.saldo_intercambios_internacionales [i], &junio_2022.Demanda [i]);
                }

                printf("                           Junio 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",junio_2022.hidraulica[0], junio_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",junio_2022.eolica[0], junio_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",junio_2022.solar_fotovoltaica[0], junio_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",junio_2022.solar_termica[0], junio_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",junio_2022.otras_renovables[0], junio_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",junio_2022.residuos_renovables[0], junio_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",junio_2022.Generacion_Renovable[0], junio_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",junio_2022.turbinacion_bombeo[0], junio_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",junio_2022.nuclear[0], junio_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",junio_2022.ciclo_combinado[0], junio_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",junio_2022.carbon[0],junio_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",junio_2022.cogeneracion[0], junio_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",junio_2022.residuos_no_renovables[0], junio_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",junio_2022.Generacion_No_Renovable[0], junio_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",junio_2022.consumos_en_bombeo[0], junio_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",junio_2022.enlace_peninsula_baleares[0], junio_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",junio_2022.saldo_intercambios_internacionales[0], junio_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",junio_2022.Demanda[0], junio_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = junio_2022.hidraulica[0];
                *hidraulica_1 = junio_2022.hidraulica[1];
                *eolica_0 = junio_2022.eolica[0];
                *eolica_1 = junio_2022.eolica[1];
                *solar_fotovoltaica_0 = junio_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = junio_2022.solar_fotovoltaica[1];
                *solar_termica_0 = junio_2022.solar_termica[0];
                *solar_termica_1 = junio_2022.solar_termica[1];
                *otras_renovables_0 = junio_2022.otras_renovables[0];
                *otras_renovables_1 = junio_2022.otras_renovables[1];
                *residuos_renovables_0 = junio_2022.residuos_renovables[0];
                *residuos_renovables_1 = junio_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = junio_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = junio_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = junio_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = junio_2022.turbinacion_bombeo[1];
                *nuclear_0 = junio_2022.nuclear[0];
                *nuclear_1 = junio_2022.nuclear[1];
                *ciclo_combinado_0 = junio_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = junio_2022.ciclo_combinado[1];
                *carbon_0 = junio_2022.carbon[0];
                *carbon_1 = junio_2022.carbon[1];
                *cogeneracion_0 = junio_2022.cogeneracion[0];
                *cogeneracion_1 = junio_2022.cogeneracion[1];
                *residuos_no_renovables_0 = junio_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = junio_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = junio_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = junio_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = junio_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = junio_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = junio_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = junio_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = junio_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = junio_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = junio_2022.Demanda[0];
                *Demanda_1 = junio_2022.Demanda[1];
            }

            fclose(plectura_2022_junio);
        }

        if (mes_void == 7)
        {
            FILE *plectura_2022_julio;
            plectura_2022_julio = fopen("Ficheros_Comparaciones/2022/2022_julio.csv", "r");
            if (plectura_2022_julio == NULL)
            {
                printf("Error al abrir el fichero de lectura (07/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (07/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes julio_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_julio, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &julio_2022.hidraulica [i], &julio_2022.eolica [i], &julio_2022.solar_fotovoltaica [i], &julio_2022.solar_termica [i], &julio_2022.otras_renovables [i], &julio_2022.residuos_renovables [i], &julio_2022.Generacion_Renovable [i], &julio_2022.turbinacion_bombeo [i], &julio_2022.nuclear [i], &julio_2022.ciclo_combinado [i], &julio_2022.carbon [i],&julio_2022.cogeneracion [i], &julio_2022.residuos_no_renovables [i], &julio_2022.Generacion_No_Renovable [i], &julio_2022.consumos_en_bombeo [i], &julio_2022.enlace_peninsula_baleares [i], &julio_2022.saldo_intercambios_internacionales [i], &julio_2022.Demanda [i]);
                }

                printf("                           Julio 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",julio_2022.hidraulica[0], julio_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",julio_2022.eolica[0], julio_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",julio_2022.solar_fotovoltaica[0], julio_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",julio_2022.solar_termica[0], julio_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",julio_2022.otras_renovables[0], julio_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",julio_2022.residuos_renovables[0], julio_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",julio_2022.Generacion_Renovable[0], julio_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",julio_2022.turbinacion_bombeo[0], julio_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",julio_2022.nuclear[0], julio_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",julio_2022.ciclo_combinado[0], julio_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",julio_2022.carbon[0],julio_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",julio_2022.cogeneracion[0], julio_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",julio_2022.residuos_no_renovables[0], julio_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",julio_2022.Generacion_No_Renovable[0], julio_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",julio_2022.consumos_en_bombeo[0], julio_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",julio_2022.enlace_peninsula_baleares[0], julio_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",julio_2022.saldo_intercambios_internacionales[0], julio_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",julio_2022.Demanda[0], julio_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = julio_2022.hidraulica[0];
                *hidraulica_1 = julio_2022.hidraulica[1];
                *eolica_0 = julio_2022.eolica[0];
                *eolica_1 = julio_2022.eolica[1];
                *solar_fotovoltaica_0 = julio_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = julio_2022.solar_fotovoltaica[1];
                *solar_termica_0 = julio_2022.solar_termica[0];
                *solar_termica_1 = julio_2022.solar_termica[1];
                *otras_renovables_0 = julio_2022.otras_renovables[0];
                *otras_renovables_1 = julio_2022.otras_renovables[1];
                *residuos_renovables_0 = julio_2022.residuos_renovables[0];
                *residuos_renovables_1 = julio_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = julio_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = julio_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = julio_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = julio_2022.turbinacion_bombeo[1];
                *nuclear_0 = julio_2022.nuclear[0];
                *nuclear_1 = julio_2022.nuclear[1];
                *ciclo_combinado_0 = julio_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = julio_2022.ciclo_combinado[1];
                *carbon_0 = julio_2022.carbon[0];
                *carbon_1 = julio_2022.carbon[1];
                *cogeneracion_0 = julio_2022.cogeneracion[0];
                *cogeneracion_1 = julio_2022.cogeneracion[1];
                *residuos_no_renovables_0 = julio_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = julio_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = julio_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = julio_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = julio_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = julio_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = julio_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = julio_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = julio_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = julio_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = julio_2022.Demanda[0];
                *Demanda_1 = julio_2022.Demanda[1];
            }

            fclose(plectura_2022_julio);
        }

        if (mes_void == 8)
        {
            FILE *plectura_2022_agosto;
            plectura_2022_agosto = fopen("Ficheros_Comparaciones/2022/2022_agosto.csv", "r");
            if (plectura_2022_agosto == NULL)
            {
                printf("Error al abrir el fichero de lectura (08/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (08/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes agosto_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_agosto, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &agosto_2022.hidraulica [i], &agosto_2022.eolica [i], &agosto_2022.solar_fotovoltaica [i], &agosto_2022.solar_termica [i], &agosto_2022.otras_renovables [i], &agosto_2022.residuos_renovables [i], &agosto_2022.Generacion_Renovable [i], &agosto_2022.turbinacion_bombeo [i], &agosto_2022.nuclear [i], &agosto_2022.ciclo_combinado [i], &agosto_2022.carbon [i],&agosto_2022.cogeneracion [i], &agosto_2022.residuos_no_renovables [i], &agosto_2022.Generacion_No_Renovable [i], &agosto_2022.consumos_en_bombeo [i], &agosto_2022.enlace_peninsula_baleares [i], &agosto_2022.saldo_intercambios_internacionales [i], &agosto_2022.Demanda [i]);
                }

                printf("                           Agosto 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",agosto_2022.hidraulica[0], agosto_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",agosto_2022.eolica[0], agosto_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",agosto_2022.solar_fotovoltaica[0], agosto_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",agosto_2022.solar_termica[0], agosto_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",agosto_2022.otras_renovables[0], agosto_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",agosto_2022.residuos_renovables[0], agosto_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",agosto_2022.Generacion_Renovable[0], agosto_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",agosto_2022.turbinacion_bombeo[0], agosto_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",agosto_2022.nuclear[0], agosto_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",agosto_2022.ciclo_combinado[0], agosto_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",agosto_2022.carbon[0],agosto_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",agosto_2022.cogeneracion[0], agosto_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",agosto_2022.residuos_no_renovables[0], agosto_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",agosto_2022.Generacion_No_Renovable[0], agosto_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",agosto_2022.consumos_en_bombeo[0], agosto_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",agosto_2022.enlace_peninsula_baleares[0], agosto_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",agosto_2022.saldo_intercambios_internacionales[0], agosto_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",agosto_2022.Demanda[0], agosto_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = agosto_2022.hidraulica[0];
                *hidraulica_1 = agosto_2022.hidraulica[1];
                *eolica_0 = agosto_2022.eolica[0];
                *eolica_1 = agosto_2022.eolica[1];
                *solar_fotovoltaica_0 = agosto_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = agosto_2022.solar_fotovoltaica[1];
                *solar_termica_0 = agosto_2022.solar_termica[0];
                *solar_termica_1 = agosto_2022.solar_termica[1];
                *otras_renovables_0 = agosto_2022.otras_renovables[0];
                *otras_renovables_1 = agosto_2022.otras_renovables[1];
                *residuos_renovables_0 = agosto_2022.residuos_renovables[0];
                *residuos_renovables_1 = agosto_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = agosto_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = agosto_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = agosto_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = agosto_2022.turbinacion_bombeo[1];
                *nuclear_0 = agosto_2022.nuclear[0];
                *nuclear_1 = agosto_2022.nuclear[1];
                *ciclo_combinado_0 = agosto_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = agosto_2022.ciclo_combinado[1];
                *carbon_0 = agosto_2022.carbon[0];
                *carbon_1 = agosto_2022.carbon[1];
                *cogeneracion_0 = agosto_2022.cogeneracion[0];
                *cogeneracion_1 = agosto_2022.cogeneracion[1];
                *residuos_no_renovables_0 = agosto_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = agosto_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = agosto_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = agosto_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = agosto_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = agosto_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = agosto_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = agosto_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = agosto_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = agosto_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = agosto_2022.Demanda[0];
                *Demanda_1 = agosto_2022.Demanda[1];
            }

            fclose(plectura_2022_agosto);
        }

        if (mes_void == 9)
        {
            FILE *plectura_2022_septiembre;
            plectura_2022_septiembre = fopen("Ficheros_Comparaciones/2022/2022_septiembre.csv", "r");
            if (plectura_2022_septiembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (09/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (09/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes septiembre_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_septiembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &septiembre_2022.hidraulica [i], &septiembre_2022.eolica [i], &septiembre_2022.solar_fotovoltaica [i], &septiembre_2022.solar_termica [i], &septiembre_2022.otras_renovables [i], &septiembre_2022.residuos_renovables [i], &septiembre_2022.Generacion_Renovable [i], &septiembre_2022.turbinacion_bombeo [i], &septiembre_2022.nuclear [i], &septiembre_2022.ciclo_combinado [i], &septiembre_2022.carbon [i],&septiembre_2022.cogeneracion [i], &septiembre_2022.residuos_no_renovables [i], &septiembre_2022.Generacion_No_Renovable [i], &septiembre_2022.consumos_en_bombeo [i], &septiembre_2022.enlace_peninsula_baleares [i], &septiembre_2022.saldo_intercambios_internacionales [i], &septiembre_2022.Demanda [i]);
                }

                printf("                           Septiembre 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",septiembre_2022.hidraulica[0], septiembre_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",septiembre_2022.eolica[0], septiembre_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",septiembre_2022.solar_fotovoltaica[0], septiembre_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",septiembre_2022.solar_termica[0], septiembre_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",septiembre_2022.otras_renovables[0], septiembre_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",septiembre_2022.residuos_renovables[0], septiembre_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",septiembre_2022.Generacion_Renovable[0], septiembre_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",septiembre_2022.turbinacion_bombeo[0], septiembre_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",septiembre_2022.nuclear[0], septiembre_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",septiembre_2022.ciclo_combinado[0], septiembre_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",septiembre_2022.carbon[0],septiembre_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",septiembre_2022.cogeneracion[0], septiembre_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",septiembre_2022.residuos_no_renovables[0], septiembre_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",septiembre_2022.Generacion_No_Renovable[0], septiembre_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",septiembre_2022.consumos_en_bombeo[0], septiembre_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",septiembre_2022.enlace_peninsula_baleares[0], septiembre_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",septiembre_2022.saldo_intercambios_internacionales[0], septiembre_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",septiembre_2022.Demanda[0], septiembre_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = septiembre_2022.hidraulica[0];
                *hidraulica_1 = septiembre_2022.hidraulica[1];
                *eolica_0 = septiembre_2022.eolica[0];
                *eolica_1 = septiembre_2022.eolica[1];
                *solar_fotovoltaica_0 = septiembre_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = septiembre_2022.solar_fotovoltaica[1];
                *solar_termica_0 = septiembre_2022.solar_termica[0];
                *solar_termica_1 = septiembre_2022.solar_termica[1];
                *otras_renovables_0 = septiembre_2022.otras_renovables[0];
                *otras_renovables_1 = septiembre_2022.otras_renovables[1];
                *residuos_renovables_0 = septiembre_2022.residuos_renovables[0];
                *residuos_renovables_1 = septiembre_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = septiembre_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = septiembre_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = septiembre_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = septiembre_2022.turbinacion_bombeo[1];
                *nuclear_0 = septiembre_2022.nuclear[0];
                *nuclear_1 = septiembre_2022.nuclear[1];
                *ciclo_combinado_0 = septiembre_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = septiembre_2022.ciclo_combinado[1];
                *carbon_0 = septiembre_2022.carbon[0];
                *carbon_1 = septiembre_2022.carbon[1];
                *cogeneracion_0 = septiembre_2022.cogeneracion[0];
                *cogeneracion_1 = septiembre_2022.cogeneracion[1];
                *residuos_no_renovables_0 = septiembre_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = septiembre_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = septiembre_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = septiembre_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = septiembre_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = septiembre_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = septiembre_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = septiembre_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = septiembre_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = septiembre_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = septiembre_2022.Demanda[0];
                *Demanda_1 = septiembre_2022.Demanda[1];
            }

            fclose(plectura_2022_septiembre);
        }

        if (mes_void == 10)
        {
            FILE *plectura_2022_octubre;
            plectura_2022_octubre = fopen("Ficheros_Comparaciones/2022/2022_octubre.csv", "r");
            if (plectura_2022_octubre == NULL)
            {
                printf("Error al abrir el fichero de lectura (10/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (10/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes octubre_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_octubre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &octubre_2022.hidraulica [i], &octubre_2022.eolica [i], &octubre_2022.solar_fotovoltaica [i], &octubre_2022.solar_termica [i], &octubre_2022.otras_renovables [i], &octubre_2022.residuos_renovables [i], &octubre_2022.Generacion_Renovable [i], &octubre_2022.turbinacion_bombeo [i], &octubre_2022.nuclear [i], &octubre_2022.ciclo_combinado [i], &octubre_2022.carbon [i],&octubre_2022.cogeneracion [i], &octubre_2022.residuos_no_renovables [i], &octubre_2022.Generacion_No_Renovable [i], &octubre_2022.consumos_en_bombeo [i], &octubre_2022.enlace_peninsula_baleares [i], &octubre_2022.saldo_intercambios_internacionales [i], &octubre_2022.Demanda [i]);
                }

                printf("                           Octubre 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",octubre_2022.hidraulica[0], octubre_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",octubre_2022.eolica[0], octubre_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",octubre_2022.solar_fotovoltaica[0], octubre_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",octubre_2022.solar_termica[0], octubre_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",octubre_2022.otras_renovables[0], octubre_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",octubre_2022.residuos_renovables[0], octubre_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",octubre_2022.Generacion_Renovable[0], octubre_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",octubre_2022.turbinacion_bombeo[0], octubre_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",octubre_2022.nuclear[0], octubre_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",octubre_2022.ciclo_combinado[0], octubre_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",octubre_2022.carbon[0],octubre_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",octubre_2022.cogeneracion[0], octubre_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",octubre_2022.residuos_no_renovables[0], octubre_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",octubre_2022.Generacion_No_Renovable[0], octubre_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",octubre_2022.consumos_en_bombeo[0], octubre_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",octubre_2022.enlace_peninsula_baleares[0], octubre_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",octubre_2022.saldo_intercambios_internacionales[0], octubre_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",octubre_2022.Demanda[0], octubre_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = octubre_2022.hidraulica[0];
                *hidraulica_1 = octubre_2022.hidraulica[1];
                *eolica_0 = octubre_2022.eolica[0];
                *eolica_1 = octubre_2022.eolica[1];
                *solar_fotovoltaica_0 = octubre_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = octubre_2022.solar_fotovoltaica[1];
                *solar_termica_0 = octubre_2022.solar_termica[0];
                *solar_termica_1 = octubre_2022.solar_termica[1];
                *otras_renovables_0 = octubre_2022.otras_renovables[0];
                *otras_renovables_1 = octubre_2022.otras_renovables[1];
                *residuos_renovables_0 = octubre_2022.residuos_renovables[0];
                *residuos_renovables_1 = octubre_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = octubre_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = octubre_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = octubre_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = octubre_2022.turbinacion_bombeo[1];
                *nuclear_0 = octubre_2022.nuclear[0];
                *nuclear_1 = octubre_2022.nuclear[1];
                *ciclo_combinado_0 = octubre_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = octubre_2022.ciclo_combinado[1];
                *carbon_0 = octubre_2022.carbon[0];
                *carbon_1 = octubre_2022.carbon[1];
                *cogeneracion_0 = octubre_2022.cogeneracion[0];
                *cogeneracion_1 = octubre_2022.cogeneracion[1];
                *residuos_no_renovables_0 = octubre_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = octubre_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = octubre_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = octubre_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = octubre_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = octubre_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = octubre_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = octubre_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = octubre_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = octubre_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = octubre_2022.Demanda[0];
                *Demanda_1 = octubre_2022.Demanda[1];
            }

            fclose(plectura_2022_octubre);
        }

        if (mes_void == 11)
        {
            FILE *plectura_2022_noviembre;
            plectura_2022_noviembre = fopen("Ficheros_Comparaciones/2022/2022_noviembre.csv", "r");
            if (plectura_2022_noviembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (11/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (11/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes noviembre_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_noviembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &noviembre_2022.hidraulica [i], &noviembre_2022.eolica [i], &noviembre_2022.solar_fotovoltaica [i], &noviembre_2022.solar_termica [i], &noviembre_2022.otras_renovables [i], &noviembre_2022.residuos_renovables [i], &noviembre_2022.Generacion_Renovable [i], &noviembre_2022.turbinacion_bombeo [i], &noviembre_2022.nuclear [i], &noviembre_2022.ciclo_combinado [i], &noviembre_2022.carbon [i],&noviembre_2022.cogeneracion [i], &noviembre_2022.residuos_no_renovables [i], &noviembre_2022.Generacion_No_Renovable [i], &noviembre_2022.consumos_en_bombeo [i], &noviembre_2022.enlace_peninsula_baleares [i], &noviembre_2022.saldo_intercambios_internacionales [i], &noviembre_2022.Demanda [i]);
                }

                printf("                           Noviembre 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",noviembre_2022.hidraulica[0], noviembre_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",noviembre_2022.eolica[0], noviembre_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",noviembre_2022.solar_fotovoltaica[0], noviembre_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",noviembre_2022.solar_termica[0], noviembre_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",noviembre_2022.otras_renovables[0], noviembre_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",noviembre_2022.residuos_renovables[0], noviembre_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",noviembre_2022.Generacion_Renovable[0], noviembre_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",noviembre_2022.turbinacion_bombeo[0], noviembre_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",noviembre_2022.nuclear[0], noviembre_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",noviembre_2022.ciclo_combinado[0], noviembre_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",noviembre_2022.carbon[0],noviembre_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",noviembre_2022.cogeneracion[0], noviembre_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",noviembre_2022.residuos_no_renovables[0], noviembre_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",noviembre_2022.Generacion_No_Renovable[0], noviembre_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",noviembre_2022.consumos_en_bombeo[0], noviembre_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",noviembre_2022.enlace_peninsula_baleares[0], noviembre_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",noviembre_2022.saldo_intercambios_internacionales[0], noviembre_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",noviembre_2022.Demanda[0], noviembre_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = noviembre_2022.hidraulica[0];
                *hidraulica_1 = noviembre_2022.hidraulica[1];
                *eolica_0 = noviembre_2022.eolica[0];
                *eolica_1 = noviembre_2022.eolica[1];
                *solar_fotovoltaica_0 = noviembre_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = noviembre_2022.solar_fotovoltaica[1];
                *solar_termica_0 = noviembre_2022.solar_termica[0];
                *solar_termica_1 = noviembre_2022.solar_termica[1];
                *otras_renovables_0 = noviembre_2022.otras_renovables[0];
                *otras_renovables_1 = noviembre_2022.otras_renovables[1];
                *residuos_renovables_0 = noviembre_2022.residuos_renovables[0];
                *residuos_renovables_1 = noviembre_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = noviembre_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = noviembre_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = noviembre_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = noviembre_2022.turbinacion_bombeo[1];
                *nuclear_0 = noviembre_2022.nuclear[0];
                *nuclear_1 = noviembre_2022.nuclear[1];
                *ciclo_combinado_0 = noviembre_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = noviembre_2022.ciclo_combinado[1];
                *carbon_0 = noviembre_2022.carbon[0];
                *carbon_1 = noviembre_2022.carbon[1];
                *cogeneracion_0 = noviembre_2022.cogeneracion[0];
                *cogeneracion_1 = noviembre_2022.cogeneracion[1];
                *residuos_no_renovables_0 = noviembre_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = noviembre_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = noviembre_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = noviembre_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = noviembre_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = noviembre_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = noviembre_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = noviembre_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = noviembre_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = noviembre_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = noviembre_2022.Demanda[0];
                *Demanda_1 = noviembre_2022.Demanda[1];
            }

            fclose(plectura_2022_noviembre);
        }

        if (mes_void == 12)
        {
            FILE *plectura_2022_diciembre;
            plectura_2022_diciembre = fopen("Ficheros_Comparaciones/2022/2022_diciembre.csv", "r");
            if (plectura_2022_diciembre == NULL)
            {
                printf("Error al abrir el fichero de lectura (12/2022).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (12/2022) abierto correctamente.\n");
                printf("\n");

                datos_mes diciembre_2022;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2022_diciembre, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &diciembre_2022.hidraulica [i], &diciembre_2022.eolica [i], &diciembre_2022.solar_fotovoltaica [i], &diciembre_2022.solar_termica [i], &diciembre_2022.otras_renovables [i], &diciembre_2022.residuos_renovables [i], &diciembre_2022.Generacion_Renovable [i], &diciembre_2022.turbinacion_bombeo [i], &diciembre_2022.nuclear [i], &diciembre_2022.ciclo_combinado [i], &diciembre_2022.carbon [i],&diciembre_2022.cogeneracion [i], &diciembre_2022.residuos_no_renovables [i], &diciembre_2022.Generacion_No_Renovable [i], &diciembre_2022.consumos_en_bombeo [i], &diciembre_2022.enlace_peninsula_baleares [i], &diciembre_2022.saldo_intercambios_internacionales [i], &diciembre_2022.Demanda [i]);
                }

                printf("                           Diciembre 2022 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",diciembre_2022.hidraulica[0], diciembre_2022.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",diciembre_2022.eolica[0], diciembre_2022.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",diciembre_2022.solar_fotovoltaica[0], diciembre_2022.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",diciembre_2022.solar_termica[0], diciembre_2022.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",diciembre_2022.otras_renovables[0], diciembre_2022.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",diciembre_2022.residuos_renovables[0], diciembre_2022.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",diciembre_2022.Generacion_Renovable[0], diciembre_2022.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",diciembre_2022.turbinacion_bombeo[0], diciembre_2022.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",diciembre_2022.nuclear[0], diciembre_2022.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",diciembre_2022.ciclo_combinado[0], diciembre_2022.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",diciembre_2022.carbon[0],diciembre_2022.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",diciembre_2022.cogeneracion[0], diciembre_2022.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",diciembre_2022.residuos_no_renovables[0], diciembre_2022.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",diciembre_2022.Generacion_No_Renovable[0], diciembre_2022.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",diciembre_2022.consumos_en_bombeo[0], diciembre_2022.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",diciembre_2022.enlace_peninsula_baleares[0], diciembre_2022.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",diciembre_2022.saldo_intercambios_internacionales[0], diciembre_2022.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",diciembre_2022.Demanda[0], diciembre_2022.Demanda[1]);
                printf("\n");

                *hidraulica_0 = diciembre_2022.hidraulica[0];
                *hidraulica_1 = diciembre_2022.hidraulica[1];
                *eolica_0 = diciembre_2022.eolica[0];
                *eolica_1 = diciembre_2022.eolica[1];
                *solar_fotovoltaica_0 = diciembre_2022.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = diciembre_2022.solar_fotovoltaica[1];
                *solar_termica_0 = diciembre_2022.solar_termica[0];
                *solar_termica_1 = diciembre_2022.solar_termica[1];
                *otras_renovables_0 = diciembre_2022.otras_renovables[0];
                *otras_renovables_1 = diciembre_2022.otras_renovables[1];
                *residuos_renovables_0 = diciembre_2022.residuos_renovables[0];
                *residuos_renovables_1 = diciembre_2022.residuos_renovables[1];
                *Generacion_Renovable_0 = diciembre_2022.Generacion_Renovable[0];
                *Generacion_Renovable_1 = diciembre_2022.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = diciembre_2022.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = diciembre_2022.turbinacion_bombeo[1];
                *nuclear_0 = diciembre_2022.nuclear[0];
                *nuclear_1 = diciembre_2022.nuclear[1];
                *ciclo_combinado_0 = diciembre_2022.ciclo_combinado[0];
                *ciclo_combinado_1 = diciembre_2022.ciclo_combinado[1];
                *carbon_0 = diciembre_2022.carbon[0];
                *carbon_1 = diciembre_2022.carbon[1];
                *cogeneracion_0 = diciembre_2022.cogeneracion[0];
                *cogeneracion_1 = diciembre_2022.cogeneracion[1];
                *residuos_no_renovables_0 = diciembre_2022.residuos_no_renovables[0];
                *residuos_no_renovables_1 = diciembre_2022.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = diciembre_2022.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = diciembre_2022.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = diciembre_2022.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = diciembre_2022.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = diciembre_2022.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = diciembre_2022.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = diciembre_2022.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = diciembre_2022.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = diciembre_2022.Demanda[0];
                *Demanda_1 = diciembre_2022.Demanda[1];
            }

            fclose(plectura_2022_diciembre);
        }
    }

    if (anio_mes_void == 2023)
    {
        if (mes_void == 1)
        {
            FILE *plectura_2023_enero;
            plectura_2023_enero = fopen("Ficheros_Comparaciones/2023/2023_enero.csv", "r");
            if (plectura_2023_enero == NULL)
            {
                printf("Error al abrir el fichero de lectura (01/2023).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (01/2023) abierto correctamente.\n");
                printf("\n");

                datos_mes enero_2023;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2023_enero, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &enero_2023.hidraulica [i], &enero_2023.eolica [i], &enero_2023.solar_fotovoltaica [i], &enero_2023.solar_termica [i], &enero_2023.otras_renovables [i], &enero_2023.residuos_renovables [i], &enero_2023.Generacion_Renovable [i], &enero_2023.turbinacion_bombeo [i], &enero_2023.nuclear [i], &enero_2023.ciclo_combinado [i], &enero_2023.carbon [i],&enero_2023.cogeneracion [i], &enero_2023.residuos_no_renovables [i], &enero_2023.Generacion_No_Renovable [i], &enero_2023.consumos_en_bombeo [i], &enero_2023.enlace_peninsula_baleares [i], &enero_2023.saldo_intercambios_internacionales [i], &enero_2023.Demanda [i]);
                }

                printf("                           Enero 2023 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",enero_2023.hidraulica[0], enero_2023.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",enero_2023.eolica[0], enero_2023.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",enero_2023.solar_fotovoltaica[0], enero_2023.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",enero_2023.solar_termica[0], enero_2023.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",enero_2023.otras_renovables[0], enero_2023.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",enero_2023.residuos_renovables[0], enero_2023.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",enero_2023.Generacion_Renovable[0], enero_2023.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",enero_2023.turbinacion_bombeo[0], enero_2023.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",enero_2023.nuclear[0], enero_2023.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",enero_2023.ciclo_combinado[0], enero_2023.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",enero_2023.carbon[0], enero_2023.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",enero_2023.cogeneracion[0], enero_2023.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",enero_2023.residuos_no_renovables[0], enero_2023.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",enero_2023.Generacion_No_Renovable[0], enero_2023.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",enero_2023.consumos_en_bombeo[0], enero_2023.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",enero_2023.enlace_peninsula_baleares[0], enero_2023.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",enero_2023.saldo_intercambios_internacionales[0], enero_2023.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",enero_2023.Demanda[0], enero_2023.Demanda[1]);
                printf("\n");

                *hidraulica_0 = enero_2023.hidraulica[0];
                *hidraulica_1 = enero_2023.hidraulica[1];
                *eolica_0 = enero_2023.eolica[0];
                *eolica_1 = enero_2023.eolica[1];
                *solar_fotovoltaica_0 = enero_2023.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = enero_2023.solar_fotovoltaica[1];
                *solar_termica_0 = enero_2023.solar_termica[0];
                *solar_termica_1 = enero_2023.solar_termica[1];
                *otras_renovables_0 = enero_2023.otras_renovables[0];
                *otras_renovables_1 = enero_2023.otras_renovables[1];
                *residuos_renovables_0 = enero_2023.residuos_renovables[0];
                *residuos_renovables_1 = enero_2023.residuos_renovables[1];
                *Generacion_Renovable_0 = enero_2023.Generacion_Renovable[0];
                *Generacion_Renovable_1 = enero_2023.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = enero_2023.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = enero_2023.turbinacion_bombeo[1];
                *nuclear_0 = enero_2023.nuclear[0];
                *nuclear_1 = enero_2023.nuclear[1];
                *ciclo_combinado_0 = enero_2023.ciclo_combinado[0];
                *ciclo_combinado_1 = enero_2023.ciclo_combinado[1];
                *carbon_0 = enero_2023.carbon[0];
                *carbon_1 = enero_2023.carbon[1];
                *cogeneracion_0 = enero_2023.cogeneracion[0];
                *cogeneracion_1 = enero_2023.cogeneracion[1];
                *residuos_no_renovables_0 = enero_2023.residuos_no_renovables[0];
                *residuos_no_renovables_1 = enero_2023.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = enero_2023.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = enero_2023.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = enero_2023.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = enero_2023.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = enero_2023.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = enero_2023.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = enero_2023.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = enero_2023.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = enero_2023.Demanda[0];
                *Demanda_1 = enero_2023.Demanda[1];
            }

            fclose(plectura_2023_enero);
        }

        if (mes_void == 2)
        {
            FILE *plectura_2023_febrero;
            plectura_2023_febrero = fopen("Ficheros_Comparaciones/2023/2023_febrero.csv", "r");
            if (plectura_2023_febrero == NULL)
            {
                printf("Error al abrir el fichero de lectura (02/2023).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (02/2023) abierto correctamente.\n");
                printf("\n");

                datos_mes febrero_2023;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2023_febrero, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &febrero_2023.hidraulica [i], &febrero_2023.eolica [i], &febrero_2023.solar_fotovoltaica [i], &febrero_2023.solar_termica [i], &febrero_2023.otras_renovables [i], &febrero_2023.residuos_renovables [i], &febrero_2023.Generacion_Renovable [i], &febrero_2023.turbinacion_bombeo [i], &febrero_2023.nuclear [i], &febrero_2023.ciclo_combinado [i], &febrero_2023.carbon [i],&febrero_2023.cogeneracion [i], &febrero_2023.residuos_no_renovables [i], &febrero_2023.Generacion_No_Renovable [i], &febrero_2023.consumos_en_bombeo [i], &febrero_2023.enlace_peninsula_baleares [i], &febrero_2023.saldo_intercambios_internacionales [i], &febrero_2023.Demanda [i]);
                }

                printf("                           Febrero 2023 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",febrero_2023.hidraulica[0], febrero_2023.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",febrero_2023.eolica[0], febrero_2023.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",febrero_2023.solar_fotovoltaica[0], febrero_2023.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",febrero_2023.solar_termica[0], febrero_2023.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",febrero_2023.otras_renovables[0], febrero_2023.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",febrero_2023.residuos_renovables[0], febrero_2023.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",febrero_2023.Generacion_Renovable[0], febrero_2023.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",febrero_2023.turbinacion_bombeo[0], febrero_2023.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",febrero_2023.nuclear[0], febrero_2023.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",febrero_2023.ciclo_combinado[0], febrero_2023.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",febrero_2023.carbon[0], febrero_2023.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",febrero_2023.cogeneracion[0], febrero_2023.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",febrero_2023.residuos_no_renovables[0], febrero_2023.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",febrero_2023.Generacion_No_Renovable[0], febrero_2023.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",febrero_2023.consumos_en_bombeo[0], febrero_2023.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",febrero_2023.enlace_peninsula_baleares[0], febrero_2023.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",febrero_2023.saldo_intercambios_internacionales[0], febrero_2023.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",febrero_2023.Demanda[0], febrero_2023.Demanda[1]);
                printf("\n");

                *hidraulica_0 = febrero_2023.hidraulica[0];
                *hidraulica_1 = febrero_2023.hidraulica[1];
                *eolica_0 = febrero_2023.eolica[0];
                *eolica_1 = febrero_2023.eolica[1];
                *solar_fotovoltaica_0 = febrero_2023.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = febrero_2023.solar_fotovoltaica[1];
                *solar_termica_0 = febrero_2023.solar_termica[0];
                *solar_termica_1 = febrero_2023.solar_termica[1];
                *otras_renovables_0 = febrero_2023.otras_renovables[0];
                *otras_renovables_1 = febrero_2023.otras_renovables[1];
                *residuos_renovables_0 = febrero_2023.residuos_renovables[0];
                *residuos_renovables_1 = febrero_2023.residuos_renovables[1];
                *Generacion_Renovable_0 = febrero_2023.Generacion_Renovable[0];
                *Generacion_Renovable_1 = febrero_2023.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = febrero_2023.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = febrero_2023.turbinacion_bombeo[1];
                *nuclear_0 = febrero_2023.nuclear[0];
                *nuclear_1 = febrero_2023.nuclear[1];
                *ciclo_combinado_0 = febrero_2023.ciclo_combinado[0];
                *ciclo_combinado_1 = febrero_2023.ciclo_combinado[1];
                *carbon_0 = febrero_2023.carbon[0];
                *carbon_1 = febrero_2023.carbon[1];
                *cogeneracion_0 = febrero_2023.cogeneracion[0];
                *cogeneracion_1 = febrero_2023.cogeneracion[1];
                *residuos_no_renovables_0 = febrero_2023.residuos_no_renovables[0];
                *residuos_no_renovables_1 = febrero_2023.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = febrero_2023.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = febrero_2023.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = febrero_2023.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = febrero_2023.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = febrero_2023.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = febrero_2023.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = febrero_2023.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = febrero_2023.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = febrero_2023.Demanda[0];
                *Demanda_1 = febrero_2023.Demanda[1];
            }

            fclose(plectura_2023_febrero);
        }

        if (mes_void == 3)
        {
            FILE *plectura_2023_marzo;
            plectura_2023_marzo = fopen("Ficheros_Comparaciones/2023/2023_marzo.csv", "r");
            if (plectura_2023_marzo == NULL)
            {
                printf("Error al abrir el fichero de lectura (03/2023).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (03/2023) abierto correctamente.\n");
                printf("\n");

                datos_mes marzo_2023;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2023_marzo, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &marzo_2023.hidraulica [i], &marzo_2023.eolica [i], &marzo_2023.solar_fotovoltaica [i], &marzo_2023.solar_termica [i], &marzo_2023.otras_renovables [i], &marzo_2023.residuos_renovables [i], &marzo_2023.Generacion_Renovable [i], &marzo_2023.turbinacion_bombeo [i], &marzo_2023.nuclear [i], &marzo_2023.ciclo_combinado [i], &marzo_2023.carbon [i],&marzo_2023.cogeneracion [i], &marzo_2023.residuos_no_renovables [i], &marzo_2023.Generacion_No_Renovable [i], &marzo_2023.consumos_en_bombeo [i], &marzo_2023.enlace_peninsula_baleares [i], &marzo_2023.saldo_intercambios_internacionales [i], &marzo_2023.Demanda [i]);
                }

                printf("                           Marzo 2023 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",marzo_2023.hidraulica[0], marzo_2023.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",marzo_2023.eolica[0], marzo_2023.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",marzo_2023.solar_fotovoltaica[0], marzo_2023.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",marzo_2023.solar_termica[0], marzo_2023.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",marzo_2023.otras_renovables[0], marzo_2023.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",marzo_2023.residuos_renovables[0], marzo_2023.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",marzo_2023.Generacion_Renovable[0], marzo_2023.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",marzo_2023.turbinacion_bombeo[0], marzo_2023.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",marzo_2023.nuclear[0], marzo_2023.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",marzo_2023.ciclo_combinado[0], marzo_2023.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",marzo_2023.carbon[0], marzo_2023.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",marzo_2023.cogeneracion[0], marzo_2023.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",marzo_2023.residuos_no_renovables[0], marzo_2023.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",marzo_2023.  Generacion_No_Renovable[0], marzo_2023.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",marzo_2023.consumos_en_bombeo[0], marzo_2023.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",marzo_2023.enlace_peninsula_baleares[0], marzo_2023.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",marzo_2023.saldo_intercambios_internacionales[0], marzo_2023.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",marzo_2023.Demanda[0], marzo_2023.Demanda[1]);
                printf("\n");

                *hidraulica_0 = marzo_2023.hidraulica[0];
                *hidraulica_1 = marzo_2023.hidraulica[1];
                *eolica_0 = marzo_2023.eolica[0];
                *eolica_1 = marzo_2023.eolica[1];
                *solar_fotovoltaica_0 = marzo_2023.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = marzo_2023.solar_fotovoltaica[1];
                *solar_termica_0 = marzo_2023.solar_termica[0];
                *solar_termica_1 = marzo_2023.solar_termica[1];
                *otras_renovables_0 = marzo_2023.otras_renovables[0];
                *otras_renovables_1 = marzo_2023.otras_renovables[1];
                *residuos_renovables_0 = marzo_2023.residuos_renovables[0];
                *residuos_renovables_1 = marzo_2023.residuos_renovables[1];
                *Generacion_Renovable_0 = marzo_2023.Generacion_Renovable[0];
                *Generacion_Renovable_1 = marzo_2023.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = marzo_2023.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = marzo_2023.turbinacion_bombeo[1];
                *nuclear_0 = marzo_2023.nuclear[0];
                *nuclear_1 = marzo_2023.nuclear[1];
                *ciclo_combinado_0 = marzo_2023.ciclo_combinado[0];
                *ciclo_combinado_1 = marzo_2023.ciclo_combinado[1];
                *carbon_0 = marzo_2023.carbon[0];
                *carbon_1 = marzo_2023.carbon[1];
                *cogeneracion_0 = marzo_2023.cogeneracion[0];
                *cogeneracion_1 = marzo_2023.cogeneracion[1];
                *residuos_no_renovables_0 = marzo_2023.residuos_no_renovables[0];
                *residuos_no_renovables_1 = marzo_2023.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = marzo_2023.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = marzo_2023.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = marzo_2023.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = marzo_2023.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = marzo_2023.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = marzo_2023.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = marzo_2023.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = marzo_2023.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = marzo_2023.Demanda[0];
                *Demanda_1 = marzo_2023.Demanda[1];  
            }

            fclose(plectura_2023_marzo);
        }

        if (mes_void == 4)
        {
            FILE *plectura_2023_abril;
            plectura_2023_abril = fopen("Ficheros_Comparaciones/2023/2023_abril.csv", "r");
            if (plectura_2023_abril == NULL)
            {
                printf("Error al abrir el fichero de lectura (04/2023).\n");
                printf("\n");
            }
            else
            {
                printf("Fichero de lectura (04/2023) abierto correctamente.\n");
                printf("\n");

                datos_mes abril_2023;

                 for (i = 0; i < N; i++)
                {
                    fscanf(plectura_2023_abril, "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,", &abril_2023.hidraulica [i], &abril_2023.eolica [i], &abril_2023.solar_fotovoltaica [i], &abril_2023.solar_termica [i], &abril_2023.otras_renovables [i], &abril_2023.residuos_renovables [i], &abril_2023.Generacion_Renovable [i], &abril_2023.turbinacion_bombeo [i], &abril_2023.nuclear [i], &abril_2023.ciclo_combinado [i], &abril_2023.carbon [i],&abril_2023.cogeneracion [i], &abril_2023.residuos_no_renovables [i], &abril_2023.Generacion_No_Renovable [i], &abril_2023.consumos_en_bombeo [i], &abril_2023.enlace_peninsula_baleares [i], &abril_2023.saldo_intercambios_internacionales [i], &abril_2023.Demanda [i]);
                }

                printf("                           Abril 2023 (GWh) ||  Acumulado Anual (GWh)  \n");
                printf("  Hidraulica:                           %i   %i  \n",abril_2023.hidraulica[0], abril_2023.hidraulica[1]);
                printf("  Eolica:                               %i   %i  \n",abril_2023.eolica[0], abril_2023.eolica[1]);
                printf("  Solar Fotovoltaica:                   %i   %i  \n",abril_2023.solar_fotovoltaica[0], abril_2023.solar_fotovoltaica[1]);
                printf("  Solar Termica:                        %i   %i  \n",abril_2023.solar_termica[0], abril_2023.solar_termica[1]);
                printf("  Otras Renovables:                     %i   %i  \n",abril_2023.otras_renovables[0], abril_2023.otras_renovables[1]);
                printf("  Residuos Renovables:                  %i   %i  \n",abril_2023.residuos_renovables[0], abril_2023.residuos_renovables[1]);
                printf("  GENERACION RENOVABLE:                 %i   %i  \n",abril_2023.Generacion_Renovable[0], abril_2023.Generacion_Renovable[1]);
                printf("  Turbinacion Bombeo:                   %i   %i  \n",abril_2023.turbinacion_bombeo[0], abril_2023.turbinacion_bombeo[1]);
                printf("  Nuclear:                              %i   %i  \n",abril_2023.nuclear[0], abril_2023.nuclear[1]);
                printf("  Ciclo Combinado:                      %i   %i  \n",abril_2023.ciclo_combinado[0], abril_2023.ciclo_combinado[1]);
                printf("  Carbon:                               %i   %i  \n",abril_2023.carbon[0], abril_2023.carbon[1]);
                printf("  Cogeneracion:                         %i   %i  \n",abril_2023.cogeneracion[0], abril_2023.cogeneracion[1]);
                printf("  Residuos No Renovables:               %i   %i  \n",abril_2023.residuos_no_renovables[0], abril_2023.residuos_no_renovables[1]);
                printf("  GENERACION NO RENOVABLE:              %i   %i  \n",abril_2023.Generacion_No_Renovable[0], abril_2023.Generacion_No_Renovable[1]);
                printf("  Consumos en Bombeo:                   %i   %i  \n",abril_2023.consumos_en_bombeo[0], abril_2023.consumos_en_bombeo[1]);
                printf("  Enlace Peninsula-Baleares:            %i   %i  \n",abril_2023.enlace_peninsula_baleares[0], abril_2023.enlace_peninsula_baleares[1]);
                printf("  Saldo Intercambios Internacionales::  %i   %i  \n",abril_2023.saldo_intercambios_internacionales[0], abril_2023.saldo_intercambios_internacionales[1]);
                printf("  DEMANDA:                              %i   %i  \n",abril_2023.Demanda[0], abril_2023.Demanda[1]);
                printf("\n");

                *hidraulica_0 = abril_2023.hidraulica[0];
                *hidraulica_1 = abril_2023.hidraulica[1];
                *eolica_0 = abril_2023.eolica[0];
                *eolica_1 = abril_2023.eolica[1];
                *solar_fotovoltaica_0 = abril_2023.solar_fotovoltaica[0];
                *solar_fotovoltaica_1 = abril_2023.solar_fotovoltaica[1];
                *solar_termica_0 = abril_2023.solar_termica[0];
                *solar_termica_1 = abril_2023.solar_termica[1];
                *otras_renovables_0 = abril_2023.otras_renovables[0];
                *otras_renovables_1 = abril_2023.otras_renovables[1];
                *residuos_renovables_0 = abril_2023.residuos_renovables[0];
                *residuos_renovables_1 = abril_2023.residuos_renovables[1];
                *Generacion_Renovable_0 = abril_2023.Generacion_Renovable[0];
                *Generacion_Renovable_1 = abril_2023.Generacion_Renovable[1];
                *turbinacion_bombeo_0 = abril_2023.turbinacion_bombeo[0];
                *turbinacion_bombeo_1 = abril_2023.turbinacion_bombeo[1];
                *nuclear_0 = abril_2023.nuclear[0];
                *nuclear_1 = abril_2023.nuclear[1];
                *ciclo_combinado_0 = abril_2023.ciclo_combinado[0];
                *ciclo_combinado_1 = abril_2023.ciclo_combinado[1];
                *carbon_0 = abril_2023.carbon[0];
                *carbon_1 = abril_2023.carbon[1];
                *cogeneracion_0 = abril_2023.cogeneracion[0];
                *cogeneracion_1 = abril_2023.cogeneracion[1];
                *residuos_no_renovables_0 = abril_2023.residuos_no_renovables[0];
                *residuos_no_renovables_1 = abril_2023.residuos_no_renovables[1];
                *Generacion_No_Renovable_0 = abril_2023.Generacion_No_Renovable[0];
                *Generacion_No_Renovable_1 = abril_2023.Generacion_No_Renovable[1];
                *consumos_en_bombeo_0 = abril_2023.consumos_en_bombeo[0];
                *consumos_en_bombeo_1 = abril_2023.consumos_en_bombeo[1];
                *enlace_peninsula_baleares_0 = abril_2023.enlace_peninsula_baleares[0];
                *enlace_peninsula_baleares_1 = abril_2023.enlace_peninsula_baleares[1];
                *saldo_intercambios_internacionales_0 = abril_2023.saldo_intercambios_internacionales[0];
                *saldo_intercambios_internacionales_1 = abril_2023.saldo_intercambios_internacionales[1]; 
                *Demanda_0 = abril_2023.Demanda[0];
                *Demanda_1 = abril_2023.Demanda[1];    
            }

            fclose(plectura_2023_abril);
        }

    }            
}









//funcion principal
void predicciones()
{
	//emisiones de CO2
				void prediccionesemisionco2()
			{
				char menu00[20];
				//vector que guarda datos del fichero
					
					
					void imprimirDatos(energias energia1[], int numDatos,int indice) 
					{
					    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
					                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
						int q=0,r=1;
						
						printf("Emision mensual de: %s\n\n",energia1[indice].nombre);
					    for (q = 0;q<numDatos;q++) 
						{
					        printf("%s 202%i: %f tCO2 eq./MWh\n", meses[q % 12],r,energia1[indice].datos[q]);
					        if(q==11)
					        {
					        	r++;
							}
					    }
					    q=0;
					    printf("\n\n");
					}
					
					void imprimirDatosPredicciones(energias energia1[],int numDatos,int indice) 
					{
					    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
					                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
						int q=0,r=1;
						
						printf("\nEmision mensual de: %s\n\n",energia1[indice].nombre);
					    for (q = 0;q<numDatos;q++) 
						{
					        printf("%s 202%i: %f tCO2 eq./MWh\n", meses[q % 12],r,energia1[indice].datos[q]);
					        if(q==11)
					        {
					        	r++;
							}
					    }
					    q=0;
					    printf("\n\n");
					}
					
					void errorabsolutomedio(energias energia1[], int indice, int fechas) 
					{
					    float vector2021[100];
					    float vector2022[100];
					    int z = 0,w=0;
					    float errorabsolutomedio = 0,dif=0;
					    double sumerrores=0;
					
					    for (z = 0; z < fechas; z++) 
						{
					        if (z < fechas / 2 ) 
							{
					            vector2021[z] = energia1[indice].datos[z];
					            //printf("vector2021 %f\n",vector2021[z]);
					        }
					        if (z > fechas / 2 + 1||z==fechas/2) 
							{
					            break;
					        }
					    }
					    
					    for (w=0,z = z; z<fechas,w<fechas/2; z++,w++)
						{
							if (z < fechas) 
							{
					            vector2022[w] = energia1[indice].datos[z];
					            //printf("vector2022 %f\n",vector2022[z]);
					        }
						} 
						w=0;
					
					    for (z = 0; z < fechas / 2; z++) 
						{
							dif=vector2021[z]-vector2022[z];
					        sumerrores=sumerrores+fabs(vector2021[z]-vector2022[z]);
					        //printf("\nsumaerrore %lf",dif);
					    }
					    z=0;
					    errorabsolutomedio=sumerrores/(fechas/2.0);
					    printf("\nEl error medio absoluto de %s 2021-2022 = %lf tCO2 eq./MWh\n\n", energia1[indice].nombre, errorabsolutomedio);
					}
					
				void errorabsolutomedio2023(energias energia1[], int indice, int fechas)
			{
			    int i = 0, q = 0, r = 2023;
			    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
			                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
			    float sumy = 0, sumx = 0, xpory = 0, sumxcuadrado = 0, mediax = 0, mediay = 0, pendiente = 0, b = 0;
				float errorabsolutomedio = 0,dif=0;
			    for (i = 0; i < fechas; i++) {
			        sumy += energia1[indice].datos[i];
			    }
			    
			    //printf("\nsumy = %f", sumy);
			
			    for (i = 1; i <= fechas; i++) 
				{
			        sumx += i;
			    }
			
			    //printf("\nsumx = %f", sumx);
			
			    for (i = 1, q = 0; i <= fechas && q < fechas; i++, q++) {
			        xpory += i * energia1[indice].datos[q];
			    }
			
			    //printf("\nx por y = %f", xpory);
			
			    for (i = 1; i <= fechas; i++) {
			        sumxcuadrado += i * i;
			    }
			
			    //printf("\nsumxcuadrado = %f", sumxcuadrado);
			
			    mediax = sumx / fechas;
			
			    mediay = sumy / fechas;
			
			    pendiente = (xpory - (sumx * sumy / fechas)) / (sumxcuadrado - (sumx * sumx / fechas));
			
			    b = mediay - pendiente * mediax;
			    
			    for(q=0;q<fechas;q++)
			    {
			    	dif=dif+fabs(energia1[indice].datos[q]-(pendiente*(q + 1) + b));
			    	
				}
				errorabsolutomedio=dif/fechas;
				printf("\nEl error medio absoluto de %s 2023-2022 = %lf tCO2 eq./MWh\n\n", energia1[indice].nombre, errorabsolutomedio);
			    
							i=0;
							q=0;
							pendiente=0;
							b=0;
							mediax=0;
							mediay=0;
							xpory=0;
							sumx=0;
							sumy=0;
							sumxcuadrado=0;
			}	
					
				void rectaregresion(energias energia1[], int indice, int fechas)
			{
			    int i = 0, q = 0, r = 2023;
			    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
			                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
			    float sumy = 0, sumx = 0, xpory = 0, sumxcuadrado = 0, mediax = 0, mediay = 0, pendiente = 0, b = 0;
			
			    for (i = 0; i < fechas; i++) {
			        sumy += energia1[indice].datos[i];
			    }
			    
			    //printf("\nsumy = %f", sumy);
			
			    for (i = 1; i <= fechas; i++) 
				{
			        sumx += i;
			    }
			
			    //printf("\nsumx = %f", sumx);
			
			    for (i = 1, q = 0; i <= fechas && q < fechas; i++, q++) {
			        xpory += i * energia1[indice].datos[q];
			    }
			
			    //printf("\nx por y = %f", xpory);
			
			    for (i = 1; i <= fechas; i++) {
			        sumxcuadrado += i * i;
			    }
			
			    //printf("\nsumxcuadrado = %f", sumxcuadrado);
			
			    mediax = sumx / fechas;
			
			    mediay = sumy / fechas;
			
			    pendiente = (xpory - (sumx * sumy / fechas)) / (sumxcuadrado - (sumx * sumx / fechas));
			
			    b = mediay - pendiente * mediax;
			    
			
			    printf("\n\n%s en 2023: \n", energia1[indice].nombre);
			    printf("\nEmision mensual de: %s\n\n", energia1[indice].nombre);
			
			    for (q = 0; q < fechas; q++) 
				{
			        printf("%s 2023: %f tCO2 eq./MWh\n", meses[q % 12], pendiente * (q + 1) + b);
			        if (q == 11) {
			            r++;
			        }
			    }
			    printf("\nmedia de dias = %f dias", mediax);
			    printf("\nmedia de emision = %f tCO2 eq./MWh", mediay);
			    printf("\npendiente recta = %f", pendiente);
			    printf("\nb = %f\n\n", b);
							i=0;
							q=0;
							pendiente=0;
							b=0;
							mediax=0;
							mediay=0;
							xpory=0;
							sumx=0;
							sumy=0;
							sumxcuadrado=0;
			}	
					
						lectores_e lectores0_e[20];
						prediccion predicciones[20];
						energias energia[20];
						FILE*fichero;
						char opcion6[20],lector_0_e[10000],lectorfechas_e[300],lector[10000],lector2[5000],copia1[5000],copiareal[10000],menu[20],menu0[20],opcion1[20],opcion2[20],opcion3[20],opcion4[20],opcion5[20];
						int error=0,i=0,j=0,contpuntos=0,contfechas_e=0,contfilas_e=0,energiastot_e=0,energiapredecir=0,conttrabajado_e=0,k=0,l=0,m=0,o=0,p=0;
						float num[100];
						
						
						
						fichero=fopen("Ficheros_Predicciones/emisiones_y_factor_de_emision_(1).csv","r");
						if(fichero==NULL)
						{
							printf("no abierto correctamente");
							error=1;
						}
						
						while(fscanf(fichero,"%c",&lector_0_e[i])!=EOF)
						{
							i++;
						}
						lector_0_e[i]='\0';
						//printf("%s",lector);
						if(fichero!=NULL)
						{
						fclose(fichero);
						}
						
						for(i=0;i<strlen(lector_0_e);i++)
						{
							lectorfechas_e[i]=lector_0_e[i];
							if(lector_0_e[i]=='\n')
							{
								lectorfechas_e[i]='\n';
								lectorfechas_e[i+1]='\0';
								for(j=i+1;j<strlen(lector_0_e);j++)
								{
									lector[k]=lector_0_e[j];
									k++;
								}
								lector[k]='\0';
								break;
							}
						}
						
						for(i=0;i<strlen(lectorfechas_e);i++)
						{
							if(lectorfechas_e[i]==',')
							{
								contfechas_e++;
							}
						}
						strcat(lectorfechas_e,lector);
						strcpy(copiareal,lectorfechas_e);
						k=0;
						j=0;
						k=0;
						
						//printf("Numero de meses analizados desde 2021 a 2022 = %i\n\n",contfechas_e);
					
						
						
						for(i=0;i<strlen(lector);i++)
						{
							lectores0_e[j].lector0_e[k]=lector[i];
							if(lectores0_e[j].lector0_e[k]=='\n')
							{
								lectores0_e[j].lector0_e[k+1]='\0';
								j++;
								k=0;
								contfilas_e++;
								continue;
							}
							k++;
						}
						k=0;
						i=0;
						for(i=0;i<j;i++)
						{
							for(k=0;k<1000;k++)
							{
								if (lectores0_e[i].lector0_e[k]==' ')
								{
									lectores0_e[i].lector0_e[k]='_';
								}
								if (lectores0_e[i].lector0_e[k]=='\0')
								{
									k=0;
									break;
								}
							}
						}
						
						i=0;
						k=0;
						j=0;
						
						
						//hasta aquí se guardan los datos en vectores, por filas, luego se hara el fichero de una linea
						while(conttrabajado_e<=contfilas_e-1)
						{
							fichero=fopen("Ficheros_Predicciones/emisiones_y_factor_de_emision_(1).csv","w");
								if(fichero==NULL)
								{
									printf("no abierto correctamente");
									error=1;
								}
								
										if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
								
								fprintf(fichero,"%s",lectores0_e[o].lector0_e);
								if(fichero!=NULL)
								{
								fclose(fichero);
								}
									
								
								for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
							    {
							    	if(lectores0_e[o].lector0_e[i]==',')
							    	{
							    		lectores0_e[o].lector0_e[i]='.';
									}
									if(lectores0_e[o].lector0_e[i]=='"')
									{
										lectores0_e[o].lector0_e[i]=' ';
									}
								}
								lectores0_e[o].lector0_e[i]='\0';
								
								
								for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
								{
									if(lectores0_e[o].lector0_e[i]==' ')
									{
										lectores0_e[o].lector0_e[i]='\n';
									}
								}
								lectores0_e[o].lector0_e[i]='\0';
							for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
								{
									if(lectores0_e[o].lector0_e[i]=='.')
									{
										contpuntos++;
									}
								}
							
								
								fichero=fopen("Ficheros_Predicciones/emisiones_y_factor_de_emision_(1).csv","w");
								if(fichero==NULL)
								{
									printf("no abierto correctamente");
									error=1;
								}
								
										if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
								
								fprintf(fichero,"%s",lectores0_e[o].lector0_e);
								if(fichero!=NULL)
								{
								fclose(fichero);
								}
								
							fichero = fopen("Ficheros_Predicciones/emisiones_y_factor_de_emision_(1).csv", "r");
							if (fichero == NULL) 
							{
							    printf("Error al abrir el archivo\n");
							    error=1;
							}
							
							i = 0;
							int num_puntos = 0;
							while (fscanf(fichero, "%c", &lector2[i]) != EOF) 
							{
							    if (lector2[i] == '.') 
								{
							        contpuntos++;
							    }
							    i++;
							}
							lector2[i] = '\0';
							if(fichero!=NULL)
							{
							fclose(fichero);
							}
							
							
							j = 1;
							for (i = 0; i < strlen(lector2); i++) 
							{
							    if (lector2[i] == '.' && j % 2 == 1) 
								{
							        lector2[i] = ' ';
							        j++;
							    }
								if (lector2[i] == '.') 
								{
							        j++;
							    }
							}
							//printf("%s",lector2);
							//hasta aqui es perfeccion
							
							fichero = fopen("Ficheros_Predicciones/emisiones_y_factor_de_emision_(1).csv", "w");
							if (fichero == NULL) 
							{
							    printf("Error al abrir el archivo\n");
							    error=1;
							}
							
									if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
							
							fprintf(fichero,"%s",lector2);
							//printf("%s\n\n",lector2);
							if(fichero!=NULL)
							{
							fclose(fichero);
							}
							
							//sigue siendo bueno
							fichero = fopen("Ficheros_Predicciones/emisiones_y_factor_de_emision_(1).csv", "r");
							    if (fichero == NULL) 
								{
							        printf("Error al abrir el archivo\n");
							        error=1;
							    }
							    
								    if (error == 1) 
							{
						        printf("Ocurrió un error en la función predicciones.\n");
						        return;
						    }
							
							    // Leer la primera palabra y almacenarla en la estructura
							    fscanf(fichero, "%s", energia[0+l].nombre);
								i=0;
							    // Leer los datos y almacenarlos en el vector de la estructura
							    while (fscanf(fichero, "%lf", &energia[0+l].datos[i]) != EOF) 
								{
							        i++;
							    
							    }
							    
							    if(fichero!=NULL)
							    {
							    fclose(fichero);
								}
								
								for(k=0;k<strlen(energia[0+l].nombre);k++)
								{
									if(energia[0+l].nombre[k]=='_')
									{
										energia[0+l].nombre[k]=' ';
									}
								}
								energia[0+l].nombre[k]='\0';
								
								
								/*imprimirDatos(energia,contfechas_e,0+l);*/
								
								
							conttrabajado_e++;
							o++;
							l++;
							k=0;
							energiastot_e=l;
							//printf("\n\nenergiastot=%i\n\ncontfechas_e=%i",energiastot_e,contfechas_e);
						}
						
						
						fichero = fopen("Ficheros_Predicciones/emisiones_y_factor_de_emision_(1).csv", "w");
						if (fichero == NULL) 
						{
						    printf("Error al abrir el archivo\n");
						    error=1;
						}
						
							if (error == 1) 
							{
						        printf("Ocurrió un error en la función predicciones.\n");
						        return;
						    }
						
						fprintf(fichero,"%s",copiareal);
						if(fichero!=NULL)
						{
						fclose(fichero);
						}
						//printf("energias totales analizadas = %i\n\n",energiastot_e);
						i=0;
						//analisis de fichero acaba aqui//
						do 
						{
				        printf("\nBIENVENIDO A LA FUNCION DE PREDICCIONES\n\nEscoja una opcion:\n");
				        printf("1. Mostrar datos disponibles\n2. Error absoluto medio de los datos de 2022 respecto 2021\n3. Predicciones para el anio 2023\n4. Volver al menu de predicciones\n\n");
				        scanf(" %[^\n]",menu0);
				        
				        if(strcasecmp(menu0,"Opcion 1")==0||strcasecmp(menu0,"1")==0||strcasecmp(menu0,"Mostrar datos disponibles")==0)
				        {
				        	//printf("\nELIGIO OPCION 1\n\n");
				        	printf("\n1. Mostrar todos los datos disponibles\n2. Elegir un tipo especifico\n");
				        	scanf(" %[^\n]",opcion1);
				        	
				        	if(strcasecmp(opcion1,"1")==0||strcasecmp(opcion1,"todos los datos")==0||strcasecmp(opcion1,"todos los datos disponibles")==0||strcasecmp(opcion1,"mostrar todos los datos disponibles")==0||strcasecmp(opcion1,"todos los datos disponibles")==0||strcasecmp(opcion1,"los disponibles")==0)
				        	{
								for(i=0;i<energiastot_e;i++)
								{
									printf("\n");
									imprimirDatos(energia,contfechas_e,0+i);
								}
								i=0;
							}
							
							if(strcasecmp(opcion1,"2")==0||strcasecmp(opcion1,"Elegir un tipo especifico")==0||strcasecmp(opcion1,"un tipo especifico")==0||strcasecmp(opcion1,"especifico")==0)
							{
								printf("\n\nEscriba el nombre del tipo en especifico para mostrar en pantalla:\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion2);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion2,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								
								i=0;
								energiapredecir--;
								//printf("%s\n\n",energia[energiapredecir].nombre);
								imprimirDatosPredicciones(energia,contfechas_e,energiapredecir);
							}
						}
							
						if(strcasecmp(menu0,"2")==0||strcasecmp(menu0,"Error")==0||strcasecmp(menu0,"error absoluto")==0||strcasecmp(menu0,"error absoluto medio")==0)
							{
								printf("\nEscriba el nombre del tipo en especifico para calcular el error absoluto medio entre 2021-2022\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion3);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion3,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								if(strcasecmp(opcion3,energia[i].nombre)!=0)
								{
									printf("\n\n\n\n");
									continue;
								}
								i=0;
								energiapredecir--;
								errorabsolutomedio(energia,energiapredecir, contfechas_e);
							}
							
						if(strcasecmp(menu0,"3")==0||strcasecmp(menu0,"Predicciones para el anio 2023")==0||strcasecmp(menu0,"predicciones")==0)
						{
							printf("\n1. Mostrar predicciones de todos los tipos de emisores de CO2\n2. Elegir un tipo especifico para mostrar una prediccion a futuro\n3. Error absoluto medio de las predicciones de 2023 respecto 2022\n");
				        	scanf(" %[^\n]",opcion4);
				        	
				        	if(strcasecmp(opcion4,"1")==0||strcasecmp(opcion4,"Mostrar predicciones de todos los tipos de emisores de CO2")==0||strcasecmp(opcion4,"todos los tipos de emisores")==0||strcasecmp(opcion4,"todos los tipos")==0||strcasecmp(opcion4,"todos los datos disponibles")==0||strcasecmp(opcion4,"todos los tipos de emisores")==0)
				        	{
				        		for(i=0;i<energiastot_e;i++) 
				        		{
				        			
									rectaregresion(energia,i,contfechas_e/2);
									
								}
								i=0;
								j=0;
							}
							
							if(strcasecmp(opcion4, "2") == 0 || strcasecmp(opcion4, "Elegir un tipo especifico para mostrar una prediccion a futuro") == 0 || strcasecmp(opcion4, "un tipo especifico") == 0 || strcasecmp(opcion4, "elegir un tipo especifico para mostrar") == 0)
							{
								printf("\nEscriba el nombre del tipo en especifico para ver una prediccion de los datos para 2023\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion5);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion5,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								i=0;
								energiapredecir--;
								rectaregresion(energia,energiapredecir,contfechas_e/2);
							}
							
							if(strcasecmp(opcion4, "3") == 0 || strcasecmp(opcion4, "Error absoluto medio de las predicciones de 2023 respecto 2022") == 0 || strcasecmp(opcion4, "Error absoluto medio") == 0 || strcasecmp(opcion4, "Error absoluto medio de las predicciones de 2023") == 0)
							{
								printf("\nEscriba el nombre del tipo en especifico para calcular el error absoluto medio de 2023 respecto 2022\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion6);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion6,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								i=0;
								energiapredecir--;
								errorabsolutomedio2023(energia,energiapredecir,contfechas_e/2);
							}
						}
						if((strcasecmp(menu0,"4")==0||strcasecmp(menu0,"Volver al menu de predicciones")==0||strcasecmp(menu0,"Volver a predicciones")==0||strcasecmp(menu0,"SALIR")==0))
						{
							printf("\n\n");
							break;
						}
						printf("\n\n");
				    	} while (strcmp(menu0,"ñ")!=0);
						
						//final
						if (error == 1) 
						{
					        printf("Ocurrio un error en la funcion predicciones.\n");
					        return;
						}
						printf("\n\n");
					}
						
				
				
				
				//predicciones evolucion potencia instalada
				void prediccionesevpi()
			{
				char menu00[20];
					//
					
					void imprimirDatos(energias energia1[], int numDatos,int indice) 
					{
					    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
					                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
						int q=0,r=1;
						
						printf("Evolucion mensual de: %s\n\n",energia1[indice].nombre);
					    for (q = 0;q<numDatos;q++) 
						{
					        printf("%s 202%i: %f 0/0\n", meses[q % 12],r,energia1[indice].datos[q]);
					        if(q==11)
					        {
					        	r++;
							}
					    }
					    q=0;
					    printf("\n\n");
					}
					
					void imprimirDatosPredicciones(energias energia1[],int numDatos,int indice) 
					{
					    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
					                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
						int q=0,r=1;
						
						printf("\nEvolucion mensual de: %s\n\n",energia1[indice].nombre);
					    for (q = 0;q<numDatos;q++) 
						{
					        printf("%s 202%i: %f 0/0\n", meses[q % 12],r,energia1[indice].datos[q]);
					        if(q==11)
					        {
					        	r++;
							}
					    }
					    q=0;
					    printf("\n\n");
					}
					
					void errorabsolutomedio(energias energia1[], int indice, int fechas) 
					{
					    float vector2021[100];
					    float vector2022[100];
					    int z = 0,w=0;
					    float errorabsolutomedio = 0,dif=0;
					    double sumerrores=0;
					
					    for (z = 0; z < fechas; z++) 
						{
					        if (z < fechas / 2 ) 
							{
					            vector2021[z] = energia1[indice].datos[z];
					            //printf("vector2021 %f\n",vector2021[z]);
					        }
					        if (z > fechas / 2 + 1||z==fechas/2) 
							{
					            break;
					        }
					    }
					    
					    for (w=0,z = z; z<fechas,w<fechas/2; z++,w++)
						{
							if (z < fechas) 
							{
					            vector2022[w] = energia1[indice].datos[z];
					            //printf("vector2022 %f\n",vector2022[z]);
					        }
						} 
						w=0;
					
					    for (z = 0; z < fechas / 2; z++) 
						{
							dif=vector2021[z]-vector2022[z];
					        sumerrores=sumerrores+fabs(vector2021[z]-vector2022[z]);
					        //printf("\nsumaerrore %lf",dif);
					    }
					    z=0;
					    errorabsolutomedio=sumerrores/(fechas/2.0);
					    printf("\nEl error medio absoluto de %s 2021-2022 = %lf 0/0\n\n", energia1[indice].nombre, errorabsolutomedio);
					}
					
				void errorabsolutomedio2023(energias energia1[], int indice, int fechas)
			{
			    int i = 0, q = 0, r = 2023;
			    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
			                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
			    float sumy = 0, sumx = 0, xpory = 0, sumxcuadrado = 0, mediax = 0, mediay = 0, pendiente = 0, b = 0;
				float errorabsolutomedio = 0,dif=0;
			    for (i = 0; i < fechas; i++) {
			        sumy += energia1[indice].datos[i];
			    }
			    
			    //printf("\nsumy = %f", sumy);
			
			    for (i = 1; i <= fechas; i++) 
				{
			        sumx += i;
			    }
			
			    //printf("\nsumx = %f", sumx);
			
			    for (i = 1, q = 0; i <= fechas && q < fechas; i++, q++) {
			        xpory += i * energia1[indice].datos[q];
			    }
			
			    //printf("\nx por y = %f", xpory);
			
			    for (i = 1; i <= fechas; i++) {
			        sumxcuadrado += i * i;
			    }
			
			    //printf("\nsumxcuadrado = %f", sumxcuadrado);
			
			    mediax = sumx / fechas;
			
			    mediay = sumy / fechas;
			
			    pendiente = (xpory - (sumx * sumy / fechas)) / (sumxcuadrado - (sumx * sumx / fechas));
			
			    b = mediay - pendiente * mediax;
			    
			    for(q=0;q<fechas;q++)
			    {
			    	dif=dif+fabs(energia1[indice].datos[q]-(pendiente*(q + 1) + b));
			    	
				}
				errorabsolutomedio=dif/fechas;
				printf("\nEl error medio absoluto de %s 2023-2022 = %lf 0/0\n\n", energia1[indice].nombre, errorabsolutomedio);
			    
							i=0;
							q=0;
							pendiente=0;
							b=0;
							mediax=0;
							mediay=0;
							xpory=0;
							sumx=0;
							sumy=0;
							sumxcuadrado=0;
			}	
					
				void rectaregresion(energias energia1[], int indice, int fechas)
			{
			    int i = 0, q = 0, r = 2023;
			    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
			                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
			    float sumy = 0, sumx = 0, xpory = 0, sumxcuadrado = 0, mediax = 0, mediay = 0, pendiente = 0, b = 0;
			
			    for (i = 0; i < fechas; i++) {
			        sumy += energia1[indice].datos[i];
			    }
			    
			    //printf("\nsumy = %f", sumy);
			
			    for (i = 1; i <= fechas; i++) 
				{
			        sumx += i;
			    }
			
			    //printf("\nsumx = %f", sumx);
			
			    for (i = 1, q = 0; i <= fechas && q < fechas; i++, q++) {
			        xpory += i * energia1[indice].datos[q];
			    }
			
			    //printf("\nx por y = %f", xpory);
			
			    for (i = 1; i <= fechas; i++) {
			        sumxcuadrado += i * i;
			    }
			
			    //printf("\nsumxcuadrado = %f", sumxcuadrado);
			
			    mediax = sumx / fechas;
			
			    mediay = sumy / fechas;
			
			    pendiente = (xpory - (sumx * sumy / fechas)) / (sumxcuadrado - (sumx * sumx / fechas));
			
			    b = mediay - pendiente * mediax;
			    
			
			    printf("\n\n%s en 2023: \n", energia1[indice].nombre);
			    printf("\nEvolucion mensual de: %s\n\n", energia1[indice].nombre);
			
			    for (q = 0; q < fechas; q++) 
				{
			        printf("%s 2023: %f 0/0\n", meses[q % 12], pendiente * (q + 1) + b);
			        if (q == 11) {
			            r++;
			        }
			    }
			    printf("\nmedia de dias = %f dias", mediax);
			    printf("\nmedia de evolucion de  potencia instalada= %f 0/0", mediay);
			    printf("\npendiente recta = %f", pendiente);
			    printf("\nb = %f\n\n", b);
							i=0;
							q=0;
							pendiente=0;
							b=0;
							mediax=0;
							mediay=0;
							xpory=0;
							sumx=0;
							sumy=0;
							sumxcuadrado=0;
			}	
					
						lectores_e lectores0_e[20];
						prediccion predicciones[20];
						energias energia[20];
						FILE*fichero;
						char opcion6[20],lector_0_e[10000],lectorfechas_e[300],lector[10000],lector2[5000],copia1[5000],copiareal[10000],menu[20],menu0[20],opcion1[20],opcion2[20],opcion3[20],opcion4[20],opcion5[20];
						int error=0,i=0,j=0,contpuntos=0,contfechas_e=0,contfilas_e=0,energiastot_e=0,energiapredecir=0,conttrabajado_e=0,k=0,l=0,m=0,o=0,p=0;
						float num[100];
						
						
						fichero=fopen("Ficheros_Predicciones/evolucion_potencia_instalada.csv","r");
						if(fichero==NULL)
						{
							printf("no abierto correctamente");
							error=1;
						}
						
						while(fscanf(fichero,"%c",&lector_0_e[i])!=EOF)
						{
							i++;
						}
						lector_0_e[i]='\0';
						//printf("%s",lector);
						if(fichero!=NULL)
						{
						fclose(fichero);
						}
						
						for(i=0;i<strlen(lector_0_e);i++)
						{
							lectorfechas_e[i]=lector_0_e[i];
							if(lector_0_e[i]=='\n')
							{
								lectorfechas_e[i]='\n';
								lectorfechas_e[i+1]='\0';
								for(j=i+1;j<strlen(lector_0_e);j++)
								{
									lector[k]=lector_0_e[j];
									k++;
								}
								lector[k]='\0';
								break;
							}
						}
						
						for(i=0;i<strlen(lectorfechas_e);i++)
						{
							if(lectorfechas_e[i]==',')
							{
								contfechas_e++;
							}
						}
						strcat(lectorfechas_e,lector);
						strcpy(copiareal,lectorfechas_e);
						k=0;
						j=0;
						k=0;
						
						//printf("Numero de meses analizados desde 2021 a 2022 = %i\n\n",contfechas_e);
					
						
						
						for(i=0;i<strlen(lector);i++)
						{
							lectores0_e[j].lector0_e[k]=lector[i];
							if(lectores0_e[j].lector0_e[k]=='\n')
							{
								lectores0_e[j].lector0_e[k+1]='\0';
								j++;
								k=0;
								contfilas_e++;
								continue;
							}
							k++;
						}
						k=0;
						i=0;
						for(i=0;i<j;i++)
						{
							for(k=0;k<1000;k++)
							{
								if (lectores0_e[i].lector0_e[k]==' ')
								{
									lectores0_e[i].lector0_e[k]='_';
								}
								if (lectores0_e[i].lector0_e[k]=='\0')
								{
									k=0;
									break;
								}
							}
						}
						
						i=0;
						k=0;
						j=0;
						
						
						//hasta aquí se guardan los datos en vectores, por filas, luego se hara el fichero de una linea
						while(conttrabajado_e<=contfilas_e-1)
						{
							fichero=fopen("Ficheros_Predicciones/evolucion_potencia_instalada.csv","w");
								if(fichero==NULL)
								{
									printf("no abierto correctamente");
									error=1;
								}
								
										if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
								
								fprintf(fichero,"%s",lectores0_e[o].lector0_e);
								if(fichero!=NULL)
								{
								fclose(fichero);
								}
									
								
								for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
							    {
							    	if(lectores0_e[o].lector0_e[i]==',')
							    	{
							    		lectores0_e[o].lector0_e[i]='.';
									}
									if(lectores0_e[o].lector0_e[i]=='"')
									{
										lectores0_e[o].lector0_e[i]=' ';
									}
								}
								lectores0_e[o].lector0_e[i]='\0';
								
								
								for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
								{
									if(lectores0_e[o].lector0_e[i]==' ')
									{
										lectores0_e[o].lector0_e[i]='\n';
									}
								}
								lectores0_e[o].lector0_e[i]='\0';
							for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
								{
									if(lectores0_e[o].lector0_e[i]=='.')
									{
										contpuntos++;
									}
								}
							
								
								fichero=fopen("Ficheros_Predicciones/evolucion_potencia_instalada.csv","w");
								if(fichero==NULL)
								{
									printf("no abierto correctamente");
									error=1;
								}
								
										if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
								
								fprintf(fichero,"%s",lectores0_e[o].lector0_e);
								if(fichero!=NULL)
								{
								fclose(fichero);
								}
								
							fichero = fopen("Ficheros_Predicciones/evolucion_potencia_instalada.csv", "r");
							if (fichero == NULL) 
							{
							    printf("Error al abrir el archivo\n");
							    error=1;
							}
							
							i = 0;
							int num_puntos = 0;
							while (fscanf(fichero, "%c", &lector2[i]) != EOF) 
							{
							    if (lector2[i] == '.') 
								{
							        contpuntos++;
							    }
							    i++;
							}
							lector2[i] = '\0';
							if(fichero!=NULL)
							{
							fclose(fichero);
							}
							
							
							j = 1;
							for (i = 0; i < strlen(lector2); i++) 
							{
							    if (lector2[i] == '.' && j % 2 == 1) 
								{
							        lector2[i] = ' ';
							        j++;
							    }
								if (lector2[i] == '.') 
								{
							        j++;
							    }
							}
							//printf("%s",lector2);
							//hasta aqui es perfeccion
							
							fichero = fopen("Ficheros_Predicciones/evolucion_potencia_instalada.csv", "w");
							if (fichero == NULL) 
							{
							    printf("Error al abrir el archivo\n");
							    error=1;
							}
							
									if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
							
							fprintf(fichero,"%s",lector2);
							if(fichero!=NULL)
							{
							fclose(fichero);
							}
							
							//sigue siendo bueno
							fichero = fopen("Ficheros_Predicciones/evolucion_potencia_instalada.csv", "r");
							    if (fichero == NULL) 
								{
							        printf("Error al abrir el archivo\n");
							        error=1;
							    }
							    
								    if (error == 1) 
							{
						        printf("Ocurrió un error en la función predicciones.\n");
						        return;
						    }
							
							    // Leer la primera palabra y almacenarla en la estructura
							    fscanf(fichero, "%s", energia[0+l].nombre);
								i=0;
							    // Leer los datos y almacenarlos en el vector de la estructura
							    while (fscanf(fichero, "%lf", &energia[0+l].datos[i]) != EOF) 
								{
							        i++;
							    }
							    if(fichero!=NULL)
							    {
							    fclose(fichero);
								}
								
								for(k=0;k<strlen(energia[0+l].nombre);k++)
								{
									if(energia[0+l].nombre[k]=='_')
									{
										energia[0+l].nombre[k]=' ';
									}
								}
								energia[0+l].nombre[k]='\0';
								
								
								/*imprimirDatos(energia,contfechas_e,0+l);*/
								
								
							conttrabajado_e++;
							o++;
							l++;
							k=0;
							energiastot_e=l;
						}
						
						
						fichero = fopen("Ficheros_Predicciones/evolucion_potencia_instalada.csv", "w");
						if (fichero == NULL) 
						{
						    printf("Error al abrir el archivo\n");
						    error=1;
						}
						
							if (error == 1) 
							{
						        printf("Ocurrió un error en la función predicciones.\n");
						        return;
						    }
						
						fprintf(fichero,"%s",copiareal);
						if(fichero!=NULL)
						{
						fclose(fichero);
						}
						//printf("energias totales analizadas = %i\n\n",energiastot_e);
						i=0;
						//analisis de fichero acaba aqui//
						do 
						{
				        printf("\nBIENVENIDO A LA FUNCION DE PREDICCIONES\n\nEscoja una opcion:\n");
				        printf("1. Mostrar datos disponibles\n2. Error absoluto medio de los datos de 2022 respecto 2021\n3. Predicciones para el anio 2023\n4. Volver al menu de predicciones\n\n");
				        scanf(" %[^\n]",menu0);
				        
				        if(strcasecmp(menu0,"Opcion 1")==0||strcasecmp(menu0,"1")==0||strcasecmp(menu0,"Mostrar datos disponibles")==0)
				        {
				        	//printf("\nELIGIO OPCION 1\n\n");
				        	printf("\n1. Mostrar todos los datos disponibles\n2. Elegir un tipo especifico\n");
				        	scanf(" %[^\n]",opcion1);
				        	
				        	if(strcasecmp(opcion1,"1")==0||strcasecmp(opcion1,"todos los datos")==0||strcasecmp(opcion1,"todos los datos disponibles")==0||strcasecmp(opcion1,"mostrar todos los datos disponibles")==0||strcasecmp(opcion1,"todos los datos disponibles")==0||strcasecmp(opcion1,"los disponibles")==0)
				        	{
								for(i=0;i<energiastot_e;i++)
								{
									printf("\n");
									imprimirDatos(energia,contfechas_e,0+i);
								}
								i=0;
							}
							
							if(strcasecmp(opcion1,"2")==0||strcasecmp(opcion1,"Elegir un tipo especifico")==0||strcasecmp(opcion1,"un tipo especifico")==0||strcasecmp(opcion1,"especifico")==0)
							{
								printf("\n\nEscriba el nombre del tipo en especifico para mostrar en pantalla:\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion2);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion2,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								
								i=0;
								energiapredecir--;
								//printf("%s\n\n",energia[energiapredecir].nombre);
								imprimirDatosPredicciones(energia,contfechas_e,energiapredecir);
							}
						}
							
						if(strcasecmp(menu0,"2")==0||strcasecmp(menu0,"Error")==0||strcasecmp(menu0,"error absoluto")==0||strcasecmp(menu0,"error absoluto medio")==0)
							{
								printf("\nEscriba el nombre del tipo en especifico para calcular el error absoluto medio entre 2021-2022\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion3);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion3,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								if(strcasecmp(opcion3,energia[i].nombre)!=0)
								{
									printf("\n\n\n\n");
									continue;
								}
								i=0;
								energiapredecir--;
								errorabsolutomedio(energia,energiapredecir, contfechas_e);
							}
							
						if(strcasecmp(menu0,"3")==0||strcasecmp(menu0,"Predicciones para el anio 2023")==0||strcasecmp(menu0,"predicciones")==0)
						{
							printf("\n1. Mostrar predicciones de todos los tipos (renovables y no renovables)\n2. Elegir un tipo especifico para mostrar una prediccion a futuro\n3. Error absoluto medio de las predicciones de 2023 respecto 2022\n");
				        	scanf(" %[^\n]",opcion4);
				        	
				        	if(strcasecmp(opcion4,"1")==0||strcasecmp(opcion4,"Mostrar predicciones de todos los (renovables y no renovables)")==0||strcasecmp(opcion4,"renovables y no renovables")==0||strcasecmp(opcion4,"todos los tipos")==0||strcasecmp(opcion4,"todos los datos disponibles")==0||strcasecmp(opcion4,"todos")==0)
				        	{
				        		for(i=0;i<energiastot_e;i++) 
				        		{
				        			
									rectaregresion(energia,i,contfechas_e/2);
									
								}
								i=0;
								j=0;
							}
							
							if(strcasecmp(opcion4, "2") == 0 || strcasecmp(opcion4, "Elegir un tipo especifico para mostrar una prediccion a futuro") == 0 || strcasecmp(opcion4, "un tipo especifico") == 0 || strcasecmp(opcion4, "elegir un tipo especifico para mostrar") == 0)
							{
								printf("\nEscriba el nombre del tipo en especifico para ver una prediccion de los datos para 2023\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion5);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion5,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								i=0;
								energiapredecir--;
								rectaregresion(energia,energiapredecir,contfechas_e/2);
							}
							
							if(strcasecmp(opcion4, "3") == 0 || strcasecmp(opcion4, "Error absoluto medio de las predicciones de 2023 respecto 2022") == 0 || strcasecmp(opcion4, "Error absoluto medio") == 0 || strcasecmp(opcion4, "Error absoluto medio de las predicciones de 2023") == 0)
							{
								printf("\nEscriba el nombre del tipo en especifico para calcular el error absoluto medio de 2023 respecto 2022\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion6);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion6,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								i=0;
								energiapredecir--;
								errorabsolutomedio2023(energia,energiapredecir,contfechas_e/2);
							}
						}
						if((strcasecmp(menu0,"4")==0||strcasecmp(menu0,"volver al menu de predicciones")==0||strcasecmp(menu0,"volver al menu")==0||strcasecmp(menu0,"SALIR")==0))
						{
							printf("\n\n");
							break;
						}
						printf("\n\n");
				    	} while (strcmp(menu0,"ñ")!=0);
						
						//final
						if (error == 1) 
						{
					        printf("Ocurrio un error en la funcion predicciones.\n");
					        return;
						}
				}
			
			
				
				//predicciones generacion mensual
				void prediccionesgeneracionmensual()
			{
				char menu00[20];
					//
					
					void imprimirDatos(energias energia1[], int numDatos,int indice) 
					{
					    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
					                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
						int q=0,r=1;
						
						printf("Generacion mensual de: %s\n\n",energia1[indice].nombre);
					    for (q = 0;q<numDatos;q++) 
						{
					        printf("%s 202%i: %f GWh\n", meses[q % 12],r,energia1[indice].datos[q]);
					        if(q==11)
					        {
					        	r++;
							}
					    }
					    q=0;
					    printf("\n\n");
					}
					
					void imprimirDatosPredicciones(energias energia1[],int numDatos,int indice) 
					{
					    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
					                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
						int q=0,r=1;
						
						printf("\nGeneracion mensual de: %s\n\n",energia1[indice].nombre);
					    for (q = 0;q<numDatos;q++) 
						{
					        printf("%s 202%i: %f GWh\n", meses[q % 12],r,energia1[indice].datos[q]);
					        if(q==11)
					        {
					        	r++;
							}
					    }
					    q=0;
					    printf("\n\n");
					}
					
					void errorabsolutomedio(energias energia1[], int indice, int fechas) 
					{
					    float vector2021[100];
					    float vector2022[100];
					    int z = 0,w=0;
					    float errorabsolutomedio = 0,dif=0;
					    double sumerrores=0;
					
					    for (z = 0; z < fechas; z++) 
						{
					        if (z < fechas / 2 ) 
							{
					            vector2021[z] = energia1[indice].datos[z];
					            //printf("vector2021 %f\n",vector2021[z]);
					        }
					        if (z > fechas / 2 + 1||z==fechas/2) 
							{
					            break;
					        }
					    }
					    
					    for (w=0,z = z; z<fechas,w<fechas/2; z++,w++)
						{
							if (z < fechas) 
							{
					            vector2022[w] = energia1[indice].datos[z];
					            //printf("vector2022 %f\n",vector2022[z]);
					        }
						} 
						w=0;
					
					    for (z = 0; z < fechas / 2; z++) 
						{
							dif=vector2021[z]-vector2022[z];
					        sumerrores=sumerrores+fabs(vector2021[z]-vector2022[z]);
					        //printf("\nsumaerrore %lf",dif);
					    }
					    z=0;
					    errorabsolutomedio=sumerrores/(fechas/2.0);
					    printf("\nEl error medio absoluto de %s 2021-2022 = %lf GWh\n\n", energia1[indice].nombre, errorabsolutomedio);
					}
					
				void errorabsolutomedio2023(energias energia1[], int indice, int fechas)
			{
			    int i = 0, q = 0, r = 2023;
			    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
			                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
			    float sumy = 0, sumx = 0, xpory = 0, sumxcuadrado = 0, mediax = 0, mediay = 0, pendiente = 0, b = 0;
				float errorabsolutomedio = 0,dif=0;
			    for (i = 0; i < fechas; i++) {
			        sumy += energia1[indice].datos[i];
			    }
			    
			    //printf("\nsumy = %f", sumy);
			
			    for (i = 1; i <= fechas; i++) 
				{
			        sumx += i;
			    }
			
			    //printf("\nsumx = %f", sumx);
			
			    for (i = 1, q = 0; i <= fechas && q < fechas; i++, q++) {
			        xpory += i * energia1[indice].datos[q];
			    }
			
			    //printf("\nx por y = %f", xpory);
			
			    for (i = 1; i <= fechas; i++) {
			        sumxcuadrado += i * i;
			    }
			
			    //printf("\nsumxcuadrado = %f", sumxcuadrado);
			
			    mediax = sumx / fechas;
			
			    mediay = sumy / fechas;
			
			    pendiente = (xpory - (sumx * sumy / fechas)) / (sumxcuadrado - (sumx * sumx / fechas));
			
			    b = mediay - pendiente * mediax;
			    
			    for(q=0;q<fechas;q++)
			    {
			    	dif=dif+fabs(energia1[indice].datos[q]-(pendiente*(q + 1) + b));
			    	
				}
				errorabsolutomedio=dif/fechas;
				printf("\nEl error medio absoluto de %s 2023-2022 = %lf GWh\n\n", energia1[indice].nombre, errorabsolutomedio);
			    
							i=0;
							q=0;
							pendiente=0;
							b=0;
							mediax=0;
							mediay=0;
							xpory=0;
							sumx=0;
							sumy=0;
							sumxcuadrado=0;
			}	
					
				void rectaregresion(energias energia1[], int indice, int fechas)
			{
			    int i = 0, q = 0, r = 2023;
			    char* meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
			                       "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
			    float sumy = 0, sumx = 0, xpory = 0, sumxcuadrado = 0, mediax = 0, mediay = 0, pendiente = 0, b = 0;
			
			    for (i = 0; i < fechas; i++) {
			        sumy += energia1[indice].datos[i];
			    }
			    
			    //printf("\nsumy = %f", sumy);
			
			    for (i = 1; i <= fechas; i++) 
				{
			        sumx += i;
			    }
			
			    //printf("\nsumx = %f", sumx);
			
			    for (i = 1, q = 0; i <= fechas && q < fechas; i++, q++) {
			        xpory += i * energia1[indice].datos[q];
			    }
			
			    //printf("\nx por y = %f", xpory);
			
			    for (i = 1; i <= fechas; i++) {
			        sumxcuadrado += i * i;
			    }
			
			    //printf("\nsumxcuadrado = %f", sumxcuadrado);
			
			    mediax = sumx / fechas;
			
			    mediay = sumy / fechas;
			
			    pendiente = (xpory - (sumx * sumy / fechas)) / (sumxcuadrado - (sumx * sumx / fechas));
			
			    b = mediay - pendiente * mediax;
			    
			
			    printf("\n\n%s en 2023: \n", energia1[indice].nombre);
			    printf("\nGeneracion mensual de: %s\n\n", energia1[indice].nombre);
			
			    for (q = 0; q < fechas; q++) 
				{
			        printf("%s 2023: %f GWh\n", meses[q % 12], pendiente * (q + 1) + b);
			        if (q == 11) {
			            r++;
			        }
			    }
			    printf("\nmedia de dias = %f dias", mediax);
			    printf("\nmedia de energia generada = %f GWh", mediay);
			    printf("\npendiente recta = %f", pendiente);
			    printf("\nb = %f\n\n", b);
							i=0;
							q=0;
							pendiente=0;
							b=0;
							mediax=0;
							mediay=0;
							xpory=0;
							sumx=0;
							sumy=0;
							sumxcuadrado=0;
			}	
					
						lectores_e lectores0_e[20];
						prediccion predicciones[20];
						energias energia[20];
						FILE*fichero;
						char opcion6[20],lector_0_e[10000],lectorfechas_e[300],lector[10000],lector2[5000],copia1[5000],copiareal[10000],menu[20],menu0[20],opcion1[20],opcion2[20],opcion3[20],opcion4[20],opcion5[20];
						int error=0,i=0,j=0,contpuntos=0,contfechas_e=0,contfilas_e=0,energiastot_e=0,energiapredecir=0,conttrabajado_e=0,k=0,l=0,m=0,o=0,p=0;
						float num[100];
						
						
						
						fichero=fopen("Ficheros_Predicciones/generacion_por_tecnologias_21_22(1).csv","r");
						if(fichero==NULL)
						{
							printf("no abierto correctamente");
							error=1;
						}
						
						while(fscanf(fichero,"%c",&lector_0_e[i])!=EOF)
						{
							i++;
						}
						lector_0_e[i]='\0';
						//printf("%s",lector);
						if(fichero!=NULL)
						{
						fclose(fichero);
						}
						
						for(i=0;i<strlen(lector_0_e);i++)
						{
							lectorfechas_e[i]=lector_0_e[i];
							if(lector_0_e[i]=='\n')
							{
								lectorfechas_e[i]='\n';
								lectorfechas_e[i+1]='\0';
								for(j=i+1;j<strlen(lector_0_e);j++)
								{
									lector[k]=lector_0_e[j];
									k++;
								}
								lector[k]='\0';
								break;
							}
						}
						
						for(i=0;i<strlen(lectorfechas_e);i++)
						{
							if(lectorfechas_e[i]==',')
							{
								contfechas_e++;
							}
						}
						strcat(lectorfechas_e,lector);
						strcpy(copiareal,lectorfechas_e);
						k=0;
						j=0;
						k=0;
						
						//printf("Numero de meses analizados desde 2021 a 2022 = %i\n\n",contfechas_e);
					
						
						
						for(i=0;i<strlen(lector);i++)
						{
							lectores0_e[j].lector0_e[k]=lector[i];
							if(lectores0_e[j].lector0_e[k]=='\n')
							{
								lectores0_e[j].lector0_e[k+1]='\0';
								j++;
								k=0;
								contfilas_e++;
								continue;
							}
							k++;
						}
						k=0;
						i=0;
						for(i=0;i<j;i++)
						{
							for(k=0;k<1000;k++)
							{
								if (lectores0_e[i].lector0_e[k]==' ')
								{
									lectores0_e[i].lector0_e[k]='_';
								}
								if (lectores0_e[i].lector0_e[k]=='\0')
								{
									k=0;
									break;
								}
							}
						}
						
						i=0;
						k=0;
						j=0;
						
						
						//hasta aquí se guardan los datos en vectores, por filas, luego se hara el fichero de una linea
						while(conttrabajado_e<=contfilas_e-1)
						{
							fichero=fopen("Ficheros_Predicciones/generacion_por_tecnologias_21_22(1).csv","w");
								if(fichero==NULL)
								{
									printf("no abierto correctamente");
									error=1;
								}
								
										if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
								
								fprintf(fichero,"%s",lectores0_e[o].lector0_e);
								if(fichero!=NULL)
								{
								fclose(fichero);
								}
									
								
								for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
							    {
							    	if(lectores0_e[o].lector0_e[i]==',')
							    	{
							    		lectores0_e[o].lector0_e[i]='.';
									}
									if(lectores0_e[o].lector0_e[i]=='"')
									{
										lectores0_e[o].lector0_e[i]=' ';
									}
								}
								lectores0_e[o].lector0_e[i]='\0';
								
								
								for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
								{
									if(lectores0_e[o].lector0_e[i]==' ')
									{
										lectores0_e[o].lector0_e[i]='\n';
									}
								}
								lectores0_e[o].lector0_e[i]='\0';
							for(i=0;i<strlen(lectores0_e[o].lector0_e);i++)
								{
									if(lectores0_e[o].lector0_e[i]=='.')
									{
										contpuntos++;
									}
								}
							
								
								fichero=fopen("Ficheros_Predicciones/generacion_por_tecnologias_21_22(1).csv","w");
								if(fichero==NULL)
								{
									printf("no abierto correctamente");
									error=1;
								}
								
										if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
								
								fprintf(fichero,"%s",lectores0_e[o].lector0_e);
								if(fichero!=NULL)
								{
								fclose(fichero);
								}
								
							fichero = fopen("Ficheros_Predicciones/generacion_por_tecnologias_21_22(1).csv", "r");
							if (fichero == NULL) 
							{
							    printf("Error al abrir el archivo\n");
							    error=1;
							}
							
							i = 0;
							int num_puntos = 0;
							while (fscanf(fichero, "%c", &lector2[i]) != EOF) 
							{
							    if (lector2[i] == '.') 
								{
							        contpuntos++;
							    }
							    i++;
							}
							lector2[i] = '\0';
							if(fichero!=NULL)
							{
							fclose(fichero);
							}
							
							
							j = 1;
							for (i = 0; i < strlen(lector2); i++) 
							{
							    if (lector2[i] == '.' && j % 2 == 1) 
								{
							        lector2[i] = ' ';
							        j++;
							    }
								if (lector2[i] == '.') 
								{
							        j++;
							    }
							}
							//printf("%s",lector2);
							//hasta aqui es perfeccion
							
							fichero = fopen("Ficheros_Predicciones/generacion_por_tecnologias_21_22(1).csv", "w");
							if (fichero == NULL) 
							{
							    printf("Error al abrir el archivo\n");
							    error=1;
							}
							
									if (error == 1) 
								{
							        printf("Ocurrió un error en la función predicciones.\n");
							        return; // Retorna sin hacer nada más
							    }
							
							fprintf(fichero,"%s",lector2);
							if(fichero!=NULL)
							{
							fclose(fichero);
							}
							
							//sigue siendo bueno
							fichero = fopen("Ficheros_Predicciones/generacion_por_tecnologias_21_22(1).csv", "r");
							    if (fichero == NULL) 
								{
							        printf("Error al abrir el archivo\n");
							        error=1;
							    }
							    
								    if (error == 1) 
							{
						        printf("Ocurrió un error en la función predicciones.\n");
						        return;
						    }
							
							    // Leer la primera palabra y almacenarla en la estructura
							    fscanf(fichero, "%s", energia[0+l].nombre);
								i=0;
							    // Leer los datos y almacenarlos en el vector de la estructura
							    while (fscanf(fichero, "%lf", &energia[0+l].datos[i]) != EOF) 
								{
							        i++;
							    }
							    if(fichero!=NULL)
							    {
							    fclose(fichero);
								}
								
								for(k=0;k<strlen(energia[0+l].nombre);k++)
								{
									if(energia[0+l].nombre[k]=='_')
									{
										energia[0+l].nombre[k]=' ';
									}
								}
								energia[0+l].nombre[k]='\0';
								
								
								/*imprimirDatos(energia,contfechas_e,0+l);*/
								
								
							conttrabajado_e++;
							o++;
							l++;
							k=0;
							energiastot_e=l;
						}
						
						
						fichero = fopen("Ficheros_Predicciones/generacion_por_tecnologias_21_22(1).csv", "w");
						if (fichero == NULL) 
						{
						    printf("Error al abrir el archivo\n");
						    error=1;
						}
						
							if (error == 1) 
							{
						        printf("Ocurrió un error en la función predicciones.\n");
						        return;
						    }
						
						fprintf(fichero,"%s",copiareal);
						if(fichero!=NULL)
						{
						fclose(fichero);
						}
						//printf("energias totales analizadas = %i\n\n",energiastot_e);
						i=0;
						//analisis de fichero acaba aqui//
						do 
						{
				        printf("\nBIENVENIDO A LA FUNCION DE PREDICCIONES\n\nEscoja una opcion:\n");
				        printf("1. Mostrar datos disponibles\n2. Error absoluto medio de los datos de 2022 respecto 2021\n3. Predicciones para el anio 2023\n4. Volver al menu de predicciones\n\n");
				        scanf(" %[^\n]",menu0);
				        
				        if(strcasecmp(menu0,"Opcion 1")==0||strcasecmp(menu0,"1")==0||strcasecmp(menu0,"Mostrar datos disponibles")==0)
				        {
				        	//printf("\nELIGIO OPCION 1\n\n");
				        	printf("\n1. Mostrar todos los datos disponibles\n2. Elegir un tipo especifico\n");
				        	scanf(" %[^\n]",opcion1);
				        	
				        	if(strcasecmp(opcion1,"1")==0||strcasecmp(opcion1,"todos los datos")==0||strcasecmp(opcion1,"todos los datos disponibles")==0||strcasecmp(opcion1,"mostrar todos los datos disponibles")==0||strcasecmp(opcion1,"todos los datos disponibles")==0||strcasecmp(opcion1,"los disponibles")==0)
				        	{
								for(i=0;i<energiastot_e;i++)
								{
									printf("\n");
									imprimirDatos(energia,contfechas_e,0+i);
								}
								i=0;
							}
							
							if(strcasecmp(opcion1,"2")==0||strcasecmp(opcion1,"Elegir un tipo especifico")==0||strcasecmp(opcion1,"un tipo especifico")==0||strcasecmp(opcion1,"especifico")==0)
							{
								printf("\n\nEscriba el nombre del tipo en especifico para mostrar en pantalla:\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion2);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion2,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								
								i=0;
								energiapredecir--;
								//printf("%s\n\n",energia[energiapredecir].nombre);
								imprimirDatosPredicciones(energia,contfechas_e,energiapredecir);
							}
						}
							
						if(strcasecmp(menu0,"2")==0||strcasecmp(menu0,"Error")==0||strcasecmp(menu0,"error absoluto")==0||strcasecmp(menu0,"error absoluto medio")==0)
							{
								printf("\nEscriba el nombre del tipo en especifico para calcular el error absoluto medio entre 2021-2022\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion3);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion3,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								if(strcasecmp(opcion3,energia[i].nombre)!=0)
								{
									printf("\n\n\n\n");
									continue;
								}
								i=0;
								energiapredecir--;
								errorabsolutomedio(energia,energiapredecir, contfechas_e);
							}
							
						if(strcasecmp(menu0,"3")==0||strcasecmp(menu0,"Predicciones para el anio 2023")==0||strcasecmp(menu0,"predicciones")==0)
						{
							printf("\n1. Mostrar predicciones de todos los tipos de generadores de energia\n2. Elegir un tipo especifico para mostrar una prediccion a futuro\n3. Error absoluto medio de las predicciones de 2023 respecto 2022\n");
				        	scanf(" %[^\n]",opcion4);
				        	
				        	if(strcasecmp(opcion4,"1")==0||strcasecmp(opcion4,"Mostrar predicciones de todos los tipos de generadores de energia")==0||strcasecmp(opcion4,"todos los tipos de energia")==0||strcasecmp(opcion4,"todos los tipos")==0||strcasecmp(opcion4,"todos los datos disponibles")==0||strcasecmp(opcion4,"todos los tipos de generadores de energia")==0)
				        	{
				        		for(i=0;i<energiastot_e;i++) 
				        		{
				        			
									rectaregresion(energia,i,contfechas_e/2);
									
								}
								i=0;
								j=0;
							}
							
							if(strcasecmp(opcion4, "2") == 0 || strcasecmp(opcion4, "Elegir un tipo especifico para mostrar una prediccion a futuro") == 0 || strcasecmp(opcion4, "un tipo especifico") == 0 || strcasecmp(opcion4, "elegir un tipo especifico para mostrar") == 0)
							{
								printf("\nEscriba el nombre del tipo en especifico para ver una prediccion de los datos para 2023\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion5);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion5,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								i=0;
								energiapredecir--;
								rectaregresion(energia,energiapredecir,contfechas_e/2);
							}
							
							if(strcasecmp(opcion4, "3") == 0 || strcasecmp(opcion4, "Error absoluto medio de las predicciones de 2023 respecto 2022") == 0 || strcasecmp(opcion4, "Error absoluto medio") == 0 || strcasecmp(opcion4, "Error absoluto medio de las predicciones de 2023") == 0)
							{
								printf("\nEscriba el nombre del tipo en especifico para calcular el error absoluto medio de 2023 respecto 2022\n\n");
								for(i=0;i<energiastot_e;i++)
								{
									printf("%i. %s\n",i+1,energia[i].nombre);
								} 
								i=0;
								printf("\n");
								scanf(" %[^\n]",opcion6);
								for(i=0;i<energiastot_e;i++)
								{
									if(strcasecmp(opcion6,energia[i].nombre)==0)
									{
										//printf("analizando: %i\n",i+1);
										energiapredecir=i+1;
										break;
									}
								}
								i=0;
								energiapredecir--;
								errorabsolutomedio2023(energia,energiapredecir,contfechas_e/2);
							}
						}
						if((strcasecmp(menu0,"4")==0||strcasecmp(menu0,"volver al menu de predicciones")==0||strcasecmp(menu0,"volver al menu")==0||strcasecmp(menu0,"SALIR")==0))
						{
							printf("\n\n");
							break;
						}
						printf("\n\n");
				    	} while (strcmp(menu0,"ñ")!=0);
						
						//final
						if (error == 1) 
						{
					        printf("Ocurrio un error en la funcion predicciones.\n");
					        return;
						}
				}
	
	
	char menu00[20];
	
	do
	{
	printf("\n\nPREDICCIONES A NIVEL NACIONAL SOBRE:\n\n1. GENERACION MENSUAL DE ENERGIA\n2. EMISIONES DE CO2\n3. EVOLUCION DE LA POTENCIA INSTALADA\n4. VOLVER AL MENU PRINCIPAL\n\nSeleccione una opcion:");
	scanf(" %[^\n]",menu00);
	
	if(strcasecmp(menu00,"generacion mensual de energia")==0||strcasecmp(menu00,"1")==0||strcasecmp(menu00,"prediccion sobre generacion mensual de energia")==0)
	{
	prediccionesgeneracionmensual();
	}
	
	if(strcasecmp(menu00,"4")==0||strcasecmp(menu00,"Volver al menu principal")==0||strcasecmp(menu00,"menu principal")==0||strcasecmp(menu00,"MENU")==0||strcasecmp(menu00,"Volver al menu")==0||strcasecmp(menu00,"MENU")==0||strcasecmp(menu00,"SALIR")==0)
	{
				printf("\n\n");
				menu();
				break;
	}
	
	if(strcasecmp(menu00,"emisiones de co2")==0||strcasecmp(menu00,"2")==0||strcasecmp(menu00,"emision de co2")==0)
	{
	prediccionesemisionco2();
	}
	printf("\n\n");
	
	
	
	if(strcasecmp(menu00,"evolucion potencia instalada")==0||strcasecmp(menu00,"3")==0||strcasecmp(menu00,"potencia instalada")==0)
	{
	prediccionesevpi();
	}
	printf("\n\n");
	}
	while (strcmp(menu00,"ñ")!=0);
}
