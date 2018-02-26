#include "engine.hpp"

#include "transform.hpp"
#include "rigid_body.hpp"

using namespace symbiosis;

class PhysicsSystem: public SystemImplementation<Transform, RigidBody> {
public:
    
    template<typename... EngineTypes>
    PhysicsSystem(Engine<EngineTypes...>& engine):
    transforms(engine.template getAll<Transform>()),
    bodies(engine.template getAll<RigidBody>()) {
        
    }
    
	void update() override {
        
        // Do something cool with the bodies and transforms.
        for(auto i = 0; i < 10; i++) {
            transforms[i];
            bodies[i];
        }
	}
    
private:
    
    std::vector<Transform>& transforms;
    std::vector<RigidBody>& bodies;
};

int main() {
	
	Engine<Transform, RigidBody> engine;
	engine.addSystem<PhysicsSystem>();
    Entity e;
    engine.createComponent<Transform>(e);
	
	return 0;
}
