#include <iostream>
#include "List.h"
using namespace std;

int main() 
{
    List<int> list;
    int choice;
    do 
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add element (head)" << endl;
        cout << "2. Add element (tail)" << endl;
        cout << "3. Delete element (head)" << endl;
        cout << "4. Delete element (tail)" << endl;
        cout << "5. Delete all elements" << endl;
        cout << "6. Show all elements" << endl;
        cout << "7. Insert element at a position" << endl;
        cout << "8. Delete element from a position" << endl;
        cout << "9. Find element" << endl;
        cout << "10. Replace element value" << endl;
        cout << "11. Reverse the list" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            list.AddToHead(value);
            break;
        }
        case 2: 
        {
            int value;
            cout << "Enter value: ";
            cin >> value;
            list.AddToTail(value);
            break;
        }
        case 3:
            list.DeleteFromHead();
            break;
        case 4:
            list.DeleteFromTail();
            break;
        case 5:
            list.DeleteAll();
            break;
        case 6:
            list.Show();
            break;
        case 7: 
        {
            int position, value;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;
            list.InsertAt(position, value);
            break;
        }
        case 8: 
        {
            int position;
            cout << "Enter position: ";
            cin >> position;
            list.DeleteAt(position);
            break;
        }
        case 9: 
        {
            int value;
            cout << "Enter value to find: ";
            cin >> value;
            int position = list.Find(value);
            if (position != -1) 
            {
                cout << "Element found at position: " << position << endl;
            }
            else 
            {
                cout << "Element not found." << endl;
            }
            break;
        }
        case 10: 
        {
            int oldValue, newValue;
            cout << "Enter value to replace: ";
            cin >> oldValue;
            cout << "Enter new value: ";
            cin >> newValue;
            int count = list.Replace(oldValue, newValue);
            if (count != -1) 
            {
                cout << "Replaced elements: " << count << endl;
            }
            else 
            {
                cout << "Element not found." << endl;
            }
            break;
        }
        case 11:
            list.Reverse();
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}