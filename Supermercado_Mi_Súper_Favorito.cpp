#include <iostream>
#include <fstream> //Librería para la utilización de archivos
#include <stdlib.h> //Librería para operacioones con cadena
#include <locale.h> //Librería para el idioma del programa
#include <string.h> //Librería para comparación de cadenas
#include <vector> //Librería para la utilización de los vectores de usuarios y contraseñas
#include <conio.h> //Librería para la utilización de getch()

using namespace std;

//Constantes 
#define ENTER 13 
#define BACKSPACE 8

//Funciones
void supermercadoEscribir();
void supermercadoModificar();
void supermercadoEliminar();
void supermercadoAbrir();
void tipoDeEmpleadosAbrir();
void empleadosEscribir();
void empleadosModificar();
void empleadosEliminar();
void empleadosAbrir();
void clientesEscribir();
void clientesModificar();
void clientesEliminar();
void clientesAbrir();
void productosEscribir();
void productosModificar();
void productosEliminar();
void productosAbrir();
void tiposDeProductosFiltrar();
void proveedoresEscribir();
void proveedoresModificar();
void proveedoresEliminar();
void proveedoresAbrir();
void ventasFiltradoDia();
void ventasFiltradoMes();
void cajasEscribir();
void cajasModificar();
void cajasEliminar();
void cajasAbrir();
void ofertas();
void ventasFiltradoDia();
void ventasFiltradoMes();
void formasDePagoEfectivo();
void formasDePagoTarjeta();
void ventasFiltradoAnual();

//Registros
//Datos Supermercado
typedef struct datosSupermercado{
	char razonSocial[51];
	char lugar[31];
	int pbx;
	char correo[51];
	char nit[10];
}regSuper;

//Datos Empleados
typedef struct datosEmpleados{
	char carne[16];
	char nombres[21];
	char apellidos[21];
	char dpi[16];
	int edad;
	char puesto[31];
	char caja[2];
	double sueldo;
}regEmp;

//Datos Clientes
typedef struct datosClientes{
	char nit[10];
	char nombres[16];
	char apellidos[16];
	char dpi[16];
}regClient;


//Productos
typedef struct datosProductos{
	char codigo[16];
	char clasificacion[16];
	int cantidad;
	char descripcion[31];
	double precio;
	double precioTotal;
	char dia[3];
	char mes[3];
	char anio[5];
}regProduct;

//Proveedores
typedef struct datosProveedores{
	char nit[10];
	char nombreComercial[31];
	char razonSocial[51];
	char envios;
	char facturas;
	char lugar[31];
	int pbx;
	char correo[51];
}regProv;

//Cajas
typedef struct datosCajas{
	float monto;
	char formasDePago[9];
}regCajas;

