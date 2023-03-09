// Ricardo Nieblas, Rodrigo Cortez, Katherin Ramirez, Vivien Frias
// 03 de Junio del 2022
// VIRK HOSPITAL

#include <iostream>
#include <array>

#include "hospital.h"

using namespace std;

/* ••••• Declaración de variables ••••• */

int tempInput; // Variable para uso general de input
int menuSelect; // Variable para la selección de menús
bool userFound; // Variable para revisar si el usuario se ha encontrado

// Arreglos que se utilizan en la opcion 3 del menú.
array <string, 10> article = {
	"Ibuprofen",
	"Arcoxia",
	"Penicilin",
	"Paracetamol",
	"Gloves",
	"Omeprazole",
	"Facemasks",
	"Aspirin",
	"Syringes",
	"Alcohol",
};
array <int, 10> expireage = { 2023, 2024, 2025, 2024, 2025, 2026, 2024, 2023, 2025, 2028};
array <int, 10> quantity = { 150, 100, 8, 10, 99, 40, 200, 50, 390, 70};

/* ••••• Declaración de clases ••••• */

class Appt { // class to set appointments
	private:
		string patName;
		string doctor;
		string time;
		string docList[4] = {"Dr.Katherin", "Dr.Rodrigo", "Dr.Ricardo", "Dr.Vivien"};
    	int matri[4] = {34300, 34700,34735,35399};
    	string special[4] = {"Family Medicine", "Toxicology", "Neurologist", "Pediatrics"};
		string schedule[5] = {"13:00", "14:00", "15:00", "16:00", "17:00"};

	public:
		Appt() { cout << "\n\n     Registering an appointment..." << endl; }
		void chooseDoc();
		void setTime();
		void displayAppt();

};

// Clase para opcion 1.
class Doctor1 {
	public:
		int ageD;
		string nameD;
		string specialty;
		int matri;
		void getDataD();
		void showDataD();
		
		//Static
		static int size;

		Doctor1(string nameD = "", int ageD = 0, int matri = 0, string specialty = ""){
			this -> nameD = nameD;
    		this -> ageD = ageD;
    		this -> matri = matri;
    		this -> specialty = specialty;
  		}
};
// Declarar valor
int Doctor1:: size = 4;

class DisplayDoc: public Doctor1{
public:
  void display();
  void insert(Doctor1);
};

//Clase para la opcion 1.
class Patient1{
public:
  int ageP;
  int matriP;
  string nameP;
  string illness;
  string prescription;
  void getDataP();
  void showDataP();

  //Static
  static int sizeP;

  Patient1(string nameP = "", int ageP = 0, int matriP = 0, string illness = "", string prescription = ""){
    this -> nameP = nameP;
    this -> ageP = ageP;
    this -> matriP = matriP;
    this -> illness = illness;
    this -> prescription = prescription;
  }
};
int Patient1:: sizeP = 4; // Declarar valor

class DisplayPat: public Patient1{
public:
  void display();
  void insert(Patient1);
};

/* ••••• Declaración de objetos ••••• */

Patient patients[] = { // Se crean dentro de un arreglo para facilitar las funciones de búsqueda
  Patient("Derek", 19, 34015, "Depression", "Antidepressant"),
	Patient("Jorge Cerda", 19, 34628, "AIDS", "Hope"),
	Patient("Luis Garcia", 19, 34991, "Stomachache", "Genoprazole")
};

Patient1 Patients[100] = { // Se crean dentro de un arreglo para facilitar las funciones de búsqueda
  Patient1("Derek", 19, 34015, "Depression", "Antidepressant"),
	Patient1("Jorge Cerda", 19, 34628, "AIDS", "Hope"),
	Patient1("Luis Garcia", 19, 34991, "Stomachache", "Genoprazole"),
  Patient1("Joel Vizcarra", 11, 1235, "Cabeza", "Nueva cabeza")
};

Doctor doctor[4] = {
	Doctor("Katherin Ramirez", 20, 34300, "Family Medicine"),
	Doctor("Rodrigo Cortez", 53, 34700, "Toxicology"),
	Doctor("Ricardo Nieblas", 20, 34735, "Neurologist"),
	Doctor("Vivien Frias", 19, 35399, "Pediatrics"),
};

