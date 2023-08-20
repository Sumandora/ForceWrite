# Force Write
ForceWrite is a utility project for Linux that allows writing to read-only memory pages by utilizing the `/proc/pid/mem` interface.

## Usage
1. Include the `ForceWrite.hpp` header in your C++ project.
2. Use the `ForceWrite::write()` function to modify memory. The syntax is as follows:

```cpp
ForceWrite::write(targetAddress, newValue);
```