#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <dirent.h>
#include <algorithm>
#define stab "\t\t\t\t"
#define tab "\t\t\t\t\t\t\t"
#define format "=======================================================================\n"

using namespace std;

string user_id;

// ignore the inputs during sleep.
void ignore()
{
    while (kbhit())
    {
        getch();
    }
}

// To display the introduction
void introduction()
{
    string intro;
    system("color a");
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHE PROJECT LEAF";
    Sleep(300);
    ignore();
    getch();
    system("cls");
    system("color b");
    ifstream file("introduction.txt");
    if (!file)
    {
        cout << "DataBase Error";
        exit(0);
    }
    while (file.good())
    {
        getline(file, intro);
        cout << intro << endl;
    }
    Sleep(300);
    ignore();
    getch();
    system("cls");
    file.close();
}

// Just displays redirecting...
void redirect()
{
    for (int i = 0; i <= 2; i++)
    {
        cout << "Directing to login";
        Sleep(200);
        system("cls");
        cout << "Directing to login..";
        Sleep(200);
        system("cls");
        cout << "Directing to login....";
        Sleep(200);
        system("cls");
    }
}

// displays try again info..
/*void tryagain()
{
    cout << tab << "[1] Try Again !!" << endl;
    cout << tab << "[2] Create LEAF ID" << endl;
    cout << tab << "[3] Help" << endl;
    cout << tab << "[0] Terminate" << endl;
}*/

// Creates files and folder ..
void create()
{
    mkdir("C:\\User_Data");
    fstream file("C:\\User_Data\\users.txt", ios::in | ios::app);
    file.close();
    ofstream help("C:\\User_Data\\Help.txt");
    help << "\n\n\n\n\n\n"
         << endl;
    help << stab << "||============================================================================||" << endl;
    help << stab << "||*************************Welcome To LEAF COMMUNITY**************************||" << endl;
    help << stab << "||============================================================================||" << endl;
    help << stab << "||========1. Enter your user name and valid password to login.          ======||" << endl;
    help << stab << "||========2. Not created LEAF ID yet!,                                  ======||" << endl;
    help << stab << "||========	- Create your account.                                  ======||" << endl;
    help << stab << "||========	- Enter the desired user name.                          ======||" << endl;
    help << stab << "||========	- Set your passcode. It must be of 8 characters.        ======||" << endl;
    help << stab << "||========	- Now, you will get the message "
         << "Registration Successful"
         << ".======||" << endl;
    help << stab << "||========	- Continue to login,                                    ======||" << endl;
    help << stab << "||========	- Login                                                 ======||" << endl;
    help << stab << "||========	- All set now, Login and Enjoy.                         ======||" << endl;
    help << stab << "||============================================================================||" << endl;
    help << stab << "||============================================================================||" << endl;
    help.close();
}

// Open help file...
void gethelp()
{
    ifstream file;
    system("cls");
    file.open("C:\\User_Data\\Help.txt");
    while (file.good())
    {
        string str;
        getline(file, str);
        cout << str << endl;
    }
}

// Display termination message
void message()
{
    cout << "\n\n\n\n\n\n\n";
    cout << tab << "SEE YOU AGAIN !!\n  " << tab << "THE PROJECT LEAF";
}

// gets user name and return it.
string user_name()
{
    cout << endl
         << tab << "Enter the user name:";
    cin.clear();
    cin >> user_id;
    transform(user_id.begin(), user_id.end(), user_id.begin(), ::toupper);
    return (user_id);
}

// Class to hold the user name and password and checks for it in file
class registry
{
    string user_name, u, p;
    int found;

public:
    string get()
    {
        cout << endl
             << endl
             << tab << "Enter the user name:";
        cin >> user_name;
        Sleep(400);
        ignore();
        transform(user_name.begin(), user_name.end(), user_name.begin(), ::toupper);
        return user_name;
    }
    int check(string a)
    {
        ifstream input("C:\\User_Data\\users.txt");
        if (input.is_open())
        {
            while (input >> u >> p)
            {
                transform(u.begin(), u.end(), u.begin(), ::toupper);
                if (u == a)
                {
                    found = 1;
                    break;
                }
            }
            if (found == 1)
                return 1;
            else
                return 0;
        }
        else
        {
            cout << endl
                 << "Database Error";
            Sleep(500);
            getch();
            message();
            exit(0);
        }
    }
};