Doctor1 doct[100] = {
	Doctor1("Katherin Ramirez", 20, 34300, "Family Medicine"),
	Doctor1("Rodrigo Cortez", 53, 34700, "Toxicology"),
	Doctor1("Ricardo Nieblas", 20, 34735, "Neurologist"),
	Doctor1("Vivien Frias", 19, 35399, "Pediatrics"),
};

/* ••••• Funciones de clases ••••• */

//non-line funcs for class Apt
void Appt::displayAppt() { cout << endl<< "Your appointment is today with " << doctor << " at "<< time; }

void Appt::setTime() {
  int tempTime;
  bool on = true;
    cout << "\n     Available times for " << doctor << " are "<< endl;
	for(int i = 0; i<5;i++) {
		cout << i+1<< ") "<< schedule[i] << endl;       
	}
  while(on ==true){
	cout << "Please enter the time you would like to set your appointment: "; cin >> tempTime;
  switch(tempTime){
    case 1: time = "13:00"; on = false;break;
    case 2: time = "14:00"; on = false;break;
    case 3: time = "15:00"; on = false;break;
    case 4: time = "16:00"; on = false;break;
    case 5: time = "17:00"; on = false;break;
    default: cout << "Invalid input, please try again" << endl; continue;
    }
    on = false;}
}

void Appt::chooseDoc() {
	bool on = true;
	int drID = 0;
	cout << "\n     Available Doctors:\n" << endl;
	for(int i = 0; i<4;i++){
		cout << "     • " << docList[i] << " (" << special[i] << ", ID: " << matri[i]<< ")" << endl;
	}
	while (on == true) {
    	cout << "\n     Please enter the doctor's ID to set your appointment with: "; cin >> drID;
    // aqui tambien
    switch(drID){
      case 34300: doctor = "Dr.Katherin"; on = false; break; 
      case 34700: doctor = "Dr.Rodrigo"; on = false; break;
      case 34735: doctor = "Dr.Ricardo"; on = false; break;
      case 35399: doctor = "Dr.Vivien"; on = false;break;
      default: cout <<"\n     Invalid input, please try again"<< endl; continue;
    }
}
}

// Funcion get de la opc1.
void Doctor1::getDataD(){
  cout << "\n...NEW DOCTOR..." << endl;
  cout << "\nName of the new doctor: ";
  cin >> nameD;
  cout << "\nID number: ";
  cin >> matri;
  //cin.ignore();
  cout << "\nAge of the new doctor: ";
  cin >> ageD;
  cout << "\nSpecialty: ";
  cin >> specialty;
}

// Funcion get de la opc1.
void Patient1::getDataP(){
  cout << "\n...NEW PATIENT..." << endl;
  cout << "\nName of the new patient: ";
  cin >> nameP;
  cout << "\nAge of the new patient: ";
  cin >> ageP;
  cout << "\nID of the new patient: ";
  cin >> matriP;
  cout << "\nIllness: ";
  cin >> illness;
  cout << "\nPrescription: ";
  cin >> prescription;
}

// Función display de clase Doctor1
void DisplayDoc::display() {
  cout << "\n...DATA INFORMATION...";
  for(int i = 0; i < size; i++){
    if(doct[i].nameD != " ")
    {
      cout << "\nObjeto no. " << i + 1 
      << "\n • Doctor's name: " << doct[i].nameD 
      << "\n • Age: " << doct[i].ageD 
      << "\n • ID: " << doct[i].matri
      << "\n • Specialty: " << doct[i].specialty << "\n" << endl;
    }
  }
}
// Agrega un nuevo elemento en lista doct.
void DisplayDoc :: insert(Doctor1 doc){
  doct[size] = {doc};
  Doctor1::size = Doctor1::size + 1;
}
// Función display de la clase Patient1
void DisplayPat::display() {
  cout << "\n...DATA INFORMATION...";
  for(int i = 0; i < sizeP; i++){
    if(Patients[i].nameP != " ")
    {
      cout << "\nObjeto no. " << i + 1 
      << "\n • Patient's name: " << Patients[i].nameP 
      << "\n • Age: " << Patients[i].ageP
      << "\n • ID: " << Patients[i].matriP
      << "\n • Illness: " << Patients[i].illness
      << "\n • Prescription: " << Patients[i].prescription << "\n" << endl;
    }
  }
}

