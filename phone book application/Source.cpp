#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#define color(i) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(i));
using namespace std;

string selection;
int Nocontact = 0;
int deleted[1000000], deleted_num = 0;
int output[1000000], output_num = 0;

struct birht_day
{
    string day;
    string month;
    string year;
};

struct phone
{
    string name;
    string nickname;
    string gender;
    string number;
    string number2;
    string email;
    string email2;
    string address;
    birht_day date;
}contact[1000000];

void loading()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    color(13);
    cout << "\t\t\t\t\tLOADING...";
    char x = 219;
    for (int i = 0; i < 20; ++i) {
        color(13);
        cout << x;
        if (i < 10) Sleep(200);
        else if (i >= 10 && i <= 15) Sleep(100);
        else Sleep(25);
    }
}

void showtitle()
{
    system("CLS");
    color(12);
    cout << "\t\t\t\t\t  ----------------------------------\n";
    cout << "\t\t\t\t\t  |                                |\n";
    cout << "\t\t\t\t\t  |  << Phone Book Application >>  |  \n";
    cout << "\t\t\t\t\t  |                                |\n";
    cout << "\t\t\t\t\t  ----------------------------------\n\n\n";
    color(14);
}

void show_menu()
{
    color(11);
    cout << "[ 1 ]  _ Show the saved contacts.\n";
    cout << "[ 2 ]  _ Add Contact.\n";
    cout << "[ 3 ]  _ Search for contact.\n";
    cout << "[ 4 ]  _ Delete contact.\n";
    cout << "[ 5 ]  _ Update or change the details of contacts.\n";
    cout << "[ 6 ]  _ Exit.\n";
    cout << "\n\n_______________\n\n";
    cout << "Enter selection number : ";
    cin >> selection;
}

void write()
{
    ofstream myfile("Data.txt");
    myfile << Nocontact << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].name << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].nickname << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].gender << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].number << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].number2 << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].email << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].email2 << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].address << endl;
    for (int i = 0; i < Nocontact; i++) myfile << contact[i].date.day << " " << contact[i].date.month << " " << contact[i].date.year << " " << endl;

    myfile.close();
}

void read()
{
    string myText;
    ifstream MyReadFile("Data.txt");
    getline(MyReadFile, myText);
    if (myText.size() != 0) Nocontact = stoi(myText);
    else Nocontact = 0;

    for (int i = 0; i < Nocontact; i++) getline(MyReadFile, contact[i].name);
    for (int i = 0; i < Nocontact; i++) getline(MyReadFile, contact[i].nickname);
    for (int i = 0; i < Nocontact; i++) getline(MyReadFile, contact[i].gender);
    for (int i = 0; i < Nocontact; i++) getline(MyReadFile, contact[i].number);
    for (int i = 0; i < Nocontact; i++) getline(MyReadFile, contact[i].number2);
    for (int i = 0; i < Nocontact; i++) getline(MyReadFile, contact[i].email);
    for (int i = 0; i < Nocontact; i++) getline(MyReadFile, contact[i].email2);
    for (int i = 0; i < Nocontact; i++) getline(MyReadFile, contact[i].address);
    for (int i = 0; i < Nocontact; i++)
    {
        getline(MyReadFile, myText);
        int counter = 1;
        string completed;
        myText += " ";
        for (int j = 0; j < myText.size(); j++)
        {
            if (myText[j] == ' ')
            {
                if (counter == 1) contact[i].date.day = completed;
                else if (counter == 2) contact[i].date.month = completed;
                else if (counter == 3) contact[i].date.year = completed;
                counter++;
                completed.clear();
            }
            else completed += myText[j];
        }
    }
    MyReadFile.close();

    deleted_num = 0;
    for (int i = 0; i < Nocontact; i++)
    {
        if (contact[i].name == "0")
        {
            deleted[deleted_num] = i;
            deleted_num++;
        }
    }
}

void invalid_input()
{
    color(4);
    cout << "Invalid number\n";
    color(14);
    cout << "Re-enter the number\n";
}

bool compare(phone one, phone two)
{
    if (one.name < two.name) return true;
    return false;
}

void sort()
{
    sort(contact, contact + Nocontact, compare);
}