// displays the login window..............
void logidisplay()
{
    ifstream file("intro.txt");
    if (!file)
    {
        cout << "Database Error";
        getch();
        exit(0);
    }
    srand(time(0));
    int numLines = 0, randomLineNum = rand() % 25 + 1;
    string line;
    while (getline(file, line))
    {
        numLines++;
        if (numLines == randomLineNum)
        {
            cout << "LITERATURE FACT FOR YOU !!\n";
            cout << line << endl
                 << endl;
            cout << "\n\n\n";
            break;
        }
    }
    file.close();
    cout << "\t\t\t"
         << "||============================================================================||" << endl;
    cout << "\t\t\t"
         << "||*************************Welcome To LEAF COMMUNITY**************************||" << endl;
    cout << "\t\t\t"
         << "||============================================================================||\n"
         << endl;
    cout << tab << "[1] Continue to Login" << endl;
    cout << tab << "[2] Create Leaf ID" << endl;
    cout << tab << "[3] Need Help ?" << endl;
    cout << tab << "[0] Terminate" << endl;
}

// to register the new user......
void registr()
{
    registry N;
    int check;
    string reguser;
    reguser = N.get();
    cin.clear();
    check = N.check(reguser);
    if (check == 0)
    {
    registar:
        string regpass;
        char pass[8];
        cout << tab << "Enter the password:";

        // Allows user to enter password:
        int i = 0;
        while (regpass.size() <= 7)
        {
            pass[i] = getch();

            if (pass[i] == '\r')
            {
                cout << endl
                     << tab << "must be 8 characters";
                Sleep(200);
                ignore();
                system("cls");
                logidisplay();
                cout << tab << "Enter the user name:" << reguser << endl;
                ;
                goto registar;
            }
            else if (pass[i] == ' ')
            {
                cout << endl
                     << tab << "Cannot be NULL";
                cout << " [Use special characters instead]";
                Sleep(200);
                system("cls");
                ignore();
                system("color b");
                logidisplay();
                cout << tab << "Enter the user name:" << reguser << endl;
                ;
                goto registar;
            }
            else if (pass[i] == '\b')
            {
                if (i > 0)
                {
                    regpass.pop_back();
                    i--;
                }
                system("cls");
                logidisplay();
                cout << tab << "Enter the user name:" << reguser << endl;
                ;
                cout << tab << "Enter the password:";
                for (int a = 0; a < regpass.size(); a++)
                    cout << "*";
            }
            else
            {
                regpass = regpass + pass[i];
                cout << "*";
                i++;
            }
        }

        // Stores the credentials in a file:

        fstream reg("C:\\User_Data\\users.txt", ios::app);
        ofstream note("C:\\User_Data\\" + reguser + ".txt");
        string folder_name = "C:\\User_Data\\" + reguser;
        mkdir(folder_name.c_str());
        if (reg.is_open() && note.is_open())
        {
            reg << reguser << ' ' << regpass << endl;
            reg.close();
            note.close();
            system("color a");
            cout << endl
                 << endl
                 << tab << "!! Registration successful !!";
            Sleep(300);
            ignore();
            getch();
            system("cls");
        }
        else
            cout << "Database Error";
    }
    else
    {
        cout << endl
             << tab << "User exists !!";
        Sleep(300);
        ignore();
        system("cls");
        logidisplay();
        registr();
    }
}