// Agrega un nuevo elemento en lista Patients.
void DisplayPat :: insert(Patient1 pat){
  Patients[sizeP] = {pat};
  Patient1::sizeP = Patient1::sizeP + 1;
}

/* ••••• Declaración de funciones generales ••••• */

// Funciones declaradas antes de startMenu() para que se identifiquen las mismas al ejecutar el código
void option1(), option2(), option3(), option4(), option5();

// Título de nuestro proyecto en estilo ASCII
void hospitalLogo() {
	cout << " __     _____ ____  _  __  _   _                 _ _        _  " << endl;
	cout << " \\ \\   / /_ _|  _ \\| |/ / | | | | ___  ___ _ __ (_) |_ __ _| | " << endl;
	cout << "  \\ \\ / / | || |_) | ' /  | |_| |/ _ \\/ __| '_ \\| | __/ _` | | " << endl;
	cout << "   \\ V /  | ||  _ <| . \\  |  _  | (_) \\__ \\ |_) | | || (_| | | " << endl;
	cout << "    \\_/  |___|_| \\_\\_|\\_\\ |_| |_|\\___/|___/ .__/|_|\\__\\__,_|_| " << endl;
    cout << "                                          |_|                  ";
}

// Función para desplegar el menú principal
void startMenu(int x = 0) { // Función para desplegar el menú principal
	hospitalLogo();
	if (x == 1) { cout << "\nInvalid answer, please try again..."; }
  	cout << "\n\n     1) Add a user\n";
  	cout << "\n     2) Consult user information\n";
  	cout << "\n     3) Check medicine inventory\n";
  	cout << "\n     4) Modify a user's info\n";
  	cout << "\n     5) Register an appointment\n";
  	cout << "\n     6) Exit the program\n";
  	cout << "\n\n     Please select an option: "; 
    cin >> menuSelect;

	switch (menuSelect) {
		case 1: system("clear"); option1(); break;
		case 2: system("clear"); option2(); break;
    	case 3: system("clear"); option3(); break;
		case 4: system("clear"); option4(); break;
		case 5: system("clear"); option5(); break;
		case 6: cout << "\n\n     Exiting the program...\n" << endl;
		default: break;
	}
}

// Opción 1 - Agregar un usuario
void option1() {
	hospitalLogo();
	
	cout << "\n\n     Adding a user...\n";
	cout << "\n     1) Create a patient profile\n";
	cout << "\n     2) Create a doctor profile\n";
	cout << "\n\n     Please select an option: "; cin >> tempInput;
  Patient1 obj;
  DisplayPat obj2;
  Doctor1 obj3;
  DisplayDoc obj4;
  string answer;
  while(answer != "NO"){
   switch (tempInput) {
		case 1: 
      obj.getDataP();
      obj2.insert(obj);
      obj2.display();
      cout << "\n¿Desea agregar otro paciente? ";
      cin >> answer;
      
      break;
		case 2: 
      obj3.getDataD();
      obj4.insert(obj3);
      obj4.display();
      cout << "\n¿Desea agregar otro doctor? ";
      cin >> answer;
      
      break;
		default: break;
	}
    system("clear");
    startMenu();
  }
}

// Opción 2 - Consultar información del usuario
void option2() {
	hospitalLogo();

	// Toma el valor del ID y realiza una búsqueda con los pacientes, si encuentra un usuario con ese ID, despliega toda la información, pero si no lo encuentra, realiza la misma búsqueda en el arreglo de los doctores
	cout << "\n\n     Consulting user information...\n";
  	cout << "\n     Please enter user ID: "; cin >> tempInput; userFound = false; // QUITE EL INPUT AQUI PORQUE POR ESO NO AGARRABA.
	for (int i = 0; i < sizeof(patients)/sizeof(patients[0]); i++) {
    	if (tempInput == patients[i].getId()) {
			cout << "\n     A patient was found!" << endl;
			patients[i].display(); userFound = true;
		}
  	}
	for (int i = 0; i < sizeof(doctor)/sizeof(doctor[0]); i++) {
	    if (tempInput == doctor[i].getId()) {
			cout << "\n     A doctor was found!" << endl;
			doctor[i].display(); userFound = true;
		}
  	}
	if (userFound == false) { cout << "\n     Sorry, it seems no users contain this ID."; }
	
	// Menú con opciones para seguir buscando o para volver al menú principal
	cout << "\n\n\n     1) Search again\n";
	cout << "\n     2) Go back to main menu\n";
	cout << "\n\n     Please select an option: "; cin >> menuSelect;
	switch (menuSelect) {
		case 1: system("clear"); option2(); break;
		case 2: system("clear"); startMenu(); break;
		default: break;
	}
}

