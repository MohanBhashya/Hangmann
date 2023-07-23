#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// User class to store user information
class User {
private:
    string username;
    string password;
public:
    User(string u, string p) {
        username = u;
        password = p;
    }
    string getUsername() {
        return username;
    }
    string getPassword() {
        return password;
    }
};

// Function to sign up a new user
User signup() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    return User(username, password);
}

// Function to log in an existing user
User login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    return User(username, password);
}

class BloodPressure {
private:
    int systolicPressure;
    int diastolicPressure;
public:
    BloodPressure(int sys, int dia) {
        systolicPressure = sys;
        diastolicPressure = dia;
    }
    void displayInfo() {
        cout << "Systolic Pressure: " << systolicPressure << endl;
        cout << "Diastolic Pressure: " << diastolicPressure << endl;
        if (systolicPressure < 90 || diastolicPressure < 60) {
            cout << "Low Blood Pressure" << endl;
        } else if (systolicPressure >= 90 && systolicPressure <= 120 && diastolicPressure >= 60 && diastolicPressure <= 80) {
            cout << "Normal Blood Pressure" << endl;
        } else if (systolicPressure > 120 && systolicPressure <= 130 && diastolicPressure > 80 && diastolicPressure <= 85) {
            cout << "Elevated Blood Pressure" << endl;
        } else if (systolicPressure > 130 && systolicPressure <= 140 && diastolicPressure > 85 && diastolicPressure <= 90) {
            cout << "Stage 1 Hypertension" << endl;
        } else if (systolicPressure > 140 && diastolicPressure > 90) {
            cout << "Stage 2 Hypertension" << endl;
        } else {
            cout << "Invalid Blood Pressure Values" << endl;
        }
    }
};

// Class to calculate BMI
class BodyMassIndex {
private:
    float height;
    float weight;
public:
    BodyMassIndex(float h, float w) {
        height = h;
        weight = w;
    }
    void displayInfo() {
        float bmi = weight / pow(height / 100, 2);
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "BMI: " << bmi << endl;
        if (bmi < 18.5) {
            cout << "Underweight" << endl;
        } else if (bmi >= 18.5 && bmi <= 24.9) {
            cout << "Normal Weight" << endl;
        } else if (bmi >= 25 && bmi <= 29.9) {
            cout << "Overweight" << endl;
        } else {
            cout << "Obese" << endl;
        }
    }
};

// Base class for Medicine
class Medicine {
protected:
    string name;
    int quantity;
    float price;
public:
    Medicine(string n, int q, float p) {
        name = n;
        quantity = q;
        price = p;
    }
    virtual void displayInfo() = 0; // pure virtual function
};

// Derived class for Tablet
class Tablet : public Medicine {
private:
    string dosageForm;
public:
    Tablet(string n, int q, float p, string df) : Medicine(n, q, p) {
        dosageForm = df;
    }
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Total Dosage:" << quantity << endl;
        cout << "Price of each medicine: " << price << endl;
        cout << "Medicine form: " << dosageForm << endl;
    }
};

// Derived class for Syrup
class Syrup : public Medicine {
private:
    string flavor;
public:
    Syrup(string n, int q, float p, string f) : Medicine(n, q, p) {
        flavor = f;
    }
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity <<"ml"<< endl;
        cout << "Price: " << price << endl;
        cout<<"Medicine Form: Syrup"<<endl;
        cout << "Flavor: " << flavor << endl;
    }
};

// Encapsulation: Class to get input from the user
class Symptom {
private:
    string symptom;
public:
    void getSymptom() {
        cout << "Enter your symptom: ";
        getline(cin, symptom);
    }
    string getSymptomValue() {
        return symptom;
    }
};

