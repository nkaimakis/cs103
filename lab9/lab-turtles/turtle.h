#include "draw.h"

class Turtle{
	public:
		Turtle(double x0, double y0, double dir0);
		~Turtle();
		void turn (double deg);
		void move (double dist);
		void on (); //leave trail
		void off (); //leave no trail
		void setColor (Color color); 


	private:
		double x_val;
		double y_val;
		double direction;
		bool trail;
		Color c;

};