int main(){
	setlocale(LC_CTYPE, "spanish");
	system("color 1F");
	
	int menu;
	int menu1;
	int menu2;
	int salir;
	char salir1;
	string usuario;
	string contrasena;
	int contador = 0;
	bool ingresa = false;
	char caracter;
	
	//Declaración de variables en el ector
	vector<string> usuarios;
	vector<string> claves;
	
	// Se añaden usuarios al vector
	usuarios.push_back("Vanni");
	usuarios.push_back("Carlos");
	usuarios.push_back("Ludwing");
	usuarios.push_back("Alfredo");
	usuarios.push_back("Marcos");
	
	// Se añaden claves al vector
	claves.push_back("123");
	claves.push_back("123");
	claves.push_back("123");
	claves.push_back("123");
	claves.push_back("123");
	
	cout<<"==============================" <<endl;
	cout<<"Supermercado Mi Súper Favorito" <<endl;
	cout<<"==============================" <<endl <<endl;
	cout<<"1.Supermercado" <<endl;
	cout<<"2.Tipos de empleados" <<endl;
	cout<<"3.Empleados" <<endl;
	cout<<"4.Clientes" <<endl;
	cout<<"5.Productos" <<endl;
	cout<<"6.Tipos de productos" <<endl;
	cout<<"7.Proveedores" <<endl;
	cout<<"8.Cajas" <<endl;
	cout<<"9.Ofertas" <<endl;
	cout<<"10.Venta o facturación" <<endl;
	cout<<"11.Formas de pago" <<endl;
	cout<<"12.Etc" <<endl <<endl;
	cout<<"Elija una opción: ";
	cin>> menu;
	
	switch(menu){
		case 1: 
			system("cls");
			
			cout<<"=========================" <<endl;
			cout<<"\tSúpermercado" <<endl;
			cout<<"=========================" <<endl <<endl;
			cout<<"1.Sólo personal autorizado" <<endl;
			cout<<"2.Usuario" <<endl;
			cout<<"3.Regresar al menú principal" <<endl;
			cout<<"4.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> menu1;
			
			if(menu1 == 1){
				system("cls");
				
				do{
					
					fflush(stdin);
					
					cout<<"=========================" <<endl;
					cout<<"\tSúpermercado" <<endl;
					cout<<"=========================" <<endl <<endl;
					cout << "Usuario: ";
					getline(cin, usuario);
					cout << "Contraseña: ";
					
					//Entrada de caracter e ingreso de un caracter vacío
					caracter = getch();
						
					//Reseteo de datos ingresados en la variable contrasena
					contrasena = "";
		
					//Hasta que el usuario presione la tecla enter, se cerrará el ciclo
					while (caracter != ENTER){
						
						//Eliminación de caracteres
						//Si el usuario presiona la tecla backspace (borrar)
						if (caracter != BACKSPACE){
							
							//Muestra en pantalla, los asteriscos que se obtienen al ingresar cada uno de los caracteres de la variable caracter y almacena los caracteres en la variable contrasena
							contrasena.push_back(caracter);
							cout << "*";
				
						} 
						else{
							//Contador de caraceres (.length())
							//Si la contraseña ingresada, tiene de uno a más caracteres
							if (contrasena.length() > 0){
								
								//Borrado de caracteres
								//Retrocede un espacio; deja ese espacio en blanco; y, como avanza un espacio, se retrocede a esa posición, en donde está el espacio en blanco
								cout << "\b \b";
								
								//Elimina el último caracter contenido en la contraseña ingresada
								contrasena = contrasena.substr(0, contrasena.length() - 1);
							}
						}
						caracter = getch();
					}
					
					//Comparación decredenciales correctas
					//Ciclo, de acuerdo al número de elementos del vector usuario (usuarios.size())
					for (int i = 0; i < usuarios.size(); i++){
						if (usuarios[i] == usuario && claves[i] == contrasena){
							//Indica, que sí se pude acceder
							ingresa = true;
							
							//Cierra el ciclo
							break;
						}
					}
					
					//Si el usuario ingresa credenciales incorrectas
					if (!ingresa){
						cout << "\n\nUsuario y/o contraseña incorrectos" <<endl <<endl;
						cout << "Inténtelo nuevamente" <<endl;
						
						cin.get();
						
						//Aumenta en 1, el contador
						contador++;
						
						//Limpia la pantalla, para mostrar el resto de pantallas
						system("cls");
						
						//Muestra el número de intentos que lleva el usuario
						cout << "Intento " <<contador+1 <<", de 5"  <<endl <<endl;
					}
					
					//El ciclo se va a cerrar, hasta que la variable ingresa, sea falsa y el contador, llegue al límite de 5 intentos
				}while(ingresa == false && contador < 5);
				
				//Límite de 5 intentos de acceso incorrectos de credenciales
				if (ingresa == false){
					cout << "\nHa alcanzado el límite de intentos permitidos." << endl;
					cout << "Inténtelo más tarde" << endl;
				} 
				else{
					
					//Si las credenciales son correctas
					cout<<"\n\n";
					
					system("pause");
					system("cls");
					
					cout<<"============================" <<endl;
					cout<<"\tSólo personal autorizado" <<endl;
					cout<<"============================" <<endl <<endl;
					cout<<"1.Ingresar datos" <<endl;
					cout<<"2.Modificar datos" <<endl;
					cout<<"3.Eliminar datos" <<endl;
					cout<<"4.Ver datos" <<endl;
					cout<<"5.Regresar al menú anterior" <<endl;
					cout<<"6.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> menu2;
					
					if(menu2 == 1){
						system("cls");
					
						supermercadoEscribir();
						
						system("pause");
						system("cls");
						
						cout<<"¿Qué desea hacer?" <<endl <<endl;
						cout<<"1.Regresar al menú principal" <<endl;
						cout<<"2.Salir del programa" <<endl <<endl;
						cout<<"Elija una opción: ";
						cin>> salir;
			
						if(salir == 1){
							system("cls");
				
							return main();
						}
						else{
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
							return 0;
						}
					}
					else{
						if(menu2 == 2){
							system("cls");
					
							supermercadoModificar();
						
							system("pause");
							system("cls");
						
							cout<<"¿Qué desea hacer?" <<endl <<endl;
							cout<<"1.Regresar al menú principal" <<endl;
							cout<<"2.Salir del programa" <<endl <<endl;
							cout<<"Elija una opción: ";
							cin>> salir;
			
							if(salir == 1){
								system("cls");
					
								return main();
							}
							else{
								if(salir == 2){
									system("pause");
									system("cls");
									
									cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
									cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
									return 0;
								}
							}
						}
						else{
							if(menu2 == 3){
								system("cls");
								
								supermercadoEliminar();
								
								system("pause");
								system("cls");
						
								cout<<"¿Qué desea hacer?" <<endl <<endl;
								cout<<"1.Regresar al menú principal" <<endl;
								cout<<"2.Salir del programa" <<endl <<endl;
								cout<<"Elija una opción: ";
								cin>> salir;
			
								if(salir == 1){
									system("cls");
					
									return main();
								}
								else{
									if(salir == 2){
										system("pause");
										system("cls");
									
										cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
										cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
									return 0;
									}
								}	
							}
							else{
								if(menu2 == 4){
									system("cls");
									
									supermercadoAbrir();
									
									system("pause");
									system("cls");
						
									cout<<"¿Qué desea hacer?" <<endl <<endl;
									cout<<"1.Regresar al menú principal" <<endl;
									cout<<"2.Salir del programa" <<endl <<endl;
									cout<<"Elija una opción: ";
									cin>> salir;
			
									if(salir == 1){
										system("cls");
				
										return main();
									}
									else{
										if(salir == 2){
											system("pause");
											system("cls");
											
											cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
											cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
											return 0;
										}
									}	
								}
								else{
									if(menu2 == 5){
										system("cls");
										
										return main();
									}
									else{
										if(menu2 == 6){
											system("pause");
											system("cls");
									
											cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
											cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
											return 0;
										}
									}
								}
							}
						}
					}
				}		
			}
			else{
				if(menu1 == 2){
					system("cls");
				
					supermercadoAbrir();
					
					system("pause");
					system("cls");
						
					cout<<"¿Qué desea hacer?" <<endl <<endl;
					cout<<"1.Regresar al menú principal" <<endl;
					cout<<"2.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> salir;
			
					if(salir == 1){
						system("cls");
				
						return main();
					}
					else{
						system("pause");
						system("cls");
							
						cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
						cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
						return 0;
					}
				}
				else{
					if(menu1 == 3){
						system("cls");
					
						return main();
					}
					else{
						if(menu1 == 4){
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;
							return 0;
						}
					}
				}
			}
		break;
		
		case 2:
			system("cls");
			
			tipoDeEmpleadosAbrir();
			
			system("pause");
			system("cls");
						
			cout<<"¿Qué desea hacer?" <<endl <<endl;
			cout<<"1.Regresar al menú principal" <<endl;
			cout<<"2.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> salir;
			
			if(salir == 1){
				system("cls");
				
				return main();
			}
			else{
				system("pause");
				system("cls");
							
				cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
				cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
				return 0;
			}
		break;
		
		case 3:
			
			system("cls");
			
			cout<<"=========================" <<endl;
			cout<<"\tEmpleados" <<endl;
			cout<<"=========================" <<endl <<endl;
			cout<<"1.Sólo personal autorizado" <<endl;
			cout<<"2.Usuario" <<endl;
			cout<<"3.Regresar al menú principal" <<endl;
			cout<<"4.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> menu1;
			
			if(menu1 == 1){
				system("cls");
				
				do{
					fflush(stdin);
					
					cout<<"=========================" <<endl;
					cout<<"\tEmpleados" <<endl;
					cout<<"=========================" <<endl <<endl;
					cout << "Usuario: ";
					getline(cin, usuario);
					cout << "Contraseña: ";
					caracter = getch();
		
					contrasena = "";
		
					while (caracter != ENTER){
		
						if (caracter != BACKSPACE){
							contrasena.push_back(caracter);
							cout << "*";
				
						} 
						else{
							if (contrasena.length() > 0){
								cout << "\b \b";
								contrasena = contrasena.substr(0, contrasena.length() - 1);
							}
						}
						caracter = getch();
					}
		
					for (int i = 0; i < usuarios.size(); i++){
						if (usuarios[i] == usuario && claves[i] == contrasena){
							ingresa = true;
							break;
						}
					}
		
					if (!ingresa){
						cout << "\n\nUsuario y/o contraseña incorrectos" <<endl <<endl;
						cout << "Inténtelo nuevamente" <<endl;
						
						cin.get();
						
						contador++;
						
						system("cls");
						
						cout << "Intento " <<contador+1 <<", de 5"  <<endl <<endl;
					}
				}while(ingresa == false && contador < 5);
	
				if (ingresa == false){
					cout << "\nHa alcanzado el límite de intentos permitidos." << endl;
					cout << "Inténtelo más tarde" << endl;
				} 
				else{
					cout<<"\n\n";
					
					system("pause");
					system("cls");
					
					cout<<"============================" <<endl;
					cout<<"\tSólo personal autorizado" <<endl;
					cout<<"============================" <<endl <<endl;
					cout<<"1.Ingresar o agregar datos" <<endl;
					cout<<"2.Modificar datos" <<endl;
					cout<<"3.Eliminar datos" <<endl;
					cout<<"4.Abrir datos" <<endl;
					cout<<"5.Regresar el menú anterior" <<endl;
					cout<<"6.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> menu2;
					
					if(menu2 == 1){
						system("cls");
					
						empleadosEscribir();
						
						system("pause");
						system("cls");
						
						cout<<"¿Qué desea hacer?" <<endl <<endl;
						cout<<"1.Regresar al menú principal" <<endl;
						cout<<"2.Salir del programa" <<endl <<endl;
						cout<<"Elija una opción: ";
						cin>> salir;
			
						if(salir == 1){
							system("cls");
				
							return main();
						}
						else{
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
							return 0;
						}
					}
					else{
						if(menu2 == 2){
							system("cls");
					
							empleadosModificar();
						
							system("pause");
							system("cls");
						
							cout<<"¿Qué desea hacer?" <<endl <<endl;
							cout<<"1.Regresar al menú principal" <<endl;
							cout<<"2.Salir del programa" <<endl <<endl;
							cout<<"Elija una opción: ";
							cin>> salir;
			
							if(salir == 1){
								system("cls");
				
								return main();
							}
							else{
								system("pause");
								system("cls");
							
								cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
								cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
								return 0;
							}
						}
						else{
							if(menu2 == 3){
								system("cls");
								
								empleadosEliminar();
								
								system("pause");
								system("cls");
						
								cout<<"¿Qué desea hacer?" <<endl <<endl;
								cout<<"1.Regresar al menú principal" <<endl;
								cout<<"2.Salir del programa" <<endl <<endl;
								cout<<"Elija una opción: ";
								cin>> salir;
			
								if(salir == 1){
									system("cls");
				
									return main();
								}
								else{
									system("pause");
									system("cls");
							
									cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
									cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
									return 0;
								}
							}
							else{
								if(menu2 == 4){
									system("cls");
									
									empleadosAbrir();
									
									system("pause");
									system("cls");
						
									cout<<"¿Qué desea hacer?" <<endl <<endl;
									cout<<"1.Regresar al menú principal" <<endl;
									cout<<"2.Salir del programa" <<endl <<endl;
									cout<<"Elija una opción: ";
									cin>> salir;
			
									if(salir == 1){
										system("cls");
				
										return main();
									}
									else{
										system("pause");
										system("cls");
							
										cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
										cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
										return 0;
									}	
								}
								else{
									if(menu2 == 5){
										system("cls");
										
										return main();
									}
									else{
										if(menu2 == 6){
											system("pause");
											system("cls");
									
											cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
											cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
											return 0;
										}
									}
								}
							}
						}
					}
				}		
			}
			else{
				if(menu1 == 2){
					system("cls");
				
					empleadosAbrir();
					
					system("pause");
					system("cls");
						
					cout<<"¿Qué desea hacer?" <<endl <<endl;
					cout<<"1.Regresar al menú principal" <<endl;
					cout<<"2.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> salir;
			
					if(salir == 1){
						system("cls");
				
						return main();
					}
					else{
						system("pause");
						system("cls");
						
						cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
						cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
						return 0;
					}
				}
				else{
					if(menu1 == 3){
						system("cls");
					
						return main();
					}
					else{
						if(menu1 == 4){
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;
							return 0;
						}
					}
				}
			}
		break;
		
		case 4:
			system("cls");
			
			cout<<"=========================" <<endl;
			cout<<"\tClientes" <<endl;
			cout<<"=========================" <<endl <<endl;
			cout<<"1.Sólo personal autorizado" <<endl;
			cout<<"2.Usuario" <<endl;
			cout<<"3.Regresar al menú principal" <<endl;
			cout<<"4.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> menu1;
			
			if(menu1 == 1){
				system("cls");
				
				do{
					fflush(stdin);

					cout<<"=========================" <<endl;
					cout<<"\tClientes" <<endl;
					cout<<"=========================" <<endl <<endl;
					cout << "Usuario: ";
					getline(cin, usuario);
					cout << "Contraseña: ";
					caracter = getch();
		
					contrasena = "";
		
					while (caracter != ENTER){
		
						if (caracter != BACKSPACE){
							contrasena.push_back(caracter);
							cout << "*";
				
						} 
						else{
							if (contrasena.length() > 0){
								cout << "\b \b";
								contrasena = contrasena.substr(0, contrasena.length() - 1);
							}
						}
						caracter = getch();
					}
		
					for (int i = 0; i < usuarios.size(); i++){
						if (usuarios[i] == usuario && claves[i] == contrasena){
							ingresa = true;
							break;
						}
					}
		
					if (!ingresa){
						cout << "\n\nUsuario y/o contraseña incorrectos" <<endl <<endl;
						cout << "Inténtelo nuevamente" <<endl;
						
						cin.get();
						
						contador++;
						
						system("cls");
						
						cout << "Intento " <<contador+1 <<", de 5"  <<endl <<endl;
					}
				}while(ingresa == false && contador < 5);
	
				if (ingresa == false){
					cout << "\nHa alcanzado el límite de intentos permitidos." << endl;
					cout << "Inténtelo más tarde" << endl;
				} 
				else{
					cout<<"\n\n";
					
					system("pause");
					system("cls");
					
					cout<<"============================" <<endl;
					cout<<"\tSólo personal autorizado" <<endl;
					cout<<"============================" <<endl <<endl;
					cout<<"1.Ingresar o agregar datos" <<endl;
					cout<<"2.Modificar datos" <<endl;
					cout<<"3.Eliminar datos" <<endl;
					cout<<"4.Abrir datos" <<endl;
					cout<<"5.Regresar al menú anterior" <<endl;
					cout<<"6.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> menu2;
					
					if(menu2 == 1){
						system("cls");
					
						clientesEscribir();
						
						system("pause");
						system("cls");
						
						cout<<"¿Qué desea hacer?" <<endl <<endl;
						cout<<"1.Regresar al menú principal" <<endl;
						cout<<"2.Salir del programa" <<endl <<endl;
						cout<<"Elija una opción: ";
						cin>> salir;
			
						if(salir == 1){
							system("cls");
				
							return main();
						}
						else{
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
							return 0;
						}
					}
					else{
						if(menu2 == 2){
							system("cls");
					
							clientesModificar();
						
							system("pause");
							system("cls");
						
							cout<<"¿Qué desea hacer?" <<endl <<endl;
							cout<<"1.Regresar al menú principal" <<endl;
							cout<<"2.Salir del programa" <<endl <<endl;
							cout<<"Elija una opción: ";
							cin>> salir;
			
							if(salir == 1){
								system("cls");
				
								return main();
							}
							else{
								system("pause");
								system("cls");
							
								cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
								cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
								return 0;
							}
						}
						else{
							if(menu2 == 3){
								system("cls");
								
								clientesEliminar();
								
								system("pause");
								system("cls");
						
								cout<<"¿Qué desea hacer?" <<endl <<endl;
								cout<<"1.Regresar al menú principal" <<endl;
								cout<<"2.Salir del programa" <<endl <<endl;
								cout<<"Elija una opción: ";
								cin>> salir;
			
								if(salir == 1){
									system("cls");
				
									return main();
								}
								else{
									system("pause");
									system("cls");
							
									cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
									cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
									return 0;
								}
							}
							else{
								if(menu2 == 4){
									system("cls");
									
									clientesAbrir();
									
									system("pause");
									system("cls");
						
									cout<<"¿Qué desea hacer?" <<endl <<endl;
									cout<<"1.Regresar al menú principal" <<endl;
									cout<<"2.Salir del programa" <<endl <<endl;
									cout<<"Elija una opción: ";
									cin>> salir;
					
									if(salir == 1){
										system("cls");
				
										return main();
									}		
									else{
										system("pause");
										system("cls");
							
										cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
										cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
										return 0;
									}	
								}
								else{
									if(menu2 == 5){
										system("cls");
										
										return main();
									}
									else{
										if(menu2 == 6){
											system("pause");
											system("cls");
									
											cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
											cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
											return 0;
										}
									}
								}
							}
						}
					}
				}		
			}
			else{
				if(menu1 == 2){
					system("cls");
				
					clientesAbrir();
					
					system("pause");
					system("cls");
						
					cout<<"¿Qué desea hacer?" <<endl <<endl;
					cout<<"1.Regresar al menú principal" <<endl;
					cout<<"2.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> salir;
			
					if(salir == 1){
						system("cls");
				
						return main();
					}
					else{
						system("pause");
						system("cls");
						
						cout<<"¡Gracias por utilizar el sistema del Súpermercado!" <<endl;
						cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
						return 0;
					}
				}
				else{
					if(menu1 == 3){
						system("cls");
					
						return main();
					}
					else{
						if(menu1 == 4){
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema del Súpermercado!" <<endl;
							cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;
							return 0;
						}
					}
				}
			}
		break;
		
		case 5:
			system("cls");
			
			cout<<"=========================" <<endl;
			cout<<"\tProductos" <<endl;
			cout<<"=========================" <<endl <<endl;
			cout<<"1.Sólo personal autorizado" <<endl;
			cout<<"2.Usuario" <<endl;
			cout<<"3.Regresar al menú principal" <<endl;
			cout<<"4.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> menu1;
			
			if(menu1 == 1){
				system("cls");
				
				do{
					fflush(stdin);
					
					cout<<"=========================" <<endl;
					cout<<"\tProductos" <<endl;
					cout<<"=========================" <<endl <<endl;
					cout << "Usuario: ";
					getline(cin, usuario);
					cout << "Contraseña: ";
					caracter = getch();
		
					contrasena = "";
		
					while (caracter != ENTER){
		
						if (caracter != BACKSPACE){
							contrasena.push_back(caracter);
							cout << "*";
				
						} 
						else{
							if (contrasena.length() > 0){
								cout << "\b \b";
								contrasena = contrasena.substr(0, contrasena.length() - 1);
							}
						}
						caracter = getch();
					}
		
					for (int i = 0; i < usuarios.size(); i++){
						if (usuarios[i] == usuario && claves[i] == contrasena){
							ingresa = true;
							break;
						}
					}
		
					if (!ingresa){
						cout << "\n\nUsuario y/o contraseña incorrectos" <<endl <<endl;
						cout << "Inténtelo nuevamente" <<endl;
						
						cin.get();
						
						contador++;
						
						system("cls");
						
						cout << "Intento " <<contador+1 <<", de 5"  <<endl <<endl;
					}
				}while(ingresa == false && contador < 5);
	
				if (ingresa == false){
					cout << "\nHa alcanzado el límite de intentos permitidos." << endl;
					cout << "Inténtelo más tarde" << endl;
				} 
				else{
					cout<<"\n\n";
					
					system("pause");
					system("cls");
					
					cout<<"============================" <<endl;
					cout<<"\tSólo personal autorizado" <<endl;
					cout<<"============================" <<endl <<endl;
					cout<<"1.Ingresar o agregar datos" <<endl;
					cout<<"2.Modificar datos" <<endl;
					cout<<"3.Eliminar datos" <<endl;
					cout<<"4.Ver datos" <<endl;
					cout<<"5.Regresar al menú anterior" <<endl;
					cout<<"6.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> menu2;
					
					if(menu2 == 1){
						system("cls");
					
						productosEscribir();
						
						system("pause");
						system("cls");
						
						cout<<"¿Qué desea hacer?" <<endl <<endl;
						cout<<"1.Regresar al menú principal" <<endl;
						cout<<"2.Salir del programa" <<endl <<endl;
						cout<<"Elija una opción: ";
						cin>> salir;
			
						if(salir == 1){
							system("cls");
				
							return main();
						}
						else{
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
							return 0;
						}
					}
					else{
						if(menu2 == 2){
							system("cls");
					
							productosModificar();
						
							system("pause");
							system("cls");
						
							cout<<"¿Qué desea hacer?" <<endl <<endl;
							cout<<"1.Regresar al menú principal" <<endl;
							cout<<"2.Salir del programa" <<endl <<endl;
							cout<<"Elija una opción: ";
							cin>> salir;
			
							if(salir == 1){
								system("cls");
					
								return main();
							}
							else{
								system("pause");
								system("cls");
								
								cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
								cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
								return 0;
							}
						}
						else{
							if(menu2 == 3){
								system("cls");
								
								productosEliminar();
								
								system("pause");
								system("cls");
						
								cout<<"¿Qué desea hacer?" <<endl <<endl;
								cout<<"1.Regresar al menú principal" <<endl;
								cout<<"2.Salir del programa" <<endl <<endl;
								cout<<"Elija una opción: ";
								cin>> salir;
			
								if(salir == 1){
									system("cls");
					
									return main();
								}
								else{
									system("pause");
									system("cls");
							
									cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
									cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
									return 0;
								}	
							}
							else{
								if(menu2 == 4){
									system("cls");
									
									productosAbrir();
									
									system("pause");
									system("cls");
						
									cout<<"¿Qué desea hacer?" <<endl <<endl;
									cout<<"1.Regresar al menú principal" <<endl;
									cout<<"2.Salir del programa" <<endl <<endl;
									cout<<"Elija una opción: ";
									cin>> salir;
			
									if(salir == 1){
										system("cls");
				
										return main();
									}
									else{
										system("pause");
										system("cls");
							
										cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
										cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
										return 0;
									}	
								}
								else{
									if(menu2 == 5){
										system("cls");
										
										return main();
									}
									else{
										if(menu2 == 6){
											system("cls");
									
											cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
											cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
											return 0;
										}
									}
								}
							}
						}
					}
				}		
			}
			else{
				if(menu1 == 2){
					system("cls");
				
					productosAbrir();
					
					system("pause");
					system("cls");
						
					cout<<"¿Qué desea hacer?" <<endl <<endl;
					cout<<"1.Regresar al menú principal" <<endl;
					cout<<"2.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> salir;
			
					if(salir == 1){
						system("cls");
				
						return main();
					}
					else{
						system("pause");
						system("cls");
						
						cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
						cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
						return 0;
					}
				}
				else{
					if(menu1 == 3){
						system("cls");
					
						return main();
					}
					else{
						if(menu1 == 4){
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;
							return 0;
						}
					}
				}
			}
		break;
		
		case 6:
			system("cls");
			
			tiposDeProductosFiltrar();
			
			system("pause");
			system("cls");
						
			cout<<"¿Qué desea hacer?" <<endl <<endl;
			cout<<"1.Regresar al menú principal" <<endl;
			cout<<"2.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> salir;
			
			if(salir == 1){
				system("cls");
				
				return main();
			}
			else{
				system("pause");
				system("cls");
				
				cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
				cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
				return 0;
			}
		break;
		
		case 7:
			system("cls");
			
			cout<<"=========================" <<endl;
			cout<<"\tProveedores" <<endl;
			cout<<"=========================" <<endl <<endl;
			cout<<"1.Sólo personal autorizado" <<endl;
			cout<<"2.Usuario" <<endl;
			cout<<"3.Regresar al menú principal" <<endl;
			cout<<"4.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> menu1;
			
			if(menu1 == 1){
				system("cls");
				
				do{
					fflush(stdin);
					
					cout<<"=========================" <<endl;
					cout<<"\tProveedores" <<endl;
					cout<<"=========================" <<endl <<endl;
					cout << "Usuario: ";
					getline(cin, usuario);
					cout << "Contraseña: ";
					caracter = getch();
		
					contrasena = "";
		
					while (caracter != ENTER){
		
						if (caracter != BACKSPACE){
							contrasena.push_back(caracter);
							cout << "*";
				
						} 
						else{
							if (contrasena.length() > 0){
								cout << "\b \b";
								contrasena = contrasena.substr(0, contrasena.length() - 1);
							}
						}
						caracter = getch();
					}
		
					for (int i = 0; i < usuarios.size(); i++){
						if (usuarios[i] == usuario && claves[i] == contrasena){
							ingresa = true;
							break;
						}
					}
		
					if (!ingresa){
						cout << "\n\nUsuario y/o contraseña incorrectos" <<endl <<endl;
						cout << "Inténtelo nuevamente" <<endl;
						
						cin.get();
						
						contador++;
						
						system("cls");
						
						cout << "Intento " <<contador+1 <<", de 5"  <<endl <<endl;
					}
				}while(ingresa == false && contador < 5);
	
				if (ingresa == false){
					cout << "\nHa alcanzado el límite de intentos permitidos." << endl;
					cout << "Inténtelo más tarde" << endl;
				} 
				else{
					cout<<"\n\n";
					system("pause");
					system("cls");
					cout<<"============================" <<endl;
					cout<<"\tSólo personal autorizado" <<endl;
					cout<<"============================" <<endl <<endl;
					cout<<"1.Ingresar o agregar datos" <<endl;
					cout<<"2.Modificar datos" <<endl;
					cout<<"3.Eliminar datos" <<endl;
					cout<<"4.Ver datos" <<endl;
					cout<<"5.Regresar al menú anterior" <<endl;
					cout<<"6.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> menu2;
					
					if(menu2 == 1){
						system("cls");
					
						proveedoresEscribir();
						
						system("pause");
						system("cls");
						
						cout<<"¿Qué desea hacer?" <<endl <<endl;
						cout<<"1.Regresar al menú principal" <<endl;
						cout<<"2.Salir del programa" <<endl <<endl;
						cout<<"Elija una opción: ";
						cin>> salir;
			
						if(salir == 1){
							system("cls");
				
							return main();
						}
						else{
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
							return 0;
						}
					}
					else{
						if(menu2 == 2){
							system("cls");
					
							proveedoresModificar();
						
							system("pause");
							system("cls");
						
							cout<<"¿Qué desea hacer?" <<endl <<endl;
							cout<<"1.Regresar al menú principal" <<endl;
							cout<<"2.Salir del programa" <<endl <<endl;
							cout<<"Elija una opción: ";
							cin>> salir;
			
							if(salir == 1){
								system("cls");
					
								return main();
							}
							else{
								cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
								cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
								return 0;
							}
						}
						else{
							if(menu2 == 3){
								system("cls");
								
								proveedoresEliminar();
								
								system("pause");
								system("cls");
						
								cout<<"¿Qué desea hacer?" <<endl <<endl;
								cout<<"1.Regresar al menú principal" <<endl;
								cout<<"2.Salir del programa" <<endl <<endl;
								cout<<"Elija una opción: ";
								cin>> salir;
			
								if(salir == 1){
									system("cls");
					
									return main();
								}
								else{
									cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
									cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
									return 0;
								}	
							}
							else{
								if(menu2 == 4){
									system("cls");
									
									proveedoresAbrir();
									
									system("pause");
									system("cls");
						
									cout<<"¿Qué desea hacer?" <<endl <<endl;
									cout<<"1.Regresar al menú principal" <<endl;
									cout<<"2.Salir del programa" <<endl <<endl;
									cout<<"Elija una opción: ";
									cin>> salir;
			
									if(salir == 1){
										system("cls");
				
										return main();
									}
									else{
										cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
										cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
										return 0;
									}	
								}
								else{
									if(menu2 == 5){
										system("cls");
										
										return main();
									}
									else{
										if(menu2 == 6){
											system("cls");
									
											cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
											cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
											return 0;
										}
									}
								}
							}
						}
					}
				}		
			}
			else{
				if(menu1 == 2){
					system("cls");
				
					proveedoresAbrir();
					
					system("pause");
					system("cls");
						
					cout<<"¿Qué desea hacer?" <<endl <<endl;
					cout<<"1.Regresar al menú principal" <<endl;
					cout<<"2.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> salir;
			
					if(salir == 1){
						system("cls");
				
						return main();
					}
					else{
						system("pause");
						system("cls");
							
						cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
						cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
						return 0;
					}
				}
				else{
					if(menu1 == 3){
						system("cls");
					
						return main();
					}
					else{
						if(menu1 == 4){
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;
							return 0;
						}
					}
				}
			}
		break;
		
		case 8:
			system("cls");
			
			cout<<"=========================" <<endl;
			cout<<"\tCajas" <<endl;
			cout<<"=========================" <<endl <<endl;
			cout<<"1.Sólo personal autorizado" <<endl;
			cout<<"2.Usuario" <<endl;
			cout<<"3.Regresar al menú principal" <<endl;
			cout<<"4.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> menu1;
			
			if(menu1 == 1){
				system("cls");
				
				do{
					fflush(stdin);
					
					cout<<"=========================" <<endl;
					cout<<"\tCajas" <<endl;
					cout<<"=========================" <<endl <<endl;
					cout << "Usuario: ";
					getline(cin, usuario);
					cout << "Contraseña: ";
					caracter = getch();
		
					contrasena = "";
		
					while (caracter != ENTER){
		
						if (caracter != BACKSPACE){
							contrasena.push_back(caracter);
							cout << "*";
				
						} 
						else{
							if (contrasena.length() > 0){
								cout << "\b \b";
								contrasena = contrasena.substr(0, contrasena.length() - 1);
							}
						}
						caracter = getch();
					}
		
					for (int i = 0; i < usuarios.size(); i++){
						if (usuarios[i] == usuario && claves[i] == contrasena){
							ingresa = true;
							break;
						}
					}
		
					if (!ingresa){
						cout << "\n\nUsuario y/o contraseña incorrectos" <<endl <<endl;
						cout << "Inténtelo nuevamente" <<endl;
						
						cin.get();
						
						contador++;
						
						system("cls");
						
						cout << "Intento " <<contador+1 <<", de 5"  <<endl <<endl;
					}
				}while(ingresa == false && contador < 5);
	
				if (ingresa == false){
					cout << "\nHa alcanzado el límite de intentos permitidos." << endl;
					cout << "Inténtelo más tarde" << endl;
				} 
				else{
					cout<<"\n\n";
					system("pause");
					system("cls");
					cout<<"============================" <<endl;
					cout<<"\tSólo personal autorizado" <<endl;
					cout<<"============================" <<endl <<endl;
					cout<<"1.Ingresar o agregar datos" <<endl;
					cout<<"2.Modificar datos" <<endl;
					cout<<"3.Eliminar datos" <<endl;
					cout<<"4.Ver datos" <<endl;
					cout<<"5.Regresar al menú anterior" <<endl;
					cout<<"6.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> menu2;
					
					if(menu2 == 1){
						system("cls");
					
						cajasEscribir();
						
						system("pause");
						system("cls");
						
						cout<<"¿Qué desea hacer?" <<endl <<endl;
						cout<<"1.Regresar al menú principal" <<endl;
						cout<<"2.Salir del programa" <<endl <<endl;
						cout<<"Elija una opción: ";
						cin>> salir;
			
						if(salir == 1){
							system("cls");
				
							return main();
						}
						else{
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
							return 0;
						}
					}
					else{
						if(menu2 == 2){
							system("cls");
					
							cajasModificar();
						
							system("pause");
							system("cls");
						
							cout<<"¿Qué desea hacer?" <<endl <<endl;
							cout<<"1.Regresar al menú principal" <<endl;
							cout<<"2.Salir del programa" <<endl <<endl;
							cout<<"Elija una opción: ";
							cin>> salir;
			
							if(salir == 1){
								system("cls");
					
								return main();
							}
							else{
								cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
								cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
								return 0;
							}
						}
						else{
							if(menu2 == 3){
								system("cls");
								
								cajasEliminar();
								
								system("pause");
								system("cls");
						
								cout<<"¿Qué desea hacer?" <<endl <<endl;
								cout<<"1.Regresar al menú principal" <<endl;
								cout<<"2.Salir del programa" <<endl <<endl;
								cout<<"Elija una opción: ";
								cin>> salir;
			
								if(salir == 1){
									system("cls");
					
									return main();
								}
								else{
									cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
									cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
									return 0;
								}	
							}
							else{
								if(menu2 == 4){
									system("cls");
									
									cajasAbrir();
									
									system("pause");
									system("cls");
						
									cout<<"¿Qué desea hacer?" <<endl <<endl;
									cout<<"1.Regresar al menú principal" <<endl;
									cout<<"2.Salir del programa" <<endl <<endl;
									cout<<"Elija una opción: ";
									cin>> salir;
			
									if(salir == 1){
										system("cls");
				
										return main();
									}
									else{
										cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
										cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
										return 0;
									}	
								}
								else{
									if(menu2 == 5){
										system("cls");
										
										return main();
									}
									else{
										if(menu2 == 6){
											system("cls");
									
											cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
											cout<<"\t\t¡Vuelva pronto!" <<endl <<endl;  
				
											return 0;
										}
									}
								}
							}
						}
					}
				}		
			}
			else{
				if(menu1 == 2){
					system("cls");
				
					cajasAbrir();
					
					system("pause");
					system("cls");
						
					cout<<"¿Qué desea hacer?" <<endl <<endl;
					cout<<"1.Regresar al menú principal" <<endl;
					cout<<"2.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> salir;
			
					if(salir == 1){
						system("cls");
				
						return main();
					}
					else{
						system("pause");
						system("cls");
							
						cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
						cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
						return 0;
					}
				}
				else{
					if(menu1 == 3){
						system("cls");
					
						return main();
					}
					else{
						if(menu1 == 4){
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;
							return 0;
						}
					}
				}
			}
		break;
		
		case 9:
			system("cls");
			
			ofertas();
			
			system("pause");
			system("cls");
						
			cout<<"¿Qué desea hacer?" <<endl <<endl;
			cout<<"1.Regresar al menú principal" <<endl;
			cout<<"2.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> salir;
			
			if(salir == 1){
				system("cls");
				
				return main();
			}
			else{
				system("pause");
				system("cls");
						
				cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
				cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
				return 0;
			}
		break;
		
		case 10:
			system("cls");
			
			cout<<"=========================" <<endl;
			cout<<"Filtrado de Ventas" <<endl;
			cout<<"=========================" <<endl <<endl;
			cout<<"1.Diario" <<endl;
			cout<<"2.Mensual" <<endl;
			cout<<"3.Regresar al menú principal" <<endl;
			cout<<"4.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> menu1;
			
			if(menu1 == 1){
				system("cls");

				ventasFiltradoDia();
						
				system("pause");
				system("cls");
						
				cout<<"¿Qué desea hacer?" <<endl <<endl;
				cout<<"1.Regresar al menú principal" <<endl;
				cout<<"2.Salir del programa" <<endl <<endl;
				cout<<"Elija una opción: ";
				cin>> salir;
			
				if(salir == 1){
					system("cls");
				
					return main();
				}
				else{
					system("pause");
					system("cls");
							
					cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
					cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
					return 0;
				}
			}	
			else{
				if(menu1 == 2){
					system("cls");
					
					ventasFiltradoMes();
						
					system("pause");
					system("cls");
						
					cout<<"¿Qué desea hacer?" <<endl <<endl;
					cout<<"1.Regresar al menú principal" <<endl;
					cout<<"2.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> salir;
			
					if(salir == 1){
						system("cls");
					
						return main();
					}
					else{
						if(salir == 2){
							system("pause");
							system("cls");
									
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
							return 0;
						}
					}
				}
				else{
					if(menu1 == 3){
					system("cls");
				
					return main();
					}
					else{
						if(menu1 == 4){
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;
							
							return 0;
						}
					}
				}
			}		
		break;
		
		case 11:
			system("cls");
			
			cout<<"=========================" <<endl;
			cout<<"Filtrado de Ventas" <<endl;
			cout<<"=========================" <<endl <<endl;
			cout<<"1.Efectivo" <<endl;
			cout<<"2.Tarjeta de crédito o débito" <<endl;
			cout<<"3.Regresar al menú principal" <<endl;
			cout<<"4.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> menu1;
			
			if(menu1 == 1){
				system("cls");

				formasDePagoEfectivo();
						
				system("pause");
				system("cls");
						
				cout<<"¿Qué desea hacer?" <<endl <<endl;
				cout<<"1.Regresar al menú principal" <<endl;
				cout<<"2.Salir del programa" <<endl <<endl;
				cout<<"Elija una opción: ";
				cin>> salir;
			
				if(salir == 1){
					system("cls");
				
					return main();
				}
				else{
					system("pause");
					system("cls");
							
					cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
					cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
					return 0;
				}
			}	
			else{
				if(menu1 == 2){
					system("cls");
					
					formasDePagoTarjeta();
						
					system("pause");
					system("cls");
						
					cout<<"¿Qué desea hacer?" <<endl <<endl;
					cout<<"1.Regresar al menú principal" <<endl;
					cout<<"2.Salir del programa" <<endl <<endl;
					cout<<"Elija una opción: ";
					cin>> salir;
			
					if(salir == 1){
						system("cls");
					
						return main();
					}
					else{
						if(salir == 2){
							system("pause");
							system("cls");
									
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
							return 0;
						}
					}
				}
				else{
					if(menu1 == 3){
					system("cls");
				
					return main();
					}
					else{
						if(menu1 == 4){
							system("pause");
							system("cls");
							
							cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
							cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;
							
							return 0;
						}
					}
				}
			}
			
		break;
		
		case 12:
			system("cls");
			
			ventasFiltradoAnual();
			
			system("pause");
			system("cls");
						
			cout<<"¿Qué desea hacer?" <<endl <<endl;
			cout<<"1.Regresar al menú principal" <<endl;
			cout<<"2.Salir del programa" <<endl <<endl;
			cout<<"Elija una opción: ";
			cin>> salir;
			
			if(salir == 1){
				system("cls");
				
				return main();
			}
			else{
				system("pause");
				system("cls");
							
				cout<<"¡Gracias por utilizar el sistema de Mi Súper Favorito!" <<endl;
				cout<<"\t\t\t¡Vuelva pronto!" <<endl <<endl;  
				
				return 0;
			}
	}
	
	system("pause");
	
	return 0;
}

