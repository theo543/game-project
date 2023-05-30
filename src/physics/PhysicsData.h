#ifndef ASTEROIDS_PHYSICSDATA_H
#define ASTEROIDS_PHYSICSDATA_H

#include <vector>
#include "SFML.h"
#include "physics/AABB.h"

/**
 * The GameObject will instantiate this and then use it to store position and velocity data.
 * As far as it cares this is just a struct.
 * There will also be private stuff only Physics cares about used to resolve collisions.
 */
class PhysicsData : public sf::Transformable {
    std::vector<sf::Vector2f> mesh;
    sf::Vector2f velocity;
    float angularVelocity;
    float boundingRadius;
    AABB base_aabb;
    mutable AABB cached_aabb;
    mutable sf::Transform cached_transform;
    void updateAABB() const;
public:
    PhysicsData();
    /// It'd be incovenient if we did this in the constructor.
    void initialize(std::vector<sf::Vector2f> &&mesh);
    void initialize(const sf::Shape &shape);
    bool isInitialized() const;
    void setVelocity(sf::Vector2f velocity);
    void setAngularVelocity(float angularVelocity);
    [[nodiscard]] sf::Vector2f getVelocity() const;
    [[nodiscard]] float getAngularVelocity() const;
    [[nodiscard]] float getBoundingRadius() const;
    void accelerate(sf::Vector2f acceleration);
    void accelerateAngular(float acceleration);
    [[nodiscard]] const AABB &getAABB() const;
    bool aabb_collides(const PhysicsData &other) const;

    friend class Physics;
};


#endif //ASTEROIDS_PHYSICSDATA_H
