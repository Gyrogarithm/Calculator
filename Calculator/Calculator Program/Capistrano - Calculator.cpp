#include <iostream>
#include <string>
using namespace std;


const int max_equations = 100;


int equation_count = 0;
char choice;
int flag = 0;
string number;
int temp;
struct eq {
    string equation; //Struct

};
eq* equation_pointers[max_equations]; //Declares an array of pointers to eq struct outside of eq struct




void add_equation(const string& equation) {
    eq* new_equation = new eq; // Allocates memory using new and creates new_equation
    new_equation->equation = equation; //Arrow is used to access the member of the structure through pointer
    equation_pointers[equation_count] = new_equation; //Stores in equation_pointers array
    equation_count++;
}

void display_equations() {
    system("CLS");
    cout << "\nEquations: " << endl << endl;
    for (int i = 0; i < equation_count; i++) {
        cout << equation_pointers[i]->equation << " --> "  << equation_pointers[i] << endl; //Displays all equations
    }
}

void display_equation(){
    system("CLS");
    cout << "Input the number of the previous equation you want to view (it starts from 1): " << endl;
    cin >> number;
    for(int i = 0; i < equation_count; i++){
        if (number == to_string(i + 1)) {
            cout << equation_pointers[i]->equation << " --> "  << equation_pointers[i] << endl; //Displays one equation and makes a true flag
            temp = 1;
            break;
        }
        else{
            temp = 0; //If equation cannot be found
        }

    }
    if (temp == 0){
        cout << "\nThe equation does not exist. Please try again.";
    }
    cout << endl;
}


void addition(int n1, int n2){
    int result = n1 + n2;
    string equation = to_string(n1) + " + " + to_string(n2) + " = " + to_string(result); //Turns a whole expression into a string
    cout << endl << equation << endl;
    add_equation(equation);
}


void subtraction(int n1, int n2){
    int result = n1 - n2;
    string equation = to_string(n1) + " - " + to_string(n2) + " = " + to_string(result);
    cout << endl << equation << endl;
    add_equation(equation);
}


void multiplication(int n1, int n2){
    int result = n1 * n2;
    string equation = to_string(n1) + " * " + to_string(n2) + " = " + to_string(result);
    cout << endl << equation << endl;
    add_equation(equation);
}


void division(float n1, float n2){
    if (n2 == 0){
        cout << "The result is undefined." << endl;
        string equation = to_string(n1) + " / " + to_string(n2) + " = UNDEFINED"; //Adds undefined as the result
        cout << endl << equation << endl;
        add_equation(equation);
    }
    else {
        float result = n1 / n2;
        string equation = to_string(n1) + " / " + to_string(n2) + " = " + to_string(result);
        cout << endl << equation << endl;
        add_equation(equation);
    }
}




int main(){
    char operation, again;
    double n1, n2;


    do{
        system("CLS");
        cout << "Welcome to Calculator!" << endl;
        cout << endl << endl;
        cout << "Please enter the expression to be calculated: \t\t" << endl << endl;
        while (!(cin >> n1 >> operation >> n2)){ //Error handling when expression is incorrect
        cin.clear();
        cout << "Expression inputted is incorrect. Please try again.\t\t" << endl << endl;
        while (cin.get() != '\n');
        }


        if (operation == '+'){
            addition(n1, n2);
        }
        else if (operation == '-'){
            subtraction(n1, n2);
        }
        else if (operation == '*' || operation == 'x'){
            multiplication(n1, n2);
        }
        else if (operation == '/'){
            division(n1, n2);
        }
        else {
            cout << "Operation is invalid! Please try again.\t\t" << endl << endl; //Error handling when operation is not correct
        }

        do {

        cout << "\nChoose an option from below:";
        cout << "\n\n1.) Display all equations\n2.) Display only one equation\n3.) What if I don't want to look at the equations?" << endl;
        cin >> choice;
        if (choice == '1'){
            display_equations();
        }
        else if (choice == '2'){
            display_equation();

        }

        else if (choice =='3'){
            system("CLS");
            cout << endl << "Would you like to continue evaluating equations? [Y/N]\t\t" << endl;
            cin >> again;
            while (!(again == 'y' || again == 'n' || again == 'Y' || again == 'N')){ //Error handling, not equal
                cout << "Invalid input. Please try again. [Y/N] \t\t";
                cin >> again;
            }
                flag = 1; //Flag to end the program
                cout << "\nThank you for using Calculator! See you next time!" << endl << endl;
        }


        else {
            cout << "Invalid choice. Please try again." << endl;
        }

        }while (choice == '1' || choice == '2' || flag == 0);





    }
    while (again == 'y' || again == 'Y');

    return 0;
}
