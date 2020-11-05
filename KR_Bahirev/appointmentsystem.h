#ifndef APPOINTMENTSYSTEM_H
#define APPOINTMENTSYSTEM_H
#include "appointment.h"
#include "iostream"


#include <vector>
using namespace std;
class AppointmentSystem
{
public:
    AppointmentSystem(vector<Appointment> appointments);
    bool validate();
    vector<Appointment> appointments;
    bool addAppointment(Appointment appointment);
    bool removeAppointment(Date date);
    wstring toString();
    wstring toString(Date date);
    wstring toFile();
};

#endif // APPOINTMENTSYSTEM_H