//Supermercado
void supermercadoEscribir(){
	regSuper datosSupermercado;
	
	//Si el archivo ya tiene datos, la información a grabar, se guardará después del último dato que trnga el archivo
	ofstream Archivo("Supermercado.dat", ios::app | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<" Error: ¡No se pudo abrir el archivo Supermercado.dat, por alguna extraña razón!" <<endl;
		
		exit(1);
	}
	else{
		system("cls");
		
		cout<<"===================================" <<endl;	
		cout<<"Ingrese los datos del Supermercado " <<endl;
		cout<<"===================================" <<endl <<endl;
		
		fflush(stdin);
		
		cout<<"Nombre: " <<"Mi Súper Favorito" <<endl;
		cout<<"Razón Social del Supermercado: "; 
		cin.getline(datosSupermercado.razonSocial, 51, '\n');
		cout<<"Lugar: "; 
		cin.getline(datosSupermercado.lugar, 31, '\n');
		
		fflush(stdin);
		
		cout<<"PBX: "; 
		cin>> datosSupermercado.pbx;
		
		fflush(stdin);
		
		cout<<"Correo electrónico: "; 
		cin.getline(datosSupermercado.correo, 51, '\n');
		cout<<"NIT: "; 
		cin.getline(datosSupermercado.nit, 10, '\n');
		cout<<"\n================================" <<endl <<endl;
			
		//Guardar información dentro del archivo para variablesde tipo caracter
		Archivo.write(reinterpret_cast <char*>(&datosSupermercado), sizeof(regSuper));
		
		cout<<"Datos guardados con éxito" <<endl <<endl;
	}
	
	Archivo.close();
}

void supermercadoModificar(){
	regSuper datosSupermercado;
	
	bool bandera = false;
	char razonSocialM[51];
	char opcion;

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarSupermercado.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Supermercado.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
			
			cerr<<"Error: ¡El archivo auxiliar o el de lectura ArchivoAuxiliarSupermercado.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			fflush(stdin);
			
			cout<<"Ingrese la razón social del Supermercado, del que desea modificar datos: "; 
			cin.getline(razonSocialM, 51,'\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosSupermercado), sizeof(regSuper))){
				if ( strcmp(datosSupermercado.razonSocial, razonSocialM) == 0){
					system("cls");
					
					cout<<"===============================================" <<endl;
					cout<<"Los datos actuales del Supermercado, son:" <<endl <<endl;
					cout<<"===============================================" <<endl;
					cout<<"Razón Social: " <<datosSupermercado.razonSocial <<endl;
					cout<<"Nombre: " <<"Mi Súper Favorito" <<endl;
					cout<<"Lugar: " <<datosSupermercado.lugar <<endl;
					cout<<"PBX: " <<datosSupermercado.pbx <<endl;
					cout<<"Correo electrónico: " <<datosSupermercado.correo <<endl;
					cout<<"NIT: " <<datosSupermercado.nit <<endl <<endl;
					cout<<"=====================================" <<endl <<endl;	
					cout<<"Ingrese los nuevos datos para el Supermercado: "<<endl;
					cout<<"-----------------------------------------------" <<endl <<endl;
					
					fflush(stdin);
					
					cout<<"Nueva razón social: ";
					cin.getline(datosSupermercado.razonSocial, 51, '\n');
					
					cout <<"Nuevo lugar: "; 
					cin.getline(datosSupermercado.lugar, 31, '\n');
					
					fflush(stdin);
				
					cout <<"Nuevo PBX: "; 
					cin>> datosSupermercado.pbx;
					
					fflush(stdin);
					
					cout <<"Nuevo correo electrónico: "; 
					cin.getline(datosSupermercado.correo, 21, '\n');
					cout <<"Nuevo NIT: "; 
					cin.getline(datosSupermercado.nit, 10, '\n');
					cout << "\n\n-----------------------------------------------" <<endl;
					
					ArchivoAux.write(reinterpret_cast<char *>(&datosSupermercado), sizeof(regSuper));
					bandera = true;
				}
				else
					ArchivoAux.write(reinterpret_cast<char *>(&datosSupermercado), sizeof(regSuper));
			}

			ArchivoLectura.close();
			ArchivoAux.close();

			if (bandera == false) {
				remove("ArchivoAuxiliarSupermercado.dat");
				cout << "\n\nRegistro no encontrado." <<endl<<endl;
			}
			else {
				remove("Supermercado.dat");
				rename("ArchivoAuxiliarSupermercado.dat", "Supermercado.dat");
				cout << "\n\nRegistro actualizado exitosamente!." <<endl<<endl;
			}
		}
		cout << "\n\n¿Desea modificar los datos nuevamente (s = si, n = no)?:  "; 
		
		fflush(stdin);
		 
		cin >> opcion;
	} while (opcion == 's' || opcion == 'S');
} 