void cout_contact(int indx, int rank)
{
    color(14);
    cout << endl << rank << " ____________________________________________________________________\n\n";
    color(15);
    cout << "Name:-       \t" << contact[indx].name << endl;
    if (contact[indx].nickname != "0")
    {
        cout << "Nickname:-   \t" << contact[indx].nickname << endl;
    }
    cout << "Number:-     \t" << contact[indx].number;
    if (contact[indx].number2 != "0")
    {
        cout << " - " << contact[indx].number2 << endl;
    }
    else cout << endl;
    if (contact[indx].gender != "0")
    {
        cout << "Gender:-     \t" << contact[indx].gender << endl;
    }
    if (contact[indx].email != "0" || contact[indx].email2 != "0")
    {
        cout << "E-mail :-      \t";
        bool email = 0;
        if (contact[indx].email != "0")
        {
            cout << contact[indx].email;
            email = true;
        }
        if (contact[indx].email2 != "0")
        {
            if (email) cout << " - " << contact[indx].email2 << "\n";
            else cout << contact[indx].email2 << "\n";
        }
        else cout << "\n";
    }

    if (contact[indx].address != "0")
    {
        cout << "Address:-    \t" << contact[indx].address << endl;
    }
    if (contact[indx].date.day != "0")
    {
        cout << "Birthdate:-  \t" << contact[indx].date.day << "/" << contact[indx].date.month << "/" << contact[indx].date.year << endl;
    }
}

void saved()
{
    deleted_num = 0;
    if (Nocontact == 0) cout << "\n\tThere are no saved contacts \n\n\n\n\n";
    else
    {
        int rank = 1;
        for (int i = 0; i < Nocontact; i++)
        {
            if (contact[i].name != "0")
            {
                cout_contact(i, rank);
                rank++;
            }
            else
            {
                deleted[deleted_num] = i;
                deleted_num++;
            }
        }
        cout << "\n\n\n\n\n\t\t Contact = " << rank - 1 << endl;
    }
    cout << "\n\nPress any key to back to the main menu ... ";
    cin >> selection;
    selection = "0";
}

bool Add = true;
bool check_date(string check)
{
    for (int b = 0; b < check.size(); b++)
    {
        if (check[b] >= '0' && check[b] <= '9') continue;
        else return false;
    }
    return true;
}

bool check_number(string check)
{
    for (int b = 0; b < check.size(); b++)
    {
        if ((check[b] >= '0' && check[b] <= '9') || check[b] == '+') continue;
        else return false;
    }
    return true;
}

bool check_out(string check)
{
    if (check == "#")
    {
        Add = false;
        return true;
    }
    else return false;
}

