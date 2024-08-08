#include "symmetrize/symmetrize.h"
#include <sstream>

int main(int argc, char **argv)
{
    std::stringstream ss;
    ss << "Usage: imgpro [options] [arg1] [arg2] ..." << std::endl
       << "Options: " << std::endl
       << " -s [-LRTB] <img_path>   :   Symmetrize image at the specified path," << std::endl
       << "                             [-LRTB] represent symmetrical methods." << std::endl
       << "                             e.g. -L represents flipping the left half" << std::endl
       << "                             of the image and covering the right half with it." << std::endl;
    std::string help_info{ss.str()};
    if (argc < 2)
    {
        std::cout << "Options required." << std::endl;
        std::cout << help_info;
        return -1;
    }
    std::string op{argv[1]};
    if (op[0] != '-' || op.length() != 2)
    {
        std::cout << "Invalid Option: " << op << std::endl;
        std::cout << help_info;
        return -1;
    }
    char op_code{op[1]};
    switch (op_code)
    {
    case 's':
        if (argc < 3)
        {
            std::cout << "Option \"-s\" requires args" << std::endl;
            std::cout << help_info;
        }
        else if (argc == 3)
        {
            symmetrize(argv[2]);
        }
        else
        {
            std::string modifier{argv[2]};
            if (modifier != "-L" && modifier != "-R" && modifier != "-T" && modifier != "-B")
            {
                std::cout << "Invalid Option: " << op << std::endl;
                std::cout << help_info;
                return -1;
            }
            char flag{modifier[1]};
            std::string img_path{argv[3]};
            symmetrize(img_path, flag);
        }
        break;
    default:
        break;
    }
    return 0;
}