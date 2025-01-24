#include<iostream>
#include<vector>

using namespace std;

class airline {

public:
    vector<string> name;
    vector<string> reserved_seats;
    vector<vector<string>> details = {  {"Flight Number"},
                                        {"Source"},
                                        { "Destination"},
                                        { "Total Seats"}, 
                                        {"Booked Seats"},
                                        {"Available Seats"}};


    void add(){
        string a_number;
        string a_source;
        string a_destination;
        string a_total_seats;

        cout<<"Enter the flight number: ";
        cin>>a_number;
        cout<<"Enter the source: ";
        cin>>a_source;
        cout<<"Enter the destination: ";
        cin>>a_destination;
        cout<<"Enter the total seats: ";
        cin>>a_total_seats;

        details[0].push_back(a_number);
        details[1].push_back(a_source);
        details[2].push_back(a_destination);
        details[3].push_back(a_total_seats);
    }


    void reserve(){
        string r_name;
        string r_number;
        string r_seats;
        cout<<"Enter the name of the passenger: ";
        cin>>r_name;
        cout<<"Enter the flight number: ";
        cin>>r_number;
        cout<<"Enter the number of seats to reserve: ";
        cin>>r_seats;

        for(int i = 0; i<details[0].size(); i++){
            if(details[0][i] == r_number){
                if(details[5][i] >= r_seats){
                    details[5][i] = stoi(details[5][i]) - stoi(r_seats);
                    cout<<"Seats reserved successfully!"<<endl;
                }
                else{
                    cout<<"Seats not available!"<<endl;
                }
            }
            else{
                cout<<"Flight not found!"<<endl;
            }
        }
        
    }

    void cancellation(){
        string c_name;
        string c_number;
        cout<<"Enter the name of the passenger: ";
        cin>>c_name;
        cout<<"Enter the flight number: ";
        cin>>c_number;

        for(int i = 0; i<details[0].size(); i++){
            if(details[0][i] == c_number){
                for (int j = 0; j<name.size(); j++){
                    if(name[j] == c_name){
                        name.erase(name.begin() + j);
                        reserved_seats.erase(reserved_seats.begin() + j);
                        details[5][i] = stoi(details[5][i]) + stoi(reserved_seats[j]);
                        cout<<"Seats cancelled successfully!"<<endl;
                        break;
                    }

                }
            }      
        }
        }
        
    










};
