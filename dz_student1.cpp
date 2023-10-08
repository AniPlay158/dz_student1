#include <iostream>
using namespace std;

class Student
{
private:
	string surname;
	string name;
	string patronymic;
	string adress;
	string phone_number;

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    int* practice_rates = nullptr;
    int practice_rates_count = 0;

    int* exam_rates = nullptr;
    int exam_rates_count = 0;

public:

    void SetName(string name)
    {
        this->name = name;
    }

    string GetName() const
    {
        return name;
    }

    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    string GetSurname() const
    {
        return surname;
    }

    void SetPatronymic(string patronymic)
    {
        this->patronymic = patronymic;
    }

    string GetPatronymic() const
    {
        return patronymic;
    }

    void SetAdress(string adress)
    {
        this->adress = adress;
    }

    string GetAdress() const
    {
        return adress;
    }

    void SetPhoneNumber(string phone_number)
    {
        this->phone_number = phone_number;
    }

    string GetPhoneNumber() const
    {
        return phone_number;
    }

    Student()
    {
        SetSurname("Garfield");
        SetName("Andrew");
        SetPatronymic("Russell");
        SetAdress("Baker street 221b");
        SetPhoneNumber("617-254-8039");
    }

    Student(string name) : Student(name, "Labida", "Oda", "Shkolnaya 987", "037-522-6725"){}

    Student(string name, string surname, string patronymic, string adress, string phone_number)
    {
        SetSurname(name);
        SetName(surname);
        SetPatronymic(patronymic);
        SetAdress(adress);
        SetPhoneNumber(phone_number);
    }

    ~Student()
    {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if(practice_rates != nullptr)
        {
            delete[] practice_rates;
            practice_rates = nullptr;
        }
        if (exam_rates != nullptr)
        {
            delete[] exam_rates;
            exam_rates = nullptr;
        }
    }

    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12"<<endl;
            throw "ERROR!";
        }

        if (hometask_rates_count == 0)
        {
            cout << "Add first rate!"<<endl;
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another rate"<<endl;
            int* temp = new int[hometask_rates_count+1];
            for (int i = 0; i < hometask_rates_count; i++)
            {
                temp[i] = hometask_rates[i];
                temp[i + 1] = rate;
            }
            delete[] hometask_rates;
            hometask_rates = temp;
        }

        hometask_rates_count++;
    }

    int GetHometasksRatesCount() const
    {
        return hometask_rates_count;
    }

    int* GetHometaskRates() const
    {
        return hometask_rates;
    }

    void AddPracticRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12" << endl;
            throw "ERROR!";
        }

        if (practice_rates_count == 0)
        {
            cout << "Add first rate!" << endl;
            practice_rates = new int[1];
            practice_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another rate" << endl;
            int* temp = new int[practice_rates_count + 1];
            for (int i = 0; i < practice_rates_count; i++)
            {
                temp[i] = practice_rates[i];
                temp[i + 1] = rate;
            }
            delete[] practice_rates;
            practice_rates = temp;
        }

        practice_rates_count++;
    }

    int GetPracticetasksRatesCount() const
    {
        return practice_rates_count;
    }

    int* GetPracticetasksRates() const
    {
        return practice_rates;
    }

    void AddExamRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12" << endl;
            throw "ERROR!";
        }

        if (exam_rates_count == 0)
        {
            cout << "Add first rate!" << endl;
            exam_rates = new int[1];
            exam_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another rate" << endl;
            int* temp = new int[exam_rates_count + 1];
            for (int i = 0; i < exam_rates_count; i++)
            {
                temp[i] = exam_rates[i];
                temp[i + 1] = rate;
            }
            delete[] exam_rates;
            exam_rates = temp;
        }

        exam_rates_count++;
    }


    int GetExamtasksRatesCount() const
    {
        return exam_rates_count;
    }

    int* GetExamtaskRates() const
    {
        return exam_rates;
    }

    void PrintHomeTaskRates()
    {
        for (int i = 0; i < hometask_rates_count; i++)
        {
            cout << i+1 << ")" << hometask_rates[i]<<endl;
        }
    }
    void PrintPracticeTaskRates()
    {
        for (int i = 0; i < practice_rates_count; i++)
        {
            cout << practice_rates_count << ")" << practice_rates[i]<<endl;
        }
    }
    void PrintExamTaskRates()
    {
        for (int i = 0; i < exam_rates_count; i++)
        {
            cout << exam_rates_count << ")" << exam_rates[i]<<endl;
        }
    }

    void Print()
    {
        cout << "Surname: " << surname << endl;
        cout << "Nane: " << name << endl;
        cout << "Patronymic: " << patronymic << endl;
        cout << "Adress: " << adress << endl;
        cout << "Phone number: " << phone_number << endl;
    }

};
class DateTime
{
private:

    int day;
    int month;
    int year;

public:

    void SetDay(int day)
    {
        if (day > 0 && day < 31)
        {
            this->day = day;
        }
        else
            cout << "Invalid value!" << endl;
    }
    int GetDay() const
    {
        return day;
    }

    void SetMonth(int month)
    {
        if (month > 0 && month <= 12)
        {
            this->month = month;
        }
        else
            cout << "Invalid value!" << endl;
    }
    int GetMonth() const
    {
        return month;
    }

    void SetYear(int year)
    {
        if (year > 0 && year <= 2017)
        {
            this->year = year;
        }
        else
            cout << "Invalid value!" << endl;
    }
    int GetYear() const
    {
        return year;
    }

    DateTime()
    {
        SetDay(23);
        SetMonth(03);
        SetYear(2005);
    }

    DateTime(int day, int month) : DateTime( day, month, 2004){}

    DateTime(int day, int month, int year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }

    void Print()
    {
        cout << "Birthday day: " << day << "." << month << "." << year << endl;
    }
};

int main()
{
    Student s1;
    Student s2("Alex");
    Student s3("Andrey", "Kozin", "Bond", "Laminaria 12", "235-621-4566");
    DateTime d1;
    DateTime d2(2, 05);
    DateTime d3(18, 07, 2003);

    cout << "----------------------" << endl;
    s1.Print();
    d1.Print();
    cout << "----------------------" << endl;

    cout << "Rate for home tasks: " << endl;
    s1.AddHometaskRate(10);
    s1.PrintHomeTaskRates();
    s1.AddHometaskRate(11);
    s1.PrintHomeTaskRates();
    s1.AddHometaskRate(12);
    s1.PrintHomeTaskRates();
    cout << endl;

    cout << "Rate for practice tasks: " << endl;
    s1.AddPracticRate(11);
    s1.PrintPracticeTaskRates();
    s1.AddPracticRate(11);
    s1.PrintPracticeTaskRates();
    s1.AddPracticRate(12);
    s1.PrintPracticeTaskRates();
    cout << endl;

    cout << "Rate for exam tasks: " << endl;
    s1.AddExamRate(10);
    s1.PrintExamTaskRates();
    s1.AddExamRate(11);
    s1.PrintExamTaskRates();
    cout << endl;

   

}