// Validate user credentials and login.....
int login()
{
login:
    int exists;
    string user = user_name();
    system("color a");
auth:
    string key, u, p;
    char pass[8];
    cout << tab << "Enter the password:";
    // Receives the password from user:
    //=============================================
    int i = 0;
    do
    {
        pass[i] = getch();

        if (pass[i] == '\r')
        {
            cout << "must be 8 characters";
            Sleep(400);
            ignore();
            system("cls");
            logidisplay();
            cout << endl
                 << endl
                 << tab << "Enter the user name:" << user << endl;
            ;
            goto auth;
        }
        else if (pass[i] == ' ')
        {
            cout << "Cannot be NULL";
            cout << "Use special characters instead";
            Sleep(400);
            ignore();
            system("cls");
            logidisplay();
            cout << endl
                 << endl
                 << tab << "Enter the user name:" << user << endl;
            ;
            goto auth;
        }
        else if (pass[i] == '\b')
        {
            if (i > 0)
            {
                key.pop_back();
                i--;
            }
            system("cls");
            logidisplay();
            cout << endl
                 << endl
                 << tab << "Enter the user name:" << user << endl;
            ;
            cout << tab << "Enter the password:";
            for (int a = 0; a < key.size(); a++)
                cout << "*";
        }
        else
        {
            key = key + pass[i];
            cout << "*";
            i++;
        }
    } while (key.size() <= 7);

    // Validate the password:=======================================
    ifstream input("C:\\User_Data\\users.txt");
    if (input.is_open())
    {
        while (input >> u >> p)
        {
            if (u == user && p == key)
            {
                exists = 1;
            }
        }
        input.close();
        if (exists == 1)
        {
            system("cls");
            system("color c");
            cout << "\n\n\n\n\n\n\n\n";
            cout << endl
                 << stab << format << tab << "@" << user << ","
                 << "Congratulations! Logged in" << endl
                 << stab << format;
            Sleep(500);
            ignore();
            getch();
            system("cls");
            system("color d");
            cout << "\n\n\n\n\n\n\n\n";
            cout << endl
                 << stab << format << tab << "Welcome to the LEAF Community" << endl
                 << stab << format;
            Sleep(500);
            ignore();
            getch();
            return (1);
        }
        else
        {
            return (0);
        }
    }
    else
    {
        cout << endl
             << "Database Error";
        Sleep(500);
        ignore();
        message();
        exit(0);
    }
}

// To display a random fact and login system.
void authentication()
{
login:
    logidisplay();
    // Switch cases for login system
    char a = getch();
    switch (a)
    {
    case '1':
    {
        int check = login();
        if (check == 1)
            break;
        else
        {
            cout << endl
                 << endl
                 << tab << "Entered Credentials do not match" << endl;
            cout << tab << "[Try again or Create New account]" << endl;
            Sleep(300);
            ignore();
            getch();
            system("cls");
            system("color b");
            goto login;
        }
    }
    case '2':
    {
        registr();
        redirect();
        system("cls");
        system("color e");
        goto login;
    }
    case '3':
    {
        system("color a");
        gethelp();
        cout << tab << "\n\n Enter any Key to Continue.....";
        getch();
        system("cls");
        goto login;
    }
    case '0':
    {
        message();
        getch();
        system("cls");
        exit(0);
    }
    default:
    {
        cout << tab << "Enter Valid Option";
        Sleep(500);
        ignore();
        getch();
        system("cls");
        goto login;
    }
    }
}

// Template Editor....
void edit(string inputfile, string outputfile, string input, string output)
{
    ifstream infile;
    ofstream outfile;
    string line;
    infile.open(inputfile + ".txt", ios::in);
    if (!infile)
    {
        cout << "Unable to open file!" << endl;
        exit(0);
    }

    outfile.open(outputfile + ".txt", ios::out);
    if (!outfile)
    {
        cout << "Unable to open file!" << endl;
        exit(0);
    }

    while (getline(infile, line))
    {
        size_t pos = line.find(input);
        if (pos != string::npos)
        {
            line.replace(pos, input.size(), output);
        }
        outfile << line << endl;
    }
    infile.close();
    outfile.close();
}

// A template file creator..
void sample()
{
    string filename;
    string advertiser, position, department, advertisement, experience, qualification, institution, name;
    cout << "Enter the following details:" << endl;
    cin.ignore();
    cout << "Name of Hiring Manager: ";
    getline(cin, advertiser);
    // cin.ignore();
    cout << "Vacant Position: ";
    getline(cin, position);
    // cin.ignore();
    cout << "Name of Department: ";
    getline(cin, department);
    // cin.ignore();
    cout << "Where was vacancy published: ";
    getline(cin, advertisement);
    // cin.ignore();
    cout << "Year of experience: ";
    getline(cin, experience);
    // cin.ignore();
    cout << "Your qualification :";
    getline(cin, qualification);
    // cin.ignore();
    cout << "Graduated from(institution): ";
    getline(cin, institution);
    // cin.ignore();
    cout << "Applicant's Name: ";
    getline(cin, name);
    // cin.ignore();

    filename = "C:\\User_Data\\" + user_id;
    ofstream file("temp.txt");
    ofstream file1("temp1.txt");
    edit("samples", "temp", "[advertiser]", advertiser);
    edit("temp", "temp1", "[position]", position);
    edit("temp1", "temp", "[dept]", department);
    edit("temp", "temp1", "[advertisement]", advertisement);
    edit("temp1", "temp", "[experience]", experience);
    edit("temp", "temp1", "[qualification]", qualification);
    edit("temp1", "temp", "[institution]", institution);
    edit("temp", filename, "[name]", name);
    file.close();
    file1.close();
    remove("temp.txt");
    remove("temp1.txt");

    cout << "Created successfully!" << endl;
    cout << "DO you want to open now" << endl;
    cout << endl
         << endl
         << "=======================================================\n";
    cout << "||   Open=1\t\t      \t\t             ||" << endl;
    cout << "||   Enter you choice:-\t\t\t\t     ||" << endl;
    cout << "=======================================================\n";
    if (char a = getch() == '1')
    {
        system("cls");
        system("color a");
        ifstream file(filename + ".txt");
        string line;
        while (file.good())
        {
            getline(file, line);
            cout << line << endl;
        }
    }
}

