#include "utils.hpp"

void log(std::string source, std::string text) {
    time_t timer = std::time(nullptr);
    std::tm time = *std::localtime(std::addressof(timer));
    std::cout << "[" << std::setfill('0') << std::setw(2) << time.tm_hour << ":" << time.tm_min << ":" << time.tm_sec << "]";
    std::cout << "[" << source << "] " << text << "\n";
}

void throwError(std::string type, std::string details) {
    std::cout << "error: " << type << ": " << details << "\n";
    exit(-1);
}

// template<typename T>
// T lerp(T a, T b, double u) {
//     return (1.0f - u) * a + u * b;
// }
