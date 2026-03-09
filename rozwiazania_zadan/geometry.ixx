module;
#include<cmath>;
#include<iostream>
export module mathh:geometry;
export class shape {
	int base_edges_num;
	bool type; //0 to graniastoslup, 1 ostroslup
	int a;
	int H;
public:
	shape(){}
	shape(int _base_ed_n, bool _type, int _base_l, int _height) :base_edges_num(_base_ed_n),type(_type), a(_base_l), H(_height) {}
	double base_surface() {
		double base1_surface;
		if (base_edges_num == 3) {
			base1_surface = ((a * a * sqrt(3)) / 4);
		}
		else if (base_edges_num == 4) {
			base1_surface = a * a;
		}
		else if (base_edges_num == 6) {
			base1_surface = ((a * a * sqrt(3)) / 4) * 6;
		}
		else {
			std::cout << "wrong number of base edges" << std::endl;
			return 0;
		}
		return base1_surface;
	}
	double surface_area() {
		double base1_surface= this->base_surface();
		

		if (type == 0) {
			//graniastoslup
			double side_surface=a* H*base_edges_num;
			double total_base_surface = 2 * base1_surface;

			

			return total_base_surface+ side_surface;
			
			
		}
		else {
			//ostroslup
			double side_H;
			double r;
			if (base_edges_num == 3) {
				r = (a * sqrt(3)) / 6;
			}
			else if (base_edges_num == 4) {
				r = a  / 2;
			}
			else if (base_edges_num == 6) {
				r = (a * sqrt(3)) / 2;
			}
			side_H = sqrt((H * H) + (r * r));
			double side_surface;


			if (base_edges_num == 3) {
				side_surface = ((side_H*a)/2)*3;
			}
			else if (base_edges_num == 4) {
				side_surface = ((side_H * a) / 2) * 4;
			}
			else if (base_edges_num == 6) {
				side_surface = ((side_H * a) / 2) * 6;
			}
			return base1_surface + side_surface;
		}
		
	}
	double volume() {
		double base1_surface = this->base_surface();
		if (type == 0) {
			return base1_surface* H;
		}
		else {
			return (base1_surface * H)/3;
		}
	}
};