void add_contact(int rank)
{
    Add = true;
    cout << "\t Press # to Cancel adding & Back to main menu.\n\n";
    cout << "Enter name :-    ";
    while (true)
    {
        string c, final_name;
        cin.ignore();
        getline(cin, c);
        if (check_out(c)) return;
        c += " ";
        transform(c.begin(), c.end(), c.begin(), ::tolower); // for convert to lowercase
        contact[rank].name.clear();
        int cnt = 0;
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] == ' ')
            {
                if (final_name[0] >= 'a' && final_name[0] <= 'z') final_name[0] -= 32;
                contact[rank].name += final_name;
                contact[rank].name += " ";
                final_name.clear();
                cnt++;
            }
            else
            {
                final_name += c[i];
            }
        }
        if (cnt != c.size()) break;
        else
        {
            color(4);
            cout << "Invalid name\n";
            color(14);
            cout << "Re-enter the name\n";
        }
    }
    cout << "Enter nickname :-   (press 0 to skip)   ";
    cin >> contact[rank].nickname;
    if (check_out(contact[rank].nickname)) return;
    cout << "Enter gender :-  [Male / Female]      (Press 0 to skip)   ";
    while (true)
    {
        cin >> contact[rank].gender;
        if (check_out(contact[rank].gender)) return;
        if (contact[rank].gender != "0")
        {
            if (contact[rank].gender[0] == 'f' || contact[rank].gender[0] == 'F')
            {
                contact[rank].gender = "Female";
                break;
            }
            else if (contact[rank].gender[0] == 'm' || contact[rank].gender[0] == 'M')
            {
                contact[rank].gender = "Male";
                break;
            }
            else
            {
                color(4);
                cout << "Invalid gender\n";
                color(14);
                cout << "Re-enter gender\n";
            }
        }
        else break;
    }
    cout << "Enter number :-    ";
    cin >> contact[rank].number;
    if (check_out(contact[rank].number)) return;
    while (true)
    {
        if (check_number(contact[rank].number)) break;
        else
        {
            color(4);
            cout << "\nInvalid Number\n";
            color(14);
            cout << "Enter number :-    ";
            cin >> contact[rank].number;
            if (check_out(contact[rank].number)) return;
        }
    }
    cout << "Enter another number :-    (Press 0 to skip)   ";
    cin >> contact[rank].number2;
    if (check_out(contact[rank].number2)) return;
    while (true)
    {
        if (check_number(contact[rank].number2)) break;
        else
        {
            color(4);
            cout << "\nInvalid Number\n";
            color(14);
            cout << "Enter number :-    ";
            cin >> contact[rank].number2;
            if (check_out(contact[rank].number2)) return;
        }
    }
    cout << "Enter E-mail :-    (Press 0 to skip)   ";
    cin >> contact[rank].email;
    if (check_out(contact[rank].email)) return;
    if (contact[rank].email != "0")
    {
        cout << "Enter another E-mail :-    (Press 0 to skip)   ";
        cin >> contact[rank].email2;
        if (check_out(contact[rank].email2)) return;
    }
    else contact[rank].email2 = "0";

    cout << "Enter address :-    (Press 0 to skip)   ";
    cin.ignore();
    getline(cin, contact[rank].address);
    if (check_out(contact[rank].address)) return;

    cout << "Enter birthdate  ..  ( To remove birthdate press 0 )\n";
    cout << "Day = ";
    cin >> contact[rank].date.day;
    if (check_out(contact[rank].date.day)) return;
    if (contact[rank].date.day != "0")
    {
        while (true)
        {
            int day;
            bool d = check_date(contact[rank].date.day);
            if (d) day = stoi(contact[rank].date.day);
            if (d && (day <= 31 && day > 0)) break;
            else
            {
                color(4);
                cout << "\nInvalid Day\n";
                color(14);
                cout << "Day = ";
                cin >> contact[rank].date.day;
                if (check_out(contact[rank].date.day)) return;
            }
        }
        cout << "Month = ";
        cin >> contact[rank].date.month;
        if (check_out(contact[rank].date.month)) return;
        while (true)
        {
            int month;
            bool d = check_date(contact[rank].date.month);
            if (d) month = stoi(contact[rank].date.month);
            if (d && (month <= 12 && month > 0)) break;
            else
            {
                color(4);
                cout << "\nInvalid Month\n";
                color(14);
                cout << "Month = ";
                cin >> contact[rank].date.month;
                if (check_out(contact[rank].date.month)) return;
            }
        }
        cout << "Year = ";
        cin >> contact[rank].date.year;
        if (check_out(contact[rank].date.year)) return;
        while (true)
        {
            int year;
            bool d = check_date(contact[rank].date.year);
            if (d) year = stoi(contact[rank].date.year);
            if (d && year > 0) break;
            else
            {
                color(4);
                cout << "\nInvalid Month\n";
                color(14);
                cout << "Year = ";
                cin >> contact[rank].date.year;
                if (check_out(contact[rank].date.year)) return;
            }
        }
    }
    else
    {
        contact[rank].date.month = "0";
        contact[rank].date.year = "0";
    }
}

void add()
{
    if (deleted_num != 0)
    {
        add_contact(deleted[deleted_num - 1]);
        if (Add)
        {
            deleted_num--;
            color(10);
            cout << "\n\n < Added Successfully >\n";
        }
    }
    else
    {
        add_contact(Nocontact);
        if (Add)
        {
            Nocontact++;
            color(10);
            cout << "\n\n < Added Successfully >\n";
        }
    }
    if (Add)
    {
        cout << "\nPress 0 to back to main menu ..  ";
        cout << "\nPress 2 to to add another contact .. \n";
        cin >> selection;
        while (selection != "0" && selection != "2")
        {
            invalid_input();
            cin >> selection;
        }
    }
    else selection = "0";
}

