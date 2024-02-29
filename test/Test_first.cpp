#include "PTree.h"


#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <time.h>


using namespace std;

int main(int argc, char *argv[])
{
    Ptree *tree = new Ptree("dataset.txt");
    tree->disPlayInfo();  

}