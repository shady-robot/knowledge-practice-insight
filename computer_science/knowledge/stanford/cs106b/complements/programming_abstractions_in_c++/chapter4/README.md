# Streams

## Formatted output and input

The insertion (<<) operator, which is preprogrammed for all standard C++ data
types, sends bytes to an output stream object.

This operator is called the insertion operator because it has the effect of
inserting data into a stream. The << operator is overloaded so that the operand
on the right can be a string or any primitive value. If this operand is not a
string, the << operator converts it to string form before sending it to the
output stream. This feature makes it easy to display the values of variables,
because C++ handles the output conversion automatically.

In C++ Streams:

* `<<` is insertion operator.
* `>>` is extraction operator.

### manipulator

Manipulators are functions specifically designed to be used in conjunction with
the insertion (<<) and extraction (>>) operators on stream objects.

Manipulators are used to change formatting parameters on streams and to insert
or extract certain special characters.

## Data files

### Single character I/O

Input streams in the C++ library support reading a single character using a
method called get, which exists in two forms.

```c++
int ch;
while ((ch = infile.get()) != EOF) {
  #Perform some operation on the character.
}
```

`infile.unget();` The effect of this call is to "push" the most recent
character back into the input stream so that it is returned on the next
call to get. The specifications for the C++ library guarantees that it will
always be possible to push one character back into the input file, but you
should not rely on being able to read several characters ahead and then push
them all back.

* Refer to [ShowFileContents.cpp](./codes/ShowFileContents.cpp) for a demo.
* Refer to [C++ Manipulators][1] for more details.

[1]:<http://www.cplusplus.com/reference/library/manipulators/>