#include "appointmentsystem.h"
#include <algorithm>
#include "appointment.h"

AppointmentSystem::AppointmentSystem(vector<Appointment> appointments)
{
    this->appointments = appointments;
}

bool AppointmentSystem::validate()
{
    for (int i = 0; i < appointments.size(); i++) {
        for (int j = i + 1; j < appointments.size(); j++) {
            if (appointments[i].date.equals(appointments[j].date)) {
                return false;
            }
        }
    }
    return true;
}

bool AppointmentSystem::addAppointment(Appointment appointment)
{
    for (int i = 0; i < appointments.size(); i++) {
        if (appointments[i].date.equals(appointment.date)) {
            return false;
        }
    }
    appointments.push_back(appointment);
    sort(appointments.begin(), appointments.end(), appointment.comp);
    return true;
}

bool AppointmentSystem::removeAppointment(Date date)
{
    for (int i = 0; i < appointments.size(); i++) {
        if (appointments[i].date.equals(date)) {
            appointments.erase(appointments.begin() + i);
            return true;
        }
    }
    return false;
}

wstring AppointmentSystem::toString()
{
    sort(appointments.begin(), appointments.end(), Appointment().comp);
    wstring result = L"Список записи:\n\n";
    for (int i = 0; i < appointments.size(); i++) {
        result += appointments[i].toString() + L"\n\n";
    }
    return result;
}

wstring AppointmentSystem::toString(Date date)
{
    sort(appointments.begin(), appointments.end(), Appointment().comp);
    wstring result = L"Список записи на "
        + to_wstring(date.day) + L"/" + to_wstring(date.month) + L"/"
        + to_wstring(date.year) + L":\n\n";

    for (int i = 0; i < appointments.size(); i++) {
        Date temp = appointments[i].date;
        if (temp.day == date.day && temp.month == date.month && temp.year == date.year) {
            result += appointments[i].toString() + L"\n\n";
        }
    }
    return result;
}

wstring AppointmentSystem::toFile()
{
    wstring result = L"";
    for (int i = 0; i < appointments.size(); i++) {
        Appointment a = appointments[i];
        result += a.patient.surname + L" " + a.patient.name + L" " + a.patient.fatherName + L" " + a.patient.policy +
            +L" " + to_wstring(a.date.year) + L" " + to_wstring(a.date.month) +
            L" " + to_wstring(a.date.day) + L" " + to_wstring(a.date.hour) + L"\n";
    }
    result += L"end_line\n";
    return result;
}