bool notfound = true, cancel = false;
void search()
{
    output_num = 0;
    notfound = true;
    cancel = false;
    cout << "\n\t Press # to Cancel searching.\n";
    cout << "\n\nEnter name/number of contact ..  ";
    string input;
    cin.ignore();
    getline(cin, input);
    cout << endl;
    if (check_out(input))
    {
        cancel = true;
        return;
    }
    int rank = 1;
    if ((input[0] >= '0' && input[0] <= '9') || input[0] == '+')
    {
        for (int i = 0; i < Nocontact; i++)
        {
            bool found = true;
            for (int j = 0; j < input.size(); j++)
            {
                if (contact[i].number[j] != input[j])
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                output[output_num] = i;
                output_num++;
                cout_contact(i, rank);
                rank++;
            }
            else
            {
                found = true;
                if (contact[i].number2 != "0")
                {
                    for (int s = 0; s < input.size(); s++)
                    {
                        if (contact[i].number2[s] != input[s])
                        {
                            found = false;
                            break;
                        }
                    }

                    if (found)
                    {
                        output[output_num] = i;
                        output_num++;
                        cout_contact(i, rank);
                        rank++;
                    }
                }
            }
        }
    }
    else
    {
        if (input[0] >= 'a' && input[0] <= 'z') input[0] -= 32;
        for (int i = 0; i < Nocontact; i++)
        {
            bool found = true;
            if (contact[i].name != "0")
            {
                for (int s = 0; s < input.size(); s++)
                {
                    if (contact[i].name[s] != input[s])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    output[output_num] = i;
                    output_num++;
                    cout_contact(i, rank);
                    rank++;
                }
            }
        }
    }
    if (rank == 1)
    {
        cout << "No items match your search" << endl;
        notfound = false;
    }
    cout << endl;
}

int delete_bycontact()
{
    int rank = 1;
    output_num = 0;
    if (Nocontact == 0) cout << "No contacts exist";
    else
    {
        for (int i = 0; i < Nocontact; i++)
        {
            if (contact[i].name != "0")
            {
                cout_contact(i, rank);
                output[output_num] = i;
                output_num++;
                rank++;
            }
        }
    }
    return rank - 1;
}

void after_delete(int indx)
{
    contact[indx].name = "0";
    contact[indx].number = "0";
    contact[indx].nickname = "0";
    contact[indx].number2 = "0";
    contact[indx].gender = "0";
    contact[indx].email = "0";
    contact[indx].email2 = "0";
    contact[indx].address = "0";
    contact[indx].date.day = "0";
    contact[indx].date.month = "0";
    contact[indx].date.year = "0";
}

string deletechoice;
int deletenum;
void delete_number()
{
    if (deletechoice == "1")
    {
        Nocontact = 0;
        color(10);
        cout << "\n\n\tAll Contacts Deleted Successfully\n\n";
        cout << "Press any key to return to the main menu\n";
        cin >> selection;
        selection = "0";
    }
    else if (deletechoice == "2")
    {
        search();
        if (cancel)
        {
            selection = "4";
            return;
        }
        if (notfound)
        {
            int r;
            string r1;
            cout << "\n\nChoose the rank of the contact : ";
            cin >> r1;
            while (true)
            {
                if (!check_number(r1))
                {
                    invalid_input();
                    cin >> r1;
                }
                else
                {
                    r = stoi(r1);
                    if (r <= 0 || r > output_num)
                    {
                        invalid_input();
                        cin >> r1;
                    }
                    else break;
                }
            }
            r = output[r - 1];
            after_delete(r);
            deleted[deleted_num] = r;
            deleted_num++;
            color(10);
            cout << "\n\n -> Contact Deleted Successfully <- ";
        }
        cout << "\n\n Press 0 to return to the main menu .. or press 4 to delete another contact   ";
        cin >> selection;
        while (selection != "0" && selection != "4")
        {
            invalid_input();
            cin >> selection;
        }
    }
    else if (deletechoice == "3")
    {
        int rank = delete_bycontact();
        cout << "\nEnter Delete contact number : ";
        while (true)
        {
            cin >> deletenum;
            if (deletenum <= rank && deletenum > 0) break;
            else
            {
                invalid_input();
            }
        }
        int indx = output[deletenum - 1];
        after_delete(indx);
        deleted[deleted_num] = indx;
        deleted_num++;
        color(10);
        cout << "\n\n -> Contact Deleted Successfully <- ";
        cout << "\n\n Press 0 to return to the main menu .. or press 4 to delete another contact   ";
        cin >> selection;
        while (selection != "0" && selection != "4")
        {
            invalid_input();
            cin >> selection;
        }
    }
    else if (deletechoice == "4")
    {
        selection = "0";
    }
}

