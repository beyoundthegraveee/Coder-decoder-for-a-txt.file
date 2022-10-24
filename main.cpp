#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>


using namespace std;



string encrypt(string input) {
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int a;

    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                a = 1;
                word[i] = alphabet[(j + a) % 26];

                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}

string decrypt(string input) {
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int a;
    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                a = 1;
                word[i] = alphabet[(j - a) % 26];
                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}



char * passwordGenerator(){
    int N = 2000;
    char str[] { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+,-./|\\\"':;<=>?@[]^_`{}~" };
    int strN = 94;
    srand(time(NULL));
    char* pass = new char[N + 1];
    for (int i = 0; i < N; i++)
    {
        pass[i] = str[rand() % strN];
    }
    pass[N] = 0;
    return pass;
};


void login(){
    char ch;
    string str;
    cout << "ENTER THE FILE NAME OR PATH TO FILE:\n";
    char buff[50];
    cin >> buff;
    ifstream fin;
    fin.open(buff, fstream::in);
    if (!fin.is_open()) {
        cout << "WRONG FILE NAME.\n";
        exit(0);
    } else {
        cout << "ENTER THE PASSWORD:\n";
        string text;
        string decryptext;
        cin >> text;
        if (text == "project") {
            cout <<"\n______THE___BEGINNING______\n"<<endl;
            while (!fin.eof()) {
                str = "";
                getline(fin, str);
                decryptext = decrypt(str);
                cout<< decryptext <<endl;
            }
            cout<<"\n______THE___END______\n"<<"\nLogged in Succesfully!\n" <<endl;
        }else{
            cout<<"WRONG PASSWORD!"<<endl;
            while (!fin.eof()) {
                str = "";
                getline(fin, str);
                cout << str << endl;
            }
            fin.close();
            exit(0);

        }
    }
    fin.close();

}



    void file_exit() {
        cout << "Exit?" << endl;
        cout << "[1]Yes." << endl;
        cout << "[2]No." << endl;
        int q;
        cin >> q;
        if (q == 1) {
            exit(0);
        } else {
            if (q == 2) {
            } else {
                cout << "You can choose only 2 options" << endl;

            }

        }
    }


    void view_file() {
        fstream fin;
        string str;
        fin.open("text.txt", fstream::in);
        if (!fin.is_open()) {
            cout << "Something went wrong...\n";
        } else {
            cout <<"\n______THE___BEGINNING______\n"<<endl;
            while (!fin.eof()) {
                str = "";
                getline(fin, str);
                string textdecrypt = decrypt(str);
                cout << textdecrypt << endl;

            }
            cout<<"\n______THE___END______\n"<<endl;
        }

    }

    void edit_password() {
        ifstream fin;
        fin.open("text.txt");
        string str, password, line;
        ofstream fon;
        int b = 1;
        fon.open("temp.txt");
        cout << "ENTER THE PASSWORD TO EDIT: ";
        cin >> password;
        cout << "\n[1] To generate new password.\n[2] To make your own" << endl;
        cin >> b;
        if (b == 1) {
            while (!fin.eof()) {
                getline(fin, str);
                if (str != encrypt("Password-" + password)) {
                    fon << str << endl;
                } else{
                    cout<<"This password does not exist"<<endl;
                }
            }
            remove("text.txt");
            rename("temp.txt", "text.txt");
            int N = 12;
            char str[]{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
            int strN = 62;
            srand(time(NULL));
            char *pass = new char[N + 1];
            for (int i = 0; i < N; i++) {
                pass[i] = str[rand() % strN];
            }
            cout << "Your new password is:" << pass << endl;
            encrypt(pass);
            fon.open("text.txt", ofstream::app);
            fon << pass << endl;


            }
        }



void  edit_category(){


}

void view_logs(){

}



    void password_by_category() {


        cout << "Write your category" << endl;
        string sum;
        cin >> sum;
        string str;
        string str2;
        fstream fin;
        fin.open("text.txt", fstream::in);
        if (!fin) {
            cout << "Something went wrong" << endl;
        } else {
            while (!fin.eof()) {
                    getline(fin, str);
                    if (str.find(encrypt("Category-" + sum)) != std::string::npos) {
                        cout << "[1]" << decrypt(str) << endl;
                    }
                    getline(fin, str2);
                    if (str2.find(encrypt("Password-")) != std::string::npos) {
                        cout << "[2]" << decrypt(str2) << endl;
                    }
            }
            fin.close();
        }
    }


    void delete_password() {

        ifstream fin;
        fin.open("text.txt");
        string str, password, line;
        ofstream fon;
        fon.open("temp.txt");
        cout << "ENTER THE PASSWORD TO DELETE: ";
        cin >> password;
        while (!fin.eof()) {
            getline(fin, str);
            if (str!= encrypt("Password-" + password)) {
                        fon << str << endl;
                    }
                }
        cout<<"Deleted " + password<<endl;
        fin.close();
        fon.close();
        remove("text.txt");
        rename("temp.txt", "text.txt");

    }

   void delete_category(){
       ifstream fin;
       fin.open("text.txt");
       string str, cat, line;
       ofstream fon;
       fon.open("temp.txt");
       cout << "ENTER THE CATEGORY TO DELETE: ";
       cin >> cat;
       while (!fin.eof()) {
           getline(fin, str);
           if (str!= encrypt("Category-" + cat)) {
               fon << str << endl;
           }
       }
       cout<<"Deleted " + cat<<endl;
       fin.close();
       fon.close();
       remove("text.txt");
       rename("temp.txt", "text.txt");

}

    static void insert_data() {

        string textencypt;
        string textencypt1;
        string textencypt2;
        string textencypt3;
        string textencypt4;
        string textencypt5;
        string textencypt6;
        string textencypt7;
        cout << "Write category" << endl;
        char cat[50];
        cin >> cat;
        cout << "Write the name of service" << endl;
        char serv[50];
        cin >> serv;
        cout << "[1] To generate new password.\n[2] To make your own" << endl;
        int b;
        cin >> b;
        ofstream fout;
        if (b == 1) {
            int N = 12;
            char str[]{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
            int strN = 62;
            srand(time(NULL));
            char *pass = new char[N + 1];
            for (int i = 0; i < N; i++) {
                pass[i] = str[rand() % strN];
            }
            pass[N] = 0;

            fout.open("text.txt", ofstream::app);
            cout << "Your data is: " << "Category-" << cat << ", " << "Service-" << serv << ", " << "Password-"
                 << pass
                 << endl;

            if (!fout.is_open()) {
                cout << "Something went wrong...";
            } else {
                string text = "DATA: ";
                string text1 = "Category-";
                string text2 = "Service-";
                string text3 = "Password-";
                textencypt = encrypt(text);
                textencypt4 = encrypt(text1);
                textencypt5 = encrypt(text2);
                textencypt6 = encrypt(text3);
                textencypt1 = encrypt(cat);
                textencypt2 = encrypt(serv);
                textencypt3 = encrypt(pass);
                fout << textencypt << endl;
                fout << textencypt4 << textencypt1 << endl;
                fout << textencypt5 << textencypt2 << endl;
                fout << textencypt6 << textencypt3 << endl;
                fout << "\n";
            }


        } else {
            if (b == 2) {
                cout << "Write your password here:" << endl;
                char g[50];
                cin >> g;
                fout.open("text.txt", ofstream::app);
                cout << "Your data is: " << "Category-" << cat << ", " << "Service-" << serv << ", " << "Password-"
                     << g << endl;
                if (!fout.is_open()) {
                    cout << "Something went wrong...";
                } else {
                    string text = "DATA: ";
                    string text1 = "Category-";
                    string text2 = "Service-";
                    string text3 = "Password-";
                    textencypt = encrypt(text);
                    textencypt4 = encrypt(text1);
                    textencypt5 = encrypt(text2);
                    textencypt6 = encrypt(text3);
                    textencypt1 = encrypt(cat);
                    textencypt2 = encrypt(serv);
                    textencypt3 = encrypt(g);
                    fout << textencypt << endl;
                    fout << textencypt4 << textencypt1 << endl;
                    fout << textencypt5 << textencypt2 << endl;
                    fout << textencypt6 << textencypt3 << endl;
                    fout << "\n";
                }

            } else {
                cout << "You can choose only 2 options" << endl;
            }
        }
    }





    int main() {
        string choice;
        string password;
        login();
        while(true) {
            cout << "Choose your option :\n" << endl;
            cout << "[1] Insert data enter." << endl;
            cout << "[2] View file." << endl;
            cout << "[3] View logs." << endl;
            cout << "[4] Password by category." << endl;
            cout << "[5] Change password." << endl;
            cout << "[6] Change category." << endl;
            cout << "[7] Delete password." << endl;
            cout << "[8] Delete category." << endl;
            cout << "[9] Exit." << endl;
            cout << "\n >  ";
            cin >> choice;
            cout << "\n";

            try {
                if (choice == "1") {
                    insert_data();
                } else if (choice == "2") {
                    view_file();
                } else if (choice == "3") {
                    view_logs();
                } else if (choice == "4") {
                    password_by_category();
                } else if (choice == "5") {
                    edit_password();
                } else if (choice == "6") {
                    edit_category();
                } else if (choice == "7") {
                    delete_password();
                }else if (choice == "8") {
                    delete_category();
                } else if (choice == "9") {
                    file_exit();
                } else {
                    cout << "OPPS! Invalid option;\n" << endl;
                    main();
                    break;

                }
            }

            catch (const std::exception &e) {
                std::cerr << e.what() << '\n';
                cout << "[ERROR] : error while executing the programe!" << endl;
            }
        }
        return 0;

    }




