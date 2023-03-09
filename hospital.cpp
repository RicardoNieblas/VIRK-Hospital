#include <iostream>
#include "hospital.h"
using namespace std;

/* ••••• Declaración de variables ••••• */

int classInput; // Variable para uso general de input

/* ••••• Constructores y destructores para las clases ••••• */

Parent::Parent() {
	cout << "\nCreating a parent user...\n";
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
	cout << "ID: "; cin >> id;
}
Parent::Parent(string a, int b, int c) : name(a), age(b), id(c) {}
Parent::~Parent() {}

Patient::Patient() {
	cout << "\nCreating a patient...\n";
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
	cout << "ID: "; cin >> id;
	cout << "Illness: "; cin >> illness;
	cout << "Medication: "; cin >> medication;
}
Patient::Patient(string a, int b, int c, string d, string e) : Parent(a, b, c), illness(d), medication(e) {}
Patient::~Patient() {}

Doctor::Doctor() {
	cout << "\nCreating a doctor...\n";
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
	cout << "ID: "; cin >> id;
	cout << "Specialty: "; cin >> specialty;
}
Doctor::Doctor(string a, int b, int c, string d) : Parent(a, b, c), specialty(d) {}
Doctor::~Doctor() {}


/* ••••• Funciones de clases ••••• */

// Funciones set y get
void Parent::setName() { cout << "\n     Type the name of the user: "; cin >> name; }
void Parent::setAge() { cout << "\n     Type the age of the user: "; cin >> age; }
void Parent::setId() { cout << "\n     Type the ID of the user: "; cin >> id; }
int Parent::getId() { return id; }

void Patient::setIllness() { cout << "\n     Type the illness of the patient: "; cin >> illness; }
void Patient::setMedication() { cout << "\n     Type the current medication of the user: "; cin >> medication; }

void Doctor::setSpecialty() { cout << "\n     Type the specialty of the doctor: "; cin >> specialty; }

// Funciones display
void Patient::display() {
	cout << "\n     • Patient's name: " << name << endl;
	cout << "     • Age: " << age << endl;
	cout << "     • ID: " << id << endl;
	cout << "     • Illness: " << illness << endl;
	cout << "     • Medication: " << medication << endl;
}
void Doctor::display() {
  	cout << "\n     • Doctor's name: " << name << endl;
  	cout << "     • Age: " << age << endl;
  	cout << "     • ID: " << id << endl;
  	cout << "     • Specialty: " << specialty << endl;
}

// Funciones modify
void Patient::modify() {
	// Se muestran todas las opciones para modificar
	cout << "\n\n     1) Name";
	cout << "\n     2) Age";
	cout << "\n     3) ID";
	cout << "\n     4) Illness";
	cout << "\n     5) Medication";
	// Se almacena la respuesta en una variable
	cout << "\n\n     Please select the option you want to modify: "; cin >> classInput;

	// Se llama a la función modificadora correspondiente dependiendo de la elección que el usuario haya hecho
	switch (classInput) {
		case 1: setName(); break;
		case 2: setAge(); break;
		case 3: setId(); break;
		case 4: setIllness(); break;
		case 5: setMedication(); break;
		default: break;
	}

// Se confirman los cambios y se muestra la información de nuevo
	cout << "\n     Patient info has been modified!\n"; display();
}
void Doctor::modify() {
	cout << "\n     Modifying info for Dr. " << name << "...";
	cout << "\n\n     1) Name";
	cout << "\n     2) Age";
	cout << "\n     3) ID";
	cout << "\n     4) Specialty";
	cout << "\n\n     Please select the option you want to modify: "; cin >> classInput;

	switch (classInput) {
		case 1: setName(); break;
		case 2: setAge(); break;
		case 3: setId(); break;
		case 4: setSpecialty(); break;
	}

	cout << "\n     Doctor info has been modified!\n"; display();
}