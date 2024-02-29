#include "Catalog.h"

// Include memory leak detection - configured in global_config.h
#ifdef MEMORY_LEAK_ON
#include "LeakWatcher.h"
#endif

void Catalog::Insert(InfoType* ins)
{
    InfoType temp = *ins;
    
    if (InfoTypeCatalog.Insert(ins))
        cout << "Added to list:     " << temp << endl;
    else
        cout << "Already in list:   " << temp << endl;
}

void Catalog::Delete(const InfoType& x)
{
    if (InfoTypeCatalog.Delete(x))
        cout << "Deleted from list: " << x << endl;
    else
        cout << "Wasn't in list:    " << x << endl;
}

void Catalog::DisplayList()
{
    cout << "Below are the fruits currently in the list\n";
    InfoTypeCatalog.Display(cout);
    //cout << endl;
}

void Catalog::Run()
{
    // main algoirthm
    // 1. read in number of fruit items
    int num_items;
    cin >> num_items;
    cout << "There are " << num_items << " types of fruits initially in the list.\n";
    cout << "They will be read in and inserted in the list in order.\n";

    // read in the number of fruit items
    for (int i = 0; i < num_items; i++)
    {
        InfoType* temp = new InfoType;
        cin >> (*temp);
        Insert(temp);
    }
    cout << endl;

    // now we can respond to input commands, start with reading the first command
    char inCode; cin >> inCode;
    while (inCode != 'S')
    {
        switch (inCode)
        {
        case 'P':
            //cout << endl;
            DisplayList();
            break;
        case 'I':
        {
            //cout << endl;
            InfoType temp;
            cin >> temp;
            InfoType *tmp = new InfoType(temp);
            Insert(tmp);
            break;
        }
        case 'D':
        {
            InfoType temp;
            cin >> temp;
            Delete(temp);
            break;
        }
        default:
            cout << "Invalid command!\n";
        }

        // get the next code
        cin >> inCode;
        cout << endl;
    }

    cout << "Normal Termination of program 2!\n";
}