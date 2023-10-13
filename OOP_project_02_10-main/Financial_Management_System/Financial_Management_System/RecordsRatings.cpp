    #include "RecordsRatings.h"

    void RecordsRatings::LoadRecordsFromFile(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "File does not exist. No expense records loaded." << endl;
            return;
        }

        expenseRecords.clear();

        ExpenseRecord record;
        while (file >> record.name >> record.amount >> record.category >> record.day >> record.month) {
            expenseRecords.push_back(record);
        }

        file.close();
    }

    void RecordsRatings::PrintForDay(int searchDay) {
        cout << "\nExpense Records by day:" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Name\tAmount\tCategory\tDay" << endl;
        cout << "--------------------------------------------------------------" << endl;

        for (const ExpenseRecord& record : expenseRecords) {
            if (record.day == searchDay)
            {

                cout << record.name << "\t" << record.amount << "\t";

                switch (record.category) {
                case 1:
                    cout << "Food\t";
                    break;
                case 2:
                    cout << "Rent\t";
                    break;
                case 3:
                    cout << "Online\t";
                    break;
                case 4:
                    cout << "Other\t";
                    break;
                default:
                    cout << "Unknown\t";
                    break;
                }

                cout << "\t" << record.day << endl;
            }
            else {
                cout << "Records not found." << endl;
            }
        }

        cout << "--------------------------------------------------------------" << endl;
    }
