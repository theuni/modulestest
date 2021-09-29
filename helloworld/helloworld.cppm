// From: https://en.cppreference.com/w/cpp/language/modules

export module helloworld;  // module declaration
import <iostream>;         // import declaration

export void hello() {      // export declaration
    std::cout << "Hello world!\n";
}
