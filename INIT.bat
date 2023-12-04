md "SR"C
cd SRC
    type nul > main.cpp
cd ..

type nul > CMakeLists.txt

md "build"

md "Operation Mode"
cd Operation Mode
    md "User Interface"
    cd User Interface
        type nul > UI.hpp
        type nul > UI.cpp
    cd ..
cd ..


md "Programming Mode"
cd Programming Mode
    md "addProducts"
    cd addProducts
        type nul > addProducts.hpp
        type nul > addProducts.cpp
    cd ..