void supermercadoEliminar(){
	regSuper datosSupermercado;
	
	bool bandera = false; 
	bool bandera2 = false;
	char opcion;
	
	system("cls");
		
	ofstream ArchivoAux ("ArchivoAuxiliarSupermercado.dat", ios::out | ios::binary);
	ifstream ArchivoLectura ("Supermercado.dat", ios::in | ios::binary);
		
	if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
		system("cls");
		
		cerr<<"\nError: ¡El archivo auxiliar ArchAuxiliarSupermercado.dat o el de lectura Supermercado.dat, no se pudo abrir o no existe!."<<endl;
		
		exit(1);
	}
	else {
		while (ArchivoLectura.read(reinterpret_cast<char *>(&datosSupermercado), sizeof(regSuper))) {
			system("cls");
				
			cout<<"===============================================" <<endl;
			cout<<"Los datos actuales del Supermercado, son:" <<endl <<endl;
			cout<<"===============================================" <<endl;
			cout<<"Razón Social: " <<datosSupermercado.razonSocial <<endl;
			cout<<"Nombre: " <<"Mi Súper Favorito" <<endl;
			cout<<"Lugar: " <<datosSupermercado.lugar <<endl;
			cout<<"PBX: " <<datosSupermercado.pbx <<endl;
			cout<<"Correo electrónico: " <<datosSupermercado.correo <<endl;
			cout<<"NIT: " <<datosSupermercado.nit <<endl <<endl;
			cout<<"=====================================" <<endl <<endl;	
			cout << "\n\n¿Realmente desea eliminar los datos del Supermercado? (s= si o n= no): ";
			cin >> opcion;
				
			if (opcion== 's' || opcion == 'S'){
				bandera2 = true;	//Bandera para indicar que sí se eliminó el registro encontrado
			}
			else{
				ArchivoAux.write(reinterpret_cast<char *>(&datosSupermercado), sizeof(regSuper));
			}
					
			bandera = true;	//Bandera para indicar que sí se encontró el registro buscado
		};
			
		ArchivoLectura.close();
		ArchivoAux.close();
		
		if (bandera == false) {	//No se encontró el registro buscado
			remove("ArchivoAuxiliarSupermercado.dat");
			cout << "\n\n¡Registro no encontrado!." <<endl<<endl;			
		}
		else{
			if (bandera2 == false){
				remove("ArchivoAuxiliarSupermercado.dat");
				cout << "\n\n¡Registro no eliminado!." <<endl<<endl;			
			}
			else{
				remove("Supermercado.dat");
				rename("ArchivoAuxiliarSupermercado.dat","Supermercado.dat");
				cout << "\n\n¡Registro eliminado exitosamente!." <<endl <<endl;				
			}
		}
	}
}

void supermercadoAbrir(){
	regSuper datosSupermercado;
	
	char opcion;
	
	ifstream Archivo("Supermercado.dat", ios::in | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo  Supermercado.dat, porque puede ser, que no exista!" <<endl;
		
		exit(1);
	}
	else{
		
		//Lectura de datos almacenados en un archivo
		while(Archivo.read(reinterpret_cast <char*>(&datosSupermercado), sizeof(regSuper))){
			system("cls");
			
			cout<<"===============================================" <<endl;
			cout<<"Los datos actuales del Supermercado, son:" <<endl <<endl;
			cout<<"===============================================" <<endl;
			cout<<"Razón Social: " <<datosSupermercado.razonSocial <<endl;
			cout<<"Nombre: " <<"Mi Súper Favorito" <<endl;
			cout<<"Lugar: " <<datosSupermercado.lugar <<endl;
			cout<<"PBX: " <<datosSupermercado.pbx <<endl;
			cout<<"Correo electrónico: " <<datosSupermercado.correo <<endl;
			cout<<"NIT: " <<datosSupermercado.nit <<endl <<endl;
			cout<<"=====================================" <<endl <<endl;
		};
	}
	
	Archivo.close();
}

//Tipos de empleados
void tipoDeEmpleadosAbrir(){
	regEmp datosEmpleados;
	
	char opcion;
	char puestoBusqueda[21]; //21, es el tamaño o la dimensión, que tiene el campo, para ingresar la cadena de caracteres de 0 a 20
	bool bandera;
	char nombreComp[36];
	
	ifstream ArchivoDeBusqueda("Empleados.dat", ios::in | ios::binary);
	
	if(!ArchivoDeBusqueda){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Empleados.dat, porque puede ser que no exista!" <<endl;
		
		exit(1);
	}
	else{
		do{
			system("cls");
			
			bandera = false;
			
			fflush(stdin);
			
			cout<<"============================" <<endl;
			cout<<"     Tipos de empleados" <<endl;
			cout<<"============================" <<endl <<endl;
			cout<<"Ingrese el puesto que desea buscar: ";
			cin.getline(puestoBusqueda, 21,'\n');
			
			fflush(stdin);
			
			system("cls");
			
			cout<<"======================================" <<endl;
			cout<<"Los datos del empleado buscado, son:" <<endl;
			cout<<"======================================" <<endl;
			
			while(ArchivoDeBusqueda.read(reinterpret_cast <char*>(&datosEmpleados), sizeof(regEmp))){
				if( strcmp(datosEmpleados.puesto, puestoBusqueda) == 0){
					strcpy(nombreComp, datosEmpleados.nombres);
					strcat(nombreComp, " ");
					strcat(nombreComp, datosEmpleados.apellidos);
					
					cout<<"Código empleado: " <<datosEmpleados.dpi <<endl;
					cout<<"Nombre completo: " <<nombreComp <<endl;
					cout<<"Edad: " <<datosEmpleados.edad <<endl;
					cout<<"Puesto: " <<datosEmpleados.puesto <<endl;
					cout<<"Sueldo: Q." <<datosEmpleados.sueldo <<endl <<endl;
					
					bandera = true; 
					
					break;
				}
			}
			
			if(bandera == false){
				system("cls");
				
				cout<<"Registro no encontrado" <<endl;
			}
			
			cout<<"¿Desea buscar otro puesto? (s = si o n = no): ";
			cin>> opcion;
			
			if(opcion == 's' || opcion == 'S'){
				ArchivoDeBusqueda.clear();
				
				//(0 saltos, ir al inicio)
				ArchivoDeBusqueda.seekg(0, ArchivoDeBusqueda.beg);
			}
		}while(opcion == 's' || opcion == 'S');
	}
	
	ArchivoDeBusqueda.close();
}

//Empleados
void empleadosEscribir(){
	regEmp datosEmpleados;
	
	char opcion;
	
	//Si el archivo ya tiene datos, la información a grabar, se guardará después del último dato que trnga el archivo
	ofstream Archivo("Empleados.dat", ios::app | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Empleados.dat, por alguna extraña razón!" <<endl;
		
		exit(1);
	}
	else{
		do{
			system("cls");
			
			fflush(stdin);
			
			cout<<"====================================" <<endl;	
			cout<<"Ingrese los datos del empleado"  <<endl;
			cout<<"====================================" <<endl;
			cout<<"Código empleado: ";
			cin>> datosEmpleados.dpi;
			
			fflush(stdin);
			
			cout<<"Nombres: "; 
			cin.getline(datosEmpleados.nombres, 21, '\n');
			cout<<"Apellidos: "; 
			cin.getline(datosEmpleados.apellidos, 21, '\n');
			
			fflush(stdin);
			
			cout<<"Edad: "; 
			cin>> datosEmpleados.edad;
			
			fflush(stdin);
			
			cout<<"Puesto: "; 
			cin.getline(datosEmpleados.puesto, 31, '\n');
			
			fflush(stdin);
			
			if( strcmp(datosEmpleados.puesto, "Cajero") == 0 || strcmp(datosEmpleados.puesto, "cajero") == 0 || strcmp(datosEmpleados.puesto , "CAJERO") == 0 || strcmp(datosEmpleados.puesto , "Cajera") == 0|| strcmp(datosEmpleados.puesto , "cajera") == 0|| strcmp(datosEmpleados.puesto , "CAJERA") == 0){
				cout<<"Ingrese el No. de caja que tiene asignado: ";
				cin.getline(datosEmpleados.caja, 2, '\n');
			}
			
			fflush(stdin);
			
			cout<<"Sueldo: Q."; 
			cin>> datosEmpleados.sueldo;
			
			//Guardar información dentro del archivo para variablesde tipo caracter
			Archivo.write(reinterpret_cast <char*>(&datosEmpleados), sizeof(regEmp));
			
			cout<<"\n\n¿Desea ingresar los datos de otro empleado? (s = si o n = no): ";
			cin>> opcion;
		}while(opcion == 's' || opcion == 'S');
	}
	
	Archivo.close();
}

void empleadosModificar(){
	regEmp datosEmpleados;
	
	bool bandera = false;
	char dpiM[16];
	char opcion;
	char nombreComp[36];

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarEmpleados.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Empleados.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
		
			cerr<<"Error: ¡El archivo auxiliar ArchivoAuxiliarEmpleados.dat  o el de lectura Empleados.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			fflush(stdin);
						
			cout<<"Ingrese el código del empleado, del que desea modificar datos: "; 
			cin.getline(dpiM, 16, '\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosEmpleados), sizeof(regEmp))) {
				if ( strcmp(datosEmpleados.dpi, dpiM) == 0){
					strcpy(nombreComp, datosEmpleados.nombres);
					strcat(nombreComp, " ");
					strcat(nombreComp, datosEmpleados.apellidos);
					
					system("cls");
					
					cout<<"======================================" <<endl;
					cout<<"\tLos datos del empleado buscado, son:" <<endl;
					cout<<"=====================================" <<endl;
					cout<<"Código empleado: " <<datosEmpleados.dpi <<endl;
					cout<<"Nombre completo: " <<nombreComp <<endl;
					cout<<"Edad: " <<datosEmpleados.edad <<endl;
					cout<<"Puesto: " <<datosEmpleados.puesto <<endl;
					cout<<"Sueldo: Q." <<datosEmpleados.sueldo;
					cout<<"\n\n=====================================" <<endl <<endl;					
					cout<<"Ingrese los nuevos datos para el empleado: "<<endl <<endl;
					cout<< "-----------------------------------------------" <<endl <<endl;
					
					cout <<"Nuevos nombres: "; 
					cin.getline(datosEmpleados.nombres, 21,'\n');
					cout <<"Nuevos apellidos: "; 
					cin.getline(datosEmpleados.apellidos, 21,'\n');
					
										
					fflush(stdin);
					
					cout <<"Nueva edad: "; 
					cin>> datosEmpleados.edad;
					
										
					fflush(stdin);
					
					cout <<"Nuevo puesto: "; 
					cin.getline(datosEmpleados.puesto, 31,'\n');
					
										
					fflush(stdin);
					
					cout <<"Nuevo sueldo: Q."; 
					cin>> datosEmpleados.sueldo;
					cout << "\n\n-----------------------------------------------" <<endl <<endl;
					
					ArchivoAux.write(reinterpret_cast<char *>(&datosEmpleados), sizeof(regEmp));
					bandera = true;
				}
				else
					ArchivoAux.write(reinterpret_cast<char *>(&datosEmpleados), sizeof(regEmp));
			}

			ArchivoLectura.close();
			ArchivoAux.close();

			if (bandera == false) {
				remove("ArchivoAuxiliarEmpleados.dat");
				cout << "\n\nRegistro no encontrado." <<endl<<endl;
			}
			else {
				remove("Empleados.dat");
				rename("ArchivoAuxiliarEmpleados.dat", "Empleados.dat");
				cout << "\n\nRegistro actualizado exitosamente!." <<endl <<endl;
			}
		}
		
		fflush(stdin);
			
		cout<<"¿Desea modificar los datos de otro empleado (s= si o n= no)?:  ";  
		cin>> opcion;
	} while (opcion == 's' || opcion == 'S');
}

void empleadosEliminar(){
	regEmp datosEmpleados;
	
	bool bandera = false;
	int correlativo = 1;
	bool bandera2 = false;
	char dpiM[14];
	char opcion;
	char nombreComp[36];
	char salir2;

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarEmpleados.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Empleados.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
			
			cerr<<"Error: ¡El archivo auxiliar o el de lectura ArchivoAuxiliarEmpleados.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			cout<<"Ingrese el código del empleado, del que desea eliminar datos: "; 
			cin.getline(dpiM, 14, '\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosEmpleados), sizeof(regEmp))) {
				if ( strcmp(datosEmpleados.dpi, dpiM) == 0){
					strcpy(nombreComp, datosEmpleados.nombres);
					strcat(nombreComp, " ");
					strcat(nombreComp, datosEmpleados.apellidos);
					
					system("cls");
					
					cout<<"======================================" <<endl;
					cout<<"Los datos del empleado buscado, son:" <<endl <<endl;
					cout<<"=====================================" <<endl;
					cout<<"Código empleado: " <<datosEmpleados.dpi <<endl;
					cout<<"Nombre completo: " <<nombreComp <<endl;
					cout<<"Edad: " <<datosEmpleados.edad <<endl;
					cout<<"Puesto: " <<datosEmpleados.puesto <<endl;
					cout<<"Sueldo: Q." <<datosEmpleados.sueldo <<endl <<endl;
					cout<<"=====================================" <<endl <<endl;					
					cout<<"\n\n¿Realmente desea eliminar los datos del empleado? (s= si o n= no): ";
					cin>> opcion;
					
					if (opcion == 's' || opcion == 'S'){
						bandera2 = true;	//Bandera para indicar que sí se eliminó el registro encontrado
					}
					else {
						ArchivoAux.write(reinterpret_cast<char *>(&datosEmpleados), sizeof(regEmp));
					}
					bandera = true;	//Bandera para indicar que sí se encontró el registro buscado
				}
				else{
					ArchivoAux.write(reinterpret_cast<char *>(&datosEmpleados), sizeof(regEmp));
				}
			}
		}
		
		cout<<"\n\n¿Desea eliminar los datos de otro empleado? (s= sí o n= no): ";
		cin>> salir2;
		
		ArchivoLectura.close();
		ArchivoAux.close();
	
	}while(salir2 == 's' || salir2 == 'S');
}

void empleadosAbrir(){
	regEmp datosEmpleados;
	
	char nombreComp[36];
	int correlativo = 1;
	
	ifstream Archivo("Empleados.dat", ios::in | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Empleados.dat, porque puede ser, que no exista!" <<endl;
		
		exit(1);
	}
	else{
		
		//Lectura de datos almacenados en un archivo
		system("cls");
			
		cout<<"========================================================" <<endl;
		cout<<"Datos de los empleados que tiene el Supermercado" <<endl;
		cout<<"========================================================" <<endl;
	
		while(Archivo.read(reinterpret_cast <char*>(&datosEmpleados), sizeof(regEmp))){
			strcpy(nombreComp, datosEmpleados.nombres);
			strcat(nombreComp, " ");
			strcat(nombreComp, datosEmpleados.apellidos);
			
			cout<<"Correlativo: " <<correlativo++ <<endl;		
			cout<<"Código empleado: " <<datosEmpleados.dpi <<endl;
			cout<<"Nombre completo: " <<nombreComp <<endl;
			cout<<"Edad: " <<datosEmpleados.edad <<endl;
			cout<<"Puesto: " <<datosEmpleados.puesto <<endl;
			cout<<"Sueldo: Q." <<datosEmpleados.sueldo <<endl;
			cout<<"========================================================" <<endl;
		}
	}
	
	Archivo.close();
}

