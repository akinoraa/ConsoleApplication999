#include <iostream>
using namespace std;

class DateTime
{
    int day;
    int month;
    int year;

public:
    void SetDay(int day)
    {
        if (day > 0 && day <= 31) // TO DO: february 28-29, april june 30
        {
            this->day = day;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    int GetDay() const
    {
        return day;
    }

    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    int GetMonth() const
    {
        return month;
    }

    void SetYear(int year)
    {
        this->year = year;
    }

    int GetYear() const
    {
        return year;
    }

    DateTime() {
        //cout << "DateTime c-tor without parameters\n";
        SetDay(11);
        SetMonth(10);
        SetYear(2023);
    }

    DateTime(int day, int month) {
        //cout << "DateTime c-tor with 2 parameters\n";
        SetDay(day);
        SetMonth(month);
        SetYear(2023);
    }

    DateTime(int day, int month, int year)
    {
        //cout << "DateTime main c-tor with 3 parameters\n";
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }

    DateTime(const DateTime& original)
    {
        //cout << "DateTime copy constructor\n";
        this->day = original.day;
        this->month = original.month;
        this->year = original.year;
    }

    ~DateTime() {
        //cout << "DateTime destructor\n";
    }

    void Print() const
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
};

class Student
{
    string name;
    string surname;
    DateTime birthday;
    DateTime study_start;
    int* hometask_rates = nullptr; // ����-��������
    int hometask_rates_count = 0;
    int* practice_rates = nullptr;
    int practice_rates_count = 0;
    int* exam_rates = nullptr;
    int exam_rates_count = 0;
public:
    static int student_count;

    bool countError()
    {
        return student_count <= 15;
    }
    void throwError()
    {
        try {
            if (countError())
                student_count++;
            else
                throw 1;
        }
        catch (int)
        {
            cout << "Student counter overloaded" << endl;
        }
    }
    Student()
    {
        SetName("Veronika");
        SetSurname("Geyna");
        SetBirthday({ 14,07,2005 });
        SetStudyStart({ 1,9,2022 });
        throwError();
    }

    void printStudent()
    {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Birthday: ";
        birthday.Print();
        cout << "Study start date";
        study_start.Print();
    }
    // �i�� �� ��� �����, ��� ������� ����i����� �� �������������
    // ���������� ���i������

    // ���� � �����i ����� � ����-��������,
    // �� ����i��� ����'������ ������� ����� ����������� ���i������
    // � ����� �i� ��i ����-��������� ���� ���i���� ������ ���� �I����� ���'��I
    Student(const Student& original)
    {
        this->name = original.name;
        this->surname = original.surname;
        this->birthday = original.birthday;
        this->study_start = original.study_start;

        // ������� ��������� ���I������
        this->hometask_rates_count = original.hometask_rates_count;

        // ��� ���i�-��������i� ���� ������� ���, ���� ���i��� ���� ���'���!!!!
        this->hometask_rates = new int[this->hometask_rates_count];
        // ���� ���i���� ���'��, ii ����i��� �� � ���i�i�i��i������!!!
        for (int i = 0; i < this->hometask_rates_count; i++)
        {
            this->hometask_rates[i] = original.hometask_rates[i];
        }
        throwError();
    }

    ~Student()
    {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
    }
    void SetName(string name)
    {
        this->name = name;
    }

    string GetName() const
    {
        return name;
    }

private:

    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

public:

    DateTime GetBirthday() const
    {
        return birthday;
    }

    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }
    DateTime GetStudyStart() const
    {
        return study_start;
    }

    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    string GetSurname() const
    {
        return surname;
    }

    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[hometask_rates_count + 1];
            for (int i = 0; i < hometask_rates_count; i++)
                temp[i] = hometask_rates[i];
            temp[hometask_rates_count] = rate;
            delete[] hometask_rates;
            hometask_rates = temp;
        }
        hometask_rates_count++;
    }

    void PrintHometaskRates() const
    {
        cout << "Hometasks rates: ";
        for (int i = 0; i < hometask_rates_count; i++)
        {
            cout << hometask_rates[i] << ", ";
        }
        cout << "\n";
    }

    int GetHometaskRateByIndex(unsigned int index)
    {
        if (index >= hometask_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return hometask_rates[index];
    }

    int GetHometasksRatesCount() const
    {
        return hometask_rates_count;
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

    int GetPracticeRateByIndex(unsigned int index)
    {
        if (index >= practice_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return practice_rates[index];
    }

    int GetPracticetasksRatesCount() const
    {
        return practice_rates_count;
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

    int GetExamRateByIndex(unsigned int index)
    {
        if (index >= exam_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return exam_rates[index];
    }

    void PrintPracticeTaskRates() const
    {
        for (int i = 0; i < practice_rates_count; i++)
        {
            cout << practice_rates_count << ")" << practice_rates[i] << endl;
        }
    }
};
class Group
{
    Student* group;
    int groupSize, courseN;
    string groupName, specialty;
public:
    static int group_count;

    bool countError()
    {
        return group_count <= 15;
    }
    void throwError()
    {
        try {
            if (countError())
                group_count++;
            else
                throw 1;
        }
        catch (int)
        {
            cout << "Group counter overloaded" << endl;
        }
    }
    Group() : Group(0) { throwError(); }

    Group(int groupSize)
    {
        this->groupSize = groupSize;
        courseN = 1;
        groupName = "KN-0";
        specialty = "Designer";
        group = new Student[groupSize];
        throwError();
    }

    Group(const Group& obj)
    {
        this->group = new Student[obj.groupSize];
        this->groupSize = obj.groupSize;
        this->courseN = obj.courseN;
        this->groupName = obj.groupName;
        this->specialty = obj.specialty;
        for (int i = 0; i < obj.groupSize; i++)
            this->group[i] = obj.group[i];
        throwError();
    }

    void printGroup()
    {
        cout << "Group name: " << groupName << endl;
        cout << "Specialty: " << specialty << endl;
        int f;
        Student temp;
        for (int i = 1; i < groupSize; i++)
        {
            f = 0;
            for (int r = 0; r < groupSize - i; r++)
            {
                if (group[r].GetSurname() > group[r + 1].GetSurname())
                {
                    temp = group[r];
                    group[r] = group[r + 1];
                    group[r + 1] = temp;
                    f = 1;
                }
            }
            if (f == 0)
            {
                break;
            }
        }
        for (int i = 0; i < groupSize; i++)
        {
            cout << i + 1 << ' ' << group[i].GetSurname() << ' ' << group[i].GetName();
            cout << endl;
        }
    }

    int getGroupSize() const
    {
        return groupSize;
    }
    Student getStudentByIndex(int index)const
    {
        return group[index];
    }
    void AddStudent(const Student& new_student)
    {
        Student* tmp = new Student[groupSize + 1];
        for (int i = 0; i < groupSize; i++)
            tmp[i] = group[i];

        tmp[groupSize] = new_student;

        delete[] group;
        group = tmp;
        groupSize++;
    }


    void MergeWithGroup(Group& another_group)
    {
        for (int i = 0; i < another_group.getGroupSize(); i++)
        {
            this->AddStudent(another_group.getStudentByIndex(i));
        }

        int k = another_group.getGroupSize();
        for (int i = 0; i < k; i++)
        {
            another_group.DeleteTheWorstStudent();
        }
    }

    void TransferStudent(Group& other, int index)
    {
        if (index >= 0 && index < groupSize)
        {
            other.AddStudent(group[index]);
            for (int i = index; i < groupSize - 1; i++)
                group[i] = group[i + 1];
            groupSize--;
        }
    }

    void DeleteFailedStudents()
    {
        int failedExams = 0, newSize = 0;
        for (int i = 0; i < groupSize; i++)
        {
            if (!(group[i].GetExamRateByIndex(i) > 4))//pass-grade is 4
                failedExams++;
        }
        newSize = failedExams;
        Student* tmp = new Student[groupSize + 1];
        for (int i = 0, j = 0; i < groupSize; i++)
        {
            if (group[i].GetExamRateByIndex(i))
            {
                tmp[j] = group[i];
                j++;
            }
        }
        delete[]group;
        group = tmp;
        groupSize -= failedExams;
    }
    void DeleteTheWorstStudent()
    {
        int worst = 0, tmp1 = 0, first = 0, index = 0;
        Student* tmp = new Student[groupSize - 1];
        for (int i = 0; i < groupSize; i++)
        {
            int gradesCount = group[i].GetHometasksRatesCount();
            for (int j = 0; j < gradesCount; i++)
                tmp1 = group[i].GetHometaskRateByIndex(j);
            if (gradesCount > 0 && first == 0)
            {
                worst = tmp1 / gradesCount;
                index = i;
            }
            else if (gradesCount > 0 && first > 0)
            {
                worst = (tmp1 / gradesCount) < worst ? (tmp1 / gradesCount) : worst;
                index = i;
            }
            tmp1 = 0;
            first++;
        }
        for (int i = 0; i < groupSize; i++)
        {
            if (i < index)
                tmp[i] = group[i];
            else if (i == index)
                continue;
            else
                tmp[i - 1] = group[i];
        }
        delete[]group;
        group = tmp;
    }
};
int Student::student_count = 0;
int Group::group_count = 0;
int main()
{

    Student original;
    for (int i = 0; i < 20; i++)
    {
        Student();
    }
    Group one, two, three;
    //1
    one.printGroup();
    cout << endl;
    //2
    one.AddStudent(original);
    one.AddStudent(original);

    one.printGroup();
    cout << endl;

    //3
    two.AddStudent(original);
    one.TransferStudent(two, 0);
    cout << endl;
    one.printGroup();
    two.printGroup();
    cout << endl;

}