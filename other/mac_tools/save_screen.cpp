#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;

int main()
{
    // RESULTS: We seem to be getting about 4 frames per second
    // with this approach on a macbook air. This might not be 
    // sufficient for our needs
    for (int i = 0; i < 30; ++i) {
        auto start = std::chrono::steady_clock::now();
        string cmd = "screencapture frame" + to_string(i) + ".tif -t tif";
        system(cmd.c_str());
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms " << std::endl;
    }
}