// Abstraction: Class to handle medicine information
class MedicineInfo {
private:
    Medicine* medicine;
public:
    void getMedicineInfo(Symptom* symptom) {
        string symptomValue = symptom->getSymptomValue();
        // Lookup medicine information based on symptomValue
        if (symptomValue == "fever") {
            medicine = new Tablet("Paracetamol", 9, 2.5, "Tablet");
        } else if (symptomValue == "cough") {
            medicine = new Syrup("Benadryl", 10, 3.0, "Menthol");
        } else if (symptomValue == "headache"||symptomValue == "headpain") {
            medicine = new Tablet("Ibuprofen", 1, 1.0, "Tablet");
        } else if (symptomValue == "nausea") {
            medicine = new Tablet("Ondansetron", 4, 2.0, "Tablet");
        } else if (symptomValue == "diarrhea") {
            medicine = new Tablet("Loperamide", 10, 1.5, "Tablet");
        } else if (symptomValue == "sore throat"||symptomValue == "throat pain") {
            medicine = new Syrup("Chloraseptic", 12, 3.5, "Cherry");
        } else if (symptomValue == "stomachache"||symptomValue == "stomachpain") {
            medicine = new Tablet("Pepto-Bismol", 20, 2.5, "Tablet");
        } else if (symptomValue == "vomiting"||symptomValue == "vomit") {
            medicine = new Tablet("Ondansetron", 4, 4.0, "Tablet");
        }else if (symptomValue == "acidity"||symptomValue == "gastric problem") {
            medicine = new Tablet("gelusil", 1, 2.0, "Tablet");
        } else if (symptomValue == "tiredness") {
            medicine = new Tablet("Caffeine", 2, 1.0, "Tablet");
        }else if (symptomValue == "toothache") {
            medicine = new Tablet("Acetaminophen", 5, 2.0, "Tablet");
        } else if (symptomValue == "earpain") {
            medicine = new Syrup("EarDrops", 8, 5.5, "Menthol");
        } else if (symptomValue == "back pain") {
            medicine = new Tablet("Naproxen", 20, 3.0, "Tablet");
        } else if (symptomValue == "muscle pain") {
            medicine = new Tablet("Tylenol", 8, 1.5, "Tablet");
        } else if (symptomValue == "joint pain") {
            medicine = new Syrup("JointFlex", 10, 4.0, "Mint");
        } else if (symptomValue == "skin rash") {
            medicine = new Tablet("Allegra", 14, 2.5, "Tablet");
        } else if (symptomValue == "hives") {
            medicine = new Syrup("Benadryl", 8, 3.0, "Cherry");
        } else if (symptomValue == "cold") {
            medicine = new Tablet("Advil", 7, 2.0, "Tablet");
        } else {
            medicine = new Tablet("Aspirin", 30, 1.5, "Tablet");
        }
    }
    void displayMedicineInfo() {
        medicine->displayInfo();
    }
};

// Function to check if a disease is severe or mild
bool isDiseaseSevere(int numSymptoms) {
    if (numSymptoms > 5) {
        return true;
    } else {
        return false;
    }
}

// Function to display instructions for severe diseases
void displaySevereDiseaseInstructions() {
    cout << "Your disease is severe. Please consult a doctor immediately and call for an ambulance if necessary." << endl;
}

// Function to handle a single symptom
void handleSymptom(int symptomNum) {
    Symptom symptom;
    symptom.getSymptom();

    MedicineInfo medicineInfo;
    medicineInfo.getMedicineInfo(&symptom);

    cout << "Solution for symptom " << symptomNum << ":" << endl;
    medicineInfo.displayMedicineInfo();
}

int main() {
    // Get number of symptoms
    int choice;
    int systolicPressure, diastolicPressure;
    float height, weight;
    int numSymptoms;
    User currentUser("guest", ""); // initialize currentUser as a guest user with empty password

    cout << "Welcome to the program!" << endl;
    bool a=true;
    while (a) {
        cout << "1. Sign up" << endl;
        cout << "2. Log in" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                currentUser = signup();
                cout << "Sign up successful!" << endl;
                break;
            case 2:
                if (currentUser.getUsername() == "guest") {
                    cout << "You need to sign up first!" << endl;
                } else {
                    User inputUser = login();
                    if (inputUser.getUsername() == currentUser.getUsername() && inputUser.getPassword() == currentUser.getPassword()) {
                        cout << "Login successful!" << endl;
                        a=false;
                    } else {
                        cout << "Incorrect username or password!" << endl;
                    }
                }
                break;
            case 3:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }
    cout << "Enter Systolic Pressure: ";
    cin >> systolicPressure;
    cout << "Enter Diastolic Pressure: ";
    cin >> diastolicPressure;
    BloodPressure bp(systolicPressure, diastolicPressure);
    cout << "Blood Pressure:" << endl;
    bp.displayInfo();

    cout << "Enter Height (in cm): ";
    cin >> height;
    cout << "Enter Weight (in kg): ";
    cin >> weight;
    BodyMassIndex bmi(height, weight);
    cout << "Body Mass Index:" << endl;
    bmi.displayInfo();

    cout << "Enter the number of symptoms: ";
    cin >> numSymptoms;
   
// Consume remaining newline character from input stream
cin.ignore();

// Check if disease is severe or mild
bool isSevere = isDiseaseSevere(numSymptoms);
if (isSevere) {
    displaySevereDiseaseInstructions();
} else {
    
    for (int i = 1; i <= numSymptoms; i++) {
        handleSymptom(i);
    }
    cout<<"Get well soon.Wishing you a speedy Recovery!!!"<<endl;
    cout<<"If the symptoms still persists,consult the Doctor";
}
return 0;
}
