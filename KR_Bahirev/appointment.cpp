#include "appointment.h"


Appointment::Appointment(Date date, Patient patient)
{
    this->date = date;
    this->patient = patient;
}

Appointment::Appointment()
{
    this->date = Date();
    this->patient = Patient();
}

bool Appointment::comp(Appointment a, Appointment b)
{
    return Date().comp(a.date, b.date);
}

wstring Appointment::toString()
{
    return L"Дата: " + date.toString() + L"\nПациент: " + patient.toString();

}
