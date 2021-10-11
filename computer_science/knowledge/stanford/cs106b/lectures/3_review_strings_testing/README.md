# C++ Review, String and Testing

> Software and cathedrals are much the same – first we build them,
> then we pray.    – Sam Redwine

## Lecture Meta

* Themes: Review, String and Testing
* Textbook: Text 3.1-3.7
* [Docs for standard library](https://web.stanford.edu/dept/cs_edu/cppdoc)

## Loops

* **while loops**

  while loop are great when you want to continue executing something until a
  certain condition is met and you don't know exactly how many times you want
  to iterate for.

* **for loops**

  for loops are great when you have a known, fixed number of times that you want
  to execute a block of code.

## Strings in C++

string: A data type that represents a sequence of characters.

* String in C++ areYou can add characters to strings and strings to strings
  using += and + mutable.
* Strings must use double quotes while characters use single.
* You can use logical operators to compare strings. C++ is using the ASCII
  values of their first character to compare.

## string utility functions

* Built-in C++ char functions (\<cctype> library)
* Built-in string methods(\<string> library)
* Standard string library functions("strlib.h" library)

## Two ways to loop through the string

```c++
void loopingOverStrFor(string word){
    for(int i=0; i<word.length(); i++){
        cout << word[i] << endl;
    }
}

void loopingOverStrForEach(string word){
    for(char letter: word){
        cout << letter << endl;
    }
}

void alphabetLoop(){
    for(char letter='a'; letter <= 'z'; letter++) {
        cout << letter << endl;
    }
}
```

## Two types of C++ strings

String is a collection of characters. There are two types of strings commonly
used in C++ programming language:

* Strings that are objects of string class (The Standard C++ Library string
  class)
* C-strings (C-style Strings)

### C-strings

In C programming, the collection of characters is stored in the form of arrays.
C-strings are arrays of type `char` terminated with null character,
that is, `\0` (ASCII value of null character is 0).

1. How to define a C-strings?

```c++
char str[] = "C++";

char str[100];
cout << "Enter a string: ";
cin.get(str, 100);
```

### string object

Unlike using char arrays, string objects has no fixed length, and can be
extended as per your requirement.

```c++
string str;
cout << "Enter a string: ";
getline(cin, str);
```

### differences

* C strings have no methods
* Conversion fixes
  * string("text"); converts the C string literal into a C++ string
  * string.c_str() returns a C string from a C++ string

```c++
// Error
string hiThere = "hi" + "There";

// "hi" here is a C string.
```