//Clientes
void clientesEscribir(){
	regClient datosClientes;
	
	char opcion;
	
	//Si el archivo ya tiene datos, la información a grabar, se guardará después del último dato que trnga el archivo
	ofstream Archivo("Clientes.dat", ios::app | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Clientes.dat, por alguna extraña razón!" <<endl;
		
		exit(1);
	}
	else{
		do{
			system("cls");
			
			fflush(stdin);
		
			cout<<"====================================" <<endl <<endl;	
			cout<<"Ingrese los datos del cliente" <<endl;
			cout<<"====================================" <<endl <<endl;
			cout<<"DPI: ";
			cin.getline(datosClientes.dpi, 14, '\n');
			cout<<"NIT: ";
			cin.getline(datosClientes.nit, 10, '\n');
			cout<<"Nombres: "; 
			cin.getline(datosClientes.nombres, 21, '\n');
			cout<<"Apellidos: "; 
			cin.getline(datosClientes.apellidos, 21, '\n');
			
			fflush(stdin);
			
			//Guardar información dentro del archivo para variablesde tipo caracter
			Archivo.write(reinterpret_cast <char*>(&datosClientes), sizeof(regClient));
			
			cout<<"\n\n¿Desea ingresar los datos de otro cliente? (s = si o n = no): ";
			cin>> opcion;
		}while(opcion == 's' || opcion == 'S');
	}
	
	Archivo.close();
}

void clientesModificar(){
	regClient datosClientes;
	
	bool bandera = false;
	char dpiM[14];
	char opcion;
	char nombreComp[36];

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarClientes.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Clientes.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
		
			cerr<<"Error: ¡El archivo auxiliar ArchivoAuxiliarClientes.dat o el de lectura Clientes.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			fflush(stdin);
			
			cout<<"Ingrese el No. de DPI del cliente, del que desea modificar datos: "; 
			cin.getline(dpiM, 14, '\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosClientes), sizeof(regClient))) {
				if ( strcmp(datosClientes.dpi, dpiM) == 0){
					strcpy(nombreComp, datosClientes.nombres);
					strcat(nombreComp, " ");
					strcat(nombreComp, datosClientes.apellidos);
					
					cout<<"======================================" <<endl;
					cout<<"Los datos del cliente buscado, son:" <<endl;
					cout<<"=====================================" <<endl;
					cout<<"No. de DPI: " <<datosClientes.dpi <<endl; 
					cout<<"NIT: " <<datosClientes.nit <<endl;
					cout<<"Nombre completo: " <<nombreComp <<endl <<endl; 
					cout<<"=====================================" <<endl <<endl;					
					cout<<"Ingrese los nuevos datos para el cliente: "<<endl;
					cout<<"-----------------------------------------------" <<endl <<endl;
					
					fflush(stdin);
					
					cout<<"Nuevo No. de DPI: ";
					cin.getline(datosClientes.dpi, 14, '\n');
					
					
					fflush(stdin);

					cout << "-----------------------------------------------" <<endl <<endl;
					
					ArchivoAux.write(reinterpret_cast<char *>(&datosClientes), sizeof(regClient));
					bandera = true;
				}
				else
					ArchivoAux.write(reinterpret_cast<char *>(&datosClientes), sizeof(regClient));
			}

			ArchivoLectura.close();
			ArchivoAux.close();

			if (bandera == false) {
				remove("ArchivoAuxiliarClientes.dat");
				cout << "\n\nRegistro no encontrado." <<endl<<endl;
			}
			else {
				remove("Clientes.dat");
				rename("ArchivoAuxiliarClientes.dat", "Clientes.dat");
				cout << "\n\nRegistro actualizado exitosamente!." <<endl<<endl;
			}
		}
				
		cout << "¿Desea modificar los datos de otro empleado (s = si o n = no)?:  "; 
		cin >> opcion;
	} while (opcion == 's' || opcion == 'S');
}

void clientesEliminar(){
	regClient datosClientes;
	
	bool bandera = false;
	bool bandera2 = false;
	char dpiM[14];
	char opcion;
	char nombreComp[36];
	char salir2;

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarClientes.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Clientes.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
			
			cerr<<"Error: ¡El archivo auxiliar o el de lectura ArchivoAuxiliarClientes.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			fflush(stdin);
			
			cout<<"Ingrese el No. de DPI del empleado, del que desea eliminar datos: "; 
			cin.getline(dpiM, 14, '\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosClientes), sizeof(regClient))) {
				if ( strcmp(datosClientes.dpi, dpiM) == 0){
					strcpy(nombreComp, datosClientes.nombres);
					strcat(nombreComp, " ");
					strcat(nombreComp, datosClientes.apellidos);
					
					system("cls");
					
					cout<<"========================================" <<endl;
					cout<<"\tLos datos del empleado buscado, son:" <<endl;
					cout<<"========================================" <<endl;
					cout<<"No. de DPI: " <<datosClientes.dpi <<endl;
					cout<<"NIT: " <<datosClientes.nit <<endl;
					cout<<"Nombre completo: " <<nombreComp <<endl <<endl;
					cout<<"=====================================" <<endl <<endl;					
					cout<<"¿Realmente desea eliminar los datos del cliente? (s= si o n= no): ";
					cin>> opcion;
					
					if (opcion == 's' || opcion == 'S'){
						bandera2 = true;	//Bandera para indicar que sí se eliminó el registro encontrado
					}
					else {
						ArchivoAux.write(reinterpret_cast<char *>(&datosClientes), sizeof(regClient));
					}
					bandera = true;	//Bandera para indicar que sí se encontró el registro buscado
				}
				else{
					ArchivoAux.write(reinterpret_cast<char *>(&datosClientes), sizeof(regClient));
				}
			}
		}
		
		cout<<"\n\n¿Desea eliminar los datos de otro cliente? (s= sí o n= no): ";
		cin>> salir2;
		
		ArchivoLectura.close();
		ArchivoAux.close();
	
	}while(salir2 == 's' || salir2 == 'S');
}

void clientesAbrir(){
	regClient datosClientes;
	int correlativo = 1;
	
	char nombreComp[35];
	
	ifstream Archivo("Clientes.dat", ios::in | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Clientes.dat, porque puede ser, que no exista!" <<endl;
		
		exit(1);
	}
	else{
		system("cls");
		
		cout<<"====================================================" <<endl;
		cout<<"\tDatos de los clientes que tiene el Supermercado" <<endl;
		cout<<"====================================================" <<endl;
		
		//Lectura de datos almacenados en un archivo
		while(Archivo.read(reinterpret_cast <char*>(&datosClientes), sizeof(regClient))){
			strcpy(nombreComp, datosClientes.nombres);
			strcat(nombreComp, " ");
			strcat(nombreComp, datosClientes.apellidos);
			
			cout<<"Correlativo: " <<correlativo++ <<endl;
			cout<<"No. de DPI: " <<datosClientes.dpi <<endl;
			cout<<"NIT: " <<datosClientes.nit <<endl;
			cout<<"Nombre completo: " <<nombreComp <<endl;
			cout<<"=====================================" <<endl;
		}
	}
	
	Archivo.close();
}

//Productos
void productosEscribir(){
	regProduct datosProductos;
	regEmp datosEmpleados;
	
	char opcion;
	
	//Si el archivo ya tiene datos, la información a grabar, se guardará después del último dato que trnga el archivo
	ofstream Archivo("Productos.dat", ios::app | ios::binary);
	ofstream ArchivoEmpleados("Empleados.dat", ios::app | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Productos.dat, por alguna extraña razón!" <<endl;
		
		exit(1);
	}
	else{
		do{
			system("cls");
			
			fflush(stdin);
			
			cout<<"Ingrese el No. de caja, del cajero/a que le vendió los productos: ";
			cin>> datosEmpleados.caja;
			
			fflush(stdin);
			
			cout<<"====================================" <<endl;	
			cout<<"Ingrese los datos del producto" <<endl;
			cout<<"====================================" <<endl <<endl;
			cout<<"Código: ";
			cin.getline(datosProductos.codigo, 16, '\n');
			cout<<"Clasificación (alimentos, bebidas, carnes, vehículos, perfumería y entretenimiento): ";
			cin.getline(datosProductos.clasificacion, 16, '\n');
			
			fflush(stdin);
			
			cout<<"Cantidad: "; 
			cin>> datosProductos.cantidad;
			
			fflush(stdin);
			
			cout<<"Descripción: "; 
			cin.getline(datosProductos.descripcion, 31, '\n');
			
			fflush(stdin);
			
			cout<<"Precio: Q.";
			cin>> datosProductos.precio;
			
			fflush(stdin);
			
			cout<<"Ingrese el día de venta: ";
			cin.getline(datosProductos.dia, 3, '\n');
			cout<<"Ingrese el mes: ";
			cin.getline(datosProductos.mes, 3, '\n');
			cout<<"Ingrese el año: ";
			cin.getline(datosProductos.anio, 5, '\n');
			
			fflush(stdin);
			
			datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precioTotal;
			 
			//Guardar información dentro del archivo para variablesde tipo caracter
			Archivo.write(reinterpret_cast <char*>(&datosProductos), sizeof(regProduct));
			ArchivoEmpleados.write(reinterpret_cast <char*>(&datosEmpleados), sizeof(regEmp));
			
			cout<<"\n\n¿Desea ingresar los datos de otro producto? (s = si o n = no): ";
			cin>> opcion;
		}while(opcion == 's' || opcion == 'S');
	}
	
	Archivo.close();
	ArchivoEmpleados.close();
}

void productosModificar(){
	regProduct datosProductos;
	regEmp datosEmpleados;
	
	bool bandera = false;
	char codigoM[16];
	char opcion;

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarProductos.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Productos.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
			
			cerr<<"\nError: ¡El archivo auxiliar o el de lectura ArchivoAuxiliarProdcutos.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			fflush(stdin);
			
			cout << "Ingrese el código del producto, del que desea modificar datos: "; 
			cin.getline(codigoM, 16, '\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosProductos), sizeof(regProduct))) {
				if ( strcmp(datosProductos.codigo, codigoM) == 0){
					datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
					
					system("cls");
					
					cout<<"No. de caja, del cajero/a que le vendió los productos: " <<datosEmpleados.caja <<endl;
					cout<<"========================================" <<endl;
					cout<<"\tLos datos del producto buscado, son:" <<endl;
					cout<<"=======================================" <<endl;
					cout<<"Código: " <<datosProductos.codigo <<endl;
					cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
					cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
					cout<<"Descripción: " <<datosProductos.descripcion <<endl;
					cout<<"Precio: Q." <<datosProductos.precio <<endl;
					printf("Precio Total: Q.%.2f", datosProductos.precioTotal);
					cout<<"\nFecha de venta: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl; 
					cout<<"=====================================" <<endl <<endl;					
					cout<<"Ingrese los nuevos datos para el producto: "<<endl;
					cout<<"-----------------------------------------------" <<endl <<endl;
					
					fflush(stdin);
					
					cout<<"Código: ";
					cin>> datosProductos.codigo;
					
					cout<<"Cantidad: "; 
					cin>> datosProductos.cantidad;
					
					fflush(stdin);
					
					cout<<"Descripción: ";
					cin.getline(datosProductos.descripcion, 31, '\n');
					
					fflush(stdin);
					
					cout<<"Precio: Q.";
					cin>> datosProductos.precio;
					cout << "-----------------------------------------------" <<endl <<endl;
					
					ArchivoAux.write(reinterpret_cast<char *>(&datosProductos), sizeof(regProduct));
					bandera = true;
				}
				else
					ArchivoAux.write(reinterpret_cast<char *>(&datosProductos), sizeof(regProduct));
			}

			ArchivoLectura.close();
			ArchivoAux.close();

			if (bandera == false) {
				remove("ArchivoAuxiliarProductos.dat");
				cout << "\n\nRegistro no encontrado." <<endl<<endl;
			}
			else {
				remove("Productos.dat");
				rename("ArchivoAuxiliarProductos.dat", "Productos.dat");
				cout << "\n\nRegistro actualizado exitosamente!." <<endl<<endl;
			}
		}
				
		cout << "¿Desea modificar los datos de otro producto (s = si o n = no)?:  "; 
		cin>> opcion;
	} while (opcion == 's' || opcion == 'S');
}

void productosEliminar(){
	regProduct datosProductos;
	regEmp datosEmpleados;
	
	bool bandera = false;
	bool bandera2 = false;
	char codigoM[16];
	char opcion;
	char salir2;

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarProductos.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Productos.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
		
			cerr<<"\nError: ¡El archivo auxiliar o el de lectura ArchivoAuxiliarProductos.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			fflush(stdin);
			
			cout<<"Ingrese el código del producto, del que desea eliminar datos: "; 
			cin.getline(codigoM, 16, '\n' );
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosProductos), sizeof(regProduct))) {
				if ( strcmp(datosProductos.codigo, codigoM) == 0){
					datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
					
					system("cls");
					
					cout<<"No. de caja, del cajero/a que le vendió los productos: " <<datosEmpleados.caja <<endl;
					cout<<"======================================" <<endl;
					cout<<"\tLos datos del producto buscado, son:" <<endl;
					cout<<"=====================================" <<endl;
					cout<<"Código: " <<datosProductos.codigo <<endl;
					cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
					cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
					cout<<"Descripción: " <<datosProductos.descripcion <<endl;
					cout<<"Precio: Q." <<datosProductos.precio <<endl;
					printf("Precio Total: Q.%.2f", datosProductos.precioTotal);
					cout<<"\nFecha de venta: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl; 
					cout<<"=====================================" <<endl <<endl;  					
					cout<<"¿Realmente desea eliminar los datos del producto? (s= si o n= no): ";
					cin>> opcion;
					
					if (opcion == 's' || opcion == 'S'){
						bandera2 = true;	//Bandera para indicar que sí se eliminó el registro encontrado
					}
					else {
						ArchivoAux.write(reinterpret_cast<char *>(&datosProductos), sizeof(regProduct));
					}
					bandera = true;	//Bandera para indicar que sí se encontró el registro buscado
				}
				else{
					ArchivoAux.write(reinterpret_cast<char *>(&datosProductos), sizeof(regProduct));
				}
			}
			
			ArchivoLectura.close();
			ArchivoAux.close();
		
			if (bandera == false) {	//No se encontró el registro buscado
				remove("ArchivoAuxiliarProductos.dat");
				cout << "\n\n\tRegistro no encontrado!." <<endl<<endl;			
			}
			else {
				if (bandera2 == false) {
					remove("ArchivoAuxiliarProductos.dat");
					cout << "\n\n\tRegistro encontrado, pero no eliminado!." <<endl<<endl;			
				}
				else {
					remove("Productos.dat");
					rename("ArchivoAuxiliarProductos.dat","Productos.dat");
					cout << "\n\n\t¡Registro eliminado exitosamente!." <<endl<<endl;				
				}
			}
		}
		
		cout<<"\n\n¿Desea eliminar los datos de otro productos? (s= sí o n= no): ";
		cin>> salir2;
	}while(salir2 == 's' || salir2 == 'S');
}

void productosAbrir(){
	regProduct datosProductos;
	regEmp datosEmpleados;
	
	int correlativo = 1;
	
	ifstream Archivo("Productos.dat", ios::in | ios::binary);
	ifstream ArchivoEmpleados("Empleados.dat", ios::in | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Productos.dat, porque puede ser, que no exista!" <<endl;
		
		exit(1);
	}
	else{
		system("cls");
					
		cout<<"======================================================" <<endl;
		cout<<"Datos de los prodcutos que tiene el Supermercado" <<endl;
		cout<<"======================================================" <<endl;
		
		//Lectura de datos almacenados en un archivo
		while(Archivo.read(reinterpret_cast <char*>(&datosProductos), sizeof(regProduct)) && ArchivoEmpleados.read(reinterpret_cast<char *>(&datosEmpleados),sizeof(regEmp))){
			datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
			cout<<"Fecha: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl <<endl;
			cout<<"No. de caja, del cajero/a que le vendió los productos: " <<datosEmpleados.caja <<endl;
			cout<<"Correlativo: " <<correlativo ++ <<endl;
			cout<<"Código: " <<datosProductos.codigo <<endl;
			cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
			cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
			cout<<"Descripción: " <<datosProductos.descripcion <<endl;
			cout<<"Precio: Q." <<datosProductos.precio <<endl;
			printf("Precio Total: Q.%.2f", datosProductos.precioTotal); 
			cout<<"\nFecha de venta: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl <<endl;  
			cout<<"=====================================" <<endl <<endl;
		}
	}
	
	Archivo.close();
}