void header()
{
    system("color e");
    cout << "\n\n\n\n"
         << endl;
    cout << stab << "||===============================================================||" << endl;
    cout << stab << "||*************************PROJECT LEAF**************************||" << endl;
    cout << stab << "||===============================================================||" << endl;
}
// displays main menu tab...
void main_menu()
{
    system("cls");
    header();
    cout << "\n\n\n\n";
    cout << tab << "[1] Notes" << endl;
    cout << tab << "[2] Templates" << endl;
    cout << tab << "[3] Read" << endl;
    cout << tab << "[4] Some Authors" << endl;
    cout << tab << "[5] About Us" << endl;
    cout << tab << "[6] Logout" << endl;
    cout << tab << "[0] Terminate" << endl;
}

// TO open the contents and sequential read..
int read_content(string folder, string genre)
{
    int num = 1;
    while (num)
    {
        string filename = to_string(num) + ".txt";
        ifstream file("D:\\LEAF\\Project\\Final Project\\" + folder + "\\" + genre + "\\" + filename);
        if (!file)
        {
            cout << endl
                 << tab << "File Error" << endl;
            Sleep(300);
            ignore();
            system("cls");
            header();
            return (0);
        }
        string stories;
        system("cls");
        while (file.good())
        {
            getline(file, stories);
            cout << stories << endl;
        }
        cout << endl
             << endl
             << "=======================================================\n";
        cout << "||   Next=2\t\tBack=0\t\tPrevious=1   ||" << endl;
        cout << "||   Enter you choice:-\t\t\t\t     ||" << endl;
        cout << "=======================================================\n";
        char st = getch();
        if (st == '2')
            num++;
        else if (st == '1')
            num--;
        else if (st == '0')
            num = 0;
        else
            ignore();
    }
}

// Search for the author and display..
int search_author(string folder, string author)
{
    int num = 1;
    string line, bio;
top:
    string filename = to_string(num) + ".txt";
    ifstream file("D:\\LEAF\\Project\\Final Project\\" + folder + "\\" + filename);
    if (file.is_open())
    {
        num++;
        getline(file, line);
        if (line.find(author) != string::npos)
        {
            system("cls");
            while (file.good())
            {
                getline(file, bio);
                cout << bio << endl;
            }
        }
        else
            goto top;
    }
    else
        cout << endl
             << tab << "Entered author is not found in our library !!" << endl;
}

// Saves the user notes...
void saveNote()
{
    string date, content, title, input;
    ofstream outfile;
    cout << "Enter the date (in the format YYYY-MM-DD) : \n";
    cout << "[Invalid format alters in searching of note]" << endl;
    cin >> date;
    cin.ignore();
    cout << "Give a title to your note: ";
    getline(cin, title);
    transform(title.begin(), title.end(), title.begin(), ::toupper);
    cout << "Enter your notes: ";
    while (getline(cin, input))
    {
        if (input.empty())
            break;
        content += input + "\n";
    }
    string full_path = "C:\\User_Data\\" + user_id + "\\" + date + ".txt";
    outfile.open(full_path, ios::in | ios::app);
    if (!content.empty())
    {
        outfile << "Date:- " << date << endl;
        outfile << "[" << title << "]\n"
                << endl;
        outfile << content;
        outfile << endl
                << stab << format << endl
                << endl;
        cout << "Note saved successfully!" << endl;
    }
    else
    {
        cout << "Empty Note discarded" << endl
             << format << endl;
        remove(full_path.c_str());
    }
    outfile.close();
}

