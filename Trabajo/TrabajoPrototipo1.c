//EJEMPLO TRABAJO

#include <stdio.h>
#define N 5

//ESTRUCTURAS

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

/*Estructura CORREO ELECTRÓNICO*/
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
	char cp[N];
}crear_cuenta;

/*Estructuras dentro de Estructura INICIAR SESIÓN*/
typedef struct iniciar_sesion
{
	ce ISpersona;
}iniciar_sesion;

//FUNCIONES

/*Crear Cuenta*/
int CrearCuenta();
/*Iniciar Sesion*/
int IniciarSesion();
/*Cambio de minusculas a Mayusculas*/
void cambio_mayusculas(char nombre[], char apellido1[],  char apellido2[]);
/*Menu*/
int menu();
/*INFORMACIÓN*/
int informacion();


//COMIENZO CON EL CREAR CUENTA O INICIO DE SESIÓN
int main()
{
	printf("%cBIENVENIDO A TEAM SANGRE%c\n", 126, 126);
	
	/*Selecion de Crear Cuenta o Inicio de Sesión*/
	
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
		/*Si en la función salta un return -1, en esta función tmabién se hace el return -1*/
		comprobacion_error = CrearCuenta();
		if(comprobacion_error == -1)
		{
			return -1;
		}
		
	}
	
	
	//INICIAR SESIÓN
	/*Si el usuario selecciona 2(INICIAR SESIÓN)*/
	
	if(seleccion == 2)
	{
		/*Si en la función salta un return -1, en esta función tmabién se hace el return -1*/
		comprobacion_error = IniciarSesion();
		if(comprobacion_error == -1)
		{
			return -1;
		}
		
		
	}
	return 0;
}


//FUNCIONES (En orden de uso)

/*Función Crear Cuenta*/