//Tipos de productos
void tiposDeProductosFiltrar(){
	regProduct datosProductos;
	
	bool bandera;
	bool bandera1;
	char opcion;
	int opcion_filtrado = 0;
	float precioTotal;
	int correlativo = 1;
	
	ifstream ArchivoLectura("Productos.dat", ios::in | ios::binary);

	if (ArchivoLectura.fail()) { // Validacion de fallo en la apertura del archivo
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo de lectura!."<<endl;
		
		exit(1);
	}
	else {
		do {
			bandera = false;
			bandera1 = false;
		
			system("cls");
			
			cout<< "======================" << endl;
			cout<< "\tTipos de productos" << endl;
			cout<< "======================" << endl <<endl;
			cout<< "1.Alimentos" << endl;
			cout<< "2.Bebidas" << endl;
			cout<< "3.Carnes" << endl;
			cout<< "4.Vehículos" << endl;
			cout<< "5.Perfumería" << endl;
			cout<< "6.Salir." << endl <<endl;
			cout<< "Elija una opción: ";
			cin>> opcion_filtrado;
			
			system("cls");
					
			cout<<"======================================================" <<endl;
			cout<<"Datos de los prodcutos que tiene el Supermercado" <<endl;
			cout<<"======================================================" <<endl;
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosProductos), sizeof(regProduct))) {
				switch(opcion_filtrado) {
				   	case 1: 
						if( strcmp(datosProductos.clasificacion, "Alimentos") == 0 || strcmp(datosProductos.clasificacion, "alimentos") == 0){
							
							datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
	
							cout<<"Correlativo: " <<correlativo ++ <<endl;
							cout<<"Código: " <<datosProductos.codigo <<endl;
							cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
							cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
							cout<<"Descripción: " <<datosProductos.descripcion <<endl;
							cout<<"Precio: Q." <<datosProductos.precio <<endl;
							printf("Precio Total: Q.%.2f", datosProductos.precioTotal); 
							cout<<"\n\n======================================================" <<endl <<endl;
					
							bandera = true; 
						}	
					break;
					
				   	case 2:
						if( strcmp(datosProductos.clasificacion, "Bebidas") == 0 || strcmp(datosProductos.clasificacion, "bebidas") == 0){
							
							datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
	
							cout<<"Correlativo: " <<correlativo ++ <<endl;
							cout<<"Código: " <<datosProductos.codigo <<endl;
							cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
							cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
							cout<<"Descripción: " <<datosProductos.descripcion <<endl;
							cout<<"Precio: Q." <<datosProductos.precio <<endl;
							printf("Precio Total: Q.%.2f", datosProductos.precioTotal);  
							
							cout<<"\n\n======================================================" <<endl <<endl;
					
							bandera = true; 
						}
				   	break;
				   	
				   	case 3:
						if( strcmp(datosProductos.clasificacion, "Carnes") == 0 || strcmp(datosProductos.clasificacion, "carnes") == 0){
							
							datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
	
							cout<<"Correlativo: " <<correlativo ++ <<endl;
							cout<<"Código: " <<datosProductos.codigo <<endl;
							cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
							cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
							cout<<"Descripción: " <<datosProductos.descripcion <<endl;
							cout<<"Precio: Q." <<datosProductos.precio <<endl;
							printf("Precio Total: Q.%.2f", datosProductos.precioTotal);   
							
							cout<<"\n\n======================================================" <<endl <<endl; 
					
							bandera = true; 
						}
				   	break;
						   				   		
				   	case 4:
						if( strcmp(datosProductos.clasificacion, "Vehículos") == 0 || strcmp(datosProductos.clasificacion, "Vehiculos") == 0 || strcmp(datosProductos.clasificacion, "vehículos") == 0 || strcmp(datosProductos.clasificacion, "vehiculos") == 0){
							
							datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
	
							cout<<"Correlativo: " <<correlativo ++ <<endl;
							cout<<"Código: " <<datosProductos.codigo <<endl;
							cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
							cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
							cout<<"Descripción: " <<datosProductos.descripcion <<endl;
							cout<<"Precio: Q." <<datosProductos.precio <<endl;
							printf("Precio Total: Q.%.2f", datosProductos.precioTotal);  
							cout<<"\n\n======================================================" <<endl <<endl;
					
							bandera = true; 
						}
				   	break;	
					   			   		
				   	case 5:
						if( strcmp(datosProductos.clasificacion, "Perfumería") == 0 || strcmp(datosProductos.clasificacion, "Perfumeria") == 0 || strcmp(datosProductos.clasificacion, "perfumería") == 0 || strcmp(datosProductos.clasificacion, "perfumeria") == 0){
							
							datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
	
							cout<<"Correlativo: " <<correlativo ++ <<endl;
							cout<<"Código: " <<datosProductos.codigo <<endl;
							cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
							cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
							cout<<"Descripción: " <<datosProductos.descripcion <<endl;
							cout<<"Precio: Q." <<datosProductos.precio <<endl;
							printf("Precio Total: Q.%.2f", datosProductos.precioTotal);
							cout<<"\n\n======================================================" <<endl <<endl;  
					
							bandera = true; 
						}
				   	break;
					
					case 6:
						if( strcmp(datosProductos.clasificacion, "Entretenimiento") == 0 || strcmp(datosProductos.clasificacion, "entretenimiento") == 0){
							
							datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
	
							cout<<"Correlativo: " <<correlativo ++ <<endl;
							cout<<"Código: " <<datosProductos.codigo <<endl;
							cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
							cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
							cout<<"Descripción: " <<datosProductos.descripcion <<endl;
							cout<<"Precio: Q." <<datosProductos.precio <<endl;
							printf("Precio Total: Q.%.2f", datosProductos.precioTotal);    
							cout<<"\n\n======================================================" <<endl <<endl;
							
							bandera = true; 
						}
					break;
					
					case 7:
						while(ArchivoLectura.read(reinterpret_cast <char*>(&datosProductos), sizeof(regProduct))){
							datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
	
							cout<<"Correlativo: " <<correlativo ++ <<endl;
							cout<<"Código: " <<datosProductos.codigo <<endl;
							cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
							cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
							cout<<"Descripción: " <<datosProductos.descripcion <<endl;
							cout<<"Precio: Q." <<datosProductos.precio <<endl;
							printf("Precio Total: Q.%.2f", datosProductos.precioTotal, "\n\n");
							cout<<"\n\n======================================================" <<endl <<endl;
							
							bandera = true;   
						}
					break;		
					   		   		
				   	case 8: 
					   exit(1);
				   		
				   	default: 
					   bandera1 = true;
				}
			};
			
			cout<<"\n======================================================" <<endl <<endl;
			
			if(bandera == true) {
				cout.precision(2);			
			}
			else{
				if(bandera1 == true){
					system("cls");
					
					cout<<"Opción elegida fuera del rango (1 - 7) - ¡Elección inválida!." <<endl;
				}
				else{
					system("cls");
					
					cout << "No se encontró ninguna coincidencia con lo buscado." <<endl;
				}
			}
				
			fflush(stdin);
					
			cout<<"¿Desea filtrar y/o generar otro reporte  (s= si o n= no)?: ";	 
			cin>> opcion;
			
			if (opcion == 's' || opcion == 'S') {
				ArchivoLectura.clear();							//Con clear() se limpian los flags de estado para que seekg pueda funcionar
				ArchivoLectura.seekg(0, ArchivoLectura.beg);	//y pueda regresar a la posición inicial del archivo y hacer otra búsqueda
			}
		}while(opcion == 's' || opcion == 'S');	
	}	
	ArchivoLectura.close();
}

//Proveedores
void proveedoresEscribir(){
	regProv datosProveedores;
	
	char opcion;
	
	//Si el archivo ya tiene datos, la información a grabar, se guardará después del último dato que trnga el archivo
	ofstream Archivo("Proveedores.dat", ios::app | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Proveedores.dat, por alguna extraña razón!" <<endl;
		
		exit(1);
	}
	else{
		do{
			system("cls");
			
			fflush(stdin);
		
			cout<<"====================================" <<endl <<endl;	
			cout<<"Ingrese los datos del proveedor" <<endl;
			cout<<"====================================" <<endl <<endl;
			cout<<"NIT: ";
			cin.getline(datosProveedores.nit, 10, '\n');
			cout<<"Nombre comercial: "; 
			cin.getline(datosProveedores.nombreComercial, 31, '\n');
			cout<<"Razón social: "; 
			cin.getline(datosProveedores.razonSocial, 51, '\n');
			cout<<"Lugar: "; 
			cin.getline(datosProveedores.lugar, 31, '\n');
			
			fflush(stdin);
			
			cout<<"PBX: "; 
			cin>> datosProveedores.pbx;
			
			fflush(stdin);
			
			cout<<"Correo electrónico: ";
			cin.getline(datosProveedores.correo, 51, '\n');
			
			fflush(stdin);
			
			//Guardar información dentro del archivo para variablesde tipo caracter
			Archivo.write(reinterpret_cast <char*>(&datosProveedores), sizeof(regProv));
			
			cout<<"\n\n¿Desea ingresar los datos de otro proveedor? (s = si o n = no): ";
			cin>> opcion;
		}while(opcion == 's' || opcion == 'S');
	}
	
	Archivo.close();
}

void proveedoresModificar(){
	regProv datosProveedores;
	
	bool bandera = false;
	char nombreComercialM[31];
	char opcion;

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarProveedores.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Proveedores.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
			
			cerr<<"\nError: ¡El archivo auxiliar o el de lectura ArchivoAuxiliarProveedores.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			cout << "\n\tIngrese el nombre comercial del proveedor, del que desea modificar datos: "; 
			cin.getline(nombreComercialM, 30, '\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosProveedores), sizeof(regProv))) {
				if ( strcmp(datosProveedores.nombreComercial, nombreComercialM) == 0){
					system("cls");
					
					cout<<"======================================" <<endl;
					cout<<"Los datos del proveedor buscado, son:" <<endl;
					cout<<"=====================================" <<endl;
					cout<<"NIT: " <<datosProveedores.nit <<endl;
					cout<<"Nombre comercial: " <<datosProveedores.nombreComercial <<endl; 
					cout<<"Razón social: " <<datosProveedores.razonSocial <<endl; 
					cout<<"Lugar: " <<datosProveedores.lugar <<endl; 
					cout<<"Correo electrónico: " <<datosProveedores.correo <<endl; 
					cout<<"PBX: " <<datosProveedores.pbx <<endl; 
					cout<<"=====================================" <<endl <<endl;					
					cout<<"Ingrese los nuevos datos para el proveedor: "<<endl;
					cout<<"-----------------------------------------------" <<endl;
					
					fflush(stdin);
					
					cout<<"Nuevo NIT: ";
					cin.getline(datosProveedores.nit, 10, '\n');
					cout<<"Nuevo nombre comercial: "; 
					cin.getline(datosProveedores.nombreComercial, 31, '\n');
					cout<<"Nueva razón Social: "; 
					cin.getline(datosProveedores.razonSocial, 51, '\n');
					cout<<"Nuevo lugar: "; 
					cin.getline(datosProveedores.lugar, 31, '\n');
					
					fflush(stdin);
					
					cout<<"Nuevo PBX: "; 
					cin>> datosProveedores.pbx;
					
					fflush(stdin);
					
					cout<<"Nuevo correo electrónico: ";
					cin.getline(datosProveedores.correo, 51, '\n');
					
					fflush(stdin);

					cout << "-----------------------------------------------" <<endl;
					
					ArchivoAux.write(reinterpret_cast<char *>(&datosProveedores), sizeof(regProv));
					bandera = true;
				}
				else
					ArchivoAux.write(reinterpret_cast<char *>(&datosProveedores), sizeof(regProv));
			}

			ArchivoLectura.close();
			ArchivoAux.close();

			if (bandera == false) {
				remove("ArchivoAuxiliarProveedores.dat");
				cout << "\n\n\tRegistro no encontrado." <<endl<<endl;
			}
			else {
				remove("Proveedores.dat");
				rename("ArchivoAuxiliarProveedores.dat", "Proveedores.dat");
				cout << "\n\n\tRegistro actualizado exitosamente!." <<endl<<endl;
			}
		}
		cout << "\n\n¿Desea modificar los datos de otro proveedor (s = si o n = no)?:  "; 
		
		fflush(stdin);
		
		cin >> opcion;
	} while (opcion == 's' || opcion == 'S');
}

void proveedoresEliminar(){
	regProv datosProveedores;
	bool bandera = false;
	bool bandera2 = false;
	char nombreComercialM[30];
	char opcion;
	char salir2;

	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarProveedores.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Proveedores.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
			
			cerr<<"\nError: ¡El archivo auxiliar o el de lectura ArchivoAuxiliarProveedores.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			cout << "\n\tIngrese el nombre comercial del proveedor, del que desea eliminar datos: "; 
			cin.getline(nombreComercialM, 31, '\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosProveedores), sizeof(regProv))) {
				if ( strcmp(datosProveedores.nombreComercial, nombreComercialM) == 0){
					system("cls");
					
					cout<<"======================================" <<endl;
					cout<<"Los datos del proveedor buscado, son:" <<endl;
					cout<<"=====================================" <<endl <<endl;
					cout<<"NIT: " <<datosProveedores.nit <<endl;
					cout<<"Nombre comercial: " <<datosProveedores.nombreComercial <<endl; 
					cout<<"Razón social: " <<datosProveedores.razonSocial <<endl; 
					cout<<"Lugar: " <<datosProveedores.lugar <<endl; 
					cout<<"Correo electrónico: " <<datosProveedores.correo <<endl; 
					cout<<"PBX: " <<datosProveedores.pbx <<endl; 
					cout<<"=====================================" <<endl <<endl;					
					cout<<"\n\n¿Realmente desea eliminar los datos del proveedor? (s = si o n = no): ";
					cin>> opcion;
					
					if (opcion == 's' || opcion == 'S'){
						bandera2 = true;	//Bandera para indicar que sí se eliminó el registro encontrado
					}
					else {
						ArchivoAux.write(reinterpret_cast<char *>(&datosProveedores), sizeof(regProv));
					}
					bandera = true;	//Bandera para indicar que sí se encontró el registro buscado
				}
				else{
					ArchivoAux.write(reinterpret_cast<char *>(&datosProveedores), sizeof(regProv));
				}
			}
		}
		
		cout<<"\n\n¿Desea eliminar los datos de otro proveedor? (s= sí o n= no): ";
		cin>> salir2;
		
		ArchivoLectura.close();
		ArchivoAux.close();
	
	}while(salir2 == 's' || salir2 == 'S');
}

void proveedoresAbrir(){
	regProv datosProveedores;
	
	ifstream Archivo("Proveedores.dat", ios::in | ios::binary);
	
	if(!Archivo){
		system("cls");
		
		cerr<<" Error: ¡No se pudo abrir el archivo Proveedores.dat, porque puede ser, que no exista!" <<endl;
		
		
		exit(1);
	}
	else{
		
		cout<<"====================================================" <<endl;
		cout<<"\tDatos de los proveedores que tiene el Supermercado" <<endl;
		cout<<"====================================================" <<endl;
		
		//Lectura de datos almacenados en un archivo
		while(Archivo.read(reinterpret_cast <char*>(&datosProveedores), sizeof(regProv))){
			cout<<"NIT: " <<datosProveedores.nit <<endl;
			cout<<"Nombre comercial: " <<datosProveedores.nombreComercial <<endl; 
			cout<<"Razón social: " <<datosProveedores.razonSocial <<endl; 
			cout<<"Lugar: " <<datosProveedores.lugar <<endl; 
			cout<<"Correo electrónico: " <<datosProveedores.correo<<endl; 
			cout<<"PBX: " <<datosProveedores.pbx <<endl; 
			cout<<"=====================================" <<endl;
		}
	}
	
	Archivo.close();
}

