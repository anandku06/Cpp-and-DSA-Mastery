# Bit Manipulation

- Bit manipulation is a technique used in programming to perform operations on individual bits of data. It is often used for optimization, low-level programming, and solving problems that require efficient use of memory and processing power.

## Key Concepts of Bit Manipulation

- Bitwise Operators: These are operators that perform operations on the binary representations of numbers. Common bitwise operators include AND (&), OR (|), XOR (^), NOT (~), left shift (<<), and right shift (>>).
- Bit Masks: A bit mask is a binary number that is used to isolate or modify specific bits in another binary number. It can be created using bitwise operators and is often used in conjunction with bitwise operations to manipulate individual bits.
- Bitwise Operations: These are operations that manipulate the bits of a binary number. Common bitwise operations include setting a bit, clearing a bit, toggling a bit, and checking the value of a bit.
- Bit Manipulation Techniques: There are various techniques used in bit manipulation, such as using bitwise operators to perform arithmetic operations, using bit masks to isolate or modify specific bits, and using bitwise operations to optimize algorithms and data structures.

### Example of Bit Manipulation

```cpp
// Function to check if a number is even or odd using bit manipulation
bool isEven(int n) {
    return (n & 1) == 0; // If the least significant bit is 0, the number is even
}
```

### Example of Bit Masking

```cpp
// Function to set the 3rd bit of a number using bit masking
int setThirdBit(int n) {
    return n | (1 << 2); // Set the 3rd bit (index 2) to 1
}
```

### Example of Bitwise Operations

```cpp
// Function to toggle the 2nd bit of a number using bitwise operations
int toggleSecondBit(int n) {
    return n ^ (1 << 1); // Toggle the 2nd bit (index 1)
}
```

### Binary Number Conversion

- Converting between decimal and binary representations is a fundamental aspect of bit manipulation. Understanding how to convert numbers to and from binary is essential for performing bitwise operations effectively.
- For example, to convert a decimal number to binary, you can repeatedly divide the number by 2 and record the remainders. To convert a binary number to decimal, you can multiply each bit by 2 raised to the power of its position and sum the results.

#### Decimal to Binary Conversion

- By repeatedly dividing the decimal number by 2 and recording the remainders, you can convert a decimal number to binary. The binary representation is obtained by reading the remainders in reverse order.

```cpp
int decimalToBinary(int n) {
    int binary = 0;
    int place = 1;
    while (n > 0) {
        int remainder = n % 2;
        binary += remainder * place;
        n /= 2;
        place *= 10;
    }
    return binary;
}
```

#### Binary to Decimal Conversion

- To convert a binary number to decimal, you can multiply each bit by 2 raised to the power of its position and sum the results. The least significant bit (rightmost) is at position 0.

```cpp
int binaryToDecimal(int n) {
    int decimal = 0;
    int base = 1; // 2^0
    while (n > 0) {
        int lastDigit = n % 10;
        decimal += lastDigit * base;
        n /= 10;
        base *= 2; // Move to the next power of 2
    }
    return decimal;
}
```

### One's Complement

- One's complement is a binary representation of numbers where all the bits are inverted (0s become 1s and 1s become 0s). It is used in some computer systems to represent negative numbers. The one's complement of a binary number can be obtained by flipping all the bits.
- For example, the one's complement of the binary number `1010` is `0101`.

### Two's Complement

- Two's complement is a binary representation of numbers that allows for both positive and negative integers. It is obtained by taking the one's complement of a binary number and adding 1 to the least significant bit (LSB). Two's complement is widely used in computer systems for representing signed integers.
- For example, to find the two's complement of the binary number `1010`, you first find the one's complement `0101` and then add 1, resulting in `0110`.

#### A number is negative if its most significant bit (MSB) is 1 in two's complement representation. For example, in an 8-bit system, the number `11111111` represents -1, while `00000001` represents 1

## Bitwise Operators

1. AND (&): Performs a bitwise AND operation between two binary numbers. The result has a 1 in each position where both corresponding bits are 1, i.e. 1 & 1 = 1, otherwise 0.
   e.g., `5 & 3` (binary `0101 & 0011`) results in `0001` (decimal `1`).

2. OR (|): Performs a bitwise OR operation between two binary numbers. The result has a 1 in each position where at least one of the corresponding bits is 1, i.e. 1 | 0 = 1, 0 | 1 = 1, and 1 | 1 = 1.
   e.g., `5 | 3` (binary `0101 | 0011`) results in `0111` (decimal `7`).

3. XOR (^): Performs a bitwise XOR operation between two binary numbers. The result has a 1 in each position where the corresponding bits are different, i.e. 1 ^ 0 = 1, 0 ^ 1 = 1, and 1 ^ 1 = 0.
   e.g., `5 ^ 3` (binary `0101 ^ 0011`) results in `0110` (decimal `6`).
4. NOT (~): Performs a bitwise NOT operation, inverting all the bits of a binary number. 0s become 1s and 1s become 0s, i.e. ~0 = 1 and ~1 = 0.
   e.g., `~5` (binary `0101`) results in `1010` (decimal `-6` in two's complement representation).

#### Why NOT operator results in -6?

- The NOT operator (~) inverts all the bits of a binary number. In the case of the number 5, its binary representation in an 8-bit system is `00000101`. When you apply the NOT operator, it flips all the bits, resulting in `11111010`. In two's complement representation, this is the binary representation of -6.

5. Left Shift (<<): Shifts the bits of a binary number to the left by a specified number of positions, filling the rightmost bits with 0s. This operation effectively multiplies the number by 2 for each shift, i.e. `n << 1` is equivalent to `n * 2`.
   e.g., `5 << 1` (binary `0101 << 1`) results in `1010` (decimal `10`).
   - Note: Left shifting a signed integer can lead to undefined behavior if the sign bit is shifted out of the range of the data type.
     e.g., -2^31 << 1 (binary `10000000000000000000000000000000 << 1`) results in `0` (undefined behavior in signed integers).
     Same for 2^31 - 1 << 1 (binary `01111111111111111111111111111111 << 1`) results in `-2` (undefined behavior in signed integers).

6. Right Shift (>>): Shifts the bits of a binary number to the right by a specified number of positions, filling the leftmost bits with 0s (for unsigned numbers) or the sign bit (for signed numbers). This operation effectively divides the number by 2 for each shift, i.e. `n >> 1` is equivalent to `n / 2`.
   e.g., `5 >> 1` (binary `0101 >> 1`) results in `0010` (decimal `2`).
   - Note: Right shifting a signed integer in C++ is implementation-defined, meaning the behavior can vary between different compilers and platforms. It's generally recommended to use unsigned integers for right shifts to avoid undefined behavior.
