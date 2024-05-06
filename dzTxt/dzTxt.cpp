
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    //  #1--------------------------------------------------------------

    FILE* file = nullptr;
    fopen_s(&file, "task1.txt", "w");
    if (file == NULL) cout << "Error!";
    else 
    {
        int j = 0;
        cout << "Enter int number - ";
        cin >> j;
        for(int i = 0;i<5;i++)
        {
            fprintf(file, "%d ", j);
        }
        fprintf(file, "\n");
        
        float part2 = 0;
        cout << "Enter double number - ";
        cin >> part2;
        for (int i = 0; i < 5; i++)
        {
            fprintf(file, "%f ", part2);
        }
        fprintf(file, "\n");
        char part3[20] = "";
        cout << "Enter word - ";
        cin >> part3;
        for (int i = 0; i < 5; i++)
        {
            fprintf(file, "%s ", part3);
        }
        cout << "Done!";
    }

    //  #2--------------------------------------------------------------

    FILE* file = nullptr;
    fopen_s(&file, "task2.txt", "w");
    if (file == NULL) cout << "Error!";
    else 
    {
        int fib1 = 1, fib2 = 1;
        for (int i = 0; i < 6; i++) 
        {
            fprintf(file, "%d %d ", fib1,fib2);
            fib1 = fib1 + fib2;
            fib2 = fib1 + fib2;
        }
        cout << "Done!";
    }

    //  #3--------------------------------------------------------------

    FILE* file = nullptr;
    fopen_s(&file, "hw1.txt", "r");
    if (file == NULL) cout << "Error!";
    else
    {
        int a = 0;
        cout << "Enter a - ";
        cin >> a;
        for (int i = 0; i < 13; i++)
        {
            int b = 0;
            fscanf_s(file, "%d ", &b);
            if (b > a) cout << b << " ";
        }
    }

    //  #4--------------------------------------------------------------

    FILE* file = nullptr;
    fopen_s(&file, "hw1.txt", "r");
    if (file == NULL) cout << "Error!";
    else 
    {
        int* arr = nullptr,numPositive=0;
        for (int i = 0; i < 13; i++)
        {
            int a = 0;
            fscanf_s(file, "%d ", &a);
            if (a > 0) numPositive++;
        }
        
        arr = new int[numPositive];
        fseek(file,0, SEEK_SET);
        for (int i = 0,j=0; i < 13; i++)
        {
            int a = 0;
            fscanf_s(file, "%d ", &a);
            if (a > 0) {
                arr[j]=a;
                j++;
            }
        }
        printArray(arr, numPositive);
    }

    //  #5--------------------------------------------------------------

    FILE* file = nullptr,*toSave=nullptr;
    fopen_s(&file, "hw1.txt", "r");
    fopen_s(&toSave, "toSave.txt", "w");
    if (file == NULL || toSave == NULL) cout << "Error!";
    else
    {
        int without = 0;
        cout << "enter number, which you need'nt - ";
        cin >> without;
        cout << "hw1.txt : " << endl;
        while (!feof(file)) 
        {
            int a = 0;
            fscanf_s(file, "%d ", &a);
            cout << a << " ";
            if(a!=without) fprintf(toSave, "%d ", a);
        }
        fclose(file);
        fclose(toSave);
        fopen_s(&toSave, "toSave.txt", "r");
        cout << "\ntoSave.txt : " << endl;
        while (!feof(toSave))
        {
            int a = 0;
            fscanf_s(toSave, "%d ", &a);
            cout << a << " ";
        }
        fclose(toSave);
    }

    //  #6--------------------------------------------------------------

FILE* input1 = nullptr, * input2 = nullptr, * sum = nullptr, * maxes = nullptr;
fopen_s(&input1, "hw1.txt", "r");
fopen_s(&input2, "hw2.txt", "r");
fopen_s(&sum, "hwSum.txt", "w");
fopen_s(&maxes, "hwMax.txt", "w");
if (input1 == NULL || input2 == NULL || sum ==NULL||maxes==NULL) cout << "Error!";
else 
{
    while (!feof(input1))
    {
        int a = 0,b=0;
        fscanf_s(input1, "%d ", &a);
        fscanf_s(input2, "%d ", &b);
        cout << a<<" + " << b<<" = " << a + b << endl;
        cout << a << " > " << b << " = " << (a > b ? "true" : "false") << endl << endl;

        fprintf(sum, "%d ", a + b);
        fprintf(maxes, "%d ", a>b ? a:b);
    }
    cout << "Done!";
    fclose(input1);
    fclose(input2);
    fclose(sum);
    fclose(maxes);
}
}
