#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

int overall_number_of_vertices=0;

typedef struct
{
    int x, y;
} point;

typedef struct
{
    int vertex_num;
    std::vector<point> vertices;
} shape;

shape generate_shape()
{
    shape new_shape;
    point new_point;

    new_shape.vertex_num=rand()%3+3;

    for (int i=0; i<new_shape.vertex_num; i++)
    {   
        new_point.x=rand();
        new_point.y=rand();
        new_shape.vertices.push_back(new_point);
    }

    return new_shape;
}

void print_vector(std::vector<shape> shapes)
{   
    std::vector<shape>::iterator iter;
    int i=0;
    for (iter=shapes.begin(); iter!=shapes.end(); iter++)
    {   
        std::cout<<"Element number "<<i<<std::endl;
        std::cout<<"Number of vertices: "<<shapes[i].vertex_num<<std::endl;
        std::cout<<"Vertices are: "<<std::endl;

        for (int j=0; j<shapes.at(i).vertices.size(); j++)
        {   
            std::cout<<"Point "<<j<<std::endl;
            std::cout<<"x: "<<shapes.at(i).vertices.at(j).x<<std::endl;
            std::cout<<"y: "<<shapes.at(i).vertices.at(j).y<<std::endl<<std::endl;
        }
        ++i;
    }
}

void get_overall_number_of_vertices(shape const& s)
{
    static int number_of_vertices=0;
    number_of_vertices+=s.vertex_num;
    overall_number_of_vertices=number_of_vertices;
}

bool is_pentagon(shape &s)
{
    return (s.vertex_num==5);
}

bool is_quadrangle(shape &s)
{
    return (s.vertex_num==4);
}

bool is_triangle(shape &s)
{
    return (s.vertex_num==3);
}

void count_shapes(std::vector<shape> shapes)
{   
    int number_of_triangles, number_of_quadrangles, number_of_pentagons;
    number_of_triangles=count_if(shapes.begin(), shapes.end(), is_triangle);
    std::cout<<"The number of triangles is: "<<number_of_triangles<<std::endl;

    number_of_quadrangles=count_if(shapes.begin(), shapes.end(), is_quadrangle);
    std::cout<<"The number of quadrangles is: "<<number_of_quadrangles<<std::endl;

    number_of_pentagons=count_if(shapes.begin(), shapes.end(), is_pentagon);
    std::cout<<"The number of pentagons is: "<<number_of_pentagons<<std::endl<<std::endl;
}

void erase_pentagons(std::vector<shape>& shapes)
{
    std::vector<shape>::iterator it;
    it=remove_if(shapes.begin(), shapes.end(), is_pentagon);
    shapes.erase(it, shapes.end());
}

point get_random_point(shape const &s)
{
	return(s.vertices[rand()%(s.vertex_num)]);
}

bool greater_than(shape a, shape b)
{
	 if (a.vertex_num>b.vertex_num) return true;
	 return false;
}


void sort(std::vector<shape> &v)
{
	for (int i = 0; i<v.size(); i++)
	{
		for (int j=i+1; j<v.size(); j++)
		{
			if (greater_than(v[i],v[j]))
            {
				shape temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}