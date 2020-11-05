#ifndef PATIENT_H
#define PATIENT_H

#include <string>


using namespace std;
class Patient
{
public:
    Patient(wstring surname, wstring name, wstring fatherName, wstring policy);
    Patient();
    wstring name;
    wstring fatherName;
    wstring surname;
    wstring policy;
    wstring toString();
};

#endif // PATIENT_H
