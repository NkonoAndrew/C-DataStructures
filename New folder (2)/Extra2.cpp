#include <iostream>

using namespace std;

bool canMakeTotal(int values[], int numValues, int total) {

    if (total == 0)

        return true;

    if (numValues == 0 && total != 0)

        return false;

    if (values[numValues-1] > total)

        return canMakeTotal(values, numValues-1, total);

        return canMakeTotal(values, numValues-1, total) ||

  canMakeTotal(values, numValues-1, total-values[numValues-1]);

}

int main()

{

int values[] = {3, 34, 4, 12, 5, 2, 7, 6, 3};

int total = 16;

int numValues = 9;

    if (canMakeTotal(values, numValues, total) == true)

      cout << "\n Found a subset with given total";

    else

      cout << "\n No subset with given total";

return 0;

}