int CrearCuenta()
{
	/*Creamos las variables que utilizaremos en esta parte*/
		crear_cuenta CCusuario;
		int i, j, k;
		printf("\n\n\n\nCREAR CUENTA");
		
		/*Creamos y abrimos el fichero donde vamos a guardar los datos del usuario*/
		FILE *pf;
		pf = fopen("C:/Users/david/OneDrive/Documentos/tw_E10X_2022_2023-team_sangre/Trabajo/Ficheros/Crear_Cuenta.txt", "a");
		if(pf == NULL)
		{
			printf("ERROR; no he encontrado el archivo");
			return -1;
		}
		else
		{
			/*Creamos y abrimos el fichero donde solo se va a guardar los correos de los usuarios*/
			FILE *pf1;
			pf1 = fopen("C:/Users/david/OneDrive/Documentos/tw_E10X_2022_2023-team_sangre/Trabajo/Ficheros/Crear_Cuenta_Correo.txt", "a");
			
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
				pf2 = fopen("C:/Users/david/OneDrive/Documentos/tw_E10X_2022_2023-team_sangre/Trabajo/Ficheros/Crear_Cuenta_Correo.txt","r");
				
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
					
					while(fscanf(pf2,"%c",&correo_pf2[i]) != EOF)
					{		
						i++;
					}
					int longitud_cadena = i;
					
					k = 0;
					j = 0;
					i = 0;
					
					
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
			
				/*Creamos y abrimos un fichero donde almacenaremos las contraseñas de los usuarios, se utilizará para el INICIO DE SESIÓN*/
				FILE *pf3;
				pf3 = fopen("C:/Users/david/OneDrive/Documentos/tw_E10X_2022_2023-team_sangre/Trabajo/Ficheros/Crear_Cuenta_contrasena.txt","a");
			
				if(pf3 == NULL)
				{
					printf("ERROR; no he encontrado el archivo");
					return -1;
				}
				else
				{
					/*Abrimos el fichero(sólo lectura) donde almacenamos las contraseñas de los usurios, aquí comprobaremos si la contraseña introducida
					ya esta creada, en ese caso el usuario debera crear otra contraseña, lo hacemos para que no se creen contraseñas iguales*/
					/*FILE *pf4;
					pf4 = fopen("C:/Users/david/OneDrive/Documentos/tw_E10X_2022_2023-team_sangre/Trabajo/Ficheros/Crear_Cuenta_contrasena.txt","r");
					
					if(pf4 == NULL)
					{
						printf("ERROR; no he encontrado el archivo");
						return -1;
					}
					else
					{*/
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
						
						/*Medimos la longitud de la contraseña introducida por el usuario
						i = 0;
						while(CCusuario.CCPersona.contrasena[i] != '\0')
						{
							i++;
						}
						int longitud2 = i;
						
						/*Medimos la longitud del fichero del cual leeremos todas las contraseñas
						char contrasena_pf4[1000];
						i = 0;
						
						while(fscanf(pf4,"%c", &contrasena_pf4[i]) != EOF)
						{
							i++;
						}
						int longitud_cadena1 = i;
						
						/*Comenzamos el bucle para comprobar si esta contraseña ya existe
						k = 0;
						j = 0;
						i = 0;
					
						for(i = 0 ; i < longitud_cadena1 ; i++)
						{
							if(CCusuario.CCPersona.contrasena[0] == contrasena_pf4[i])
							{
								j = i;
							
								for(k = 0 ; k < longitud2 ; k++)
								{
									if(CCusuario.CCPersona.contrasena[k] != contrasena_pf4[j])
									{
										break;
									}
									else
									{
										j++;
									}
								
								}
							}
						
							if(k == longitud2)
							{
								printf("\nYa existe esta contrasena, por favor crea otra\n");
								
								return 0;
							}
						}*/
						
						/*Simplemente por hacerlo algo más real imprimimos (*) en lugar de la contraseña*/
						printf("Contrasena: ");
						for(k = 0 ; k < longitud1 ; k++)
						{
							printf("*");
						}
			
						fprintf(pf,"%s;", CCusuario.CCPersona.contrasena);
						fprintf(pf3,"%s;%s\n", CCusuario.CCPersona.correo, CCusuario.CCPersona.contrasena);
						fclose(pf3);
				//	}
				//fclose(pf4);	
				}
			fclose(pf1);	
			}
			
			/*NOMBRE APELLIDO1 APELLIDO2*/
			
			/*Pedimos al usuario el primer apellido, en el caso de poner cualquier otra cosa que no sea una letra saltará ERROR*/
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
			
			/*Pedimos al usuario el segundo apellido, en el caso de poner cualquier otra cosa que no sea una letra saltará ERROR*/
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
			
			/*Pedimos al usuario el nombre, en el caso de poner cualquier otra cosa que no sea un aletra saltará ERROR*/
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
			
			/*Comprobamos si el año de su nacimiento es Bisiesto*/
			/*Cubrimos todos los casos en caso de años bisiestos o no, es decir, solo se permiten fechas reales*/
			
			if((CCusuario.fecha.ano % 4 == 0) && (CCusuario.fecha.ano % 100 != 0) || (CCusuario.fecha.ano % 400 == 0))/*Si el año es bisiesto*/
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
					
				/*if((CCusuario.persona.parte_numerica < 48) || (CCusuario.persona.parte_numerica > 57))
				{
					printf("ERROR; introduzca solo la parte numerica");
				
				}*/
				

				if((CCusuario.persona.parte_numerica < 1) || (CCusuario.persona.parte_numerica > 99999999))
				{
					printf("ERROR; un numero de DNI no tiene esas cifras");
				}
			}
			while((CCusuario.persona.parte_numerica < 1) || (CCusuario.persona.parte_numerica > 99999999));
			
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
	/*Abrimos el fichero en modo solo lectura, aqui comprobaremos si el correo y la contraseña introducida ya estan registradas*/
	FILE *pf5;
	pf5 = fopen("C:/Users/david/OneDrive/Documentos/tw_E10X_2022_2023-team_sangre/Trabajo/Ficheros/Crear_Cuenta_contrasena.txt","r");
		
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
		char correo_pf5[500];
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
					
		for(i = 0 ; i < longitud_cadena ; i++)
		{
			if(ISusuario.ISpersona.correo[0] == correo_pf5[i])
			{
				j = i;
							
				for(k = 0 ; k < longitud_correo ; k++)
				{
					if(ISusuario.ISpersona.correo[k] != correo_pf5[j])
					{
						break;
					}
					else
					{
						j++;
					}
								
				}
			}
			if(k == longitud_correo)
			{
				int comprobacion = 0;
				int c = 0;
				do
				{
					printf("-Introduce la contrasena: ");
					scanf("%s", &ISusuario.ISpersona.contrasena);
			
					j = 0;
					k = 0;
					
					
					/*Medimos la longitud de la contraseña introducida por el usuario*/
					
					while(ISusuario.ISpersona.contrasena[k] != '\0')
					{
						k++;
					}
					int longitud_contrasena = k;
				
					/*Guardamos el valor de i*/
					
					int principio_contrasena = i + longitud_correo;
					principio_contrasena = principio_contrasena + 1;
					
					/*Comenzamos el bucle para comprobar si la contraseña introducida por el usuario es correcta*/
				
					for(i = 0 ; i < longitud_contrasena ; i++)
					{
						if(ISusuario.ISpersona.contrasena[i] != correo_pf5[principio_contrasena + i])
						{
							break;
						}
						
					}
					
					/*Observamos que será correcta si el valor que tenemos en longitud_contrasena es igual al valor de i*/
					
					if(longitud_contrasena == i)
					{
						printf("\nInicio de Sesion completado\n");
						comprobacion = 1;
						menu();
					}
					/*Si la contraseña introducida no es correcta, el usuario tiene tres intentos para escribirla bien*/
					else
					{
						printf("CONTRASENA INCORRECTA\n\n");
						comprobacion = 0;
					
					}
					c++;
				}
				/*Si en esos tres intentos no la pone bien el programa le expulsará del INICIO DE SESIÓN*/
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


/*Una vez finalizado el Inicio de sesión llevamos al usuario al menu*/
int menu()
{
	int seleccion;
	/*El usuario seleccion que desea realizar*/
	
	do
	{
		printf("\n\n\n\n\n\nSeleccione que desea realizar");
		printf("\n1.-Comparaciones");
		printf("\n2.-Predicciones");
		printf("\n3.-Mis Datos");
		printf("\n4.-Informacion");
		printf("\n5.-Salir");
		printf("\nSeleccion(1 | 2 | 3 | 4 | 5): ");
		scanf("%i", &seleccion);
		
		if((seleccion < 1) || (seleccion > 5))
		{
			printf("ERROR; la seleccion no es valida");
		}
	}
	while((seleccion < 1) || (seleccion > 5));
	
	switch (seleccion)
	{
		case 1:
			{
				printf("\n\nCOMPARACIONES");
				
				break;
			}
		case 2:
			{
				printf("\n\nPREDICCIONES");
				
				break;
			}
		case 3:
			{
				printf("\n\nMIS DATOS");
				
				break;
			}
		case 4:
			{
				printf("\n\nINFORMACION");
				int comprobacion_error1 = informacion();
				if(comprobacion_error1 == -1)
				{
					return -1;
				}
				
				break;
			}
		case 5:
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
	printf("\n\nInformacon Extraida de Red.Electrica: https://www.ree.es/es/datos/publicaciones");
	
	FILE *pfin;
	pfin = fopen("C:/Users/david/OneDrive/Documentos/tw_E10X_2022_2023-team_sangre/Trabajo/Ficheros/Informacion.txt","r");
	
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