void delete_menu()
{
    cout << "[1]   Delete All.\n";
    cout << "[2]   Delete by search.\n";
    cout << "[3]   Delete from contact list.\n";
    cout << "[4]   Back to main menu.\n";
    cout << "_______________\n\n";
    cout << "Enter Selection number : ";
    cin >> deletechoice;
    while (true)
    {
        if (deletechoice != "1" && deletechoice != "2" && deletechoice != "3" && deletechoice != "4")
        {
            invalid_input();
            cin >> deletechoice;
        }
        else break;
    }
    delete_number();
}

void upcontact(int rank)
{
    showtitle();
    string Selection;
    bool invalid = true;
    cout << "[1]   change name \n";
    cout << "[2]   change nickname \n";
    cout << "[3]   change gender \n";
    cout << "[4]   change number \n";
    cout << "[5]   change 2nd number\n";
    cout << "[6]   change email\n";
    cout << "[7]   change 2nd email\n";
    cout << "[8]   change address\n";
    cout << "[9]   change date\n";
    cout << "[0]   save\n";
    while (true)
    {
        if (invalid)
        {
            cout << "_______________\n\n";
            cout << "Enter Selection number : ";
        }
        cin >> Selection;
        invalid = true;
        if (Selection == "1")
        {
            cout << "Enter new name : ";
            while (true)
            {
                string c, final_name;
                cin.ignore();
                getline(cin, c);
                if (check_out(c)) return;
                c += " ";
                transform(c.begin(), c.end(), c.begin(), ::tolower); // for convert to lowercase
                contact[rank].name.clear();
                int cnt = 0;
                for (int i = 0; i < c.size(); i++)
                {
                    if (c[i] == ' ')
                    {
                        if (final_name[0] >= 'a' && final_name[0] <= 'z') final_name[0] -= 32;
                        contact[rank].name += final_name;
                        contact[rank].name += " ";
                        final_name.clear();
                        cnt++;
                    }
                    else
                    {
                        final_name += c[i];
                    }
                }
                if (cnt != c.size()) break;
                else
                {
                    color(4);
                    cout << "Invalid name\n";
                    color(14);
                    cout << "Re-enter the name\n";
                }
            }
        }
        else if (Selection == "2")
        {
            cout << "Enter new nickname :  ( Press 0 to remove )    ";
            cin >> contact[rank].nickname;
        }
        else if (Selection == "3")
        {
            cout << "Enter new gender :   ( Press 0 to remove )    ";
            cin >> contact[rank].gender;
        }
        else if (Selection == "4")
        {
            cout << "Enter new number : ";
            cin >> contact[rank].number;
        }
        else if (Selection == "5")
        {
            cout << "Enter new 2nd number :   ( Press 0 to remove )    ";
            cin >> contact[rank].number2;

        }
        else if (Selection == "6")
        {
            cout << "Enter new email :   ( Press 0 to remove )    ";
            cin >> contact[rank].email;

        }
        else if (Selection == "7")
        {
            cout << "Enter new 2nd email :   ( Press 0 to remove )    ";
            cin >> contact[rank].email2;
        }
        else if (Selection == "8")
        {
            cout << "Enter the address :   ( Press 0 to remove )    ";
            cin.ignore();
            getline(cin, contact[rank].address);
        }
        else if (Selection == "9")
        {
            cout << "Enter new day :   ( Press 0 to remove )    ";
            cin >> contact[rank].date.day;
            if (contact[rank].date.day != "0")
            {
                while (true)
                {
                    int day;
                    bool d = check_date(contact[rank].date.day);
                    if (d) day = stoi(contact[rank].date.day);
                    if (d && (day <= 31 && day > 0)) break;
                    else
                    {
                        color(4);
                        cout << "\nInvalid Day\n";
                        color(14);
                        cout << "Day = ";
                        cin >> contact[rank].date.day;
                    }
                    break;
                }
                cout << "Enter new month : ";
                cin >> contact[rank].date.month;
                while (true)
                {
                    int month;
                    bool d = check_date(contact[rank].date.month);
                    if (d) month = stoi(contact[rank].date.month);
                    if (d && (month <= 12 && month > 0)) break;
                    else
                    {
                        color(4);
                        cout << "\nInvalid Month\n";
                        color(14);
                        cout << "Month = ";
                        cin >> contact[rank].date.month;
                    }
                    break;
                }
                cout << "Enter new year : ";
                cin >> contact[rank].date.year;
                while (true)
                {
                    int year;
                    bool d = check_date(contact[rank].date.year);
                    if (d) year = stoi(contact[rank].date.year);
                    if (d && year > 0) break;
                    else
                    {
                        color(4);
                        cout << "\nInvalid Year\n";
                        color(14);
                        cout << "Year = ";
                        cin >> contact[rank].date.year;
                    }
                    break;
                }
            }
            else
            {
                contact[rank].date.month = "0";
                contact[rank].date.year = "0";
            }
        }
        else if (Selection == "0")
        {
            break;
        }
        else
        {
            invalid_input();
            invalid = false;
        }
    }
}