//Cajas
void cajasEscribir(){ 
	regEmp datosEmpleados;
	regCajas datosCajas;
	
	bool bandera = false;
	char dpiA[16];
	char cajaA[2];
	char opcion;

	do{
		bandera=false;
		
		ofstream ArchivoCaja("Cajas.dat", ios::out | ios::binary);
		ifstream ArchivoEmpleados("Empleados.dat", ios::in | ios::binary);
	
		if (ArchivoCaja.fail() || ArchivoEmpleados.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
		
			cerr<<"Error: ¡El archivo Cajas.dat  o el de lectura Empleados.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			fflush(stdin);
						
			cout<<"Ingrese el código del empleado: "; 
			cin.getline(dpiA, 16, '\n');
			
			cout<<"Ingrese el No. de caja que tiene asignado: ";
			cin.getline(cajaA, 2, '\n');
			
			cout<<"====================================================" <<endl;
			cout<<"\t\t\tCajas" <<endl;
			cout<<"====================================================" <<endl;
		
			while (ArchivoEmpleados.read(reinterpret_cast<char *>(&datosEmpleados), sizeof(regEmp))) {
				if ( strcmp(datosEmpleados.dpi, dpiA) == 0 && strcmp(datosEmpleados.caja, cajaA) == 0){
					system("cls");
					
					cout <<"Ingrese el monto que tiene asignada la caja No. " <<datosEmpleados.caja <<": Q."; 
					cin>> datosCajas.monto;
					
					fflush(stdin);
					
					cout <<"Ingrese la forma de pago que acepta la caja (efectivo o tarjeta): "; 
					cin.getline(datosCajas.formasDePago, 9, '\n');					

					cout << "\n\n-----------------------------------------------" <<endl <<endl;
					
					ArchivoCaja.write(reinterpret_cast<char *>(&datosCajas), sizeof(regCajas));
					bandera = true;
				}
				else
					ArchivoCaja.write(reinterpret_cast<char *>(&datosCajas), sizeof(regCajas));
			}

			ArchivoEmpleados.close();
			ArchivoCaja.close();
		}
		
		fflush(stdin);
			
		cout<<"¿Desea agregar los datos de otra caja (s= si o n= no)?:  ";  
		cin>> opcion;
	} while (opcion == 's' || opcion == 'S');
}

void cajasModificar(){
	regEmp datosEmpleados;
	regCajas datosCajas;
	
	bool bandera = false;
	char dpiA[16];
	char cajaA[2];
	char opcion;

	do{
		bandera=false;
		
		ofstream ArchivoAux("ArchvoAuxiliarCajas.dat", ios::out | ios::binary);
		ifstream ArchivoCaja("Cajas.dat", ios::out | ios::binary);
		ifstream ArchivoEmpleados("Empleados.dat", ios::in | ios::binary);
	
		if (ArchivoAux.fail() || ArchivoCaja.fail() || ArchivoEmpleados.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
		
			cerr<<"Error: ¡El archivo ArchivoAuxiliarCajas.dat, Cajas.dat  o el de lectura Empleados.dat, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			fflush(stdin);
						
			cout<<"Ingrese el código del empleado, del que desea modificar datos: "; 
			cin.getline(dpiA, 16, '\n');
			
			cout<<"Ingrese el No. de caja que tiene asignado: ";
			cin.getline(cajaA, 2, '\n');
			
			cout<<"====================================================" <<endl;
			cout<<"\t\t\tDatos de la caja buscada" <<endl;
			cout<<"====================================================" <<endl;
		
			while (ArchivoEmpleados.read(reinterpret_cast<char *>(&datosEmpleados), sizeof(regEmp))) {
				if ( strcmp(datosEmpleados.dpi, dpiA) == 0 && strcmp(datosEmpleados.caja, cajaA) == 0){
					cout<<"Monto que tiene asignada la caja: Q." <<datosCajas.monto <<endl;
					cout<<"Forma de pago que tiene asignada la caja: " <<datosCajas.formasDePago <<endl;
					cout<<"====================================================" <<endl;
					cout<<"Ingrese los nuevos datos para el proveedor: "<<endl;
					cout<<"-----------------------------------------------" <<endl;
					cout <<"Ingrese el nuevo monto que tiene asignada la caja No. " <<datosEmpleados.caja <<": Q."; 
					cin>> datosCajas.monto;
					
					fflush(stdin);
					
					cout <<"Ingrese el nuevo tipo de pago que acepta la caja (efectivo o tarjeta): "; 
					cin.getline(datosCajas.formasDePago, 9, '\n');					

					cout << "\n\n-----------------------------------------------" <<endl <<endl;
					
					ArchivoAux.write(reinterpret_cast<char *>(&datosCajas), sizeof(regCajas));
					bandera = true;
				}
				else
					ArchivoAux.write(reinterpret_cast<char *>(&datosCajas), sizeof(regCajas));
			}

			ArchivoEmpleados.close();
			ArchivoCaja.close();
		}
		
		fflush(stdin);

		if (bandera == false) {
			remove("ArchivoAuxiliarCajas.dat");
			cout << "\n\n\tRegistro no encontrado." <<endl<<endl;
		}
		else {
			remove("Cajas.dat");
			rename("ArchivoAuxiliarCajas.dat", "Cajas.dat");
			cout << "\n\n\tRegistro actualizado exitosamente!." <<endl<<endl;
		}
			
		cout<<"¿Desea modificar los datos de otra caja (s= si o n= no)?:  ";  
		cin>> opcion;
	} while (opcion == 's' || opcion == 'S');
}

void cajasEliminar(){
	regEmp datosEmpleados;
	regCajas datosCajas;
	
	bool bandera;
	bool bandera2;
	char dpiA[16];
	char cajaA[2];
	char opcion;
	char salir2;
	
	do{
		bandera=false;
		
		ofstream ArchivoAux ("ArchivoAuxiliarCajas.dat", ios::out | ios::binary);
		ifstream ArchivoLectura ("Cajas.dat", ios::in | ios::binary);
	
		if (ArchivoLectura.fail() || ArchivoAux.fail()) { //Validación de apertura de los 2 archivos
			system("cls");
			
			cerr<<"\nError: ¡El archivo auxiliar o el de lectura, no se pudo abrir o no existe!."<<endl;
			
			exit(1);
		}
		else {
			system("cls");
			
			cout<<"Ingrese el código del empleado, del que desea modificar datos: "; 
			cin.getline(dpiA, 16, '\n');
			
			cout<<"Ingrese el No. de caja que tiene asignado: ";
			cin.getline(cajaA, 2, '\n');
		
			while (ArchivoLectura.read(reinterpret_cast<char *>(&datosCajas), sizeof(regCajas))) {
				if ( strcmp(datosEmpleados.dpi, dpiA) == 0 && strcmp(datosEmpleados.caja, cajaA) == 0){
					system("cls");
					
					cout<<"======================================" <<endl;
					cout<<"Los datos de la caja buscada, son:" <<endl;
					cout<<"=====================================" <<endl <<endl;
					cout<<"Monto que tiene asignada la caja: Q." <<datosCajas.monto <<endl;
					cout<<"Forma de pago que tiene asignada la caja: " <<datosCajas.formasDePago <<endl;
					cout<<"=====================================" <<endl <<endl;					
					cout<<"\n\n¿Realmente desea eliminar los datos de la caja? (s= si; n= no). ";
					cin>> opcion;
					
					if (opcion == 's' || opcion == 'S'){
						bandera2 = true;	//Bandera para indicar que sí se eliminó el registro encontrado
					}
					else {
						ArchivoAux.write(reinterpret_cast<char *>(&datosCajas), sizeof(regCajas));
					}
					bandera = true;	//Bandera para indicar que sí se encontró el registro buscado
				}
				else{
					ArchivoAux.write(reinterpret_cast<char *>(&datosCajas), sizeof(regCajas));
				}
			}
		}
		
		cout<<"\n\n¿Desea eliminar los datos de otra caja? (s= sí o n= no): ";
		cin>> salir2;
		
		ArchivoLectura.close();
		ArchivoAux.close();
	
	}while(salir2 == 's' || salir2 == 'S');
}

void cajasAbrir(){
	regEmp datosEmpleados;
	regCajas datosCajas;
	
	char nombreComp[36];
	float montoTotal;
	
	ifstream ArchivoCajas("Cajas.dat", ios::in | ios::binary);
	ifstream ArchivoEmpleados("Empleados.dat", ios::in | ios::binary);
	
	if(!ArchivoCajas || !ArchivoEmpleados){
		system("cls");
		
		cerr<<" Error: ¡No se pudo abrir el archivo Cajas.dat o Empleadeos.dat, porque puede ser, que no existan!" <<endl;
		
		
		exit(1);
	}
	else{
		
		cout<<"====================================================" <<endl;
		cout<<"\tDatos de las cajs que tiene el Supermercado" <<endl;
		cout<<"====================================================" <<endl;
		
		//Lectura de datos almacenados en un archivo
		while(ArchivoCajas.read(reinterpret_cast <char*>(&datosCajas), sizeof(regCajas)) && ArchivoEmpleados.read(reinterpret_cast <char*>(&datosEmpleados), sizeof(regEmp))){
			strcpy(nombreComp, datosEmpleados.nombres);
			strcat(nombreComp, " ");
			strcat(nombreComp, datosEmpleados.apellidos);
			
			cout<<"No. de caja: " <<datosEmpleados.caja <<endl;
			cout<<"Nombre del empleado que atiende la caja: " <<nombreComp <<endl;
			cout<<"Monto que tiene asignada la caja: Q." <<datosCajas.monto <<endl; 
			cout<<"Forma de pago que acepta: " <<datosCajas.formasDePago <<endl; 
			cout<<"=====================================" <<endl;
			
			montoTotal = montoTotal + datosCajas.monto;
		}
		
		cout<<"Monto total que tienen las cajas: Q." <<montoTotal <<endl <<endl;
	}
	ArchivoCajas.close();
	ArchivoEmpleados.close();
}

//Ofertas
void ofertas(){
	regProduct datosProductos;
	regEmp datosEmpleados;
	
	int correlativo = 1;
	float descuento;
	float precioTotalFinal;
	
	ifstream ArchivoProductos("Productos.dat", ios::in | ios::binary);
	ifstream ArchivoEmpleados("Empleados.dat", ios::in | ios::binary);
	
	if(!ArchivoProductos || !ArchivoEmpleados){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Productos.dat o Empleados.dat, porque puede ser, que no existan!" <<endl;
		
		exit(1);
	}
	else{
		system("cls");
					
		cout<<"=====================================" <<endl;
		cout<<"Las ventas que tienen descuento son:" <<endl;
		cout<<"=====================================" <<endl <<endl;
		
		//Lectura de datos almacenados en un archivo
		while(ArchivoProductos.read(reinterpret_cast <char*>(&datosProductos), sizeof(regProduct)) && ArchivoEmpleados.read(reinterpret_cast<char *>(&datosEmpleados),sizeof(regEmp))){
			datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
			descuento = datosProductos.precioTotal * 0.15;
			precioTotalFinal = datosProductos.precioTotal - descuento;
			
			if(datosProductos.precioTotal >= 1000){
				cout<<"\t\tVenta con descuento" <<endl <<endl;
				cout<<"\nFecha de venta: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl;
				cout<<"No. de caja, del cajero/a que le vendió los productos: " <<datosEmpleados.caja <<endl;
				cout<<"Correlativo: " <<correlativo ++ <<endl;
				cout<<"Código: " <<datosProductos.codigo <<endl;
				cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
				cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
				cout<<"Descripción: " <<datosProductos.descripcion <<endl;
				cout<<"Precio: Q." <<datosProductos.precio <<endl;
				printf("Precio Total: Q.%.2f", datosProductos.precioTotal); 
				printf("\nPrecio Total Final: Q.%.2f", precioTotalFinal);  
				cout<<"=====================================" <<endl <<endl;
			}
			else{
				cout<<"\t\tVenta sin descuento" <<endl <<endl;
				cout<<"\nFecha de venta: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl;
				cout<<"No. de caja, del cajero/a que le vendió los productos: " <<datosEmpleados.caja <<endl;
				cout<<"Correlativo: " <<correlativo ++ <<endl;
				cout<<"Código: " <<datosProductos.codigo <<endl;
				cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
				cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
				cout<<"Descripción: " <<datosProductos.descripcion <<endl;
				cout<<"Precio: Q." <<datosProductos.precio <<endl;
				printf("Precio Total: Q.%.2f", datosProductos.precioTotal);   
				cout<<"\n=====================================" <<endl <<endl;
			}
		}
	}
	
	ArchivoProductos.close();	
	ArchivoEmpleados.close();
}

//Error
//Reportes
//Ventas o facturación
void ventasFiltradoDia(){
	regProduct datosProductos;
	regEmp datosEmpleados;
	
	char diaB[3];
	char mesB[3];
	char anioB[5];
	char cajaB[2];
	bool bandera;
	char opcion;
	
	ifstream FiltradoArchivoVentasDia ("Productos.dat", ios::in | ios::binary);
	ifstream FiltradoArchivoVentasDiaEmpleados ("Empleados.dat", ios::in | ios::binary);
	
	if (!FiltradoArchivoVentasDia || !FiltradoArchivoVentasDiaEmpleados) {
		
		cerr<<"Error: ¡No se pudo abrir el archivo Productos.dat o Empleados.dat Porque puede ser que no exista alguno!";
	
		exit(1);

	} 
	else{
		do{
			system("cls");
			
			fflush(stdin);
			
    		bandera = false;
    
			cout<<"Ingrese el día: ";
			cin.getline(diaB, 3, '\n');
			cout<<"Ingrese el mes: ";
			cin.getline(mesB, 3, '\n');
			cout<<"Ingrese el año: ";
			cin.getline(anioB, 5, '\n');
			cout<<"Ingrese el No. de caja que tiene asignado: ";
			cin.getline(cajaB, 2, '\n');
			
			fflush(stdin);
			
			system("cls");
		
			cout<<"=====================================" <<endl;
			cout<<" Los datos filtrados por día, son: "<<endl;
			cout<<"=====================================" <<endl <<endl;
		
			cout<<"Fecha: " <<diaB <<"/" <<mesB	 <<"/" <<anioB <<endl;
		
			while(FiltradoArchivoVentasDia.read(reinterpret_cast<char *>(&datosProductos),sizeof(regProduct))  && FiltradoArchivoVentasDiaEmpleados.read(reinterpret_cast<char *>(&datosEmpleados),sizeof(regEmp))){	
				if( strcmp(datosProductos.dia,diaB) == 0 && strcmp(datosProductos.mes,mesB) == 0 && strcmp(datosProductos.anio,anioB) == 0 && strcmp(datosEmpleados.caja,cajaB) == 0){
					datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
					cout<<"No. de caja que tiene asignado: " <<datosEmpleados.caja <<endl;
					cout<<"Código: " <<datosProductos.codigo <<endl;
					cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
					cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
					cout<<"Descripción: " <<datosProductos.descripcion <<endl;
					cout<<"Precio: Q." <<datosProductos.precio <<endl;
					printf("Precio Total: Q.%.2f", datosProductos.precioTotal);
					cout<<"\n=====================================" <<endl <<endl;
				
					bandera=true; 		
				}
				else{
					if(strcmp(datosProductos.dia,diaB) == 0){
						cout<<"El día que busca, no existe\nInténtelo nuevamente" <<endl <<endl;
					
						break;
					}
				}
			};
			
			cout<<"¿Desea filtrar otros productos por día? (s= sí o n= no): ";
			cin>> opcion;
			
			if (opcion == 's' || opcion == 'S') {
				FiltradoArchivoVentasDia.clear();							//Con clear() se limpian los flags de estado para que seekg pueda funcionar
				FiltradoArchivoVentasDia.seekg(0, FiltradoArchivoVentasDia.beg);
				FiltradoArchivoVentasDiaEmpleados.clear();							//Con clear() se limpian los flags de estado para que seekg pueda funcionar
				FiltradoArchivoVentasDiaEmpleados.seekg(0, FiltradoArchivoVentasDia.beg);	//y pueda regresar a la posición inicial del archivo y hacer otra búsqueda
			}
			
		FiltradoArchivoVentasDia.close();
		FiltradoArchivoVentasDiaEmpleados.close();
	
		}while(opcion == 's' || opcion == 'S');
	}
}

