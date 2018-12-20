#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>

// http://stackoverflow.com/questions/478898
std::string exec(const char* cmd)
{
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe))
    {
        if(fgets(buffer, 128, pipe) != NULL)
        {
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

std::string paste()
{
    return exec("pbpaste");
}

std::string copy(const char * new_clipboard)
{
    std::stringstream cmd;
    cmd << "echo \"" << new_clipboard << "\" | pbcopy";
    return exec(cmd.str().c_str());
}

int main(int argc, char * argv[])
{
    using namespace std;
    cout<<"old clipboard: "<<paste()<<endl;
    copy("Bomb!");
    cout<<"new clipboard: "<<paste()<<endl;
    return 0;
}
