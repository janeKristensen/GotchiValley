#include "MovementSystem.h"


using namespace GotchiValley;

void MovementSystem::Update() {
	
	auto controlArray = componentRegistry.GetComponentArray<Controlable>();
	for (auto i = controlArray.begin(); i != controlArray.end(); i++) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 
			NotifyObservers(i->first, EntityEvent::MOVE_UP);
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
			NotifyObservers(i->first, EntityEvent::MOVE_DOWN);
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
			NotifyObservers(i->first, EntityEvent::MOVE_RIGHT);
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
			NotifyObservers(i->first, EntityEvent::MOVE_LEFT);
		else 
			NotifyObservers(i->first, EntityEvent::IDLE);
		
	}
}

void MovementSystem::AddObserver(IGameObserver* observer) {

	mObservers.emplace(observer);
}

void MovementSystem::RemoveObserver(IGameObserver* observer) {

	mObservers.erase(observer);
}

void MovementSystem::NotifyObservers(const Entity& entity, const EntityEvent& eventMessage) const{

	for (auto observer : mObservers) {
		observer->OnNotify(entity, eventMessage);
	}
}