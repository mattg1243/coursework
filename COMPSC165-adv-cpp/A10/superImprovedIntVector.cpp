#include <iostream>
#include <iomanip>

using namespace std;

class IntVector
{
    protected:
    int length, *numbers;
    
    public:
    IntVector() { numbers = nullptr; length = 0; }
    IntVector(int, int);
    ~IntVector() { if(length > 0) delete[] numbers; }
    int& at(int pos) { return numbers[pos]; }
    int size() const { return length; }
    void push_back(int);
  
   // new stuff....
    IntVector(const IntVector&);
    bool operator==(const IntVector& rhs) const
    {
        if(length == rhs.length)
            return true;
        else
            return false;
    }
    bool operator<(const IntVector& rhs) const
    {
       if (length < rhs.length)
           return true;
       else
           return false;
    }
    IntVector operator++(int);
    int& operator[](const int& i)
    {    return numbers[i];  }
    // cout << x;
    // f << x;
    friend ostream& operator<<(ostream&, const IntVector&);
    // x = y = z;
    // x = x;
    // rhs has an array and rhs has no array
    const IntVector operator=(const IntVector&);
};

class EnhancedIntVector : public IntVector {

    public:
    EnhancedIntVector() { IntVector(); };
    EnhancedIntVector(int a, int b) { IntVector(a, b); };
    double getAverage() const;
    int getHighest() const;
    int getLowest() const;
    int first() const { if (length == 0) return -1; return numbers[0]; }
    int last() const { if (length == 0) return -1; return numbers[length - 1]; }
    bool find(int val) const;

};


int main() {

    EnhancedIntVector e(42, 68);
    EnhancedIntVector f;
    e.push_back(35);
    e.push_back(1);
    e.push_back(70);
    e.push_back(25);
    e.push_back(79);
    e.push_back(59);
    e.push_back(63);
    e.push_back(65);
    
    int searchParam;
    cout << "Here are the values I added to the object: " << endl;
    cout << e << endl;
    cout << "Here are the results of calling all the methods: " << endl;
    cout << "Highest value: " << e.getHighest() << endl;
    cout << "Lowest value: " << e.getLowest() << endl;
    cout << "Average value: " << e.getAverage() << endl;
    cout << "First value: " << e.first() << endl;
    cout << "Last value: " << e.last() << endl;
    cout << "Enter a value to search for: ";
    cin >> searchParam;
    if (e.find(searchParam)) { cout << "Found it!\n"; } else { cout << searchParam << " is not in this object.\n"; }
    /* 
    cout << "Test no arr return value: \n" << f.getAverage() << endl;
    cout << f.getHighest() << endl;
    cout << f.getLowest() << endl;
    cout << f.first() << endl;
    cout << f.last() << endl;
    cout << f.find(1) << endl;
    */
}

// EnhancedIntVector methods

double EnhancedIntVector::getAverage() const {

    if (length == 0) return -1;

    double sum = 0;

    for (int i = 0; i < length; ++i) {

        sum += numbers[i];

    }

    return sum / length;
}

int EnhancedIntVector::getHighest() const {

    if (length == 0) return -1;

    int highest = numbers[0];

    for(int i = 0; i < length; ++i) {

        if(highest < numbers[i]) { highest = numbers[i]; }

    }

    return highest;
}

int EnhancedIntVector::getLowest() const {

    if (length == 0) return -1;

    int lowest = numbers[0];

    for(int i = 0; i < length; ++i) {

        if(lowest > numbers[i]) { lowest = numbers[i]; }

    }

    return lowest;
}

bool EnhancedIntVector::find(int search) const { 

    if (length == 0) return false;
    
    for(int i = 0; i < length; ++i) {

        if(numbers[i] == search) { return true; }

    }

    return false;
}


// everything below this line was copied from improvedIntVector.cpp from canvas

IntVector::IntVector(int n, int val)
{
    // create the new array of n elements
    numbers = new int[n];
    // set the length variable so the object knows
    // how long it is 
    length = n;
    // populate the new array with vals
    // could use length or n for the test expression, really,
    // since length == n, but I'll go with length
    for (int i = 0; i < length; i++)
        numbers[i] = val;
}
void IntVector::push_back(int val)
{
    // here's our plan to make this work right:
    // to get this to work, we need to do a few things:
    // 0. if there is no array, we have to create a 1 element array,
    //    put the value in it, and update the length variable and 
    //    we're done.  Otherwise, proceed to step 1!
    // 1. create a temporary array of length + 1 to accommodate
    //    the new value 
    // 2. copy the contents of the old array to the new array
    // 3. store the new value in the leftover element 
    // 4. update the length variable 
    // 5. delete the original array, so we don't have memory leaks
    // 6. update the numbers pointer with the address of the new
    //    array.
    // you have to be careful handling the memory to avoid leaks
    // 0. if there is no array, we have to create a 1 element array,
    //    put the value in it, and update the length variable and 
    //    we're done.  Otherwise, proceed to step 1!
    // if there is no array...
    if (numbers == nullptr)
    {
        // we have to create a 1 element array...
        numbers = new int[1];
        // put the value in it...
        numbers[0] = val;
        // update the length variable...
        length++;
        // and, we're done...
        return;
    }
    // otherwise, proceed to step 1...
    // 1. create a temporary array of length + 1 to accommodate
    //    the new value 
    int* tempArray = new int[length + 1];
    // 2. copy the contents of the old array to the new array
    for (int i = 0; i < length; i++)
        tempArray[i] = numbers[i];
    // 3. store the new value in the leftover element 
    tempArray[length] = val;
    // 4. update the length variable 
    length++;
    // 5. delete the original array, so we don't have memory leaks
    delete[] numbers;
    // 6. update the numbers pointer with the address of the new
    //    array.
    numbers = tempArray;
    }
// IntVector i = j;     // i is lhs, j is rhs
// IntVector i(j);
IntVector::IntVector(const IntVector& rhs)
{
    // no rhs array
    if (rhs.numbers == nullptr)  // or if (rhs.length == 0)
    {
        length = 0;
        numbers = nullptr;
    }
    // yes rhs array
    else
    {
        length = rhs.length;
        numbers = new int[length];
        for(int i = 0; i < length; i++)
            numbers[i] = rhs.numbers[i];
    }
}
// IntVector i;
// i++;
IntVector IntVector::operator++(int)
{
    // be a temp IntVector that preserves state
    IntVector temp(*this);
    // update the array
    for(int i = 0; i < length; i++)
        numbers[i] = numbers[i] + 1;
    return temp;
}
// cout << x;
// x is rhs
ostream& operator<<(ostream& o, const IntVector& rhs)
{
    o << "[";
    int i = 0;
    for(; i < rhs.size() - 1; i++)
        o << rhs.numbers[i] << ", ";
    if(rhs.length > 0)
    o << rhs.numbers[i];
    o << "]";
    return o;
}
// x = y;
// x is "this" it's also the lhs and y is the rhs
// x.operator(y);
const IntVector IntVector::operator=(const IntVector& rhs)
{
    if (this != &rhs)
    {
        // no rhs array and yes rhs array
        if (rhs.numbers == nullptr)
        {
            numbers = nullptr;
            length = 0;
        }
        else
        {
            if(numbers != nullptr)
                delete [] numbers;
            length = rhs.length;
            numbers = new int[length];
            for(int i = 0; i < length; i++)
                numbers[i] = rhs.numbers[i];
        }
    }
    return *this;
}