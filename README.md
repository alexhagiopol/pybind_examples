# PyBind Examples
Zero-to-one guide for using [PyBind](https://github.com/pybind/pybind11) to compile and call C++ functions from Python code. Includes [NumPy](https://numpy.org/)<->[Eigen](https://gitlab.com/libeigen/eigen) example useful for mathematical programming.

## Installation
This project assumes existing installations of...
- a C++ compiler invokable by `make` command
- a [CMake](https://cmake.org/) installation invokable by `cmake` command
- Python 3+ with NumPy

## Usage
The Python script `demo.py`...
- compiles the C++ functions in `ExampleFunctions.cpp` using the compilation procedure defined in `CMakeLists.txt`
- imports the C++ functions to make them available for use using Python code 
- constructs and passes arbitrary inputs to the C++ functions
- calls the C++ functions
- displays the results. 

`ExampleFunctions.cpp` contains `add()` that uses only C++ standard data types and `fill()` that uses data types from the Eigen library. This illustrates how to use PyBind to translate between Python data types in `demo.py` to C++ data types in `ExampleFunctions.cpp`. PyBind translates standard C++ data type to standard Python data types. PyBind translates NumPy data types to Eigen data types.

```
python3 demo.py 
-- The C compiler identification is GNU 11.3.0
-- The CXX compiler identification is GNU 11.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- pybind11 v2.11.0 dev1
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.10.6", minimum required is "3.6") 
-- Found PythonLibs: /usr/lib/x86_64-linux-gnu/libpython3.10.so
-- Performing Test HAS_FLTO
-- Performing Test HAS_FLTO - Success
-- Configuring done
-- Generating done
-- Build files have been written to: /home/a/pybind_examples/accelerated_functions_build
[ 50%] Building CXX object CMakeFiles/accelerated_functions.dir/AcceleratedFunctions.cpp.o
[100%] Linking CXX shared module accelerated_functions.cpython-310-x86_64-linux-gnu.so
[100%] Built target accelerated_functions
************************
Python code: add() demo:
Python code: sending inputs 41 677
C++ code: executing add(41,677)=718
Python code: received result 718
************************
Python code: fill() demo:
Python code: sending input matrix
 [[4.64478392e-310 0.00000000e+000]
 [4.82407136e+228 2.57691368e-312]]
Python code: sending input value 133.0
C++ code: executing fill()
C++ code: modifying 4.64478e-310 to 133.000000
C++ code: modifying 0 to 133.000000
C++ code: modifying 4.82407e+228 to 133.000000
C++ code: modifying 2.57691e-312 to 133.000000
Python code: matrix modified
 [[133. 133.]
 [133. 133.]]
```

## Further Reading
The full [PyBind documentation](https://pybind11.readthedocs.io/_/downloads/en/latest/pdf/) is excellent for going beyond what is illustrated here.
