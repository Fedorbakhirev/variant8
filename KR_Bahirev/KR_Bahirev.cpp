﻿#include <iostream>
#include <fstream>
#include <vector>
#include "appointmentsystem.h"
#include <filesystem>
using namespace std;
int main()
{
    setlocale(LC_ALL, ".866");

    AppointmentSystem system = AppointmentSystem(vector<Appointment>(0));
    wstring instructions = L"Добро пожаловать!\n"
        "Чтобы считать данные с файла, введите:\n\"read <имя файла (только англ)>\".\n\n"
        "Чтобы ввести данные через консоль, введите данные в формате:\n"
        "\"<Фамилия> <Имя> <Отчество> <Номер полиса> <Год> <Месяц> <День> <Час>\""
        "\nдля каждой записи. Введите \"end_line\" для завершения.\n";
    wcout << instructions;
    wstring temp;
    wcin >> temp;
    wstring surname, name, fathername, policy;
    int year, month, day, hour;
    if (temp == L"read") {
        string filename;
        cin >> filename;
        wifstream  win(filename);
        system = AppointmentSystem(vector<Appointment>(0));
        setlocale(LC_ALL, ".1251");
        win >> temp;
        while (temp != L"end_line") {
            surname = temp;
            win >> name >> fathername >> policy >> year >> month >> day >> hour;
            Date date = Date(year, month, day, hour);
            Patient patient = Patient(surname, name, fathername, policy);
            Appointment appointment = Appointment(date, patient);
            if (!system.addAppointment(appointment)) {
                wcout << L"Ошибка. Время записи уже занято.\n";
            }
            win >> temp;
        }
        setlocale(LC_ALL, ".866");
    }
    else {
        system = AppointmentSystem(vector<Appointment>(0));

        while (temp != L"end_line") {
            surname = temp;
            wcin >> name >> fathername >> policy >> year >> month >> day >> hour;
            Date date = Date(year, month, day, hour);
            Patient patient = Patient(surname, name, fathername, policy);
            Appointment appointment = Appointment(date, patient);
            if (!system.addAppointment(appointment)) {
                wcout << L"Ошибка. Время записи уже занято.\n";
            }
            wcin >> temp;
        }
    }
    if (system.validate()) {
        wcout << L"Данные прошли проверку. Текущая таблица:\n";
        wcout << system.toString();
    }

    instructions = L"Чтобы добавить запись, введите:\n"
        "\"add <Фамилия> <Имя> <Отчество> <Номер полиса> <Год> <Месяц> <День> <Час>\"\n\n"
        "Чтобы удалить запись, введите:\n"
        "\"remove <Год> <Месяц> <День> <Час>\"\n\n"
        "Чтобы вывести все записи, введите:\n"
        "\"print all\"\n\n"
        "Чтобы вывести записи за день, введите:\n"
        "\"print <Год> <Месяц> <День>\"\n\n"
        "Чтобы сохранить в файл, введите:\n"
        "\"save <имя файла (только англ)>\"\n\n"
        "Чтобы выйти, введите:\n"
        "\"quit\"\n";
    wcout << instructions;
    wstring cmd;
    while (wcin >> cmd && cmd != L"quit") {
        if (cmd == L"add") {
            wcin >> surname >> name >> fathername >> policy >> year >> month >> day >> hour;
            Date date = Date(year, month, day, hour);
            Patient patient = Patient(surname, name, fathername, policy);
            Appointment appointment = Appointment(date, patient);
            if (!system.addAppointment(appointment)) {
                wcout << L"Ошибка. Время записи уже занято.\n";
            }
            else {
                wcout << L"Успешно.\n";
            }
        }
        else if (cmd == L"remove") {
            wcin >> year >> month >> day >> hour;
            Date date = Date(year, month, day, hour);
            if (!system.removeAppointment(date)) {
                wcout << L"Ошибка. Записи не существует.\n";
            }
            else {
                wcout << L"Успешно.\n";
            }
        }
        else if (cmd == L"print") {
            wcin >> temp;
            if (temp == L"all") {
                wcout << system.toString();
            }
            else {
                year = std::stoi(temp);
                wcin >> month >> day;
                Date date = Date(year, month, day);
                wcout << system.toString(date);
            }
        }
        else if (cmd == L"save") {
            setlocale(LC_ALL, ".1251");
            string filename;
            cin >> filename;
            wofstream  wout(filename);
            wout << system.toFile();
            wout.close();
            wcout << L"Успешно.\n";
            setlocale(LC_ALL, ".866");
        }
    }

}