void ventasFiltradoMes(){
	regProduct datosProductos;
	regEmp datosEmpleados;
	
	char diaB[3];
	char mesB[3];
	char anioB[5];
	char cajaB[2];
	bool bandera;
	char opcion;
	
	ifstream FiltradoArchivoVentasMes ("Productos.dat", ios::in | ios::binary);
	ifstream FiltradoArchivoVentasMesEmpleados ("Empleados.dat", ios::in | ios::binary);
	
	if (!FiltradoArchivoVentasMes || !FiltradoArchivoVentasMesEmpleados) {
		
	cerr<<"Error: !No se pudo abrir el archivo Productos.dat o Empleados.dat Porque puede ser que no exista alguno!";
	exit(1);

	} 
	else{
		do{
			system("cls");
			
			fflush(stdin);
			
    		bandera = false;
    
			cout<<"Ingrese el mes: ";
			cin.getline(mesB, 3, '\n');
			cout<<"Ingrese el año: ";
			cin.getline(anioB, 5, '\n');
			cout<<"Ingrese el No. de caja que tiene asignado: ";
			cin.getline(cajaB, 2, '\n');
	
			system("cls");
			
			cout<<"=====================================" <<endl;
			cout<<" Los datos filtrados por mes, son: "<<endl;
			cout<<"=====================================" <<endl <<endl;
		
			cout<<"Fecha: " <<mesB	 <<"/" <<anioB <<endl;
			cout<<"No. de caja que tiene asignado: " <<datosEmpleados.caja <<endl <<endl;
		
			while(FiltradoArchivoVentasMes.read(reinterpret_cast<char *>(&datosProductos),sizeof(regProduct)) && FiltradoArchivoVentasMesEmpleados.read(reinterpret_cast<char *>(&datosEmpleados),sizeof(regEmp))){	
				if( strcmp(datosProductos.mes,mesB)== 0 && strcmp(datosProductos.anio,anioB)== 0 && strcmp(datosEmpleados.caja, cajaB) == 0){
					datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
					cout<<"No. de caja que tiene asignado: " <<datosEmpleados.caja <<endl;
					cout<<"Código: " <<datosProductos.codigo <<endl;
					cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
					cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
					cout<<"Descripción: " <<datosProductos.descripcion <<endl;
					cout<<"Precio: Q." <<datosProductos.precio <<endl;
					printf("Precio Total: Q.%.2f", datosProductos.precioTotal);
					cout<<"\n=====================================" <<endl <<endl;
				
					bandera=true; 		
				}
				else{
					if(strcmp(datosProductos.mes,mesB) != 0){
						cout<<"El mes que busca, no existe\nInténtelo nuevamente" <<endl <<endl;
					
						break;
					}
				}
			
			};
			
			cout<<"¿Desea filtrar otros productos por día? (s= sí o n= no): ";
			cin>> opcion;
			
			if (opcion == 's' || opcion == 'S') {
				FiltradoArchivoVentasMes.clear();							//Con clear() se limpian los flags de estado para que seekg pueda funcionar
				FiltradoArchivoVentasMes.seekg(0, FiltradoArchivoVentasMes.beg);
				FiltradoArchivoVentasMesEmpleados.clear();							//Con clear() se limpian los flags de estado para que seekg pueda funcionar
				FiltradoArchivoVentasMesEmpleados.seekg(0, FiltradoArchivoVentasMesEmpleados.beg);	//y pueda regresar a la posición inicial del archivo y hacer otra búsqueda
			}
		}while(opcion == 's' || opcion == 'S');
	}
	
	FiltradoArchivoVentasMes.close();
	FiltradoArchivoVentasMesEmpleados.close();
}

//Formas de pago
void formasDePagoEfectivo(){
	regProduct datosProductos;
	
	char codigoM[16];
	int correlativo = 1;
	string realizarPago;
	float descuento;
	float precioTotalFinal;
	float descuentoBeneficio;
	float totalBeneficio;
	char opcion;
	bool bandera;
	
	ifstream ArchivoDeBusqueda("Productos.dat", ios::in | ios::binary);
	
	if(!ArchivoDeBusqueda){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Productos.dat, porque puede ser que no exista!" <<endl;
		
		exit(1);
	}
	else{
		do{
			system("cls");
			
			bandera = false;
			
			fflush(stdin);
			
			cout<<"============================" <<endl;
			cout<<"     Efectivo" <<endl;
			cout<<"============================" <<endl <<endl;
			cout<< "Ingrese el código del producto, del que desea cancelar el pago: "; 
			cin.getline(codigoM, 16, '\n');
			
			fflush(stdin);
			
			system("cls");
			
			cout<<"======================================" <<endl;
			cout<<"Los datos del producto buscado, son:" <<endl;
			cout<<"======================================" <<endl;
			
			while(ArchivoDeBusqueda.read(reinterpret_cast <char*>(&datosProductos), sizeof(regProduct))){
				if( strcmp(datosProductos.codigo, codigoM) == 0){
					datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
					
					system("cls");
			
					if(datosProductos.precioTotal >= 1000){
						descuento = datosProductos.precioTotal * 0.15;
						precioTotalFinal = datosProductos.precioTotal - descuento;
					
						cout<<"\t\tVenta con descuento" <<endl <<endl;
						cout<<"\nFecha de venta: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl;
						cout<<"Correlativo: " <<correlativo ++ <<endl;
						cout<<"Código: " <<datosProductos.codigo <<endl;
						cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
						cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
						cout<<"Descripción: " <<datosProductos.descripcion <<endl;
						cout<<"Precio: Q." <<datosProductos.precio <<endl;
						printf("Precio Total: Q.%.2f", datosProductos.precioTotal); 
						printf("\nPrecio Total Final: Q.%.2f", precioTotalFinal);
						printf("\nPrecio Total Final con descuento del pago en efectivo: Q.%.2f", totalBeneficio);   
						cout<<"\n=====================================" <<endl <<endl;  
						
						descuentoBeneficio = (datosProductos.precioTotal * 3) / 100;
						totalBeneficio = (datosProductos.precioTotal - descuentoBeneficio) - descuento;
							
						cout<<"Total a pagar, con beneficio de efectivo: Q." <<totalBeneficio <<endl <<endl;
						cout<<"¿Desea realizar su pago? (s= sí o n= no): ";
						cin>> realizarPago;
						
						if(realizarPago == "sí" || realizarPago == "SÍ" || realizarPago == "si" || realizarPago == "SI" || realizarPago == "s" || realizarPago == "S"){
						cout<<"\n\nPago efectuado con éxito" <<endl <<endl;
						}
						else{
							cout<<"\n\nPago no completado" <<endl <<endl;
						}
					}
					else{
						cout<<"\t\tVenta sin descuento" <<endl <<endl;
						cout<<"\nFecha de venta: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl;
						cout<<"Correlativo: " <<correlativo ++ <<endl;
						cout<<"Código: " <<datosProductos.codigo <<endl;
						cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
						cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
						cout<<"Descripción: " <<datosProductos.descripcion <<endl;
						cout<<"Precio: Q." <<datosProductos.precio <<endl;
						printf("Precio Total: Q.%.2f", datosProductos.precioTotal);
						printf("\nPrecio Total Final con descuento del pago en efectivo: Q.%.2f", totalBeneficio);      
						cout<<"\n=====================================" <<endl <<endl;
						
						descuentoBeneficio = (datosProductos.precioTotal * 3) / 100;
						totalBeneficio = datosProductos.precioTotal - descuentoBeneficio;
							
						cout<<"Total a pagar, con beneficio de efectivo: Q." <<totalBeneficio <<endl <<endl;
						cout<<"¿Desea realizar su pago? (s= sí o n= no): ";
						cin>> realizarPago;
						
						if(realizarPago == "sí" || realizarPago == "SÍ" || realizarPago == "si" || realizarPago == "SI" || realizarPago == "s" || realizarPago == "S"){
						cout<<"\n\nPago efectuado con éxito" <<endl <<endl;
						}
						else{
							cout<<"\n\nPago no completado" <<endl <<endl;
						}
					}			
				
					bandera = true; 
					
					break;
				}
			}
			
			if(bandera == false){
				system("cls");
				
				cout<<"Registro no encontrado" <<endl;
			}
			
			cout<<"¿Desea cancelar el pago de otro producto? (s = si o n = no): ";
			cin>> opcion;
			
			if(opcion == 's' || opcion == 'S'){
				ArchivoDeBusqueda.clear();
				
				//(0 saltos, ir al inicio)
				ArchivoDeBusqueda.seekg(0, ArchivoDeBusqueda.beg);
			}
		}while(opcion == 's' || opcion == 'S');
	}
	
	ArchivoDeBusqueda.close();
}

void formasDePagoTarjeta(){
	regProduct	datosProductos;
	
	char codigoM[16];
	string nombre;
	string numeroTarjeta;
	string cvv;
	char caracter;
	string realizarPago;
	char opcion;
	bool bandera;
	
	ifstream ArchivoDeBusqueda("Productos.dat", ios::in | ios::binary);
	
	if(!ArchivoDeBusqueda){
		system("cls");
		
		cerr<<"Error: ¡No se pudo abrir el archivo Productos.dat, porque puede ser que no exista!" <<endl;
		
		exit(1);
	}
	else{
		do{
			system("cls");
			
			bandera = false;
			
			fflush(stdin);
			
			cout<<"============================" <<endl;
			cout<<"Tarjeta de crédito o débito" <<endl;
			cout<<"============================" <<endl <<endl;
			cout<< "Ingrese el código del producto, del que desea cancelar el pago: "; 
			cin.getline(codigoM, 16, '\n');
			
			fflush(stdin);

			cout<<"Nombre de la tarjeta: ";
			getline(cin, nombre);
			cout<<"Número de la tarjeta: ";
			getline(cin, numeroTarjeta);
			cout << "CVV: ";
			
			//Entrada de caracter e ingreso de un caracter vacío
			caracter = getch();
					
			//Reseteo de datos ingresados en la variable cvv
			cvv = "";
		
			//Hasta que el usuario presione la tecla enter (13, que corresponde a dicha posición en el código ASCII), se cerrará el ciclo
			while (caracter != 13){
						
				//Eliminación de caracteres
				//Si el usuario presiona la tecla backspace (borrar. 8, que corresponde a dicha posición en el código ASCII)
				if (caracter != 8){
							
					//Muestra en pantalla, los asteriscos que se obtienen al ingresar cada uno de los caracteres de la variable caracter y almacena los caracteres en la variable contrasena
					cvv.push_back(caracter);
							cout << "*";
				
				} 
				else{
					//Contador de caraceres (.length())
					//Si el cvv ingresado, tiene de uno a más caracteres
					if (cvv.length() > 0){
								
						//Borrado de caracteres
						//Retrocede un espacio; deja ese espacio en blanco; y, como avanza un espacio, se retrocede a esa posición, en donde está el espacio en blanco
						cout << "\b \b";
								
						//Elimina el último caracter contenido en el cvv ingresada
						cvv = cvv.substr(0, cvv.length() - 1);
					}
				}
		
				caracter = getch();
			}
	
			system("cls");
			
			cout<<"======================================" <<endl;
			cout<<"Los datos del producto buscado, son:" <<endl;
			cout<<"======================================" <<endl;
			
			while(ArchivoDeBusqueda.read(reinterpret_cast <char*>(&datosProductos), sizeof(regProduct))){
				if( strcmp(datosProductos.codigo, codigoM) == 0){
					datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
					
					system("cls");
					
					cout<<"========================================" <<endl;
					cout<<"\tLos datos del producto buscado, son:" <<endl;
					cout<<"=======================================" <<endl;
					cout<<"Código: " <<datosProductos.codigo <<endl;
					cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
					cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
					cout<<"Descripción: " <<datosProductos.descripcion <<endl;
					cout<<"Precio: Q." <<datosProductos.precio <<endl;
					printf("Precio Neto: Q.%.2f", datosProductos.precioTotal);
					cout<<"\nFecha de venta: " <<datosProductos.dia <<"/" <<datosProductos.mes <<"/" <<datosProductos.anio <<endl; 
					cout<<"\n=====================================" <<endl <<endl;
					cout<<"¿Desea realizar su pago? (s= sí o n= no): ";
					cin>> realizarPago;
						
					if(realizarPago == "sí" || realizarPago == "SÍ" || realizarPago == "si" || realizarPago == "SI" || realizarPago == "s" || realizarPago == "S"){
						cout<<"\n\nPago efectuado con éxito" <<endl <<endl;
					}
					else{
						cout<<"\n\nPago no completado" <<endl <<endl;
					}			
				
					bandera = true; 
					
					break;
				}
			}
			
			if(bandera == false){
				system("cls");
				
				cout<<"Registro no encontrado" <<endl;
			}
			
			cout<<"¿Desea cancelar el pago de otro producto? (s = si o n = no): ";
			cin>> opcion;
			
			if(opcion == 's' || opcion == 'S'){
				ArchivoDeBusqueda.clear();
				
				//(0 saltos, ir al inicio)
				ArchivoDeBusqueda.seekg(0, ArchivoDeBusqueda.beg);
			}
		}while(opcion == 's' || opcion == 'S');
	}
	
	ArchivoDeBusqueda.close();				
}

//Etc
//Filtrado de ventas anual
void ventasFiltradoAnual(){
	regProduct datosProductos;
	regEmp datosEmpleados;
	
	char anioB[5];
	bool bandera;
	char opcion;
	
	ifstream FiltradoArchivoVentasAnual("Productos.dat", ios::in | ios::binary);
	
	if (!FiltradoArchivoVentasAnual) {
		
		cerr<<"Error: ¡No se pudo abrir el archivo Productos.dat. Porque puede ser que no exista!";
	
		exit(1);

	} 
	else{
		do{
			system("cls");
			
			fflush(stdin);
			
    		bandera = false;
    		
    		cout<<"Filtrado de ventas anual" <<endl <<endl;
    		cout<<"Ingrese el año: ";
			cin.getline(anioB, 5, '\n');
			
			fflush(stdin);
			
			system("cls");
		
			cout<<"=====================================" <<endl;
			cout<<" Los datos filtrados anualmente de los productos, son: "<<endl;
			cout<<"=====================================" <<endl <<endl;
		
			cout<<"Año: "  <<anioB <<endl <<endl;
		
			while(FiltradoArchivoVentasAnual.read(reinterpret_cast<char *>(&datosProductos),sizeof(regProduct))){	
				if( strcmp(datosProductos.anio,anioB)== 0 ){
					datosProductos.precioTotal = datosProductos.cantidad * datosProductos.precio;
					
					cout<<"Código: " <<datosProductos.codigo <<endl;
					cout<<"Clasificación: " <<datosProductos.clasificacion <<endl; 
					cout<<"Cantidad: " <<datosProductos.cantidad <<endl; 
					cout<<"Descripción: " <<datosProductos.descripcion <<endl;
					cout<<"Precio: Q." <<datosProductos.precio <<endl;
					printf("Precio Total: Q.%.2f", datosProductos.precioTotal);
					cout<<"\n=====================================" <<endl <<endl;
				
					bandera=true; 		
				}
				else{
					cout<<"El año que busca, no existe\nInténtelo nuevamente" <<endl <<endl;
					
					break;
				}
			
			};
			
			cout<<"¿Desea filtrar otro año? (s= sí o n= no): ";
			cin>> opcion;
			
			if (opcion == 's' || opcion == 'S') {
				FiltradoArchivoVentasAnual.clear();							//Con clear() se limpian los flags de estado para que seekg pueda funcionar
				FiltradoArchivoVentasAnual.seekg(0, FiltradoArchivoVentasAnual.beg);
			}
			
		FiltradoArchivoVentasAnual.close();
	
		}while(opcion == 's' || opcion == 'S');
	}
}
