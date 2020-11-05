#include "patient.h"

Patient::Patient(wstring surname, wstring name, wstring fatherName, wstring policy)
{
    this->surname = surname;
    this->name = name;
    this->fatherName = fatherName;
    this->policy = policy;
}

Patient::Patient()
{
    this->surname = L"surname";
    this->name = L"name";
    this->fatherName = L"fatherName";
    this->policy = L"policy";
}

wstring Patient::toString()
{
    return surname + L" " + name + L" " + fatherName + L" ¹" + policy;
}
