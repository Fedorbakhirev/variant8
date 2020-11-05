#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "date.h"
#include "patient.h"

class Appointment
{
public:
    Appointment(Date date, Patient patient);
    Appointment();
    Date date;
    Patient patient;
    static bool comp(Appointment a, Appointment b);
    wstring toString();
    wstring toString(Date date);
};

#endif // APPOINTMENT_H