// Displays all notes from User folder...
int view_notes()
{
    DIR *dir;
    dirent *ent;
    string note;
    string folder_path = "C:\\User_Data\\" + user_id + "\\";

    if ((dir = opendir(folder_path.c_str())) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            string filename = folder_path + ent->d_name;
            ifstream file(filename);
            if (file)
            {
                string line;
                while (getline(file, line))
                {
                    note = note + "\n" + line;
                }
                file.close();
            }
        }
        closedir(dir);
    }
    else
    {
        cout << "Database Error " << endl;
        return 1;
    }
    if (note.empty())
    {
        cout << "\n\n\n"
             << tab << "You have no any saved notes.";
        return 1;
    }
    else
        cout << note;
    return 0;
}

// =============PROGRAM EXECUTION=====================

int main()
{
    create();
    introduction(); // display introduction to literature.
logout:
    authentication(); // login and new user creation.
menu:
    main_menu();
    char a = getch();
    system("cls");
    system("color a");
    header();
    switch (a)
    {
    case '1':
    case1:
    {
        cout << "\n\n\n\n";
        cout << tab << "[1]. Keep Note" << endl;
        cout << tab << "[2]. View Notes" << endl;
        cout << tab << "[3]. Filter Note" << endl;
        cout << tab << "[4]. Edit Note" << endl;
        cout << tab << "[5]. Delete Note" << endl;
        cout << tab << "[0]. Back" << endl;
        char enter = getch();
        switch (enter)
        {
        case '1':
        {
            system("cls");
            header();
            cout << "\n\n\n\n";
            saveNote();
            getch();
            system("cls");
            header();
            goto case1;
        }
        case '2':
        {
            system("cls");
            system("color a");
            header();
            cout << "\n\n\n";
            view_notes();
            getch();
            system("cls");
            header();
            goto case1;
        }
        case '3':
        {
            string date, line;
            cin.ignore();
            cout << "Enter the date to view notes:-";
            getline(cin, date);
            ifstream file("C:\\User_Data\\" + user_id + "\\" + date + ".txt");
            if (!file)
            {
                cout << tab << "Error opening note";
            }
            system("cls");
            header();
            while (file.good())
            {
                getline(file, line);
                cout << line << endl;
            }
            file.close();
            Sleep(300);
            ignore();
            getch();
            system("cls");
            header();
            goto case1;
        }
        case '4':
        {
            system("cls");
            system("color a");
            string check, enter, date;
            header();
            int found = view_notes();
            if (!found)
            {
                cout << endl
                     << tab << "Enter the date to edit :-";
                cin >> date;
                Sleep(100);
                ignore();
                system("cls");
                header();
                string filename = "C:\\User_Data\\" + user_id + "\\" + date;
                // string temp_file="C:\\User_Data\\"+user_id+"\\"+"temporary";
                // ofstream file1(temp_file+".txt");
                fstream file;
                file.open(filename + ".txt", ios::app | ios::in | ios::out);
                if (file.is_open())
                {
                    string line;
                    while (file.good())
                    {
                        getline(file, line);
                        cout << line << endl;
                    }
                    file.close();
                    Sleep(100);
                    ignore();
                    cin.ignore();
                    cout << tab << "Enter the line to find:-";
                    getline(cin, check);
                    cout << endl
                         << tab << "Enter the line that replace:-";
                    getline(cin, enter);
                    cin.ignore();
                    string filename = "C:\\User_Data\\" + user_id + "\\" + date + ".txt";

                    string contents;
                    ifstream infile(filename);
                    if (infile)
                    {
                        contents.assign((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
                        infile.close();
                    }
                    else
                    {
                        cerr << "Error: unable to open file " << endl;
                    }

                    size_t pos = contents.find(check);
                    if (pos != string::npos)
                    {
                        contents.replace(pos, check.size(), enter);
                    }
                    else
                    {
                        cerr << "Error: line not found" << endl;
                    }

                    ofstream outfile(filename);
                    if (outfile)
                    {
                        outfile << contents;
                        outfile.close();
                    }
                    else
                    {
                        cerr << "Error: unable to write to file " << filename << endl;
                        return 1;
                    }
                    cout << "File " << filename << " has been updated" << endl;
                }
                Sleep(100);
                ignore();
                getch();
                system("cls");
                header();
                goto case1;
            }
        }
        case '5':
        {
            string date, line;
            cin.ignore();
            cout << tab << "Enter the date to delete:- ";
            cin >> date;
            Sleep(200);
            ignore();
            ifstream file("C:\\User_Data\\" + user_id + "\\" + date + ".txt");
            if (!file)
            {
                cout << tab << "No Notes Found for this day";
                Sleep(300);
                ignore();
                system("cls");
                header();
                goto case1;
            }
            system("cls");
            header();
            string filename = "C:\\User_Data\\" + user_id + "\\" + date + ".txt";
            while (file.good())
            {
                getline(file, line);
                cout << line << endl;
            }
            file.close();
            cout << endl
                 << tab << "Confirm to delete ?!" << endl;
            cout << tab << "[1] DELETE\t\t\t[0] CANCEL";
            char a = getch();
            if (a == '1')
            {
                remove(filename.c_str());
                cout << endl
                     << tab << "Note Deleted Successfully !!";
            }
            else if (a == '0')
            {
                cout << endl
                     << tab << "Request Canceled !";
            }
            else
                ignore();
            Sleep(300);
            ignore();
            system("cls");
            header();
            goto case1;
        }
        case '0':
        {
            system("cls");
            goto menu;
        }
        default:
        {
            cout << endl
                 << tab << "Enter Valid Option";
            Sleep(500);
            ignore();
            getch();
            system("cls");
            goto menu;
        }
        }
    }
    case '2':
    case2:
    {
        cout << "\n\n\n\n";
        cout << tab << "[1]. Job Application" << endl;
        cout << tab << "[0]. Back" << endl;
        cout << tab << "More to be added......" << endl;
        char check = getch();
        if (check == '1')
        {
            system("cls");
            sample();
            goto case2;
        }
        else if (check == '0')
            goto menu;
        else
        {
            cout << endl
                 << tab << "Invalid Option" << endl;
            Sleep(300);
            system("cls");
            header();
            goto case2;
        }
    }
    case '3':
    case3:
    {
        cout << "\n\n\n\n";
        cout << tab << "[1]. Stories" << endl;
        cout << tab << "[2]. Poems" << endl;
        cout << tab << "[3]. Dramas" << endl;
        cout << tab << "[4]. Jokes" << endl;
        cout << tab << "[0]. Back" << endl;
        char check = getch();
        switch (check)
        {
        case '1':
        {
            int value = read_content("Contents", "Stories");
            if (!value)
                goto case3;
            system("cls");
            header();
            goto case3;
        }
        case '2':
        {
            int value = read_content("Contents", "Poems");
            if (!value)
                goto case3;
            system("cls");
            header();
            goto case3;
        }
        case '3':
        {
            int value = read_content("Contents", "Dramas");
            if (!value)
                goto case3;
            system("cls");
            header();
            goto case3;
        }
        case '4':
        {
            int value = read_content("Contents", "Jokes");
            if (!value)
                goto case3;
            system("cls");
            header();
            goto case3;
        }
        case '0':
        {
            system("cls");
            goto menu;
        }
        default:
        {
            ignore();
            system("cls");
            header();
            goto case3;
        }
        }
    }
    case '4':
    case4:
    {
        cout << "\n\n\n\n";
        cout << tab << "[1]. View randomly" << endl;
        cout << tab << "[2]. Search by Name" << endl;
        cout << tab << "[0]. Back" << endl
             << endl;
        char check = getch();
        switch (check)
        {
        case '1':
        {
            int value = read_content("Authors", "");
            if (!value)
                goto case4;
            system("cls");
            header();
            goto case4;
        }
        case '2':
        {
            string author;
            cout << tab << "Enter the author's name:- ";
            cin >> author;
            Sleep(200);
            ignore();
            transform(author.begin(), author.end(), author.begin(), ::toupper);
            search_author("authors", author);
            Sleep(300);
            ignore();
            getch();
            system("cls");
            header();
            goto case4;
        }
        case '0':
        {
            system("cls");
            goto menu;
        }
        default:
        {
            ignore();
            system("cls");
            header();
            goto case4;
        }
        }
    }
    case '5':
    {
        system("color f");
        system("cls");
        ifstream file("about_us.txt");
        if (!file)
        {
            cout << "Error Database";
            goto menu;
        }
        string line;
        while (file.good())
        {
            getline(file, line);
            cout << line << endl;
        }
        getch();
        system("cls");
        system("color 2");
        goto menu;
    }
    case '6':
    {
        system("cls");
        system("color 4");
        goto logout;
    }
    case '0':
    {
        message();
        getch();
        system("cls");
        exit(0);
    }
    default:
    {
        main_menu();
        cout << endl
             << tab << "Enter Valid Option";
        Sleep(500);
        ignore();
        system("cls");
        goto menu;
    }
    }

    getch();
    system("cls");
    return 0;
}