// Opción 3 - Manejar inventario de medicinas
void option3() {
	hospitalLogo();
	
	cout << "\n\n     Managing medicine inventory...\n";
	cout << "\n     - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "\n     Article # " << i + 1 << ": " << article[i] << " (" << quantity[i] << " left)" << endl;
		cout << "\n     Expiration Date: " << expireage[i] << endl;
		cout << "\n     - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	}
	
	cout << "\n     Enter the article number: "; cin >> menuSelect; menuSelect--;
	if (menuSelect >= 0 && menuSelect <= 9) {
		cout << "\n     Enter the desired quantity: "; cin >> tempInput;
		// Se revisa que la cantidad este dentro del rango
		if (tempInput > quantity[menuSelect]) {
			cout << "\n     There is not enough items in the inventory" << endl;
		} else {
			// Y se resta la cantidad en el arreglo
			quantity[menuSelect] = quantity[menuSelect] - tempInput;
			// Solo se imprime que el cambio se realiza con exito.
			cout << "\n     Item successfully modified!";
		}
	} else {
		// Caso contrario, imprimimos que no es un artículo válido
		cout << "\n     Article number invalid.";
	}
	
	cout << "\n\n\n     1) Modify another article\n";
	cout << "\n     2) Go back to main menu\n";
	cout << "\n\n     Please select an option: "; cin >> tempInput;
  // aqui tambien le quite el input
	switch (tempInput) {
		case 1: system("clear"); option3(); break;
		case 2: system("clear"); startMenu(); break;
	}
}

// Opción 4 - Modificar la información de un usuario
void option4() {
	hospitalLogo();

	// Toma el valor del ID y realiza una búsqueda con los pacientes, si encuentra un usuario con ese ID, despliega toda la información disponible para modificar
	cout << "\n\n     Modifying a user's info\n";
	cout << "\n     Please enter user ID: "; cin >> tempInput; userFound = false; //aqui igual
	
	for (int i = 0; i < sizeof(patients)/sizeof(patients[0]); i++) {
    	if (patients[i].getId() == tempInput) patients[i].modify(); userFound = true;
  	}
	for (int i = 0; i < sizeof(doctor)/sizeof(doctor[0]); i++) {
    	if (doctor[i].getId() == tempInput) doctor[i].modify(); userFound = true;
  	}
	if (userFound == false) { cout << "\n     Sorry, it seems no users contain this ID."; }

	// Menú con opciones para seguir modificando datos o para volver al menú principal
	cout << "\n\n\n     1) Modify data again\n";
	cout << "\n     2) Go back to main menu\n";
	cout << "\n\n     Please select an option: "; cin >> menuSelect;
	switch (menuSelect) {
		case 1: system("clear"); option4(); break;
		case 2: system("clear"); startMenu(); break;
		default: break;
	}
}

// Opción 5 - Agendar una cita
void option5() {
	hospitalLogo();
	
	Appt appt;
	appt.chooseDoc();
	appt.setTime();
	appt.displayAppt();
	
	cout << "\n\n     1) Register another appointment";
	cout << "\n     2) Go back to main menu\n";
	cout << "\n\n     Please select an option: "; cin >> menuSelect;
	switch (menuSelect) {
		case 1: system("clear"); option5(); break;
		case 2: system("clear"); startMenu(); break;
		default: break;
	}	
}

/* ••••• Main Section ••••• */

int main() {
	system("clear");
	startMenu();
	
	return 0;
}