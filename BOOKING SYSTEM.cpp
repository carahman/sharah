#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdio>

using namespace std; // THIS IS IMPROVISED CODE //

//use glo for global variable
string glo_name, glo_id, glo_room, glo_date;
int glo_startTime, glo_endTime;

int UserIdentity(string name,string id);
int NewBooking(string name, string id, int option, string date, int startTime, int endTime, string room);
int EditBooking(string glo_name, string glo_id, string glo_room, string glo_date, int glo_startTime, int glo_endTime);
int ListBooking(string glo_name, string glo_id, string glo_room, string glo_date, int glo_startTime, int glo_endTime);
void DeleteBooking();
void MultipleBooking();

int main() //this is the main function
{
    int process=0, option=0, startTime=0, endTime=0, choice;
    string date;
    string name, room, id;

    cout << "\n ###############################################################################################################";
    cout << "\n ########################################## UNIMY ROOM BOOKING SYSTEM ##########################################";
    cout << "\n ###############################################################################################################";

    cout << "\n\nHi, welcome to UNIMY Room Booking System.\nPlease enter your identity information to proceed.\n";

    for(int x=0;x<1;x++){ //this loop is for identity clarification; only UNIMY pupils can access this system.
        cout << "\nYour Identity: \n";
        cout << " 1. UNIMY Staff" << endl;
        cout << " 2. UNIMY Student" << endl;
        cout << " 3. UNIMY Lecturer" << endl;
        cout << " 4. None of the above" << endl;
        cin >> choice;
        //user choose the option of choice to identified their identity
        if (choice==1){
            cout << "Your identity is UNIMY Staff"<< endl;
        }
        else if(choice==2){
            cout << "Your identity is UNIMY Student "<< endl;
        }
        else if(choice==3){
            cout << "Your identity is UNIMY Lecturer "<< endl;
        }
        else{
            cout << "USER ERROR! Only UNIMY Pupils can access to this system." << endl;
            x-=1;
        }
}
    UserIdentity(name,id); //calling back return value in the UserIdentity() function

    for(int i=0;i=true;i++){
        cout << "\nPlease choose the process.\n";
        cout << " 1. New Booking" << endl;
        cout << " 2. Edit Booking" << endl;
        cout << " 3. List Booking" << endl;
        cout << " 4. Delete Booking" << endl;
        cout << " 5. Add Booking" << endl;
        cout << " 6. Multiple Booking" << endl; //using array to store multiple data
        cout << " 7. Exit" << endl;
        cin >> process;

        if (process==1){ //this change of variable is referring to the task preferred to do by the user.
            NewBooking(name,id, option,date,startTime,endTime,room);
        }
        else if (process==2){
            EditBooking(glo_name, glo_id, glo_room, glo_date, glo_startTime, glo_endTime);
        }
        else if (process==3){
            ListBooking(glo_name, glo_id, glo_room, glo_date, glo_startTime, glo_endTime);
        }
        else if (process==4){
            DeleteBooking();
        }
        else if (process==5){
            NewBooking(name,id,option,date,startTime,endTime,room);
        }
        else if (process==6){
            MultipleBooking();
        }
        else if (process==7){
            cout << "\nPlease come again, thank you." << endl;
            return 0;
        }
        else{
            cout << "Please enter the right choice.\n";
        }
    }
}
int UserIdentity(string name, string id) //this function is for user to key in the personal information
{
    cout << "\nPlease enter your name: ";
    cin >> name;
    cout << "Please enter your id  : ";
    cin >> id;
    glo_name = name;
    glo_id = id;
}
int NewBooking(string name, string id, int option,  string date, int startTime, int endTime, string room)
{ //this function is to take the input of booking from user
    cout << "\n1) Classroom\n2) Exam hall\n3) Auditorium\n4) Meeting Room\n5) Computer Lab\n" << endl;
    cout << "Which room do you prefer : ";
    cin >> option;

    switch(option){
    case 1:
        glo_room = "Classroom";
    break;
    case 2:
        glo_room = "Exam Hall";
    break;
    case 3:
        glo_room = "Auditorium";
    break;
    case 4:
        glo_room = "Meeting Room";
    break;
    case 5:
        glo_room = "Computer Lab";
    break;
    }

    cout << "\nPlease enter the date, time and duration preferred."<< endl;
    cout << "  Date (DD/MM/YY)    : ";
    cin >> date;
    glo_date = date;

    for (int k=0;k<1;k++){ //this loop is for valid time input
            cout << "\nNOTE: Time available only from (1000-2000 hours)\n"<< endl;
            cout << "  Start time(24 hrs format) : ";
            cin >> startTime;
            cout << "  End time(24 hrs format)   : ";
            cin >> endTime;

            if (startTime>=1000 && startTime<=2000){
                if (endTime>=1000 && endTime<=2000){
                    if(endTime!=startTime){
                        if(endTime>startTime){
                            glo_startTime = startTime;
                            glo_endTime = endTime;
                        }
                        else{
                        cout << "\nInvalid time. Start Time must be earlier than End Time.\n";
                        k-=1; //the user need to key in back the valid input
                        }
                    }
                    else{
                        cout << "\nInvalid time. Start Time cannot be same as End Time.\n";
                        k-=1;
                    }
                }
                else{
                    cout << "\nInvalid time.\n";
                    k-=1;
                }
                }
            else{
                cout << "\nInvalid time\n";
                k-=1;
                }
            }
}
int EditBooking(string name, string id, string room, string date, int startTime, int endTime)
{ //this function is for editing the booking that has been made by user
    int newoption;

    cout << "Name : " << name << endl;
    cout << "Id   : " << id << endl;
    cout << "Room : " << room << endl;
    cout << "Date : " << date << endl;
    cout << "Time : " << startTime << " to " << endTime << endl;
    //user can change the booking
    for(int j=0;j=true;j++){
        cout << "\nPlease choose the new editing.\n";
        cout << " 1. New Name" << endl;
        cout << " 2. New Id" << endl;
        cout << " 3. Room" << endl;
        cout << " 4. Date" << endl;
        cout << " 5. Time" << endl;
        cout << " 6. Done" << endl;
        cin >> newoption;

        if (newoption==1){
            cout << "Enter new name : ";
            cin >> name;
            glo_name = name;
        }
        else if (newoption==2){
            cout << "Enter new Id   : ";
            cin >> id;
            glo_id = id;
        }
        else if (newoption==3){
            cout << "\n1) Classroom\n2) Exam hall\n3) Auditorium\n4) Meeting Room\n5) Computer Lab\n" << endl;
            cout << "Which room do you prefer : ";
            cin >> newoption;

        switch(newoption){
            case 1:
                glo_room = "Classroom";
            break;
            case 2:
                glo_room = "Exam Hall";
            break;
            case 3:
                glo_room = "Auditorium";
            break;
            case 4:
                glo_room = "Meeting Room";
            break;
            case 5:
                glo_room = "Computer Lab";
            break;
    }
        }
        else if (newoption==4){
            cout << "Enter new Date(DD/MM/YY) : ";
            cin >> date;
            glo_date = date;
        }
        else if (newoption==5){
            for (int k=0;k<1;k++){ //this loop is for valid time input
            cout << "\nNOTE: Time available only from (1000-2000 hours)\n"<< endl;
            cout << "  Start time(24 hrs format) : ";
            cin >> startTime;
            cout << "  End time(24 hrs format)   : ";
            cin >> endTime;

            if (startTime>=1000 && startTime<=2000){
                if (endTime>=1000 && endTime<=2000){
                    if(endTime!=startTime){
                        if(endTime>startTime){
                            glo_startTime = startTime;
                            glo_endTime = endTime;
                        }
                        else{
                        cout << "\nInvalid time. Start Time must be earlier than End Time.\n";
                        k-=1; //the user need to key in back the valid input
                        }
                    }
                    else{
                        cout << "\nInvalid time. Start Time cannot be same as End Time.\n";
                        k-=1;
                    }
                }
                else{
                    cout << "\nInvalid time.\n";
                    k-=1;
                }
                }
            else{
                cout << "\nInvalid time\n";
                k-=1;
                }
            }
        }
        else if (newoption==6){
            return 0;
        }
        else{
            cout << "Invalid input";
        }
    }
    cout << "Name : " << glo_name << endl;
    cout << "Id   : " << glo_id << endl;
    cout << "Room : " << glo_room << endl;
    cout << "Date : " << glo_date << endl;
    cout << "Time : " << glo_startTime << " to " << glo_endTime << endl;
}
int ListBooking(string glo_name, string glo_id, string glo_room, string glo_date, int glo_startTime, int glo_endTime)
{
    cout << "Name : " << glo_name << endl;
    cout << "Id   : " << glo_id << endl;
    cout << "Room : " << glo_room << endl;
    cout << "Date : " << glo_date << endl;
    cout << "Time : " << glo_startTime << " to " << glo_endTime << endl;
}
void DeleteBooking() //show statement the booking is deleted
{
    cout << "Your booking is deleted." << endl;
}
void MultipleBooking() //using array for multiple booking
{
    int counter, size, xoption[100], xstartTime[100], xendTime[100];
    string xname, xid, xdate[100], xroom[100];

    cout << "Welcome to multiple booking option!" << endl;
    cout << "\nPlease enter your name: ";
    cin >> xname;
    cout << "Please enter your id  : ";
    cin >> xid;
    cout << "Please enter the number of booking: ";
    cin >> size;

    for(counter=0;counter<size;counter++){
        cout << "\n\nBooking " << counter+1 << " : ";
        cout << "\n1) Classroom\n2) Exam hall\n3) Auditorium\n4) Meeting Room\n5) Computer Lab\n" << endl;
        cout << "Which room do you prefer : ";
        cin >> xoption[counter];

        switch(xoption[counter]){
        case 1:
            xroom[counter] = "Classroom";
        break;
        case 2:
            xroom[counter] = "Exam Hall";
        break;
        case 3:
            xroom[counter] = "Auditorium";
        break;
        case 4:
            xroom[counter] = "Meeting Room";
        break;
        case 5:
            xroom[counter] = "Computer Lab";
        break;
        }

        cout << "\nPlease enter the date, time and duration preferred."<< endl;
        cout << "  Date (DD/MM/YY)    : ";
        cin >> xdate[counter];

        for (int z=0;z<1;z++){ //this loop is for valid time input
            cout << "\nNOTE: Time available only from (1000-2000 hours)\n"<< endl;
            cout << "  Start time(24 hrs format) : ";
            cin >> xstartTime[counter];
            cout << "  End time(24 hrs format)   : ";
            cin >> xendTime[counter];

            if (xstartTime[counter]>=1000 && xstartTime[counter]<=2000){
                if (xendTime[counter]>=1000 && xendTime[counter]<=2000){
                    if(xendTime[counter]!=xstartTime[counter]){
                        if(xendTime[counter]>xstartTime[counter]){
                        }
                        else{
                        cout << "\nInvalid time. Start Time must be earlier than End Time.\n";
                        z-=1; //the user need to key in back the valid input
                        }
                    }
                    else{
                        cout << "\nInvalid time. Start Time cannot be same as End Time.\n";
                        z-=1;
                    }
                }
                else{
                    cout << "\nInvalid time.\n";
                    z-=1;
                }
                }
            else{
                cout << "\nInvalid time\n";
                z-=1;
                }
            }
    }
    cout << endl << "BOOKING DETAILS" <<
    endl << "Name : " << xname <<
    endl << "Id   : " << xid << endl << endl;
    for(counter=0;counter<size;counter++){

        cout << "Booking " << counter+1 <<
        endl << "Room : " << xroom[counter] <<
        endl << "Date : " << xdate[counter] <<
        endl << "Time : " << xstartTime[counter] << " to " << xendTime[counter] << endl << endl;
    }
}
