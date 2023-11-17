#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#define LN { std::cout << __LINE__ << std::endl; }
#define DEB(x) { std::cout << #x << "=(" << (x) << ") "; }
using namespace std;

static std::string ch_hor = "\u2500" /*─*/, ch_ver = "\u2502" /*│*/, ch_ddia = "\u250C" /*┌*/, ch_rddia = "\u2510" /*┐*/, ch_udia = "\u2514" /*└*/, ch_ver_hor = "\u251C\u2500" /*├─*/, ch_udia_hor = "\u2514\u2500" /*└─*/, ch_ddia_hor = "\u250C\u2500" /*┌─*/, ch_ver_spa = "\u2502 " /*│ */;

typedef struct tree
{
    int data;
    tree* left,* right;
}Tree;

        void AddSheet(Tree*, int num, Tree* tmp = NULL);
        int search(Tree*, int);
        void wr_block(Tree*, int);
        void PrintTree(Tree const * node, std::string const & rpref = "", std::string const & cpref = "", std::string const & lpref = "");

