#include <string>
using namespace std;

#ifndef CREATE_H
#define CREATE_H

/* ••••• Declaración de clases ••••• */

class Parent { // Clase de la que heredamos los datos y funciones que se comparten
protected: // Datos protegidos para que se puedan heredar y vuelvan privados en las clases derivadas
  string name;
  int age;
	int id;

public:
// Funciones de set y get para acceder a los datos miembto
  void setName();
  void setAge();
  void setId();
	int getId();
	virtual void display() = 0; // Función virtual para desplegar toda la información del objeto, para que se adapte a los valores de cada clase heredada
	virtual void modify() = 0; // Función virtual para modificar la información del objeto, para que se adapte a los valores de cada clase heredada

	Parent(); // Constructor default ejecutado por el usuario cuando se crea un nuevo objeto
	Parent(string, int, int); // Constructor por default para crear varios objetos al principio de la ejecución
	~Parent(); // Destructor para ahorrar memoria cuando los objetos se dejen de usar
};

class Patient : public Parent { // Clase para los pacientes
	private:
    	string illness;
		string medication;
		string appointment;

	public:
    	void setIllness();
    	void setMedication();
    	void setRoomNumber();

		void display() override;
		void modify() override;

    	Patient();
		Patient(string, int, int, string, string);
		~Patient();
};

class Doctor : public Parent { // Clase para los doctores
  	private:
    	string specialty;

  	public:
    	void setSpecialty();

		void display() override;
		void modify() override;

    	Doctor();
		Doctor(string, int, int, string);
		~Doctor();
};


#endif