void selcontact()
{
    int rank = 1;
    int r;
    output_num = 0;
    if (Nocontact == 0) cout << "No contacts exist";
    else
    {
        for (int i = 0; i < Nocontact; i++)
        {
            if (contact[i].name != "0")
            {
                output[output_num] = i;
                output_num++;
                cout_contact(i, rank);
                rank++;
            }
        }
        cout << "\n\n\t\t Contact = " << rank - 1 << endl;
        cout << endl;
        cout << "Choose the rank of the contact : ";
        cin >> r;
        while (r <= 0 || r > output_num)
        {
            invalid_input();
            cin >> r;
        }
        r = output[r - 1];
        upcontact(r);
        color(10);
        cout << "\n\n   <Updated Successfully>    ";
        color(14);
        cout << "\n\nPress 0 to back to main menu  - or press 5 to update .. ";
        cin >> selection;
        while (selection != "0" && selection != "5")
        {
            invalid_input();
            cin >> selection;
        }
    }
}

void update()
{
    string Selection;
    cout << "[1]   Update by search \n";
    cout << "[2]   Update from contact list\n";
    cout << "[3]   Back to main menu \n";
    cout << "_______________\n\n";
    cout << "Enter Selection number : ";
    cin >> Selection;
    while (true)
    {
        if (Selection != "1" && Selection != "2" && Selection != "3")
        {
            invalid_input();
            cin >> Selection;
        }
        else break;
    }
    if (Selection == "1")
    {
        search();
        if (cancel)
        {
            selection = "5";
            return;
        }
        cout << endl;
        if (notfound)
        {
            int r;
            string r1;
            cout << "Choose the rank of the contact : ";
            cin >> r1;
            while (true)
            {
                if (!check_number(r1))
                {
                    invalid_input();
                    cin >> r1;
                }
                else
                {
                    r = stoi(r1);
                    if (r <= 0 || r > output_num)
                    {
                        invalid_input();
                        cin >> r1;
                    }
                    else break;
                }
            }
            r = output[r - 1];
            upcontact(r);
            color(10);
            cout << "\n\n   <Updated successfully>    ";
            color(14);
        }
        cout << "\n\npress 0 to back to main menu  - or press 5 to Re-update .. ";
        cin >> selection;
        while (selection != "0" && selection != "5")
        {
            invalid_input();
            cin >> selection;
        }
    }
    else if (Selection == "2") { selcontact(); }
    else if (Selection == "3")
    {
        selection = "0";
        return;
    }
}

int main()
{
    loading();
    read();
    showtitle();
    show_menu();

    while (true)
    {
        if (selection == "0")
        {
            showtitle();
            show_menu();
        }
        else if (selection == "1")
        {
            showtitle();
            sort();
            saved();
        }
        else if (selection == "2")
        {
            showtitle();
            add();
        }
        else if (selection == "3")
        {
            showtitle();
            search();
            if (cancel)
            {
                selection = "0";
                continue;
            }
            cout << "\n\nPress 0 to back to main menu .. or press 3 to research .. \n";
            cin >> selection;
            while (selection != "0" && selection != "3")
            {
                invalid_input();
                cin >> selection;
            }
        }
        else if (selection == "4")
        {
            showtitle();
            delete_menu();
        }
        else if (selection == "5")
        {
            showtitle();
            update();
        }
        else if (selection == "6")
        {
            sort();
            write();
            showtitle();
            color(11);
            cout << "\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t   Thank you for using our App\n\n\n";
            color(7);
            return 0;
        }
        else
        {
            showtitle();
            show_menu();
        }
    }

    return 0;
}