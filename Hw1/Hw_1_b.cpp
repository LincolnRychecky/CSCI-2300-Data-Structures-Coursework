#include <iostream> //cin, cout, endl
#include <fstream> //ifstream
#include <string> //string
#include <sstream> //stringstream
#include <vector> //vector
//command line notes

//g++ -std=c++11 (name of file.cpp) -o (what you want it to be called "cmdarg_program")
//./(NAME OVF ALLIAS) input input input, etc...
//always have to recompile after changing code
//int main(int argc, char* argv[])
using namespace std;

struct student
{
    string username;
    float gpa;
    int age;
};

void addUser(vector<student> &gradeList, string name, float _gpa, int _age){
    
    student s1;
    
    s1.username = name;
    
    s1.gpa = _gpa;
    
    s1.age = _age;
    
    gradeList.push_back(s1);
    
}

void printList(const vector<student> &gradeList){
    
    string u_Name;
    
    float grade_Point;
    
    int age_Of;
    
    for(int i = 0; i < gradeList.size(); i++){
        
        u_Name = gradeList[i].username;
        
        grade_Point = gradeList[i].gpa;
        
        age_Of = gradeList[i].age;
        
        cout << u_Name << " [" << grade_Point << "]" << " age: " << age_Of << endl;
        
    }
    
}

int main(int argc, char* argv[]) {
   
   ifstream writeFile; //create ifstream variable
   writeFile.open(argv[1]); //open the file specified in the command line argument
   
   string tempString; //holding string
   
   vector <student> graList;
   
   string uName;
   string tempGpa;
   string tempAge;
   float gpa_;
   int age;
   
   while(getline(writeFile, tempString)){
       
       stringstream ss(tempString);
       
       getline(ss, uName, ',');
       
       getline(ss, tempGpa, ',');
       
       getline(ss, tempAge, ',');
       
       gpa_ = stof(tempGpa);
       
       age = stoi(tempAge);
       
       addUser(graList,uName,gpa_, age);
       
   }
   
   printList(graList);
   
   writeFile.close();
   
 return 0;
}