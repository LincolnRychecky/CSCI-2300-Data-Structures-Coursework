#include<iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "PriorityQueue.hpp"
using namespace std;

int main(int argc, char *argv[]){
    
    cout << "======Main Menu======" << endl;
    cout << "1. Get Patient Information from File" << endl;
    cout << "2. Add Patient to Priority Queue" << endl;
    cout << "3. Show Next Patient" << endl;
    cout << "4. Admit Next Patient" << endl;
    cout << "5. Process Entire Queue" << endl;
    cout << "6. Quit" << endl;
    
    string choice;
    int total = 0; 
    int totalWaitTime = 0;
    PriorityQueue one (stoi(argv[1]));
    
    getline(cin, choice);
    
    while(choice != "6"){
        
        if(choice == "1"){
                
                string line;
                
                string name;
                
                string injury_Severity;
                
                string treatment_Time;
                
                string chunk;
                
                ifstream readFile; //create ofstream variable
                
                readFile.open(argv[2]);
                
                while(getline(readFile,line)){
                stringstream ss(line);   
                int i = 0;
                while(getline(ss, chunk, ' ')){
                    if(i == 0){
                        name = chunk;
                    }
                    if(i == 1){
                        injury_Severity = chunk;
                    }
                    if(i == 2){
                        treatment_Time = chunk;
                    }
                    i++;
                }
                
                one.enqueue(name, stoi(injury_Severity), stoi(treatment_Time));
                total ++;
                
                if(total == stoi(argv[1])){
                    cout << "Priority Queue full. Send remaining patients to another hospital." << endl;
                    break;
                }
            }
            
        }
        
        if(choice == "2"){
            if(total == stoi(argv[1])){
                    cout << "Priority Queue full. Send remaining patients to another hospital." << endl;
                }
            else{
                
                string name1;
                
                string injurySev;
                
                string treatTime;
                


                cout << "Enter Patient Name:" << endl;
                getline(cin, name1);
                cout << "Enter Injury Severity:" << endl;
                getline(cin, injurySev);
                cout << "Enter Treatment Time:" << endl;
                getline(cin, treatTime);
                
                one.enqueue(name1, stoi(injurySev), stoi(treatTime));
                total ++;
            }
            
        }
        
        if(choice == "3"){
            
            if(total == 0){
                cout << "Queue empty." << endl;
            }
            else{
            cout << "Patient Name: " << one.peekName() << " " << endl;
            cout << "Injury Severity: " << one.peekInjurySeverity() << " " << endl;
            cout << "Treatment Time: " << one.peekTreatmentTime() << endl;
            }
        }
        
        if(choice == "4"){
            
            if(one.isEmpty() == true || total == 0){
                cout << "Queue empty." << endl;
            }
            else{
                totalWaitTime += one.peekTreatmentTime();
                cout << "Patient Name: " <<  one.peekName() << " - Total Time Treating Patients: " << totalWaitTime << endl;
                one.dequeue();
                total --;
            }
        }
        
        if(choice == "5"){
            
            while(one.isEmpty() == false){
                
                cout << "Patient Name: " << one.peekName() << " - Total Wait Time: " << totalWaitTime + one.peekTreatmentTime() << endl;
                
                totalWaitTime += one.peekTreatmentTime();
                
                one.dequeue();
                
                total--;
                
            }
        }
        
        cout << "======Main Menu======" << endl;
        cout << "1. Get Patient Information from File" << endl;
        cout << "2. Add Patient to Priority Queue" << endl;
        cout << "3. Show Next Patient" << endl;
        cout << "4. Admit Next Patient" << endl;
        cout << "5. Process Entire Queue" << endl;
        cout << "6. Quit" << endl;
    
        getline(cin, choice);
        
    }

    cout << "Goodbye!" << endl;
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}