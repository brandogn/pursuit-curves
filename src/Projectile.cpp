#include <cmath>

class Projectile {
   public:
    double y;
    double x;

    Projectile(double x, double y, double velocity, double radian) {
        this->x = x;
        this->y = y;
        this->velocity = velocity;
        this->direction = radian;
    }

    /// @brief Takes in dt as change in time in seconds
    void move(double dt) {
        // formula for move:
        double travelDist = velocity * dt;
        double dx = std::cos(direction) * travelDist;
        double dy = std::sin(direction) * travelDist;
        x += dx;
        y -= dy;
    }

   private:
    // velocity stored as m/s, direction stored in radians
    double velocity;
    double direction;
};
