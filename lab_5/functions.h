#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

typedef struct 
{
    int key_1;
    int key_2;
    std::string str;
}   data_struct;

std::vector<data_struct> fill_vector(std::vector<data_struct> &v, int size)
{
    std::vector<std::string> str_table;
    std::vector<std::string>::iterator iter;
    std::vector<data_struct>::iterator it;
    std::string line;
    data_struct dtstr;
    std::ifstream file("text");
    int index;

    if(!file)
    {
        std::cout<<"Cannot open the file!";
        exit(EXIT_FAILURE);
    }

    while (!file.eof())
    {
        getline(file, line, '\n');
        str_table.push_back(line);
    }

    for (int i=0; i<size; i++) 
    {
        dtstr.key_1=rand()%11-5;
        dtstr.key_2=rand()%11-5;
        index=rand()%9+0;
        dtstr.str=str_table.at(index);
        v.push_back(dtstr);
    }

    return v; 
}

bool greater_than(data_struct a, data_struct b)
{
	 if (a.key_1>b.key_1) return true;
	 if ((a.key_2>b.key_2)&&(a.key_1==b.key_1)) return true;
	 if ((a.str.length()>b.str.length())&&(a.key_2==b.key_2)&&(a.key_1==b.key_1))
	 	return true;
	 return false;
}

void sort(std::vector<data_struct> &v)
{
	for (int i = 0; i<v.size(); i++)
	{
		for (int j=i+1; j<v.size(); j++)
		{
			if (greater_than(v[i],v[j]))
            {
				data_struct temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}
