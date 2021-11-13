#include "04.hpp"
FileSysterm tfs(10);

FileSysterm& f_tfs()
{
    static FileSysterm fs(11);
    return fs;
}